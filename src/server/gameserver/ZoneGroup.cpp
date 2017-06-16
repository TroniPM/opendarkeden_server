//////////////////////////////////////////////////////////////////////////////
// Filename    : ZoneGroup.cc
// Written By  : reiot@ewestsoft.com
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "ZoneGroup.h"
#include "ZonePlayerManager.h"
#include "Assert.h"
#include "VSDateTime.h"
#include "Profile.h"

//////////////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////////////
ZoneGroup::ZoneGroup (ZoneGroupID_t zoneGroupID) 
	throw ()
: m_ZoneGroupID(zoneGroupID), m_pZonePlayerManager(NULL)
{
	__BEGIN_TRY

	m_Mutex.setName("ZoneGroupMutex");

	Assert(m_ZoneGroupID > 0);

	m_TickTime.tv_sec = 0;
	m_TickTime.tv_usec = 0;

	__END_CATCH
}
	
//////////////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////////////
ZoneGroup::~ZoneGroup () 
	throw ()
{
	__BEGIN_TRY

	// �ؽ��ʾȿ� �ִ� ���� pair ��� ����Ѵ�.
	m_Zones.clear();

	__END_CATCH
}
	
//////////////////////////////////////////////////////////////////////////////
// initialize zone group
//////////////////////////////////////////////////////////////////////////////
void ZoneGroup::init () 
	throw (Error)
{
	__BEGIN_TRY

	// init == load
	load();
			
	__END_CATCH
}
	
//////////////////////////////////////////////////////////////////////////////
// load from database
//////////////////////////////////////////////////////////////////////////////
void ZoneGroup::load ()
	throw (Error)
{
	__BEGIN_TRY

	throw UnsupportedError();

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// save to database
//////////////////////////////////////////////////////////////////////////////
void ZoneGroup::save ()
	throw (Error)
{
	__BEGIN_TRY

	throw UnsupportedError();

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// process all players in zone player manager
//////////////////////////////////////////////////////////////////////////////
void ZoneGroup::processPlayers ()
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	//__ENTER_CRITICAL_SECTION(m_Mutex)

	try 
	{
		//m_pZonePlayerManager->copyPlayers();
		//__ENTER_CRITICAL_SECTION(m_pZonePlayerManager)

		beginProfileEx("ZPM_SELECT");
		m_pZonePlayerManager->select();
		endProfileEx("ZPM_SELECT");

		beginProfileEx("ZPM_EXCEPTION");
		m_pZonePlayerManager->processExceptions();
		endProfileEx("ZPM_EXCEPTION");

		beginProfileEx("ZPM_INPUT");
		m_pZonePlayerManager->processInputs();
		endProfileEx("ZPM_INPUT");

		beginProfileEx("ZPM_OUTPUT");
		m_pZonePlayerManager->processOutputs();
		endProfileEx("ZPM_OUTPUT");

		//__LEAVE_CRITICAL_SECTION(m_pZonePlayerManager)
	} 
	catch (TimeoutException&) 
	{
		// timeout �� �߻��ϸ�, �Է�, ����, OOB ó�� ���� ���̳� �� �� ����..
		// �߸��� FD�� ��� ���� ¥���� ��Ͽ� �����Ѵ� -_-;
		//m_pZonePlayerManager->processOutputs();
	} 
	catch (InterruptedException & ie) 
	{
		//throw Error(ie.toString());
	}
	catch (IOException & ioe) 
	{
		//throw Error(ioe.toString());
	}
	catch (Error& er)
	{
		filelog("errorLog.txt", "%s", er.toString().c_str());

		//Assert(false);
	}

	try {

		// ���� �÷��̾��� ����� ó���Ѵ�.
		beginProfileEx("ZPM_COMMAND");
	//	__ENTER_CRITICAL_SECTION(m_pZonePlayerManager)
		m_pZonePlayerManager->processCommands();
	//	__LEAVE_CRITICAL_SECTION(m_pZonePlayerManager)
		endProfileEx("ZPM_COMMAND");

	} catch (Error& er) {
		filelog("errorLog.txt", "%s", er.toString().c_str());

		//Assert(false);
	} catch (Throwable&) {
	}

	try {
		beginProfileEx("ZPM_HEARTBEAT");
		m_pZonePlayerManager->heartbeat();	// ���ο��� lock�Ǵ�.
		endProfileEx("ZPM_HEARTBEAT");
	} catch (Error& er) {

		filelog("errorLog.txt", "%s", er.toString().c_str());

		//Assert(false);
	} catch (Throwable&) {
	}

	//__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_DEBUG
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// process all npc, monsters, ... in zones
//////////////////////////////////////////////////////////////////////////////
void ZoneGroup::heartbeat()
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	//VSTime vstime;
	//vstime.start();
	//__ENTER_CRITICAL_SECTION(m_Mutex)

	// now process each zones' NPCs, MOBs, weather, quest, ...
	for (map< ZoneID_t , Zone* >::iterator itr = m_Zones.begin() ; itr != m_Zones.end() ; itr ++) 
	{
		Zone* pZone = itr->second;
		pZone->heartbeat();
	}

	//__LEAVE_CRITICAL_SECTION(m_Mutex)

	//filelog("ZoneGroupHeartbeat.txt", "ZoneGroupID[%d]ZoneGroupHeartbeat:%d", m_ZoneGroupID, vstime.elapsed());

	__END_DEBUG
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// process all npc, monsters, ... in zones
//////////////////////////////////////////////////////////////////////////////
void ZoneGroup::makeZoneUserInfo(GMServerInfo & gmServerInfo )
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	//VSTime vstime;
	//vstime.start();

	// now process each zones' NPCs, MOBs, weather, quest, ...
	for (map< ZoneID_t , Zone* >::iterator itr = m_Zones.begin() ; itr != m_Zones.end() ; itr ++) 
	{
		Zone* pZone = itr->second;

		gmServerInfo.addZoneUserData( pZone->getZoneID(), pZone->getPCCount() );
	}

	//filelog("ZoneGroupHeartbeat.txt", "ZoneGroupID[%d]ZoneGroupHeartbeat:%d", m_ZoneGroupID, vstime.elapsed());

	__END_DEBUG
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// add zone to zone group
//////////////////////////////////////////////////////////////////////////////
void ZoneGroup::addZone (Zone* pZone) 
	throw (Error)
{
	__BEGIN_TRY

	// �ϴ� ��� ���̵��� ��� �ִ��� üũ�غ���.
	map< ZoneID_t , Zone *>::iterator itr = m_Zones.find(pZone->getZoneID());
	
	if (itr != m_Zones.end())
		// �Ȱ�� ���̵��� �̹� ����Ѵٴ� �Ҹ���. - -;
		throw Error("duplicated zone id");

	m_Zones[ pZone->getZoneID() ] = pZone;

	__END_CATCH
}
	
//////////////////////////////////////////////////////////////////////////////
// Delete zone from zone group
//////////////////////////////////////////////////////////////////////////////
void ZoneGroup::deleteZone (ZoneID_t zoneID) 
	throw (NoSuchElementException)
{
	__BEGIN_TRY
		
	map< ZoneID_t , Zone *>::iterator itr = m_Zones.find(zoneID);
	
	if (itr != m_Zones.end()) 
	{
		// �� ����Ѵ�.
		SAFE_DELETE(itr->second);

		// pair�� ����Ѵ�.
		m_Zones.erase(itr);
	} 
	else 
	{
		// �׷� � ���̵��� ã� �� ����� ��
		StringStream msg;
		msg << "ZoneID : " << zoneID;
		throw NoSuchElementException(msg.toString());
	}

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// Remove zone from zone group
// delete���� �ʰ� node�� �����ش�.
//////////////////////////////////////////////////////////////////////////////
Zone* ZoneGroup::removeZone (ZoneID_t zoneID) 
	throw (NoSuchElementException)
{
	__BEGIN_TRY
		
	map< ZoneID_t , Zone *>::iterator itr = m_Zones.find(zoneID);
	
	if (itr != m_Zones.end()) 
	{
		// �� ����Ѵ�.
		//SAFE_DELETE(itr->second);
		Zone* pZone = itr->second;

		// pair�� ����Ѵ�.
		m_Zones.erase(itr);

		return pZone;
	} 
	else 
	{
		// �׷� � ���̵��� ã� �� ����� ��
		StringStream msg;
		msg << "ZoneID : " << zoneID;
		throw NoSuchElementException(msg.toString());
	}

	return NULL;

	__END_CATCH
}
	
//////////////////////////////////////////////////////////////////////////////
// get zone from zone group
//////////////////////////////////////////////////////////////////////////////
Zone* ZoneGroup::getZone (ZoneID_t zoneID) const
	throw (NoSuchElementException)
{
	__BEGIN_TRY
		
	Zone* pZone = NULL;

	map< ZoneID_t , Zone *>::const_iterator itr = m_Zones.find(zoneID);
	
	if (itr != m_Zones.end()) 
	{
		pZone = itr->second;
	} 
	else 
	{
		// �׷� � ���̵��� ã� �� ����� ��
		StringStream msg;
		msg << "ZoneID : " << zoneID;
		throw NoSuchElementException(msg.toString());
	}

	return pZone;

	__END_CATCH
}

//#ifdef __NO_COMBAT__
Zone* ZoneGroup::getCombatZone (ZoneID_t zoneID) const
	throw (Error)
{
	Zone* pZone = NULL;

	__BEGIN_TRY
		
	map< ZoneID_t , Zone *>::const_iterator itr = m_Zones.find(zoneID);
	
	if(itr != m_Zones.end()){ 
		pZone = itr->second;
		return pZone;
	}

	__END_CATCH

	return NULL;
}
//#endif

void   
ZoneGroup::initLoadValue()
{
	Zone* pZone = NULL;

	__BEGIN_TRY
		
	map< ZoneID_t , Zone *>::const_iterator itr = m_Zones.begin();
	
	while (itr != m_Zones.end())
	{ 
		pZone = itr->second;

		pZone->initLoadValue();

		itr++;
	}

	__END_CATCH
}

DWORD  
ZoneGroup::getLoadValue() const
{
	Zone* pZone = NULL;
	DWORD loadValue = 0;

	__BEGIN_TRY

	map< ZoneID_t , Zone *>::const_iterator itr = m_Zones.begin();
	
	while (itr != m_Zones.end())
	{ 
		pZone = itr->second;

		loadValue += pZone->getLoadValue();

		itr++;
	}

	__END_CATCH

	return loadValue;
}


//////////////////////////////////////////////////////////////////////////////
// get debug string
//////////////////////////////////////////////////////////////////////////////
string ZoneGroup::toString () const
	throw ()
{
	StringStream msg;
	msg << "ZoneGroup("
			<< "ZoneGroupID:" << (int)m_ZoneGroupID
			<< "GameTime:"    << m_GameTime.toString()
			<< ")";	
	return msg.toString();
}
