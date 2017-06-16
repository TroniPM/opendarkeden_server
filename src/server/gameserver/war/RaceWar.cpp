///////////////////////////////////////////////////////////////////
// ���￡ ���� �������� ��� �� ���� ���� �� ����� ó����ƾ ����
///////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "RaceWar.h"
#include "Mutex.h"
#include "WarSystem.h"
#include "Properties.h"
#include "DB.h"
#include "Assert.h"
#include "ZoneGroupManager.h"
//#include "HolyLandRaceBonus.h"
#include "Zone.h"
#include "ZoneGroup.h"
#include "ZoneUtil.h"
#include "CastleInfoManager.h"
#include "ShrineInfoManager.h"
#include "ZoneInfoManager.h"
#include "PCManager.h"
#include "Gpackets/GCWarScheduleList.h"
#include "RaceWarInfo.h"
#include "HolyLandManager.h"
#include "VariableManager.h"
#include "RaceWarLimiter.h"
#include "RegenZoneManager.h"

#include "StringStream.h"

#include "Gpackets/GCSystemMessage.h"
#include "Gpackets/GCNoticeEvent.h"
#include "Cpackets/CGSay.h"

//--------------------------------------------------------------------------------
//
// constructor / destructor
//
//--------------------------------------------------------------------------------
RaceWar::RaceWar( WarState warState, WarID_t warID )
: War( warState, warID )
{
}

RaceWar::~RaceWar()
{
}

//--------------------------------------------------------------------------------
//
// executeStart
//
//--------------------------------------------------------------------------------
// ������ �����ϴ� ������� ó���ؾ� �� �͵�
//
// (!) Zone�� �پ��ִ� WarScheduler���� �����Ǵ� �κ��̹Ƿ� 
//     �ڽ��� Zone(��)�� ���� ó���� lock�� �ʿ�����.
//--------------------------------------------------------------------------------
void RaceWar::executeStart()
	throw (Error)
{
	__BEGIN_TRY

	sendWarStartMessage();

	// ���������� ���ʽ��� ����.
//	g_pHolyLandRaceBonus->clear();

	// ���� �߿��� NPC�� ��������.
	//g_pCastleInfoManager->deleteAllNPCs();

	// ���� �߿��� �� �ȿ��� ���� �ο���~
	g_pCastleInfoManager->releaseAllSafeZone();

	// ��ȣ���� ��ȣ���� ���� ��������.
	g_pShrineInfoManager->removeAllShrineShield();

	// �ƴ��� ���� ������ ���� ���� �ġ�� �����ش�.
	// �̰� ��� WarSystem::addWar �ȿ��� �ҷ��ش�.
	// g_pShrineInfoManager->broadcastBloodBibleStatus();
//	g_pHolyLandManager->sendBloodBibleStatus();

	// �ƴ��� ���� ������ �ð�� ����Ѵ�.
	g_pHolyLandManager->fixTimeband( g_pVariableManager->getVariable( RACE_WAR_TIMEBAND ) );

	g_pHolyLandManager->killAllMonsters();

	RegenZoneManager::getInstance()->putTryingPosition();
	RegenZoneManager::getInstance()->broadcastStatus();

	// hasActiveRaceWar()�� ����Ǵ� Ÿ�̹� ������..
	// WarSystem::addWar()���� �����Ѵ�.
	// �� ���￡ �������� �ʴ� ������� ��������.
	//g_pHolyLandManager->remainRaceWarPlayers();

	// RaceWarHistory Table �� ����
	recordRaceWarStart();

	__END_CATCH
}

void RaceWar::recordRaceWarStart()
	throw (Error)
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	Result* pResult  = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery("SELECT Race, SUM(CurrentNum) FROM RaceWarPCLimit GROUP BY Race");

		uint slayerSum  = 0;
		uint vampireSum = 0;
		uint oustersSum = 0;

		string slayerOld;
		string vampireOld;
		string oustersOld;

		while (pResult->next())
		{
			uint race = pResult->getInt(1);
			uint num  = pResult->getInt(2);

			if ( race == 0 )
				slayerSum = num;
			else if ( race == 1 )
				vampireSum = num;
			else if ( race == 2 )
				oustersSum = num;
		}

		pResult = pStmt->executeQuery("SELECT ID, OwnerRace FROM ShrineInfo");

		while (pResult->next())
		{
			uint id   		= pResult->getInt(1);
			uint ownerRace	= pResult->getInt(2);

			if ( ownerRace == 0 )
				slayerOld = slayerOld + itos(id) + "|";
			else if ( ownerRace == 1 )
				vampireOld = vampireOld + itos(id) + "|";
			else if ( ownerRace == 2 )
				oustersOld = oustersOld + itos(id) + "|";
		}

		pStmt->executeQuery("INSERT INTO RaceWarHistory (RaceWarID, SlayerNum, VampireNum, OustersNum, SlayerOldBloodBible, VampireOldBloodBible, OustersOldBloodBible) VALUES ('%s', %d, %d, %d, '%s', '%s', '%s')",
						getWarStartTime().toStringforWeb().c_str(),
						slayerSum, vampireSum, oustersSum,
						slayerOld.c_str(),
						vampireOld.c_str(),
						oustersOld.c_str() );
	}
	END_DB(pStmt)

	__END_CATCH
}

//--------------------------------------------------------------------------------
//
// executeEnd
//
//--------------------------------------------------------------------------------
// ������ ������ ������� ó���ؾ� �� �͵�
//--------------------------------------------------------------------------------
void RaceWar::executeEnd()
	throw (Error)
{
	__BEGIN_TRY

	//----------------------------------------------------------------------------
	// ���� �����ٴ� �� �˸���.
	//----------------------------------------------------------------------------
	sendWarEndMessage();

	//----------------------------------------------------------------------------
	// ������ ���� ó��
	//----------------------------------------------------------------------------
	// ���� ��û�� ���ΰŴ� ��� �ұ�? ���� _-_;
	// ���������� ���� ���ʽ��� �ٽ� �Ҵ�.
//	g_pHolyLandRaceBonus->refresh();

	//----------------------------------------------------------------------------
	// ���� ���� ���� �ǵ����ش�.
	//----------------------------------------------------------------------------
	g_pShrineInfoManager->returnAllBloodBible();

	g_pShrineInfoManager->addAllShrineShield();
	
	g_pCastleInfoManager->resetAllSafeZone();

	g_pCastleInfoManager->transportAllOtherRace();

	//g_pCastleInfoManager->loadAllNPCs();

	// �ƴ��� ���� ������ ���� ���� �ġ�� �����ش�.
	//g_pHolyLandManager->sendBloodBibleStatus();
	g_pShrineInfoManager->broadcastBloodBibleStatus();

	// �ƴ��� ���� ������ ����ߴ� �ð�� �ٽ� ������.
	g_pHolyLandManager->resumeTimeband();

	// ���� ������ ����Ʈ�� ���� ����Ѵ�.
	RaceWarLimiter::clearPCList();

	// ������ ���ڸ� 0��� �ٲ۴�.
	RaceWarLimiter::getInstance()->clearCurrent();
	RegenZoneManager::getInstance()->deleteTryingPosition();
	RegenZoneManager::getInstance()->reload();

	// ĳ���͵��� Flag�� ���� ����Ѵ�.
	g_pZoneGroupManager->removeFlag( Effect::EFFECT_CLASS_RACE_WAR_JOIN_TICKET );

	CGSayHandler::opworld(NULL, "*world *load blood_bible_owner", 0, true);

	// RaceWarHistory Table �� ����
	recordRaceWarEnd();

	__END_CATCH
}

void RaceWar::recordRaceWarEnd()
	throw (Error)
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	Result* pResult  = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		pResult = pStmt->executeQuery("SELECT ID, OwnerRace FROM ShrineInfo");

		string slayerNew;
		string vampireNew;
		string oustersNew;

		while (pResult->next())
		{
			uint id   		= pResult->getInt(1);
			uint ownerRace	= pResult->getInt(2);

			if ( ownerRace == 0 )
				slayerNew = slayerNew + itos(id) + "|";
			else if ( ownerRace == 1 )
				vampireNew = vampireNew + itos(id) + "|";
			else if ( ownerRace == 2 )
				oustersNew = oustersNew + itos(id) + "|";
		}

		pStmt->executeQuery("UPDATE RaceWarHistory SET SlayerBloodBible = '%s', VampireBloodBible = '%s', OustersBloodBible = '%s' WHERE RaceWarID = '%s'",
						slayerNew.c_str(),
						vampireNew.c_str(),
						oustersNew.c_str(),
						getWarStartTime().toStringforWeb().c_str() );
	}
	END_DB(pStmt)

	// script ������ ��.,�� system �Լ��� ���� �� ���̾� !_!
	char cmd[100];
	sprintf(cmd, "/home/darkeden/vs/bin/script/recordRaceWarHistory.py %s %d %d ",
					getWarStartTime().toStringforWeb().c_str(),
					g_pConfig->getPropertyInt("Dimension"),
					g_pConfig->getPropertyInt("WorldID") );

	filelog("script.log", cmd);
	system(cmd);
	
	__END_CATCH
}

string RaceWar::getWarName() const
	throw (Error)
{
	__BEGIN_TRY

	return "���� ����";

	__END_CATCH
}

//--------------------------------------------------------------------------------
// ���� ���� ��
//--------------------------------------------------------------------------------
void RaceWar::sendWarEndMessage() const
    throw (ProtocolException, Error)
{
    __BEGIN_TRY

	War::sendWarEndMessage();

	// �������� ��� Ȯ��? ��Ŷ
	GCNoticeEvent gcNoticeEvent;
	gcNoticeEvent.setCode( NOTICE_EVENT_RACE_WAR_OVER );
	g_pZoneGroupManager->broadcast( &gcNoticeEvent );

    __END_CATCH
}


void    RaceWar::makeWarScheduleInfo( WarScheduleInfo* pWSI ) const 
	throw (Error)
{
	__BEGIN_TRY

    pWSI->warType 				= getWarType();
    pWSI->challengerGuildID		= 0;
    pWSI->challengerGuildName	= "";

	__END_CATCH
}

void 	RaceWar::makeWarInfo(WarInfo* pWarInfo) const 
	throw (Error)
{
	__BEGIN_TRY

	Assert(pWarInfo!=NULL);
	Assert(pWarInfo->getWarType()==WAR_RACE);

	RaceWarInfo* pRaceWarInfo = dynamic_cast<RaceWarInfo*>(pWarInfo);
	Assert(pRaceWarInfo!=NULL);

	const map<ZoneID_t, CastleInfo*>& castleInfos = g_pCastleInfoManager->getCastleInfos();

	map<ZoneID_t, CastleInfo*>::const_iterator itr = castleInfos.begin();

	for ( ; itr!=castleInfos.end(); itr++)
	{
		CastleInfo* pCastleInfo = itr->second;
		pRaceWarInfo->addCastleID( pCastleInfo->getZoneID() );
	}

	__END_CATCH
}


string RaceWar::toString() const
	throw (Error)
{
	__BEGIN_TRY

	StringStream msg;
	
	msg << "RaceWar("
		<< "WarID:" << (int)getWarID()
		<< ",State:" << (int)getState()
		<< ")";

	return msg.toString();

	__END_CATCH
}
