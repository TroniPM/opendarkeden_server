//----------------------------------------------------------------------
//
// Filename    : GTOAcknowledgementHandler.cpp
// Written By  : Reiot
// Description :
//
//----------------------------------------------------------------------

// include files
#include "GTOAcknowledgement.h"
#include "Properties.h"

#ifdef __THE_ONE_SERVER__

#include "DB.h"

#endif

//----------------------------------------------------------------------
// 
// GTOAcknowledgementHander::execute()
// 
//----------------------------------------------------------------------
void GTOAcknowledgementHandler::execute ( GTOAcknowledgement * pPacket )
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY __BEGIN_DEBUG_EX

#ifdef __THE_ONE_SERVER__

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery( "INSERT IGNORE INTO TheOneServerRules VALUES ('%s',%d,'%s',%d,'%s',now())",
				pPacket->getServerIP().c_str(), pPacket->getServerType(),
				pPacket->getHost().c_str(), pPacket->getPort(),
				pPacket->getMessage().c_str());

		pStmt->executeQuery( "UPDATE TheOneServerRules SET ServerType=%d, ActualIP='%s', ActualPort=%d, LastMsg='%s', LastAckTime=now() WHERE ServerIP='%s'",
				pPacket->getServerType(), pPacket->getHost().c_str(), pPacket->getPort(), pPacket->getMessage().c_str(), pPacket->getServerIP().c_str() );
				
		SAFE_DELETE( pStmt );
	}
	END_DB( pStmt )

	filelog( "TheOneServer.log", "패킷이 도착했습니다. : [%s:%05d] %s", pPacket->getHost().c_str(), pPacket->getPort(), pPacket->toString().c_str() );
	cout << "패킷이 도착했습니다. : [" << pPacket->getHost() << ":" << pPacket->getPort() <<"] : " << pPacket->toString() << endl;

#endif

	__END_DEBUG_EX __END_CATCH
}
