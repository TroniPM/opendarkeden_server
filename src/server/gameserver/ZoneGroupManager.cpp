//--------------------------------------------------------------------------------
//
// Filename    : ZoneGroupManager.cpp
// Written By  : Reiot
// Description :
//
//--------------------------------------------------------------------------------

// include files
#include "ZoneGroupManager.h"
#include "ZoneGroup.h"
#include "ZonePlayerManager.h"
#include "ZoneInfoManager.h"
#include "PCManager.h"
#include "Portal.h"
#include "DB.h"
#include "LogClient.h"
#include "Tile.h"
#include "GamePlayer.h"
#include "LoginServerManager.h"
#include "IncomingPlayerManager.h"
#include <stdio.h>
#include <list>
#include <map>

//--------------------------------------------------------------------------------
// constructor
//--------------------------------------------------------------------------------
ZoneGroupManager::ZoneGroupManager () 
	throw ()
//: m_ZoneGroups(10)
{
	__BEGIN_TRY
	__END_CATCH
}

	
//--------------------------------------------------------------------------------
// destructor
//--------------------------------------------------------------------------------
ZoneGroupManager::~ZoneGroupManager () 
	throw ()
{
	__BEGIN_TRY

	map< ZoneGroupID_t , ZoneGroup *>::iterator itr = m_ZoneGroups.begin();
	for (; itr != m_ZoneGroups.end(); itr++)
	{
		ZoneGroup* pZoneGroup = itr->second;
		SAFE_DELETE(pZoneGroup);
	}

	// �ؽ��ʾȿ� �ִ� ���� pair ��� ����Ѵ�.
	m_ZoneGroups.clear();

	__END_CATCH
}

	
//--------------------------------------------------------------------------------
// initialize zone manager
//--------------------------------------------------------------------------------
void ZoneGroupManager::init () 
	throw (Error)
{
	__BEGIN_TRY

	load();	
			
	__END_CATCH
}

	
//--------------------------------------------------------------------------------
//
// load data from database
//
// ����Ÿ���̽��� �����ؼ� ZoneGroup � �ε��ؿ´�.
//
//--------------------------------------------------------------------------------
void ZoneGroupManager::load ()
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Statement* pStmt = NULL;
	list<ZoneGroupID_t> ZoneGroupIDList;

	// ���� � �׷� ���̵���� �д´�.
	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pResult = pStmt->executeQuery("SELECT ZoneGroupID FROM ZoneGroupInfo ORDER BY ZoneGroupID");

		while (pResult->next())
		{
			ZoneGroupID_t ID = pResult->getInt(1);
			ZoneGroupIDList.push_back(ID);
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)


	list<ZoneGroupID_t>::iterator itr = ZoneGroupIDList.begin();
	for (; itr != ZoneGroupIDList.end(); itr++)
	{
		ZoneGroupID_t ID = (*itr);

		// �ش��ϴ� ID�� � �׷�� �����ϰ�, �Ŵ������� ���Ѵ�.
		ZoneGroup* pZoneGroup = new ZoneGroup(ID);
		ZonePlayerManager* pZonePlayerManager = new ZonePlayerManager();
		pZonePlayerManager->setZGID( ID );
		pZoneGroup->setZonePlayerManager(pZonePlayerManager);
		addZoneGroup(pZoneGroup);

		// �� � �׷쿡 ���ϴ� ��� ����� �о����̰�, �ʱ�ȭ�ؾ� �Ѵ�.
		BEGIN_DB
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			//Result* pResult = pStmt->executeQuery("SELECT ZoneID FROM ZoneInfo WHERE ZoneGroupID = %d", ID);
			Result* pResult = pStmt->executeQuery(
					"SELECT ZoneID FROM ZoneInfo WHERE ZoneGroupID = %d ORDER BY ZoneID", (int)ID);

			while (pResult->next())
			{
				ZoneID_t zoneID = pResult->getInt(1);

				// � ��ü�� ����, �ʱ�ȭ�� ��, ��׷쿡 �߰��Ѵ�.
				Zone* pZone = new Zone(zoneID);
				Assert(pZone != NULL);
								
				pZone->setZoneGroup(pZoneGroup);

				pZoneGroup->addZone(pZone);

				//--------------------------------------------------------------------------------
				// ������ ����� ��.
				// ���ο��� NPC �� �ε��ϰ� �Ǵµ�.. AtFirst-SetPosition �����-�׼�� �����Ҷ�
				// ZoneGroupManager �� ����ϰ� �ȴ�. ������, ���� ZGM�� �߰��� �� �ʱ�ȭ�� �ؾ� �Ѵ�.
				//--------------------------------------------------------------------------------

				printf("\n@@@@@@@@@@@@@@@ [%d]th ZONE INITIALIZATION START @@@@@@@@@@@@@@@\n", zoneID);

				pZone->init();

				printf("\n@@@@@@@@@@@@@@@ [%d]th ZONE INITIALIZATION SUCCESS @@@@@@@@@@@@@@@\n", zoneID);
			}

			SAFE_DELETE(pStmt);
		}
		END_DB(pStmt)
	}

	ZoneGroupIDList.clear();

	/*


	Statement* pStmt1 = NULL;

	try 
	{
		pStmt1 = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		// ZoneGroupID �� �о��´�.
		//Result* pResult1 = pStmt1->executeQuery("SELECT ZoneGroupID FROM ZoneGroupInfo ORDER BY ZoneGroupID");
		Result* pResult1 = pStmt1->executeQuery("SELECT ZoneGroupID FROM ZoneGroupInfo");

		while (pResult1->next()) 
		{
			ZoneGroupID_t zoneGroupID = pResult1->getInt(1);

			// ZoneGroup ��ü�� ZonePlayerManager ��ü�� �����Ѵ�.
			ZoneGroup* pZoneGroup = new ZoneGroup(zoneGroupID);
			ZonePlayerManager* pZonePlayerManager = new ZonePlayerManager();
			pZoneGroup->setZonePlayerManager(pZonePlayerManager);

			// ��׷�� ��׷��Ŵ����� �߰��Ѵ�.
			addZoneGroup(pZoneGroup);
	
			// Ư� ZoneGroupID �� ���� � ����� �о��´�.
			Statement* pStmt2 = NULL;
			
			BEGIN_DB
			{
				pStmt2 = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
				Result* pResult2 = pStmt2->executeQuery("SELECT ZoneID FROM ZoneInfo WHERE ZoneGroupID = %d", zoneGroupID);
		
				while (pResult2->next()) 
				{
					__BEGIN_DEBUG

					ZoneID_t zoneID = pResult2->getInt(1);

					// � ��ü�� ����, �ʱ�ȭ�� ��, ��׷쿡 �߰��Ѵ�.
					Zone* pZone = new Zone (zoneID);
					Assert(pZone != NULL);
									
					pZone->setZoneGroup(pZoneGroup);

					pZoneGroup->addZone(pZone);

					//--------------------------------------------------------------------------------
					// ������ ����� ��.
					// ���ο��� NPC �� �ε��ϰ� �Ǵµ�.. AtFirst-SetPosition �����-�׼�� �����Ҷ�
					// ZoneGroupManager �� ����ϰ� �ȴ�. ������, ���� ZGM�� �߰��� �� �ʱ�ȭ�� �ؾ� �Ѵ�.
					//--------------------------------------------------------------------------------

					printf("\n@@@@@@@@@@@@@@@ [%d]th ZONE INITIALIZATION START @@@@@@@@@@@@@@@\n", zoneID);

					pZone->init();

					printf("\n@@@@@@@@@@@@@@@ [%d]th ZONE INITIALIZATION SUCCESS @@@@@@@@@@@@@@@\n", zoneID);

					__END_DEBUG
				}

				SAFE_DELETE(pStmt2);
			}
			END_DB(pStmt2)
		}

		SAFE_DELETE(pStmt1);
	} 
	catch (SQLQueryException & sqe) 
	{
		SAFE_DELETE(pStmt1);
		throw Error(sqe.toString());
	}
	*/

	__END_DEBUG
	__END_CATCH
}


//--------------------------------------------------------------------------------
// save data to database
//--------------------------------------------------------------------------------
void ZoneGroupManager::save ()
	throw (Error)
{
	__BEGIN_TRY

	throw UnsupportedError();

	__END_CATCH
}


//--------------------------------------------------------------------------------
// add zone to zone manager
//--------------------------------------------------------------------------------
void ZoneGroupManager::addZoneGroup (ZoneGroup* pZoneGroup) 
	throw (Error)
{
	__BEGIN_TRY

	map< ZoneGroupID_t , ZoneGroup *>::iterator itr = m_ZoneGroups.find(pZoneGroup->getZoneGroupID());
	
	if (itr != m_ZoneGroups.end())
		// �Ȱ�� ���̵��� �̹� ����Ѵٴ� �Ҹ���. - -;
		throw Error("duplicated zone id");

	// itr �� ����Ű��
	m_ZoneGroups[ pZoneGroup->getZoneGroupID() ] = pZoneGroup;

	__END_CATCH
}

//--------------------------------------------------------------------------------
// get zone from zone manager
//--------------------------------------------------------------------------------
ZoneGroup* ZoneGroupManager::getZoneGroupByGroupID (ZoneGroupID_t ZoneGroupID) const
	throw (NoSuchElementException)
{
	__BEGIN_TRY
		
	ZoneGroup* pZoneGroup = NULL;

	map< ZoneGroupID_t , ZoneGroup *>::const_iterator itr = m_ZoneGroups.find(ZoneGroupID);
	
	if (itr != m_ZoneGroups.end()) {

		pZoneGroup = itr->second;

	} else {

		// �׷� � ���̵��� ã� �� ����� ��
		StringStream msg;
		msg << "ZoneGroupID : " << ZoneGroupID;
		throw NoSuchElementException(msg.toString());

	}

	return pZoneGroup;

	__END_CATCH
}


//--------------------------------------------------------------------------------
// Delete zone from zone manager
//--------------------------------------------------------------------------------
void ZoneGroupManager::deleteZoneGroup (ZoneGroupID_t zoneID) 
	throw (NoSuchElementException)
{
	__BEGIN_TRY
		
	map< ZoneGroupID_t , ZoneGroup *>::iterator itr = m_ZoneGroups.find(zoneID);
	
	if (itr != m_ZoneGroups.end()) 
	{
		// �� ����Ѵ�.
		SAFE_DELETE(itr->second);

		// pair�� ����Ѵ�.
		m_ZoneGroups.erase(itr);
	} 
	else 
	{
		// �׷� � ���̵��� ã� �� ����� ��
		StringStream msg;
		msg << "ZoneGroupID : " << zoneID;
		throw NoSuchElementException(msg.toString());
	}

	__END_CATCH
}
	

//--------------------------------------------------------------------------------
// get zone from zone manager
//--------------------------------------------------------------------------------
ZoneGroup* ZoneGroupManager::getZoneGroup (ZoneGroupID_t zoneID) const
	throw (NoSuchElementException)
{
	__BEGIN_TRY
		
	ZoneGroup* pZoneGroup = NULL;

	map< ZoneGroupID_t , ZoneGroup *>::const_iterator itr = m_ZoneGroups.find(zoneID);
	
	if (itr != m_ZoneGroups.end()) {

		pZoneGroup = itr->second;

	} else {

		// �׷� � ���̵��� ã� �� ����� ��
		StringStream msg;
		msg << "ZoneGroupID : " << zoneID;
		throw NoSuchElementException(msg.toString());

	}

	return pZoneGroup;

	__END_CATCH
}

void   ZoneGroupManager::broadcast(Packet* pPacket) 
	throw (Error)
{
	ZoneGroup* pZoneGroup = NULL;

	map< ZoneGroupID_t , ZoneGroup *>::const_iterator itr = m_ZoneGroups.begin();
	
	for (; itr != m_ZoneGroups.end(); itr++)
	{
		pZoneGroup = itr->second;

		pZoneGroup->getZonePlayerManager()->broadcastPacket( pPacket );
	}	
}

void ZoneGroupManager::outputLoadValue()
	throw (Error)
{
	//------------------------------------------------------------------
	// ZoneGroup load
	//------------------------------------------------------------------
	ofstream file("loadBalance.txt", ios::app);

	VSDateTime current = VSDateTime::currentDateTime();
	file << current.toString() << endl;

	map< ZoneGroupID_t , ZoneGroup* >::const_iterator itr;

	for (itr = m_ZoneGroups.begin() ; itr != m_ZoneGroups.end() ; itr ++) 
	{
		ZoneGroup* pZoneGroup = itr->second;
		file << "[" << (int)pZoneGroup->getZoneGroupID() << "] ";

		const map< ZoneID_t, Zone* >& zones = pZoneGroup->getZones();
		map< ZoneID_t, Zone* >::const_iterator iZone;

		// �� Zone�� loadValue�� ���Ѵ�.
		int totalLoad = 0;
		for (iZone=zones.begin(); iZone!=zones.end(); iZone++)
		{
			Zone* pZone = iZone->second;

			int load = pZone->getLoadValue();
			int playerLoad = pZone->getPCCount();

			file << (int)pZone->getZoneID() << "(" << load << ", " << playerLoad << ") ";

			totalLoad += load;
		}

		file << " = " << totalLoad << endl;

	}

	file << endl;
	file.close();
}

//---------------------------------------------------------------------------
// make Balanced LoadInfo
//---------------------------------------------------------------------------
//
// bForce : balacing�� �ʿ䰡 ���ٰ� �ǴܵǴ� ���쿡�� 
//          ����� ZoneGroup� balancing�� ���쿡 �����ȴ�.
//
// Zone������ 10�ʰ��� loop ó�� ȸ���� load����� �Ѵ�.
// ���꿡 ���Ǹ� ��ؼ� ��� load�� ����� ���� ����Ѵ�.
//
//     load = (loadLimit - load)*loadMultiplier;
//
//---------------------------------------------------------------------------
bool 	ZoneGroupManager::makeBalancedLoadInfo(LOAD_INFOS& loadInfos, bool bForce)
	throw (Error)
{
	const int maxGroup  		= m_ZoneGroups.size();	// zoneGroup ��
	//const int loadMultiplier 	= 5;					// load ����ġ - ��� �ֵ�� �� �����...���� �ϱ� ��� ��.
	const int loadLimit 		= 500;					// load �� ��� - sleep�� ���ؼ� ��ѵż� ���� ó��ȸ�� 500�� �ְ���.
	const int stableLoad 		= 120;					// ������� load - �� ����� balancing�� �ʿ����ٰ� �����Ǵ� ����
	//const int minLoadGap 		= 20 * loadMultiplier;	// load balancing� �ϱ� ��� load ���� - �ְ�~������ ���̰� ��� �� �̻��̾����� balancing�� �ǹ��ִ�.
	const int minLoadGap 		= 20;	// load balancing� �ϱ� ��� load ���� - �ְ�~������ ���̰� ��� �� �̻��̾����� balancing�� �ǹ��ִ�.
	const int averageLoadPercent = 90;					// �� group�� load % ���. 100��� �ص� �ǰ����� 90����� ������� ����.

	int i;

	//LOAD_INFOS 	loadInfos;
	GROUPS		groups;

	map< ZoneGroupID_t , ZoneGroup* >::const_iterator itr;

	// ��ü load
	int totalLoad = 0;


	//------------------------------------------------------------------
	// ZoneGroup���� loadValue ��� 
	//------------------------------------------------------------------
	int maxLoadValue = 0;
	int minLoadValue = loadLimit;
	for (itr = m_ZoneGroups.begin() ; itr != m_ZoneGroups.end() ; itr ++) 
	{
		ZoneGroup* pZoneGroup = itr->second;

		const map< ZoneID_t, Zone* >& zones = pZoneGroup->getZones();
		map< ZoneID_t, Zone* >::const_iterator iZone;

		// �� Zone�� loadValue�� ���Ѵ�.
		for (iZone=zones.begin(); iZone!=zones.end(); iZone++)
		{
			Zone* pZone = iZone->second;

			int load = pZone->getLoadValue();
			load = min( load, loadLimit );

			// 10~500
			maxLoadValue = max(maxLoadValue, load);
			minLoadValue = min(minLoadValue, load);

			// ���� ����� ��� �Ŵ�.
			// ������ ���Ǹ� ��ؼ� ���ڸ� ����?�´�. --> ū ���� ���ϰ� ū �ɷ� �ٲ۴�.
			// player���ڸ� ���ϰ���ġ�� �����Ѵ�.
			// playerLoad = 1 ~ 20���?
			int playerLoad = pZone->getPCCount()/10;
			playerLoad = max(1, playerLoad);
			//load = (loadLimit - load)*loadMultiplier;	// ���� ����ġ
			load = (loadLimit - load)*playerLoad;	// ���� ����ġ

			LoadInfo* pInfo = new LoadInfo;
			pInfo->id 			= pZone->getZoneID();
			pInfo->oldGroupID 	= itr->first;
			pInfo->groupID 		= -1;
			pInfo->load 		= load;

			// ���Ͽ� zoneID�� �̷����� key
			DWORD key = (load << 8) | pInfo->id;

			loadInfos[key] = pInfo;

			totalLoad += load;
		}
	}

	//------------------------------------------------------------------
	//
	// balancing�� �ʿ����� Ȯ��
	//
	//------------------------------------------------------------------
	if (!bForce)
	{
		int loadBoundary = stableLoad;
		//int loadBoundary = ( loadLimit - stableLoad ) * loadMultiplier;

		// ���� �Ѱ� ��ġ���� �۰ų�
		// min~max ���� ��ġ ���̰� �����ġ �����̸�
		// load balancing�� �ʿ䰡 ����.
		//if (maxLoad <= loadBoundary
		if (minLoadValue >= loadBoundary
			|| maxLoadValue-minLoadValue <= minLoadGap)
		{

			// load�� �ٽ� ����ؾ� �Ѵ�.
			for (itr = m_ZoneGroups.begin() ; itr != m_ZoneGroups.end() ; itr ++) 
			{
				ZoneGroup* pZoneGroup = itr->second;

				// loadValue�� �ʱ�ȭ �����ش�.
				const map< ZoneID_t, Zone* >& zones = pZoneGroup->getZones();
				map< ZoneID_t, Zone* >::const_iterator iZone;

				// �� Zone�� loadValue�� ���Ѵ�.
				for (iZone=zones.begin(); iZone!=zones.end(); iZone++)
				{
					Zone* pZone = iZone->second;

					pZone->initLoadValue();
				}
			}

			return false;
		}
	}

	// ���� load
	//int avgLoad = totalLoad / maxGroups;
	// average�� 90%�� ��� ����
	int avgLoad = totalLoad * averageLoadPercent / maxGroup / 100;

	// ���ο� �׷��� load�� �����ϱ� ��ؼ�
	groups.reserve( maxGroup );
	for (i=0; i<maxGroup; i++)
	{
		groups[i] = 0;
	}

	// balancing�ϱ� ���� ���� ����
	//outputLoadValue();

	//------------------------------------------------------------------
	//
	// load balancing
	//
	// �ణ�� ��ȭ�� ��? FirstFit ����.
	//------------------------------------------------------------------
	LOAD_INFOS::const_iterator iInfo = loadInfos.begin();

	int index = 0;

	for (; iInfo!=loadInfos.end(); iInfo++)
	{
		LoadInfo* pInfo = iInfo->second;

		// ��� �� group� ã�´�.
		int newGroupID = -1;
		for (int k=0; k<maxGroup; k++)
		{
			int groupLoad = groups[index];

			if (groupLoad+pInfo->load <= avgLoad)
			{
				newGroupID = index;	

				if (++index>=maxGroup) index = 0;

				break;
			}

			if (++index>=maxGroup) index = 0;
		}

		// ������ group� �� ã����� � ���� ��� group�� �ִ´�.
		if (newGroupID==-1)
		{
			newGroupID = 0;
			for (int k=1; k<maxGroup; k++)
			{
				if (groups[k] < groups[newGroupID])
				{
					newGroupID = k;
				}
			}
		}

		// newGroupID���ٰ� Info�� �߰��Ѵ�.
		pInfo->groupID = newGroupID + 1;		// 1� ���������� �Ѵ�. -_-;
		groups[newGroupID] += pInfo->load;
	}

	return true;
}

//---------------------------------------------------------------------------
// make DefaultLoadInfo
//---------------------------------------------------------------------------
// DB�� ����� �⺻ ZoneGroup��� ����Ѵ�.
//---------------------------------------------------------------------------
bool	ZoneGroupManager::makeDefaultLoadInfo( LOAD_INFOS& loadInfos )
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Statement* pStmt = NULL;
	list<ZoneGroupID_t> ZoneGroupIDList;

	// ���� � �׷� ���̵���� �д´�.
	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pResult = pStmt->executeQuery("SELECT ZoneGroupID FROM ZoneGroupInfo");

		while (pResult->next())
		{
			ZoneGroupID_t ID = pResult->getInt(1);
			ZoneGroupIDList.push_back(ID);
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)


	list<ZoneGroupID_t>::iterator itr = ZoneGroupIDList.begin();
	for (; itr != ZoneGroupIDList.end(); itr++)
	{
		ZoneGroupID_t ID = *itr;

		BEGIN_DB
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			//Result* pResult = pStmt->executeQuery("SELECT ZoneID FROM ZoneInfo WHERE ZoneGroupID = %d", ID);
			Result* pResult = pStmt->executeQuery(
					"SELECT ZoneID FROM ZoneInfo WHERE ZoneGroupID = %d", ID);

			while (pResult->next())
			{
				ZoneID_t zoneID = pResult->getInt(1);

				LoadInfo* pInfo 	= new LoadInfo;
				pInfo->id 			= zoneID;

				try {
					pInfo->oldGroupID 	= g_pZoneInfoManager->getZoneInfo(zoneID)->getZoneGroupID();
				} catch (NoSuchElementException& ) {
					filelog("makeDefaultLoadInfoError.txt", "NoSuch ZoneInfo : %d", zoneID);
					pInfo->oldGroupID 	= ID;	// �׳� �Ѿ�� �Ѵ�.
				}

				pInfo->groupID 		= ID;
				pInfo->load 		= 0;	// �ǹ̾���.

				loadInfos[zoneID] = pInfo;
			}

			SAFE_DELETE(pStmt);
		}
		END_DB(pStmt)
	}

	ZoneGroupIDList.clear();

	__END_DEBUG
	__END_CATCH

	return true;
}

//---------------------------------------------------------------------------
// balance ZoneGroup ( bForce )
//---------------------------------------------------------------------------
//
// bForce : balacing�� �ʿ䰡 ���ٰ� �ǴܵǴ� ���쿡�� 
//          ����� ZoneGroup� balancing�� ���쿡 �����ȴ�.
//
// bDefault : DB���� ����Ǿ� �ִ� ����� ZoneGroup� ����Ѵ�.
//
// Zone������ 10�ʰ��� loop ó�� ȸ���� load����� �Ѵ�.
// ���꿡 ���Ǹ� ��ؼ� ��� load�� ����� ���� ����Ѵ�.
//
//     load = (loadLimit - load)*loadMultiplier;
//
//---------------------------------------------------------------------------
void   ZoneGroupManager::balanceZoneGroup(bool bForce, bool bDefault) 
	throw (Error)
{
	__BEGIN_TRY

	LOAD_INFOS 	loadInfos;

	//------------------------------------------------------------------
	// zoneGroup� balancing�� LoadInfo�� �����Ѵ�.
	//------------------------------------------------------------------
	if (bDefault)
	{
		makeDefaultLoadInfo( loadInfos );
	}
	else
	{
		if (!makeBalancedLoadInfo( loadInfos, bForce ))
		{
			// balancing�� �ʿ䰡 ���ٰ� �ǴܵǴ� �����̴�.
			return;
		}
	}

	map< ZoneGroupID_t , ZoneGroup* >::const_iterator itr;
	LOAD_INFOS::const_iterator iInfo;

	//------------------------------------------------------------------
	//
	// ZoneGroup ����
	//
	//------------------------------------------------------------------
	// ZonePlayerManager::m_PlayerListQueue
	// m_ZoneGroups 
	// ZoneInfoManager
	// Zone::m_pZoneGroup
	// ZonePlayerManager::m_pPlayers
	//------------------------------------------------------------------
	try {
		//------------------------------------------------------------------
		// LoginServerManager LOCK
		//------------------------------------------------------------------
		//__ENTER_CRITICAL_SECTION(g_pLoginServerManager)
		g_pLoginServerManager->lock();

		//------------------------------------------------------------------
		//
		// 					LOCK all ZoneGroups
		//
		//------------------------------------------------------------------

		for (itr = m_ZoneGroups.begin() ; itr != m_ZoneGroups.end() ; itr ++) 
		{
			ZoneGroup* pZoneGroup = itr->second;
			pZoneGroup->lock();
			pZoneGroup->processPlayers();	// ���~���� �ұ�. Ư�� EventResurrect�����̴�.
		}

		//------------------------------------------------------------------
		// Zone���� ���� �ֵ�� �ٽ� ��ǥ Zone��� �ִ´�.
		//------------------------------------------------------------------
		g_pIncomingPlayerManager->heartbeat();

		//------------------------------------------------------------------
		// �� ZoneGroup�� 
		// ZPM���� Zone��� ��� ���⿭�� �ִ� �����ڵ�� �켱 �־�����.
		//------------------------------------------------------------------
		for (itr = m_ZoneGroups.begin() ; itr != m_ZoneGroups.end() ; itr ++) 
		{
			ZoneGroup* pZoneGroup = itr->second;

			// ZonePlayerManager::m_PlayerListQueue�� ������ش�. --> �ϴ� Zone�� �߰�.
			pZoneGroup->getZonePlayerManager()->processPlayerListQueue();
		}

		//------------------------------------------------------------------
		// ZoneGroup ����
		//------------------------------------------------------------------
		for (iInfo=loadInfos.begin(); iInfo!=loadInfos.end(); iInfo++)
		{
			LoadInfo* pInfo = iInfo->second;

			int oldGroupID = pInfo->oldGroupID;
			int newGroupID = pInfo->groupID;
			int zoneID = pInfo->id;

			// group�� ����� �̵���ų �ʿ䰡 ����.
			if (oldGroupID==newGroupID)
			{
				//cout << "same ZoneGroup" << endl;
				continue;
			}
			
			try {
				//cout << "[" << (int)zoneID << "] " << (int)oldGroupID << " --> " << (int)newGroupID << endl;

				map< ZoneGroupID_t , ZoneGroup* >::iterator iOldZoneGroup = m_ZoneGroups.find( oldGroupID );
				map< ZoneGroupID_t , ZoneGroup* >::iterator iNewZoneGroup = m_ZoneGroups.find( newGroupID );

				ZoneGroup* pOldZoneGroup = iOldZoneGroup->second;
				ZoneGroup* pNewZoneGroup = iNewZoneGroup->second;

				// ZonePlayerManager
				ZonePlayerManager* pOldZPM = pOldZoneGroup->getZonePlayerManager();
				ZonePlayerManager* pNewZPM = pNewZoneGroup->getZonePlayerManager();
				
				Zone* pZone = pOldZoneGroup->getZone(zoneID);

				// Old ZoneGroup --> New ZoneGroup
				pOldZoneGroup->removeZone( zoneID );
				pNewZoneGroup->addZone( pZone );
				

				// ZoneGroup
				pZone->setZoneGroup( pNewZoneGroup );

				// ZoneInfoManager
				ZoneInfo* pZoneInfo = g_pZoneInfoManager->getZoneInfo( zoneID );
				pZoneInfo->setZoneGroupID( newGroupID );

				//------------------------------------------------------------------
				// ZonePlayerManager::m_pPlayers
				//------------------------------------------------------------------
				// pZone�� PCManager�� �ֵ�� 
				// 		pOldZoneGroup->m_pZonePlayerManager���� ����ؼ�
				// 		pZoneGroup->m_pZonePlayerManager�� �߰��Ѵ�.
				//------------------------------------------------------------------
				const PCManager* pPCManager = pZone->getPCManager();
				const map< ObjectID_t, Creature* >& players = pPCManager->getCreatures();
				map< ObjectID_t, Creature* >::const_iterator iPlayer;

				// �� Player���� ZPM� �ű���.
				for (iPlayer=players.begin(); iPlayer!=players.end(); iPlayer++)
				{
					Player* pPlayer = iPlayer->second->getPlayer();

					pOldZPM->deletePlayer_NOBLOCKED( pPlayer->getSocket()->getSOCKET() );
					pNewZPM->addPlayer_NOBLOCKED( dynamic_cast<GamePlayer*>(pPlayer) );
				}

			} catch (NoSuchElementException& t) {
				filelog("changeZoneGroupError.txt", "%s", t.toString().c_str());
			}
		}

		// balancing�� ���� ���� ����
		outputLoadValue();

		//------------------------------------------------------------------
		//
		// 					UNLOCK all ZoneGroups
		//
		//------------------------------------------------------------------
		for (itr = m_ZoneGroups.begin() ; itr != m_ZoneGroups.end() ; itr ++) 
		{
			ZoneGroup* pZoneGroup = itr->second;

			// loadValue�� �ʱ�ȭ �����ش�.
			const map< ZoneID_t, Zone* >& zones = pZoneGroup->getZones();
			map< ZoneID_t, Zone* >::const_iterator iZone;

			// �� Zone�� loadValue�� ���Ѵ�.
			for (iZone=zones.begin(); iZone!=zones.end(); iZone++)
			{
				Zone* pZone = iZone->second;

				pZone->initLoadValue();
			}

			pZoneGroup->unlock();
		}

		//------------------------------------------------------------------
		// LoginServerManager UNLOCK
		//------------------------------------------------------------------
		//__LEAVE_CRITICAL_SECTION(g_pLoginServerManager)
		g_pLoginServerManager->unlock();

	} catch (Throwable& t) {
		filelog("balanceZoneGroup.txt", "%s", t.toString().c_str());

		for (itr = m_ZoneGroups.begin() ; itr != m_ZoneGroups.end() ; itr ++) 
		{
			ZoneGroup* pZoneGroup = itr->second;
			pZoneGroup->unlock();
		}
	}


	//------------------------------------------------------------------
	// loadInfos �����ֱ�
	//------------------------------------------------------------------
	for (iInfo=loadInfos.begin(); iInfo!=loadInfos.end(); iInfo++)
	{
		LoadInfo* pInfo = iInfo->second;

		SAFE_DELETE(pInfo);
	}
	

	__END_CATCH
}

//--------------------------------------------------------------------------------
// lock all ZoneGroup and LoginServerManager
//--------------------------------------------------------------------------------
void ZoneGroupManager::lockZoneGroups()
	throw( Error )
{
	__BEGIN_TRY

	//------------------------------------------------------------------
	// LoginServerManager UNLOCK
	//------------------------------------------------------------------
	g_pLoginServerManager->lock();

	//------------------------------------------------------------------
	//
	// 					LOCK all ZoneGroups
	//
	//------------------------------------------------------------------
	map< ZoneGroupID_t , ZoneGroup* >::const_iterator itr;

	for (itr = m_ZoneGroups.begin() ; itr != m_ZoneGroups.end() ; itr ++) 
	{
		ZoneGroup* pZoneGroup = itr->second;
		pZoneGroup->lock();
//		pZoneGroup->processPlayers();	// ���~���� �ұ�. Ư�� EventResurrect�����̴�.
	}

	__END_CATCH
}

//--------------------------------------------------------------------------------
// lock all ZoneGroup and LoginServerManager
//--------------------------------------------------------------------------------
void ZoneGroupManager::unlockZoneGroups()
	throw( Error )
{
	__BEGIN_TRY

	//------------------------------------------------------------------
	//
	// 					UNLOCK all ZoneGroups
	//
	//------------------------------------------------------------------
	map< ZoneGroupID_t , ZoneGroup* >::const_iterator itr;

	for (itr = m_ZoneGroups.begin() ; itr != m_ZoneGroups.end() ; itr ++) 
	{
		ZoneGroup* pZoneGroup = itr->second;
		pZoneGroup->unlock();
//		pZoneGroup->processPlayers();	// ���~���� �ұ�. Ư�� EventResurrect�����̴�.
	}

	//------------------------------------------------------------------
	// LoginServerManager UNLOCK
	//------------------------------------------------------------------
	g_pLoginServerManager->unlock();


	__END_CATCH
}

//--------------------------------------------------------------------------------
// get PlayerNum. by sigi. 2002.12.30
//--------------------------------------------------------------------------------
int ZoneGroupManager::getPlayerNum () const
	throw (Error)
{
	__BEGIN_TRY

	int numPC = 0;
	
	map< ZoneGroupID_t , ZoneGroup* >::const_iterator itr = m_ZoneGroups.begin();

	for (; itr != m_ZoneGroups.end() ; itr ++) 
	{
		ZoneGroup* pZoneGroup = itr->second;
		
		// lock �� �ʿ� ����
		numPC += pZoneGroup->getZonePlayerManager()->size();
	}

	return numPC;

	__END_CATCH
}

void   ZoneGroupManager::removeFlag(Effect::EffectClass EC)
	throw (Error)
{
	__BEGIN_TRY

	ZoneGroup* pZoneGroup = NULL;

	map< ZoneGroupID_t , ZoneGroup *>::const_iterator itr = m_ZoneGroups.begin();
	
	for (; itr != m_ZoneGroups.end(); itr++)
	{
		pZoneGroup = itr->second;

		pZoneGroup->getZonePlayerManager()->removeFlag( EC );
	}	

	__END_CATCH
}

//--------------------------------------------------------------------------------
// get debug string
//--------------------------------------------------------------------------------
string ZoneGroupManager::toString () const
	throw ()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "ZoneGroupManager(";
		
	for (map< ZoneGroupID_t , ZoneGroup* >::const_iterator itr = m_ZoneGroups.begin() ; itr != m_ZoneGroups.end() ; itr ++) 
	{
		msg << itr->second->toString();
	}

	msg << ")";

	return msg.toString();

	__END_CATCH
}

// global variable definition
ZoneGroupManager* g_pZoneGroupManager = NULL;
