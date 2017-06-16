//////////////////////////////////////////////////////////////////////////////
// Filename    : PlayerCreature.h
// Written by  : excel96
// Description : 
// Slayer �� Vampire Ŭ������ �������̽� �� �����Ǵ� �κ�� ���Ƴ�� 
// Ŭ������. abstract Ŭ�����̹Ƿ�, �ٷ� �����ϸ� �� �� ���̴�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __PLAYER_CREATURE_H__
#define __PLAYER_CREATURE_H__

#include "Creature.h"
#include "ObjectRegistry.h"
#include "InventorySlot.h"
#include "Garbage.h"
#include "RankBonus.h"
#include "ExpFwd.h"
//#include "RankExpTable.h"
//#include "ItemNameInfo.h"
//#include "quest/Squest/QuestManager.h"
#include "Gpackets/GCMonsterKillQuestInfo.h"

#include <map>
#include <bitset>
#include <list>
#include <vector>

static const GuildID_t SlayerCommon	=99;
static const GuildID_t VampireCommon=0;
static const GuildID_t OustersCommon=66;


//////////////////////////////////////////////////////////////////////////////
// class PlayerCreature
//////////////////////////////////////////////////////////////////////////////

class Inventory;
class InventorySlot;
class Stash;
class Player;
class FlagSet;
class QuestManager;
class TimeLimitItemManager;
class GoodsInventory;
class PetInfo;
class PetItem;
class Pet;
//class GCMonsterKillQuestInfo;
//struct GCMonsterKillQuestInfo::QuestInfo;

typedef map<DWORD, RankBonus*> HashMapRankBonus;
typedef HashMapRankBonus::iterator HashMapRankBonusItor;
typedef HashMapRankBonus::const_iterator HashMapRankBonusConstItor;


class PlayerCreature : public Creature
{
////////////////////////////////////////////////////////////
// ������ �� �Ҹ���
////////////////////////////////////////////////////////////
public:
	PlayerCreature(ObjectID_t objectID = 0, Player* pPlayer = NULL) throw();
	virtual ~PlayerCreature() throw();

	virtual void tinysave(const string & field) const throw (Error) = 0;
//	virtual void tinysave(const char* field) const throw (Error) = 0;

////////////////////////////////////////////////////////////
// OID ���� ���� �޽���
////////////////////////////////////////////////////////////
protected:
	virtual void registerItem(Item* pItem, ObjectRegistry& OR) throw();

public:
	virtual void registerInventory(ObjectRegistry& OR) throw();
	virtual void registerInitInventory(ObjectRegistry& OR) throw();
	virtual void registerStash(void) throw();

	virtual void registerGoodsInventory(ObjectRegistry& OR) throw();

//////////////////////////////////////////////////////////////
// �ð���� ������ ���� �Լ�
//////////////////////////////////////////////////////////////
public:
	bool wasteIfTimeLimitExpired(Item* pItem) throw (Error);
	virtual void checkItemTimeLimit() throw (Error) = 0;
	void sendTimeLimitItemInfo() throw(Error);
	void addTimeLimitItem(Item* pItem, DWORD time) throw(Error);
	void sellItem( Item* pItem ) throw(Error);
	void deleteItemByMorph( Item* pItem ) throw(Error);
	void loadTimeLimitItem() throw(Error);

//////////////////////////////////////////////////////////////
// ���� ��ǰ ������ ���� �Լ�
//////////////////////////////////////////////////////////////
public:
	void loadGoods() throw(Error);

//////////////////////////////////////////////////////////////
// ����Ʈ �Ŵ��� ���� �Լ�
//////////////////////////////////////////////////////////////
public:
	QuestManager*	getQuestManager() const { return m_pQuestManager; }
	void			sendCurrentQuestInfo() const throw(Error);

	virtual	int		getQuestLevel() const = 0;
	virtual void	whenQuestLevelUpgrade();

////////////////////////////////////////////////////////////
// �κ��丮 ���� �޽���
////////////////////////////////////////////////////////////
public:
	virtual Inventory* getInventory() const throw() { return m_pInventory; }
	virtual void setInventory(Inventory* pInventory) throw() { m_pInventory = pInventory; }

	virtual InventorySlot* getExtraInventorySlot() throw() { return m_pExtraInventorySlot; }
	virtual Item* getExtraInventorySlotItem() throw(Error) { return m_pExtraInventorySlot->getItem(); }
	virtual void deleteItemFromExtraInventorySlot() throw(Error) { m_pExtraInventorySlot->deleteItem(); }
	virtual void addItemToExtraInventorySlot(Item* pItem) throw(Error) { m_pExtraInventorySlot->addItem(pItem); }

	// 2003.04.04. by Sequoia
	virtual void loadItem() throw (InvalidProtocolException, Error);

	virtual GoodsInventory* getGoodsInventory() const throw() { return m_pGoodsInventory; }

////////////////////////////////////////////////////////////
// ������ ���� �޽���
////////////////////////////////////////////////////////////
public:
	virtual Stash* getStash(void) const throw() { return m_pStash; }
	virtual void setStash(Stash* pStash) throw() { m_pStash = pStash; }

	virtual BYTE getStashNum(void) const throw() { return m_StashNum; }
	virtual void setStashNum(BYTE num) throw() { m_StashNum = num; }
	virtual void setStashNumEx(BYTE num) throw();

	virtual Gold_t getStashGold(void) const throw() { return m_StashGold; }
	virtual void setStashGold(Gold_t gold) throw() { m_StashGold = gold; }
	virtual void setStashGoldEx(Gold_t gold) throw();
	virtual void increaseStashGoldEx(Gold_t gold) throw();
	virtual void decreaseStashGoldEx(Gold_t gold) throw();
	virtual bool checkStashGoldIntegrity() = 0;

	virtual bool getStashStatus(void) const throw() { return m_bStashStatus; }
	virtual void setStashStatus(bool s) throw() { m_bStashStatus = s; }

	virtual void deleteStash(void) throw();


////////////////////////////////////////////////////////////
// ������ ���� �޽���
////////////////////////////////////////////////////////////
public:
	void addItemToGarbage(Item* pItem) { m_Garbage.addItem(pItem); }
	void addItemToGarbageEx(Item* pItem) { m_Garbage.addItemEx(pItem, getName()); }
	Item* popItemFromGarbage(void) { return m_Garbage.popItem(); }
	void saveGarbage(void) { m_Garbage.save(getName()); }
	int getGarbageSize(void) { return m_Garbage.size(); }

////////////////////////////////////////////////////////////
// ������ �˻� �Լ�
////////////////////////////////////////////////////////////
public:
	virtual Item* findItemOID(ObjectID_t id) throw() = 0;
	virtual Item* findItemOID(ObjectID_t id, int& storage, int& x, int& y) throw() = 0;

	virtual Item* findItemIID(ItemID_t id) throw() = 0;
	virtual Item* findItemIID(ItemID_t id, int& storage, int& x, int& y) throw() = 0;

	virtual Item* findBeltOID(ObjectID_t id) throw() = 0;
	virtual Item* findBeltOID(ObjectID_t id, int& storage, int& x, int& y) throw() = 0;

	virtual Item* findBeltIID(ItemID_t id) throw() = 0;
	virtual Item* findBeltIID(ItemID_t id, int& storage, int& x, int& y) throw() = 0;


////////////////////////////////////////////////////////////
// �÷��� �� ���� �Լ�
////////////////////////////////////////////////////////////
public:
	FlagSet* getFlagSet(void) const throw() { return m_pFlagSet; }
	void setFlagSet(FlagSet* pSet) throw() { m_pFlagSet = pSet; } 
	void deleteFlagSet(void) throw();


////////////////////////////////////////////////////////////
// ��Ÿ �Լ�
////////////////////////////////////////////////////////////
public:
	virtual Fame_t getFame() const throw() = 0;
	virtual void setFame(Fame_t fame) throw() = 0;

	virtual Gold_t getGold() const throw() = 0;
	virtual void setGold(Gold_t gold) throw() = 0;
	virtual void setGoldEx(Gold_t gold) throw() = 0;
	virtual void   increaseGoldEx(Gold_t gold) throw() = 0;
    virtual void   decreaseGoldEx(Gold_t gold) throw() = 0;
	virtual bool checkGoldIntegrity() = 0;
	bool checkDBGold( Gold_t gold )
	{
		Gold_t temp = getGold();
		setGold(gold);
		bool ret = checkGoldIntegrity();
		setGold(temp);
		return ret;
	}


	virtual Sex	getSex() const throw() = 0;

	virtual ZoneID_t getResurrectZoneID(void) const throw() = 0;
	virtual void setResurrectZoneID(ZoneID_t id) throw() = 0;
	virtual void setResurrectZoneIDEx(ZoneID_t id) throw() = 0;

	//virtual Race_t getRace() const = 0; - Creature�� �÷ȴ�.
	virtual GuildID_t getCommonGuildID() const = 0;

	virtual IP_t getIP(void) const = 0;


////////////////////////////////////////////////////////////
// ���� �ý��� ����
////////////////////////////////////////////////////////////
	// enemy specific methods
	void addEnemy(const string& Name) throw(Error);
	void deleteEnemy(const string& Name) throw(NoSuchElementException, Error);

	// �� Ư� �����ڰ� �̹� ����� �Ͽ��°�?
	bool hasEnemy(const string& Name) const throw();
	uint getMaxEnemies() const throw();

	list<string>& getEnemies(void) throw() { return m_Enemies;}

	bool isPK() throw() { return m_isPK; }

	void setPK(bool isPK) throw() { m_isPK = isPK; }

	void setGuildID( GuildID_t GuildID ) throw() { m_GuildID = GuildID; }
	GuildID_t getGuildID() const throw() { return m_GuildID; }

	string getGuildName() const throw();
	GuildMemberRank_t getGuildMemberRank() const throw();

	Rank_t  	getRank() const throw();
	RankExp_t   getRankExp() const throw();
	RankExp_t   getRankGoalExp() const throw();

//	virtual Rank_t getRank() const throw() = 0;
	void increaseRankExp(RankExp_t Point);

	WORD getRankExpSaveCount(void) const { return m_RankExpSaveCount; }
	void setRankExpSaveCount(WORD count) { m_RankExpSaveCount = count; }

	virtual Alignment_t getAlignment() const throw()=0;
	virtual void setAlignment(Alignment_t Alignment) throw()=0;

////////////////////////////////////////////////////////////
// Rank Bonus ����
////////////////////////////////////////////////////////////
	void loadRankBonus() throw();
	bool hasRankBonus( RankBonus::RankBonusType type ) throw() { return m_RankBonusFlag.test(type); }
	RankBonus* getRankBonus( RankBonus::RankBonusType type ) const throw();
	RankBonus* getRankBonusByRank( Rank_t rank ) const throw();
	bool learnRankBonus( DWORD type ) throw();
	void clearRankBonus() throw();
	void clearRankBonus( Rank_t rank ) throw();
	HashMapRankBonus& getRankBonuses() { return m_RankBonuses; }

	void sendRankBonusInfo() throw();

protected:
	void addRankBonus( RankBonus* rankBonus ) throw();

public :
	// by sigi. 2002.11.19
	bool isBillingPlayAvaiable() throw(Error);
	virtual bool isPayPlayAvaiable() throw(Error);
	virtual bool canPlayFree() throw(Error);

public:
	Item*	getQuestItem() const { return m_pQuestItem; }
	void	setQuestItem( Item* pItem ) { m_pQuestItem = pItem; }

public :
	// by sigi. 2002.12.3
/*	void	loadQuest() throw (Error);
	bool 	hasQuest() const 	{ return m_pQuestManager!=NULL && !m_pQuestManager->isEmpty(); }
	bool 	addQuest(Quest* pQuest) throw (Error);
	bool 	checkEvent(QuestEvent* pQuest) throw (Error);
	Quest* 	removeCompleteQuest() throw (Error);
	void 	removeAllQuest() throw (Error)	{ if (m_pQuestManager!=NULL) m_pQuestManager->release(); }*/

	virtual void initAllStatAndSend() = 0;
	virtual void initAllStat(int numPartyMember) throw() = 0;

	void heartbeat(const Timeval& currentTime) throw();

////////////////////////////////////////////////////////////
// ���� ������
////////////////////////////////////////////////////////////
protected:
	Inventory*     m_pInventory;          // �κ��丮 ������
	InventorySlot* m_pExtraInventorySlot; // ���콺 ������

	GoodsInventory* m_pGoodsInventory;    // ���� ������ �κ��丮

	Stash*         m_pStash;              // ������ ������
	BYTE           m_StashNum;            // �������� ����
	Gold_t         m_StashGold;           // ������ ���� �� �׼�
	bool           m_bStashStatus;        // ������ ������ OID ���� ����

	Garbage        m_Garbage;             // ������...

	FlagSet*       m_pFlagSet;            // �÷��� ����

	// ���� ������ �������� �̸�� �����Ѵ�.
	// ObjectID�� ������ ���� �����, �׾ �ٽ� ��� �������� ������� �ʱ� ������ �̸���� �������ش�.
    list<string> m_Enemies;

	// PK�� ���ߴ�� �ƴϳĸ� �����Ѵ�.
	bool m_isPK;

	// GuildID
	GuildID_t		m_GuildID;

	// Rank Bonus map
	HashMapRankBonus m_RankBonuses;
	bitset<RankBonus::RANK_BONUS_MAX> m_RankBonusFlag;

	Rank*	m_pRank;
	WORD	m_RankExpSaveCount;

//	QuestManager*	m_pQuestManager;
	QuestManager*			m_pQuestManager;
	TimeLimitItemManager*	m_pTimeLimitItemManager;

	Item*					m_pQuestItem;
	vector<Item*>			m_PetStash;		// pet ������

public:
	/////////////////////////////////////////////////////////
	// pet �����Ͽ� ���õ� method
	/////////////////////////////////////////////////////////
	Item*				getPetStashItem(int idx);	
	void				addPetStashItem(int idx, Item* pPetItem);

	/////////////////////////////////////////////////////////
	// BloodBible ���� ���ʽ� ��ġ��
	/////////////////////////////////////////////////////////
public:
	int					getConsumeMPRatio() const { return m_ConsumeMPRatio; }
	void				setConsumeMPRatio( int ratio ) { m_ConsumeMPRatio = ratio; }

	int					getGamblePriceRatio() const { return m_GamblePriceRatio; }
	void				setGamblePriceRatio( int ratio ) { m_GamblePriceRatio = ratio; }

	int					getPotionPriceRatio() const { return m_PotionPriceRatio; }
	void				setPotionPriceRatio( int ratio ) { m_PotionPriceRatio = ratio; }

	Damage_t			getMagicBonusDamage() const { return m_MagicBonusDamage; }
	void				setMagicBonusDamage( Damage_t damage ) { m_MagicBonusDamage = damage; }

	Damage_t			getPhysicBonusDamage() const { return m_PhysicBonusDamage; }
	void				setPhysicBonusDamage( Damage_t damage ) { m_PhysicBonusDamage = damage; }

/*	bool				isEmptyItemNameInfoList() { return m_ItemNameInfoList.empty(); }
	void				clearItemNameInfoList() { m_ItemNameInfoList.clear(); }
	const list<ItemNameInfo*>& getItemNameInfoList() const { return m_ItemNameInfoList; }
	void				addItemNameInfoList( ItemNameInfo* itemNameInfo ) { m_ItemNameInfoList.push_back(itemNameInfo); }
	bool				deleteItemNameInfoList( ObjectID_t objectID ) throw(Error);
	string				getItemName( ObjectID_t objectID ) throw(Error);*/

protected:
	int						m_ConsumeMPRatio;
	int						m_GamblePriceRatio;
	int						m_PotionPriceRatio;
	Damage_t				m_MagicBonusDamage;
	Damage_t				m_PhysicBonusDamage;

//	list<ItemNameInfo*> 	m_ItemNameInfoList;

// �������� ��÷ ���θ� �����ϱ� ��� ��¿ �� ���� ���� �߰��ؾ� �ɵ�

public:
	DWORD				getLottoRewardID() const { return m_LottoRewardID; }
	void				setLottoRewardID( DWORD lottoRewardID ) { m_LottoRewardID = lottoRewardID; }

	DWORD				getLottoQuestLevel() const { return m_LottoQuestLevel; }
	void 				setLottoQuestLevel( DWORD lottoQuestLevel ) { m_LottoQuestLevel = lottoQuestLevel; }

	bool				isLotto() const { return m_bLotto; }
	void				setLotto( bool lotto ) { m_bLotto = lotto; }

protected:
	DWORD				m_LottoRewardID;
	DWORD				m_LottoQuestLevel;
	bool				m_bLotto;

	//////////////////////////////////////////////
	// Default Option Set Info
	//////////////////////////////////////////////
public:
	void	addDefaultOptionSet( DefaultOptionSetType_t type ) throw();
	void	removeDefaultOptionSet( DefaultOptionSetType_t type ) throw();

protected:
	list<DefaultOptionSetType_t>		m_DefaultOptionSet;

public:
	PetInfo*	getPetInfo() const;
	void		setPetInfo(PetInfo* pPetInfo);

	list<PetItem*>& getPetItems() { return m_PetItems; }
	const list<PetItem*>& getPetItems() const { return m_PetItems; }

	Pet*		getPet() const { return m_pPet; }

protected:
	PetInfo* m_pPetInfo;
	list<PetItem*> m_PetItems;
	Pet*	m_pPet;

	// 2�� �� ����Ʈ ���� 
public:
	SpriteType_t	getTargetMonsterSType() const { return m_TargetMonster; }
	virtual void	initPetQuestTarget() = 0;
	GCMonsterKillQuestInfo::QuestInfo*	getPetQuestInfo() const;

protected:
	SpriteType_t	m_TargetMonster;
	DWORD			m_TargetNum;
	DWORD			m_TimeLimit;
};

#endif
