//----------------------------------------------------------------------
//
// Filename    : ReconnectLoginInfoManager.h
// Written By  : Reiot
// Description :
//
//----------------------------------------------------------------------

#ifndef __CONNECTION_INFO_MANAGER_H__
#define __CONNECTION_INFO_MANAGER_H__

// include files
#include "Types.h"
#include "Exception.h"
#include <map>
#include "ReconnectLoginInfo.h"

typedef map< string , ReconnectLoginInfo * > HashMapReconnectLoginInfo;

//----------------------------------------------------------------------
//
// class ReconnectLoginInfoManager;
//
// IP ��Ʈ��� Ű����� �ϴ� map � ���ο� ������ �ִ�.
//
//----------------------------------------------------------------------

class ReconnectLoginInfoManager {
	
public :
	
	// constructor
	ReconnectLoginInfoManager () throw ();
	
	// destructor
	~ReconnectLoginInfoManager () throw ();
	

public :
	
	// add connection info to connection info manager
	void addReconnectLoginInfo ( ReconnectLoginInfo * pReconnectLoginInfo ) throw ( DuplicatedException , Error );
	
	// delete connection info from connection info manager
	void deleteReconnectLoginInfo ( string ip ) throw ( NoSuchElementException , Error );
	
	// get connection info from connection info manager
	ReconnectLoginInfo * getReconnectLoginInfo ( string ip ) throw ( NoSuchElementException , Error );

	// heartbeat method
	// expire �� ReconnectLoginInfo �� ����Ѵ�.
	void heartbeat () throw ( Error );	

	// get debug string
	string toString () const throw ();


private :
	
	// hash map of ReconnectLoginInfo
	// key is ip-string
	HashMapReconnectLoginInfo m_ReconnectLoginInfos;

	Timeval m_NextHeartbeat;
};

// global variable declaration
extern ReconnectLoginInfoManager * g_pReconnectLoginInfoManager;

#endif
