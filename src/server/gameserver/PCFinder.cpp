//////////////////////////////////////////////////////////////////////////////
// Filename    : PCFinder.cpp
// Written By  : Reiot
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "PCFinder.h"
#include "Player.h"
//#include "GamePlayer.h"

//////////////////////////////////////////////////////////////////////////////
// class PCFinder member methods
//////////////////////////////////////////////////////////////////////////////

PCFinder::PCFinder()
	throw()
{
	__BEGIN_TRY

	m_Mutex.setName("PCFinder");

	__END_CATCH
}

PCFinder::~PCFinder()
	throw()
{
	__BEGIN_TRY

	m_PCs.clear();

	__END_CATCH
}

// add creature to map
// execute just once at PC's login
void PCFinder::addCreature (Creature* pCreature) 
	throw (DuplicatedException , Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	Assert(pCreature != NULL);

	const string& Name = pCreature->getName();
	const string& ID = pCreature->getPlayer()->getID();

	map< string , Creature* >::iterator itr = m_PCs.find(Name);
	map< string , Creature* >::iterator itr2 = m_IDs.find(ID); // for BillingServer. by sigi. 2002.11.18

	if (itr != m_PCs.end() 
		|| itr2 != m_IDs.end())
	{
		//m_Mutex.unlock();
		throw DuplicatedException();
	}

	m_PCs[ Name ]	= pCreature;
	m_IDs[ ID ] 	= pCreature; // for BillingServer. by sigi. 2002.11.18

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

// Delete creature from map
// execute just once at PC's logout
void PCFinder::deleteCreature (const string & name) 
	throw ()//NoSuchElementException , Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map< string , Creature* >::iterator itr = m_PCs.find(name);

	if (itr == m_PCs.end())
	{
		//cerr << "PCFinder::deleteCreature() : NoSuchElementException" << endl;
		//throw NoSuchElementException();
		// NoSuch���. by sigi. 2002.5.2

		m_Mutex.unlock();
		return;
	}


	// for BillingServer. by sigi. 2002.11.18
	Creature* pCreature = itr->second;
	Player* pPlayer = pCreature->getPlayer();
	Assert(pPlayer!=NULL);

	const string& ID = pPlayer->getID();

	map< string , Creature* >::iterator itr2 = m_IDs.find(ID);

	if (itr != m_IDs.end())
	{
		m_IDs.erase(itr2);
	}
	// �������� 2002.11.18


	m_PCs.erase(itr);

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

// get creature with PC-name
Creature* PCFinder::getCreature_LOCKED (const string & name) const 
	throw ()//NoSuchElementException , Error)
{
	__BEGIN_TRY

	map< string , Creature* >::const_iterator itr;

	//__ENTER_CRITICAL_SECTION(m_Mutex)

	itr = m_PCs.find(name);

	if (itr == m_PCs.end())
	{
		//cerr << "PCFinder::getCreature() : NoSuchElementException" << endl;
		//cerr << "PCFinder::getCreature() : NoSuchCreature" << endl;
		//m_Mutex.unlock();

		//throw NoSuchElementException();
		// NoSuch���. by sigi. 2002.5.2
		return NULL;
	}

	//__LEAVE_CRITICAL_SECTION(m_Mutex)

	return itr->second;


	__END_CATCH
}

// get creature with PlayerID
Creature* PCFinder::getCreatureByID_LOCKED (const string & ID) const 
	throw ()//NoSuchElementException , Error)
{
	__BEGIN_TRY

	map< string , Creature* >::const_iterator itr;

	//__ENTER_CRITICAL_SECTION(m_Mutex)

	itr = m_IDs.find(ID);

	if (itr == m_IDs.end())
	{
		//cerr << "PCFinder::getCreature() : NoSuchElementException" << endl;
		//cerr << "PCFinder::getCreature() : NoSuchCreature" << endl;
		//m_Mutex.unlock();

		//throw NoSuchElementException();
		// NoSuch���. by sigi. 2002.5.2
		return NULL;
	}

	//__LEAVE_CRITICAL_SECTION(m_Mutex)

	return itr->second;


	__END_CATCH
}



// get creature with PC-name
Creature* PCFinder::getCreature (const string & name) const 
	throw ()//NoSuchElementException , Error)
{
	__BEGIN_TRY

	map< string , Creature* >::const_iterator itr;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	itr = m_PCs.find(name);

	if (itr == m_PCs.end())
	{
		//cerr << "PCFinder::getCreature() : NoSuchElementException" << endl;
		//cerr << "PCFinder::getCreature() : NoSuchCreature" << endl;
		m_Mutex.unlock();

		//throw NoSuchElementException();
		// NoSuch���. by sigi. 2002.5.2
		return NULL;
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return itr->second;


	__END_CATCH
}

// get creature with PlayerID
Creature* PCFinder::getCreatureByID (const string & ID) const 
	throw ()//NoSuchElementException , Error)
{
	__BEGIN_TRY

	map< string , Creature* >::const_iterator itr;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	itr = m_IDs.find(ID);

	if (itr == m_IDs.end())
	{
		//cerr << "PCFinder::getCreature() : NoSuchElementException" << endl;
		//cerr << "PCFinder::getCreature() : NoSuchCreature" << endl;
		m_Mutex.unlock();

		//throw NoSuchElementException();
		// NoSuch���. by sigi. 2002.5.2
		return NULL;
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return itr->second;


	__END_CATCH
}

// get creature's IP address 
IP_t PCFinder::getIP (const string & name) const 
	throw (NoSuchElementException , Error)
{
	__BEGIN_TRY

	IP_t IP = 0;

	map< string , Creature* >::const_iterator itr;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	itr = m_PCs.find(name);

	if (itr == m_PCs.end())
	{
		cerr << "PCFinder::getCreature() : NoSuchElementException" << endl;
		//m_Mutex.unlock();
		throw NoSuchElementException();
	}

	Creature* pCreature = itr->second;
	Assert( pCreature->isPC() );

	Player* pPlayer = pCreature->getPlayer();
	Assert( pPlayer != NULL );

	Socket* pSocket = pPlayer->getSocket();
	Assert( pSocket != NULL );

	IP = pSocket->getHostIP();

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return IP;

	__END_CATCH
}

/*
// get creature with PC-name
bool PCFinder::sendPacket (const string& name, Packet* pPacket) const
	throw ()//NoSuchElementException , Error)
{
	__BEGIN_TRY

	map< string , Creature* >::const_iterator itr;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	itr = m_PCs.find(name);

	if (itr == m_PCs.end())
	{
		m_Mutex.unlock();

		return false;
	}

	// sendPacket
	try {
		Creature* pCreature = itr->second;
		Player* pPlayer = pCreature->getPlayer();
		pPlayer->sendPacket( pPacket );
	} catch (Throwable& ) {
		// �׳� �����Ѵ�.
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH

	return true;
}

// kick
bool PCFinder::setKickCharacter (const string & name, const string& host, uint port) const 
	throw ()//NoSuchElementException , Error)
{
	__BEGIN_TRY

	map< string , Creature* >::const_iterator itr;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	itr = m_PCs.find(name);

	if (itr == m_PCs.end())
	{
		//cerr << "PCFinder::getCreature() : NoSuchElementException" << endl;
		//cerr << "PCFinder::getCreature() : NoSuchCreature" << endl;
		m_Mutex.unlock();

		//throw NoSuchElementException();
		// NoSuch���. by sigi. 2002.5.2
		return false;
	}

	Creature* pCreature = itr->second;
	Player* pPlayer = pCreature->getPlayer();
	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>( pPlayer );
	Assert(pGamePlayer!=NULL);

	// ��� ��� ��Ų��.
	pGamePlayer->setPenaltyFlag(PENALTY_TYPE_KICKED);
	pGamePlayer->setKickForLogin(true);

	// ��� ��� ��, ���� ������ ��..
	pGamePlayer->setKickRequestHost( host );
	pGamePlayer->setKickRequestPort( port );


	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH

	return true;
}
*/

void PCFinder::addNPC(NPC *pNPC) throw(DuplicatedException, Error)
{
    __BEGIN_TRY

    __ENTER_CRITICAL_SECTION(m_Mutex)

    Assert(pNPC != NULL);

    const string& Name = pNPC->getName();

    map< string , NPC* >::iterator itr = m_NPCs.find(Name);

    if (itr != m_NPCs.end())
    {
		return;
        //throw DuplicatedException();
    }

    m_NPCs[ Name ] = pNPC;

    __LEAVE_CRITICAL_SECTION(m_Mutex)

    __END_CATCH
}


void PCFinder::deleteNPC (const string & name)
    throw ()
{

    // ����� ���� �� �� �Լ����� ������ �׷��� �׳� add �� ��� ���߱� ��� =_=
    __BEGIN_TRY

    __ENTER_CRITICAL_SECTION(m_Mutex)

    map< string , NPC* >::iterator itr = m_NPCs.find(name);

    if (itr == m_NPCs.end())
    {
        return;
    }

    m_NPCs.erase(itr);

    __LEAVE_CRITICAL_SECTION(m_Mutex)

    __END_CATCH
}


NPC* PCFinder::getNPC (const string & name) const
    throw ()
{
    __BEGIN_TRY

    map< string , NPC* >::const_iterator itr;

    __ENTER_CRITICAL_SECTION(m_Mutex)

    itr = m_NPCs.find(name);

    if (itr == m_NPCs.end())
    {
        m_Mutex.unlock();
        return NULL;
    }

    __LEAVE_CRITICAL_SECTION(m_Mutex)

    return itr->second;


    __END_CATCH
}


NPC* PCFinder::getNPC_LOCKED (const string & name) const
    throw ()
{
    __BEGIN_TRY

    map< string , NPC* >::const_iterator itr;

    itr = m_NPCs.find(name);

    if (itr == m_NPCs.end())
    {
        return NULL;
    }

    return itr->second;

    __END_CATCH
}

// global variable definition
PCFinder* g_pPCFinder = NULL;
