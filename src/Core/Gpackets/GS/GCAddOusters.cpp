//////////////////////////////////////////////////////////////////////////////
// Filename    : GCAddOusters.cpp
// Written By  : Reiot
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "GCAddOusters.h"

//////////////////////////////////////////////////////////////////////////////
// class GCAddOusters member methods
//////////////////////////////////////////////////////////////////////////////

GCAddOusters::GCAddOusters()
{
	m_pEffectInfo = NULL;
	m_pPetInfo = NULL;
}

GCAddOusters::GCAddOusters(const PCOustersInfo3& info)
	: m_OustersInfo(info)
{
	m_pEffectInfo = NULL;
	m_pPetInfo = NULL;
}

GCAddOusters::~GCAddOusters()
	throw()
{
	__BEGIN_TRY
	
	SAFE_DELETE(m_pEffectInfo);

	__END_CATCH
}

void GCAddOusters::read ( SocketInputStream & iStream ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	m_OustersInfo.read( iStream );
	m_pEffectInfo = new EffectInfo();
	m_pEffectInfo->read( iStream );

	m_pPetInfo = new PetInfo();
	m_pPetInfo->read( iStream );
	if ( m_pPetInfo->getPetType() == PET_NONE ) SAFE_DELETE( m_pPetInfo );

	__END_CATCH
}
		    
void GCAddOusters::write ( SocketOutputStream & oStream ) const 
     throw ( ProtocolException , Error )
{
	__BEGIN_TRY

	PetInfo NullPetInfo;
		
	m_OustersInfo.write( oStream );
	m_pEffectInfo->write( oStream );

	if ( m_pPetInfo == NULL )
		NullPetInfo.write( oStream );
	else
	{
		m_pPetInfo->setSummonInfo(0);
		m_pPetInfo->write( oStream );
	}

	__END_CATCH
}

void GCAddOusters::execute ( Player * pPlayer ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCAddOustersHandler::execute( this , pPlayer );
		
	__END_CATCH
}

PacketSize_t GCAddOusters::getPacketSize() const 
	throw()
{   
	__BEGIN_TRY

	return m_OustersInfo.getSize() + m_pEffectInfo->getSize() + ((m_pPetInfo!=NULL)?m_pPetInfo->getSize():szPetType);

	__END_CATCH
}

string GCAddOusters::toString () const
       throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "GCAddOusters("
		<< "OustersInfo:" << m_OustersInfo.toString()
		<< "EffectInfo:" << m_pEffectInfo->toString()
		<< ")";
	return msg.toString();

	__END_CATCH
}
