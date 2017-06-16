//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCGuildChat.h 
// Written By  : elca
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_GUILD_CHAT_H__
#define __GC_GUILD_CHAT_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"


//////////////////////////////////////////////////////////////////////
//
// class GCGuildChat;
//
//////////////////////////////////////////////////////////////////////

class GCGuildChat : public Packet {

public :
	
    // 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_GC_GUILD_CHAT; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw()
	{
		return szBYTE +					// sender size
			   m_Sender.size() +		// sender
			   szuint +					// text color
			   szBYTE +					// message size
			   m_Message.size();		// message
	}

	// get packet name
	string getPacketName() const throw() { return "GCGuildChat"; }
	
	// get packet's debug string
	string toString() const throw();

	// get/set sender
	string getSender() const throw() { return m_Sender; }
	void setSender( const string& sender ) throw() { m_Sender = sender; }

	// get/set text color
	uint getColor() const throw() { return m_Color; }
	void setColor( uint color ) throw() { m_Color = color; }

	// get/set chatting message
	string getMessage() const throw() { return m_Message; }
	void setMessage(const string & msg) throw() { m_Message = msg; }
	
private :

	// sender
	string m_Sender;

	// text color
	uint m_Color;
	
	// chatting message
	string m_Message;

};


//////////////////////////////////////////////////////////////////////
//
// class GCGuildChatFactory;
//
// Factory for GCGuildChat
//
//////////////////////////////////////////////////////////////////////

class GCGuildChatFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket() throw() { return new GCGuildChat(); }

	// get packet name
	string getPacketName() const throw() { return "GCGuildChat"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GC_GUILD_CHAT; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static GCGuildChatPacketMaxSize 를 정의, 리턴하라.
	PacketSize_t getPacketMaxSize() const throw()
	{
		return szBYTE +				// sender size
			   10 +					// sender max size
			   szuint +				// text color size
			   szBYTE +				// message size
			   128;					// message
	}

};


//////////////////////////////////////////////////////////////////////
//
// class GCGuildChatHandler;
//
//////////////////////////////////////////////////////////////////////

class GCGuildChatHandler {
	
public :
	
	// execute packet's handler
	static void execute(GCGuildChat* pPacket, Player* pPlayer) throw(ProtocolException, Error);

};

#endif
