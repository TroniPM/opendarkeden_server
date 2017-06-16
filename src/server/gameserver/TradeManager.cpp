////////////////////////////////////////////////////////////////////////////////
// Filename    : TradeManager.cpp
// Written by  : �輺��
// Description :  
////////////////////////////////////////////////////////////////////////////////

#include "TradeManager.h"
#include "Creature.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "Item.h"
#include "ItemUtil.h"
#include "Inventory.h"
#include "Player.h"
#include "ItemMap.h"
#include "DB.h"
#include "LogClient.h"
#include "VSDateTime.h"
#include "FlagSet.h"
#include "EventItemUtil.h"
#include "GamePlayer.h"

#include "VariableManager.h"

#include "Gpackets/GCTradeFinish.h"

////////////////////////////////////////////////////////////////////////////////
// class TradeInfo member methods
////////////////////////////////////////////////////////////////////////////////

TradeInfo::TradeInfo()
	throw ()
{
	__BEGIN_TRY
	
	m_Gold      = 0;
	m_Status    = TRADE_TRADING;

	Timeval currentTime;
	getCurrentTime(currentTime);
	m_LastOKTime = currentTime;

	__END_CATCH
}

TradeInfo::~TradeInfo()
	throw ()
{
	__BEGIN_TRY
	
	m_ItemList.clear();

	__END_CATCH
}

bool TradeInfo::hasItem(Item* pItem)
	throw ()
{
	__BEGIN_TRY

	list<Item*>::const_iterator itr = m_ItemList.begin();
	for (; itr != m_ItemList.end(); itr++)
	{
		if (pItem == (*itr)) return true;
	}
	return false;

	__END_CATCH
}

bool TradeInfo::addItem(Item* pItem)
	throw ()
{
	__BEGIN_TRY

	if (hasItem(pItem)) return false;
	m_ItemList.push_back(pItem);
	return true;

	__END_CATCH
}

bool TradeInfo::removeItem(Item* pItem)
	throw ()
{
	__BEGIN_TRY
	
	list<Item*>::iterator itr = m_ItemList.begin();
	for (; itr != m_ItemList.end(); itr++)
	{
		if (pItem == (*itr))
		{
			m_ItemList.erase(itr);
			return true;
		}
	}
	return false;

	__END_CATCH
}

void TradeInfo::clearAll(void)
	throw()
{
	__BEGIN_TRY

	m_ItemList.clear();
	m_Gold   = 0;
	m_Status = TRADE_TRADING;

	__END_CATCH
}

void TradeInfo::setNextTime(const Timeval& currentTime)
{
	m_LastOKTime.tv_sec = (currentTime.tv_sec + 4);
	m_LastOKTime.tv_usec = currentTime.tv_usec;
}

bool TradeInfo::isValidOKTime(const Timeval& currentTime)
{
	if (m_LastOKTime < currentTime) return true;
	return false;
}

////////////////////////////////////////////////////////////////////////////////
// class TradeManager member methods
////////////////////////////////////////////////////////////////////////////////

TradeManager::TradeManager()
	throw ()
{
	__BEGIN_TRY
	__END_CATCH
}

TradeManager::~TradeManager()
	throw ()
{
	__BEGIN_TRY

	map<string, TradeInfo*>::iterator itr = m_InfoMap.begin();
	for (; itr != m_InfoMap.end(); itr++)
	{
		TradeInfo* pInfo = itr->second;
		SAFE_DELETE(pInfo);
	}

	m_InfoMap.clear();
	
	__END_CATCH
}

void TradeManager::init()
	throw ()
{
	__BEGIN_TRY
	__END_CATCH
}

bool TradeManager::hasTradeInfo(const string & Name)
	throw ()
{
	__BEGIN_TRY

	map<string, TradeInfo*>::iterator itr = m_InfoMap.find(Name);
	if (itr == m_InfoMap.end()) return false;
	return true;

	__END_CATCH
}

TradeInfo* TradeManager::getTradeInfo(const string & Name)
	throw ()
{
	__BEGIN_TRY

	map<string, TradeInfo*>::iterator itr = m_InfoMap.find(Name);
	if (itr == m_InfoMap.end()) return NULL;
	return itr->second;

	__END_CATCH
}

void TradeManager::addTradeInfo(TradeInfo* pInfo)
	throw (DuplicatedException)
{
	__BEGIN_TRY

	Assert(pInfo != NULL);
	map<string, TradeInfo*>::iterator itr = m_InfoMap.find(pInfo->getMainName());
	if (itr != m_InfoMap.end()) throw DuplicatedException();
	m_InfoMap[pInfo->getMainName()] = pInfo;
		
	__END_CATCH
}

void TradeManager::removeTradeInfo(const string & Name)
	throw (NoSuchElementException)
{
	__BEGIN_TRY
	
	map<string, TradeInfo*>::iterator itr = m_InfoMap.find(Name);
	if (itr == m_InfoMap.end())
	{
		cerr << "TradeManager::removeTradeInfo() : NoSuchElementException" << endl;
		// �ǹ� ���°� ���Ƽ� �����Ѵ�.
		// by sigi. 2002.8.31
		//throw NoSuchElementException();
		return;
	}
	TradeInfo* pInfo = itr->second;
	m_InfoMap.erase(itr);
	SAFE_DELETE(pInfo);

	__END_CATCH
}

void TradeManager::initTrade(Creature* pCreature1, Creature* pCreature2)
	throw ()
{
	__BEGIN_TRY

	// �� �߿� �ϳ����� ��ȯ ����� ����ϸ� �����ϴ�.
	if (hasTradeInfo(pCreature1->getName()) || 
		hasTradeInfo(pCreature2->getName()))
	{
		throw ("TradeManager::initTrade() : Trade info already exist!");
	}

	TradeInfo* pInfo1 = new TradeInfo();
	pInfo1->setMainName(pCreature1->getName());
	pInfo1->setTargetName(pCreature2->getName());
	pInfo1->setStatus(TRADE_TRADING);
	addTradeInfo(pInfo1);

	TradeInfo* pInfo2 = new TradeInfo();
	pInfo2->setMainName(pCreature2->getName());
	pInfo2->setTargetName(pCreature1->getName());
	pInfo2->setStatus(TRADE_TRADING);
	addTradeInfo(pInfo2);

	__END_CATCH
}

int TradeManager::canTrade(Creature* pCreature1, Creature* pCreature2)
	throw ()
{
	__BEGIN_TRY

	try {

	// �����Ͱ� ���̸� �����Ѵ�.
	if (pCreature1 == NULL || pCreature2 == NULL) return 0;

	// ���������� ��ȯ� �ؾ߸� �Ѵ�.
	if (!pCreature1->isPC() || !pCreature2->isPC()) return 0;

	// �ٸ� �������� ��ȯ�� �� ����.
	if (!isSameRace(pCreature1, pCreature2)) return 0;

	// ��ȯ ����� �����Ǿ� ���� �ʴٸ� ��ȯ�� �� ����.
	if (!isTrading(pCreature1, pCreature2)) return 0;

	TradeInfo* pInfo1 = getTradeInfo(pCreature1->getName());
	TradeInfo* pInfo2 = getTradeInfo(pCreature2->getName());

	if (pInfo1==NULL || pInfo2==NULL)	// by sigi. 2002.12.25
		return 0;

	// �� �߿� �ϳ����� ��ȯ� �����ϰ� ���� �ʴٸ� ��ȯ�� �� ����.
	if (pInfo1->getStatus() != TRADE_FINISH || pInfo2->getStatus() != TRADE_FINISH) 
		return 0;

	// �ʿ��� ������� �غ��Ѵ�.
	list<Item*>      tradeList1  = pInfo1->getItemList();
	list<Item*>      tradeList2  = pInfo2->getItemList();
	ItemMap          itemMap1;
	ItemMap          itemMap2;
	Inventory*       pInventory1 = NULL;
	Inventory*       pInventory2 = NULL;

	bool             bTradeGiftBox = false;
	int				 EventGiftBoxCount = 0;

	if (pCreature1->isSlayer() && pCreature2->isSlayer())
	{
		Slayer* pSlayer1 = dynamic_cast<Slayer*>(pCreature1);
		Slayer* pSlayer2 = dynamic_cast<Slayer*>(pCreature2);

		pInventory1 = new Inventory(pSlayer1->getInventory());
		pInventory2 = new Inventory(pSlayer2->getInventory());
		pInventory1->setDeleteAllFlag(false);
		pInventory2->setDeleteAllFlag(false);
	}
	else if (pCreature1->isVampire() && pCreature2->isVampire())
	{
		Vampire* pVampire1 = dynamic_cast<Vampire*>(pCreature1);
		Vampire* pVampire2 = dynamic_cast<Vampire*>(pCreature2);

		pInventory1 = new Inventory(pVampire1->getInventory());
		pInventory2 = new Inventory(pVampire2->getInventory());
		pInventory1->setDeleteAllFlag(false);
		pInventory2->setDeleteAllFlag(false);
	}
	else if (pCreature1->isOusters() && pCreature2->isOusters())
	{
		Ousters* pOusters1 = dynamic_cast<Ousters*>(pCreature1);
		Ousters* pOusters2 = dynamic_cast<Ousters*>(pCreature2);

		pInventory1 = new Inventory(pOusters1->getInventory());
		pInventory2 = new Inventory(pOusters2->getInventory());
		pInventory1->setDeleteAllFlag(false);
		pInventory2->setDeleteAllFlag(false);
	}
	else throw Error("TradeManager::canTrade() : ���� �ٸ��ڳ�!");	// throw Error�� �ٲ�. by sigi. 2002.12.25

	// ���� ������ �κ��丮���� ��ȯ�� �����۵�� ����Ѵ�.
	for (list<Item*>::iterator itr = tradeList1.begin(); itr != tradeList1.end(); itr++)
	{
		Item* pItem = (*itr);
		if (pInventory1->hasItem(pItem->getObjectID()))
		{
			// ���� ���� ��ȯ �̺�Ʈ (���� ���ڴ� �ٸ� �����۰� �Բ� Trade �� �� ����! - ���Ҵ�
			if ( pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX
				 && pItem->getItemType() > 1 && pItem->getItemType() < 6 )
			{
				/*
				if ( tradeList1.size() != 1 )
					goto ErrorCode;
				*/

				bTradeGiftBox = true;
			}

			if ( pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX
					&& pItem->getItemType() >= 16 && pItem->getItemType() <= 18 )
			{
				EventGiftBoxCount++;
			}

			pInventory1->deleteItem(pItem->getObjectID());
			itemMap1.addItem(pItem);
		}
		else goto ErrorCode;
	}

	for (list<Item*>::iterator itr = tradeList2.begin(); itr != tradeList2.end(); itr++)
	{
		Item* pItem = (*itr);
		if (pInventory2->hasItem(pItem->getObjectID()))
		{
			// ���� ���� ��ȯ �̺�Ʈ (���� ���ڴ� �ٸ� �����۰� �Բ� Trade �� �� ����! - ��Ҵ�
			if ( pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX
				 && pItem->getItemType() > 1 && pItem->getItemType() < 6 )
			{
				/*
				if ( tradeList2.size() != 1 )
					goto ErrorCode;
				*/

				// ���밡 GiftBox �� �ø��� �ʾҴٸ� Trade �� �� �� ����!
				if ( !bTradeGiftBox )
				{
					SAFE_DELETE(pInventory1);
					SAFE_DELETE(pInventory2);
					return 2;
				}

				bTradeGiftBox = false;
			}

			if ( pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX
					&& pItem->getItemType() >= 16 && pItem->getItemType() <= 18 )
			{
				EventGiftBoxCount--;
			}

			pInventory2->deleteItem(pItem->getObjectID());
			itemMap2.addItem(pItem);
		}
		else goto ErrorCode;
	}

	// �Ѹ��̶��� GiftBox �� �ø��� �ʾ���� bTradeGiftBox �� true �� �Ǽ� ���ƿ´�
	if ( bTradeGiftBox || EventGiftBoxCount != 0 )
	{
		SAFE_DELETE(pInventory1);
		SAFE_DELETE(pInventory2);
		return 2;
	}

	// ��� ������ �κ��丮���� ��ȯ�� �����۵�� ���غ���.
	for (ItemMap::iterator itr = itemMap1.begin(); itr != itemMap1.end(); itr++)
	{
		Item* pItem = itr->second;
		// ������� ���ϴ� �� �ϳ����� ���� �� ���ٸ�, false�� �����Ѵ�.
		if (!pInventory2->addItem(pItem)) goto ErrorCode;
	}

	for (ItemMap::iterator itr = itemMap2.begin(); itr != itemMap2.end(); itr++)
	{
		Item* pItem = itr->second;
		// ������� ���ϴ� �� �ϳ����� ���� �� ���ٸ�, false�� �����Ѵ�.
		if (!pInventory1->addItem(pItem)) goto ErrorCode;
	}

	SAFE_DELETE(pInventory1);
	SAFE_DELETE(pInventory2);

	// �� ���� �� �־��ٸ�, true�� �����Ѵ�.
	return 1;

ErrorCode:
	SAFE_DELETE(pInventory1);
	SAFE_DELETE(pInventory2);
	return 0;

	} catch (Throwable &t) {	// by sigi. 2002.12.25

		filelog("tradeError.txt", "C1=%s, C2=%s, %s", pCreature1->getName().c_str(), pCreature2->getName().c_str(), t.toString().c_str());

		// trade �Ұ�..�� Ȯ�����ָ� �ȴ�.
		return 0;
	}

	__END_CATCH
}

void TradeManager::processTrade(Creature* pCreature1, Creature* pCreature2)
	throw ()
{
	__BEGIN_TRY

	if (!canTrade(pCreature1, pCreature2))
	{
		throw ("TradeManager::processTrade() : ��, ����. ��ȯ�� �� �Ǵµ�, �� ��ȯ��Ű�µ�?");
	}

	// �ʿ��� ������� �غ��Ѵ�.
	TradeInfo*  pInfo1      = getTradeInfo(pCreature1->getName());
	TradeInfo*  pInfo2      = getTradeInfo(pCreature2->getName());
	list<Item*> tradeList1  = pInfo1->getItemList();
	list<Item*> tradeList2  = pInfo2->getItemList();
	ItemMap     itemMap1;
	ItemMap     itemMap2;
	Gold_t      tradeGold1  = pInfo1->getGold();
	Gold_t      tradeGold2  = pInfo2->getGold();
	Inventory*  pInventory1 = NULL;
	Inventory*  pInventory2 = NULL;
	Slayer*     pSlayer1    = NULL;
	Slayer*     pSlayer2    = NULL;
	Vampire*    pVampire1   = NULL;
	Vampire*    pVampire2   = NULL;
	Ousters*    pOusters1   = NULL;
	Ousters*    pOusters2   = NULL;
	PlayerCreature*    pPlayerCreature1  = dynamic_cast<PlayerCreature*>(pCreature1);
	PlayerCreature*    pPlayerCreature2  = dynamic_cast<PlayerCreature*>(pCreature2);

	bool check1 = pPlayerCreature1->checkDBGold( pPlayerCreature1->getGold() + tradeGold1 );
	bool check2 = pPlayerCreature2->checkDBGold( pPlayerCreature2->getGold() + tradeGold2 );

	if ( !check1 )
	{
		filelog( "GoldBug.log", "TradeManager::processTrade : ���� �� �½�ϴ�. [%s:%s]", pPlayerCreature1->getName().c_str(), pPlayerCreature1->getPlayer()->getID().c_str() );
	}

	if ( !check2 )
	{
		filelog( "GoldBug.log", "TradeManager::processTrade : ���� �� �½�ϴ�. [%s:%s]", pPlayerCreature2->getName().c_str(), pPlayerCreature2->getPlayer()->getID().c_str() );
	}

	if ( !check1 || !check2 )
	{
		GamePlayer* pGamePlayer1 = dynamic_cast<GamePlayer*>(pPlayerCreature1->getPlayer());
		GamePlayer* pGamePlayer2 = dynamic_cast<GamePlayer*>(pPlayerCreature2->getPlayer());

		if ( pGamePlayer1 != NULL )
		{
			pGamePlayer1->setPenaltyFlag(PENALTY_TYPE_KICKED);
			pGamePlayer1->setItemRatioBonusPoint(1);
		}

		if ( pGamePlayer2 != NULL )
		{
			pGamePlayer2->setPenaltyFlag(PENALTY_TYPE_KICKED);
			pGamePlayer2->setItemRatioBonusPoint(1);
		}

		return;
	}


	bool        bTradeGiftBox = false;
	int         giftBoxType1 = 0;
    int         giftBoxType2 = 0;

	if (pCreature1->isSlayer() && pCreature2->isSlayer())
	{
		pSlayer1 = dynamic_cast<Slayer*>(pCreature1);
		pSlayer2 = dynamic_cast<Slayer*>(pCreature2);

		pInventory1 = pSlayer1->getInventory();
		pInventory2 = pSlayer2->getInventory();
	}
	else if (pCreature1->isVampire() && pCreature2->isVampire())
	{
		pVampire1 = dynamic_cast<Vampire*>(pCreature1);
		pVampire2 = dynamic_cast<Vampire*>(pCreature2);

		pInventory1 = pVampire1->getInventory();
		pInventory2 = pVampire2->getInventory();
	}
	else if (pCreature1->isOusters() && pCreature2->isOusters())
	{
		pOusters1 = dynamic_cast<Ousters*>(pCreature1);
		pOusters2 = dynamic_cast<Ousters*>(pCreature2);

		pInventory1 = pOusters1->getInventory();
		pInventory2 = pOusters2->getInventory();
	}
	else throw ("TradeManager::processTrade() : �ٸ� �� ���� ��ȯ�� ���� ����!");

	// ���� ������ �κ��丮���� ��ȯ�� �����۵�� ����Ѵ�.
	for (list<Item*>::iterator itr = tradeList1.begin(); itr != tradeList1.end(); itr++)
	{
		Item* pItem = (*itr);
		if (pInventory1->hasItem(pItem->getObjectID()))
		{
			// ���� ���� ��ȯ �̺�Ʈ (���� ���ڴ� �ٸ� �����۰� �Բ� Trade �� �� ����! - ���Ҵ�
			if ( pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX
				 && pItem->getItemType() > 1 && pItem->getItemType() < 6 )
			{
				/*
				if ( tradeList1.size() != 1 )
					throw ("TradeManager::processTrade() : ���� ���ڴ� �ٸ� �����۰� �Բ� ��ȯ�� ���� ����!");
				*/

				bTradeGiftBox = true;

				giftBoxType1 = pItem->getItemType();
			}

			pInventory1->deleteItem(pItem->getObjectID());
			itemMap1.addItem(pItem);
			pItem->whenPCLost(pPlayerCreature1);
		}
		else throw ("TradeManager::processTrade() : ����? �������� ���ڳ�!");
	}
	for (list<Item*>::iterator itr = tradeList2.begin(); itr != tradeList2.end(); itr++)
	{
		Item* pItem = (*itr);
		if (pInventory2->hasItem(pItem->getObjectID()))
		{
			// ���� ���� ��ȯ �̺�Ʈ (���� ���ڴ� �ٸ� �����۰� �Բ� Trade �� �� ����! - ���Ҵ�
			if ( pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX
				 && pItem->getItemType() > 1 && pItem->getItemType() < 6 )
			{
				/*
				if ( tradeList2.size() != 1 )
					throw ("TradeManager::processTrade() : ���� ���ڴ� �ٸ� �����۰� �Բ� ��ȯ�� ���� ����!");
				*/

				// ���밡 GiftBox �� �ø��� �ʾҴٸ� Trade �� �� �� ����!
				if ( !bTradeGiftBox )
					throw ("TradeManager::processTrade() : ���� ���ڴ� �� �� �÷�� ��ȯ�� �� �ִ�!");

				giftBoxType2 = pItem->getItemType();
			}

			pInventory2->deleteItem(pItem->getObjectID());
			itemMap2.addItem(pItem);
			pItem->whenPCLost(pPlayerCreature2);
		}
		else throw ("TradeManager::processTrade() : ����? �������� ���ڳ�!");
	}

	// ��� ������ �κ��丮���� ��ȯ�� �����۵�� ���غ���.
	for (ItemMap::iterator itr = itemMap1.begin(); itr != itemMap1.end(); itr++)
	{
		Item* pItem = itr->second;
		// ������� ���ϴ� �� �ϳ����� ���� �� ���ٸ�, false�� �����Ѵ�.
		if (!pInventory2->addItem(pItem))
		{
			throw ("TradeManager::processTrade() : ����, ��ȯ�ϴٰ� ��������.");
		}

		pItem->whenPCTake( pPlayerCreature2 );
		
		// ũ�������� �̺�Ʈ 2002.12.16. by bezz.
		// ���� ���� ���ڶ��� ��� ����� �ٲ۴�.
		if (pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX && pItem->getItemType() == 0)
		{
			pItem->setItemType(1);

			// FlagSet���. ���� ���� ���ڸ� ��� ���� by sigi. 2002.12.16
			FlagSet* pFlagSet = pPlayerCreature2->getFlagSet();
			Assert(pFlagSet!=NULL);
			pFlagSet->turnOn(FLAGSET_RECEIVE_GREEN_GIFT_BOX);
			pFlagSet->save( pCreature2->getName() );
		}

		if (pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX && pItem->getItemType() > 1 && pItem->getItemType() < 6)
		{
			int blackGiftBoxType = getBlackGiftBoxType( giftBoxType1, giftBoxType2 );

			if ( blackGiftBoxType != 0 )
				pItem->setItemType(blackGiftBoxType);
			else
				throw ("TradeManager::processTrade() : ����, ��ȯ�ϴٰ� ��������.");
		}

		if ( pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX
				&& pItem->getItemType() >= 16 && pItem->getItemType() <= 18 )
		{
			pItem->setItemType( pItem->getItemType()+3 );
		}

		// ItemTraceLog �� ������
		if ( pItem != NULL && pItem->isTraceItem() )
		{
			remainTraceLog( pItem, pCreature1->getName(), pCreature2->getName(), ITEM_LOG_TRADE, DETAIL_TRADE);
		}
	}
	for (ItemMap::iterator itr = itemMap2.begin(); itr != itemMap2.end(); itr++)
	{
		Item* pItem = itr->second;
		// ������� ���ϴ� �� �ϳ����� ���� �� ���ٸ�, false�� �����Ѵ�.
		if (!pInventory1->addItem(pItem))
		{
			throw ("TradeManager::processTrade() : ����, ��ȯ�ϴٰ� ��������.");
		}

		pItem->whenPCTake( pPlayerCreature1 );

		// ũ�������� �̺�Ʈ 2002.12.16. by bezz.
		// ���� ���� ���ڶ��� ��� ����� �ٲ۴�.
		if (pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX && pItem->getItemType() == 0)
		{
			pItem->setItemType(1);

			// FlagSet���. ���� ���� ���ڸ� ��� ���� by sigi. 2002.12.16
			FlagSet* pFlagSet = pPlayerCreature1->getFlagSet();
			Assert(pFlagSet!=NULL);
			pFlagSet->turnOn(FLAGSET_RECEIVE_GREEN_GIFT_BOX);
			pFlagSet->save( pCreature1->getName() );

		}

		if (pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX && pItem->getItemType() > 1 && pItem->getItemType() < 6)
		{
			int blackGiftBoxType = getBlackGiftBoxType( giftBoxType1, giftBoxType2 );

			if ( blackGiftBoxType != 0 )
				pItem->setItemType(blackGiftBoxType);
			else
				throw ("TradeManager::processTrade() : ����, ��ȯ�ϴٰ� ��������.");
		}

		if ( pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX
				&& pItem->getItemType() >= 16 && pItem->getItemType() <= 18 )
		{
			pItem->setItemType( pItem->getItemType()+3 );
		}

		// ItemTraceLog �� ������
		if ( pItem != NULL && pItem->isTraceItem() )
		{
			remainTraceLog( pItem, pCreature2->getName(), pCreature1->getName(), ITEM_LOG_TRADE, DETAIL_TRADE);
		}
	}

	// �Ű��� ������� DB���ٰ� �����Ѵ�.
	pInventory1->save(pCreature1->getName());
	pInventory2->save(pCreature2->getName());

	// �Ű��� ��� �����Ѵ�.
	if (pCreature1->isSlayer())
	{
		pSlayer1->setGoldEx(pSlayer1->getGold() + tradeGold2);
		pSlayer2->setGoldEx(pSlayer2->getGold() + tradeGold1);
	}
	else if (pCreature2->isVampire())
	{
		pVampire1->setGoldEx(pVampire1->getGold() + tradeGold2);
		pVampire2->setGoldEx(pVampire2->getGold() + tradeGold1);
	}
	else if (pCreature2->isOusters())
	{
		pOusters1->setGoldEx(pOusters1->getGold() + tradeGold2);
		pOusters2->setGoldEx(pOusters2->getGold() + tradeGold1);
	}

	// ��ȯ ����� ����ϱ� ���� �α׸� ���ܵд�.
	string ip1 = pCreature1->getPlayer()->getSocket()->getHost();
	string ip2 = pCreature2->getPlayer()->getSocket()->getHost();
	StringStream msg;
	msg << "[" << pCreature1->getName() << "(" << pPlayerCreature1->getPlayer()->getID() << ")] " << "\n";
	msg << "GOLD:" << tradeGold1 << "\n";
	for (ItemMap::iterator itr = itemMap1.begin(); itr != itemMap1.end(); itr++)
		msg << itr->second->toString() << "\n";
	msg << "----" << "\n";
	msg << "[" << pCreature2->getName() << "(" << pPlayerCreature2->getPlayer()->getID() << ")] "  << "\n";
	msg << "GOLD:" << tradeGold2 << "\n";
	for (ItemMap::iterator itr = itemMap2.begin(); itr != itemMap2.end(); itr++)
		msg << itr->second->toString() << "\n";

	// ���α� ������ -_-a
	if ( tradeGold1 >= g_pVariableManager->getMoneyTraceLogLimit() )
	{
		remainMoneyTraceLog( pCreature1->getName(), pCreature2->getName(), ITEM_LOG_TRADE, DETAIL_TRADE, tradeGold1 );
	}

	if ( tradeGold2 >= g_pVariableManager->getMoneyTraceLogLimit() )
	{
		remainMoneyTraceLog( pCreature2->getName(), pCreature1->getName(), ITEM_LOG_TRADE, DETAIL_TRADE, tradeGold2 );
	}

	//log(LOG_TRADE, pCreature1->getName(), pCreature2->getName(), msg.toString());

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		StringStream SQL;
		SQL << "INSERT INTO TradeLog (Timeline, Name1, IP1, Name2, IP2, Content) VALUES ("
			<< "'" << VSDateTime::currentDateTime().toString() << "',"
			<< "'" << pCreature1->getName() << "',"
			<< "'" << ip1 << "',"
			<< "'" << pCreature2->getName() << "',"
			<< "'" << ip2 << "',"
			<< "'" << msg.toString() << "'"
			<< ")";

		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery(SQL.toString());

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt);

	// ��ȯ�� �������, ��ȯ ����� ����Ѵ�.
	// *** Ŭ���̾�Ʈ ������ ��ȯ�� ���� �Ŀ���
	// ��ȯ â� ���� �ʱ⸦ ���ؼ���...
	//removeTradeInfo(pCreature1->getObjectID());
	//removeTradeInfo(pCreature2->getObjectID());
	pInfo1->clearAll();
	pInfo2->clearAll();

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ��ȯ� ���ҽ�Ű��, ��ȯ ������� üũ�� ���� �����۵�� ������ �ǵ�����.
// ����� �ǵ���� �� ��� �� ���̴�.
////////////////////////////////////////////////////////////////////////////////
void TradeManager::cancelTrade(Creature* pCreature1, Creature* pCreature2)
	throw ()
{
	__BEGIN_TRY

	try {

		int nCondition = 0;

		// �����Ͱ� ���̸� �����Ѵ�.
		if (pCreature1 == NULL || pCreature2 == NULL) nCondition = 1;

		// ���������� ��ȯ� �ؾ߸� �Ѵ�.
		if (!pCreature1->isPC() || !pCreature2->isPC()) nCondition = 2;

		// �ٸ� �������� ��ȯ�� �� ����.
		if (!isSameRace(pCreature1, pCreature2)) nCondition = 3;

		// ��ȯ ����� �����Ǿ� ���� �ʴٸ� ��ȯ�� �� ����.
		if (!isTrading(pCreature1, pCreature2)) nCondition = 4;

		if (nCondition != 0)
		{
			StringStream msg;
			msg << "TradeManager::cancelTrade() ��� �߻�... CODE(" 
				<< nCondition << ")";
			filelog("tradeError.txt", "[1] %s", msg.toString().c_str());
			//throw ("TradeManager::cancelTrade() : �̰� �� ����?");

			return;
		}

		TradeInfo* pInfo1 = getTradeInfo(pCreature1->getName());
		TradeInfo* pInfo2 = getTradeInfo(pCreature2->getName());

		// ù��° ũ���Ŀ� ���õ� ��ȯ ����� ���
		if (pCreature1->isSlayer())
		{
			Slayer* pSlayer1 = dynamic_cast<Slayer*>(pCreature1);
			if (pInfo1) pSlayer1->setGold(pSlayer1->getGold() + pInfo1->getGold());
		}
		else if (pCreature1->isVampire())
		{
			Vampire* pVampire1 = dynamic_cast<Vampire*>(pCreature1);
			if (pInfo1) pVampire1->setGold(pVampire1->getGold() + pInfo1->getGold());
		}
		else if (pCreature1->isOusters())
		{
			Ousters* pOusters1 = dynamic_cast<Ousters*>(pCreature1);
			if (pInfo1) pOusters1->setGold(pOusters1->getGold() + pInfo1->getGold());
		}

		// �ι�° ũ���Ŀ� ���õ� ��ȯ ����� ���
		if (pCreature2->isSlayer())
		{
			Slayer* pSlayer2 = dynamic_cast<Slayer*>(pCreature2);
			if (pInfo2) pSlayer2->setGold(pSlayer2->getGold() + pInfo2->getGold());
		}
		else if (pCreature2->isVampire())
		{
			Vampire* pVampire2 = dynamic_cast<Vampire*>(pCreature2);
			if (pInfo2) pVampire2->setGold(pVampire2->getGold() + pInfo2->getGold());
		}
		else if (pCreature2->isOusters())
		{
			Ousters* pOusters2 = dynamic_cast<Ousters*>(pCreature2);
			if (pInfo2) pOusters2->setGold(pOusters2->getGold() + pInfo2->getGold());
		}

		// ��ȯ ����� ����Ѵ�.
		if (pInfo1) removeTradeInfo(pCreature1->getName());
		if (pInfo2) removeTradeInfo(pCreature2->getName());

	} catch (Throwable& t) {
		filelog("tradeError.txt", "[1] %s", t.toString().c_str());
		//throw Error(t.toString().c_str());
	}

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ��ȯ� ���ҽ�Ű��, ��ȯ ������� üũ�� ���� �����۵�� ������ �ǵ�����.
// ����� �ǵ���� �� ��� �� ���̴�.
////////////////////////////////////////////////////////////////////////////////
void TradeManager::cancelTrade(Creature* pPC)
	throw ()
{
	__BEGIN_TRY

	try {

		// �����Ͱ� ���̸� �����Ѵ�.
		if (pPC == NULL) return;

		TradeInfo* pInfo1    = getTradeInfo(pPC->getName());
		TradeInfo* pInfo2    = NULL;
		string 	TargetName;
		Creature*  pTargetPC = NULL;
		Zone*      pZone     = pPC->getZone();

		if (pInfo1 != NULL)
		{
			pInfo2    = getTradeInfo(pInfo1->getTargetName());
			TargetName = pInfo1->getTargetName();

			// ù��° ũ���Ŀ� ���õ� ��ȯ ����� ���
			if (pPC->isSlayer())
			{
				Slayer* pSlayer1 = dynamic_cast<Slayer*>(pPC);
				pSlayer1->setGold(pSlayer1->getGold() + pInfo1->getGold());
			}
			else if (pPC->isVampire())
			{
				Vampire* pVampire1 = dynamic_cast<Vampire*>(pPC);
				pVampire1->setGold(pVampire1->getGold() + pInfo1->getGold());
			}
			else if (pPC->isOusters())
			{
				Ousters* pOusters1 = dynamic_cast<Ousters*>(pPC);
				pOusters1->setGold(pOusters1->getGold() + pInfo1->getGold());
			}

			/*
			try { pTargetPC = pZone->getCreature(TargetName); }
			catch (NoSuchElementException) { pTargetPC = NULL; }
			*/

			// NoSuch.. ���. by sigi. 2002.5.2
			pTargetPC = pZone->getCreature(TargetName);

			// ��ȯ ���밡 ��� ��� ����� ���, 
			// ��ȯ ���뿡�� ��ȯ�� �źεǾ��ٴ� ��Ŷ� �����ְ�,
			// ��ȯ ����� ������ش�.
			if (pTargetPC != NULL && pTargetPC->isPC() && pInfo2 != NULL)
			{
				// �ι�° ũ���Ŀ� ���õ� ��ȯ ����� ���
				if (pTargetPC->isSlayer())
				{
					Slayer* pSlayer2 = dynamic_cast<Slayer*>(pTargetPC);
					pSlayer2->setGold(pSlayer2->getGold() + pInfo2->getGold());
				}
				else if (pTargetPC->isVampire())
				{
					Vampire* pVampire2 = dynamic_cast<Vampire*>(pTargetPC);
					pVampire2->setGold(pVampire2->getGold() + pInfo2->getGold());
				}
				else if (pTargetPC->isOusters())
				{
					Ousters* pOusters2 = dynamic_cast<Ousters*>(pTargetPC);
					pOusters2->setGold(pOusters2->getGold() + pInfo2->getGold());
				}

				// Ÿ���� �Ǵ� ���󿡼� ��ȯ �ź� ��Ŷ� �����ش�.
				GCTradeFinish gcTradeFinish;
				gcTradeFinish.setTargetObjectID(pPC->getObjectID());
				gcTradeFinish.setCode(GC_TRADE_FINISH_REJECT);

				Player* pTargetPlayer = pTargetPC->getPlayer();
				pTargetPlayer->sendPacket(&gcTradeFinish);
			}

			// ��ȯ ����� ����Ѵ�.
			removeTradeInfo(pPC->getName());
			removeTradeInfo(TargetName);
		}

	} catch (Throwable& t) {
		filelog("tradeError.txt", "[2] %s", t.toString().c_str());
		//throw Error(t.toString().c_str());
	}

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// �� ũ���İ� ���� ��ȯ�������� üũ�Ѵ�.
////////////////////////////////////////////////////////////////////////////////
bool TradeManager::isTrading(Creature* pCreature1, Creature* pCreature2)
	throw ()
{
	__BEGIN_TRY

	TradeInfo* pInfo1 = getTradeInfo(pCreature1->getName());
	TradeInfo* pInfo2 = getTradeInfo(pCreature2->getName());

	if (pInfo1 == NULL || pInfo2 == NULL) return false;

	if ((pInfo1->getMainName() == pInfo2->getTargetName()) &&
		(pInfo2->getMainName() == pInfo1->getTargetName())) return true;

	return false;

	__END_CATCH
}
