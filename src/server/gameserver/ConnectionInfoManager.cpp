//////////////////////////////////////////////////////////////////////////////
// Filename    : ConnectionInfoManager.cpp
// Written By  : Reiot
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "ConnectionInfoManager.h"
#include "StringStream.h"
#include "Assert.h"
#include "DB.h"
#include "ZoneGroup.h"
#include "ZoneGroupManager.h"
#include "LoginServerManager.h"
#include "ZonePlayerManager.h"
#include "Properties.h"
#include "LogDef.h"
#include <stdio.h>

#include "Gpackets/GMServerInfo.h"

// global variable definition
ConnectionInfoManager* g_pConnectionInfoManager = NULL;

//////////////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////////////
ConnectionInfoManager::ConnectionInfoManager () 
	throw ()
{
	__BEGIN_TRY

	m_Mutex.setName("ConnectionInfoManager");

	// ��� heartbeat �ð�� ����Ѵ�.
	getCurrentTime(m_NextHeartbeat);
	m_NextHeartbeat.tv_sec += 10;

	// 30���� ������ ���� �����.
	m_UpdateUserStatusTime.tv_sec = m_NextHeartbeat.tv_sec + 20;

	__END_CATCH
}
	
//////////////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////////////
ConnectionInfoManager::~ConnectionInfoManager () 
	throw ()
{
	__BEGIN_TRY

	// ���� ConnectionInfo �� ����ؾ� �Ѵ�.
	HashMapConnectionInfo::iterator itr = m_ConnectionInfos.begin() ;
	for (; itr != m_ConnectionInfos.end(); itr++) 
	{
		SAFE_DELETE(itr->second);
	}

	// �ؽ��ʾȿ� �ִ� ���� pair ��� ����Ѵ�.
	m_ConnectionInfos.clear();

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// add connection info to connection info manager
//////////////////////////////////////////////////////////////////////////////
void ConnectionInfoManager::addConnectionInfo (ConnectionInfo* pConnectionInfo) 
	throw (DuplicatedException , Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	Assert(pConnectionInfo != NULL);

	HashMapConnectionInfo::iterator itr = m_ConnectionInfos.find(pConnectionInfo->getClientIP());
	
	if (itr != m_ConnectionInfos.end())
	{
		// �Ȱ�� ���̵��� �̹� ����Ѵٴ� �Ҹ���. - -;
		//throw DuplicatedException("duplicated connection info id");

		// ����� �ִ� ����� ����ϰ� ������� ����Ѵ�.
		// by sigi. 2002.12.7
		//throw DuplicatedException("duplicated connection info id");
		ConnectionInfo* pOldConnectionInfo = itr->second;

		FILELOG_INCOMING_CONNECTION("connectionInfo.log", "DupDelete [%s:%s] %s (%u)",
										pOldConnectionInfo->getPlayerID().c_str(),
										pOldConnectionInfo->getPCName().c_str(),
										pOldConnectionInfo->getClientIP().c_str(),
										pOldConnectionInfo->getKey());

		SAFE_DELETE(pOldConnectionInfo);

		itr->second = pConnectionInfo;

		m_Mutex.unlock();

		return;

	}

	m_ConnectionInfos[ pConnectionInfo->getClientIP() ] = pConnectionInfo;

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}
	
//////////////////////////////////////////////////////////////////////////////
// Delete connection info from connection info manager
//////////////////////////////////////////////////////////////////////////////
void ConnectionInfoManager::deleteConnectionInfo (const string& clientIP) 
	throw (NoSuchElementException , Error)
{
	__BEGIN_TRY
		
	__ENTER_CRITICAL_SECTION(m_Mutex)

	HashMapConnectionInfo::iterator itr = m_ConnectionInfos.find(clientIP);
	
	if (itr != m_ConnectionInfos.end()) 
	{
		Assert(itr->second != NULL);

		// ConnectionInfo �� ����Ѵ�.
		SAFE_DELETE(itr->second);

		// pair�� ����Ѵ�.
		m_ConnectionInfos.erase(itr);
	} 
	else 
	{
		throw NoSuchElementException(clientIP);
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}
	

//////////////////////////////////////////////////////////////////////////////
// get connection info from connection info manager
//////////////////////////////////////////////////////////////////////////////
ConnectionInfo* ConnectionInfoManager::getConnectionInfo (const string& clientIP) 
	throw (NoSuchElementException , Error)
{
	__BEGIN_TRY
		
	ConnectionInfo* pConnectionInfo = NULL;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	HashMapConnectionInfo::iterator itr = m_ConnectionInfos.find(clientIP);
	
	if (itr != m_ConnectionInfos.end()) 
	{
		pConnectionInfo = itr->second;
	} 
	else 
	{
		throw NoSuchElementException(clientIP);
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return pConnectionInfo;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// expire �� Connection Info ��ü�� ����Ѵ�.
//////////////////////////////////////////////////////////////////////////////
void ConnectionInfoManager::heartbeat ()
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	Timeval currentTime;
	getCurrentTime(currentTime);

	if (m_NextHeartbeat < currentTime) 
	{
		m_NextHeartbeat = currentTime;
		m_NextHeartbeat.tv_sec += 10;

	    HashMapConnectionInfo::iterator before  = m_ConnectionInfos.end() ;
		HashMapConnectionInfo::iterator current = m_ConnectionInfos.begin() ;

		while (current != m_ConnectionInfos.end()) 
		{
			if (current->second->getExpireTime() < currentTime) 
			{
				ConnectionInfo* pConnectionInfo = current->second;

				m_ConnectionInfos.erase(current);

				// by sigi. 2002.12.7
				FILELOG_INCOMING_CONNECTION("connectionInfo.log", "Expire [%s:%s] %s (%u)",
										pConnectionInfo->getPlayerID().c_str(),
										pConnectionInfo->getPCName().c_str(),
										pConnectionInfo->getClientIP().c_str(),
										pConnectionInfo->getKey());


				SAFE_DELETE(pConnectionInfo);

				if (before == m_ConnectionInfos.end()) 	// case of first
				{  
					current = m_ConnectionInfos.begin();
				} 
				else 										// case of not first
				{                        
					current = before;
					current ++;
				}
			} 
			else 
			{
				before = current ++ ;
			}
    	}

		// ������ ���� ����� �˸���.
		Statement* pStmt = NULL;
		Result* pResult = NULL;

		static int GroupCount = 0;

		BEGIN_DB
		{
			if (GroupCount==0)
			{
				pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
				pResult = pStmt->executeQuery("SELECT MAX(ZoneGroupID) FROM ZoneGroupInfo");

				pResult->next();

				GroupCount = pResult->getInt(1) + 1;

				SAFE_DELETE(pStmt);
			}
		}
		END_DB(pStmt)

		GMServerInfo gmServerInfo;

		static int worldID = g_pConfig->getPropertyInt("WorldID" );
		static int serverID = g_pConfig->getPropertyInt("ServerID");

		gmServerInfo.setWorldID( worldID );
		gmServerInfo.setServerID( serverID );

		//cout << "GroupCount: " << GroupCount << endl;
		uint numPC = 0;

		for (int i = 1; i < GroupCount; i++) 
		{
			ZoneGroup* pZoneGroup = NULL;

			try 
			{
				pZoneGroup = g_pZoneGroupManager->getZoneGroupByGroupID(i);
			} 
			catch (NoSuchElementException& t) 
			{
				throw Error("Critical Error : ZoneInfoManager�� �ش� ��׷��� ������� �ʽ�ϴ�.");
			}

			pZoneGroup->makeZoneUserInfo(gmServerInfo);

			numPC += pZoneGroup->getZonePlayerManager()->size();
		}

		// �ݸ������̸� DB�� ����.. by sigi. 2002.11.4
		if (currentTime > m_UpdateUserStatusTime)
		{
			// 1�� ����
			m_UpdateUserStatusTime.tv_sec = currentTime.tv_sec + 30;

			if (g_pConfig->getPropertyInt("IsNetMarble")==1)
			{
				pStmt = NULL;
				BEGIN_DB
				{
					pStmt = g_pDatabaseManager->getUserInfoConnection()->createStatement();

					pStmt->executeQuery( 
							"UPDATE UserStatus SET CurrentUser=%d WHERE WorldID=%d AND ServerID=%d", 
							numPC, worldID, serverID);

					// ���ٸ� �߰��ؾ���
					if (pStmt->getAffectedRowCount()==0)
					{
						pStmt->executeQuery( 
								"INSERT IGNORE INTO UserStatus (WorldID, ServerID, CurrentUser) Values (%d, %d, %d)",
								worldID, serverID, numPC);
					}

					SAFE_DELETE(pStmt);
				}
				END_DB(pStmt)
			}
		}

		// ����� MonitorClient���� �� ��� �޾Ƽ� �Ⱦ���.
		//g_pLoginServerManager->sendPacket(g_pConfig->getProperty("MonitorClientIP1") , g_pConfig->getPropertyInt("MonitorClient1UDPORT"), &gmServerInfo);
		//g_pLoginServerManager->sendPacket(g_pConfig->getProperty("MonitorClientIP2") , g_pConfig->getPropertyInt("MonitorClient2UDPORT"), &gmServerInfo);

		static int portNum = g_pConfig->getPropertyInt("LoginServerUDPPortNum");
		static const string& loginServerIP = g_pConfig->getProperty("LoginServerIP");
		static int loginServerUDPPort = g_pConfig->getPropertyInt("LoginServerUDPPort");
		static int loginServerBaseUDPPort = g_pConfig->getPropertyInt("LoginServerBaseUDPPort");

		// �⺻
		g_pLoginServerManager->sendPacket( loginServerIP, loginServerUDPPort, &gmServerInfo);

		// �������� -_-;
		if (portNum > 1)
		{
			for ( int j = 0 ; j < portNum ; j++ )
			{
				g_pLoginServerManager->sendPacket(loginServerIP, loginServerBaseUDPPort+j, &gmServerInfo);
			}
		}

	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// get debug string
//////////////////////////////////////////////////////////////////////////////
string ConnectionInfoManager::toString () const
	throw ()
{
	StringStream msg;

	msg << "ConnectionInfoManager(";

	for (map<string, ConnectionInfo*>::const_iterator itr = m_ConnectionInfos.begin() ; itr != m_ConnectionInfos.end() ;itr++)
	{
		Assert(itr->second != NULL);
		msg << itr->second->toString();
	}

	msg << ")";

	return msg.toString();
}


