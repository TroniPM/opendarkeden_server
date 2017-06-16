//////////////////////////////////////////////////////////////////////////////
// Filename    : Vampire.h
// Written By  : Elca
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__

#include "PlayerCreature.h"
#include "Inventory.h"
#include "Zone.h"
#include "PCVampireInfo.h"
#include "PCVampireInfo2.h"
#include "PCVampireInfo3.h"
#include "InventoryInfo.h"
#include "GearInfo.h"
#include "ExtraInfo.h"
#include "OptionInfo.h"
#include "VampireSkillInfo.h"
#include "Mutex.h"
#include "ModifyInfo.h"
#include "CreatureUtil.h"
//#include "RankExpTable.h"
#include <map>

#include "skill/VampireSkillSlot.h"

#include "Gpackets/GCModifyInformation.h"

#define VAMPIRE_MAX_LEVEL				150		//abcd
#define VAMPIRE_MAX_RANK				50		// ���� max
#define BONUS_POINTS_PER_LEVEL1			3		// �������� �־����� �ɷ�ġ point
#define BONUS_POINTS_PER_LEVEL2			2		// �������� �־����� �ɷ�ġ point
#define BONUS_POINTS_PER_LEVEL3			1		// �������� �־����� �ɷ�ġ point

////////////////////////////////////////////////////////////////////////////////
// ������ �԰� ��� �� ���� �԰� ���� ���� �ɷ�ġ�� 
// ������ �α� ��� ����(?) Ŭ����
////////////////////////////////////////////////////////////////////////////////

class VAMPIRE_RECORD
{
public:
	Attr_t       pSTR[3];
	Attr_t       pDEX[3];
	Attr_t       pINT[3];
	Rank_t    	 Rank;
	HP_t         pHP[2];
	Damage_t     pDamage[2];
	Defense_t    Defense;
	Protection_t Protection;
	ToHit_t      ToHit;
	Speed_t      AttackSpeed;
};

////////////////////////////////////////////////////////////////////////////////
//
// Class Vampire;
//
////////////////////////////////////////////////////////////////////////////////

class Vampire : public PlayerCreature 
{

////////////////////////////////////////////////////
// Ŭ���� ���� ���� ����
////////////////////////////////////////////////////
public:
public:
	// ���� ���
	enum WearPart
	{ 
		WEAR_NECK, 
		WEAR_BODY, 
		WEAR_WRIST1, 
		WEAR_WRIST2, 
		WEAR_FINGER1,
		WEAR_FINGER2, 
		WEAR_FINGER3, 
		WEAR_FINGER4, 
		WEAR_EARRING1,
		WEAR_EARRING2,
		WEAR_LEFTHAND,
		WEAR_RIGHTHAND,
		WEAR_AMULET1,
		WEAR_AMULET2,
		WEAR_AMULET3,
		WEAR_AMULET4,
		VAMPIRE_WEAR_MAX 
	};

	
////////////////////////////////////////////////////
// ������/�Ҹ���
////////////////////////////////////////////////////
public:
	Vampire() throw();
	virtual ~Vampire() throw ();

////////////////////////////////////////////////////
// ��� Ŭ����(Creature) ���� �Լ�
////////////////////////////////////////////////////
public:
	virtual CreatureClass getCreatureClass() const throw() { return CREATURE_CLASS_VAMPIRE; }
	virtual string getCreatureClassString() const throw() { return "CREATURE_CLASS_VAMPIRE"; }

	virtual void registerObject() throw(Error);
	virtual void registerInitObject() throw(Error);

	virtual bool load() throw (InvalidProtocolException, Error);
	void loadItem( bool checkTimeLimit = false ) throw (InvalidProtocolException, Error);

	virtual void save() const throw (Error);
	virtual void tinysave(const string & field) const throw (Error);
//	virtual void tinysave(const char* field) const throw (Error);
	void saveSkills(void) const throw (Error);
	void saveGears(void) const throw (Error);
	void saveExps(void) const throw (Error);

	virtual void act(const Timeval& currentTime) throw(Error) {}

	virtual string toString() const throw();

	virtual Race_t getRace() const { return RACE_VAMPIRE; }
	virtual GuildID_t getCommonGuildID() const { return VampireCommon; }


//////////////////////////////////////////////////////////////
// �ð���� ������ ���� �Լ�
//////////////////////////////////////////////////////////////
public:
	void checkItemTimeLimit() throw (Error);


////////////////////////////////////////////////////
// ���� ���� �Լ�(Dead or Alive!)
////////////////////////////////////////////////////
public:
	bool isAlive() const throw() { return m_HP[ATTR_CURRENT] != 0; }
	bool isDead() const throw() { return m_HP[ATTR_CURRENT] == 0; }


////////////////////////////////////////////////////
// �Ѹ��� ���� �Լ�(�̸�, ����, ����, �Ӹ�, �Ǻ�)
////////////////////////////////////////////////////
public:
	const string& getName() const throw() { return m_Name; }
	void setName(const string & name) throw() { m_Name = name; m_Owner = name; }

	BYTE getCompetence() const throw() { return m_Competence; }
	void setCompetence(BYTE Competence) { m_Competence = Competence; }

	BYTE getCompetenceShape() const throw() { return m_CompetenceShape; }
	void setCompetenceShape(BYTE CompetenceShape) { m_CompetenceShape = CompetenceShape; }

	Sex getSex() const throw() { return m_Sex; }
	void setSex(Sex sex) throw() { m_Sex = sex; m_VampireInfo.setSex(sex); }
	void setSex(const string & sex) throw(InvalidProtocolException) 
	{
		if(sex == Sex2String[MALE])
			setSex(MALE);
		else if(sex == Sex2String[FEMALE])
			setSex(FEMALE);
		else throw InvalidProtocolException("invalid sex");
	}

	Color_t getBatColor() const throw() { return m_BatColor; }
	void setBatColor(Color_t batColor) throw() { m_BatColor = batColor; }

	Color_t getSkinColor() const throw() { return m_SkinColor; }
	void setSkinColor(Color_t skinColor) throw() { m_SkinColor = skinColor; }

////////////////////////////////////////////////////
// �ɷ�ġ ���� �Լ�(STR, DEX, INT)
////////////////////////////////////////////////////
public:

	Alignment_t getAlignment() const throw() { return m_Alignment; }
	void setAlignment(Alignment_t Alignment) throw() { m_Alignment = Alignment; }
	void saveAlignment(Alignment_t alignment) throw();

	Attr_t getSTR(AttrType attrType = ATTR_CURRENT) const throw() { return m_STR[attrType]; }
	void setSTR(Attr_t attr, AttrType attrType = ATTR_CURRENT) throw() { m_STR[attrType] = attr; }
	
	Attr_t getDEX(AttrType attrType = ATTR_CURRENT) const throw() { return m_DEX[attrType]; }
	void setDEX(Attr_t attr, AttrType attrType = ATTR_CURRENT) throw() { m_DEX[attrType] = attr; }

	Attr_t getINT(AttrType attrType = ATTR_CURRENT) const throw() { return m_INT[attrType]; }
	void setINT(Attr_t attr, AttrType attrType = ATTR_CURRENT) throw() { m_INT[attrType] = attr; }

////////////////////////////////////////////////////
// �ɷ�ġ ���� �Լ�(HP)
////////////////////////////////////////////////////
public:
	HP_t getHP(AttrType attrType = ATTR_CURRENT) const throw() { return m_HP[attrType]; }
	void setHP(HP_t hp, AttrType attrType = ATTR_CURRENT) throw() { m_HP[attrType] = hp; }
	void setHP(HP_t current, HP_t max) throw() { m_HP[ATTR_CURRENT] = current; m_HP[ATTR_MAX] = max; }

////////////////////////////////////////////////////
// �ɷ�ġ ���� �Լ�(Damage, Protect, Defense, ToHit)
////////////////////////////////////////////////////
public:
	Damage_t     getDamage(AttrType attrType = ATTR_CURRENT) const throw() { return m_Damage[attrType]; }
	Protection_t getProtection(void) const throw() { return m_Protection[ATTR_CURRENT]; }
	Defense_t    getDefense(void) const throw() { return m_Defense[ATTR_CURRENT]; }
	ToHit_t      getToHit(void) const throw() { return m_ToHit[ATTR_CURRENT]; }
	Speed_t      getAttackSpeed(void) const throw() { return m_AttackSpeed[ATTR_CURRENT]; }
	
////////////////////////////////////////////////////
// ����ġ ���� �Լ�
////////////////////////////////////////////////////
public:
//	Exp_t getExp() const throw() { return m_Exp; }
//	void  setExp(Exp_t exp) throw() { m_Exp = exp; }

	Exp_t getGoalExp() const throw() { return m_GoalExp; }
	void  setGoalExp(Exp_t GoalExp) throw() { m_GoalExp = GoalExp; }

//	Exp_t getExpOffset() const throw() { return m_ExpOffset; }
//	void  setExpOffset(Exp_t expOffset) throw() { m_ExpOffset = expOffset; }

//	void setExp(Exp_t exp, Exp_t expOffset) throw() { m_Exp = exp; m_ExpOffset = expOffset; }

	Level_t getLevel() const throw() { return m_Level; }
	void    setLevel(Level_t level) throw() { m_Level = level; }

	int		getQuestLevel() const { return getLevel(); }

	// ����. by sigi. 2002.8.30
/*	Rank_t  getRank() const throw() { return m_Rank; }
//	void    setRank(Rank_t rank) throw() { m_Rank = rank; }
	RankExp_t   getRankExp() const throw() { return m_RankExp; }
//	void    setRankExp(RankExp_t exp) throw() { m_RankExp = exp; }
	RankExp_t   getRankGoalExp() const throw() { return m_RankGoalExp; }
//	void    setRankGoalExp(RankExp_t RankGoalExp) throw() { m_RankGoalExp = RankGoalExp; }*/


	Bonus_t getBonus() const throw() { return m_Bonus; }
	void    setBonus(Bonus_t bonus) throw() { m_Bonus = bonus; }

////////////////////////////////////////////////////
// ��ų ���� �Լ�
////////////////////////////////////////////////////
public:
	void addSkill(SkillType_t SkillType) throw();
    void addSkill(VampireSkillSlot* pSkillSlot) throw();
	void removeCastleSkill(SkillType_t SkillType) throw();
	void removeAllCastleSkill() throw();
	VampireSkillSlot* hasSkill(SkillType_t SkillType) const throw() { return getSkill(SkillType); }
	VampireSkillSlot* getSkill(SkillType_t SkillType) const throw();

//	void setHotKey(BYTE pos, SkillType_t SkillType) throw() { m_HotKey[pos] = SkillType; }
//	SkillType_t getHotKey(BYTE pos) const throw() { return m_HotKey[pos]; }


////////////////////////////////////////////////////
// ������ ��/Ż ���� �Լ�
////////////////////////////////////////////////////
public:
	bool  isWear(WearPart Part) throw() { return m_pWearItem[Part] != NULL ? true : false; }
	void  addWearItem(WearPart Part, Item* pItem) throw() { Assert(m_pWearItem[Part] != NULL); m_pWearItem[Part] = pItem; }
	void  deleteWearItem(WearPart Part) throw() { m_pWearItem[Part] = NULL; }
	Item* getWearItem(WearPart Part) throw() { return m_pWearItem[Part]; }

	void wearItem(WearPart Part) throw();
	void wearItem(WearPart Part, Item* pItem) throw();
	void takeOffItem(WearPart Part, bool bAddOnMouse, bool bSendModifyInfo) throw();
	//WearPart getWearPart(Item::ItemClass IClass) const;
	//bool    changeShape(Item* pItem, Color_t color);
	bool    addShape(Item::ItemClass IClass, ItemType_t IType, Color_t color);
    bool    removeShape(Item::ItemClass IClass, bool bSendPacket=true);
	Color_t getItemShapeColor(Item* pItem, OptionInfo* pOptionInfo=NULL) const;


	void destroyGears() throw();

	bool isRealWearing(WearPart Part) const throw();
	bool isRealWearing(Item* pItem) const throw();
	bool isRealWearingEx(WearPart Part) const;
	DWORD sendRealWearingInfo(void) const throw();

	void  getShapeInfo (DWORD& flag, Color_t color[PCVampireInfo::VAMPIRE_COLOR_MAX]) const;

////////////////////////////////////////////////////
// ������ ��/Ż�� �ɷ�ġ ��� ���� �Լ�
////////////////////////////////////////////////////
public:
	void initAllStat(int numPartyMember=-1) throw();
	void initCastleSkill() throw();
	void sendModifyInfo(const VAMPIRE_RECORD& previous) const throw();
	void addModifyInfo(const VAMPIRE_RECORD& previous, ModifyInfo& pkt) const throw();
	void initAllStatAndSend();
	
private:
	void computeStatOffset(void) throw();
	void computeItemStat(Item* pItem) throw();
	void computeOptionStat(Item* pItem) throw();
	void computeOptionStat(OptionType_t optionType) throw();
	void computeOptionClassStat(OptionClass OClass, int PlusPoint);


//////////////////////////////////////////////////////////////
// ������ �˻� �Լ�
//////////////////////////////////////////////////////////////
public:

	virtual Item* findItemOID(ObjectID_t id) throw() { return ::findItemOID(this, id); }
	virtual Item* findItemOID(ObjectID_t id, int& storage, int& x, int& y) throw() { return ::findItemOID(this, id, storage, x, y); }

	virtual Item* findItemIID(ItemID_t id) throw() { return ::findItemIID(this, id); }
	virtual Item* findItemIID(ItemID_t id, int& storage, int& x, int& y) throw() { return ::findItemIID(this, id, storage, x, y); }

	virtual Item* findBeltOID(ObjectID_t id) throw() { return ::findItemOID(this, id, Item::ITEM_CLASS_BELT); }
	virtual Item* findBeltOID(ObjectID_t id, int& storage, int& x, int& y) throw() { return ::findItemOID(this, id, Item::ITEM_CLASS_BELT, storage, x, y); }

	virtual Item* findBeltIID(ItemID_t id) throw(){ return ::findItemIID(this, id, Item::ITEM_CLASS_BELT); }
	virtual Item* findBeltIID(ItemID_t id, int& storage, int& x, int& y) throw(){ return ::findItemIID(this, id, Item::ITEM_CLASS_BELT, storage, x, y); }

////////////////////////////////////////////////////
// ���� ���� �Լ�
////////////////////////////////////////////////////
public:

	PCVampireInfo2* getVampireInfo2() throw();
	PCVampireInfo3  getVampireInfo3() const throw();
	InventoryInfo*  getInventoryInfo() const throw();
	GearInfo*       getGearInfo() const throw();
	ExtraInfo*      getExtraInfo() const throw();
	void sendVampireSkillInfo() throw();


////////////////////////////////////////////////////
// ��Ÿ �Լ�
////////////////////////////////////////////////////
public:

	virtual Gold_t getGold() const throw() { return m_Gold; }
	virtual void setGold(Gold_t gold) throw();
	virtual void setGoldEx(Gold_t gold) throw();
	virtual void   increaseGoldEx(Gold_t gold) throw();
    virtual void   decreaseGoldEx(Gold_t gold) throw();
	virtual bool checkGoldIntegrity();
	virtual bool checkStashGoldIntegrity();

	void setInMagics(const string & blob) throw() {}

	void heartbeat(const Timeval& currentTime) throw();

	void getVampireRecord(VAMPIRE_RECORD& record) const throw();

	virtual Fame_t getFame() const throw() { return m_Fame; }
	virtual void   setFame(Fame_t fame) throw() { m_Fame = fame; }

	virtual ZoneID_t getResurrectZoneID(void) const throw() { return m_ResurrectZoneID; }
	virtual void setResurrectZoneID(ZoneID_t id) throw() { m_ResurrectZoneID = id; }
	virtual void setResurrectZoneIDEx(ZoneID_t id) throw();

	Silver_t getSilverDamage() const throw() { return m_SilverDamage; }
	void setSilverDamage(Silver_t damage) throw() { m_SilverDamage = damage; }
	void saveSilverDamage(Silver_t damage) throw();

	virtual Steal_t getHPStealAmount(void) const { return m_HPStealAmount; }
	virtual void setHPStealAmount(Steal_t steal) { m_HPStealAmount = steal; }

	virtual Steal_t getHPStealRatio(void) const { return m_HPStealRatio; }
	virtual void setHPStealRatio(Steal_t steal) { m_HPStealRatio = steal; }

	virtual Regen_t getHPRegen(void) const { return m_HPRegen; }
	virtual void setHPRegen(Regen_t regen) { m_HPRegen = regen; }

	virtual Luck_t getLuck(void) const { return m_Luck; }
	virtual void setLuck(Luck_t luck) { m_Luck = luck; }


	virtual int getCriticalRatio(void) const { return m_CriticalRatio[ATTR_CURRENT]; }
	virtual void setCriticalRatio(int ratio) { m_CriticalRatio[ATTR_CURRENT] = ratio; }

	virtual IP_t getIP(void) const;

	virtual ClanType_t getClanType(void) const { return m_ClanType; }
	virtual void setClanType(ClanType_t clan) { m_ClanType = clan; }

//	WORD getRankExpSaveCount(void) const { return m_RankExpSaveCount; }
//	void setRankExpSaveCount(WORD count) { m_RankExpSaveCount = count; }

	WORD getExpSaveCount(void) const { return m_ExpSaveCount; }
	void setExpSaveCount(WORD count) { m_ExpSaveCount = count; }

	WORD getFameSaveCount(void) const { return m_FameSaveCount; }
	void setFameSaveCount(WORD count) { m_FameSaveCount = count; }

	WORD getAlignmentSaveCount(void) const { return m_AlignmentSaveCount; }
	void setAlignmentSaveCount(WORD count) { m_AlignmentSaveCount = count; }

//	void increaseVampExp(Exp_t Point);
//	void increaseRankExp(RankExp_t Point);

	void saveInitialRank(void) throw();

public :
	 // by sigi. 2002.11.19
	virtual bool isPayPlayAvaiable() throw(Error);
	virtual bool canPlayFree() throw(Error);

	void	initPetQuestTarget();

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
	
private:

	// PC Name
	string m_Name;

	// ����
	BYTE m_Competence;
	BYTE m_CompetenceShape;

	// Sex, Color
	Sex m_Sex;
	Color_t m_BatColor;
	Color_t m_SkinColor;

	// Alignment
	Alignment_t m_Alignment;

	// STR/DEX/INT
	Attr_t m_STR[3];
	Attr_t m_DEX[3];
	Attr_t m_INT[3];

	// HP
	HP_t m_HP[3];

	Damage_t     m_Damage[3];
	ToHit_t      m_ToHit[2];
	Defense_t    m_Defense[2];
	Protection_t m_Protection[2];
	Speed_t      m_AttackSpeed[2];
	int          m_CriticalRatio[2];

	// Exp/ExpOffset
//	Exp_t m_Exp;
//	Exp_t m_ExpOffset;

	// Gaol Exp
	Exp_t m_GoalExp;

	// level
	Level_t m_Level;

	// ����. by sigi. 2002.8.30
//	Rank_t 		m_Rank;
//	RankExp_t 	m_RankExp;
//	RankExp_t 	m_RankGoalExp;

//	Rank*		m_pRank;

	// exp bonus
	Bonus_t m_Bonus;

	// gold
	Gold_t m_Gold;

	Fame_t m_Fame;

	ZoneCoord_t m_VisionWidth;
	ZoneCoord_t m_VisionHeight;

	// SkillSlot
	//VampireSkillSlot* m_pSkillSlot[MAX_VAMPIRE_SKILL_SLOT];
	map<SkillType_t, VampireSkillSlot*> m_SkillSlot;

	// WearItem Field
	Item* m_pWearItem[VAMPIRE_WEAR_MAX];
	bool m_pRealWearingCheck[VAMPIRE_WEAR_MAX];

	// Vampire Outlook Information
	mutable PCVampireInfo3 m_VampireInfo;

	// Hot Key Set
//	SkillType_t m_HotKey[8];

	// mutable Thread Mutex
	mutable Mutex m_Mutex;

	// ��Ȱ� ����
	ZoneID_t m_ResurrectZoneID;

	// � ���� ������ ����
	Silver_t m_SilverDamage;

	// HP ��ƿ
	Steal_t m_HPStealAmount;
	Steal_t m_HPStealRatio;

	// HP ����
	Regen_t m_HPRegen;

	// HP ���� ���ʽ� ����Ʈ. �ʴ� �ö󰡴� ���ʽ� ����Ʈ
	Regen_t m_HPRegenBonus;

	Luck_t m_Luck;

	Timeval m_HPRegenTime;

	ClanType_t m_ClanType;

	// ��� ����ġ ���̺� ī��Ʈ
//	WORD m_RankExpSaveCount;
	WORD m_ExpSaveCount;
	WORD m_FameSaveCount;
	WORD m_AlignmentSaveCount;
};


#endif // __VAMPIRE_H__
