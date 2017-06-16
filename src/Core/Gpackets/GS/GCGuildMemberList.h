//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCGuildMemberList.h 
// Written By  : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_GUILD_MEMBER_LIST_H__
#define __GC_GUILD_MEMBER_LIST_H__

// include files
#include <list>
#include "Packet.h"
#include "PacketFactory.h"
#include "GuildMemberInfo.h"

typedef list<GuildMemberInfo*> GuildMemberInfoList;
typedef list<GuildMemberInfo*>::const_iterator GuildMemberInfoListConstItor;


//////////////////////////////////////////////////////////////////////
//
// class GCGuildMemberList;
//
// Ŭ���̾�Ʈ�� ���� �������� ���� ����Ʈ�� ������.
//
//////////////////////////////////////////////////////////////////////

class GCGuildMemberList : public Packet {

public :

	// constructor
	GCGuildMemberList() throw();

	// destructor
	~GCGuildMemberList() throw();
	
    // �Է½�Ʈ��(����)��κ��� ����Ÿ�� �о ��Ŷ� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ���½�Ʈ��(����)��� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_GC_GUILD_MEMBER_LIST; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw();

	// get packet name
	string getPacketName() const throw() { return "GCGuildMemberList"; }
	
	// get packet's debug string
	string toString() const throw();

public:

	BYTE getListNum() const throw() { return m_GuildMemberInfoList.size(); }

	// add GuildMemberInfoList
	void addGuildMemberInfo( GuildMemberInfo* pGuildMemberInfo ) throw() { m_GuildMemberInfoList.push_front( pGuildMemberInfo ); }

	// clear GuildMemberInfoList
	void clearGuildMemberInfoList() throw();

	// pop front Element in GuildMemberInfoList
	GuildMemberInfo* popFrontGuildMemberInfoList() throw()
	{
		if ( !m_GuildMemberInfoList.empty() )
		{
			GuildMemberInfo* pGuildMemberInfo = m_GuildMemberInfoList.front();
			m_GuildMemberInfoList.pop_front();
			return pGuildMemberInfo;
		}
		return NULL;
	}


private :
	
	GuildMemberInfoList m_GuildMemberInfoList;	
};


//////////////////////////////////////////////////////////////////////
//
// class GCGuildMemberListFactory;
//
// Factory for GCGuildMemberList
//
//////////////////////////////////////////////////////////////////////

class GCGuildMemberListFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket() throw() { return new GCGuildMemberList(); }

	// get packet name
	string getPacketName() const throw() { return "GCGuildMemberList"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GC_GUILD_MEMBER_LIST; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static GCSystemMessagePacketMaxSize �� ���, �����϶�.
	PacketSize_t getPacketMaxSize() const throw() { return GuildMemberInfo::getMaxSize(); }

};


//////////////////////////////////////////////////////////////////////
//
// class GCGuildMemberList;
//
//////////////////////////////////////////////////////////////////////

class GCGuildMemberListHandler {
	
public :
	
	// execute packet's handler
	static void execute(GCGuildMemberList* pPacket, Player* pPlayer) throw(ProtocolException, Error);

};

#endif
