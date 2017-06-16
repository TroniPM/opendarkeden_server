//////////////////////////////////////////////////////////////////////////////
// Filename    : GameServerInfoManager.h
// Written By  : reiot@ewestsoft.com
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __GAME_SERVER_INFO_MANAGER_H__
#define __GAME_SERVER_INFO_MANAGER_H__

#include "Types.h"
#include "Exception.h"
#include "GameServerInfo.h"
#include <map>

typedef map<ServerID_t, GameServerInfo*> HashMapGameServerInfo;

//////////////////////////////////////////////////////////////////////////////
// class GameServerInfoManager;
// ���� ������ ID �� Ű����� �ϴ� GameServerInfo�� map � 
// ���ο� ������ �ִ�.
//////////////////////////////////////////////////////////////////////////////

class GameServerInfoManager 
{
public:
	GameServerInfoManager () throw ();
	~GameServerInfoManager () throw ();

public:
	void init () throw ( Error );
	void load () throw ( Error );

	// clear GameServerInfo objects
	void clear() throw ( Error );
	
	void addGameServerInfo ( GameServerInfo * pGameServerInfo, const ServerGroupID_t ServerGroupID, WorldID_t WorldID ) throw ( DuplicatedException );
	void deleteGameServerInfo ( const ServerID_t ServerID, const ServerGroupID_t ServerGroupID, WorldID_t WorldID ) throw ( NoSuchElementException );
	//GameServerInfo * getGameServerInfo ( const string & name ) const throw ( NoSuchElementException );
	GameServerInfo * getGameServerInfo ( const ServerID_t ServerID, const ServerGroupID_t ServerGroupID, WorldID_t WorldID ) const throw( NoSuchElementException );
	uint getSize ( WorldID_t WorldID, const ServerGroupID_t ServerGroupID ) const throw () { return m_pGameServerInfos[WorldID][ServerGroupID].size(); }
	string toString () const throw ();

	// by sigi. 2002.5.30
	int						getMaxWorldID() const		{ return m_MaxWorldID; }
	int						getMaxServerGroupID() const		{ return m_MaxServerGroupID; }
	HashMapGameServerInfo** getGameServerInfos() const { return m_pGameServerInfos; }
private:
	// hash map of GameServerInfo
	// key   : GameServerID_t
	// value : GameServerInfo *
	HashMapGameServerInfo** m_pGameServerInfos;
	int m_MaxServerGroupID;
	int m_MaxWorldID;

};

// global variable declaration
extern GameServerInfoManager * g_pGameServerInfoManager;

#endif
