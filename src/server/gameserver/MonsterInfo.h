//////////////////////////////////////////////////////////////////////////////
// Filename    : MonsterInfo.h
// Written By  : �輺��
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __MONSTERINFO_H__
#define __MONSTERINFO_H__

#include "Types.h"
#include "Exception.h"
#include "Assert.h"
#include "Creature.h"
#include "MonsterSummonInfo.h"
#include "MonsterInfoTypes.h"
#include "Treasure.h"
#include <list>
#include <vector>
#include <map>

// ���� �������Ʈ ��� �ִ� ����
const int MAX_SPRITE_TYPE = 200;

//////////////////////////////////////////////////////////////////////////////
// �����Ͱ� ������ �� �ִ� ���� �ִ� ����, �Ǵ� ���� ����Ʈ�� ����ϴ� �ε���
//////////////////////////////////////////////////////////////////////////////
enum EnemyPriority 
{
	ENEMY_PRIMARY = 1 ,
	ENEMY_SECONDARY ,
	ENEMY_THIRD ,
	ENEMY_FOURTH ,
	ENEMY_FIFTH ,
	ENEMY_SIXTH ,
	ENEMY_SEVENTH ,
	ENEMY_EIGHTH ,
	ENEMY_MAX
};


//////////////////////////////////////////////////////////////////////////////
// ���� �������� ��, ������ ���� �����ϴ°�?
//////////////////////////////////////////////////////////////////////////////
enum AttackOrder 
{
	ATTACK_FIRST,          // ��� ���� ���� ������ ����
	ATTACK_LAST,           // ��� ���߿� ���� �� ���� ����
	ATTACK_WEAKEST,        // ��� ���� ������ ����
	ATTACK_STRONGEST,      // ��� ���� ������ ����
	ATTACK_CLOSEST,        // ��� ������ �� ���� ����
	ATTACK_FAREST,         // ��� �� �� ���� ����
	ATTACK_FIGHTER,        // ���� ���� ����
	ATTACK_PRIEST,         // ������ ���� ����
	ATTACK_GUNNER,         // �ǳ� ���� ����
	ATTACK_MAX
};

const string AttackOrder2String[] = 
{
	"ATTACK_FIRST" ,
	"ATTACK_LAST" ,
	"ATTACK_WEAKEST" ,
	"ATTACK_STRONGEST" ,
	"ATTACK_CLOSEST" ,
	"ATTACK_FAREST" ,
	"ATTACK_FIGHTER" ,
	"ATTACK_PRIEST" ,
	"ATTACK_GUNNER" ,
	"ATTACK_BOMBER"
};


//////////////////////////////////////////////////////////////////////////////
// ������ ���� - �����ʹ� PC�� ���� ��� �����ϴ°�?
//////////////////////////////////////////////////////////////////////////////
enum MAlignment 
{
    ALIGNMENT_FRIENDLY ,
    ALIGNMENT_NEUTRAL ,
    ALIGNMENT_AGGRESSIVE
};

const string MAlignment2String[] = 
{
	"ALIGNMENT_FRIENDLY" ,
    "ALIGNMENT_NEUTRAL" ,
    "ALIGNMENT_AGGRESSIVE"
};


//////////////////////////////////////////////////////////////////////////////
// AI Level - �����ʹ� �󸶳� �ȶ��Ѱ�?
//////////////////////////////////////////////////////////////////////////////
enum AILevel 
{
	AI_VERY_LOW ,		//   1 - 50
	AI_LOW ,			//  51 - 100
	AI_MEDIUM ,			// 101 - 150
	AI_HIGH ,			// 151 - 200
	AI_VERY_HIGH 		// 201 - 250
};

//////////////////////////////////////////////////////////////////////////////
// Body Size - �������� ���� ũ��
//////////////////////////////////////////////////////////////////////////////
enum BodySize
{
	BODYSIZE_SMALL = 0,
	BODYSIZE_MEDIUM,
	BODYSIZE_LARGE
};

//////////////////////////////////////////////////////////////////////////////
// class MonsterInfo
//////////////////////////////////////////////////////////////////////////////

class MonsterInfo 
{
public:
	MonsterInfo() throw();
	~MonsterInfo() throw();

public:
	MonsterType_t getMonsterType() const { return m_MonsterType; }
	void setMonsterType(MonsterType_t spriteType) { m_MonsterType = spriteType; }

	SpriteType_t getSpriteType() const { return m_SpriteType; }
	void setSpriteType(SpriteType_t spriteType) { m_SpriteType = spriteType; }

	string getHName() const { return m_HName; }
	void setHName(const string & name) { m_HName = name; }

	string getEName() const { return m_EName; }
	void setEName(const string & name) { m_EName = name; }

	Level_t getLevel() const { return m_Level; }
	void setLevel(Level_t level) { m_Level = level; }

	Attr_t getSTR() const { return m_STR; }
	void setSTR(Attr_t str) { m_STR = str; }

	Attr_t getDEX() const { return m_DEX; }
	void setDEX(Attr_t dex) { m_DEX = dex; }

	Attr_t getINT() const { return m_INT; }
	void setINT(Attr_t inte) { m_INT = inte; }

	uint getBodySize() const { return m_BodySize; }
	void setBodySize(uint size) { m_BodySize = size; }

	HP_t getHP() const { return m_HP; }
	void setHP(HP_t hp) { m_HP = hp; }

	Exp_t getExp() const { return m_Exp; }
	void setExp(Exp_t exp) { m_Exp = exp; }

	Color_t getMainColor() const { return m_MainColor; }
	void setMainColor(Color_t mainColor) { m_MainColor = mainColor; }

	Color_t getSubColor() const { return m_SubColor; }
	void setSubColor(Color_t subColor) { m_SubColor = subColor; }

	MAlignment getAlignment() const { return m_Alignment; }
	void setAlignment(MAlignment alignment) { m_Alignment = alignment; }

	AttackOrder getAttackOrder() const { return m_AttackOrder; }
	void setAttackOrder(AttackOrder attackOrder) { m_AttackOrder = attackOrder; }

	Moral_t getMoral() const { return m_Moral; }
	void setMoral(Moral_t moral) { m_Moral = moral; }

	Turn_t getDelay() const { return m_Delay; }
	void setDelay(Turn_t delay) { m_Delay = delay; }

	Turn_t getAttackDelay() const { return m_AttackDelay; }
	void setAttackDelay(Turn_t delay) { m_AttackDelay = delay; }

	Sight_t getSight() const { return m_Sight; }
	void setSight(Sight_t sight) { m_Sight = sight; }

	int getMeleeRange(void) const { return m_MeleeRange; }
	void setMeleeRange(int range) { m_MeleeRange = range; }

	int getMissileRange(void) const { return m_MissileRange; }
	void setMissileRange(int range) { m_MissileRange = range; }

	Creature::MoveMode getMoveMode() const { return m_MoveMode; }
	void setMoveMode(Creature::MoveMode moveMode) { m_MoveMode = moveMode; }
	void setMoveMode(const string & moveMode) throw(Error);

	uint getAIType(void) const { return m_AIType;}
	void setAIType(uint aitype) { m_AIType = aitype;}

	int getEnhanceHP(void) const { return m_EnhanceHP; }
	int getEnhanceToHit(void) const { return m_EnhanceToHit; }
	int getEnhanceDefense(void) const { return m_EnhanceDefense; }
	int getEnhanceProtection(void) const { return m_EnhanceProtection; }
	int getEnhanceMinDamage(void) const { return m_EnhanceMinDamage; }
	int getEnhanceMaxDamage(void) const { return m_EnhanceMaxDamage; }
	void parseEnhanceAttr(const string& enhance) throw();

	void parseSlayerTreasureString(const string& text) throw();
	TreasureList* getSlayerTreasureList(void) const { return m_pSlayerTreasureList; }
	TreasureList* getSlayerTreasureList(void) { return m_pSlayerTreasureList; }
	void setSlayerTreasureList(TreasureList* pTreasureList) throw();

	void parseVampireTreasureString(const string& text) throw();
	TreasureList* getVampireTreasureList(void) const { return m_pVampireTreasureList; }
	TreasureList* getVampireTreasureList(void) { return m_pVampireTreasureList; }
	void setVampireTreasureList(TreasureList* pTreasureList) throw();

	void parseOustersTreasureString(const string& text) throw();
	TreasureList* getOustersTreasureList(void) const { return m_pOustersTreasureList; }
	TreasureList* getOustersTreasureList(void) { return m_pOustersTreasureList; }
	void setOustersTreasureList(TreasureList* pTreasureList) throw();

	RegenType selectRegenType() const;
	int getRegenType(RegenType rt) const				{ return m_RegenType[rt]; }
	void setRegenType(RegenType rt, int percent);

	int  getUnburrowChance(void) const { return m_UnburrowChance;}
	void setUnburrowChance(uint uc) { m_UnburrowChance = uc;}	// 0~128

	int  isMaster(void) const { return m_bMaster;}
	void setMaster(bool bMaster=true) { m_bMaster = bMaster;}

	int  getClanType(void) const { return m_ClanType;}
	void setClanType(int clanType) { m_ClanType = clanType;}

	void setMonsterSummonInfo(const string& text);
	bool getMonsterSummonInfo(int step, SUMMON_INFO2& summonInfo) const;
	bool hasNextMonsterSummonInfo(int step) const;

	void setDefaultEffects(const string& text);
	const list<Effect::EffectClass>& getDefaultEffects() const { return m_DefaultEffects; }
	void addDefaultEffects(Creature* pCreature) const;

	bool isChief(void) const { return m_bChief; }
	void setChief(bool flag) { m_bChief = flag; }

	bool  isNormalRegen(void) const { return m_bNormalRegen;}
	void setNormalRegen(bool bNormalRegen=true) { m_bNormalRegen = bNormalRegen;}

	bool  hasTreasure(void) const { return m_bHasTreasure;}
	void setHasTreasure(bool bHasTreasure=true) { m_bHasTreasure = bHasTreasure;}

	int  getMonsterClass(void) const { return m_MonsterClass;}
	void setMonsterClass(int mClass) { m_MonsterClass = mClass;}

	int  getSkullType(void) const { return m_SkullType;}
	void setSkullType(int skullType) { m_SkullType = skullType;}

	string toString() const throw();

private:
	MonsterType_t      m_MonsterType;               // ������ Ÿ��
	SpriteType_t       m_SpriteType;                // ���� �������Ʈ Ÿ��
	string             m_HName;                     // ������ �ѱ� �̸�
	string             m_EName;                     // ������ ���� �̸�
	Level_t            m_Level;                     // ������ ����
	Attr_t             m_STR;                       // �⺻ STR
	Attr_t             m_DEX;                       // �⺻ DEX
	Attr_t             m_INT;                       // �⺻ INT
	uint               m_BodySize;                  // �������� ũ��
	HP_t               m_HP;                        // ������
	Exp_t              m_Exp;                       // �׿�� �� PC �����̾ �޴� ����ġ (not used)
	Color_t            m_MainColor;                 // Main Color (not used)
	Color_t            m_SubColor;                  // Sub Color (not used)
	MAlignment         m_Alignment;                 // ����
	AttackOrder        m_AttackOrder;               // ���� ������ ���õ� ����
	Moral_t            m_Moral;                     // ����
	Turn_t             m_Delay;                     // ��� ����� �ϱ� ������ ������ �ð�.
	Turn_t             m_AttackDelay;               // ��� ����� �ϱ� ������ ������ �ð�.
	Sight_t            m_Sight;                     // �þ�
	int                m_MeleeRange;                // ����� ����Ÿ�
	int                m_MissileRange;              // �̻��� ����Ÿ�
	Creature::MoveMode m_MoveMode;                  // �̵� ����
	uint               m_AIType;                    // �ΰ����� Ÿ��
	int                m_EnhanceHP;                 // ü�� ��ȭ ����
	int                m_EnhanceToHit;              // ToHit ��ȭ ���
	int                m_EnhanceDefense;            // ���潺 ��ȭ ����
	int                m_EnhanceProtection;         // ����ؼ� ��ȭ ����
	int                m_EnhanceMinDamage;             // ������ ��ȭ ����
	int                m_EnhanceMaxDamage;             // ������ ��ȭ ����
	TreasureList*      m_pSlayerTreasureList;       // �����̾ ��� ������ ����Ʈ
	TreasureList*      m_pVampireTreasureList;      // �����̾ ��� ������ ����Ʈ
	TreasureList*      m_pOustersTreasureList;      // �ƿ콺��� ��� ������ ����Ʈ
	int   		       m_RegenType[REGENTYPE_MAX];	// �� ���������� Ȯ��
	int                m_UnburrowChance;            // ������ �Ŀ� ����� ���� Ȯ��
	bool               m_bMaster;                   // �����̾� �������ΰ�?
	int                m_ClanType;                    // ���� clan�� ���ϴ� �������ΰ�?
	MonsterSummonInfo* m_pMonsterSummonInfo;	    // ������ ��ȯ ���
	list<Effect::EffectClass> m_DefaultEffects;		// �����Ϳ��� �⺻����� �پ��ִ� ����Ʈ
	bool				m_bNormalRegen;		// ��� �ÿ� ���õǴ� ������ Ÿ���ΰ�?
	bool				m_bHasTreasure;		// Treasure.bin ȭ���� �ʿ��Ѱ�?
	bool				m_bChief;			// ġ�� �������ΰ�?

	int					m_MonsterClass;		// �������� Ŭ����
	ItemType_t			m_SkullType;		// �������� �ذ� Ÿ��
};


//////////////////////////////////////////////////////////////////////////////
// class MonsterInfoManager
//////////////////////////////////////////////////////////////////////////////

class MonsterInfoManager 
{
public:
	MonsterInfoManager() throw();
	~MonsterInfoManager() throw();

public:
	// initialize
	void init() throw(Error);

	// load to database
	void load() throw(Error);
	void reload(MonsterType_t monsterType) throw(Error);

	// add monster info with monster type
	void addMonsterInfo(MonsterType_t monsterType, MonsterInfo* pMonsterInfo) throw(DuplicatedException, OutOfBoundException, Error);

	// get monster info with monster type
	const MonsterInfo* getMonsterInfo(MonsterType_t monsterType) const throw(NoSuchElementException, OutOfBoundException, Error);

	// ������ �������Ʈ Ÿ��� ���� �������� Ÿ�� ����Ʈ�� ����´�.
	// (���� �����Ͱ� �ϳ��� �������Ʈ Ÿ��� ���� �� �ֱ� ������) 
	const vector<MonsterType_t>& getMonsterTypeBySprite(SpriteType_t spriteType) const throw (NoSuchElementException, OutOfBoundException, Error);

	SpriteType_t getSpriteTypeByName(const string& monsterName) const throw (NoSuchElementException, Error);
	MonsterType_t getChiefMonsterTypeByName(const string& monsterName) const throw (NoSuchElementException, Error);
	vector<MonsterType_t>& getMonsterTypesByMonsterClass(int MonsterClass) { return m_MonsterClassMap[MonsterClass]; }

	uint	getMaxMonsterType() const	{ return m_MaxMonsterType; }
	MonsterType_t	getRandomMonsterByClass( int minClass, int maxClass );

	// get debug string
	string toString() const throw();

protected :
	void	clearTreasures();

private:
	uint                  m_MaxMonsterType;      // size of MonsterInfo* array
	MonsterInfo**         m_MonsterInfos;          // array of monster info
	vector<MonsterType_t> m_MonsterSpriteSet[MAX_SPRITE_TYPE]; // array of MonsterType by SpriteType
	map<string, SpriteType_t> m_MonsterSpriteTypes; 	// �̸���� SpriteType_tã��
	map<string, MonsterType_t> m_ChiefMonster; 	// Chief ������ ��� ������ �ֱ�
	map<int, vector<SpriteType_t> > m_MonsterClassMap; // ������ Ŭ������ ������ Ÿ�� ã��

	TreasureLists 			m_SlayerTreasureLists;       // �����̾ ��� ������ ����Ʈ
	TreasureLists    		m_VampireTreasureLists;      // �����̾ ��� ������ ����Ʈ
	TreasureLists    		m_OustersTreasureLists;      // �ƿ콺��� ��� ������ ����Ʈ
};

// global variable declaration
extern MonsterInfoManager* g_pMonsterInfoManager;

#endif
