////////////////////////////////////////////////////////////////////////////////
// Filename    : MasterLairManager.h 
// Written By  : ��
// Description : 
////////////////////////////////////////////////////////////////////////////////


#include "MasterLairManager.h"
#include "MasterLairInfoManager.h"
#include "Assert.h"
#include "Zone.h"
#include "VariableManager.h"
#include "Timeval.h"
#include "Monster.h"
#include "MonsterManager.h"
#include "PlayerCreature.h"
#include "Inventory.h"
#include "PCManager.h"
#include "Item.h"
#include "ItemUtil.h"
#include "ItemFactoryManager.h"
#include "EffectMasterLairPass.h"
#include "EffectContinualGroundAttack.h"
#include "PacketUtil.h"
#include "Player.h"
#include "MonsterCorpse.h"
#include "ZoneInfoManager.h"
#include "ZoneGroupManager.h"
#include "StringPool.h"

#include "Gpackets/GCNoticeEvent.h"
#include "Gpackets/GCSystemMessage.h"
#include "Gpackets/GCCreateItem.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCSay.h"

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
//
// constructor
//
////////////////////////////////////////////////////////////////////////////////
MasterLairManager::MasterLairManager (Zone* pZone) 
	throw (Error)
{
	__BEGIN_TRY
		
	Assert(pZone != NULL);
	m_pZone = pZone;

	MasterLairInfo* pInfo = g_pMasterLairInfoManager->getMasterLairInfo( m_pZone->getZoneID() );
	Assert(pInfo!=NULL);

	m_MasterID = 0;           // ������ �� ���� 
	m_MasterX = 0;
	m_MasterY = 0;

	m_bMasterReady = false;      // �����Ͱ� �ο� �غ��� �Ǿ���? 

	//m_nMaxSummonMonster = pInfo->getMaxSummonMonster(); // �����Ͱ� ��ȯ�� �ִ��� ������ �� 
	//m_nSummonedMonster = 0;

	m_nMaxPassPlayer = pInfo->getMaxPassPlayer(); // �ִ� ���� ������ ��
	m_nPassPlayer = 0;

	m_Event = EVENT_WAITING_REGEN;
	m_EventValue = 0;

	Timeval currentTime;
	getCurrentTime(currentTime);

	// �ǹ̾���. - -;
	m_EventTime.tv_sec = currentTime.tv_sec + pInfo->getFirstRegenDelay();
	m_EventTime.tv_usec = 0;

	m_RegenTime.tv_sec = currentTime.tv_sec + pInfo->getFirstRegenDelay();
	m_RegenTime.tv_usec = 0;

	m_Mutex.setName("MasterLairManager");

	//cout << "Init MasterLairManager: zoneID=" << (int)m_pZone->getZoneID() << endl;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// destructor
//
////////////////////////////////////////////////////////////////////////////////
MasterLairManager::~MasterLairManager () 
	throw ()
{
	__BEGIN_TRY

	__END_CATCH
}
	
////////////////////////////////////////////////////////////////////////////////
//
// enterCreature ( Creature* )
//
////////////////////////////////////////////////////////////////////////////////
//
// Creature�� �� Zone(MasterLair)�� ������ �� �ִ��� üũ�ϰ�
// ������ �� �ִٸ� �����Դٰ� ���� üũ�صд�.
//
// [���]
//   - EVENT_WAITING_PLAYER, 
//     EVENT_MINION_COMBAT, 
//     EVENT_MASTER_COMBAT�� ���츸 ������ ���ɼ��� �ִ�.
//   - EffectMasterLairPass�� �ְ� ���� MasterLair�� ���� �´� ������ ����� �����´�.
//   - EVENT_WAITING_PLAYER�� �ƴϸ� �� �����´�.
//   - �����Ͱ� ���� ���� m_nPassPlayer >= m_nMaxPassPlayer�� ���� �� ������
//
// ���� ������ ĳ���Ϳ��Դ� EffectMasterLairPass�� ���ٸ�
//   - m_nPassPlayer�� 1��������Ű�� EffectMasterLairPass�� �ٿ��ش�.
//   - EffectMasterLairPass�� ���� �ð�� EVENT_MASTER_COMBAT�� ������ �ð������̴�.
//
////////////////////////////////////////////////////////////////////////////////
bool MasterLairManager::enterCreature(Creature* pCreature)
	throw(Error)
{	
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	if (pCreature->isDM() || pCreature->isGOD())
	{
		m_Mutex.unlock();
			
		goto ENTER_OK;
	}

	if (m_Event!=EVENT_WAITING_PLAYER
		&& m_Event!=EVENT_MINION_COMBAT
		&& m_Event!=EVENT_MASTER_COMBAT)
	{
		//cout << "[" << (int)m_pZone->getZoneID() << "] MasterLairManager: ����� ��� �� ���� ����" << endl;
		m_Mutex.unlock();
		return false;
	}

	EffectMasterLairPass* pPassEffect = NULL;

	// ���� Zone�� EffectMasterLairPass�� ���� �ִ°�?
	if (pCreature->isFlag( Effect::EFFECT_CLASS_MASTER_LAIR_PASS ))
	{
		if (g_pVariableManager->isRetryMasterLair())
		{
			Effect* pEffect = pCreature->getEffectManager()->findEffect( Effect::EFFECT_CLASS_MASTER_LAIR_PASS );
			Assert(pEffect!=NULL);

			pPassEffect = dynamic_cast<EffectMasterLairPass*>(pEffect);

			if (pPassEffect->getZoneID()==m_pZone->getZoneID())
			{
				//cout << "[" << (int)m_pZone->getZoneID() << "] MasterLairManager: " << pCreature->getName().c_str() << " has EffectPass" << endl;
				m_Mutex.unlock();

				goto ENTER_OK;
			}

			// �ٸ� Lair�� Pass��. - -;
			//cout << "[" << (int)m_pZone->getZoneID() << "] MMasterLairManager: " << pCreature->getName().c_str() << " has Wrong EffectPass" << endl;
		}
		else
		{
			//cout << "[" << (int)m_pZone->getZoneID() << "] MMasterLairManager: " << pCreature->getName().c_str() << " can't enter more" << endl;

			m_Mutex.unlock();
			return false;
		}
	}

	// ������ �� ���� ����
	if (m_Event!=EVENT_WAITING_PLAYER)
	{
		//cout << "[" << (int)m_pZone->getZoneID() << "] MasterLairManager: Not WAITING_PLAYER: "
		//	<< m_pZone->getPCManager()->getSize() << " / " << m_nPassPlayer << "/" << m_nMaxPassPlayer << endl;

		m_Mutex.unlock();
		return false;
	}

	//if (m_nPassPlayer >= m_nMaxPassPlayer)
	if (m_nPassPlayer >= g_pVariableManager->getVariable(MASTER_LAIR_PLAYER_NUM))	// by sigi. 2002.12.31
	{
		//cout << "[" << (int)m_pZone->getZoneID() << "] MasterLairManager: Already Maximum Players: "
			//<< m_pZone->getPCManager()->getSize() << " / " << m_nPassPlayer << "/" << m_nMaxPassPlayer << endl;

		m_Mutex.unlock();
		return false;
	}

	// ������ �� �ִٰ� �Ǵܵ� ����
	m_nPassPlayer ++;

	if (pPassEffect==NULL)
	{
		pPassEffect = new EffectMasterLairPass(pCreature, m_pZone->getZoneID());

		//cout << "[" << (int)m_pZone->getZoneID() << "] MasterLairManager: " << pCreature->getName().c_str() << " received EffectPass: "
		//	<< m_pZone->getPCManager()->getSize() << " / " << m_nPassPlayer << "/" << m_nMaxPassPlayer << endl;
	}
	else
	{
		pPassEffect->setZoneID( m_pZone->getZoneID() );
	}

	pCreature->getEffectManager()->addEffect( pPassEffect );
	pCreature->setFlag( Effect::EFFECT_CLASS_MASTER_LAIR_PASS );
	
	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH

ENTER_OK :

	/*
	// Sniping ���
	if (pCreature->isFlag(Effect::EFFECT_CLASS_SNIPING_MODE))
	{
        EffectManager* pEffectManager = pCreature->getEffectManager();
        Assert(pEffectManager);
        pEffectManager->deleteEffect(pCreature, Effect::EFFECT_CLASS_INVISIBILITY);
		pCreature->removeFlag(Effect::EFFECT_CLASS_INVISIBILITY);
	}

	// Invisibility���
	if (pCreature->isFlag(Effect::EFFECT_CLASS_INVISIBILITY))
	{
        EffectManager* pEffectManager = pCreature->getEffectManager();
        Assert(pEffectManager!=NULL);
        pEffectManager->deleteEffect(pCreature, Effect::EFFECT_CLASS_INVISIBILITY);
		pCreature->removeFlag(Effect::EFFECT_CLASS_INVISIBILITY);
	}
	*/

	if (m_Event==EVENT_MINION_COMBAT
		|| m_Event==EVENT_MASTER_COMBAT)
	{
		Timeval currentTime;
		getCurrentTime(currentTime);

		int timeGap = m_EventTime.tv_sec - currentTime.tv_sec;

		GCNoticeEvent gcNoticeEvent;
		gcNoticeEvent.setCode( NOTICE_EVENT_MASTER_COMBAT_TIME );
		gcNoticeEvent.setParameter( timeGap );
		//m_pZone->broadcastPacket( &gcNoticeEvent );
		pCreature->getPlayer()->sendPacket( &gcNoticeEvent );
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
//
// leaveCreature ( Creature* )
//
////////////////////////////////////////////////////////////////////////////////
//
// WaitingPlayer�����̸� PassPlayer�� �ϳ� �ٿ��ش�.
//
// ������ ��� �ٽ� ��� �� ���� �����̸� EffectPass�� �����ش�.
//
////////////////////////////////////////////////////////////////////////////////
bool MasterLairManager::leaveCreature(Creature* pCreature)
	throw(Error)
{	
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	if (pCreature->isDM() || pCreature->isGOD())
	{
		m_Mutex.unlock();
		return true;
	}

	// waiting player�� ���츸 ���ڸ� ���δ�.
	if (m_Event==EVENT_WAITING_PLAYER)
	{
		if (m_nPassPlayer>0) m_nPassPlayer--;
	}

	// ���� ����(��� ����) ������ ��� �ٽ� ���ƿ� �� ���� ����..�� �Ǿ��ִٸ�
	// ���� �� EffectMasterLairPass�� ����Ѵ�.
	if (!g_pVariableManager->isRetryMasterLair())
	{
		if (pCreature->isFlag( Effect::EFFECT_CLASS_MASTER_LAIR_PASS ))
		{
			pCreature->getEffectManager()->deleteEffect( Effect::EFFECT_CLASS_MASTER_LAIR_PASS );
			pCreature->removeFlag( Effect::EFFECT_CLASS_MASTER_LAIR_PASS );
		}
	}
	
	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH

	//cout << "[" << (int)m_pZone->getZoneID() << "] MasterLairManager: " << pCreature->getName().c_str() << " leaved: "
	//		<< m_pZone->getPCManager()->getSize() << " / " << m_nPassPlayer << "/" << m_nMaxPassPlayer << endl;
	return true;
}



////////////////////////////////////////////////////////////////////////////////
//
// heartbeat
// 
////////////////////////////////////////////////////////////////////////////////
bool MasterLairManager::heartbeat() 
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	switch (m_Event)
	{
		case EVENT_WAITING_PLAYER :
			processEventWaitingPlayer();
		break;

		case EVENT_MINION_COMBAT :
			processEventMinionCombat();
		break;
		
		case EVENT_MASTER_COMBAT :
			processEventMasterCombat();
		break;

		case EVENT_WAITING_KICK_OUT :
			processEventWaitingKickOut();
		break;

		case EVENT_WAITING_REGEN :
			processEventWaitingRegen();
		break;

		default :
			break;
	}; 

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH

	return true;
}

////////////////////////////////////////////////////////////////////////////////
//
// process EventWaitingPlayer
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::processEventWaitingPlayer() 
	throw (Error)
{
	__BEGIN_TRY

	Timeval currentTime;
	getCurrentTime(currentTime);

	// ���� �ð��� ������..
	// �����Ͱ� �����͸� ��ȯ�ϱ� �ϱ� �����Ѵ�.
	if (currentTime >= m_EventTime)
	{
		// ������ ��� �����ִٰ� �����鿡�� �˷��ش�.
//		ZoneInfo* pZoneInfo = g_pZoneInfoManager->getZoneInfo( m_pZone->getZoneID() );
//		Assert(pZoneInfo!=NULL);

//		StringStream msg;
//		msg << "������ ����(" << pZoneInfo->getFullName().c_str() << ")�� ������ϴ�.";

//        char msg[50];
 //       sprintf( msg, g_pStringPool->c_str( STRID_MASTER_LAIR_CLOSED ),
  //                      pZoneInfo->getFullName().c_str() );
//
 //       string sMsg( msg );
//
//		GCSystemMessage gcSystemMessage;
//		gcSystemMessage.setType(SYSTEM_MESSAGE_MASTER_LAIR);
//		gcSystemMessage.setMessage( sMsg );
//		g_pZoneGroupManager->broadcast( &gcSystemMessage );

		GCNoticeEvent gcNoticeEvent;

		gcNoticeEvent.setCode(NOTICE_EVENT_MASTER_LAIR_CLOSED);
		gcNoticeEvent.setParameter( m_pZone->getZoneID() );

		g_pZoneGroupManager->broadcast( &gcNoticeEvent );

		// Minion���� �ο� ����
		activeEventMinionCombat();
	}
	else
	{ 
		int remainSec = m_EventTime.tv_sec - currentTime.tv_sec;

		// 1�� ���� �ѹ��� �˸���.
		if (remainSec!=m_EventValue && remainSec!=0 && remainSec % 60 == 0)
		{
			// ������ ��� �����ִٰ� �����鿡�� �˷��ش�.
//			ZoneInfo* pZoneInfo = g_pZoneInfoManager->getZoneInfo( m_pZone->getZoneID() );
//			Assert(pZoneInfo!=NULL);

//			StringStream msg;
//			msg << "������ ����(" << pZoneInfo->getFullName().c_str() << ") ���� ���� �ð��� "
//				<< (remainSec/60) << "�� ���ҽ�ϴ�.";

//            char msg[100];
 //           sprintf( msg, g_pStringPool->c_str( STRID_MASTER_LAIR_OPENING_COUNT_DOWN ),
  //                          pZoneInfo->getFullName().c_str(),
   //                         (int)(remainSec/60) );
//
 //           string sMsg( msg );
//
//			GCSystemMessage gcSystemMessage;
//			gcSystemMessage.setType(SYSTEM_MESSAGE_MASTER_LAIR);
//			gcSystemMessage.setMessage( sMsg );
//			g_pZoneGroupManager->broadcast( &gcSystemMessage );

			GCNoticeEvent gcNoticeEvent;

			gcNoticeEvent.setCode(NOTICE_EVENT_MASTER_LAIR_COUNT);

			int remainMin = remainSec/60;
			uint param = (remainMin << 16) | ((int)m_pZone->getZoneID());
			gcNoticeEvent.setParameter( param );

			g_pZoneGroupManager->broadcast( &gcNoticeEvent );


			m_EventValue = remainSec;
		}
	}


	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// process EventWaitingPlayer
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::processEventMinionCombat() 
	throw (Error)
{
	__BEGIN_TRY

	Timeval currentTime;
	getCurrentTime(currentTime);

	// ���� �ð��� ������..
	// ��� �� �׿��ٴ� �ǹ��̹Ƿ�..
	// ����߹��Ѵ�.
	if (currentTime >= m_EventTime)
	{
		GCNoticeEvent gcNoticeEvent;
		gcNoticeEvent.setCode( NOTICE_EVENT_MASTER_COMBAT_END );
		m_pZone->broadcastPacket( &gcNoticeEvent );

		activeEventWaitingKickOut();
	}

	// ��ȯ�� ���� �� ��� ��������..
	// �����Ͱ� ���ͼ� �ο���.
	//if (m_nSummonedMonster >= m_nMaxSummonMonster
	if (m_bMasterReady
		// ��� ������ ȥ�ڸ� ��� ����
		&& m_pZone->getMonsterManager()->getSize()==1)
	{
		activeEventMasterCombat();
	}

	// �÷��̾����� �� ��� ����
	if (m_pZone->getPCManager()->getSize()==0)
	{
		activeEventWaitingRegen();
	}

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// process EventWaitingPlayer
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::processEventMasterCombat() 
	throw (Error)
{
	__BEGIN_TRY

	Timeval currentTime;
	getCurrentTime(currentTime);

	Creature* pMaster = m_pZone->getMonsterManager()->getCreature( m_MasterID );

	if (pMaster==NULL)
	{
		// ������ ���𰬳�?
		StringStream msg;
		msg << "�����Ͱ� �������. zoneID = " << (int)m_pZone->getZoneID();

		filelog("masterLairBug.txt", "%s", msg.toString().c_str());
			
		//throw Error(msg.toString());
	}
	else
	{
		// ���� �������� �ġ
		m_MasterX = pMaster->getX();
		m_MasterY = pMaster->getY();
	}

	// �����Ͱ� �׾��ų�
	// ���� �ð��� ������..
	// ����߹� ������ �ٲ۴�.
	if (pMaster==NULL || pMaster->isDead() )
	{
		killAllMonsters();
		giveKillingReward();
		activeEventWaitingKickOut();
	}

	else if (currentTime >= m_EventTime)
	{
		activeEventWaitingKickOut();
	}

	// �÷��̾����� �� ��� ����
	if (m_pZone->getPCManager()->getSize()==0)
	{
		activeEventWaitingRegen();
	}

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// process EventWaitingPlayer
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::processEventWaitingKickOut() 
	throw (Error)
{
	__BEGIN_TRY

	Timeval currentTime;
	getCurrentTime(currentTime);

	// ���� �ð��� ������ 
	//   �����ڵ�� kickOut ��Ű��
	//   Regen�Ǳ⸦ ���ٸ���.
	if (currentTime >= m_EventTime)
	{
		kickOutPlayers();
		activeEventWaitingRegen();
	}

	__END_CATCH
}
////////////////////////////////////////////////////////////////////////////////
//
// process EventWaitingPlayer
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::processEventWaitingRegen() 
	throw (Error)
{
	__BEGIN_TRY

	Timeval currentTime;
	getCurrentTime(currentTime);

	// ��� �ð��� �Ǹ� 
	//   �����ڵ�� ���ٸ���.
	if (currentTime >= m_RegenTime)
	{
		if (g_pVariableManager->isActiveMasterLair())
		{
			activeEventWaitingPlayer();
		}
		else
		{
			// �ƴϸ� ��� ��� �ð����� �����Ѵ�.
			MasterLairInfo* pInfo = g_pMasterLairInfoManager->getMasterLairInfo( m_pZone->getZoneID() );
			Assert(pInfo!=NULL);

			m_RegenTime.tv_sec += pInfo->getRegenDelay();
		}
	}

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// active EventWaitingPlayer
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::activeEventWaitingPlayer() 
	throw (Error)
{
	__BEGIN_TRY

	MasterLairInfo* pInfo = g_pMasterLairInfoManager->getMasterLairInfo( m_pZone->getZoneID() );
	Assert(pInfo!=NULL);

	deleteAllMonsters();

	m_bMasterReady = false;
	//m_nSummonedMonster = 0;

	m_nPassPlayer = 0;

	// 5�� ���� �ð�
	getCurrentTime( m_RegenTime );
	m_EventTime.tv_sec = m_RegenTime.tv_sec + pInfo->getStartDelay();
	m_EventTime.tv_usec = m_RegenTime.tv_usec;
	m_EventValue = 0;

	// �ٴڿ��� ���� �Ҳ��� �ھƿ����.
	// 3�ʸ���
	int lairAttackTick = pInfo->getLairAttackTick();
	int lairAttackMinNumber = pInfo->getLairAttackMinNumber();
	int lairAttackMaxNumber = pInfo->getLairAttackMaxNumber();

	//cout << "EffectCon: " << (int)m_pZone->getZoneID() << ", " << lairAttackTick << ", " << lairAttackMinNumber << ", " << lairAttackMaxNumber << endl;

	if (lairAttackMinNumber>0 && lairAttackMaxNumber>0)
	{
		// ����� �ִ� ���� Effect�� ���� ������.
		for (int i=0; i<10; i++) // ���ѷ��� ���� -_-;
		{
			Effect* pOldEffect = m_pZone->findEffect( Effect::EFFECT_CLASS_CONTINUAL_GROUND_ATTACK );
			if (pOldEffect==NULL)
				break;
			m_pZone->deleteEffect( pOldEffect->getObjectID() );
		}

		EffectContinualGroundAttack* pEffect = new EffectContinualGroundAttack(m_pZone, Effect::EFFECT_CLASS_GROUND_ATTACK, lairAttackTick);
		//EffectContinualGroundAttack* pEffect = new EffectContinualGroundAttack(m_pZone, Effect::EFFECT_CLASS_METEOR_STRIKE, lairAttackTick);
		pEffect->setDeadline( pInfo->getStartDelay()*10 );
		pEffect->setNumber( lairAttackMinNumber, lairAttackMaxNumber );

		ObjectRegistry & objectregister = m_pZone->getObjectRegistry();
		objectregister.registerObject(pEffect);

		// ����ٰ� ����Ʈ�� �߰��Ѵ�.
		m_pZone->addEffect( pEffect );

		// �ұ���
		GCNoticeEvent gcNoticeEvent;
		gcNoticeEvent.setCode( NOTICE_EVENT_CONTINUAL_GROUND_ATTACK );
		gcNoticeEvent.setParameter( pInfo->getStartDelay() );	// ��

		m_pZone->broadcastPacket( &gcNoticeEvent );
	}

	// ������ ��� ���ȴٰ� �����鿡�� �˷��ش�.
//	ZoneInfo* pZoneInfo = g_pZoneInfoManager->getZoneInfo( m_pZone->getZoneID() );
//	Assert(pZoneInfo!=NULL);

//	StringStream msg;
//	msg << "������ ����(" << pZoneInfo->getFullName().c_str() << ")�� ���Ƚ�ϴ�.";

//    char msg[50];
 //   sprintf( msg, g_pStringPool->c_str( STRID_MASTER_LAIR_OPENED ),
  //                  pZoneInfo->getFullName().c_str() );
//
 //   string sMsg( msg );
//
//	GCSystemMessage gcSystemMessage;
//	gcSystemMessage.setType(SYSTEM_MESSAGE_MASTER_LAIR);
//	gcSystemMessage.setMessage( sMsg );
//	g_pZoneGroupManager->broadcast( &gcSystemMessage );

	GCNoticeEvent gcNoticeEvent;

	gcNoticeEvent.setCode(NOTICE_EVENT_MASTER_LAIR_OPEN);
	gcNoticeEvent.setParameter( m_pZone->getZoneID() );

	g_pZoneGroupManager->broadcast( &gcNoticeEvent );

	// ��� ��� �ð� ���
	m_RegenTime.tv_sec += pInfo->getRegenDelay();

	m_Event = EVENT_WAITING_PLAYER;

	//cout << "[" << (int)m_pZone->getZoneID() << "] MasterLairManager::activeEventWaitingPlayer" << endl;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// active EventWaitingPlayer
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::activeEventMinionCombat() 
	throw (Error)
{
	__BEGIN_TRY

	MasterLairInfo* pInfo = g_pMasterLairInfoManager->getMasterLairInfo( m_pZone->getZoneID() );
	Assert(pInfo!=NULL);

	// �ұ��� �����ٴ� ��ȣ
	GCNoticeEvent gcNoticeEvent;
	gcNoticeEvent.setCode( NOTICE_EVENT_CONTINUAL_GROUND_ATTACK_END );
	m_pZone->broadcastPacket( &gcNoticeEvent );

	gcNoticeEvent.setCode( NOTICE_EVENT_MASTER_COMBAT_TIME );
	gcNoticeEvent.setParameter( pInfo->getEndDelay() );
	m_pZone->broadcastPacket( &gcNoticeEvent );


	// tile������ ������ packet� �� ������.
	deleteAllMonsters();

	// ������ ����
	Monster* pMaster = new Monster( pInfo->getMasterNotReadyMonsterType() );
	Assert(pMaster != NULL);

	// ��ü���� �������� �� ������� �Ѵ�.
	pMaster->setTreasure( false );

	// ���� ���·� ���
	pMaster->setFlag(Effect::EFFECT_CLASS_NO_DAMAGE);

	// �����͸� ������ �����
	// �����Ͱ� �˾Ƽ� �����͸� ��ȯ�ϰ� �ȴ�.

	try
	{
		m_pZone->addCreature(pMaster, pInfo->getMasterX(), pInfo->getMasterY(), pInfo->getMasterDir());

		// ObjectID�� �����صΰ� �о �����Ѵ�.
		m_MasterID = pMaster->getObjectID();
	}
	catch (EmptyTileNotExistException&)
	{
		// �����Ͱ� ��� �ڸ��� ���ٰ�? -_-;
		SAFE_DELETE(pMaster);
	}

	//m_nSummonedMonster = 0;  // �����Ͱ� ��ȯ�� ������ �� 

	m_Event = EVENT_MINION_COMBAT;
	m_EventValue = 0;

	// ������� �ο���?
	getCurrentTime( m_EventTime );
	m_EventTime.tv_sec += pInfo->getEndDelay();

	//cout << "[" << (int)m_pZone->getZoneID() << "] MasterLairManager::activeEventMinionCombat" << endl;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// active EventWaitingPlayer
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::activeEventMasterCombat() 
	throw (Error)
{
	__BEGIN_TRY

	Creature* pMaster = m_pZone->getMonsterManager()->getCreature( m_MasterID );
	// ���⼭ ������ ���� �ϵ��ڵ�� �ص� �ǰ���. - -;

	if (pMaster!=NULL)
	{
		MasterLairInfo* pInfo = g_pMasterLairInfoManager->getMasterLairInfo( m_pZone->getZoneID() );
		Assert(pInfo!=NULL);

		Monster* pMasterMonster = dynamic_cast<Monster*>(pMaster);

		// ��ȯ �ܰ��� ������ ���ſ� ��� �ο��� ������ �����ͷ� �ٲ۴�.
		if (pInfo->getMasterMonsterType()!=pMasterMonster->getMonsterType())
		{
		  	// ������ ����
			Monster* pNewMaster = new Monster( pInfo->getMasterMonsterType() );
			Assert(pNewMaster != NULL);

			// ��ü���� �������� �� ������� �Ѵ�.
			pNewMaster->setTreasure( false );

			try
			{
				m_pZone->addCreature(pNewMaster, pInfo->getSummonX(), pInfo->getSummonY(), pMaster->getDir());

				// ObjectID�� �����صΰ� �о �����Ѵ�.
				m_MasterID = pNewMaster->getObjectID();
			}
			catch (EmptyTileNotExistException&)
			{
				m_MasterID = 0;

				// �����Ͱ� ��� �ڸ��� ���ٰ�? -_-;
				SAFE_DELETE(pNewMaster);
			}

			// NotReady������ Master�� �׳� ���� �δ� ����
			if (pInfo->isMasterRemainNotReady())
			{
				ZoneCoord_t cx = pMasterMonster->getX();
				ZoneCoord_t cy = pMasterMonster->getY();

			 	// ���� �ٴڿ� �����߸�����, ����Ʈ�� �Ѹ���.
			   	GCAddEffect gcAddEffect;
			    gcAddEffect.setObjectID(pMasterMonster->getObjectID());
			    gcAddEffect.setEffectID(Effect::EFFECT_CLASS_COMA);
				gcAddEffect.setDuration(0);
			    m_pZone->broadcastPacket(cx, cy, &gcAddEffect);

				// AI�� ����ϰ� �״��� �д�.
				pMasterMonster->removeBrain();

				/*
				// ��������� ���ܵѷ��µ�.. AI����ϰ� �׳� �δ°� ����� ���Ƽ�
				m_pZone->deleteCreature( pMaster, pMaster->getX(), pMaster->getY() );

				ZoneCoord_t cx = pMasterMonster->getX();
				ZoneCoord_t cy = pMasterMonster->getY();

				Tile& tile = m_pZone->getTile( cx, cy );

				bool bCreateCorpse = true;

				// ��ü�� Ÿ�Ͽ� �߰��Ѵ�. ���� Ÿ�Ͽ� �������� ����Ѵٸ�,
				if (tile.hasItem())
				{
					bCreateCorpse = false;
				}

				// Zone�� ��ü(��)�� �߰��Ѵ�.
				if (bCreateCorpse)
				{
					Timeval currentTime;
					getCurrentTime(currentTime);
					int timeGap = m_EventTime.tv_sec - currentTime.tv_sec;
					Turn_t decayTurn = timeGap * 10;

					MonsterCorpse* pMonsterCorpse = new MonsterCorpse(pMasterMonster);
					TPOINT pt = m_pZone->addItem(pMonsterCorpse, cx, cy, true, decayTurn);
					if (pt.x == -1)
					{
						SAFE_DELETE(pMonsterCorpse);
					}
				}
				else
				{
					SAFE_DELETE(pMaster);
				}
				*/
			}
			else
			{
				m_pZone->deleteCreature( pMaster, pMaster->getX(), pMaster->getY() );

				SAFE_DELETE(pMaster);
			}
		}
		else
		{
			// ���� ���� ���
			// ���� �ִ� �����Ͱ� �� �����ͷ� ��ü���� �ʰ� ��� �ο��� �ϸ� ������ �����Ͱ� �����̾���Ƿ�
			// ����� Ǯ������ �Ѵ�. �� �����Ͱ� �ο��� �Ϸ�� ���� �����ʹ� NO_DAMAGE���·� �����־�� �Ѵ�.
			// �������� ���� �����Ͱ� ������ ���ε� �̰� �ʹ� ���� Ǯ���ִ� �ٶ��� ������ ���� NO_DAMAGE
			// �� Ǯ��� ������ ��� ����� ����ġ�� ��� �� �ְ� �Ǵ� ���װ� �־���.
			// �� if�� ������� ���� �־��� ��� else ���� �ű���. 2003. 1.16. by Sequoia
			pMaster->removeFlag(Effect::EFFECT_CLASS_NO_DAMAGE);
		}
	}

	m_Event = EVENT_MASTER_COMBAT;
	m_EventValue = 0;

	//cout << "[" << (int)m_pZone->getZoneID() << "[ MasterLairManager::activeEventMasterCombat" << endl;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// active EventWaitingPlayer
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::activeEventWaitingKickOut() 
	throw (Error)
{
	__BEGIN_TRY

	MasterLairInfo* pInfo = g_pMasterLairInfoManager->getMasterLairInfo( m_pZone->getZoneID() );
	Assert(pInfo!=NULL);

	// �����Ͱ� �� �׾��ٸ� �޼��� ����
	Creature* pMaster = m_pZone->getMonsterManager()->getCreature( m_MasterID );

	if (pMaster!=NULL && pMaster->isAlive())
	{
		GCSay gcSay;
		gcSay.setObjectID( pMaster->getObjectID() );
		gcSay.setColor( MASTER_SAY_COLOR );
		gcSay.setMessage( pInfo->getRandomMasterNotDeadSay() );
		if (!gcSay.getMessage().empty())
			m_pZone->broadcastPacket(pMaster->getX(), pMaster->getY(), &gcSay);
	}
	
    // ���� �����ڵ�� ����� �������� �ð� 
	m_Event = EVENT_WAITING_KICK_OUT;
	m_EventValue = 0;

	getCurrentTime( m_EventTime );
	m_EventTime.tv_sec += pInfo->getKickOutDelay();

	// Lair�� ����鿡�� ��� �ð�� �����ش�.
	GCNoticeEvent gcNoticeEvent;
	gcNoticeEvent.setCode( NOTICE_EVENT_KICK_OUT_FROM_ZONE );
	gcNoticeEvent.setParameter( pInfo->getKickOutDelay() );

	m_pZone->broadcastPacket( &gcNoticeEvent );

	//cout << "[" << (int)m_pZone->getZoneID() << "] MasterLairManager::activeEventKickOut" << endl;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// active EventWaitingPlayer
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::activeEventWaitingRegen() 
	throw (Error)
{
	__BEGIN_TRY

	deleteAllMonsters();

	// EffectContinualGroundAttack�� ���ش�.

	//m_nSummonedMonster = 0;
	m_nPassPlayer = 0;
	m_Event = EVENT_WAITING_REGEN;
	m_EventValue = 0;

	m_bMasterReady = false;

	//cout << "[" << (int)m_pZone->getZoneID() << "] MasterLairManager::activeEventWaitingRegen" << endl;
	

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// delete All Monsters
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::deleteAllMonsters()
	throw (Error)
{
	__BEGIN_TRY

	// Zone�� MonsterManager���� ����� ����� �����ش�.
	//m_pZone->getMonsterManager()->deleteCreature( m_pMaster->getObjectID() );
	//SAFE_DELETE(m_pMaster);
	bool bDeleteFromZone = true;
	m_pZone->getMonsterManager()->deleteAllMonsters( bDeleteFromZone );

	m_MasterID = 0;
	m_MasterX = 0;
	m_MasterY = 0;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// kill All Monsters
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::killAllMonsters()
	throw (Error)
{
	__BEGIN_TRY

	// �� �κп� ���� ����� �ִ°� ���� ����Ѵ�.

	/*
	// ����� ������ ��� ������
	map<ObjectID_t, ObjectID_t> exceptCreatures;
	exceptCreatures[m_MasterID] = m_MasterID;

	// ���� �����͸� ���δ�.
	m_pZone->getMonsterManager()->killAllMonsters( exceptCreatures );
	*/

	__END_CATCH
}
////////////////////////////////////////////////////////////////////////////////
//
// increase SummonedMonster Number
// 
////////////////////////////////////////////////////////////////////////////////
/*
void MasterLairManager::increaseSummonedMonsterNumber(int num) 
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	m_nSummonedMonster += num;

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}
*/
////////////////////////////////////////////////////////////////////////////////
//
// start Event
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::startEvent()
	throw (Error)
{
	__BEGIN_TRY

	activeEventWaitingPlayer();

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// start Event
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::stopEvent()
	throw (Error)
{
	__BEGIN_TRY

	kickOutPlayers();
	activeEventWaitingRegen();

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// kickOut Players
//
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::kickOutPlayers()
	throw (Error)
{
	__BEGIN_TRY

	MasterLairInfo* pInfo = g_pMasterLairInfoManager->getMasterLairInfo( m_pZone->getZoneID() );
	Assert(pInfo!=NULL);

	/*
	ZoneID_t 	zoneID 	= pInfo->getKickZoneID();
	ZoneCoord_t zoneX 	= pInfo->getKickZoneX();
	ZoneCoord_t zoneY 	= pInfo->getKickZoneY();

	//cout << "[kickOut] " << (int)zoneID << ": "<< (int)zoneX << ", " << (int)zoneY << endl;

	// ��� ���� �����ڵ�� �ٸ� ����� �̵���Ų��.
	PCManager* pPCManager = (PCManager*)(m_pZone->getPCManager());
	pPCManager->transportAllCreatures( zoneID, zoneX, zoneY );
	*/


	// �߹� �ð� �Ŀ��� ���׿� ����
	int lairAttackTick = pInfo->getLairAttackTick();
	int lairAttackMinNumber = pInfo->getLairAttackMinNumber();
	int lairAttackMaxNumber = pInfo->getLairAttackMaxNumber();

	EffectContinualGroundAttack* pEffect = new EffectContinualGroundAttack(m_pZone, Effect::EFFECT_CLASS_METEOR_STRIKE, lairAttackTick);
	pEffect->setDeadline( pInfo->getStartDelay()*10 );
	pEffect->setNumber( lairAttackMinNumber, lairAttackMaxNumber );

	ObjectRegistry & objectregister = m_pZone->getObjectRegistry();
	objectregister.registerObject(pEffect);

	// ����ٰ� ����Ʈ�� �߰��Ѵ�.
	m_pZone->addEffect( pEffect );

	// ���׿� ����
	GCNoticeEvent gcNoticeEvent;
	gcNoticeEvent.setCode( NOTICE_EVENT_CONTINUAL_GROUND_ATTACK );
	gcNoticeEvent.setParameter( pInfo->getStartDelay() );	// ��

	m_pZone->broadcastPacket( &gcNoticeEvent );

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// give Killing Reward
//
////////////////////////////////////////////////////////////////////////////////
// �����Ͱ� �׾������ ����
// ����� QuestItem� ���� ��� �����鿡�� ������ �κ��丮�� �־��ش�.
// �κ��丮�� �ڸ��� ���� ���쿣 �ٴڿ� �����߸��µ�
// �̹� ������ �ִ� ����� �ֿ� �� ����.
////////////////////////////////////////////////////////////////////////////////
void MasterLairManager::giveKillingReward() 
	throw (Error)
{
	__BEGIN_TRY

	const PCManager* pPCManager = m_pZone->getPCManager();
	const map< ObjectID_t, Creature* > & creatures = pPCManager->getCreatures();
	map< ObjectID_t, Creature* >::const_iterator itr;

	if (creatures.empty())
		return;

	int goodOneIndex = rand()%creatures.size();	// ����Ʈ�� ���� ����� �����ϱ�?

	ItemType_t itemType;
	int i;
	for (i=0, itr=creatures.begin(); itr!=creatures.end(); i++, itr++)
	{
		Creature* pCreature = itr->second;

		if (pCreature->isPC())
		{
			PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
			Inventory* pInventory = pPC->getInventory();

			//------------------------------------------------------------
			// ���� ����ġ�� �÷��ش�.
			//------------------------------------------------------------
			// ������ �ġ�� 7Ÿ�� �̳��� �̴� ����
			//
			if (pPC->getDistance(m_MasterX, m_MasterY) <= 7)
			{
				pPC->increaseRankExp( MASTER_KILL_RANK_EXP );
			}

			//------------------------------------------------------------
			// ���� ������� �����Ѵ�.
			//------------------------------------------------------------
			// �ϵ�. - -;
			switch (m_pZone->getZoneID())
			{
				// ���丮���� & Ŭ��
				case 1104 :
				case 1106 :
					itemType = ((goodOneIndex==i)? 1:0);
				break;

				// ������ ���� & Ŭ��
				case 1114 :
				case 1115 :
					itemType = ((goodOneIndex==i)? 3:2);
				break;

				default :
					filelog("MasterLairBUG.txt", "ZoneID�� �߸��Ǿ���ϴ�");
				return;

			}

			list<OptionType_t> nullList;
			Item* pItem = g_pItemFactoryManager->createItem(Item::ITEM_CLASS_QUEST_ITEM, itemType, nullList);
 
			(m_pZone->getObjectRegistry()).registerObject(pItem);

			// �κ��丮�� �� ��� ã�´�.
			_TPOINT p;
			if (pInventory->getEmptySlot(pItem, p))
			{
				// �κ��丮�� �߰��Ѵ�.
				pInventory->addItem(p.x, p.y, pItem);

	            pItem->create(pCreature->getName(), STORAGE_INVENTORY, 0, p.x, p.y);

				// ItemTrace �� Log �� ������
				if ( pItem != NULL && pItem->isTraceItem() )
				{
					remainTraceLog( pItem, "LairMaster", pCreature->getName(), ITEM_LOG_CREATE, DETAIL_EVENTNPC);
				}

				// �κ��丮�� ������ ���� ��Ŷ� �����ش�.
				GCCreateItem gcCreateItem;

				makeGCCreateItem( &gcCreateItem, pItem, p.x, p.y );

				pCreature->getPlayer()->sendPacket(&gcCreateItem);
			}
			else
			{
				// �κ��丮�� �ڸ��� ��� �ٴڿ� �����߸���.

				TPOINT p = m_pZone->addItem(pItem, pCreature->getX(), pCreature->getY());
				if (p.x != -1)
				{
					pItem->create("", STORAGE_ZONE, m_pZone->getZoneID(), p.x, p.y );

					// ItemTrace �� Log �� ������
					if ( pItem != NULL && pItem->isTraceItem() )
					{
						char zoneName[15];
						sprintf( zoneName , "%4d%3d%3d", m_pZone->getZoneID(), p.x, p.y);
						remainTraceLog( pItem, "LairMaster", zoneName, ITEM_LOG_CREATE, DETAIL_EVENTNPC);
					}
				}
				else
				{
					SAFE_DELETE(pItem);
				}
			}
		}
		else
		{
			throw Error("PCManager�� PC�ƴѰ� �����ֳ� -_-");
		}
	}

	__END_CATCH
}

string MasterLairManager::toString() const 
	throw(Error)
{
	StringStream msg;

	int eventSec = m_EventTime.tv_sec;

	switch (m_Event)
	{
		case EVENT_WAITING_PLAYER :     // �������� ������� ���ٸ���.
			msg << "WAITING_PLAYER, ";
		break;

		case EVENT_MINION_COMBAT:      // ��ȯ�� �����Ϳ� �ο���.
			msg << "MINION_COMBAT, ";
		break;

		case EVENT_MASTER_COMBAT:
			msg << "MASTER_COMBAT, ";
		break;

		case EVENT_WAITING_KICK_OUT:    // ������ ����߹� ����(������ ��� ������ ��� �ð�)
			msg << "WAITING_KICK_OUT, ";
		break;

		case EVENT_WAITING_REGEN:      // �ٽ� ����Ǳ� ���ٸ���.
			msg << "WAITING_REGEN, ";

			eventSec = m_RegenTime.tv_sec;
		break;

		default :
		break;
	}

	Timeval currentTime;
	getCurrentTime(currentTime);

	int timeGap = eventSec - currentTime.tv_sec;

	msg << timeGap << " sec remain, " << (int)m_pZone->getPCManager()->getSize() << " players";

	return msg.toString();
}
