//----------------------------------------------------------------------
// 
// Filename    : GTOAcknowledgement.h 
// Written By  : Reiot
// Description : 
// 
//----------------------------------------------------------------------

#ifndef __GTO_ACKNOWLEDGEMENT_H__
#define __GTO_ACKNOWLEDGEMENT_H__

// include files
#include "DatagramPacket.h"
#include "PacketFactory.h"

#include <string>

const string Message = "One Server to rule them all, One Server to find them all, One Server to bring them all, and in the network bind them.";

//----------------------------------------------------------------------
//
// class GTOAcknowledgement;
//
// �α��� �������� ����ڰ� ���� ������ �����Ϸ��� �� ��, �α��� ������
// �� ���� �������� � �ּҿ��� � ����ڰ� � ũ��ó�� �α�����
// ���̴�.. ��� �˷��ִ� ��Ŷ�̴�.
//
// *CAUTION*
//
// ���� ũ��ó �̸��� �ʿ��Ѱ�? �ϴ� �ǹ��� ���� �� �ְڴµ�, ������ ����
// ��츦 ���������� �ʿ��ϰ� �ȴ�. �α��� �����κ��� Slot3 ĳ���͸� ����
// �س���, ������ ���� ������ �����ؼ��� SLOT2 ĳ���͸� �ε��ش޶�� ��
// ���� �ִ� ���̴�. �̸� ���� ���ؼ�, CLSelectPC�� ������ ĳ���͸� 
// ���� �������� �˷���� �ϸ�, CGConnect ������ ĳ���� ���̵� �����ؼ�
// �ٷ� �ε��ϵ��� �ؾ� �Ѵ�.
//
//----------------------------------------------------------------------

class GTOAcknowledgement : public DatagramPacket {

public:
	GTOAcknowledgement() { m_Message = Message; }
	
    // Datagram ��ü�������� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(Datagram & iDatagram) throw(ProtocolException, Error);
		    
    // Datagram ��ü�� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(Datagram & oDatagram) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_GTO_ACKNOWLEDGEMENT; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw() 
	{ 
		return szBYTE + szBYTE + m_Message.size() + szBYTE + m_ServerIP.size();
	}

	// get packet name
	string getPacketName() const throw() { return "GTOAcknowledgement"; }
	
	// get packet's debug string
	string toString() const throw();

public:

	string getServerIP() const throw() { return m_ServerIP; }
	void setServerIP(const string& ServerIP) throw() { m_ServerIP = ServerIP; }
	
	string getMessage() const { return m_Message; }

	BYTE getServerType() const throw() { return m_ServerType; }
	void setServerType(BYTE ServerType) throw() { m_ServerType = ServerType; }
		
private :

	BYTE m_ServerType;
	string m_Message;
	string m_ServerIP;
};


//////////////////////////////////////////////////////////////////////
//
// class GTOAcknowledgementFactory;
//
// Factory for GTOAcknowledgement
//
//////////////////////////////////////////////////////////////////////

class GTOAcknowledgementFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket() throw() { return new GTOAcknowledgement(); }

	// get packet name
	string getPacketName() const throw() { return "GTOAcknowledgement"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GTO_ACKNOWLEDGEMENT; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static GTOAcknowledgementPacketMaxSize �� ����, �����϶�.
	PacketSize_t getPacketMaxSize() const throw() 
	{ 
		return szBYTE
			+ szBYTE + 1024
			+ szBYTE + 15; 		// client ip
	}

};


//////////////////////////////////////////////////////////////////////
//
// class GTOAcknowledgementHandler;
//
//////////////////////////////////////////////////////////////////////

class GTOAcknowledgementHandler {
	
public:

	// execute packet's handler
	static void execute(GTOAcknowledgement* pPacket) throw(ProtocolException, Error);

};

#endif