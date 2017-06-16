//////////////////////////////////////////////////////////////////////////////
// Filename    : GuildManager.h
// Written By  : �輺��
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __GUILDMANAGER_H__
#define __GUILDMANAGER_H__

#include "Types.h"
#include "Assert.h"
#include "Exception.h"
#include "Mutex.h"
#include "Timeval.h"
#include <map>

//////////////////////////////////////////////////////////////////////////////
// class GuildManager
// ���� Ȱ������ ������ ���� �������� ���带 �޸𸮿� map ���·� ������ �ְ�,
// ���ο� ������ ����/����� �����Ѵ�.
//
//////////////////////////////////////////////////////////////////////////////

class Guild;

typedef map<GuildID_t, Guild*> HashMapGuild;
typedef map<GuildID_t, Guild*>::iterator HashMapGuildItor;
typedef map<GuildID_t, Guild*>::const_iterator HashMapGuildConstItor;

#ifdef __SHARED_SERVER__
class SGGuildInfo;
#endif

class GCWaitGuildList;
class GCActiveGuildList;
class PlayerCreature;

class GuildManager
{

///// Member methods /////
	
public: // constructor & destructor 
	GuildManager() throw();
	~GuildManager() throw();


public: // initializing related methods
	void init() throw();
	void load() throw();


public: // memory related methods
	void addGuild(Guild* pGuild) throw(DuplicatedException);
	void addGuild_NOBLOCKED(Guild* pGuild) throw(DuplicatedException);
	void deleteGuild(GuildID_t id) throw(NoSuchElementException);
	Guild* getGuild(GuildID_t id) throw();
	Guild* getGuild_NOBLOCKED(GuildID_t id) throw();

	void clear() throw();
	void clear_NOBLOCKED();


public: // misc methods
	ushort getGuildSize() const throw() { return m_Guilds.size(); }
	HashMapGuild& getGuilds() throw() { return m_Guilds; }
	const HashMapGuild& getGuilds_const() const throw() { return m_Guilds; }

#ifdef __SHARED_SERVER__
public:
	void makeSGGuildInfo( SGGuildInfo& sgGuildInfo ) throw();
#endif

	void makeWaitGuildList( GCWaitGuildList& gcWaitGuildList, GuildRace_t race ) throw();
	void makeActiveGuildList( GCActiveGuildList& gcWaitGuildList, GuildRace_t race ) throw();

public:
	void lock() { m_Mutex.lock(); }
	void unlock() { m_Mutex.unlock(); }


public:
	void heartbeat() throw(Error);

public:
	bool isGuildMaster( GuildID_t guildID, PlayerCreature* pPC ) throw(Error);

	string getGuildName( GuildID_t guildID ) throw (Error);

	// ���尡 ��� �����?
	bool hasCastle( GuildID_t guildID ) throw(Error);
	bool hasCastle( GuildID_t guildID, ServerID_t& serverID, ZoneID_t& zoneID ) throw(Error);

	// ���尡 ������û� �߳�?
	bool hasWarSchedule( GuildID_t guildID ) throw(Error);

	// ���� �������� ������ �ִ°�?
	bool hasActiveWar( GuildID_t guidlID ) throw(Error);

public: // debug
	string toString(void) const throw();


///// Member data /////
	
protected:
	map<GuildID_t, Guild*> m_Guilds;		// ���� ������ ��

	Timeval m_WaitMemberClearTime;				// heartbeat ���� Wait ���� �������� ��� �ð�

	// mutex
	mutable Mutex m_Mutex;
};

extern GuildManager* g_pGuildManager;

#endif // __GUILDINFO_H__
