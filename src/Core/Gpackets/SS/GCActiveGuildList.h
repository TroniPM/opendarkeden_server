//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCActiveGuildList.h 
// Written By  : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_ACTIVE_GUILD_LIST_H__
#define __GC_ACTIVE_GUILD_LIST_H__

// include files
#include <list>
#include "Packet.h"
#include "PacketFactory.h"
#include "GuildInfo.h"

typedef list<GuildInfo*> GuildInfoList;
typedef list<GuildInfo*>::const_iterator GuildInfoListConstItor;


//////////////////////////////////////////////////////////////////////
//
// class GCActiveGuildList;
//
// Ŭ���̾�Ʈ�� ���� �������� ���� ����Ʈ�� ������.
//
//////////////////////////////////////////////////////////////////////

class GCActiveGuildList : public Packet {

public :

	// constructor
	GCActiveGuildList() throw();

	// destructor
	~GCActiveGuildList() throw();
	
    // �Է½�Ʈ��(����)��κ��� ����Ÿ�� �о ��Ŷ� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ���½�Ʈ��(����)��� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_GC_ACTIVE_GUILD_LIST; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw();

	// get packet name
	string getPacketName() const throw() { return "GCActiveGuildList"; }
	
	// get packet's debug string
	string toString() const throw();

public:

	BYTE getListNum() const throw() { return m_GuildInfoList.size(); }

	// add GuildInfo
	void addGuildInfo( GuildInfo* pGuildInfo ) throw() { m_GuildInfoList.push_front( pGuildInfo ); }

	// clear GuildInfoList
	void clearGuildInfoList() throw();

	// pop front Element in GuildInfoList
	GuildInfo* popFrontGuildInfoList() throw()
	{
		if ( !m_GuildInfoList.empty() )
		{
			GuildInfo* pGuildInfo = m_GuildInfoList.front();
			m_GuildInfoList.pop_front();
			return pGuildInfo;
		}
		return NULL;
	}


private :
	
	GuildInfoList m_GuildInfoList;	
};


//////////////////////////////////////////////////////////////////////
//
// class GCActiveGuildListFactory;
//
// Factory for GCActiveGuildList
//
//////////////////////////////////////////////////////////////////////

class GCActiveGuildListFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket() throw() { return new GCActiveGuildList(); }

	// get packet name
	string getPacketName() const throw() { return "GCActiveGuildList"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GC_ACTIVE_GUILD_LIST; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static GCSystemMessagePacketMaxSize �� ���, �����϶�.
	PacketSize_t getPacketMaxSize() const throw() { return GuildInfo::getMaxSize(); }

};


//////////////////////////////////////////////////////////////////////
//
// class GCActiveGuildList;
//
//////////////////////////////////////////////////////////////////////

class GCActiveGuildListHandler {
	
public :
	
	// execute packet's handler
	static void execute(GCActiveGuildList* pPacket, Player* pPlayer) throw(ProtocolException, Error);

};

#endif
