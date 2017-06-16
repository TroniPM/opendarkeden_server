//////////////////////////////////////////////////////////////////////////////
// Filename    : MasterLairManager.h 
// Written by  : ��
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __MASTER_LAIR_MANAGER_H__
#define __MASTER_LAIR_MANAGER_H__

#include "MonsterCounter.h"
#include "Item.h"
#include "Timeval.h"
#include "Mutex.h"
#include <map>
#include <vector>

//////////////////////////////////////////////////////////////////////////////
// class MasterLairManager
//////////////////////////////////////////////////////////////////////////////

class Zone;

class MasterLairManager
{
public : 
	enum MasterLairEvent 
	{ 
		EVENT_WAITING_PLAYER,     // �������� ������� ���ٸ���. 
		EVENT_MINION_COMBAT,      // ��ȯ�� �����Ϳ� �ο���. 
		EVENT_MASTER_COMBAT,      // �����Ϳ� �ο���. 
		EVENT_WAITING_KICK_OUT,    // ������ ����߹� ����(������ ��� ������ ��� �ð�) 
		EVENT_WAITING_REGEN,      // �ٽ� ����Ǳ� ���ٸ���. 

		EVENT_MAX
	}; 


public:
	MasterLairManager(Zone* pZone) throw(Error);
	~MasterLairManager() throw();

	MasterLairEvent getCurrentEvent() const { return m_Event; }

	bool enterCreature(Creature* pCreature) throw(Error);  // ��� ������ �����Ѱ�? 
	bool leaveCreature(Creature* pCreature) throw(Error);  // ����� ���� ����

	bool heartbeat() throw (Error);

	//void increaseSummonedMonsterNumber(int num) throw(Error);
	bool isMasterReady() const { return m_bMasterReady; }
	void setMasterReady(bool bReady=true) { m_bMasterReady = bReady; }

	void startEvent() throw (Error);
	void stopEvent() throw (Error);

	void lock() throw(Error) { m_Mutex.lock(); }
    void ulnock() throw(Error) { m_Mutex.unlock(); }

	string toString() const throw(Error);

protected :
	void processEventWaitingPlayer() throw (Error);
	void processEventMinionCombat() throw (Error);
	void processEventMasterCombat() throw (Error);
	void processEventWaitingKickOut() throw (Error);
	void processEventWaitingRegen() throw (Error);

	void activeEventWaitingPlayer() throw (Error);
	void activeEventMinionCombat() throw (Error);
	void activeEventMasterCombat() throw (Error);
	void activeEventWaitingKickOut() throw (Error);
	void activeEventWaitingRegen() throw (Error);

	void deleteAllMonsters() throw (Error);		// ���� ������ ���
	void kickOutPlayers() throw (Error);		// ������ ��� �߹�
	void giveKillingReward() throw (Error);		// ������ �׿�� �� �޴� ����
	void killAllMonsters() throw (Error);		// ���� �����͸� ���δ�

private : 
	Zone*             m_pZone;  
	ObjectID_t        m_MasterID;           // ������ �� ���� 
	ZoneCoord_t       m_MasterX;
	ZoneCoord_t       m_MasterY;

	bool              m_bMasterReady;      // �����Ͱ� �ο� �غ��� �Ǿ���? 

	//int               m_nMaxSummonMonster; // �����Ͱ� ��ȯ�� �ִ��� ������ �� 
	//int               m_nSummonedMonster;  // �����Ͱ� ��ȯ�� ������ �� 

	int               m_nMaxPassPlayer;	   // �ִ� ���� ������ ��
	int               m_nPassPlayer;       // Pass�� ��� ���� �� 

	MasterLairEvent   m_Event;             // ������ �̺�Ʈ ��� 
	Timeval           m_EventTime;         // ������ �̺�Ʈ�� ���ӵ� �ð�
	int               m_EventValue;		   // �̺�Ʈ�� ���õ� ��

	Timeval           m_RegenTime;         // �� ����ϰ� �ٽ� �����ϴ� �ð� 


	mutable Mutex     m_Mutex;				// m_nPassPlayer�� Ȯ���� üũ�ҷ��..
};

#endif
