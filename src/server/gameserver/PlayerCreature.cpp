//////////////////////////////////////////////////////////////////////////////
// Filename    : PlayerCreature.cpp
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "PlayerCreature.h"
#include "Stash.h"
#include "DB.h"
#include "StringStream.h"
#include "Item.h"
#include "ItemUtil.h"
#include "Belt.h"
#include "Inventory.h"
#include "GoodsInventory.h"
#include "Zone.h"
#include "FlagSet.h"
#include "ParkingCenter.h"
#include "Key.h"
#include "Guild.h"
#include "GuildManager.h"
#include "Gpackets/GCRankBonusInfo.h"
#include "Gpackets/GCTimeLimitItemInfo.h"
#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCOtherModifyInfo.h"
#include "Gpackets/GCNoticeEvent.h"
#include "Gpackets/GCMonsterKillQuestInfo.h"
#include "Gpackets/GCPetStashList.h"
#include "Player.h"
#include "RankBonusInfo.h"
#include "GamePlayer.h"
#include "TimeLimitItemManager.h"
#include "mission/QuestManager.h"
#include "Properties.h"
#include "PKZoneInfoManager.h"
#include "RankExpTable.h"
//#include "QuestManager.h"
//#include "QuestEvent.h"
//#include "Quest.h"
//#include "SimpleQuestLoader.h"
#include <list>
#include "DefaultOptionSetInfo.h"
#include "Pet.h"

const int MAX_GOODS_INVENTORY_SIZE = 10;

//////////////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////////////
PlayerCreature::PlayerCreature(ObjectID_t OID, Player* pPlayer)
	throw()
: Creature(OID, pPlayer)
{
	__BEGIN_TRY

	m_pInventory          = new Inventory(10, 6);
	m_pExtraInventorySlot = new InventorySlot();

	m_pGoodsInventory     = new GoodsInventory();

	m_pStash              = new Stash;
	m_StashNum            = 0;
	m_StashGold           = 0;
	m_bStashStatus        = false;

	m_pFlagSet            = new FlagSet;
	m_isPK				  = false;
	m_GuildID			  = 0;

	m_pQuestManager		  = new QuestManager(this);
	m_pTimeLimitItemManager = new TimeLimitItemManager( this );

	m_bLotto			  = false;
	m_pQuestItem		= NULL;
	m_pPetInfo			= NULL;

	m_RankExpSaveCount   = 0;
	m_pRank = NULL;
	m_pPet = NULL;
	
	m_PetStash.reserve( MAX_PET_STASH );
	for ( int i=0; i<MAX_PET_STASH; ++i ) m_PetStash.push_back(NULL);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////////////
PlayerCreature::~PlayerCreature()
	throw()
{
	__BEGIN_TRY

	// �κ��丮 ���
	SAFE_DELETE(m_pInventory);

	SAFE_DELETE(m_pGoodsInventory);

	// ���콺 �����Ϳ� �޷��ִ� ������� ����Ѵ�.
	if (m_pExtraInventorySlot != NULL)
	{
		Item* pItem = m_pExtraInventorySlot->getItem();
		if (pItem != NULL)
		{
			if (pItem->getItemClass() == Item::ITEM_CLASS_KEY)
			{
				Key* pKey = dynamic_cast<Key*>(pItem);
				// �� �����ϰ� �̾ȿ��� �˾Ƽ� ����� ���� �ֵ��� ����.
				if (g_pParkingCenter->hasMotorcycleBox(pKey->getTarget()))
				{
					g_pParkingCenter->deleteMotorcycleBox(pKey->getTarget());
				}
			}

			m_pExtraInventorySlot->deleteItem();
			SAFE_DELETE(pItem);
		}

		SAFE_DELETE(m_pExtraInventorySlot);
	}

	// ������ ���
	SAFE_DELETE(m_pStash);

	// �÷��� �� ���
	SAFE_DELETE(m_pFlagSet);

	// RankBonus map ���
	for ( HashMapRankBonusItor itr = m_RankBonuses.begin(); itr != m_RankBonuses.end(); itr++ )
	{
		SAFE_DELETE( itr->second );
	}
	m_RankBonuses.clear();

	if ( m_pTimeLimitItemManager != NULL )
		SAFE_DELETE( m_pTimeLimitItemManager );

	if ( m_pQuestManager != NULL )
		SAFE_DELETE( m_pQuestManager );

/*	for ( list<ItemNameInfo*>::iterator itr = m_ItemNameInfoList.begin(); itr != m_ItemNameInfoList.end(); itr++ )
	{
		ItemNameInfo* pInfo = *itr;
		SAFE_DELETE( pInfo );
	}
	m_ItemNameInfoList.clear();*/

	if ( m_pQuestItem != NULL )
		SAFE_DELETE( m_pQuestItem );

	SAFE_DELETE( m_pRank );

	for ( int i=0; i<MAX_PET_STASH; ++i )
	{
		SAFE_DELETE( m_PetStash[i] );
	}

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// ������ �ϳ� �����ϱ�
// *** ���� ***
// �� �Լ��� �θ��� ���� �ݵ��� OR���� ��� �ɾ��� �Ѵ�.
// ��������δ� ��� ���� �ʱ� �����̴�.
//////////////////////////////////////////////////////////////////////////////
void PlayerCreature::registerItem(Item* pItem, ObjectRegistry& OR)
    throw()
{
	__BEGIN_TRY

	Assert(pItem != NULL);

	// Item ��ü�� ObjectID �Ҵ�
	OR.registerObject_NOLOCKED(pItem);
	// �ð���� ������ �Ŵ����� OID �� �ٲ����ٰ� �˷��ش�.
	m_pTimeLimitItemManager->registerItem( pItem );

	// ��Ʈ���� �ȿ� �ִ� �����۵鵵 OID�� �޾Ƴ��ƾ� �Ѵ�.
	if (pItem->getItemClass() == Item::ITEM_CLASS_BELT)
	{
		Belt*       pBelt       = dynamic_cast<Belt*>(pItem);
		PocketNum_t PocketCount = pBelt->getPocketCount();
		Inventory*  pInventory  = pBelt->getInventory();

		for (int k=0; k<PocketCount; k++)
		{
			Item* pBeltItem = pInventory->getItem(k, 0);
			if (pBeltItem != NULL)
			{
				OR.registerObject_NOLOCKED(pBeltItem);
				// �ð���� ������ �Ŵ����� OID �� �ٲ����ٰ� �˷��ش�.
				m_pTimeLimitItemManager->registerItem( pBeltItem );
			}
		}
	} 

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// �κ��丮 �ȿ� �ִ� ������ �����ϱ�
// *** ���� ***
// �� �Լ��� �θ��� ���� �ݵ��� OR���� ��� �ɾ��� �Ѵ�.
// ��������δ� ��� ���� �ʱ� �����̴�.
//////////////////////////////////////////////////////////////////////////////
void PlayerCreature::registerInventory(ObjectRegistry& OR)
    throw()
{
	__BEGIN_TRY

	list<Item*> ItemList;
	int height = m_pInventory->getHeight();
	int width  = m_pInventory->getWidth();

	for (int j=0; j<height; j++)
	{
		for (int i=0; i<width; i++)
		{
			Item* pItem = m_pInventory->getItem(i, j);
			if (pItem != NULL)
			{
				// ���ϵ� �������� ����Ʈ���� ���� ������� ã�´�.
				list<Item*>::iterator itr = find(ItemList.begin(), ItemList.end(), pItem);

				if (itr == ItemList.end())
				{
					// ��� ������� �ι� �������� �ʱ� ��ؼ�
					// ����Ʈ���ٰ� ������� �����ִ´�.
					ItemList.push_back(pItem);

					// �������� OID�� �Ҵ��޴´�.
					registerItem(pItem, OR);

					i += pItem->getVolumeWidth() - 1;
				}
			}
		}
	}

	__END_CATCH
}

void PlayerCreature::registerInitInventory(ObjectRegistry& OR)
    throw()
{
	__BEGIN_TRY

	list<Item*> ItemList;
	int height = m_pInventory->getHeight();
	int width  = m_pInventory->getWidth();

	for (int j=0; j<height; j++)
	{
		for (int i=0; i<width; i++)
		{
			Item* pItem = m_pInventory->getItem(i, j);
			if (pItem != NULL)
			{
				// ���ϵ� �������� ����Ʈ���� ���� ������� ã�´�.
				list<Item*>::iterator itr = find(ItemList.begin(), ItemList.end(), pItem);

				if (itr == ItemList.end())
				{
					// ��� ������� �ι� ������� �ʱ� ��ؼ�
					// ����Ʈ���ٰ� ������� �����ִ´�.
					ItemList.push_back(pItem);

					// ItemTrace �� ���� ������ ���
					pItem->setTraceItem( bTraceLog( pItem ) );

					// �������� OID�� �Ҵ��޴´�.
					registerItem(pItem, OR);

					i += pItem->getVolumeWidth() - 1;
				}
			}
		}
	}

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// ������ �ȿ� �����ִ� ������ �����ϱ�
//////////////////////////////////////////////////////////////////////////////
void PlayerCreature::registerStash(void)
	throw()
{
	__BEGIN_TRY

	Zone* pZone = getZone();
	ObjectRegistry& OR = pZone->getObjectRegistry();

	__ENTER_CRITICAL_SECTION(OR)

	for (int r=0; r<STASH_RACK_MAX; r++)
	{
		for (int i=0; i<STASH_INDEX_MAX; i++)
		{
			Item* pStashItem = m_pStash->get(r, i);
			if (pStashItem != NULL) registerItem(pStashItem, OR);
		}
	}

	__LEAVE_CRITICAL_SECTION(OR)

	m_bStashStatus = true;

	__END_CATCH
}

void PlayerCreature::registerGoodsInventory(ObjectRegistry& OR)
    throw()
{
	__BEGIN_TRY

	GoodsInventory::ListItem& goods = m_pGoodsInventory->getGoods();
	GoodsInventory::ListItemItr itr = goods.begin();

	for ( ; itr != goods.end(); itr++ )
	{
		registerItem( (*itr).m_pItem, OR);
	}

	__END_CATCH
}


void PlayerCreature::loadTimeLimitItem() throw(Error)
{
	__BEGIN_TRY

	Assert( m_pTimeLimitItemManager != NULL );

	m_pTimeLimitItemManager->load();

	__END_CATCH
}

void PlayerCreature::loadItem()
	throw (InvalidProtocolException, Error)
{
	__BEGIN_TRY

	loadTimeLimitItem();

	__END_CATCH
}

bool PlayerCreature::wasteIfTimeLimitExpired(Item* pItem)
	throw (Error)
{
	__BEGIN_TRY

	if ( pItem == NULL ) return false;

	if ( m_pTimeLimitItemManager->wasteIfTimeOver( pItem ) )
	{
		pItem->waste( STORAGE_TIMEOVER );
		return true;
	}

	return false;

	__END_CATCH
}

void PlayerCreature::sendTimeLimitItemInfo()
	throw(Error)
{
	__BEGIN_TRY

	GCTimeLimitItemInfo gcTimeLimitItemInfo;

	if ( m_pTimeLimitItemManager->makeTimeLimitItemInfo( gcTimeLimitItemInfo ) )
	{
		getPlayer()->sendPacket( &gcTimeLimitItemInfo );
	}

	__END_CATCH
}

void PlayerCreature::addTimeLimitItem(Item* pItem, DWORD time) throw(Error)
{
	m_pTimeLimitItemManager->addTimeLimitItem( pItem, time );
} 

void PlayerCreature::sellItem( Item* pItem ) throw(Error)
{
	__BEGIN_TRY

	if ( pItem->isTimeLimitItem() ) m_pTimeLimitItemManager->itemSold( pItem );

	__END_CATCH
}

void PlayerCreature::deleteItemByMorph( Item* pItem ) throw(Error)
{
	__BEGIN_TRY

	if ( pItem->isTimeLimitItem() ) m_pTimeLimitItemManager->deleteItemByMorph( pItem );

	__END_CATCH
}

void PlayerCreature::sendCurrentQuestInfo() const throw(Error)
{
	m_pQuestManager->sendQuestInfo();
}

void PlayerCreature::whenQuestLevelUpgrade()
{
	if ( getQuestLevel() == 40 )
	{
		GCNoticeEvent gcNE;
		gcNE.setCode( NOTICE_EVENT_CAN_PET_QUEST );
		getPlayer()->sendPacket(&gcNE);
	}
}

//////////////////////////////////////////////////////////////////////////////
// ������ ���� �����ϱ�
//////////////////////////////////////////////////////////////////////////////
void PlayerCreature::setStashNumEx(BYTE num)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;

	setStashNum(num);

	BEGIN_DB
	{
		StringStream sqlSlayer;
		StringStream sqlVampire;
		StringStream sqlOusters;

		sqlSlayer << "UPDATE Slayer set StashNum = " << (int)num
			<< " WHERE Name = '" << getName() << "'";
		sqlVampire << "UPDATE Vampire set StashNum = " << (int)num
			<< " WHERE Name = '" << getName() << "'";
		sqlOusters << "UPDATE Ousters set StashNum = " << (int)num
			<< " WHERE Name = '" << getName() << "'";

		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery(sqlSlayer.toString());
		if ( !isOusters() )
			pStmt->executeQuery(sqlVampire.toString());
		else
			pStmt->executeQuery(sqlOusters.toString());

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// �����Կ� �����ִ� �� �����ϱ�
//////////////////////////////////////////////////////////////////////////////
void PlayerCreature::setStashGoldEx(Gold_t gold)
	throw()
{
	__BEGIN_TRY

	//cout << "setStashGoldEx Called" << "Name:" << getName() << " Gold: " << (int)gold << endl;
	Statement* pStmt = NULL;

	setStashGold(gold);

	BEGIN_DB
	{
		StringStream sqlSlayer;
		StringStream sqlVampire;
		StringStream sqlOusters;

		sqlSlayer << "UPDATE Slayer set StashGold = " << (int)gold
			<< " WHERE Name = '" << getName() << "'";
		sqlVampire << "UPDATE Vampire set StashGold = " << (int)gold
			<< " WHERE Name = '" << getName() << "'";
		sqlOusters << "UPDATE Ousters set StashGold = " << (int)gold
			<< " WHERE Name = '" << getName() << "'";

		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery(sqlSlayer.toString());
		if ( !isOusters() )
			pStmt->executeQuery(sqlVampire.toString());
		else
			pStmt->executeQuery(sqlOusters.toString());

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// �����Կ� �����ִ� �� �����ϱ�
//////////////////////////////////////////////////////////////////////////////
void PlayerCreature::increaseStashGoldEx(Gold_t gold)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;

	setStashGold(m_StashGold + gold);

	BEGIN_DB
	{
		StringStream sqlSlayer;
		StringStream sqlVampire;
		StringStream sqlOusters;

		sqlSlayer << "UPDATE Slayer set StashGold = " << (int)m_StashGold
			<< " WHERE Name = '" << getName() << "'";
		sqlVampire << "UPDATE Vampire set StashGold = " << (int)m_StashGold
			<< " WHERE Name = '" << getName() << "'";
		sqlOusters << "UPDATE Ousters set StashGold = " << (int)m_StashGold
			<< " WHERE Name = '" << getName() << "'";

		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery(sqlSlayer.toString());
		if ( !isOusters() )
			pStmt->executeQuery(sqlVampire.toString());
		else
			pStmt->executeQuery(sqlOusters.toString());

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// �����Կ� �����ִ� �� �����ϱ�
//////////////////////////////////////////////////////////////////////////////
void PlayerCreature::decreaseStashGoldEx(Gold_t gold)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;

	setStashGold(m_StashGold - gold);

	BEGIN_DB
	{
		StringStream sqlSlayer;
		StringStream sqlVampire;
		StringStream sqlOusters;

		sqlSlayer << "UPDATE Slayer set StashGold = " << (int)m_StashGold
			<< " WHERE Name = '" << getName() << "'";
		sqlVampire << "UPDATE Vampire set StashGold = " << (int)m_StashGold
			<< " WHERE Name = '" << getName() << "'";
		sqlOusters << "UPDATE Ousters set StashGold = " << (int)m_StashGold
			<< " WHERE Name = '" << getName() << "'";

		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery(sqlSlayer.toString());
		if ( !isOusters() )
			pStmt->executeQuery(sqlVampire.toString());
		else
			pStmt->executeQuery(sqlOusters.toString());

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// ������ �޸𸮿��� ����ϱ�
//////////////////////////////////////////////////////////////////////////////
void PlayerCreature::deleteStash(void)
	throw()
{
	__BEGIN_TRY

	SAFE_DELETE(m_pStash);
	m_StashNum = 0;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// �÷��׼� �޸𸮿��� ����ϱ�
//////////////////////////////////////////////////////////////////////////////
void PlayerCreature::deleteFlagSet(void)
	throw()
{
	__BEGIN_TRY

	SAFE_DELETE(m_pFlagSet);

	__END_CATCH
}

//----------------------------------------------------------------------
// �������� ����Ʈ�� �����ڸ� �߰��ϴ� �Լ�
//----------------------------------------------------------------------
void PlayerCreature::addEnemy(const string& Name)
	throw(Error)
{
	__BEGIN_DEBUG

	list<string>::iterator itr = find(m_Enemies.begin() , m_Enemies.end() , Name);

	// ���ٸ� �߰�����
	if (itr == m_Enemies.end()) 
	{
		m_Enemies.push_back(Name);
		//cout << "�����ڸ� �߰��Ѵ� : " << Name << endl;
	}

	__END_DEBUG
}

//----------------------------------------------------------------------
// �������� ����Ʈ�� �����ڸ� ����ϴ� �Լ�
//----------------------------------------------------------------------
void PlayerCreature::deleteEnemy(const string& Name)
	throw(NoSuchElementException, Error)
{
	__BEGIN_DEBUG

    list<string>::iterator itr = find(m_Enemies.begin(), m_Enemies.end() , Name);
	if (itr != m_Enemies.end()) 
	{
		m_Enemies.erase(itr);
		//cout << "�����ڸ� ������ : " << Name << endl;
	}

	__END_DEBUG
}

//----------------------------------------------------------------------
// Ư� �̸�� ���� �����ڰ� �̹� �ִ��� ������ Ȯ���ϴ� �Լ�.
//----------------------------------------------------------------------
bool PlayerCreature::hasEnemy(const string& Name)
	const throw()
{
	__BEGIN_DEBUG

    list<string>::const_iterator itr = find(m_Enemies.begin(), m_Enemies.end() , Name);
	if (itr != m_Enemies.end()) 
	{
		//cout << "�����ڷ� �̹� ����� �Ǿ��ִ� : " << Name << endl;
		return true;
	} 
	else 
	{
		return false;
	}

	__END_DEBUG
}

//----------------------------------------------------------------------
// ���� �̸�� ������ �Լ�
//----------------------------------------------------------------------
string PlayerCreature::getGuildName() const
	throw()
{
	Guild* pGuild = g_pGuildManager->getGuild( m_GuildID );
	
	if ( pGuild != NULL )
		return pGuild->getName();

	return "";
}

//----------------------------------------------------------------------
// ���� ���� ��ũ�� ������ �Լ�
//----------------------------------------------------------------------
GuildMemberRank_t PlayerCreature::getGuildMemberRank() const
	throw()
{
	Guild* pGuild = g_pGuildManager->getGuild( m_GuildID );

	if ( pGuild != NULL )
	{
		GuildMember* pGuildMember = pGuild->getMember( getName() );
		if ( pGuildMember != NULL )
		{
			return pGuildMember->getRank();
		}
	}

	return GuildMember::GUILDMEMBER_RANK_DENY;
}

Rank_t PlayerCreature::getRank() const throw() { return m_pRank->getLevel(); }
RankExp_t PlayerCreature::getRankExp() const throw() { return m_pRank->getTotalExp(); }
RankExp_t PlayerCreature::getRankGoalExp() const throw() { return m_pRank->getGoalExp(); }

RankBonus* PlayerCreature::getRankBonus( RankBonus::RankBonusType type ) const
	throw()
{
	__BEGIN_TRY
	
	HashMapRankBonusConstItor itr = m_RankBonuses.find( type );

	if ( itr == m_RankBonuses.end() )
	{
		return NULL;
	}
	
	return itr->second;

	__END_CATCH
}

void PlayerCreature::addRankBonus( RankBonus* rankBonus )
	throw()
{
	__BEGIN_TRY

	HashMapRankBonusItor itr = m_RankBonuses.find( rankBonus->getType() );

	if ( itr == m_RankBonuses.end() )
	{
		m_RankBonuses[rankBonus->getType()] = rankBonus;
		m_RankBonusFlag.set( rankBonus->getType() );
	}
	else
	{
		SAFE_DELETE( rankBonus );
	}

	__END_CATCH
}

void PlayerCreature::clearRankBonus()
	throw()
{
	__BEGIN_TRY

	HashMapRankBonusItor itr = m_RankBonuses.begin();
	for ( ; itr != m_RankBonuses.end(); itr++ )
	{
		SAFE_DELETE( itr->second );
	}

	m_RankBonuses.clear();
	m_RankBonusFlag.reset();

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery( "DELETE FROM RankBonusData WHERE OwnerID = '%s'", getName().c_str() );
	}
	END_DB( pStmt )

	__END_CATCH
}

RankBonus* PlayerCreature::getRankBonusByRank( Rank_t rank ) const
	throw()
{
	__BEGIN_TRY

	HashMapRankBonusConstItor itr = m_RankBonuses.begin();

	for ( ; itr != m_RankBonuses.end(); itr++ )
	{
		RankBonus* pLearnedRankBonus = itr->second;

		if ( rank == pLearnedRankBonus->getRank() )
		{
			return pLearnedRankBonus;
		}
	}

	return NULL;

	__END_CATCH
}

void PlayerCreature::clearRankBonus( Rank_t rank )
	throw()
{
	__BEGIN_TRY

	RankBonus* pRankBonus = getRankBonusByRank( rank );
	if ( pRankBonus == NULL )
		return;

	DWORD rankBonusType = pRankBonus->getType();

	HashMapRankBonusItor itr = m_RankBonuses.find( rankBonusType );
	if ( itr != m_RankBonuses.end() )
	{
		m_RankBonusFlag.reset( rankBonusType );
		SAFE_DELETE( itr->second );
		m_RankBonuses.erase( itr );
	}

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery( "DELETE FROM RankBonusData WHERE OwnerID = '%s' AND Type = %d", getName().c_str(), (int)rankBonusType );
	}
	END_DB( pStmt )

	__END_CATCH
}

bool PlayerCreature::learnRankBonus( DWORD type )
	throw()
{
	__BEGIN_TRY

	// ��� Rank �� Bonus �� �ִٸ� ���� �� ����.
	HashMapRankBonusConstItor itr = m_RankBonuses.begin();

	RankBonusInfo* pRankBonusInfo = g_pRankBonusInfoManager->getRankBonusInfo( type );

	// �� �˻�. 0�� �����̾�. 1�� �����̾�
	bool bValidRace = isSlayer() && pRankBonusInfo->getRace() == 0
						|| isVampire() && pRankBonusInfo->getRace() == 1
						|| isOusters() && pRankBonusInfo->getRace() == 2;

	// ���� �˻�
	if ( getRank() < pRankBonusInfo->getRank() )
		return false;

	if (!bValidRace)
		return false;

	for ( ; itr != m_RankBonuses.end(); itr++ )
	{
		RankBonus* pLearnedRankBonus = itr->second;

		if ( pRankBonusInfo->getRank() == pLearnedRankBonus->getRank() )
		{
			DWORD type = pLearnedRankBonus->getType();

			RankBonusInfo* pLearnedRankBonusInfo = g_pRankBonusInfoManager->getRankBonusInfo( type );

			// ��� ���� ��� ������ ����� �� ������.
			if ( pRankBonusInfo->getRace()==pLearnedRankBonusInfo->getRace())
			{
				return false;
			}
		}
	}
	
	RankBonus* rankBonus = new RankBonus( pRankBonusInfo->getType(), pRankBonusInfo->getPoint(), pRankBonusInfo->getRank() );

	addRankBonus( rankBonus );

	// DB �� �߰�
	Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery( "INSERT INTO RankBonusData ( OwnerID, Type )  VALUES ( '%s', %d )", getName().c_str(), type );

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	return true;

	__END_CATCH
}

void PlayerCreature::sendRankBonusInfo()
	throw()
{
	__BEGIN_TRY

	HashMapRankBonusConstItor itr = m_RankBonuses.begin();

	GCRankBonusInfo gcRankBonusInfo;

	for ( ; itr != m_RankBonuses.end(); itr++ )
	{
		gcRankBonusInfo.addListElement( itr->second->getType() );
	}

	m_pPlayer->sendPacket( &gcRankBonusInfo );

	__END_CATCH
}

void PlayerCreature::loadRankBonus()
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	Result* pResult = NULL;
	
	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery( "SELECT Type FROM RankBonusData WHERE OwnerID ='%s'", getName().c_str() );

		while ( pResult->next() )
		{
			DWORD rankBonusType = pResult->getInt(1);

			RankBonusInfo* pRankBonusInfo = g_pRankBonusInfoManager->getRankBonusInfo( rankBonusType );

			if ( getRace() == pRankBonusInfo->getRace() )
			{
				RankBonus* pRankBonus = new RankBonus();

				pRankBonus->setType( rankBonusType );
				pRankBonus->setPoint( pRankBonusInfo->getPoint() );
				pRankBonus->setRank( pRankBonusInfo->getRank() );

				addRankBonus( pRankBonus );
			}
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)
		
	__END_CATCH
}

void PlayerCreature::increaseRankExp(RankExp_t Point)
{
	if (Point <= 0) return;

	// PK � �ȿ����� ����ġ�� ���� �ʴ´�.
	if ( g_pPKZoneInfoManager->isPKZone( getZoneID() ) )
		return;

	if ( m_pRank->increaseExp(Point) )
	{
		char pField[80];
		sprintf(pField, "Rank=%u, RankExp=%lu, RankGoalExp=%lu",
				getRank(), getRankExp(), getRankGoalExp());
		tinysave(pField);
		setRankExpSaveCount(0);

		GCModifyInformation gcModifyInformation;
		gcModifyInformation.addLongData(MODIFY_RANK, getRank());
		m_pPlayer->sendPacket(&gcModifyInformation);

		if (m_pZone != NULL)
		{
			GCOtherModifyInfo gcOtherModifyInfo;
			gcOtherModifyInfo.setObjectID(getObjectID());
			gcOtherModifyInfo.addShortData(MODIFY_RANK, getRank());

			m_pZone->broadcastPacket(m_X, m_Y, &gcOtherModifyInfo, this);
		}
	}
	else
	{
		WORD rankExpSaveCount = getRankExpSaveCount();
		if (rankExpSaveCount > RANK_EXP_SAVE_PERIOD)
		{
			char pField[80];
			sprintf(pField, "RankExp=%lu, RankGoalExp=%lu", getRankExp(), getRankGoalExp());
			tinysave(pField);

			rankExpSaveCount = 0;
		}
		else rankExpSaveCount++;
		setRankExpSaveCount(rankExpSaveCount);

		// ���� ����ġ�� �����ش�. by sigi. 2002.9.13
		GCModifyInformation gcModifyInformation;
		gcModifyInformation.addLongData(MODIFY_RANK_EXP, getRankGoalExp());
		m_pPlayer->sendPacket(&gcModifyInformation);
	}
}

bool PlayerCreature::isBillingPlayAvaiable() 
	throw(Error)
{
	__BEGIN_TRY

	if (m_pPlayer==NULL)
		return false;

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(m_pPlayer);
	Assert(pGamePlayer!=NULL);

	return pGamePlayer->isBillingPlayAvaiable();

	__END_CATCH
}


bool PlayerCreature::isPayPlayAvaiable() 
	throw(Error)
{
	__BEGIN_TRY

	if (m_pPlayer==NULL)
		return false;

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(m_pPlayer);
	return pGamePlayer->isPayPlaying();

	__END_CATCH
}


bool PlayerCreature::canPlayFree()
	throw(Error)
{
	return false;
}

void PlayerCreature::loadGoods()
	throw(Error)
{
	__BEGIN_TRY
	
	Statement* pStmt = NULL;
	Result* pResult = NULL;

	if ( m_pGoodsInventory->getNum() != 0 )
	{
		filelog("GoodsReload.log", "���Ͼ��� ���ε� �߳�? : %s", getName().c_str() );
		m_pGoodsInventory->clear();
	}

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getDistConnection( "PLAYER_DB" )->createStatement();

		pResult = pStmt->executeQuery( "SELECT ID, GoodsID, Num FROM GoodsListObject WHERE World = %d AND PlayerID = '%s' AND Name = '%s' AND Status = 'NOT'",
										g_pConfig->getPropertyInt("WorldID"),
										getPlayer()->getID().c_str(),
										getName().c_str() );

		while ( pResult->next() )
		{
			string ID = pResult->getString(1);
			DWORD goodsID = pResult->getInt(2);
			int num = pResult->getInt(3);

			for ( int i = 0; i < max(1,min(50,num)) ; i++ )
			{
				Item* pItem = createItemByGoodsID( goodsID );
				if ( pItem != NULL )
				{
					m_pGoodsInventory->addItem( ID, pItem );
				}
			}
		}

		SAFE_DELETE( pStmt );
	}
	END_DB(pStmt)

	__END_CATCH
}


/*void	PlayerCreature::loadQuest() 
	throw (Error)
{
	__BEGIN_TRY

#ifdef __ACTIVE_QUEST__

	SimpleQuestLoader::getInstance()->load( this );
	
#endif

	__END_CATCH
}

bool    PlayerCreature::addQuest(Quest* pQuest) 
	throw (Error)
{
	__BEGIN_TRY

#ifdef __ACTIVE_QUEST__
	if (m_pQuestManager==NULL)
	{
		m_pQuestManager = new QuestManager;
	}

	if (m_pQuestManager->addQuest( pQuest ))
	{
		return true;
	}

#endif
	__END_CATCH

	SAFE_DELETE(pQuest);

	return false;
}

bool    PlayerCreature::checkEvent(QuestEvent* pQuestEvent) 
	throw (Error)
{
	__BEGIN_TRY

#ifdef __ACTIVE_QUEST__

	if (m_pQuestManager!=NULL)
	{
		Quest* pCompleteQuest = m_pQuestManager->checkEvent( pQuestEvent );

		if (pCompleteQuest!=NULL)
		{
			//cout << "[Complete] " << pCompleteQuest->toString().c_str() << endl;
			return true;
		}
	}

#endif

	return false;

	__END_CATCH
}

Quest*  PlayerCreature::removeCompleteQuest() 
	throw (Error)
{
	__BEGIN_TRY

#ifdef __ACTIVE_QUEST__

	if (m_pQuestManager!=NULL)
	{
		Quest* pQuest = m_pQuestManager->removeCompleteQuest();

		return pQuest;
	}

#endif

	__END_CATCH

	return NULL;
}*/
/*
bool PlayerCreature::deleteItemNameInfoList( ObjectID_t objectID ) 
	throw(Error)
{
	__BEGIN_TRY

	list<ItemNameInfo*>::iterator itr = m_ItemNameInfoList.begin();
	
	for( ; itr != m_ItemNameInfoList.end() ; itr++ )
	{
		ItemNameInfo* pInfo = *itr;
		if( pInfo->getObjectID() == objectID )
		{
			SAFE_DELETE( pInfo );
			m_ItemNameInfoList.erase( itr );

			return true;
		}
	}

	return false;

	__END_CATCH
}

string PlayerCreature::getItemName( ObjectID_t objectID ) 
	throw(Error)
{
	__BEGIN_TRY

	list<ItemNameInfo*>::iterator itr = m_ItemNameInfoList.begin();
	
	for( ; itr != m_ItemNameInfoList.end() ; itr++ )
	{
		ItemNameInfo* pInfo = *itr;
		if( pInfo->getObjectID() == objectID )
		{
			return pInfo->getName();
		}
	}

	return NULL;

	__END_CATCH
}
*/

void PlayerCreature::addDefaultOptionSet( DefaultOptionSetType_t type )
	throw()
{
	// �̹� �ִ� ������ Ȯ���Ѵ�.
	list<DefaultOptionSetType_t>::iterator itr = m_DefaultOptionSet.begin();
	for ( ; itr != m_DefaultOptionSet.end(); itr++ )
	{
		if ( (*itr) == type )
			return;
	}

	m_DefaultOptionSet.push_front( type );
}

void PlayerCreature::removeDefaultOptionSet( DefaultOptionSetType_t type )
	throw()
{
	list<DefaultOptionSetType_t>::iterator before = m_DefaultOptionSet.end();
	list<DefaultOptionSetType_t>::iterator current = m_DefaultOptionSet.begin();

	for ( ; current != m_DefaultOptionSet.end(); before = current++ )
	{
		if ( (*current) == type )
		{
			// �߰��ߴ�.
			if ( before == m_DefaultOptionSet.end() )
			{
				// delete first node
				m_DefaultOptionSet.pop_front();
			}
			else
			{
				m_DefaultOptionSet.erase(current);
			}

			return;
		}
	}

	// �߰߸��ߴ�.
}

PetInfo* PlayerCreature::getPetInfo() const
{
	return m_pPetInfo;
}

void PlayerCreature::setPetInfo(PetInfo* pPetInfo)
{
	m_pPetInfo = pPetInfo;
	SAFE_DELETE( m_pPet );
	m_pPet = Pet::makePet(this, m_pPetInfo);
}

void PlayerCreature::heartbeat(const Timeval& currentTime) throw()
{
	if ( m_pPet != NULL ) m_pPet->heartbeat( currentTime );
}


GCMonsterKillQuestInfo::QuestInfo*	PlayerCreature::getPetQuestInfo() const
{
	GCMonsterKillQuestInfo::QuestInfo* pQI = new GCMonsterKillQuestInfo::QuestInfo;

	pQI->questID = PET_QUEST_ID;
	pQI->sType = m_TargetMonster;
	pQI->goal = m_TargetNum;
	pQI->timeLimit = m_TimeLimit;

	return pQI;
}

void	PlayerCreature::addPetStashItem(int idx, Item* pPetItem)
{
	Assert( pPetItem == NULL || pPetItem->getItemClass() == Item::ITEM_CLASS_PET_ITEM );
	Assert( idx >= 0 && idx <= MAX_PET_STASH );
	m_PetStash[idx] = pPetItem;
}

Item*	PlayerCreature::getPetStashItem(int idx)
{
	Assert( idx >= 0 && idx <= MAX_PET_STASH );
	return m_PetStash[idx];
}
