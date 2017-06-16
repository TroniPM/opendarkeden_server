//////////////////////////////////////////////////////////////////////////////
// Filename    : GCAddSlayer.cpp
// Written By  : Reiot
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "GCAddSlayer.h"

//////////////////////////////////////////////////////////////////////////////
// class GCAddSlayer member methods
//////////////////////////////////////////////////////////////////////////////

GCAddSlayer::GCAddSlayer()
{
	m_pEffectInfo = NULL;
	m_pPetInfo = NULL;
}

GCAddSlayer::GCAddSlayer(const PCSlayerInfo3& info)
	: m_SlayerInfo(info)
{
	m_pEffectInfo = NULL;
	m_pPetInfo = NULL;
}

GCAddSlayer::~GCAddSlayer()
	throw()
{
	__BEGIN_TRY
	
	SAFE_DELETE(m_pEffectInfo);

	__END_CATCH
}

void GCAddSlayer::read ( SocketInputStream & iStream ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	m_SlayerInfo.read( iStream );
	m_pEffectInfo = new EffectInfo();
	m_pEffectInfo->read( iStream );

	m_pPetInfo = new PetInfo();
	m_pPetInfo->read( iStream );

	if ( m_pPetInfo->getPetType() == PET_NONE ) SAFE_DELETE( m_pPetInfo );

	__END_CATCH
}
		    
void GCAddSlayer::write ( SocketOutputStream & oStream ) const 
     throw ( ProtocolException , Error )
{
	__BEGIN_TRY

	static PetInfo NullPetInfo;
		
	m_SlayerInfo.write( oStream );
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

void GCAddSlayer::execute ( Player * pPlayer ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCAddSlayerHandler::execute( this , pPlayer );
		
	__END_CATCH
}

PacketSize_t GCAddSlayer::getPacketSize() const 
	throw()
{   
	__BEGIN_TRY

	return m_SlayerInfo.getSize() + m_pEffectInfo->getSize() + ((m_pPetInfo!=NULL)?m_pPetInfo->getSize():szPetType);

	__END_CATCH
}

string GCAddSlayer::toString () const
       throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "GCAddSlayer("
		<< "SlayerInfo:" << m_SlayerInfo.toString()
		<< "EffectInfo:" << m_pEffectInfo->toString()
		<< "PetInfo:" << ((m_pPetInfo)?m_pPetInfo->toString():"NULL")
		<< ")";
	return msg.toString();

	__END_CATCH
}
