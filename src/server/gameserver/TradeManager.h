////////////////////////////////////////////////////////////////////////////////
// Filename    : TradeManager.h
// Written by  : �輺��
// Description : 
////////////////////////////////////////////////////////////////////////////////

#ifndef __TRADE_MANAGER__
#define __TRADE_MANAGER__

#include "Types.h"
#include "Exception.h"
#include "Timeval.h"
#include <list>
#include <map>

////////////////////////////////////////////////////////////////////////////////
// ��ȯ ���� �÷���
////////////////////////////////////////////////////////////////////////////////

enum
{
	// ������� �ű��� �ִ� ����
	TRADE_TRADING,

	// ������� �� �ű���, ��ȯ� ���ٸ��� �ִ� ����
	TRADE_FINISH,

	TRADE_MAX
};

////////////////////////////////////////////////////////////////////////////////
// class TradeInfo
////////////////////////////////////////////////////////////////////////////////

class Item;

class TradeInfo
{
///// Member methods /////
public:
	TradeInfo() throw();
	~TradeInfo() throw();

public:
	const string getMainName(void) const throw() { return m_MainName; }
	void setMainName(const string & Name) throw() { m_MainName = Name; }

	const string getTargetName(void) const throw() { return m_TargetName; }
	void setTargetName(const string & Name) throw() { m_TargetName = Name; }

	list<Item*> getItemList(void) throw() { return m_ItemList; }
	void setItemList(list<Item*> itemList) throw() { m_ItemList = itemList; }

	Gold_t getGold(void) const throw() { return m_Gold; }
	void setGold(Gold_t gold) { m_Gold = gold; }

	int getStatus(void) const throw() { return m_Status; }
	void setStatus(int status) throw() { m_Status = status; }

	bool hasItem(Item* pItem) throw();
	bool addItem(Item* pItem) throw();
	bool removeItem(Item* pItem) throw();

	void clearAll(void) throw();

	Timeval getLastOKTime(void) const { return m_LastOKTime; }
	void setLastOKTime(const Timeval& lastOKTime) { m_LastOKTime = lastOKTime; }
	void setNextTime(const Timeval& currentTime);
	bool isValidOKTime(const Timeval& currentTime);

protected:
	string 		m_MainName;
	string 		m_TargetName;
	list<Item*> m_ItemList;
	Gold_t      m_Gold;
	int         m_Status;
	Timeval     m_LastOKTime;
};


////////////////////////////////////////////////////////////////////////////////
// class TradeManager
////////////////////////////////////////////////////////////////////////////////

class Creature;

class TradeManager
{
///// Member methods /////
public:
	TradeManager() throw();
	~TradeManager() throw();

public:
	void init() throw();

	bool hasTradeInfo(const string & Name) throw();

	TradeInfo* getTradeInfo(const string & Name) throw();

	void addTradeInfo(TradeInfo* pInfo) throw(DuplicatedException);

	void removeTradeInfo(const string & Name) throw(NoSuchElementException);

public:

	void initTrade(Creature* pCreature1, Creature* pCreature2) throw();
	// Ʈ���̵� �� �� ����� 0, ���� ���� ��� ������ ���ϸ� 2, �� �� ����� 1
	int canTrade(Creature* pCreature1, Creature* pCreature2) throw();
	void processTrade(Creature* pCreature1, Creature* pCreature2) throw();
	void cancelTrade(Creature* pCreature1, Creature* pCreature2) throw();
	void cancelTrade(Creature* pCreature1) throw();
	bool isTrading(Creature* pCreature1, Creature* pCreature2) throw();

///// Member data /////
protected:
	map<string, TradeInfo*> m_InfoMap;
};

#endif

