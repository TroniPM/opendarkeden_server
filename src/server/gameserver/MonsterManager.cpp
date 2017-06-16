////////////////////////////////////////////////////////////////////////////////
// Filename    : MonsterManager.h 
// Written By  : Reiot
// Revised by  : �輺��
// Description : 
////////////////////////////////////////////////////////////////////////////////


#include "MonsterManager.h"
#include <stdlib.h>			// atoi()
#include "Assert.h"
#include "LogClient.h"
#include "MonsterInfo.h"
#include "ItemInfoManager.h"
#include "Creature.h"
#include "GamePlayer.h"
#include "MonsterCorpse.h"
#include "Tile.h"
#include "Zone.h"
#include "Player.h"
#include "Monster.h"
#include "OptionInfo.h"
#include "Skull.h"
#include "DB.h"
#include "Treasure.h"
#include "Thread.h"
#include "ItemFactoryManager.h"
#include "ZoneUtil.h"
#include "CreatureUtil.h"
#include "VariableManager.h"
#include "MonsterNameManager.h"
#include "MasterLairInfoManager.h"
#include "LuckInfo.h"
#include "ItemUtil.h"
#include "EventItemUtil.h"
#include "WarSystem.h"
#include "Properties.h"
#include "CastleInfoManager.h"
#include "SweeperBonusManager.h"
#include "skill/SummonGroundElemental.h"
#include "EffectPacketSend.h"
#include "ItemGradeManager.h"

#include <fstream>

#include "Gpackets/GCCreatureDied.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCAddEffectToTile.h"
#include "Gpackets/GCDeleteObject.h"
#include "Gpackets/GCSay.h"

#include "Profile.h"

#define __MONSTER_FIGHTING__
extern bool isPotentialEnemy(Monster* pMonster, Creature* pCreature);

//#define __PROFILE_MONSTER__

#ifdef __PROFILE_MONSTER__
	#define __BEGIN_PROFILE_MONSTER(name)	beginProfileEx(name);
	#define __END_PROFILE_MONSTER(name)		endProfileEx(name);
#else
	#define __BEGIN_PROFILE_MONSTER(name)	((void)0);
	#define __END_PROFILE_MONSTER(name)		((void)0);
#endif

////////////////////////////////////////////////////////////////////////////////
// ���ȭ� ������ ����Ȯ�� ���ʽ� �ۼ�Ʈ
////////////////////////////////////////////////////////////////////////////////
//const uint g_pVariableManager->getPremiumItemProbePercent() = 220;

bool isLottoWinning();

////////////////////////////////////////////////////////////////////////////////
//
// constructor
//
////////////////////////////////////////////////////////////////////////////////
MonsterManager::MonsterManager (Zone* pZone) 
	throw (Error)
{
	__BEGIN_TRY
		
	Assert(pZone != NULL);
	m_pZone = pZone;

	Assert(g_pCastleInfoManager!=NULL);
	m_CastleZoneID = 0;
	g_pCastleInfoManager->getCastleZoneID( m_pZone->getZoneID(), m_CastleZoneID );

	m_nEventMonster = 0;
	m_pEventMonsterInfo = NULL;

	getCurrentTime(m_RegenTime);

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// destructor
//
////////////////////////////////////////////////////////////////////////////////
MonsterManager::~MonsterManager () 
	throw ()
{
	__BEGIN_TRY

	SAFE_DELETE(m_pEventMonsterInfo);

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// load from database
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::load ()
	throw (Error)
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	Result*    pResult = NULL;
	string     text, eventText;

	m_RICE_CAKE_PROB_RATIO[0] = 100;
	m_RICE_CAKE_PROB_RATIO[1] = 33;
	m_RICE_CAKE_PROB_RATIO[2] = 33;
	m_RICE_CAKE_PROB_RATIO[3] = 33;
	m_RICE_CAKE_PROB_RATIO[4] = 1;
	m_SumOfCakeRatio = 0;

	for (int i=0; i<5; i++)
		m_SumOfCakeRatio += m_RICE_CAKE_PROB_RATIO[i];

	// �̹� �ִٸ� ����� MonsterCounter��� ���� ������.
	bool bReload = false;
	map< SpriteType_t, MonsterCounter* >::iterator iMC = m_Monsters.begin();
	while (iMC!=m_Monsters.end())
	{
		MonsterCounter* pMC = iMC->second;
		SAFE_DELETE(pMC);

		iMC ++;

		// m_Monsters�� �̹� �־��ٸ� reload�� ���̴�..���� ����. by sigi. 2002.9.19
		bReload = true;
	}

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery(
		"SELECT MonsterList, EventMonsterList from ZoneInfo WHERE ZoneID=%d", m_pZone->getZoneID());

		if (pResult->getRowCount() <= 0) 
		{
			SAFE_DELETE(pStmt);
//			throw Error("MonsterManager::load() : ��� ������� �ʽ�ϴ�.");
			return;
		}

		pResult->next();
		text = pResult->getString(1);
		eventText = pResult->getString(2);

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)


	parseMonsterList( text, bReload );
	parseEventMonsterList( eventText, bReload );

	__END_CATCH
}

void MonsterManager::parseMonsterList(const string& text, bool bReload)
	throw (Error)
{
	if (text.size() <= 0) return;

	//--------------------------------------------------------------------------------
	//
	// text �Ķ����ʹ� ZoneInfo ���̺��� Monsters (TEXT) �÷���� ��Ÿ����.
	// ����� ����� ����.
	//
	// (MonsterType1,#Monster1) (MonsterType2,#Monter2)(..,..)
	// i            j         k i            j        k    
	//
	//--------------------------------------------------------------------------------
	
	uint i = 0 , j = 0 , k = 0;

	do 
	{
		// parse string
		i = text.find_first_of('(',k);
		j = text.find_first_of(',',i+1);
		k = text.find_first_of(')',j+1);

		if (i==string::npos || j==string::npos || k==string::npos
			|| i > j || j > k) break;

		// ������ Ÿ�԰� �ִ� ������ ���Ѵ�. ������ Ÿ�԰� �ִ� ������ ���Ѵ�.
		uint monsterType = atoi(text.substr(i+1,j-i-1).c_str());
		uint maxMonsters = atoi(text.substr(j+1,k-j-1).c_str());

		Assert(maxMonsters > 0);

		// ������ ������ ���� Monster Sprite Type� �޾ƿ´�.
		const MonsterInfo* pMonsterInfo = g_pMonsterInfoManager->getMonsterInfo(monsterType);
		SpriteType_t spriteType = pMonsterInfo->getSpriteType();

		// �̹� ����ϴ����� ���θ� üũ�Ѵ�.
		map< SpriteType_t , MonsterCounter* >::iterator itr = m_Monsters.find(spriteType);

		if (itr != m_Monsters.end()) 
		{
			WORD CurrentMaxCount = itr->second->getMaxMonsters();
			WORD NewMaxCount = CurrentMaxCount + maxMonsters;
			itr->second->setMaxMonsters(NewMaxCount);
		} 
		else 
		{
			// ������ī���� ��ü�� ����, map �� �����Ѵ�.
			MonsterCounter* pMonsterCounter = new MonsterCounter(monsterType , maxMonsters, 0);

			// ������� �ʴ� ����, �߰��Ѵ�.
			m_Monsters[spriteType] = pMonsterCounter;
		}

		//--------------------------------------------------------------------------------
		// �ش��ϴ� Ÿ���� �����͸� ��� �߰��Ѵ�.
		//--------------------------------------------------------------------------------
		if (!bReload) // reload�� �ƴϸ�..
		{
			for (uint m = 0 ; m < maxMonsters ; m ++) 
			{
				// ��� �� ��ǥ�� ã�Ƴ���.
				ZoneCoord_t x, y;
				if (!findPosition(monsterType, x, y))
				{
					Assert(false);
					return;
				}

				// ������ ��ü�� �����ϰ� �ɷ�ġ ��� �ʱ�ȭ�Ѵ�.
				Monster* pMonster = new Monster(monsterType);

				////////////////////////////////////////////////////////////////////////////////
				// ������ �̺�Ʈ ����(7�� 1�Ϻ��ʹ� ������)
				/*
				if(rand()%g_pVariableManager->getEventRatio() == 0 &&
						g_pVariableManager->getEventActivate() == 1)
				{
				  pMonster->setEventMonsterFlag(true);
				  string MonsterName =  g_pMonsterNameManager->getRandomName(pMonster, true);
				  pMonster->setName(MonsterName);
				  //cout << "�̺�Ʈ ������ �̸�: " << pMonster->getName();
				}
				*/
				///////////////////////////////////////////////////////////////////////////
				Assert(pMonster != NULL);

				try
				{
					m_pZone->addCreature(pMonster , x , y , Directions(rand() & 0x07));
				}
				catch (EmptyTileNotExistException&)
				{
					//cerr << "MonsterManager::load() : �ڸ��� ����?" << endl;
					SAFE_DELETE(pMonster);
				}

			}
		}
	} while (k < text.size() - 1);
}

void MonsterManager::parseEventMonsterList(const string& text, bool bReload)
	throw (Error)
{
	if (text.size() <= 0) return;

	//--------------------------------------------------------------------------------
	//
	// text �Ķ����ʹ� ZoneInfo ���̺��� Monsters (TEXT) �÷���� ��Ÿ����.
	// ����� ����� ����.
	//
	// (MonsterType1,#Monster1,RegenDelay) (MonsterType2,#Monter2,RegenDelay)(..,..)
	// i            j         k          l i            j        k          l
	//
	//--------------------------------------------------------------------------------
	
	uint i = 0 , j = 0 , k = 0, l = 0;

	do 
	{
		// parse string
		i = text.find_first_of('(',l);
		j = text.find_first_of(',',i+1);
		k = text.find_first_of(',',j+1);
		l = text.find_first_of(')',k+1);

		if (i==string::npos || j==string::npos || k==string::npos || l==string::npos
			|| i > j || j > k || k > l) break;

		// ������ Ÿ�԰� �ִ� ������ ���Ѵ�. ������ Ÿ�԰� �ִ� ������ ���Ѵ�.
		uint monsterType = atoi(text.substr(i+1,j-i-1).c_str());
		uint maxMonsters = atoi(text.substr(j+1,k-j-1).c_str());
		uint regenDelay  = atoi(text.substr(k+1,l-k-1).c_str());

		Assert(maxMonsters > 0);

		//--------------------------------------------------------------------------------
		// �ش��ϴ� Ÿ���� �����͸� ��� �߰��Ѵ�.
		//--------------------------------------------------------------------------------
		if (!bReload) // reload�� �ƴϸ�..
		{
			//cout << "[MM] load EventMonsterList: [" << m_pZone->getZoneID() << "] mtype=" << monsterType
			//	<< ", maxMonsters=" << maxMonsters
			//	<< ", regenDelay=" << regenDelay << endl;
			if (m_pEventMonsterInfo==NULL)
			{
				m_pEventMonsterInfo = new vector<EventMonsterInfo>;
				//m_pEventMonsterInfo->resize( maxMonsters );
			}

			/*
			if (m_pEventMonsterInfo->size() + maxMonsters < m_pEventMonsterInfo->capacity())
			{
				m_pEventMonsterInfo->resize( m_pEventMonsterInfo->size() + maxMonsters );
			}
			*/

			for (uint m = 0 ; m < maxMonsters ; m ++) 
			{
				if (g_pVariableManager->isActiveChiefMonster())
				{
					// ��� �� ��ǥ�� ã�Ƴ���.
					ZoneCoord_t x, y;
					if (!findPosition(monsterType, x, y))
					{
						Assert(false);
						return;
					}

					// ���� ��ü�� �����ϰ� �ɷ�ġ ��� �ʱ�ȭ�Ѵ�.
					Monster* pMonster = new Monster(monsterType);
					Assert(pMonster != NULL);

					pMonster->setEventMonsterIndex( m_nEventMonster++ );

					EventMonsterInfo info;
					info.monsterType = monsterType;
					info.regenDelay = regenDelay;
					info.bExist = true;

					m_pEventMonsterInfo->push_back( info );

					try
					{
						m_pZone->addCreature(pMonster , x , y , Directions(rand() & 0x07));
					}
					catch (EmptyTileNotExistException&)
					{
						//cerr << "MonsterManager::load() : �ڸ��� ����?" << endl;
						SAFE_DELETE(pMonster);
					}
				}
				else
				{
					m_nEventMonster++;

					EventMonsterInfo info;
					info.monsterType = monsterType;
					info.regenDelay = regenDelay;
					getCurrentTime( info.regenTime );
					info.bExist = false;

					m_pEventMonsterInfo->push_back( info );
				}

			}
		}
	} while (l < text.size() - 1);


}

////////////////////////////////////////////////////////////////////////////////
void MonsterManager::addCreature (Creature* pCreature)
	throw (DuplicatedException , Error)
{
	__BEGIN_TRY

	Monster* pMonster = dynamic_cast<Monster*>(pCreature);

	// ũ��ó �ؽ��ʿ� �߰��Ѵ�.
	CreatureManager::addCreature(pMonster);

	// event monster�� MonsterCounter�� ����� �ʰ� �Ѵ�. by sigi. 2002.10.14
	if (m_pEventMonsterInfo!=NULL 
		&& pMonster->isEventMonster())
	{
		uint index = pMonster->getEventMonsterIndex();

		if (index < m_pEventMonsterInfo->size())
		{
			EventMonsterInfo& info = (*m_pEventMonsterInfo)[index];

			getCurrentTime( info.regenTime );
			info.regenTime.tv_sec += info.regenDelay;

			info.bExist = true;
		}

		//cout << "[MM] add EventMonster: [" << pMonster->getEventMonsterIndex()
		//	<< "] = " << info.monsterType << ", delay = " << info.regenDelay << endl;
		return;
	}

	// �׷� ������ Ÿ���� ��� ����� �� �ִ��� üũ�Ѵ�.
	map< SpriteType_t , MonsterCounter* >::iterator itr = m_Monsters.find(pMonster->getSpriteType());

	if (itr == m_Monsters.end()) 
	{
		StringStream msg;
		msg << "���� ��� ����� �� ���� Ÿ���� �����Ͱ� �߰��Ǿ���ϴ�.\n" 
			<< "���� �� [" << m_pZone->getZoneID() << "]�Դϴ�.\n"
			<< "�߰��Ϸ�� �� �������� Ÿ��� [" << pMonster->getMonsterType() << "]�Դϴ�.\n";
		//throw Error(msg.toString());
	}
	else
	{ 
		// ������ ī���͸� ����Ų��.
		itr->second->addMonster();
	}

	__END_CATCH
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::deleteCreature (ObjectID_t creatureID)
	throw ()//NoSuchElementException , Error)
{
	__BEGIN_TRY

	// ũ��ó �ؽ��ʿ� �׷� OID �� ���� �����Ͱ� ����ϴ��� üũ�Ѵ�.
	map<ObjectID_t , Creature* >::iterator itr = m_Creatures.find(creatureID);

	if (itr == m_Creatures.end()) 
	{
		cerr << "MonsterManager::deleteCreature() : NoSuchElementException" << endl;
		
		// �̰͵� �ܺο��� ����� ó�� �ȵǰ� �ִ°� ����.
		// by sigi. 2002.5.9
		//throw NoSuchElementException("�׷� ObjectID�� ���� �����ʹ� ������� �ʽ�ϴ�.");
		
		return;
	}

	Monster* pMonster = dynamic_cast<Monster*>(itr->second);

	// ũ��ó �ؽ����� �ش� ���带 ����Ѵ�.
	// �Լ� ���� �ִ��� ������ �÷ȴ�. by sigi
	// �ٺ���~ itr ����� ������ ���带 ������¡~. 2002.10.12 by bezz
	m_Creatures.erase(itr);


	// event monster�� MonsterCounter�� ��������. by sigi .2002.10.14
	if (m_pEventMonsterInfo!=NULL
		&& pMonster->isEventMonster())
	{
		uint index = pMonster->getEventMonsterIndex();

		if (index < m_pEventMonsterInfo->size())
		{
			EventMonsterInfo& info = (*m_pEventMonsterInfo)[index];
			info.bExist = false;
			//cout << "[MM] delete EventMonster: [" << pMonster->getEventMonsterIndex()
			//	<< "] = " << info.monsterType << endl;
		}

		return;
	}

	// ������ ī���Ϳ� �׷� ������ Ÿ���� ����ϴ��� üũ�Ѵ�.
	map< SpriteType_t , MonsterCounter *>::iterator itr2 = m_Monsters.find(pMonster->getSpriteType());

	if (itr2 == m_Monsters.end()) 
	{
		cerr << "MonsterManager::deleteCreature() : NoSuchElementException" << endl;
		//throw NoSuchElementException("�׷� SpriteType� ���� �����ʹ� ������� �ʽ�ϴ�.");
	}
	else 
	{
		// �������� ���ڸ� ���δ�.
		itr2->second->deleteMonster();
	}


	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ��ü�� �������� ����� �ν��Ѵ�. 2002.7.22 by sigi
// pAttackedMonster�� pCreature�� ������ ���쿡
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::addPotentialEnemy(Monster* pAttackedMonster, Creature* pCreature) 
	throw(Error)
{
	__BEGIN_TRY

	//cout << "MonsterManager::addPotentialEnemy()" << endl;
		
	map< ObjectID_t , Creature* >::const_iterator itr = m_Creatures.begin();

	for (; itr!=m_Creatures.end(); itr++) 
	{
		Creature* pMonsterCreature = itr->second;

		// ���� ��� ���� �ִ� �Ÿ����� �Ѵ�.
		Distance_t dist = pMonsterCreature->getDistance(pCreature->getX(), pCreature->getY());

		if (dist <= pMonsterCreature->getSight() 
			// �ڽ�� �ٸ� �ڵ忡�� üũ�Ѵ�.
			&& pMonsterCreature!=pAttackedMonster)
		{
			Monster* pMonster = dynamic_cast<Monster*>(pMonsterCreature);
			//cout << "addPotentialEnemy: " << pMonster->getName().c_str() << endl;
			pMonster->addPotentialEnemy( pCreature );
		}
	}
		

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ��ü�� ����� �ν��Ѵ�. 2002.7.22 by sigi
// pAttackedMonster�� pCreature�� ������ ���쿡
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::addEnemy(Monster* pAttackedMonster, Creature* pCreature) 
	throw(Error)
{
	__BEGIN_TRY
		
	//cout << "MonsterManager::addEnemy()" << endl;

	map< ObjectID_t , Creature* >::const_iterator itr = m_Creatures.begin();

	for (; itr!=m_Creatures.end(); itr++) 
	{
		Creature* pMonsterCreature = itr->second;

		// ���� ��� ���� �ִ� �Ÿ����� �Ѵ�.
		Distance_t dist = pMonsterCreature->getDistance(pCreature->getX(), pCreature->getY());

		if (dist <= pMonsterCreature->getSight() 
			// �ڽ�� �ٸ� �ڵ忡�� üũ�Ѵ�.
			&& pMonsterCreature!=pAttackedMonster)
		{
			Monster* pMonster = dynamic_cast<Monster*>(pMonsterCreature);
			//cout << "addEnemy: " << pMonster->getName().c_str() << endl;
			pMonster->addEnemy( pCreature );
		}
	}
		

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ũ��ó �Ŵ����� ��ӵ� �����͵��� AI�� ���� �׼�� �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::processCreatures ()
	throw (Error)
{
	__BEGIN_TRY

//	__BEGIN_PROFILE_MONSTER("MM_PROCESS_CREATURES");

	Timeval currentTime;
	getCurrentTime(currentTime);

	try
	{
		map< ObjectID_t , Creature* >::iterator before = m_Creatures.end();
		map< ObjectID_t , Creature* >::iterator current = m_Creatures.begin();

		while (current != m_Creatures.end()) 
		{
			Creature* pCreature = current->second;

			Assert(pCreature != NULL);

			__BEGIN_PROFILE_MONSTER("MM_EFFECTMANAGER");

			pCreature->getEffectManager()->heartbeat(currentTime);

			__END_PROFILE_MONSTER("MM_EFFECTMANAGER");

			if (pCreature->isAlive()) 
			{
				/*
				Monster* pMonster = dynamic_cast<Monster*>(pCreature);

				if (pMonster->isEnemyLimit())
				{
					Zone* 		pZone 	= pMonster->getZone();
					ZoneCoord_t cx 		= pMonster->getX();
					ZoneCoord_t cy 		= pMonster->getY();
					ObjectID_t 	monsterID = pMonster->getObjectID();

					map< SpriteType_t , MonsterCounter *>::iterator itr = m_Monsters.find(pMonster->getSpriteType());

					if (itr == m_Monsters.end()) 
					{
						//cerr << "MonsterManager::processCreatures() : NoSuchElementException" << endl;
						//throw NoSuchElementException("�׷� SpriteType� ���� �����ʹ� ������� �ʽ�ϴ�.");
					}
					else
					{
						// �������� ���ڸ� ���δ�.
						itr->second->deleteMonster();
					}


					// Ÿ�ϰ� ������ �Ŵ������� ũ��ó�� ����Ѵ�.
					Tile & tile = pZone->getTile(cx , cy);
					tile.deleteCreature(monsterID);

					SAFE_DELETE(pMonster);

					if (before == m_Creatures.end()) 
					{
						m_Creatures.erase(current);
						current = m_Creatures.begin();
					} 
					else 
					{
						m_Creatures.erase(current);
						current = before;
						current ++;
					}

					GCDeleteObject gcDeleteObject;
					gcDeleteObject.setObjectID(monsterID);

					pZone->broadcastPacket(cx, cy , &gcDeleteObject);
				}
			*/
				__BEGIN_PROFILE_MONSTER("MM_CREATURE_ACT");
				pCreature->act(currentTime);
				before = current ++;
				__END_PROFILE_MONSTER("MM_CREATURE_ACT");
			} 
			else
			{

				Monster* pMonster = dynamic_cast<Monster*>(pCreature);
				Assert(pMonster != NULL);

				/*if ( pMonster->getMonsterType() == 371 ||
				     pMonster->getMonsterType() == 372 ||
				     pMonster->getMonsterType() == 373 ||
				     pMonster->getMonsterType() == 374 ||
				     pMonster->getMonsterType() == 375 ||
				     pMonster->getMonsterType() == 376)
					return;
				else
				{*/

					if (pMonster->isEventMonster())		// by sigi. 2002.10.14
					{
						if (m_pEventMonsterInfo!=NULL)
						{
							uint index = pMonster->getEventMonsterIndex();

							if (index < m_pEventMonsterInfo->size())
							{
								EventMonsterInfo& info = (*m_pEventMonsterInfo)[index];
								info.bExist = false;

								//cout << "[MM] dead EventMonster: [" << pMonster->getEventMonsterIndex()
								//	<< "] = " << info.monsterType << endl;
							}
						}
					}
					else
					{
						// ������ ī���͸� �ϳ� ���δ�.
						map< SpriteType_t , MonsterCounter *>::iterator itr = m_Monsters.find(pMonster->getSpriteType());

						if (itr == m_Monsters.end()) 
						{
							//cerr << "MonsterManager::processCreatures() : NoSuchElementException" << endl;
							//throw NoSuchElementException("�׷� SpriteType� ���� �����ʹ� ������� �ʽ�ϴ�.");
						}
						else
						{
							// �������� ���ڸ� ���δ�.
							itr->second->deleteMonster();
						}
					}

				__BEGIN_PROFILE_MONSTER("MM_CREATURE_DEADACTION");
					// ���� �����͸� ���̱� ���� ������ �׼�� ���ϰ� �Ѵ�.
					pMonster->actDeadAction();
				__END_PROFILE_MONSTER("MM_CREATURE_DEADACTION");

				__BEGIN_PROFILE_MONSTER("MM_KILL_CREATURE");
					// �����͸� ����� ����ϰ�, ���ε�ĳ��Ʈ�Ѵ�.
					killCreature(pMonster);
				__END_PROFILE_MONSTER("MM_KILL_CREATURE");

					// �����Ϳ� ���� ũ��ó�� �ؽ����� ���带 ����Ѵ�.
					// �߸� ����� ����, ������ ���� ����� ����� ������ ��.
					if (before == m_Creatures.end()) 
					{
						m_Creatures.erase(current);
						current = m_Creatures.begin();
					} 
					else 
					{
						m_Creatures.erase(current);
						current = before;
						current ++;
					}
				//}

			}
		}

		// ������ ���� �ڵ忡 findPosition�̶��� ���� ���� �Լ��� �ϳ� �ִ�.
		// 30�� ���� ���� ������ �����Ͱ� �׾�� ��, �� �����͵�� ����� �ڸ��� ã�µ� 
		// �ɸ��� �ð��� ������ ���� �ִ�. �׸��� �� �ð��� �������� ����
		// �߻��Ѵ�. ��������δ� � �����������, ��� ���̱� ��ؼ� 
		// ����� ���� �˻縦 ���� �ϵ��� �����Ѵ�. -- �輺��
		// ��� �ֱ⸶�� ������ ���ڸ� Ȯ���ؼ� ��������ش�.
		if (m_RegenTime < currentTime)
		{
			__BEGIN_PROFILE_MONSTER("MM_REGENERATE_CREATURES");

			regenerateCreatures();

			m_RegenTime.tv_sec  = currentTime.tv_sec + 5;	// 5�� �� ���
			m_RegenTime.tv_usec = currentTime.tv_usec;

			__END_PROFILE_MONSTER("MM_REGENERATE_CREATURES");
		}

		// �̰� �� �ּ�ó�� �ȵǾ��־���.. by sigi. 2002.5.3
		//regenerateCreatures();
	}
	catch (Throwable & t)
	{
		filelog("MonsterManagerBug.log", "ProcessCreatureBug : %s", t.toString().c_str());
		//cerr << t.toString() << endl;
	}

//	__END_PROFILE_MONSTER("MM_PROCESS_CREATURES");

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// �������� ���ڰ� �پ����� �����͸� �������Ѵ�.
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::regenerateCreatures ()
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	// ���� �߿� ������ ��� �ȵǰ�..
	if (m_pZone->isHolyLand()) 
	{
		// �� ���� ��
		if (g_pWarSystem->hasActiveRaceWar())
			return;

		// ���� ���� ��..
		if (m_CastleZoneID!=0 && g_pWarSystem->hasCastleActiveWar(m_CastleZoneID))
		{
			CastleInfo* pCastleInfo = g_pCastleInfoManager->getCastleInfo( m_CastleZoneID );
			if (pCastleInfo!=NULL)
			{
				GuildID_t OwnerGuildID = pCastleInfo->getGuildID();

				// ���뼺�� �ƴ� ������ ��� ���Ѵ�.==���뼺� ��� �Ѵ�.
				if (OwnerGuildID!=SlayerCommon
					&& OwnerGuildID!=VampireCommon
					&& OwnerGuildID!=OustersCommon
					)
				{
					return;
				}
			}
		}
	}

	// ������ ����� �ϴ� ���̶��� -_-;; 
	ZoneID_t zoneID = m_pZone->getZoneID(); 
	if (zoneID == 1131 || zoneID == 1132 || zoneID == 1133 || zoneID == 1134)
	{
		if (!g_pSweeperBonusManager->isAble( zoneID ) )
			return;
	}

	map<SpriteType_t, MonsterCounter*>::iterator itr = m_Monsters.begin();
	for (; itr != m_Monsters.end() ; itr ++) 
	{
		MonsterCounter* pCounter = itr->second;

		// �����Ͱ� �پ������ ����...
		while (pCounter->getCurrentMonsters() < pCounter->getMaxMonsters()) 
		{
			SpriteType_t  SpriteType  = itr->first;
			MonsterType_t monsterType = 0;

			vector<MonsterType_t> RegenVector = g_pMonsterInfoManager->getMonsterTypeBySprite(SpriteType);
			Assert(RegenVector.size() > 0);

			monsterType = RegenVector[rand()%RegenVector.size()];

			// ��� �� ��ǥ�� ã�Ƴ���.
			ZoneCoord_t x, y;
			if (!findPosition(monsterType, x, y))
			{
				Assert(false);
				return;
			}

			// ������ ��ü�� �����ϰ� �ɷ�ġ ��� �ʱ�ȭ�Ѵ�.
			Monster* pMonster = new Monster(monsterType);
			Assert(pMonster != NULL);

			/////////////////////////////////////////////////////////////////////
			// �����͸� �߰��ϴ� ������� �̺�Ʈ ���������� �˻縦 �Ѵ�.
			///  7�� 1���ڷ� ��� (������ �̺�Ʈ ��)
			/*
			if(rand()%g_pVariableManager->getEventRatio()==0 && 
					g_pVariableManager->getEventActivate() == 1 )
			{		
				pMonster->setEventMonsterFlag(true);
				string MonsterName = g_pMonsterNameManager->getRandomName(pMonster, true);
				pMonster->setName(MonsterName);

				//cout << "�̺�Ʈ ������ �̸�: " << MonsterName;
			}
			*/
			/////////////////////////////////////////////////////////////////////

			try
			{
				m_pZone->addCreature(pMonster , x , y , Directions(rand()%8));
			}
			catch (EmptyTileNotExistException&)
			{
				//cerr << "MonsterManager::processCreatures() : �ڸ��� ����?" << endl;
				SAFE_DELETE(pMonster);
			}
		}
	}

	if (g_pVariableManager->isActiveChiefMonster()
		&& m_pEventMonsterInfo!=NULL)
	{
		Timeval currentTime;
		getCurrentTime( currentTime );

		//cout << "regenCheck [" << m_pZone->getZoneID() <<"] EventMonsterNum = "
		//	<< m_pEventMonsterInfo->size() << " : "; 

		for (uint i=0; i<m_pEventMonsterInfo->size(); i++)
		{
			EventMonsterInfo& info = (*m_pEventMonsterInfo)[i];

			if (!info.bExist
				&& currentTime >= info.regenTime)
			{
				//cout << i << " ";
				MonsterType_t monsterType = info.monsterType;

				// ��� �� ��ǥ�� ã�Ƴ���.
				ZoneCoord_t x, y;
				if (!findPosition(monsterType, x, y))
				{
					Assert(false);
					return;
				}

				// ������ ��ü�� �����ϰ� �ɷ�ġ ��� �ʱ�ȭ�Ѵ�.
				Monster* pMonster = new Monster(monsterType);
				Assert(pMonster != NULL);

				pMonster->setEventMonsterIndex( i );

				try
				{
					m_pZone->addCreature(pMonster , x , y , Directions(rand()%8));
				}
				catch (EmptyTileNotExistException&)
				{
					//cerr << "MonsterManager::processCreatures() : �ڸ��� ����?" << endl;
					SAFE_DELETE(pMonster);
				}
			}

			/*
			else
			{
				if (!info.bExist)
					cout << "f ";
				else
					cout << "t ";
			}
			*/
		}

		//cout << endl;
	}

	__END_DEBUG
	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool MonsterManager::findPosition(MonsterType_t monsterType, ZoneCoord_t& RX, ZoneCoord_t& RY) const
	throw()
{
	__BEGIN_TRY

	const MonsterInfo* pMonsterInfo = g_pMonsterInfoManager->getMonsterInfo(monsterType);

	int count = 0;

	// ���� �����ε�... Ȥ�ö��� ����� �����?
	while (true)
	{
		const BPOINT& pt = m_pZone->getRandomMonsterRegenPosition();

		Tile& rTile = m_pZone->getTile(pt.x,pt.y);

		// 1. Ÿ���� ���ϵǾ� ���� �ʰ�
		// 2. Ÿ�Ͽ� ��Ż�� ������� �����,
		// 3. �������밡 �ƴ϶���
		if (!rTile.isBlocked(pMonsterInfo->getMoveMode()) && 
			!rTile.hasPortal() && 
			!(m_pZone->getZoneLevel(pt.x, pt.y) & SAFE_ZONE))
		{
			RX = pt.x;
			RY = pt.y;
			return true;
		}

		if (++count >= 300)
		{
			cerr << "MonsterManager::findPosition() : Max Count Exceeded" << endl;
			throw ("MonsterManager::findPosition() : Max Count Exceeded");
		}
	}

	// ����� ���� ����ϱ�, �������� �� �����?
	return false;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ��� ũ��ó�� ó���Ѵ�.
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::killCreature (Creature* pDeadCreature)
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Assert(pDeadCreature->isDead());

	Zone* pZone = pDeadCreature->getZone();
	Assert(m_pZone == pZone);

	Monster* pDeadMonster = dynamic_cast<Monster*>(pDeadCreature);
	ZoneCoord_t cx = pDeadMonster->getX();
	ZoneCoord_t cy = pDeadMonster->getY();

	// �׾���ϱ� �켱��� �������ش�.
	PrecedenceTable* pTable = pDeadMonster->getPrecedenceTable();
	
	pTable->compute();

	if ( pTable->getHostName() == "" )
	{
		// �ƹ��� ���� ���� ���ٸ� ������� �� �ִ´�.
		pDeadMonster->setTreasure( false );
	}
	else
	{
		pDeadMonster->setHostName(pTable->getHostName());
		pDeadMonster->setHostPartyID(pTable->getHostPartyID());
	}

	// ���� �ٴڿ� �����߸�����, ����Ʈ�� �Ѹ���.
	GCAddEffect gcAddEffect;
	gcAddEffect.setObjectID(pDeadCreature->getObjectID());
	gcAddEffect.setEffectID(Effect::EFFECT_CLASS_COMA);
	gcAddEffect.setDuration(0);
	pZone->broadcastPacket(cx, cy, &gcAddEffect);

	// ������ ���
	Tile & tile = m_pZone->getTile(cx , cy);
	tile.deleteCreature(pDeadMonster->getObjectID());

	// �׶����� ������Ż� ��ü�� ������
	if ( pDeadMonster->getMonsterType() == GROUND_ELEMENTAL_TYPE )
	{
		GCDeleteObject* pGCDO = new GCDeleteObject;
		pGCDO->setObjectID( pDeadMonster->getObjectID() );

		EffectPacketSend* pEffectPacketSend = new EffectPacketSend( pDeadMonster->getZone(), pDeadMonster->getX(), pDeadMonster->getY() );
		pEffectPacketSend->setPacket( pGCDO );
		// 1�� �ڿ� ��Ŷ ��������~
		pEffectPacketSend->setDeadline(10);
		pDeadMonster->getZone()->registerObject( pEffectPacketSend );
		pDeadMonster->getZone()->addEffect( pEffectPacketSend );

		SAFE_DELETE( pDeadMonster );
		return;
	}

	// ��ü ��ü�� �����ϰ�, OID �� �Ҵ��޴´�.
	MonsterCorpse* pMonsterCorpse = new MonsterCorpse(pDeadMonster);
	pMonsterCorpse->setHostName(pDeadMonster->getHostName());
	pMonsterCorpse->setHostPartyID(pDeadMonster->getHostPartyID());
	pMonsterCorpse->setQuestHostName( pTable->getQuestHostName() );
	pMonsterCorpse->setLevel( (int)(pDeadMonster->getLevel()) );
	pMonsterCorpse->setExp( (Exp_t)computeCreatureExp(pDeadMonster, BLOODDRAIN_EXP) );
	pMonsterCorpse->setLastKiller( pDeadMonster->getLastKiller() );

	// ��� ������ ����� ������ ��ü�� ������� �߰��صд�.
	addItem(pDeadMonster, pMonsterCorpse);

	// by sigi. 2002.12.12
	addCorpseToZone( pMonsterCorpse, m_pZone, cx, cy );


	// ũ��ó�� �׾��ٰ� �ֺ��� �˷��ش�.
	GCCreatureDied gcCreatureDied;
	gcCreatureDied.setObjectID(pDeadMonster->getObjectID());
	m_pZone->broadcastPacket(cx , cy , &gcCreatureDied);

	// �������� ���쿡 ����鼭 �� ���� �ϴ°�.. by sigi. 2002.9.13
	if (pDeadMonster->isMaster())
	{
		//MonsterInfo* pMonsterInfo = g_pMonsterInfoManager->getMonsterInfo( pDeadMonster->getMonsterType() );
		MasterLairInfo* pMasterLairInfo = g_pMasterLairInfoManager->getMasterLairInfo( pZone->getZoneID() );

		if (pMasterLairInfo!=NULL
			&& pMasterLairInfo->getMasterMonsterType()==pDeadMonster->getMonsterType())
		{
			GCSay gcSay;
			gcSay.setObjectID( pDeadMonster->getObjectID() );
			gcSay.setColor( MASTER_SAY_COLOR );

			if (pDeadMonster->getLastHitCreatureClass() == Creature::CREATURE_CLASS_SLAYER)
			{
				gcSay.setMessage( pMasterLairInfo->getRandomMasterDeadSlayerSay() );
			}
			else
			{
				gcSay.setMessage( pMasterLairInfo->getRandomMasterDeadVampireSay() );
			}

			if (!gcSay.getMessage().empty())
				pZone->broadcastPacket(cx, cy, &gcSay);
		}
	}


	// ũ���ĸ� ����Ѵ�.
	SAFE_DELETE(pDeadMonster);

	__END_DEBUG
	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// addCreature
//
// (x, y) ��ó�� 
// monsterType�� Monster�� num���� �߰��Ѵ�.
////////////////////////////////////////////////////////////////////////////////
void
MonsterManager::addMonsters(ZoneCoord_t x, ZoneCoord_t y, MonsterType_t monsterType, int num, const SUMMON_INFO& summonInfo, list<Monster*>* pSummonedMonsters)
{
	TPOINT pt;

	ClanType_t clanType = CLAN_VAMPIRE_MONSTER;	// default

	// group ��ü�� ��� clan
	if (summonInfo.clanType==SUMMON_INFO::CLAN_TYPE_RANDOM_GROUP
		|| summonInfo.clanType==SUMMON_INFO::CLAN_TYPE_GROUP)
	{
		clanType = summonInfo.clanID;//rand()%90+2;
	}

	// ��� �� ��ǥ�� ã�Ƴ���.
	for (int i=0; i<num; i++)
	{
		pt = findSuitablePosition(m_pZone, x, y, Creature::MOVE_MODE_WALKING);

		// �ġ�� ã�� ���߰ų�, ������������ �߰��� �� ����.
		if (pt.x == -1 || (m_pZone->getZoneLevel(pt.x, pt.y) & SAFE_ZONE))
		{
			return;
		}

		Monster* pMonster = NULL;

		// ������ ��ü�� �����ϰ� �ɷ�ġ ��� �ʱ�ȭ�Ѵ�.
		try {

			pMonster = new Monster(monsterType);
			//cout << "������ �߰�" << endl;

			// ��ȯ�� �����Ͱ� ������� �����°�?
			pMonster->setTreasure( summonInfo.hasItem );

			////////////////////////////////////////////////////////////////////////////////
			// �����͸� �߰��ϴ� ������� �̺�Ʈ ���������� �˻縦 �Ѵ�.
			//  7�� 1�� �̺�Ʈ ����� �౸�� ������ ���
			/*
			if(rand()%g_pVariableManager->getEventRatio()==0 && 
					g_pVariableManager->getEventActivate() == 1 )
			{		
				pMonster->setEventMonsterFlag(true);
				string MonsterName = g_pMonsterNameManager->getRandomName(pMonster, true);
				pMonster->setName(MonsterName);

				//cout << "�̺�Ʈ ������ �̸�: " << MonsterName;
			}
			*/
			///////////////////////////////////////////////////////////////////////////

			Assert(pMonster != NULL);

			if (summonInfo.regenType==REGENTYPE_PORTAL)
			{
				// Ȥ�� �̹� ������������ �𸣴� �͵�� ������ش�.
				pMonster->removeFlag( Effect::EFFECT_CLASS_HIDE );
				pMonster->removeFlag( Effect::EFFECT_CLASS_INVISIBILITY );
				pMonster->removeFlag( Effect::EFFECT_CLASS_TRANSFORM_TO_BAT );

				pMonster->setFlag(Effect::EFFECT_CLASS_VAMPIRE_PORTAL);
				pMonster->setMoveMode( Creature::MOVE_MODE_WALKING );
			}

			if (summonInfo.initHPPercent!=0)
			{
				int currentHP = pMonster->getHP(ATTR_CURRENT);
				int MaxHP = currentHP * 100 / summonInfo.initHPPercent;
				pMonster->setHP(MaxHP, ATTR_MAX);
			}

		} catch (OutOfBoundException& t) {
			filelog("MonsterManagerBug.log", "addMonsters : %s", t.toString().c_str());
			SAFE_DELETE(pMonster);
			return;
		} catch (NoSuchElementException& t) {
			filelog("MonsterManagerBug.log", "addMonsters : %s", t.toString().c_str());
			SAFE_DELETE(pMonster);
			return;
		}


		try
		{
			m_pZone->addCreature(pMonster , pt.x , pt.y , Directions(rand()%8));


			// SUMMON_INFO
			if (summonInfo.clanType==SUMMON_INFO::CLAN_TYPE_RANDOM_EACH)
			{
				pMonster->setClanType( rand()%90+2 );
			}
			else
			{
				pMonster->setClanType( clanType );
			}

			//cout << "clanType=" << (int)pMonster->getClanType() << endl;

			// 
			if (summonInfo.canScanEnemy)
			{
				pMonster->setScanEnemy();

				m_pZone->monsterScan(pMonster, pt.x, pt.y, pMonster->getDir());
			}
			else if (summonInfo.scanEnemy)
			{
				m_pZone->monsterScan(pMonster, pt.x, pt.y, pMonster->getDir());
			}

			if (pSummonedMonsters!=NULL)
			{
				pSummonedMonsters->push_back( pMonster );
			}
	
		}
		catch (EmptyTileNotExistException&)
		{
			//cerr << "MonsterManager::processCreatures() : �ڸ��� ����?" << endl;
			SAFE_DELETE(pMonster);
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
// ��� �����Ϳ��Լ� ������� �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::addItem(Monster* pDeadMonster, MonsterCorpse* pMonsterCorpse)
	throw (Error)
{
	__BEGIN_TRY

	// ����Ʈ ������ �߰�
	if ( pDeadMonster->getQuestItem() != NULL )
	{
		pMonsterCorpse->addTreasure( pDeadMonster->getQuestItem() );
		pDeadMonster->setQuestItem( NULL );
	}

	if ( g_pVariableManager->getVariable( PREMIUM_TRIAL_EVENT ) != 0 && pDeadMonster->getMonsterType() == 705 )
	{
		if ( rand()%100 < 30 )
		{
			int Num = 5 + (rand()%5); // 5~9
			for ( int i=0; i<Num; ++i )
			{
				Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_LUCKY_BAG, 3, list<OptionType_t>() );
				pMonsterCorpse->addTreasure( pItem );
			}
		}
	}

	// �������� �� ����� ������ üũ(==������ ��ȯ ������)
	// by sigi. 2002.9.2
	if (!pDeadMonster->hasTreasure())
		return;

	MonsterType_t MonsterType = pDeadMonster->getMonsterType();
	const MonsterInfo* pMonsterInfo = g_pMonsterInfoManager->getMonsterInfo(MonsterType);
	TreasureList* pTreasureList = NULL;

	//----------------------------------------------------------------------
	// 2002�� �߼� �̺�Ʈ ������
	// ������ ��� Ȯ���� ���� �ڿ��� �ٸ� ������� ������ �ʾƾ� �Ѵ�. 
	//----------------------------------------------------------------------
	bool isHarvestFestivalItemAppeared = false;
	int  PartialSumOfCakeRatio = 0;
	int  itemBonusPercent = 0;

	if (g_pVariableManager->getHarvestFestivalItemRatio() > 0 &&  rand() % g_pVariableManager->getHarvestFestivalItemRatio() == 0) 
	{
		// ������� 5���� �߿��� ���� �� �ִ�.
		ITEM_TEMPLATE ricecake_template;
		ricecake_template.NextOptionRatio = 0;

		bool bOK = false;
		int EventSelector = rand() % m_SumOfCakeRatio;

		for (int i=0; i<5; i++)
		{
			PartialSumOfCakeRatio += m_RICE_CAKE_PROB_RATIO[i];

			// ���� Dice ������� �����ȴٸ�
			if ( EventSelector < PartialSumOfCakeRatio)
			{
				if ( i == 0 )
				{
					if (pDeadMonster->getLastHitCreatureClass() == Creature::CREATURE_CLASS_SLAYER)
					{
						ricecake_template.ItemClass = Item::ITEM_CLASS_POTION;
						ricecake_template.ItemType  = 11;
					}
					else
					{
						ricecake_template.ItemClass = Item::ITEM_CLASS_SERUM;
						ricecake_template.ItemType  = 5;
					}
				}
				else
				{
					// ��
					ricecake_template.ItemClass = Item::ITEM_CLASS_EVENT_STAR;
					ricecake_template.ItemType = i + 7;
				}
				bOK = true;
				break;
			}
		}

		//cout << "�̺�Ʈ ������ ����"  << "[" << i >> "," << EventSelector << "]" << m_SumOfCakeRatio << endl 
			 //<< "(" << ricecake_template.ItemClass << " " << ricecake_template.ItemType << ")" << endl;

		if (bOK)
		{
			Item* pItem = g_pItemFactoryManager->createItem(ricecake_template.ItemClass,ricecake_template.ItemType, ricecake_template.OptionType);

			Assert(pItem != NULL);

			pMonsterCorpse->addTreasure(pItem);

			isHarvestFestivalItemAppeared = true;
		}
	}

	//----------------------------------------------------------------------
	// ũ�������� ���� �߰�
	//----------------------------------------------------------------------
	int fireCrackerRatio = g_pVariableManager->getVariable( CHRISTMAS_FIRE_CRACKER_RATIO );
	if ( fireCrackerRatio > 0 )
	{
		int value = rand() % 10000;
		if ( value < fireCrackerRatio )
		{
			// �� ���� ����� ������ ���´�.
			ItemType_t fireCrackerType = value % 3;

			// ������� �����Ѵ�.
			list<OptionType_t> optionType;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_ETC, fireCrackerType, optionType );

			// ������ ��ü�� �ִ´�.
			pMonsterCorpse->addTreasure( pItem );
		}
	}
	
	//----------------------------------------------------------------------
	// ũ�������� Ʈ�� ��� �߰�
	//----------------------------------------------------------------------
	int treePartRatio = g_pVariableManager->getVariable( CHRISTMAS_TREE_PART_RATIO );
	if ( treePartRatio > 0 )
	{
		int value = rand() % 10000;
		if ( value < treePartRatio )
		{
			// 12���� Ʈ�� ����� �ִ�.
			ItemType_t treeItemType = rand() % 12;

			// ������� �����Ѵ�.
			list<OptionType_t> optionType;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, treeItemType, optionType );

			// ������ ��ü�� �ִ´�.
			pMonsterCorpse->addTreasure( pItem );
		}
	}
		
	//----------------------------------------------------------------------
	// ���� ���� ���� �߰�
	//----------------------------------------------------------------------
	int giftBoxRatio = g_pVariableManager->getVariable( CHRISTMAS_GIFT_BOX_RATIO );
	if ( giftBoxRatio > 0 )
	{
		int value = rand() % 10000;
		if ( value < giftBoxRatio )
		{
			// ���� ���� ���ڸ� �����Ѵ�.
			list<OptionType_t> optionType;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_GIFT_BOX, 0, optionType );

			// ������ ��ü�� �ִ´�.
			pMonsterCorpse->addTreasure( pItem );
		}
	}

	//----------------------------------------------------------------------
	// ���� ���� �߰�
	//----------------------------------------------------------------------
	// ���ָӴϴ� affectKillCount ���⼭ ó��������
	// ���� ���ڴ� Monster �� m_pQuestItem �� ��� ���� �ƴϹǷ� ���⼭ ó���Ѵ�
	// (���� ���ָӴϵ� m_pQuestItem �� ��� �ʿ䰡 �����ϴٸ� ;;)
	//----------------------------------------------------------------------
	if ( g_pVariableManager->isEventGiftBox() )
	{
		if ( m_pZone != NULL )
		{
			Creature* pCreature = m_pZone->getCreature( pDeadMonster->getLastKiller() );

			if ( pCreature != NULL && pCreature->isPC() )
			{
				PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);

				if ( pPC != NULL )
				{
					Item* pItem = getGiftBoxItem( getGiftBoxKind( pPC, pDeadMonster ) );

					// GiftBox ������� �߰��ؾ� �ȴٸ� �߰��Ѵ�.
					if ( pItem != NULL )
						pMonsterCorpse->addTreasure( pItem );
				}
			}
		}
	}
	

	// ������ �Ծ����� ĳ������ ��� ������.
	// ���� ��� �� ĳ���Ͱ� ���ٸ�, 
	// �� ĳ������ party�� ������.. ��Ƽ�� ���ٸ�
	// LastHit�� ������.
	// by sigi. 2002.10.14
	// ��������� �� �����͸� ���� ũ���İ� �����̾����� �����̾� ������� �����ϰ�,
	// �ƴ϶��� ����Ʈ�� �����̾� ������� �����Ѵ�.
	Creature* pItemOwnerCreature = m_pZone->getPCManager()->getCreature( pDeadMonster->getHostName() );

	Creature::CreatureClass ownerCreatureClass;
	
	int luckLevel = 0;
	if (pItemOwnerCreature!=NULL)
	{
		ownerCreatureClass = pItemOwnerCreature->getCreatureClass();
		luckLevel = pItemOwnerCreature->getLuck();

		GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pItemOwnerCreature->getPlayer());

		if ( pGamePlayer != NULL)
			itemBonusPercent = pGamePlayer->getItemRatioBonusPoint();
	}
	else if (pDeadMonster->getHostPartyID()!=0)
	{
		Party* pParty = m_pZone->getLocalPartyManager()->getParty( pDeadMonster->getHostPartyID() );

		if (pParty!=NULL)
		{
			ownerCreatureClass = pParty->getCreatureClass();
		}
		else
		{
			ownerCreatureClass = pDeadMonster->getLastHitCreatureClass();
		}
	}
	else 
	{
		ownerCreatureClass = pDeadMonster->getLastHitCreatureClass();
	}

	// ������ ������� ���� ������ �������� �� ��� 
	if (ownerCreatureClass == Creature::CREATURE_CLASS_SLAYER)
	{
		pTreasureList = pMonsterInfo->getSlayerTreasureList();
	}
	else if (ownerCreatureClass == Creature::CREATURE_CLASS_VAMPIRE)
	{
		pTreasureList = pMonsterInfo->getVampireTreasureList();
	}
	else if (ownerCreatureClass == Creature::CREATURE_CLASS_OUSTERS)
	{
		pTreasureList = pMonsterInfo->getOustersTreasureList();
	}

	// �� �����Ͱ� chief monster�ΰ�?  by sigi. 2002.10.23
	bool bChiefMonsterBonus = pDeadMonster->isChief()
								&& g_pVariableManager->isActiveChiefMonster();


	const list<Treasure*>& treasures = pTreasureList->getTreasures();

	list<Treasure*>::const_iterator itr = treasures.begin();
	for (; itr != treasures.end(); itr++)
	{
		Treasure* pTreasure = (*itr);
		ITEM_TEMPLATE it;

		it.ItemClass  = Item::ITEM_CLASS_MAX;
		it.ItemType   = 0;
		//it.OptionType = 0;

		int itemRatioBonus = 0;

		if (bChiefMonsterBonus)
		{
			it.NextOptionRatio = g_pVariableManager->getChiefMonsterRareItemPercent();
			itemRatioBonus     = g_pVariableManager->getPremiumItemProbePercent();
		}
		else
		{
			it.NextOptionRatio = 0;
		}

		Item* pItem = NULL;

		// ���ȭ ������� ������ Ȯ���� �� ����.
		Zone* pZone = pDeadMonster->getZone();

		// �����̺�Ʈ�� �����Ǵ� �. by sigi. 2003.1.17
		static bool isNetMarble = g_pConfig->getPropertyInt("IsNetMarble")!=0;
		bool isLottoZone = pZone->isPayPlay() || isNetMarble;

		if ( pZone->isPayPlay() 
			|| pZone->isPremiumZone())
		{
			//cout << "����Ȯ��!!!! : " << g_pVariableManager->getPremiumItemProbePercent() << endl;
			if (pTreasure->getRandomItem(&it, itemRatioBonus + g_pVariableManager->getPremiumItemProbePercent() + itemBonusPercent ) )
			{
				// by sigi. 2002.10.21
				int upgradeLevel = upgradeItemTypeByLuck(luckLevel, ownerCreatureClass, it);
				if ( upgradeLevel != 0 )
				{
					GCAddEffectToTile gcAE;

					if ( upgradeLevel > 0 ) gcAE.setEffectID( Effect::EFFECT_CLASS_LUCKY );
					else gcAE.setEffectID( Effect::EFFECT_CLASS_MISFORTUNE );

					gcAE.setObjectID( 0 );
					gcAE.setDuration( 0 );
					gcAE.setXY( pDeadMonster->getX(), pDeadMonster->getY() );

//					cout << "���ε�ĳ���� : " << pDeadMonster->getX() << ", " << pDeadMonster->getY() << endl;
					
					pZone->broadcastPacket( pDeadMonster->getX(), pDeadMonster->getY(), &gcAE );
				}

				if ( !it.OptionType.empty() )
				{
					upgradeOptionByLuck( luckLevel, ownerCreatureClass, it );
				}

				// ġ�� �����ʹ� ������ 1�ܰ� +
				// by sigi. 2002.10.23
				if (bChiefMonsterBonus
					// �ϴ� rare Ȯ���� ���� ���µ�..
					// ���߿� �̰͵� �ٸ� variable�� �и��ؾߵ� ���̴�.	 by sigi. 2002.10.23
					&& rand()%100 < g_pVariableManager->getChiefMonsterRareItemPercent()
					&& isPossibleUpgradeItemType(it.ItemClass))
				{
					// ItemType 1�ܰ� upgrade
					int upgradeCount = 1;
		
					it.ItemType = getUpgradeItemType(it.ItemClass, it.ItemType, upgradeCount);
				}

				pItem = g_pItemFactoryManager->createItem(it.ItemClass, it.ItemType, it.OptionType);
				Assert(pItem != NULL);

				if ( pItem->isUnique() ) pItem->setGrade(6);
				else
					pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
//				cout << "���� ������ ���� : " << pItem->getGrade() << endl;

				pItem->setDurability( computeMaxDurability(pItem) );

				if (!isHarvestFestivalItemAppeared ||
						(isHarvestFestivalItemAppeared && pItem->getItemClass() == Item::ITEM_CLASS_SKULL))
					pMonsterCorpse->addTreasure(pItem);

				// �����̺�Ʈ: �ذ� 8�� �� �߰�
				if ( isLottoZone 
					&& pItem->getItemClass() == Item::ITEM_CLASS_SKULL )
				{
					int lottoSkullRatio = g_pVariableManager->getVariable( LOTTO_SKULL_RATIO );
					if ( lottoSkullRatio > 0 )
					{
						int value = rand() % 10000;
						if ( value < lottoSkullRatio )
						{
							// �ذ� 8�� �� ������ �ִ´�.
							for ( int i = 0; i < 8; i++ )
							{
								pItem = g_pItemFactoryManager->createItem(it.ItemClass, it.ItemType, it.OptionType);
								pMonsterCorpse->addTreasure( pItem );
							}
						}
					}
				}
			}
		}
		else
		{
			//cout << "����Ȯ��!!!! : " << g_pVariableManager->getPremiumItemProbePercent() << endl;
			if (pTreasure->getRandomItem(&it, g_pVariableManager->getItemProbRatio() + itemBonusPercent ))
			{
				// by sigi. 2002.10.21
				//upgradeItemTypeByLuck(luckLevel, it);

				pItem = g_pItemFactoryManager->createItem(it.ItemClass, it.ItemType, it.OptionType);
				Assert(pItem != NULL);

				if ( pItem->isUnique() ) pItem->setGrade(6);
				else
					pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
//				pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
//				cout << "���� ������ ���� : " << pItem->getGrade() << endl;

				pItem->setDurability( computeMaxDurability(pItem) );
	
				if (!isHarvestFestivalItemAppeared ||
						(isHarvestFestivalItemAppeared && pItem->getItemClass() == Item::ITEM_CLASS_SKULL))
					pMonsterCorpse->addTreasure(pItem);

			}
		}


		/////////////////////////////////////////////////////////////////////////
		// ������(�ذ񻩰�) ����� ���� Ȯ���� ����ٸ� ������� � �� �ִ´�. ������.
		// ġ�� �����Ϳ� �߰� �������� ����Ǿ� �ִٸ� �� ��ġ��ŭ ������� �� �ִ´�.
		int nBonusItem = 0;

		if ( pItem != NULL
			&& pItem->getItemClass() != Item::ITEM_CLASS_SKULL
			)	
		{
			if ( bChiefMonsterBonus )
				nBonusItem = g_pVariableManager->getVariable( CHIEF_ITEM_BONUS_NUM );

			if ( isLottoZone && isLottoWinning() )
				nBonusItem = g_pVariableManager->getVariable( LOTTO_ITEM_BONUS_NUM );
		}

		if ( nBonusItem > 0 )
		{
			int i = 0;
			int j = 0;
			static int MaxTry = 30;
			while ( i < nBonusItem && j < MaxTry )
			{
				Treasure* pTreasure = (*itr);
				ITEM_TEMPLATE it;

				it.ItemClass  = Item::ITEM_CLASS_MAX;
				it.ItemType   = 0;
				//it.OptionType = 0;

				int itemRatioBonus = 0;

				if (bChiefMonsterBonus)
				{
					it.NextOptionRatio = g_pVariableManager->getChiefMonsterRareItemPercent();
					itemRatioBonus     = g_pVariableManager->getPremiumItemProbePercent();
				}
				else
				{
					it.NextOptionRatio = 0;
				}

				Item* pItem = NULL;

				// ���ȭ ������� ������ Ȯ���� �� ����.
				Zone* pZone = pDeadMonster->getZone();
				if ( pZone->isPayPlay() 
					|| pZone->isPremiumZone())
				{
					//cout << "����Ȯ��!!!! : " << g_pVariableManager->getPremiumItemProbePercent() << endl;
					if (pTreasure->getRandomItem(&it, itemRatioBonus + g_pVariableManager->getPremiumItemProbePercent() + itemBonusPercent ) )
					{
						// by sigi. 2002.10.21
						int upgradeLevel = upgradeItemTypeByLuck(luckLevel, ownerCreatureClass, it);

						if ( upgradeLevel != 0 )
						{
							GCAddEffectToTile gcAE;

							if ( upgradeLevel > 0 ) gcAE.setEffectID( Effect::EFFECT_CLASS_LUCKY );
							else gcAE.setEffectID( Effect::EFFECT_CLASS_MISFORTUNE );

							gcAE.setObjectID( 0 );
							gcAE.setDuration( 0 );
							gcAE.setXY( pDeadMonster->getX(), pDeadMonster->getY() );

//							cout << "���ε�ĳ���� : " << pDeadMonster->getX() << ", " << pDeadMonster->getY() << endl;
							
							pZone->broadcastPacket( pDeadMonster->getX(), pDeadMonster->getY(), &gcAE );
						}

						// ġ�� �����ʹ� ������ 1�ܰ� +
						// by sigi. 2002.10.23
						if (bChiefMonsterBonus
							// �ϴ� rare Ȯ���� ���� ���µ�..
							// ���߿� �̰͵� �ٸ� variable�� �и��ؾߵ� ���̴�.	 by sigi. 2002.10.23
							&& rand()%100 < g_pVariableManager->getChiefMonsterRareItemPercent()
							&& isPossibleUpgradeItemType(it.ItemClass))
						{
							// ItemType 1�ܰ� upgrade
							int upgradeCount = 1;
				
							it.ItemType = getUpgradeItemType(it.ItemClass, it.ItemType, upgradeCount);
						}

						if ( !it.OptionType.empty() )
						{
							upgradeOptionByLuck( luckLevel, ownerCreatureClass, it );
						}

						pItem = g_pItemFactoryManager->createItem(it.ItemClass, it.ItemType, it.OptionType);
						Assert(pItem != NULL);
						
						if ( pItem->isUnique() ) pItem->setGrade(6);
						else
							pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
						//pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
						//cout << "���� ������ ���� : " << pItem->getGrade() << endl;

						pItem->setDurability( computeMaxDurability(pItem) );
			
						if (!isHarvestFestivalItemAppeared ||
								(isHarvestFestivalItemAppeared && pItem->getItemClass() == Item::ITEM_CLASS_SKULL))
							pMonsterCorpse->addTreasure(pItem);
					}
				}
				else
				{
					//cout << "����Ȯ��!!!! : " << g_pVariableManager->getPremiumItemProbePercent() << endl;
					if (pTreasure->getRandomItem(&it, g_pVariableManager->getItemProbRatio() + itemBonusPercent ))
					{
						// by sigi. 2002.10.21
						//upgradeItemTypeByLuck(luckLevel, it);

						pItem = g_pItemFactoryManager->createItem(it.ItemClass, it.ItemType, it.OptionType);
						Assert(pItem != NULL);

						if ( pItem->isUnique() ) pItem->setGrade(6);
						else
							pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
						//pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
//						cout << "���� ������ ���� : " << pItem->getGrade() << endl;

						pItem->setDurability( computeMaxDurability(pItem) );
			
						if (!isHarvestFestivalItemAppeared ||
								(isHarvestFestivalItemAppeared && pItem->getItemClass() == Item::ITEM_CLASS_SKULL))
							pMonsterCorpse->addTreasure(pItem);
					}
				}

				if ( pItem != NULL )
					i++;

				j++;
			}
		}
		/////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////
	}

	// �ذ� �־����� �Ǵ� ����Ÿ
	if ( pMonsterInfo->getSkullType() != 0 )
	{
		Item* pSkull = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_SKULL, pMonsterInfo->getSkullType(), list<OptionType_t>() );
		if ( pSkull != NULL )
		{
			pMonsterCorpse->addTreasure( pSkull );
		}
	}

	//////////////////////////////////////////////////////////////////////
	// 2002�� 6�� ������ �̺�Ʈ
	//  �̺�Ʈ �����ͷ� ������ �� �����Ϳ��Լ��� �౸�� �������� ���´�.
	//  �౸��� ������ ITEM_TYPE� ������ �ʰ�
	//  EVENT_STAR�� Type7����� �۵��Ѵ�.
	//  ���� EventStarInfo, EventStarObject�� EventItemInfo, EventItemObject
	//  �� �����Ǿ��� �� ���̴�.
	/////////////////////////////////////////////////////////////////////
	/*
	if(pDeadMonster->getEventMonsterFlag() == true)
	{
		ITEM_TEMPLATE ball_template;
		ball_template.ItemClass = Item::ITEM_CLASS_EVENT_STAR;
		ball_template.ItemType = 6;
		ball_template.OptionType=0;

		//if(g_pVariable->getDebugMode() == "COUT")
			//cout << "�౸�� ������ ����" << endl;

		Item *pItem = g_pItemFactoryManager->createItem(ball_template.ItemClass, ball_template.ItemType, ball_template.OptionType);
		Assert(pItem != NULL);
		pMonsterCorpse->addTreasure(pItem);
	}
	*/
	

	//////////////////////////////////////////////////////////////////////
	//   2002�� 5�� ����� �� �̺�Ʈ/
	//   ���� �����Ϳ��Լ� ���� ���� �� ����Ƿ�, ���⿡ �ϵ��ڵ��Ͽ���.
	//   1/1500 �� Ȯ���� �� ������� �߰��� �����Ѵ�.(�ɸ��� ��� ������)
	//////////////////////////////////////////////////////////////////////
	//cout << "Monster Manager: star -> " << g_pVariable->getStar() << endl;
	//int star_percentage = g_pVariable->getStar();
    /*
	if(rand()%500 == 0) {
		ITEM_TEMPLATE star_template;
		star_template.ItemClass = Item::ITEM_CLASS_EVENT_STAR;

		// ���� 1/10�� Ȯ���� ���캻 ���, �ɸ��� 1/6�� Ȯ���� �� ��� ����� �Ѵ�.
		// 9/10�� Ȯ���δ� ������ ����� ���� ����� �Ѵ�.
		if(rand() % 1500 == 0)
			star_template.ItemType = rand() % 6;
		else
			star_template.ItemType = (rand() % 5) + 1;
		star_template.OptionType = 0;

		cout << "�̺�Ʈ ������ ����" << star_template.ItemType << endl;
		Item* pItem = g_pItemFactoryManager->createItem(star_template.ItemClass,star_template.ItemType, star_template.OptionType);
		Assert(pItem != NULL);
		pMonsterCorpse->addTreasure(pItem);
	}
	*/
	__END_CATCH
}

int MonsterManager::upgradeItemTypeByLuck(int luckLevel, Creature::CreatureClass ownerCreatureClass, ITEM_TEMPLATE& it)
	throw (Error)
{
	__BEGIN_TRY

	if (luckLevel==0
		|| !isPossibleUpgradeItemType(it.ItemClass))
		return 0;

	luckLevel = luckLevel + (rand()%20) - 10;
	luckLevel = min(MAX_LUCK_LEVEL, luckLevel);
//	cout << "Apply luck : " << luckLevel << endl;

	int ratio;

	switch ( ownerCreatureClass )
	{
		case Creature::CREATURE_CLASS_SLAYER:
			{
				if ( luckLevel >= 0 )
				{
					ratio = (int)(( (float)luckLevel / (4.254 + (1.0 + it.ItemType)/5.0) ) * 100);
				}
				else
				{
					ratio = (int)(( (float)luckLevel / (2.5 - (1.0 + it.ItemType)/20.0) ) * 100);
				}
			}
			break;
		case Creature::CREATURE_CLASS_VAMPIRE:
			{
				if ( luckLevel >= 0 )
				{
					ratio = (int)(( (float)luckLevel / (6.03 + (1.0 + it.ItemType)/5.0) ) * 100);
				}
				else
				{
					ratio = (int)(( (float)luckLevel / (4.14 - (1.0 + it.ItemType)/20.0) ) * 100);
				}
			}
			break;
		case Creature::CREATURE_CLASS_OUSTERS:
			{
				if ( luckLevel >= 0 )
				{
					ratio = (int)(( (float)luckLevel / (4.936 + (1.0 + it.ItemType)/5.0) ) * 100);
				}
				else
				{
					ratio = (int)(( (float)luckLevel / (3.05 - (1.0 + it.ItemType)/20.0) ) * 100);
				}
			}
			break;
		default:
			return 0;
	}

	int value = rand()%10000;
//	int value = 0;//rand()%10000;

//	cout << "ratio : " << ratio << endl;
//	cout << "value : " << value << endl;

/*	const LuckInfo& luckInfo = g_pLuckInfoManager->getLuckInfo(luckLevel);

	int upgradeCount = luckInfo.getUpgradeItemTypeCount();

	if (upgradeCount==0)
		return;*/

//	cout << "before : " << it.ItemClass << "/" << (int)it.ItemType << endl;
	if ( ratio > 0 && value < ratio )
	{
		it.ItemType = getUpgradeItemType(it.ItemClass, it.ItemType, 1);
//		cout << "after : " << it.ItemClass << "/" << (int)it.ItemType << endl;
		return 1;
	}
	else if ( ratio < 0 && value < (-ratio) )
	{
		it.ItemType = getDowngradeItemType(it.ItemClass, it.ItemType);
//		cout << "after : " << it.ItemClass << "/" << (int)it.ItemType << endl;
		return -1;
	}

	return 0;

	__END_CATCH
}

int MonsterManager::upgradeOptionByLuck(int luckLevel, Creature::CreatureClass ownerCreatureClass, ITEM_TEMPLATE& it) throw (Error)
{
	__BEGIN_TRY

	if ( it.OptionType.empty() ) return 0;

	OptionType_t optionType = it.OptionType.front();
	OptionInfo* pOptionInfo = g_pOptionInfoManager->getOptionInfo( optionType );
	if ( pOptionInfo == NULL ) return 0;

	luckLevel = luckLevel + (rand()%20) - 10;
	luckLevel = min(MAX_LUCK_LEVEL, luckLevel);
//	cout << "Apply luck to option : " << luckLevel << endl;

	int grade = pOptionInfo->getGrade() + 1;
//	cout << "Option Grade : " << grade << endl;

	int ratio;

	switch ( ownerCreatureClass )
	{
		case Creature::CREATURE_CLASS_SLAYER:
			{
				if ( luckLevel >= 0 )
				{
					ratio = (int)(( (float)luckLevel / (grade*25.0 - 15.2) ) * 100);
				}
				else
				{
					ratio = (int)(( (float)luckLevel / (7.5 - grade/2.0) ) * 100);
				}
			}
			break;
		case Creature::CREATURE_CLASS_VAMPIRE:
			{
				if ( luckLevel >= 0 )
				{
					ratio = (int)(( (float)luckLevel / (grade*25.0 - 11.3) ) * 100);
				}
				else
				{
					ratio = (int)(( (float)luckLevel / (10.3 - grade/2.0) ) * 100);
				}
			}
			break;
		case Creature::CREATURE_CLASS_OUSTERS:
			{
				if ( luckLevel >= 0 )
				{
					ratio = (int)(( (float)luckLevel / (grade/25.0 - 13.7) ) * 100);
				}
				else
				{
					ratio = (int)(( (float)luckLevel / (7.9 - grade/2.0) ) * 100);
				}
			}
			break;
		default:
			return 0;
	}

	int value = rand()%10000;
//	int value = 0;//rand()%10000;

//	cout << "ratio : " << ratio << endl;
//	cout << "value : " << value << endl;

//	cout << "before : " << pOptionInfo->getHName() << endl;

	if ( ratio > 0 && value < ratio && pOptionInfo->getUpgradeType() != optionType && pOptionInfo->isUpgradePossible() )
	{
		(*it.OptionType.begin()) = pOptionInfo->getUpgradeType();
//		cout << "after : " << g_pOptionInfoManager->getOptionInfo( it.OptionType.front() )->getHName() << endl;
		return 1;
	}
	else if ( ratio < 0 && value < (-ratio) && pOptionInfo->getPreviousType() != optionType )
	{
		if ( pOptionInfo->getPreviousType() != 0 )
			(*it.OptionType.begin()) = pOptionInfo->getPreviousType();
		else
			it.OptionType.pop_front();
//		if ( it.OptionType.front() == 0 ) it.OptionType.pop_front();
//		cout << "after : " << g_pOptionInfoManager->getOptionInfo( it.OptionType.front() )->getHName() << endl;
		return -1;
	}

	return 0;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ���� ũ��ó�� ����Ѵ�.
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::deleteAllMonsters (bool bDeleteFromZone)
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	map< ObjectID_t , Creature* >::iterator current = m_Creatures.begin();

	while (current != m_Creatures.end()) 
	{
		Creature* pCreature = current->second;

		Assert(pCreature != NULL);

		if (bDeleteFromZone)
		{
			try {
				Zone* pZone = pCreature->getZone();
				Assert(m_pZone == pZone);

				//Monster* pMonster = dynamic_cast<Monster*>(pCreature);

				ZoneCoord_t cx = pCreature->getX();
				ZoneCoord_t cy = pCreature->getY();

				// Ÿ�Ͽ��� ���
				Tile & tile = m_pZone->getTile(cx , cy);
				tile.deleteCreature(pCreature->getObjectID());

				// �ֺ��� PC�鿡�� ũ��ó�� ������ٴ� ����� ���ε�ĳ��Ʈ�Ѵ�.
				GCDeleteObject gcDeleteObject(pCreature->getObjectID());
				pZone->broadcastPacket(cx, cy, &gcDeleteObject, pCreature);

			} catch (Throwable& t) {
				filelog("MonsterManagerBug.txt", "deleteAllCreatures: %s", t.toString().c_str());
			}
		}

		// ũ���ĸ� ����Ѵ�.
		SAFE_DELETE(pCreature);

		current ++;
	}

	// �� ����Ѵ�.
	m_Creatures.clear();
	m_Monsters.clear();



	__END_DEBUG
	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ���� ũ��ó�� ���δ�.
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::killAllMonsters (const map<ObjectID_t, ObjectID_t>& exceptCreatures)
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	map< ObjectID_t , Creature* >::iterator current = m_Creatures.begin();

	while (current != m_Creatures.end()) 
	{
		Creature* pCreature = current->second;

		Assert(pCreature != NULL);

		if (pCreature->isAlive())
		{
			if (pCreature->isMonster())
			{
				map<ObjectID_t, ObjectID_t>::const_iterator itr = exceptCreatures.find( pCreature->getObjectID() );

				if (itr==exceptCreatures.end())
				{
					Monster* pMonster = dynamic_cast<Monster*>(pCreature);
					pMonster->setHP(0, ATTR_CURRENT);
				}
			}
			else Assert(false);
		}
	}

	__END_DEBUG
	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// get debug string
////////////////////////////////////////////////////////////////////////////////
string MonsterManager::toString () const
       throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "MonsterManager(" << CreatureManager::toString();

	map< SpriteType_t , MonsterCounter* >::const_iterator itr = m_Monsters.begin();
	for (; itr != m_Monsters.end() ; itr ++) msg << itr->second->toString();

	msg << ")" ;
	return msg.toString();

	__END_CATCH
}



//////////////////////////////////////////////////////////////////////////////
// Ȳ�� �ذ� �ݱ� �̺�Ʈ�� ������ �ڵ��� �Ϻκ��̴�.
// �ϴ�� ���� �Ⱦ �����µ�, ���߿����� Ȥ�� �ٽ� �������� �ؼ�
// ���� �� ����� �Űܳ��´�.
//////////////////////////////////////////////////////////////////////////////

/*
////////////////////////////////////////////////////////////
// �̺�Ʈ ���� �ڵ� ����
////////////////////////////////////////////////////////////
SpriteType_t SpriteType = pMonsterInfo->getSpriteType();
uint         event_ratio = rand()%100;
uint         skull_ratio = rand()%100;

switch (SpriteType)
{
	case 5: // �����ٵ�
		if (event_ratio < 3) ItemType = 12;
		break;
	case 8: // �ʹ׵���
		if (event_ratio < 3) ItemType = 12;
		break;
	case 7: // �ʹ׼ҿ�
		if (event_ratio < 3)
		{
			if (skull_ratio < 98) ItemType = 12;
			else ItemType = 15;
		}
		break;
	case 6: // Ű��
		if (event_ratio < 3)
		{
			if (skull_ratio < 97) ItemType = 12;
			else ItemType = 15;
		}
		break;
	case 4: // ���
		if (event_ratio < 3)
		{
			if (skull_ratio < 96) ItemType = 12;
			else ItemType = 15;
		}
		break;
	case 9: // ĸƾ
		if (event_ratio < 3)
		{
			if (skull_ratio < 94) ItemType = 12;
			else ItemType = 15;
		}
		break;
	case 42: // ��ĭ
		if (event_ratio < 4)
		{
			if (skull_ratio < 93) ItemType = 12;
			else if (93 <= skull_ratio && skull_ratio < 99) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 43: // ��������
		if (event_ratio < 4)
		{
			if (skull_ratio < 93) ItemType = 12;
			else if (93 <= skull_ratio && skull_ratio < 99) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 60: // ����Ʈ
		if (event_ratio < 4)
		{
			if (skull_ratio < 93) ItemType = 12;
			else if (93 <= skull_ratio && skull_ratio < 99) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 64: // �𵥶���
		if (event_ratio < 4)
		{
			if (skull_ratio < 93) ItemType = 12;
			else if (93 <= skull_ratio && skull_ratio < 99) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 41: // ��Ƽ��Ʈ���̴�
		if (event_ratio < 4)
		{
			if (skull_ratio < 93) ItemType = 12;
			else if (93 <= skull_ratio && skull_ratio < 99) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 62: // ����Ʈ���̴�
		if (event_ratio < 4)
		{
			if (skull_ratio < 93) ItemType = 12;
			else if (93 <= skull_ratio && skull_ratio < 99) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 61: // �������
		if (event_ratio < 4)
		{
			if (skull_ratio < 91) ItemType = 12;
			else if (91 <= skull_ratio && skull_ratio < 98) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 48: // ȣ��
		if (event_ratio < 5)
		{
			if (skull_ratio < 91) ItemType = 12;
			else if (91 < skull_ratio && skull_ratio < 98) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 27: // ��������
		if (event_ratio < 5)
		{
			if (skull_ratio < 91) ItemType = 12;
			else if (91 <= skull_ratio && skull_ratio < 98) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 40: // �񷹸�
		if (event_ratio < 5)
		{
			if (skull_ratio < 91) ItemType = 12;
			else if (91 <= skull_ratio && skull_ratio < 98) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 57: // �������
		if (event_ratio < 5)
		{
			if (skull_ratio < 91) ItemType = 12;
			else if (91 <= skull_ratio && skull_ratio < 98) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 47: // ī���������
		if (event_ratio < 6)
		{
			if (skull_ratio < 89) ItemType = 12;
			else if (89 <= skull_ratio && skull_ratio < 97) ItemType = 15;
			else ItemType = 14;
		}
		break;
	default:
		break;
}
////////////////////////////////////////////////////////////
// �̺�Ʈ ���� �ڵ� ��
////////////////////////////////////////////////////////////
*/

bool isLottoWinning()
{
	int lottoItemRatio = g_pVariableManager->getVariable( LOTTO_ITEM_RATIO );
	if ( lottoItemRatio > 0 )
	{
		int value = rand() % 10000;
		if ( value < lottoItemRatio )
		{
			return true;
		}
	}

	return false;
}
