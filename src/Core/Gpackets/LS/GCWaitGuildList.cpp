//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCWaitGuildList.cpp 
// Written By  : 
// 
//////////////////////////////////////////////////////////////////////

// include files
#include "GCWaitGuildList.h"


//////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////
GCWaitGuildList::GCWaitGuildList()
	throw()
{
}

//////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////
GCWaitGuildList::~GCWaitGuildList()
	throw()
{
	__BEGIN_TRY
	
	// ���� ����Ʈ�� ���� ��ü�� ���
	clearGuildInfoList();

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
// �Է½�Ʈ��(����)��κ��� ����Ÿ�� �о ��Ŷ� �ʱ�ȭ�Ѵ�.
//////////////////////////////////////////////////////////////////////
void GCWaitGuildList::read ( SocketInputStream & iStream ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	BYTE ListNum;

	iStream.read( ListNum );
	for ( int i = 0; i < ListNum; i++ )
	{
		GuildInfo* pGuildInfo = new GuildInfo();
		pGuildInfo->read( iStream );
		m_GuildInfoList.push_front( pGuildInfo );
	}

	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// ���½�Ʈ��(����)��� ��Ŷ�� ���̳ʸ� �̹����� ������.
//////////////////////////////////////////////////////////////////////
void GCWaitGuildList::write ( SocketOutputStream & oStream ) const 
     throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	BYTE ListNum = m_GuildInfoList.size();
	oStream.write( ListNum );

	GuildInfoListConstItor itr = m_GuildInfoList.begin();
	for ( ; itr != m_GuildInfoList.end(); itr++ )
	{
		(*itr)->write( oStream );
	}

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// execute packet's handler
//////////////////////////////////////////////////////////////////////
void GCWaitGuildList::clearGuildInfoList()
	throw()
{
	__BEGIN_TRY

	// GuildInfoList �� ����Ѵ�
	while( !m_GuildInfoList.empty() )
	{
		GuildInfo* pGuildInfo = m_GuildInfoList.front();
		m_GuildInfoList.pop_front();
		SAFE_DELETE( pGuildInfo );
	}

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// execute packet's handler
//////////////////////////////////////////////////////////////////////
void GCWaitGuildList::execute ( Player * pPlayer ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCWaitGuildListHandler::execute( this , pPlayer );

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// get packet size
//////////////////////////////////////////////////////////////////////
PacketSize_t GCWaitGuildList::getPacketSize() const
	throw()
{
	__BEGIN_TRY

	PacketSize_t PacketSize = szBYTE;

	GuildInfoListConstItor itr = m_GuildInfoList.begin();

	for ( ; itr != m_GuildInfoList.end(); itr++ )
	{
		PacketSize += (*itr)->getSize();
	}

	return PacketSize;

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// get packet's debug string
//////////////////////////////////////////////////////////////////////
string GCWaitGuildList::toString () const
       throw ()
{
	__BEGIN_TRY
		
	StringStream msg;
	
	msg << "GCWaitGuildList(";

	list<GuildInfo*>::const_iterator itr = m_GuildInfoList.begin();
	for ( ; itr != m_GuildInfoList.end(); itr++ )
	{
		msg << (*itr)->toString();
	}

	msg << ")";
	
	return msg.toString();
		
	__END_CATCH
}

