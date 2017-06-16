//////////////////////////////////////////////////////////////////////////////
// Filename    : PCFinder.h
// Written By  : Reiot
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __PC_FINDER_H__
#define __PC_FINDER_H__

#include "Types.h"
#include "Exception.h"
#include "Creature.h"
#include "NPC.h"
#include "Mutex.h"
#include <map>

//////////////////////////////////////////////////////////////////////////////
// class PCFinder;
// ���� ������ �۷ι� �Ŵ��� ��ü��, PC �̸�� �����ؼ� PC��ü�� ����� �� �ֵ���
// ���ش�. ��������� map � �����ؼ�, �˻� �ӵ��� ������Ų��.
//////////////////////////////////////////////////////////////////////////////

class PCFinder 
{
public:
	PCFinder() throw();
	~PCFinder() throw();

public:
	// add creature to map
	// execute just once at PC's login
	void addCreature(Creature* pCreature) throw(DuplicatedException, Error);

	// delete creature from map
	// execute just once at PC's logout
	void deleteCreature(const string & name) throw();//NoSuchElementException, Error);

	// get creature with PC-name
	Creature* getCreature(const string & name) const throw(); //NoSuchElementException, Error);

	// get creature with PC-name
	Creature* getCreature_LOCKED(const string & name) const throw(); //NoSuchElementException, Error);

	// PlayerID. for BillingServer. by sigi. 2002.11.18
	Creature* getCreatureByID(const string & ID) const throw(); //NoSuchElementException, Error);
	Creature* getCreatureByID_LOCKED(const string & ID) const throw(); //NoSuchElementException, Error);

	// add NPC to map
	void addNPC(NPC *npc) throw(DuplicatedException, Error);
	
	// delete NPC from map
	void deleteNPC(const string & name) throw();

	// get NPC 
	NPC* getNPC(const string & name) const throw();
	NPC* getNPC_LOCKED(const string & name) const throw();

	// get creature's IP address
	IP_t getIP(const string & name) const throw(NoSuchElementException, Error);

	void lock() throw(Error) { m_Mutex.lock(); }
	void unlock() throw(Error) { m_Mutex.unlock(); }


private:
	map< string, Creature* > 	m_PCs;
	map< string, Creature* > 	m_IDs;	// PlayerID. for BillingServer. by sigi. 2002.11.18
	map< string, NPC* > 		m_NPCs;	// NPCs.. for NPC trace ;; by DEW  2003. 04. 16
	mutable Mutex m_Mutex;
};

// global variable declaration
extern PCFinder* g_pPCFinder;

#endif
