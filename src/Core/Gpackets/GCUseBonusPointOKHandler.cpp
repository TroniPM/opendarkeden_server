//////////////////////////////////////////////////////////////////////
//
// Filename    : GCUseBonusPointOKHandler.cc
// Written By  : crazydog
// Description :
//
//////////////////////////////////////////////////////////////////////

// include files
#include "GCUseBonusPointOK.h"

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void GCUseBonusPointOKHandler::execute ( GCUseBonusPointOK * pGCUseBonusPointOK , Player * pPlayer )
	 throw ( ProtocolException, Error )
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
		
#if __TEST_CLIENT__

	//cout << pGCUseBonusPointOK->toString() << endl;
	
#elif __WINDOWS__

#endif

	__END_DEBUG_EX __END_CATCH
}