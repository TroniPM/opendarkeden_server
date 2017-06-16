//////////////////////////////////////////////////////////////////////////////
// Filename    : Vampire.cpp
// Written By  : Elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "Vampire.h"
#include "Player.h"
#include "OptionInfo.h"
#include "SkillInfo.h"
#include "ItemLoaderManager.h"
#include "EffectLoaderManager.h"
#include "SkillParentInfo.h"
#include "DB.h"
#include "ItemInfoManager.h"
#include "AbilityBalance.h"
#include "Stash.h"
#include "TradeManager.h"
#include "CreatureUtil.h"
#include "FlagSet.h"
#include "VampEXPInfo.h"
#include "Party.h"
#include "ItemUtil.h"
#include "PacketUtil.h"
#include "SkillUtil.h"
#include "Shape.h"
#include "GamePlayer.h"
//#include "RankEXPInfo.h"
#include "RankExpTable.h"
#include "VariableManager.h"
#include "WarSystem.h"
#include "ResurrectLocationManager.h"
#include "PKZoneInfoManager.h"
#include "TimeLimitItemManager.h"
#include "CastleSkillInfo.h"
#include "PetInfo.h"
#include <stdio.h>

#include "item/AR.h"
#include "item/SR.h"
#include "item/SG.h"
#include "item/SMG.h"
#include "item/PetItem.h"
#include "item/Belt.h"
#include "item/Skull.h"

#include "skill/VampireCastleSkillSlot.h"
#include "skill/EffectBless.h"
#include "skill/EffectParalyze.h"
#include "skill/EffectDoom.h"
#include "skill/EffectTransformToWolf.h"
#include "skill/EffectTransformToBat.h"
#include "EffectGrandMasterVampire.h"
#include "RaceWarLimiter.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCChangeShape.h"
#include "Gpackets/GCSkillInfo.h"
#include "Gpackets/GCRealWearingInfo.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCTakeOff.h"
#include "Gpackets/GCOtherModifyInfo.h"
#include "Gpackets/GCPetStashList.h"

#include "MonsterInfo.h"

#include "SystemAvailabilitiesManager.h"

const Color_t UNIQUE_COLOR = 0xFFFF;
const Color_t QUEST_COLOR = 0xFFFE;

const Level_t MAX_VAMPIRE_LEVEL = 150;
const Level_t MAX_VAMPIRE_LEVEL_OLD = 100;

//////////////////////////////////////////////////////////////////////////////
// incraseVampExp
//////////////////////////////////////////////////////////////////////////////
/*void Vampire::increaseVampExp(Exp_t Point)
{
	if (Point <= 0) return;

	Level_t curLevel = getLevel();

	if (curLevel >= VAMPIRE_MAX_LEVEL) 
	{
		// ���� �Ѱ迡 �����ص� ����ġ�� �װ� ���ش�.
		// by sigi. 2002.8.31
		Exp_t NewExp = getExp() + Point;

		WORD ExpSaveCount = getExpSaveCount();
		if (ExpSaveCount > VAMPIRE_EXP_SAVE_PERIOD)
		{
			char pField[80];
			sprintf(pField, "Exp=%lu", NewExp);
			tinysave(pField);
			ExpSaveCount = 0;
		}
		else ExpSaveCount++;
		setExpSaveCount(ExpSaveCount);

		setExp( NewExp );

		return;
	}

	Exp_t OldExp = getExp();

	Exp_t OldGoalExp = getGoalExp();
	Exp_t NewGoalExp = max(0, (int)(OldGoalExp - Point));

	// ���� ����ġ���� ��ǥ ����ġ�� �پ��� ��ŭ �÷��� �Ͽ��� �Ѵ�.
	Exp_t DiffGoalExp = max(0, (int)(OldGoalExp - NewGoalExp));

	Exp_t NewExp = OldExp + DiffGoalExp;

	setExp(NewExp);
	setGoalExp(NewGoalExp);

	// ��ǥ ����ġ�� 0 �̶��� ���� ���̴�.
	if (NewGoalExp == 0 && curLevel < VAMPIRE_MAX_LEVEL)
	{
		// �� �Լ� ��ü�� load�Ҷ��� �����Ǵ°ű� ������..
		// �ʿ�����. by sigi. 2002.8.31
	//	VAMPIRE_RECORD prev;
	//	getVampireRecord(prev);

		curLevel++;

		setLevel(curLevel);

		// add bonus point
		Bonus_t bonus = getBonus();

		if ((getSTR(ATTR_BASIC) + getDEX(ATTR_BASIC) + getINT(ATTR_BASIC) + getBonus() - 60) < ((getLevel() - 1) * 3)) 
		{
			// ������ ����ġ �ʰ�, ����� 3��� �����Ǿ���.
			// 2001.12.12 �輺��
			bonus += 3;
		}

		setBonus(bonus);

		VampEXPInfo* pBeforeExpInfo = g_pVampEXPInfoManager->getVampEXPInfo(curLevel-1);
		VampEXPInfo* pNextExpInfo = g_pVampEXPInfoManager->getVampEXPInfo(curLevel);
		Exp_t NextGoalExp = pNextExpInfo->getGoalExp();

		setGoalExp(NextGoalExp);

//		StringStream sav;
//		sav << "Level = " << (int)curLevel << "," << "Exp = " << (int)pBeforeExpInfo->getAccumExp() << "," << "GoalExp = " << (int)NextGoalExp << "," << "Bonus = " << (int)bonus;
//		pVampire->tinysave(sav.toString());

		char pField[80];
		sprintf(pField, "Level=%d, Exp=%lu, GoalExp=%lu, Bonus=%d", 
						curLevel, pBeforeExpInfo->getAccumExp(), NextGoalExp, bonus);
		tinysave(pField);
		setExpSaveCount(0);
	}
	else
	{
		// �ֱ������ �����Ѵ�.
		WORD ExpSaveCount = getExpSaveCount();
		if (ExpSaveCount > VAMPIRE_EXP_SAVE_PERIOD)
		{
			// by sigi. 2002.5.15
			char pField[80];
			sprintf(pField, "Exp=%lu, GoalExp=%lu", NewExp, NewGoalExp);
			tinysave(pField);

			ExpSaveCount = 0;
		}
		else ExpSaveCount++;
		setExpSaveCount(ExpSaveCount);
	}
}*/

//////////////////////////////////////////////////////////////////////////////
// increaseRankExp
//////////////////////////////////////////////////////////////////////////////
/*void Vampire::increaseRankExp(RankExp_t Point)
{
	if (Point <= 0) return;

	// PK� �ȿ����� ����ġ�� ���� �ʴ´�.
	if ( g_pPKZoneInfoManager->isPKZone( getZoneID() ) )
		return;

	Rank_t curRank = getRank();

	if (curRank >= VAMPIRE_MAX_RANK)
	{
		// ���� �Ѱ迡 �����ص� ����ġ�� �װ� ���ش�.
		// by sigi. 2002.8.31
		Exp_t NewExp = getRankExp() + Point;

		WORD ExpSaveCount = getRankExpSaveCount();
		if (ExpSaveCount > RANK_EXP_SAVE_PERIOD)
		{
			char pField[80];
			sprintf(pField, "RankExp=%lu", NewExp);
			tinysave(pField);
			ExpSaveCount = 0;
		}
		else ExpSaveCount++;
		setRankExpSaveCount(ExpSaveCount);

		setRankExp( NewExp );

		return;
	}

	Exp_t OldExp = getRankExp();

	Exp_t OldGoalExp = getRankGoalExp();
	Exp_t NewGoalExp = max(0, (int)(OldGoalExp - Point));

	// ���� ����ġ���� ��ǥ ����ġ�� �پ��� ��ŭ �÷��� �Ͽ��� �Ѵ�.
	Exp_t DiffGoalExp = max(0, (int)(OldGoalExp - NewGoalExp));

	Exp_t NewExp = OldExp + DiffGoalExp;


	// ��ǥ ����ġ�� 0 �̶��� ���� ���̴�.
	if (NewGoalExp == 0 && curRank < VAMPIRE_MAX_RANK)
	{
		VAMPIRE_RECORD prev;
		getVampireRecord(prev);

		curRank++;

		setRank(curRank);
		setRankExp(NewExp);
		setRankGoalExp(NewGoalExp);

		RankEXPInfo* pBeforeExpInfo = g_pRankEXPInfoManager[RANK_TYPE_VAMPIRE]->getRankEXPInfo(curRank-1);
		RankEXPInfo* pNextExpInfo = g_pRankEXPInfoManager[RANK_TYPE_VAMPIRE]->getRankEXPInfo(curRank);
		Exp_t NextGoalExp = pNextExpInfo->getGoalExp();

		setRankGoalExp(NextGoalExp);

//		StringStream sav;
//		sav << "Rank = " << (int)curRank << "," << "Exp = " << (int)pBeforeExpInfo->getAccumExp() << "," << "GoalExp = " << (int)NextGoalExp << "," << "Bonus = " << (int)bonus;
//		tinysave(sav.toString());

		char pField[80];
		sprintf(pField, "Rank=%d, RankExp=%lu, RankGoalExp=%lu",
						curRank, pBeforeExpInfo->getAccumExp(), NextGoalExp);
		tinysave(pField);
		setRankExpSaveCount(0);

		sendModifyInfo(prev);

		if (m_pZone != NULL)
		{
			GCOtherModifyInfo gcOtherModifyInfo;
			gcOtherModifyInfo.setObjectID(getObjectID());
			gcOtherModifyInfo.addShortData(MODIFY_RANK, curRank);

			m_pZone->broadcastPacket(m_X, m_Y, &gcOtherModifyInfo, this);
		}
	}
	else
	{
		setRankExp(NewExp);
		setRankGoalExp(NewGoalExp);

		// �ֱ������ �����Ѵ�.
		WORD rankExpSaveCount = getRankExpSaveCount();
		if (rankExpSaveCount > RANK_EXP_SAVE_PERIOD)
		{
			char pField[80];
			sprintf(pField, "RankExp=%lu, RankGoalExp=%lu", NewExp, NewGoalExp);
			tinysave(pField);

			rankExpSaveCount = 0;
		}
		else rankExpSaveCount++;
		setRankExpSaveCount(rankExpSaveCount);

		// ���� ����ġ�� �����ش�. by sigi. 2002.9.13
		GCModifyInformation gcModifyInformation;
		gcModifyInformation.addLongData(MODIFY_RANK_EXP, NewExp);
		m_pPlayer->sendPacket(&gcModifyInformation);
	}
}*/

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////



Vampire::Vampire () 
	throw () 
: PlayerCreature(0, NULL)
{
	__BEGIN_TRY

	m_CClass = CREATURE_CLASS_VAMPIRE;

	m_Mutex.setName("Vampire");

	// AttackMelee ��� �⺻ ����� �����־��ش�.
	for (int i=0; i<SKILL_DOUBLE_IMPACT; i++)
	{
		VampireSkillSlot* pVampireSkillSlot = new VampireSkillSlot;
		//pVampireSkillSlot = new VampireSkillSlot;	// 2002.1.16 by sigi
		pVampireSkillSlot->setName(m_Name);
		pVampireSkillSlot->setSkillType(i);
		pVampireSkillSlot->setInterval(5);
		pVampireSkillSlot->setRunTime();

		addSkill(pVampireSkillSlot);
	}

    for (int i = 0; i < VAMPIRE_WEAR_MAX; i++) 
        m_pWearItem[i] = NULL;

	// �� Ű�� �ʱ�ȭ �Ѵ�.
//	for (int i = 0; i < 8; i++) 
//	{
//		m_HotKey[i] = 0;
//	}

	m_SilverDamage = 0;
	m_ClanType = 0;

	// HP ��� �ð� �ʱ�ȭ
	getCurrentTime(m_HPRegenTime);

	// ����ġ ���̺� ī��Ʈ �ʱ�ȭ
//	m_RankExpSaveCount       = 0;
	m_ExpSaveCount       = 0;
	m_FameSaveCount      = 0;
	m_AlignmentSaveCount = 0;

	__END_CATCH
}

Vampire::~Vampire() 
    throw ()
{
	__BEGIN_TRY

	try
	{
		// ���� ����� �����صд�. by sigi. 2002.6.18
		DWORD   flag;
		Color_t color[PCVampireInfo::VAMPIRE_COLOR_MAX];
		getShapeInfo (flag, color);

		char pField[128];
		sprintf(pField, "Shape=%ld, CoatColor=%d",
							flag,
							color[PCVampireInfo::VAMPIRE_COLOR_COAT]);

		//cout << "SAVE = " << pField << endl;

		tinysave(pField);


		// ������ �������� �������� ����ġ, ���� ��� �����Ѵ�.
		saveGears();
		saveExps();
		saveSkills();

		// �԰� �ִ� ������� �޸𸮿��� ����Ѵ�.
		destroyGears();

		// Ŭ������ ����� ����, �ش��ϴ� ��ȯ ����� ����ؾ� ��� ����,
		// ��ȯ ���뿡�Ե� �� ����� �˷����� �Ѵ�.
		TradeManager* pTradeManager = m_pZone->getTradeManager();
		TradeInfo* pInfo = pTradeManager->getTradeInfo(getName());
		if (pInfo != NULL)
		{
			// ��ȯ ����� ���
			pTradeManager->cancelTrade(this);
		}

		// �۷ι� ��Ƽ ����� ����Ѵ�. 
		// �Ϲ����� �α׾ƿ��� ���쿡��
		// CGLogoutHandler���� Zone::deleteCreature() �Լ��� �θ��� �ǰ�,
		// ��������� �������� �ص�, 
		// GamePlayer::disconnect()���� Zone::deleteCreature() �Լ��� �θ��� �ǹǷ�,
		// ���� ��Ƽ �� ��Ƽ �ʴ�, Ʈ���̵� ����� ����� �ʿ��� ����.
		deleteAllPartyInfo(this);

		// ������� ���
		map<SkillType_t, VampireSkillSlot*>::iterator itr = m_SkillSlot.begin();
		for (; itr != m_SkillSlot.end(); itr++)
		{
			VampireSkillSlot* pVampireSkillSlot = itr->second;
			SAFE_DELETE(pVampireSkillSlot);
		}
	} catch (Throwable& t) {
		filelog("vampireDestructor.txt", "%s", t.toString().c_str());
	} catch (exception& e) {
		filelog("vampireDestructor.txt", "Unknown std::exception");
	} catch (...) {
		filelog("vampireDestructor.txt", "Unknown ... exception");
	}

	m_bDeriveDestructed = true;

	__END_CATCH
}

// registerObject
// Zone�� ��ӵ� ObjectRegistry�� �����ؼ�, Vampire �� ��������۵���
// ObjectID�� �Ҵ��޴´�.
void Vampire::registerObject ()
    throw (Error)
{
    __BEGIN_TRY

    Assert(getZone() != NULL);

    // zone �� object registery �� ����Ѵ�.
    ObjectRegistry & OR = getZone()->getObjectRegistry();

    __ENTER_CRITICAL_SECTION(OR)

	// ���� �����ۿ� OID �� �ٲ��Ƿ� �ð���� ������ �Ŵ������� OID ��� �������� �Ѵ�.
	if (m_pTimeLimitItemManager != NULL)
		m_pTimeLimitItemManager->clear();

	// �켱 �����̾��� OID�� ���Ϲ޴´�.
	OR.registerObject_NOLOCKED(this);

	// �κ��丮�� �����۵��� OID�� ���Ϲ޴´�.
	registerInventory(OR);

	// Goods Inventory�� �����۵��� OID�� ���Ϲ޴´�.
	registerGoodsInventory(OR);

	// �����ϰ� �ִ� �����۵��� OID�� ���Ϲ޴´�.
	for (int i = 0; i < VAMPIRE_WEAR_MAX; i++) 
	{
		Item* pItem = m_pWearItem[i];

		if (pItem != NULL) 
		{
			bool bCheck = true;

			// ���� ������ ����, WEAR_LEFTHAND ���� ��������Ƿ�,
			// �� ������ �ʿ��� ����.
			if (i == WEAR_RIGHTHAND && isTwohandWeapon(pItem))
				bCheck = false;

			if (bCheck) registerItem(pItem, OR);
		}
	}

	// ���콺�� ���� �ִ� �������� OID�� ���� �޴´�.
	Item* pSlotItem = m_pExtraInventorySlot->getItem();
	if (pSlotItem != NULL) registerItem(pSlotItem, OR);

	m_Garbage.registerObject(OR);

	for ( int i=0; i<MAX_PET_STASH; ++i )
	{
		Item* pItem = getPetStashItem(i);
		if ( pItem != NULL ) registerItem( pItem, OR );
	}

    __LEAVE_CRITICAL_SECTION(OR)

	m_VampireInfo.setObjectID(m_ObjectID);

    __END_CATCH
}

// Zone�� ��ӵ� ObjectRegistry�� �����ؼ�, Vampire �� ��������۵���
// ObjectID�� �Ҵ��޴´�. ItemTrace �� ������ ���� ���� ��� ���� ����
void Vampire::registerInitObject ()
    throw (Error)
{
    __BEGIN_TRY

    Assert(getZone() != NULL);

    // zone �� object registery �� ����Ѵ�.
    ObjectRegistry & OR = getZone()->getObjectRegistry();

    __ENTER_CRITICAL_SECTION(OR)

	// ���� �����ۿ� OID �� �ٲ��Ƿ� �ð���� ������ �Ŵ������� OID ��� �������� �Ѵ�.
	if (m_pTimeLimitItemManager != NULL)
		m_pTimeLimitItemManager->clear();

	// �켱 �����̾��� OID�� ���Ϲ޴´�.
	OR.registerObject_NOLOCKED(this);

	// �κ��丮�� �����۵��� OID�� ���Ϲ޴´�.
	registerInitInventory(OR);

	// Goods Inventory�� �����۵��� OID�� ���Ϲ޴´�.
	registerGoodsInventory(OR);

	// �����ϰ� �ִ� �����۵��� OID�� ���Ϲ޴´�.
	for (int i = 0; i < VAMPIRE_WEAR_MAX; i++) 
	{
		Item* pItem = m_pWearItem[i];

		if (pItem != NULL) 
		{
			// ItemTrace �� ���� ������ ���
			pItem->setTraceItem( bTraceLog( pItem ) );

			bool bCheck = true;

			// ���� ������ ����, WEAR_LEFTHAND ���� ��������Ƿ�,
			// �� ������ �ʿ��� ����.
			if (i == WEAR_RIGHTHAND && isTwohandWeapon(pItem))
				bCheck = false;

			if (bCheck) registerItem(pItem, OR);
		}
	}

	// ���콺�� ���� �ִ� �������� OID�� ���� �޴´�.
	Item* pSlotItem = m_pExtraInventorySlot->getItem();
	if (pSlotItem != NULL)
	{
		// ItemTrace �� ���� ������ ���
		pSlotItem->setTraceItem( bTraceLog( pSlotItem ) );
		registerItem(pSlotItem, OR);
	}

	m_Garbage.registerObject(OR);

    __LEAVE_CRITICAL_SECTION(OR)

	m_VampireInfo.setObjectID(m_ObjectID);

    __END_CATCH
}

// �ð���� ������� üũ�Ѵ�.
// ���� �������� �̹� register �Ǿ��־��� �Ѵ�.
void Vampire::checkItemTimeLimit() throw (Error)
{
	__BEGIN_TRY

	// �κ��丮���� ã�´�.
	{
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
					// üũ�� �������� ����Ʈ���� ���� ������� ã�´�.
					list<Item*>::iterator itr = find(ItemList.begin(), ItemList.end(), pItem);

					if (itr == ItemList.end())
					{
						i += pItem->getVolumeWidth() - 1;

						if ( wasteIfTimeLimitExpired( pItem ) )
						{
							m_pInventory->deleteItem( pItem->getObjectID() );
							SAFE_DELETE( pItem );
						}
						else
						{
							// ����Ʈ�� �������� �����
							// ��� ������� �ι� üũ���� �ʱ� ��ؼ�
							// ����Ʈ���ٰ� ������� �����ִ´�.
							ItemList.push_back(pItem);
						}
					}
				}
			}
		}
	}

	// �����ϰ� �ִ� �� �߿� ã�´�.
	{
		for (int i = 0; i < VAMPIRE_WEAR_MAX; i++) 
		{
			Item* pItem = m_pWearItem[i];

			if (pItem != NULL) 
			{
				bool bCheck = true;

				// ���� ������ ����, WEAR_LEFTHAND ���� ��������Ƿ�,
				// �� ������ �ʿ��� ����.
				if (i == WEAR_RIGHTHAND && isTwohandWeapon(pItem))
					bCheck = false;

				if (bCheck) 
				{
					if ( wasteIfTimeLimitExpired( pItem ) )
					{
						deleteWearItem( (WearPart)i );
						if ( i == WEAR_LEFTHAND && isTwohandWeapon(pItem) )
							deleteWearItem( WEAR_RIGHTHAND );
						SAFE_DELETE( pItem );
					}
				}
			}
		}
	}

	// ���콺�� ���� �ִ� ������� üũ�Ѵ�.
	{
		Item* pSlotItem = m_pExtraInventorySlot->getItem();
		if (pSlotItem != NULL && wasteIfTimeLimitExpired( pSlotItem ))
		{
			deleteItemFromExtraInventorySlot();
			SAFE_DELETE( pSlotItem );
		}
	}

	__END_CATCH
}


///////////////////////////////////////////
//	Vampire�� Slayer������ ����� ��ؼ�
//	���� �ε�� ���� ó���Ѵ�.
//
void Vampire::loadItem( bool checkTimeLimit )
	throw (InvalidProtocolException, Error)
{
	__BEGIN_TRY

	PlayerCreature::loadItem();

    // �κ��丮�� �����Ѵ�.
	SAFE_DELETE(m_pInventory);
	m_pInventory = new Inventory(10, 6);
	m_pInventory->setOwner(getName());

	// ������� �ε��Ѵ�.
	g_pItemLoaderManager->load(this);

	// ������ ������� �ε��Ѵ�.
	PlayerCreature::loadGoods();

	// �ε��� �����۵�� ���Ͻ�Ű��
    registerInitObject();

	if ( checkTimeLimit )
	{
		checkItemTimeLimit();
	}

	// �԰� �ִ� �ʿ� ���� �ɷ�ġ�� �������ش�.
	initAllStat();

	__END_CATCH
}


//----------------------------------------------------------------------
//----------------------------------------------------------------------
bool Vampire::load ()
	throw (InvalidProtocolException, Error)
{
	__BEGIN_TRY

	Statement* pStmt   = NULL;
	Result*    pResult = NULL;

	int reward = 0;

	BEGIN_DB
	{
		pStmt   = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery(
			"SELECT Name, Sex, BatColor, SkinColor, "
			"STR, DEX, INTE, HP, CurrentHP, Fame, "
			"GoalExp, Level, Bonus, Gold, GuildID,"
			"ZoneID, XCoord, YCoord, Sight, Alignment,"
			"StashGold, StashNum, Competence, CompetenceShape, ResurrectZone, SilverDamage, Reward, "
			"Rank, RankGoalExp FROM Vampire WHERE Name = '%s' AND Active = 'ACTIVE'",
			m_Name.c_str()
		);

		if (pResult->getRowCount() == 0) 
		{
			//throw Error("Critical Error : data intergrity broken. (�α��� ���������� ���� ������ �Ѿ���� ���ȿ� ĳ���Ͱ� ����Ǿ���ϴ�.)");
			SAFE_DELETE(pStmt);
			return false;
		}

		pResult->next();

		uint i = 0;

		setName(pResult->getString(++i));
		setSex(pResult->getString(++i));
		setBatColor(pResult->getInt(++i));
		setSkinColor(pResult->getInt(++i));

		m_STR[ATTR_BASIC]   = pResult->getInt(++i);
		m_STR[ATTR_CURRENT] = m_STR[ATTR_BASIC];
	   	m_STR[ATTR_MAX]     = m_STR[ATTR_BASIC];

		m_DEX[ATTR_BASIC]   = pResult->getInt(++i);
		m_DEX[ATTR_CURRENT] = m_DEX[ATTR_BASIC];
	   	m_DEX[ATTR_MAX]     = m_DEX[ATTR_BASIC];

		m_INT[ATTR_BASIC]   = pResult->getInt(++i);
		m_INT[ATTR_CURRENT] = m_INT[ATTR_BASIC];
	   	m_INT[ATTR_MAX]     = m_INT[ATTR_BASIC];

		setHP(pResult->getInt(++i) , ATTR_MAX);
		setHP(getHP(ATTR_MAX) , ATTR_BASIC);
		setHP(pResult->getInt(++i) , ATTR_CURRENT);
		
		setFame(pResult->getInt(++i));

//		setExp(pResult->getInt(++i));
		setGoalExp(pResult->getInt(++i));
//		setExpOffset(pResult->getInt(++i));
		setLevel(pResult->getInt(++i));
		setBonus(pResult->getInt(++i));

		//setInMagics(pResult->getString(++i));
		setGold(pResult->getInt(++i));
		setGuildID(pResult->getInt(++i));

//		setZoneID(pResult->getInt(++i));
		ZoneID_t zoneID = pResult->getInt(++i);
		setX(pResult->getInt(++i));
		setY(pResult->getInt(++i));

		setSight (pResult->getInt(++i));

		setAlignment(pResult->getInt(++i));

//		for (int j = 0; j < 8; j++)
//			setHotKey(j, pResult->getInt(++i));

		setStashGold(pResult->getInt(++i));
		setStashNum(pResult->getBYTE(++i));
		
		m_Competence = pResult->getBYTE(++i);

		if ( m_Competence >= 4 )
			m_Competence = 3;

		m_CompetenceShape = pResult->getBYTE(++i);

		setResurrectZoneID(pResult->getInt(++i));

		m_SilverDamage = pResult->getInt(++i);

		reward = pResult->getInt(++i);

		Rank_t CurRank               = pResult->getInt(++i);
		RankExp_t RankGoalExp        = pResult->getInt(++i);

		m_pRank = new Rank( CurRank, RankGoalExp, RankExpTable::s_RankExpTables[RANK_TYPE_VAMPIRE] );

//		setRank( pResult->getInt(++i) );
//		setRankExp( pResult->getInt(++i) );
//		setRankGoalExp( pResult->getInt(++i) );

		// maxHP�� �ٽ� �����ؼ� ������ش�.
		// 2002.7.15 by sigi
		// ���� �ٲ��� AbilityBalance.cpp�� computeHP�� ����ؾ��Ѵ�.
		int maxHP = m_STR[ATTR_CURRENT]*2 + m_INT[ATTR_CURRENT] + m_DEX[ATTR_CURRENT] + m_Level;
		maxHP = min((int)maxHP, VAMPIRE_MAX_HP);
		setHP( maxHP, ATTR_MAX );

		try
		{
			setZoneID( zoneID );
		}
		catch ( Error& e )
		{
			// ���� ����Ʈ ����� ����.
			// ���� ����Ʈ�� �� ���� ���������� ����ϹǷ� �ٸ� ���Ӽ����� ����� �� �� ����Ʈ�� ����� ���Ѵ�.
			// ���� ����Ʈ �Ա��� �ű���.
			setZoneID( 1003 );
			setX( 30 );
			setY( 30 );
		}

		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

/*	if (reward != 0)
	{
		BEGIN_DB
		{
			StringStream SQL;
			SQL << "UPDATE Vampire SET Reward = 0 WHERE Name = '" << m_Name << "'";

			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			pStmt->executeQuery(SQL.toString());
			SAFE_DELETE(pStmt);
		}
		END_DB(pStmt)

		int amount = 0;

		if (m_Level>=1 && m_Level<=10)
			amount = m_Level*2000;
		else if (m_Level>10 && m_Level<=30)
			amount = m_Level*3000;
		else if (m_Level>30)
			amount = m_Level*10000;

		int offset = 1000;

		for (int i=0; i<amount; i += offset)
		{
			increaseVampExp(offset);
		}

		reward = 0;
	}*/

	//----------------------------------------------------------------------
	// Vampire Outlook Information � �����Ѵ�.
	//----------------------------------------------------------------------
	// �����̾��� �ε��Ҷ� ObjectID�� ���� �ϵ��� �Ѵ�. �ٵ� ��� �Ҷ�? -_-
	m_VampireInfo.setObjectID(m_ObjectID);
	m_VampireInfo.setName(m_Name);
	m_VampireInfo.setSex(m_Sex);
	m_VampireInfo.setBatColor(m_BatColor);
	m_VampireInfo.setSkinColor(m_SkinColor);

	m_VampireInfo.setCompetence(m_CompetenceShape);

    //----------------------------------------------------------------------
	// ��ų� �ε��Ѵ�.
	//----------------------------------------------------------------------
	BEGIN_DB
	{
		pStmt   = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery("SELECT SkillType, Delay, CastingTime, NextTime FROM VampireSkillSave WHERE OwnerID = '%s'", m_Name.c_str());
	
		while(pResult->next()) 
		{
			int         i          = 0;
			SkillType_t SkillType = pResult->getInt(++i);

			if (hasSkill(SkillType) == NULL) 
			{
				VampireSkillSlot* pVampireSkillSlot = new VampireSkillSlot();
		
				pVampireSkillSlot->setName(m_Name);
				pVampireSkillSlot->setSkillType(SkillType);
				pVampireSkillSlot->setInterval (pResult->getInt(++i));
				pVampireSkillSlot->setCastingTime (pResult->getInt(++i));
				//pVampireSkillSlot->setRunTime (pResult->getInt(++i));
				pVampireSkillSlot->setRunTime();
		
				addSkill(pVampireSkillSlot);
			}
		}
	
		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

    //----------------------------------------------------------------------
	// Rank Bonus ��  �ε��Ѵ�.
	//----------------------------------------------------------------------
	loadRankBonus();

    //----------------------------------------------------------------------
	// ����Ʈ�� �ε��Ѵ�.
	//----------------------------------------------------------------------
	g_pEffectLoaderManager->load(this);

	//----------------------------------------------------------------------
	// GrandMaster�� ������ Effect�� �ٿ��ش�.
	//----------------------------------------------------------------------
	// by sigi. 2002.11.8
	if (m_Level>=100
		&& SystemAvailabilitiesManager::getInstance()->isAvailable( SystemAvailabilitiesManager::SYSTEM_GRAND_MASTER_EFFECT ) )
	{
		if (!isFlag(Effect::EFFECT_CLASS_GRAND_MASTER_VAMPIRE))
		{
			EffectGrandMasterVampire* pEffect = new EffectGrandMasterVampire(this);
			pEffect->setDeadline(999999);
			getEffectManager()->addEffect( pEffect );
			setFlag(Effect::EFFECT_CLASS_GRAND_MASTER_VAMPIRE);
		}
	}

	//----------------------------------------------------------------------
	// �÷��� ��� �ε��Ѵ�.
	//----------------------------------------------------------------------
	m_pFlagSet->load(getName());

	//----------------------------------------------------------------------
	// Vampire Outlook Information � �ʱ�ȭ�Ѵ�.
	//----------------------------------------------------------------------
	/*
	ItemType_t coatType = 0;
	Item* pItem = m_pWearItem[WEAR_BODY];
	if (pItem!=NULL)
	{
		coatType = pItem->getItemType();
	}
	*/

	m_VampireInfo.setCoatType( 0 );
	m_VampireInfo.setCoatColor(JACKET_BASIC);
	m_VampireInfo.setCoatColor(377);
	//m_VampireInfo.setCoatColor(2 , SUB_COLOR);

	// �߸��� ����ġ�� ���� ���ش�.
/*	VampEXPInfo* pVampEXPInfo = g_pVampEXPInfoManager->getVampEXPInfo(m_Level);

	if ((pVampEXPInfo->getAccumExp() != m_Exp + m_GoalExp) 
		&& m_Level > 1 && m_Level < VAMPIRE_MAX_LEVEL) 
	{
		//ofstream file("����ɷ�ġ��.txt", ios::out | ios::app);
		//file << "NAME:" << m_Name << endl;
		//file << "==VampEXP==" << endl;
		//file << "���緹�����Ѱ���ġ : " << (int)pVampEXPInfo->getAccumExp() << endl;
		//file << "���� ���� ����ġ : " << (int)m_Exp << endl;
		//file << "���� ��ǥ ����ġ : " << (int)m_GoalExp << endl;

		// ���� ������ ������ �޾ƿ´�.
		VampEXPInfo* pBeforeVampEXPInfo = g_pVampEXPInfoManager->getVampEXPInfo(m_Level - 1);
		// ���� ������ �� ����ġ + ��ǥ ����ġ ��ȭ�� = ���� ���� ����ġ
		m_Exp = pBeforeVampEXPInfo->getAccumExp() + (pVampEXPInfo->getGoalExp() - m_GoalExp);

		//file << "����� ���� ����ġ : " << (int)m_Exp << endl;
		//file << "����� ��ǥ ����ġ : " << (int)m_GoalExp << endl;
		//file << endl;
		//file.close();

	   // by sigi. 2002.5.15
//		StringStream attrsave;
//		attrsave << "Exp = " << (int)m_Exp;
//		tinysave(attrsave.toString());

		char pField[80];
		sprintf(pField, "Exp=%lu", m_Exp);
		tinysave(pField);
	}*/

	// rank�� 0�̸� �ʱⰪ�� ������� �ʾҴٴ� �ǹ��̴�. by sigi. 2002.9.13
	if (getRank()==0)
	{
		saveInitialRank();
	}


	// �߸��� ����� ���� ���ش�.
/*	RankEXPInfo* pRankEXPInfo = g_pRankEXPInfoManager[RANK_TYPE_VAMPIRE]->getRankEXPInfo(m_Rank);

	if ((pRankEXPInfo->getAccumExp() != m_RankExp + m_RankGoalExp) 
		&& m_Rank > 1 && m_Rank < VAMPIRE_MAX_RANK) 
	{
		//ofstream file("����ɷ�ġ��.txt", ios::out | ios::app);
		//file << "NAME:" << m_Name << endl;
		//file << "==VampEXP==" << endl;
		//file << "���緹�����Ѱ���ġ : " << (int)pVampEXPInfo->getAccumExp() << endl;
		//file << "���� ���� ����ġ : " << (int)m_Exp << endl;
		//file << "���� ��ǥ ����ġ : " << (int)m_GoalExp << endl;

		// ���� ������ ������ �޾ƿ´�.
		RankEXPInfo* pBeforeRankEXPInfo = g_pRankEXPInfoManager[RANK_TYPE_VAMPIRE]->getRankEXPInfo(m_Rank - 1);
		// ���� ������ �� ����ġ + ��ǥ ����ġ ��ȭ�� = ���� ���� ����ġ
		m_RankExp = pBeforeRankEXPInfo->getAccumExp() + (pRankEXPInfo->getGoalExp() - m_RankGoalExp);

		//file << "����� ���� ����ġ : " << (int)m_Exp << endl;
		//file << "����� ��ǥ ����ġ : " << (int)m_GoalExp << endl;
		//file << endl;
		//file.close();

		char pField[80];
		sprintf(pField, "RankExp=%lu", m_RankExp);
		tinysave(pField);
	}
*/

	initAllStat();

	// ���� ���� Flag üũ
	if ( RaceWarLimiter::isInPCList( this ) )
	{
		setFlag( Effect::EFFECT_CLASS_RACE_WAR_JOIN_TICKET );
	}

	if (m_pZone->isHolyLand()
        && g_pWarSystem->hasActiveRaceWar()
        && !isFlag( Effect::EFFECT_CLASS_RACE_WAR_JOIN_TICKET ))
    {
        ZONE_COORD ResurrectCoord;
        g_pResurrectLocationManager->getPosition( this, ResurrectCoord );
        setZoneID( ResurrectCoord.id );
        setX( ResurrectCoord.x );
        setY( ResurrectCoord.y );
    }



	return true;

	__END_CATCH
}

//----------------------------------------------------------------------
//----------------------------------------------------------------------
void Vampire::save () const
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	Statement* pStmt;

	//--------------------------------------------------------------------------------
	// �����̾� ����� �����Ѵ�.
	//--------------------------------------------------------------------------------
	BEGIN_DB
	{
		StringStream sql;
		sql << "UPDATE Vampire SET"
			//<< " BatColor = " << (int)m_BatColor
			//<< ", SkinColor = " << (int)m_SkinColor
			//<< ", STR = " << (int)m_STR[ATTR_MAX]
			//<< ", DEX = " << (int)m_DEX[ATTR_MAX]
			//<< ", INTE = " << (int)m_INT[ATTR_MAX]
			<< " CurrentHP = " << (int)m_HP[ATTR_CURRENT]
			<< ", HP = " << (int)m_HP[ATTR_MAX]
			<< ", SilverDamage = " << (int)m_SilverDamage
			//<< ", Fame = " << (int)m_Fame
			//<< ", Exp = " << (int)m_Exp
			//<< ", ExpOffset = " << (int)m_ExpOffset
			//<< ", Rank = " << (int)m_Rank
			//<< ", RankExp = " << (int)m_RankExp
			//<< ", Level = " << (int)m_Level
			//<< ", Bonus = " << (int)m_Bonus
			//<< ", Gold = " << (int)m_Gold
			<< ", ZoneID = " << (int)getZoneID()
			<< ", XCoord = " << (int)m_X
			<< ", YCoord = " << (int)m_Y
			//<< ", Sight = " << (int)m_Sight
//			<< ", F5 = " << (int)m_HotKey[0]
//			<< ", F6 = " << (int)m_HotKey[1]
//			<< ", F7 = " << (int)m_HotKey[2]
//			<< ", F8 = " << (int)m_HotKey[3]
//			<< ", F9 = " << (int)m_HotKey[4]
//			<< ", F10 = " << (int)m_HotKey[5]
//			<< ", F11 = " << (int)m_HotKey[6]
//			<< ", F12 = " << (int)m_HotKey[7]
			<< " WHERE Name = '" << m_Name << "'";
			//<< ", InMagics = '" << ??? << "'"
		
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		pStmt->executeQuery(sql.toString());

		//Assert(pStmt->getAffectedRowCount() != 1);

		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)
	
	/*
	//----------------------------------------------------------------------
	// ������� ���̺��Ѵ�.
	//----------------------------------------------------------------------
	//--------------------------------------------------
	// �κ��丮�� �����۵�� ���̺� �Ѵ�.
	//--------------------------------------------------
	m_pInventory->save(m_Name);
	*/


	//--------------------------------------------------
	// ����Ʈ�� ���̺� �Ѵ�.
	//--------------------------------------------------
	m_pEffectManager->save(m_Name);

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

//----------------------------------------------------------------------
// tinysave
//----------------------------------------------------------------------
void Vampire::tinysave(const string & field)	// by sigi. 2002.5.15
	    const throw(Error)
{
    __BEGIN_TRY

    Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery("UPDATE Vampire SET %s WHERE Name='%s'", field.c_str(), m_Name.c_str());
		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

    __END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
//
// ��ų ���� �Լ�
//
//
////////////////////////////////////////////////////////////////////////////////

// Ư� Skill� �����Ѵ�.
VampireSkillSlot* Vampire::getSkill (SkillType_t SkillType) const 
	throw()
{
	__BEGIN_TRY

	map<SkillType_t, VampireSkillSlot*>::const_iterator itr = m_SkillSlot.find(SkillType);
	if (itr != m_SkillSlot.end())
	{
		return itr->second;
	}

	return NULL;

	__END_CATCH
}

// Ư� Skill� add �Ѵ�
void Vampire::addSkill(SkillType_t SkillType)
	throw()
{
	__BEGIN_TRY

	switch (SkillType)
	{
		case SKILL_UN_BURROW:
		case SKILL_UN_TRANSFORM:
		case SKILL_UN_INVISIBILITY:
		case SKILL_THROW_HOLY_WATER:
		case SKILL_EAT_CORPSE:
		//case SKILL_HOWL:
			filelog("VampireError.log", "SkillType[%d], %s", SkillType, toString().c_str());
			Assert(false);
			break;
		default:
			break;
	}

	map<SkillType_t, VampireSkillSlot*>::iterator itr = m_SkillSlot.find(SkillType);

	if (itr == m_SkillSlot.end())
	{
		SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);
		Turn_t Delay = pSkillInfo->getMaxDelay();

		VampireSkillSlot* pVampireSkillSlot = new VampireSkillSlot;

		pVampireSkillSlot->setName(m_Name);
		pVampireSkillSlot->setSkillType(SkillType);
		pVampireSkillSlot->setInterval(Delay);
		pVampireSkillSlot->setRunTime();
		pVampireSkillSlot->create(m_Name);

		m_SkillSlot[SkillType] = pVampireSkillSlot;
	}

	__END_CATCH
}

// Ư� SkillSlot� �ڵ���� �� ����� ã�� �ִ´�.
void Vampire::addSkill(VampireSkillSlot* pVampireSkillSlot)
	throw()
{
	__BEGIN_TRY

	SkillType_t SkillType = pVampireSkillSlot->getSkillType();
	switch (SkillType)
	{
		case SKILL_UN_BURROW:
		case SKILL_UN_TRANSFORM:
		case SKILL_UN_INVISIBILITY:
		case SKILL_THROW_HOLY_WATER:
		case SKILL_EAT_CORPSE:
//		case SKILL_HOWL:
			filelog("VampireError.log", "SkillType[%d], %s", SkillType, toString().c_str());
			Assert(false);
			break;
		default:
			break;
	}

	map<SkillType_t, VampireSkillSlot*>::iterator itr = m_SkillSlot.find(pVampireSkillSlot->getSkillType());
	
	if (itr == m_SkillSlot.end())
	{
		m_SkillSlot[pVampireSkillSlot->getSkillType()] = pVampireSkillSlot;
	}
	// 2002.1.16 by sigi
	else
	{
		delete pVampireSkillSlot;
	}

	__END_CATCH
}

// ������ų� �����ִ� �Լ���.
void Vampire::removeCastleSkill(SkillType_t SkillType)
	throw()
{
	__BEGIN_TRY

	// ���� ��ų�� ���� �� �ִ�.
	if ( g_pCastleSkillInfoManager->getZoneID( SkillType ) == 0 ) return;

	map<SkillType_t, VampireSkillSlot*>::iterator itr = m_SkillSlot.find(SkillType);
	
	if (itr != m_SkillSlot.end())
	{
		VampireCastleSkillSlot* pCastleSkillSlot = dynamic_cast<VampireCastleSkillSlot*>(itr->second);

		SAFE_DELETE( pCastleSkillSlot );

		m_SkillSlot.erase( itr );
	}

	__END_CATCH
}

// ���� �ִ� ���� ������ų� �����ִ� �Լ��̴�.
void Vampire::removeAllCastleSkill()
	throw()
{
	__BEGIN_TRY

	map<SkillType_t, VampireSkillSlot*>::iterator itr = m_SkillSlot.begin();

	while ( itr != m_SkillSlot.end() )
	{
		if ( itr->second != NULL )
		{
			VampireSkillSlot* pSkillSlot = itr->second;
			if ( g_pCastleSkillInfoManager->getZoneID( pSkillSlot->getSkillType() ) == 0 )
			{
				// ������ų�� �ƴϸ� ������� �Ѿ��.
				++itr;
				continue;
			}

			// ������ų�̸� �����ش�. �ݺ��� ���뿡 ����
			SAFE_DELETE( pSkillSlot );
			map<SkillType_t, VampireSkillSlot*>::iterator prevItr = itr;
			
			++itr;
			m_SkillSlot.erase( prevItr );
		}
		else
		{
			// �̰� �ֱ�.... Assert �ؾ� ���� �ʳ� -_-;
			Assert(false);
		}
	}

	__END_CATCH
}


////////////////////////////////////////////////////////////////////////////////
//
//
// ������ ��/Ż ���� �Լ�
//
//
////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------
//
// Vampire::WearItem()
//
// Item� ����â�� ������Ű�� �ɷ�ġ�� �����Ѵ�.
//
//----------------------------------------------------------------------
void Vampire::wearItem(WearPart Part, Item* pItem)
	throw()
{
	__BEGIN_TRY

	Assert(pItem != NULL);

	Item* pPrevItem = NULL;
	Item* pLeft = NULL;
	Item* pRight = NULL;

	// ���� ��ȹ������...�ɷ�ġ�� ���ڶ������� ������� ����� ������ ����
	// �ִ�. ������ �����ۿ� ���� �ɷ�ġ�� ������ ���� �ʴ´�. 
	// �׷��Ƿ� �ϴ� ������� �ش��ϴ� ����â���� �����ִ´�.

	// vampire ���� �߰�. 2002.8.16. by sigi
	// ���� ������ ���쿡�� ���� ����â���� �ϳ��� ������ �����͸� �Ҵ�...
	if (isTwohandWeapon(pItem))
	{
		// ���տ� ������� ���� ��� ����
		if (isWear(WEAR_RIGHTHAND) && isWear(WEAR_LEFTHAND))
		{
			pLeft  = getWearItem(WEAR_RIGHTHAND);
			pRight = getWearItem(WEAR_LEFTHAND);
			
			// ���� ���⸦ ���� ��� ����
			if (pLeft == pRight)
			{
				// �䱸�� ������� ���� ����Ʈ�� �ְ�,
				m_pWearItem[WEAR_RIGHTHAND] = pItem;
				m_pWearItem[WEAR_LEFTHAND]  = pItem;

				// by sigi. 2002.5.15
				char pField[80];
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
				sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
				pItem->tinysave(pField);

				// ���� �ִ� ������� ���콺 �����Ϳ� �޾� �ش�.
				addItemToExtraInventorySlot(pLeft);
				//pLeft->save(m_Name, STORAGE_EXTRASLOT, 0, 0, 0);
				sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
				pLeft->tinysave(pField);
			}
			// �ɳ�
			else
			{
				// ���տ� �˰� ���и� ���� �־��µ�...���� ���⸦ ����� �ϸ�,
				// ��� ���콺 �����Ϳ� �޾��� �� ������, ���д� ��� �� ���� ����.
				// �κ��丮�� �־����� �� �ٵ�, ���� ����� ��� �� ���� �𸣰ڳ�...
				// �� ��� �� ���ٴ� ��Ŷ� ��������...
				//cerr << "���տ� Į�� ���и� ���� �־, ���� ���⸦ ������ �� ����ϴ�." << endl;
				return;
			}
		}
		// ���տ� ������� ��� ���� ��� ����
		else 
		{
			char pField[80];

			// ����ʿ� ������� ���� ��� ����
			if (isWear(WEAR_RIGHTHAND))
			{
				pRight = getWearItem(WEAR_RIGHTHAND);
				// �䱸�� ������� ���� ����Ʈ�� �ִ´�.
				m_pWearItem[WEAR_RIGHTHAND] = pItem;
				m_pWearItem[WEAR_LEFTHAND]  = pItem;

				// by sigi. 2002.5.15
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
				sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
				pItem->tinysave(pField);

				// ���� �ִ� ������� ���콺 �����Ϳ� �޾� �ش�.
				addItemToExtraInventorySlot(pRight);
				//pRight->save(m_Name, STORAGE_EXTRASLOT, 0, 0, 0);
				sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
				pRight->tinysave(pField);
			}
			// ���ʿ� ������� ���� ��� ����
			else if (isWear(WEAR_LEFTHAND))
			{
				pLeft = getWearItem(WEAR_LEFTHAND);
				// �䱸�� ������� ���� ����Ʈ�� �ִ´�.
				m_pWearItem[WEAR_RIGHTHAND] = pItem;
				m_pWearItem[WEAR_LEFTHAND]  = pItem;

				// by sigi. 2002.5.15
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
				sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
				pItem->tinysave(pField);

				// ���� �ִ� ������� ���콺 �����Ϳ� �޾� �ش�.
				addItemToExtraInventorySlot(pLeft);
				//pLeft->save(m_Name, STORAGE_EXTRASLOT, 0, 0, 0);
				sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
				pLeft->tinysave(pField);
			}
			// �ƹ��ʵ� ������� ���� ���� ��� ����
			else
			{
				// �䱸�� ������� ���� ����Ʈ�� �ִ´�.
				m_pWearItem[WEAR_RIGHTHAND] = pItem;
				m_pWearItem[WEAR_LEFTHAND]  = pItem;

				// by sigi. 2002.5.15
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
				sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
				pItem->tinysave(pField);
			}
		}
	}
	else 
	{
		if (isWear(Part))
		{
			pPrevItem = getWearItem(Part);
			m_pWearItem[Part] = pItem;

			// by sigi. 2002.5.15
			char pField[80];
			//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
			sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
			pItem->tinysave(pField);

			addItemToExtraInventorySlot(pPrevItem);
			//pPrevItem->save(m_Name, STORAGE_EXTRASLOT, 0, 0, 0);
			sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
			pPrevItem->tinysave(pField);
		}
		else
		{
			// �䱸�� ������� ���� ����Ʈ�� �ִ´�.
			m_pWearItem[Part] = pItem;

			// by sigi. 2002.5.15
			char pField[80];
			//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
			sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
			pItem->tinysave(pField);
		}
	}

	// ���̶��� �ʿ� ���� ����� ����ش�.
	// ���߿����� �� Ÿ���� ���� ������ �� �� ������� �����ϴµ�,
	// �����μ��� �� Ÿ���� �ϳ��̹Ƿ�, ������ �������ش�.
	if (pItem->getItemClass() == Item::ITEM_CLASS_VAMPIRE_COAT) 
	{
		m_VampireInfo.setCoatColor( getItemShapeColor( pItem ) );

		// item type� ������ش�. 
		m_VampireInfo.setCoatType( pItem->getItemType() );
	}

	__END_CATCH
}


//----------------------------------------------------------------------
// Vampire::WearItem()
// Item� ����â�� ������Ű�� �ɷ�ġ�� �����Ѵ�.
//----------------------------------------------------------------------
void Vampire::wearItem(WearPart Part)
	throw()
{
	__BEGIN_TRY

	// ���� �غ����� ������� �޾ƿ´�.
	Item* pItem = getExtraInventorySlotItem();
	Assert(pItem != NULL);

	Item* pPrevItem = NULL;
	Item* pLeft = NULL;
	Item* pRight = NULL;

	// ���� ��� �����ų�, ������ ���� ������ �ɷ�ġ�� ���ۿ��� ������ �д�.
	// �̴� ���߿� ���� �ɷ�ġ��� �����ϱ� ��� ���̴�.
	VAMPIRE_RECORD prev;
	getVampireRecord(prev);

	// ���� ��ȹ������...�ɷ�ġ�� ���ڶ������� ������� ����� ������ ����
	// �ִ�. ������ �����ۿ� ���� �ɷ�ġ�� ������ ���� �ʴ´�. 
	// �׷��Ƿ� �ϴ� ������� �ش��ϴ� ����â���� �����ִ´�.
	char pField[80];

	// vampire ���� �߰�. 2002.8.16. by sigi
	// ���� ������ ���쿡�� ���� ����â���� �ϳ��� ������ �����͸� �Ҵ�...
	if (isTwohandWeapon(pItem))
	{
		// ���տ� ������� ���� ��� ����
		if (isWear(WEAR_RIGHTHAND) && isWear(WEAR_LEFTHAND))
		{
			pLeft  = getWearItem(WEAR_RIGHTHAND);
			pRight = getWearItem(WEAR_LEFTHAND);
			
			// ���� ���⸦ ���� ��� ����
			if (pLeft == pRight)
			{
				takeOffItem(WEAR_LEFTHAND, false, false);

				// �䱸�� ������� ���� ����Ʈ�� �ְ�,
				m_pWearItem[WEAR_RIGHTHAND] = pItem;
				m_pWearItem[WEAR_LEFTHAND]  = pItem;
				// by sigi. 2002.5.15
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
				sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
				pItem->tinysave(pField);

				// �䱸�� ������� ���콺 �����Ϳ��� ����Ѵ�.
				deleteItemFromExtraInventorySlot();
				// ���� �ִ� ������� ���콺 �����Ϳ� �޾� �ش�.
				addItemToExtraInventorySlot(pLeft);
				//pLeft->save(m_Name, STORAGE_EXTRASLOT, 0, 0, 0);
				sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
				pLeft->tinysave(pField);

			}
			// �˰� ���и� ���� ��� ����
			else
			{
				// ���տ� �˰� ���и� ���� �־��µ�...���� ���⸦ ����� �ϸ�,
				// ��� ���콺 �����Ϳ� �޾��� �� ������, ���д� ��� �� ���� ����.
				// �κ��丮�� �־����� �� �ٵ�, ���� ����� ��� �� ���� �𸣰ڳ�...
				// �� ��� �� ���ٴ� ��Ŷ� ��������...
				return;
			}
		}
		// ���տ� ������� ���� ���� ��� ����
		else 
		{
			// by sigi. 2002.5.15
			// ����ʿ� ������� ���� ��� ����
			if (isWear(WEAR_RIGHTHAND))
			{
				pRight = getWearItem(WEAR_RIGHTHAND);

				takeOffItem(WEAR_RIGHTHAND, false, false);

				// �䱸�� ������� ���� ����Ʈ�� �ִ´�.
				m_pWearItem[WEAR_RIGHTHAND] = pItem;
				m_pWearItem[WEAR_LEFTHAND]  = pItem;
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);

				// by sigi. 2002.5.15
				sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
				pItem->tinysave(pField);

				// �䱸�� ������� ���콺 �����Ϳ��� ����Ѵ�.
				deleteItemFromExtraInventorySlot();
				// ���� �ִ� ������� ���콺 �����Ϳ� �޾� �ش�.
				addItemToExtraInventorySlot(pRight);
				//pRight->save(m_Name, STORAGE_EXTRASLOT, 0, 0, 0);
				sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
				pRight->tinysave(pField);
				
			}
			// ���ʿ� ������� ���� ��� ����
			else if (isWear(WEAR_LEFTHAND))
			{
				pLeft = getWearItem(WEAR_LEFTHAND);
				
				takeOffItem(WEAR_LEFTHAND, false, false);

				// �䱸�� ������� ���� ����Ʈ�� �ִ´�.
				m_pWearItem[WEAR_RIGHTHAND] = pItem;
				m_pWearItem[WEAR_LEFTHAND]  = pItem;
				
				// by sigi. 2002.5.15
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
				sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
				pItem->tinysave(pField);

				// �䱸�� ������� ���콺 �����Ϳ��� ����Ѵ�.
				deleteItemFromExtraInventorySlot();
				// ���� �ִ� ������� ���콺 �����Ϳ� �޾� �ش�.
				addItemToExtraInventorySlot(pLeft);
				//pLeft->save(m_Name, STORAGE_EXTRASLOT, 0, 0, 0);
				sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
				pLeft->tinysave(pField);
			}
			// �ƹ��ʵ� ������� ���� ���� ��� ����
			else
			{
				// �䱸�� ������� ���� ����Ʈ�� �ִ´�.
				m_pWearItem[WEAR_RIGHTHAND] = pItem;
				m_pWearItem[WEAR_LEFTHAND]  = pItem;

				pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
				// �䱸�� ������� ���콺 �����Ϳ��� ����Ѵ�.
				deleteItemFromExtraInventorySlot();
			}
		}
	}
	else
	{
		if (isWear(Part))
		{
			pPrevItem = getWearItem(Part);
			takeOffItem(Part, false, false);
			m_pWearItem[Part] = pItem;

			// by sigi. 2002.5.15
			//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
			sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
			pItem->tinysave(pField);

			deleteItemFromExtraInventorySlot();
			addItemToExtraInventorySlot(pPrevItem);

			//pPrevItem->save(m_Name, STORAGE_EXTRASLOT, 0, 0, 0);
			sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
			pPrevItem->tinysave(pField);
		}
		else
		{
			m_pWearItem[Part] = pItem;
			deleteItemFromExtraInventorySlot();

			// by sigi. 2002.5.15
			//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
			sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
			pItem->tinysave(pField);
		}
	}

	initAllStat();
	sendRealWearingInfo();
	sendModifyInfo(prev);

	// ���̶��� �ʿ� ���� ����� ����ش�.
	// ���߿����� �� Ÿ���� ���� ������ �� �� ������� �����ϴµ�,
	// �����μ��� �� Ÿ���� �ϳ��̹Ƿ�, ������ �������ش�.

	// ��� �����Ǵ� �����۸� ����� �ٲ۴�. by sigi. 2002.10.30
	if (m_pRealWearingCheck[Part])
	{
		if (pItem->getItemClass() == Item::ITEM_CLASS_VAMPIRE_COAT) 
		{
			Color_t color = getItemShapeColor( pItem );
			m_VampireInfo.setCoatColor( color );
			m_VampireInfo.setCoatType( pItem->getItemType() );

			// ��� �����Ծ����, ������ٰ� �� �����Ծ��ٰ� ����� ������.
			GCChangeShape pkt;
			pkt.setObjectID(getObjectID());
			pkt.setItemClass(Item::ITEM_CLASS_VAMPIRE_COAT);
			pkt.setItemType(pItem->getItemType());
			pkt.setOptionType(pItem->getFirstOptionType());
			pkt.setAttackSpeed(m_AttackSpeed[ATTR_CURRENT]);

			if (color == QUEST_COLOR )
				pkt.setFlag( SHAPE_FLAG_QUEST );

			Zone* pZone = getZone();
			pZone->broadcastPacket(m_X, m_Y , &pkt, this);
		}
	}

	if (m_pZone != NULL)
	{
		GCOtherModifyInfo gcOtherModifyInfo;
		makeGCOtherModifyInfo(&gcOtherModifyInfo, this, &prev);

		if (gcOtherModifyInfo.getShortCount() != 0 || gcOtherModifyInfo.getLongCount() != 0)
		{
			m_pZone->broadcastPacket(m_X, m_Y, &gcOtherModifyInfo, this);
		}
	}
	
	__END_CATCH
}


//----------------------------------------------------------------------
//
// Vampire::takeOffItem()
//
//----------------------------------------------------------------------
void Vampire::takeOffItem(WearPart Part, bool bAddOnMouse, bool bSendModifyInfo)
	throw()
{
	__BEGIN_TRY

	VAMPIRE_RECORD prev;

	// ����â�� �ִ� ������� �޾ƿ´�.
	Item* pItem = m_pWearItem[Part];
	Assert(pItem != NULL);

	//m_pWearItem[Part] = NULL;

	// vampire ���� �߰�. 2002.8.16. by sigi
	// ����â�� �ִ� ������� �޾ƿ´�.
	//Item::ItemClass IClass = pItem->getItemClass();

	if (Part == WEAR_LEFTHAND || Part == WEAR_RIGHTHAND)
	{
		if (m_pWearItem[WEAR_RIGHTHAND] && m_pWearItem[WEAR_LEFTHAND])
		{
			if (m_pWearItem[WEAR_RIGHTHAND] == m_pWearItem[WEAR_LEFTHAND])
			{
				m_pWearItem[WEAR_RIGHTHAND] = NULL;
				m_pWearItem[WEAR_LEFTHAND] = NULL;
			}
		}
	}

	// ������� ��������Ʈ���� ����Ѵ�.
	if (isTwohandWeapon(pItem))
	{
		m_pWearItem[WEAR_RIGHTHAND] = NULL;
		m_pWearItem[WEAR_LEFTHAND] = NULL;
	}
	else m_pWearItem[Part] = NULL;

	// wearItem���� ����� ������ ��� �̹� �԰� �ִ� ���쿡, �װ�� ������
	// �ٽ� ��� �����µ�, �׷��� ���� �� ��Ŷ� �ѹ�, �Ծ�� �� �ٽ� ��Ŷ�
	// �ѹ�, �� �� ���� ��Ŷ� ������ �ȴ�. �װ�� �����ϱ� ��ؼ�
	// bool ������ �ϳ� �����־���. -- 2002.01.24 �輺��
	if (bSendModifyInfo)
	{
		getVampireRecord(prev);
		initAllStat();
		sendRealWearingInfo();
		sendModifyInfo(prev);
	}
	else
	{
		initAllStat();
	}

	//---------------------------------------------
	// �־ �ȵ� üũ -_-; �ӽ� ����
	// ������� ���콺 Ŀ������ �޾��ش�.
	//---------------------------------------------
	if (bAddOnMouse) 
	{
		addItemToExtraInventorySlot(pItem);
		//pItem->save(m_Name, STORAGE_EXTRASLOT, 0, 0, 0);
		// item���� ����ȭ. by sigi. 2002.5.13
		char pField[80];
        sprintf(pField, "Storage=%d, Durability=%d", STORAGE_EXTRASLOT, pItem->getDurability());
        pItem->tinysave(pField);
	}

	if (pItem->getItemClass() == Item::ITEM_CLASS_VAMPIRE_COAT)
	{
		m_VampireInfo.setCoatColor(377);
		m_VampireInfo.setCoatType( 0 );

		GCTakeOff pkt;
		pkt.setObjectID(getObjectID());
		pkt.setSlotID((SlotID_t)ADDON_COAT);
		m_pZone->broadcastPacket(getX(), getY(), &pkt, this);
	}

	if (m_pZone != NULL)
	{
		GCOtherModifyInfo gcOtherModifyInfo;
		makeGCOtherModifyInfo(&gcOtherModifyInfo, this, &prev);

		if (gcOtherModifyInfo.getShortCount() != 0 || gcOtherModifyInfo.getLongCount() != 0)
		{
			m_pZone->broadcastPacket(m_X, m_Y, &gcOtherModifyInfo, this);
		}
	}

	__END_CATCH
}




//----------------------------------------------------------------------
// destroyGears
// ���� ������� Delete �Ѵ�.
//----------------------------------------------------------------------
void Vampire::destroyGears() 
	throw ()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	for (int j = 0; j < VAMPIRE_WEAR_MAX; j++) 
	{
		Item* pItem = m_pWearItem[j];
		if (pItem != NULL)
		{
			Item::ItemClass IClass = pItem->getItemClass();

			//-------------------------------------------------------------
			// �����̾��� ������� �԰� �ִ� �̻��� �ڽ��� ����� �� �Ʈ
			//-------------------------------------------------------------
			Assert(IClass != Item::ITEM_CLASS_AR);
			Assert(IClass != Item::ITEM_CLASS_SR);
			Assert(IClass != Item::ITEM_CLASS_SG);
			Assert(IClass != Item::ITEM_CLASS_SMG);
			Assert(IClass != Item::ITEM_CLASS_SWORD);
			Assert(IClass != Item::ITEM_CLASS_BLADE);
			Assert(IClass != Item::ITEM_CLASS_SHIELD);
			Assert(IClass != Item::ITEM_CLASS_CROSS);
			Assert(IClass != Item::ITEM_CLASS_MACE);
			Assert(IClass != Item::ITEM_CLASS_HELM);
			Assert(IClass != Item::ITEM_CLASS_GLOVE);
			Assert(IClass != Item::ITEM_CLASS_TROUSER);
			Assert(IClass != Item::ITEM_CLASS_COAT);

			// ���� ���������� �˻��ؼ� ������ �ϳ��� �����鼭
			// ����� �����ش�.
			if (isTwohandWeapon(pItem))
			{
				m_pWearItem[WEAR_RIGHTHAND] = NULL;
				m_pWearItem[WEAR_LEFTHAND]  = NULL;
			}
			else m_pWearItem[j] = NULL;

			SAFE_DELETE(pItem);
		}
	}

	__END_DEBUG
	__END_CATCH
}

//----------------------------------------------------------------------
//----------------------------------------------------------------------
bool Vampire::isRealWearing(WearPart part) const
	throw()
{
	__BEGIN_TRY

	if (part >= VAMPIRE_WEAR_MAX) throw("Vampire::isRealWearing() : invalid wear point!");

	if (m_pWearItem[part] == NULL) return false;

	return isRealWearing(m_pWearItem[part]);

	__END_CATCH
}

//----------------------------------------------------------------------
//----------------------------------------------------------------------
bool Vampire::isRealWearing(Item* pItem) const
	throw()
{
	__BEGIN_TRY

	if (pItem == NULL) return false;

	ItemInfo*       pItemInfo = g_pItemInfoManager->getItemInfo(pItem->getItemClass(), pItem->getItemType());
	
	if ( pItem->isTimeLimitItem() )
	{
		Attr_t    ReqGender = pItemInfo->getReqGender();
		if ( ( m_Sex == MALE && ReqGender == GENDER_FEMALE ) ||
			 ( m_Sex == FEMALE && ReqGender == GENDER_MALE ) ) return false;
		return true;
	}

	// ����̾� ������� ��������ڸ� ���ũ/���� �������� �����ȴ�.
	// Ŀ�ø��� ��������ڸ� �� �� �ִ�. by Sequoia 2003. 3. 5.
	if (getZone()->isPremiumZone()
		&& (pItem->isUnique() || pItem->getOptionTypeSize()>1 ||
			pItem->getItemClass() == Item::ITEM_CLASS_COUPLE_RING || pItem->getItemClass() == Item::ITEM_CLASS_VAMPIRE_COUPLE_RING))
	{
		GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(getPlayer());
		if (!pGamePlayer->isPayPlaying() 
			&& !pGamePlayer->isPremiumPlay())
		{
			return false;
		}
	}

	if ( isCoupleRing( pItem ) ) return true;

	Item::ItemClass IClass    = pItem->getItemClass();
	Level_t         ReqLevel  = pItemInfo->getReqLevel();
	Attr_t          ReqGender = pItemInfo->getReqGender();

	// ���̽� �������� �䱸ġ�� ���� 100� ��� ���� �ɼ�� �����ؼ� �䱸ġ�� 150���� �ö��� �� �ִ�.
	// �׷��� ��� ���� �䱸ġ�� �ɼ�� �����ص� 100��� ��ѵȴ�.
	// 2003.3.21 by Sequoia
	Level_t			ReqLevelMax = ( ( ReqLevel > MAX_VAMPIRE_LEVEL_OLD ) ? MAX_VAMPIRE_LEVEL : MAX_VAMPIRE_LEVEL_OLD );

	// �������� �ɼ�� ������ �ִٸ�,
	// �ɼ��� ����� ������ �ɷ�ġ ���� �÷��ش�.
	const list<OptionType_t>& optionTypes = pItem->getOptionTypeList();
	list<OptionType_t>::const_iterator itr;

	for (itr=optionTypes.begin(); itr!=optionTypes.end(); itr++)
	{
		OptionInfo* pOptionInfo = g_pOptionInfoManager->getOptionInfo( *itr );
		ReqLevel += pOptionInfo->getReqLevel();
	}

	// 2003.1.6 by Sequoia, Bezz
	// 2003.3.21 �䱸ġ ��� ���� by Sequoia
	ReqLevel = min(ReqLevel, ReqLevelMax);
	
	// �ɷ�ġ ����� �ϳ����� �ִٸ�,
	// �� �ɷ�� �����Ű���� �˻��ؾ� �Ѵ�.
	if (ReqLevel > 0 || ReqGender != GENDER_BOTH)
	{
		if (ReqLevel > 0 && m_Level < ReqLevel) return false;
		if (m_Sex == MALE && ReqGender == GENDER_FEMALE) return false;
		if (m_Sex == FEMALE && ReqGender == GENDER_MALE) return false;
	}

	return true;

	__END_CATCH
}

//----------------------------------------------------------------------
//----------------------------------------------------------------------
bool Vampire::isRealWearingEx(WearPart part) const
{
	if (part >= VAMPIRE_WEAR_MAX) return false;
	return m_pRealWearingCheck[part];
}

DWORD Vampire::sendRealWearingInfo(void) const
	throw()
{
	__BEGIN_TRY

	DWORD info = 0;
	DWORD flag = 1;

	for (int i=0; i<VAMPIRE_WEAR_MAX; i++)
	{
		if (isRealWearing((Vampire::WearPart)i)) info |= flag;
		flag <<= 1;
	}

	GCRealWearingInfo pkt;
	pkt.setInfo(info);
	m_pPlayer->sendPacket(&pkt);

	return info;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
//
// ���� ���� �Լ�
//
//
////////////////////////////////////////////////////////////////////////////////

PCVampireInfo2* Vampire::getVampireInfo2 ()
	throw ()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	PCVampireInfo2* pInfo = new PCVampireInfo2();

	pInfo->setObjectID(m_ObjectID);
	pInfo->setName(m_Name);
	pInfo->setLevel(m_Level);
	pInfo->setSex(m_Sex);
	pInfo->setBatColor(m_BatColor);
	pInfo->setSkinColor(m_SkinColor);

    // ����
	pInfo->setAlignment(m_Alignment);

	// �ɷ�ġ
	pInfo->setSTR(m_STR[ATTR_CURRENT], ATTR_CURRENT);
	pInfo->setSTR(m_STR[ATTR_MAX], ATTR_MAX);
	pInfo->setSTR(m_STR[ATTR_BASIC], ATTR_BASIC);
	pInfo->setDEX(m_DEX[ATTR_CURRENT], ATTR_CURRENT);
	pInfo->setDEX(m_DEX[ATTR_MAX], ATTR_MAX);
	pInfo->setDEX(m_DEX[ATTR_BASIC], ATTR_BASIC);
	pInfo->setINT(m_INT[ATTR_CURRENT], ATTR_CURRENT);
	pInfo->setINT(m_INT[ATTR_MAX], ATTR_MAX);
	pInfo->setINT(m_INT[ATTR_BASIC], ATTR_BASIC);
	
	pInfo->setHP(m_HP[ATTR_CURRENT] , m_HP[ATTR_MAX]);
	pInfo->setFame(m_Fame);
	pInfo->setExp(m_GoalExp);
//	pInfo->setExp(m_Exp);
	pInfo->setGold(m_Gold);
	pInfo->setSight(m_Sight);
	pInfo->setBonus(m_Bonus);
	pInfo->setSilverDamage(m_SilverDamage);

	// by sigi. 2002.8.30
	pInfo->setRank(getRank());
	pInfo->setRankExp(getRankGoalExp());

//	for (int i = 0; i < 8; i++) 
//	{
//		pInfo->setHotKey(i, m_HotKey[i]);
//	}

	pInfo->setCompetence(m_CompetenceShape);
	pInfo->setGuildID(m_GuildID);
	pInfo->setGuildName( getGuildName() );
	pInfo->setGuildMemberRank( getGuildMemberRank() );

	return pInfo;

	__END_DEBUG
	__END_CATCH
}


//----------------------------------------------------------------------
// Vampire Outlook Information
//----------------------------------------------------------------------
PCVampireInfo3 Vampire::getVampireInfo3 () const 
	throw ()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	m_VampireInfo.setX(m_X);
	m_VampireInfo.setY(m_Y);
	m_VampireInfo.setDir(m_Dir);
	m_VampireInfo.setCurrentHP(m_HP[ATTR_CURRENT]);
	m_VampireInfo.setMaxHP(m_HP[ATTR_MAX]);
	m_VampireInfo.setAttackSpeed(m_AttackSpeed[ATTR_CURRENT]);
	m_VampireInfo.setAlignment(m_Alignment);
	m_VampireInfo.setGuildID(m_GuildID);

	// by sigi. 2002.9.10
	m_VampireInfo.setRank(getRank());

	/*
	Item* pItem = m_pWearItem[WEAR_BODY];
	if (pItem!=NULL)
	{
		m_VampireInfo.setCoatType( pItem->getItemType() );
	}
	else
	{
		m_VampireInfo.setCoatType( 0 );
	}
	*/


	if (m_Flag.test(Effect::EFFECT_CLASS_TRANSFORM_TO_WOLF)) 
	{
		m_VampireInfo.setShape(SHAPE_WOLF);
	} 
	else if (m_Flag.test(Effect::EFFECT_CLASS_TRANSFORM_TO_BAT)) 
	{
		m_VampireInfo.setShape(SHAPE_BAT);
	}
	else if (m_Flag.test(Effect::EFFECT_CLASS_TRANSFORM_TO_WERWOLF))
	{
		m_VampireInfo.setShape(SHAPE_WERWOLF);
	}
	else 
	{
		m_VampireInfo.setShape(SHAPE_NORMAL);
	}

	// ��������
	m_VampireInfo.setBatColor(m_BatColor);
	m_VampireInfo.setSkinColor(m_SkinColor);

	return m_VampireInfo;

	__END_DEBUG
	__END_CATCH
}

//----------------------------------------------------------------------
//
// get Extra Info
//
//----------------------------------------------------------------------
ExtraInfo* Vampire::getExtraInfo() const
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	BYTE ItemCount = 0;

	ExtraInfo* pExtraInfo = new ExtraInfo();

	Item* pItem = m_pExtraInventorySlot->getItem();

	if (pItem != NULL) {
	
//		Item::ItemClass IClass = pItem->getItemClass();

		ExtraSlotInfo* pExtraSlotInfo = new ExtraSlotInfo();
		pItem->makePCItemInfo( *pExtraSlotInfo );

/*		pExtraSlotInfo->setObjectID(pItem->getObjectID());
		pExtraSlotInfo->setItemClass(pItem->getItemClass());
		pExtraSlotInfo->setItemType(pItem->getItemType());
		pExtraSlotInfo->setOptionType(pItem->getOptionTypeList());
		pExtraSlotInfo->setDurability(pItem->getDurability());
		pExtraSlotInfo->setSilver(pItem->getSilver());
		pExtraSlotInfo->setSilver(pItem->getEnchantLevel());

		if (IClass == Item::ITEM_CLASS_AR) 
		{
			AR* pAR = dynamic_cast<AR*>(pItem);
			pExtraSlotInfo->setItemNum(pAR->getBulletCount());
		} 
		else if (IClass == Item::ITEM_CLASS_SG) 
		{
			SG* pSG = dynamic_cast<SG*>(pItem);
			pExtraSlotInfo->setItemNum(pSG->getBulletCount());
		} 
		else if (IClass == Item::ITEM_CLASS_SMG) 
		{
			SMG* pSMG = dynamic_cast<SMG*>(pItem);
			pExtraSlotInfo->setItemNum(pSMG->getBulletCount());
		} 
		else if (IClass == Item::ITEM_CLASS_SR) 
		{
			SR* pSR = dynamic_cast<SR*>(pItem);
			pExtraSlotInfo->setItemNum(pSR->getBulletCount());
		} 
		else 
		{
			pExtraSlotInfo->setItemNum(pItem->getNum());
		}

		// ��Ʈ���� Sub �������� �߰� ����� �ʿ��ϴ�.
		if (IClass == Item::ITEM_CLASS_BELT) 
		{
			Belt* pBelt = dynamic_cast<Belt*>(pItem);
			Inventory* pBeltInventory = ((Belt*)pItem)->getInventory();
			BYTE SubItemCount = 0;

			// ������ ���ڸ�ŭ �������� ����� �о� ���δ�.
			for (int i = 0; i < pBelt->getPocketCount(); i++) 
			{
				Item* pBeltItem = pBeltInventory->getItem(i, 0);

				if (pBeltItem != NULL) 
				{
					SubItemInfo* pSubItemInfo = new SubItemInfo();
					pSubItemInfo->setObjectID(pBeltItem->getObjectID());
					pSubItemInfo->setItemClass(pBeltItem->getItemClass());
					pSubItemInfo->setItemType(pBeltItem->getItemType());
					pSubItemInfo->setItemNum(pBeltItem->getNum());
					pSubItemInfo->setSlotID(i);

					pExtraSlotInfo->addListElement(pSubItemInfo);

					SubItemCount++;
				}
			}

			pExtraSlotInfo->setListNum(SubItemCount);

		}

		// ���� ���� Main Color ����� �׳� 0 ��� ���� �صд�.
		pExtraSlotInfo->setMainColor(0);*/
	
		pExtraInfo->addListElement(pExtraSlotInfo);

		ItemCount++;

	}

	pExtraInfo->setListNum(ItemCount);

	return pExtraInfo;

	__END_DEBUG
	__END_CATCH
}

//----------------------------------------------------------------------
//
// get Gear Info
//
//----------------------------------------------------------------------
GearInfo* Vampire::getGearInfo() const
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	int ItemCount = 0;

	GearInfo* pGearInfo = new GearInfo();

	for (int i = 0; i < VAMPIRE_WEAR_MAX; i++) 
	{
		Item* pItem = m_pWearItem[i];

		if (pItem != NULL) 
		{
			//Item::ItemClass IClass = pItem->getItemClass();

			GearSlotInfo* pGearSlotInfo = new GearSlotInfo();
			pItem->makePCItemInfo( *pGearSlotInfo );

/*			pGearSlotInfo->setObjectID(pItem->getObjectID());
			pGearSlotInfo->setItemClass(pItem->getItemClass());
			pGearSlotInfo->setItemType(pItem->getItemType());
			pGearSlotInfo->setOptionType(pItem->getOptionTypeList());
			pGearSlotInfo->setDurability(pItem->getDurability());
			pGearSlotInfo->setSilver(pItem->getSilver());
			pGearSlotInfo->setEnchantLevel(pItem->getEnchantLevel());*/

			/*
			// ��Ʈ���� Sub �������� �߰� ����� �ʿ��ϴ�.
			if (IClass == Item::ITEM_CLASS_BELT) {

				// ������ ������ �޾ƿ´�.
				ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo(pItem->getItemClass(), pItem->getItemType());
	
				// ������ ���ڸ� �޾ƿ´�.
				BYTE PocketNum = ((BeltInfo*)pItemInfo)->getPocketCount();
	
				// ��Ʈ�� �κ��丮�� �޾ƿ´�.
				Inventory* pBeltInventory = ((Belt*)pItem)->getInventory();
	
				BYTE SubItemCount = 0;
	
				// ������ ���ڸ�ŭ �������� ����� �о� ���δ�.
				for (int i = 0; i < PocketNum ; i++) {
	
					Item* pBeltItem = pBeltInventory->getItem(i, 0);
	
					if (pBeltItem != NULL) {
	
						SubItemInfo* pSubItemInfo = new SubItemInfo();
						pSubItemInfo->setObjectID(pBeltItem->getObjectID());
						pSubItemInfo->setItemClass(pBeltItem->getItemClass());
						pSubItemInfo->setItemType(pBeltItem->getItemType());
						pSubItemInfo->setItemNum(pBeltItem->getNum());
						pSubItemInfo->setSlotID(i);
	
						pGearSlotInfo->addListElement(pSubItemInfo);
	
						SubItemCount++;
					}
				}
	
				pGearSlotInfo->setListNum(SubItemCount);
			}
			*/

			pGearSlotInfo->setSlotID(i);
	
			// ���� ���� Main Color ����� �׳� 0 ��� ���� �صд�.
//			pGearSlotInfo->setMainColor(0);
		
			pGearInfo->addListElement(pGearSlotInfo);

			ItemCount++;

		}
	}

	pGearInfo->setListNum(ItemCount);

	return pGearInfo;

	__END_DEBUG
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// get Inventory Info
//////////////////////////////////////////////////////////////////////////////
InventoryInfo* Vampire::getInventoryInfo() const
    throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	BYTE ItemCount = 0;

	InventoryInfo* pInventoryInfo = new InventoryInfo();
	list<Item*> ItemList;
	VolumeHeight_t Height = m_pInventory->getHeight();
	VolumeWidth_t Width = m_pInventory->getWidth();

	for (int j = 0; j < Height; j++) 
	{
		for (int i = 0 ; i < Width ; i ++) 
		{
			if (m_pInventory->hasItem(i, j)) 
			{
				Item* pItem = m_pInventory->getItem(i , j);
				VolumeWidth_t ItemWidth = pItem->getVolumeWidth();
//				Item::ItemClass IClass = pItem->getItemClass();
				list<Item*>::iterator itr = find(ItemList.begin() , ItemList.end() , pItem);

				if (itr == ItemList.end()) 
				{
					ItemList.push_back(pItem);

					// InventorySlotInfo�� ����
					InventorySlotInfo* pInventorySlotInfo = new InventorySlotInfo();
					pItem->makePCItemInfo( *pInventorySlotInfo );
					pInventorySlotInfo->setInvenX(i);
					pInventorySlotInfo->setInvenY(j);

/*					pInventorySlotInfo->setObjectID(pItem->getObjectID());
					pInventorySlotInfo->setItemClass(pItem->getItemClass());
					pInventorySlotInfo->setItemType(pItem->getItemType());
					pInventorySlotInfo->setOptionType(pItem->getOptionTypeList());
					pInventorySlotInfo->setSilver(pItem->getSilver());
					pInventorySlotInfo->setDurability(pItem->getDurability());
					pInventorySlotInfo->setEnchantLevel(pItem->getEnchantLevel());
					pInventorySlotInfo->setInvenX(i);
					pInventorySlotInfo->setInvenY(j);
					pInventorySlotInfo->setItemNum(pItem->getNum());

					if (IClass == Item::ITEM_CLASS_AR) 
					{
						AR* pAR = dynamic_cast<AR*>(pItem);
						pInventorySlotInfo->setItemNum(pAR->getBulletCount());
					} 
					else if (IClass == Item::ITEM_CLASS_SG) 
					{
						SG* pSG = dynamic_cast<SG*>(pItem);
						pInventorySlotInfo->setItemNum(pSG->getBulletCount());
					} 
					else if (IClass == Item::ITEM_CLASS_SMG) 
					{
						SMG* pSMG = dynamic_cast<SMG*>(pItem);
						pInventorySlotInfo->setItemNum(pSMG->getBulletCount());
					} 
					else if (IClass == Item::ITEM_CLASS_SR) 
					{
						SR* pSR = dynamic_cast<SR*>(pItem);
						pInventorySlotInfo->setItemNum(pSR->getBulletCount());
					}
					else if (IClass == Item::ITEM_CLASS_PET_ITEM)
					{
						PetItem* pPetItem = dynamic_cast<PetItem*>(pItem);
						PetInfo* pPetInfo = pPetItem->getPetInfo();

						if ( pPetInfo != NULL )
						{
							pInventorySlotInfo->setOptionType( list<OptionType_t>(pPetInfo->getPetOption()) );
							pInventorySlotInfo->setDurability( pPetInfo->getPetHP() );
							pInventorySlotInfo->setEnchantLevel( pPetInfo->getPetAttr() );
							pInventorySlotInfo->setSilver( pPetInfo->getPetAttrLevel() );
							pInventorySlotInfo->setItemNum( pPetInfo->getPetLevel() );
						}
					}

					// ��Ʈ���� Sub �������� �߰� ����� �ʿ��ϴ�.
					if (IClass == Item::ITEM_CLASS_BELT) 
					{
						Belt* pBelt = dynamic_cast<Belt*>(pItem);
						Inventory* pBeltInventory = ((Belt*)pItem)->getInventory();

						BYTE SubItemCount = 0;

						// ������ ���ڸ�ŭ �������� ����� �о� ���δ�.
						for (int i = 0; i < pBelt->getPocketCount() ; i++) 
						{
							Item* pBeltItem = pBeltInventory->getItem(i, 0);
							if (pBeltItem != NULL) 
							{
								SubItemInfo* pSubItemInfo = new SubItemInfo();
								pSubItemInfo->setObjectID(pBeltItem->getObjectID());
								pSubItemInfo->setItemClass(pBeltItem->getItemClass());
								pSubItemInfo->setItemType(pBeltItem->getItemType());
								pSubItemInfo->setItemNum(pBeltItem->getNum());
								pSubItemInfo->setSlotID(i);

								pInventorySlotInfo->addListElement(pSubItemInfo);

								SubItemCount++;
							}
						}

						pInventorySlotInfo->setListNum(SubItemCount);
					}

					pInventorySlotInfo->setMainColor(0);*/

					pInventoryInfo->addListElement(pInventorySlotInfo);
					ItemCount++;
					i = i + ItemWidth - 1;
				}
			}
		}
	}

	pInventoryInfo->setListNum(ItemCount);

	return pInventoryInfo;

	__END_DEBUG
	__END_CATCH
}

//----------------------------------------------------------------------
// getSkillInfo
//----------------------------------------------------------------------
void Vampire::sendVampireSkillInfo()
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	VampireSkillInfo* pVampireSkillInfo = new VampireSkillInfo();

	BYTE SkillCount = 0;

	// ���� �ð�, ��� ĳ���� Ÿ��� �����ϱ� ���
	Timeval currentTime;
	getCurrentTime( currentTime );

	map<SkillType_t, VampireSkillSlot*>::const_iterator itr = m_SkillSlot.begin();
	for (; itr != m_SkillSlot.end(); itr++)
	{
		VampireSkillSlot* pVampireSkillSlot = itr->second;
		Assert(pVampireSkillSlot != NULL);

		// AttackMelee ���� �⺻ ���� ���� ����� �������� �ʾƾ� �Ѵ�.
		if (pVampireSkillSlot->getSkillType() >= SKILL_DOUBLE_IMPACT)
		{
			SubVampireSkillInfo* pSubVampireSkillInfo = new SubVampireSkillInfo();
			pSubVampireSkillInfo->setSkillType(pVampireSkillSlot->getSkillType());
			pSubVampireSkillInfo->setSkillTurn(pVampireSkillSlot->getInterval());
			// casting time �׸�� ��� ĳ���ñ��� ��� �ð���� �Ѵ�.
			//pSubVampireSkillInfo->setCastingTime(pVampireSkillSlot->getCastingTime());
			pSubVampireSkillInfo->setCastingTime(pVampireSkillSlot->getRemainTurn( currentTime ) );

			pVampireSkillInfo->addListElement(pSubVampireSkillInfo);

			SkillCount++;
		}
	}

	GCSkillInfo gcSkillInfo;
	gcSkillInfo.setPCType(PC_VAMPIRE);
	SkillType_t LearnSkillType = g_pSkillInfoManager->getSkillTypeByLevel(SKILL_DOMAIN_VAMPIRE , m_Level);

	// ���� �������� ���� �� �ִ� ������ �ִ��� ����.
	if (LearnSkillType != 0) 
	{
		// ���� �� �ִ� ������ �ְ� ������ ��� ���¶��� �������� �˷��ش�.
		if (hasSkill(LearnSkillType) == NULL) 
		{
			pVampireSkillInfo->setLearnNewSkill(true);
		}
	}

	pVampireSkillInfo->setListNum(SkillCount);

	gcSkillInfo.addListElement(pVampireSkillInfo);

	m_pPlayer->sendPacket(&gcSkillInfo);

	__END_DEBUG
	__END_CATCH
}



////////////////////////////////////////////////////////////////////////////////
//
//
// ��Ÿ �Լ�
//
//
////////////////////////////////////////////////////////////////////////////////
void Vampire::setGold(Gold_t gold)
	throw()
{
	__BEGIN_TRY

    // MAX_MONEY �� �Ѿ�� �� ���´�
	// 2003.1.8  by bezz.
	m_Gold = min( (Gold_t)MAX_MONEY, gold );

	__END_CATCH
}

void Vampire::setGoldEx(Gold_t gold)
	throw()
{
	__BEGIN_TRY

	setGold(gold);

	/*
	StringStream sql;
	sql << "Gold = " << (int)m_Gold;

	tinysave(sql.toString());
	*/

	// by sigi. 2002.5.15
	char pField[80];
	sprintf(pField, "Gold=%ld", m_Gold);
	tinysave(pField);

	__END_CATCH
}

void Vampire::increaseGoldEx(Gold_t gold)
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	// MAX_MONEY �� �Ѿ�� �� ���´�
	// 2003.1.8  by bezz.
	if ( m_Gold + gold > MAX_MONEY )
		gold = MAX_MONEY - m_Gold;

	setGold(m_Gold+gold);

    Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery("UPDATE Vampire SET Gold=Gold+%u WHERE NAME='%s'", gold, m_Name.c_str());
		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)


	__END_DEBUG
	__END_CATCH
}

void Vampire::decreaseGoldEx(Gold_t gold)
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	// 0 �̸��� �Ǵ� �� ���´�. 0 �̸��� �Ǹ� underflow �Ǽ� ������ ����.
	// 2003.1.8  by bezz.
	if ( m_Gold < gold )
        gold = m_Gold;
	
	setGold(m_Gold-gold);

    Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery("UPDATE Vampire SET Gold=Gold-%u WHERE NAME='%s'", gold, m_Name.c_str());
		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

	__END_DEBUG
	__END_CATCH
}

bool Vampire::checkGoldIntegrity()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	bool ret = false;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pResult = pStmt->executeQuery("SELECT Gold FROM Vampire WHERE NAME='%s'", m_Name.c_str());

		if ( pResult->next() )
		{
			ret = pResult->getInt(1) == m_Gold;
		}

		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

	return ret;

	__END_CATCH
}

bool Vampire::checkStashGoldIntegrity()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	bool ret = false;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pResult = pStmt->executeQuery("SELECT StashGold FROM Vampire WHERE NAME='%s'", m_Name.c_str());

		if ( pResult->next() )
		{
			ret = pResult->getInt(1) == m_StashGold;
		}

		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

	return ret;

	__END_CATCH
}


void Vampire::saveSilverDamage(Silver_t damage)
	throw()
{
	__BEGIN_TRY

	setSilverDamage(damage);

	/*
	StringStream sql;
	sql << "SilverDamage = " << (int)m_SilverDamage;
	tinysave(sql.toString());
	*/

	// by sigi. 2002.5.15
	char pField[80];
	sprintf(pField, "SilverDamage=%d", m_SilverDamage);
	tinysave(pField);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// ��� ������ hearbeat
//////////////////////////////////////////////////////////////////////////////
void Vampire::heartbeat(const Timeval& currentTime)
    throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

/*#ifdef __ACTIVE_QUEST__
	// by sigi. 2002.12.3
	if (m_pQuestManager!=NULL)
	{
		m_pQuestManager->heartbeat();
	}
#endif*/

	PlayerCreature::heartbeat( currentTime );

	// �ֱ������ HP�� ȸ�������ش�.
	if (m_HPRegenTime < currentTime)
	{
		Timeval diffTime = timediff(currentTime, m_HPRegenTime);

		if (diffTime.tv_sec > 0)
		{
			// 1. �����ִ� �����̰� (���� HP�� 0 �ʰ�)
			// 2. �ڸ� ����Ʈ�� �پ����� �ʴٸ�.
			// 3. Mephisto ����Ʈ�� �پ����� �ʴٸ�.
			if (isAlive() 
				&& !isFlag(Effect::EFFECT_CLASS_COMA)
				&& ( !isFlag(Effect::EFFECT_CLASS_MEPHISTO) || isFlag(Effect::EFFECT_CLASS_CASKET) )
			)
			{

				// by sigi. 2002.6.19
				bool bInCasket = isFlag(Effect::EFFECT_CLASS_CASKET);

				HP_t CurHP = m_HP[ATTR_CURRENT];
				HP_t NewHP = 0;

				// �� �ӿ� �ִ� ������
				// SilverDamage�� ���� ġ���Ѵ�.
				if (bInCasket && m_SilverDamage > 0)
				{
					NewHP = ( 10 + m_HPRegenBonus ) * diffTime.tv_sec;
					if ( isFlag( Effect::EFFECT_CLASS_HAS_BLOOD_BIBLE ) ) NewHP/=2;

					int remainSilver = (int)m_SilverDamage - (int)NewHP;

					// SilverDamage�� �� ġ���ϰ� HP�� ġ���ϴ� ����
					if (remainSilver < 0)
					{
						m_SilverDamage = 0;
						NewHP = -remainSilver;
				
						HP_t MaxHP = m_HP[ATTR_MAX];
						m_HP[ATTR_CURRENT] = min((int)MaxHP, (int)(CurHP + NewHP));
					}
					// SilverDamage�� ���ҽ�Ű�� ����
					else
					{
						m_SilverDamage = remainSilver;
					}
				}
				else
				{
					HP_t MaxHP = m_HP[ATTR_MAX] - getSilverDamage();

					// Normal       : 2
					// Burrow(Hide) : 4
					// Casket       : 6
					// Wolf         : 2 (�Ϲ� ���·� ����)
					// Bat          : 0
					if (isFlag(Effect::EFFECT_CLASS_HIDE))
					{
						NewHP = ( 4 + m_HPRegenBonus ) * diffTime.tv_sec;
					}
					else if (isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_BAT))
					{
						NewHP = 0;
					}
					// by sigi. 2002.6.19
					else if (isFlag(Effect::EFFECT_CLASS_CASKET))
					{
						NewHP = ( 10 + m_HPRegenBonus ) * diffTime.tv_sec;
					}
					else
					{
						NewHP = ( 2 + m_HPRegenBonus ) * diffTime.tv_sec;
					}

					if ( isFlag( Effect::EFFECT_CLASS_HAS_BLOOD_BIBLE ) ) NewHP/=2;
					m_HP[ATTR_CURRENT] = min((int)MaxHP, (int)(CurHP + NewHP));
				}
			}

			m_HPRegenTime.tv_sec = m_HPRegenTime.tv_sec + diffTime.tv_sec;
			m_HPRegenTime.tv_usec = m_HPRegenTime.tv_usec;
		}
	}

	/*

	list<Item*> ItemList;
	VolumeHeight_t Height = m_pInventory->getHeight();
	VolumeWidth_t Width = m_pInventory->getWidth();

	for (int j = 0; j < Height; j++) 
	{
		for (int i = 0 ; i < Width ; i ++) 
		{
			if (m_pInventory->hasItem(i, j)) 
			{
				Item* pItem = m_pInventory->getItem(i , j);
				VolumeWidth_t ItemWidth = pItem->getVolumeWidth();

				list<Item*>::iterator itr = find(ItemList.begin() , ItemList.end() , pItem);

				if (itr == ItemList.end()) 
				{
					ItemList.push_back(pItem);
					//������ ũ���� ��� �ġ ���� �˻��ϱ� ���.
					i = i + ItemWidth - 1;
				}
			}
		}
	}

	for (int i = 0; i < VAMPIRE_WEAR_MAX; i++) 
	{
		Item* pItem = m_pWearItem[i];
		if (pItem != NULL) ItemList.push_back(pItem);
	}

	Item* pSlotItem = m_pExtraInventorySlot->getItem();
	if (pSlotItem != NULL) 
	{
		ItemList.push_back(pSlotItem);
	}

	for (list<Item*>::iterator itr = ItemList.begin(); itr != ItemList.end(); itr++)
	{
		Item* pItem = *itr;
		pItem->getEffectManager()->heartbeat();
	}

	*/

	__END_DEBUG
	__END_CATCH
}

void Vampire::getVampireRecord(VAMPIRE_RECORD& record) const
	throw()
{
    __BEGIN_TRY

	record.pSTR[0]     = m_STR[0];
	record.pSTR[1]     = m_STR[1];
	record.pSTR[2]     = m_STR[2];

	record.pDEX[0]     = m_DEX[0];
	record.pDEX[1]     = m_DEX[1];
	record.pDEX[2]     = m_DEX[2];

	record.pINT[0]     = m_INT[0];
	record.pINT[1]     = m_INT[1];
	record.pINT[2]     = m_INT[2];

	record.pHP[0]      = m_HP[0];
	record.pHP[1]      = m_HP[1];

	record.pDamage[0]  = m_Damage[0];
	record.pDamage[1]  = m_Damage[1];

	record.Rank     = getRank();

	record.Defense     = m_Defense[0];
	record.ToHit       = m_ToHit[0];
	record.Protection  = m_Protection[0];
	record.AttackSpeed = m_AttackSpeed[0];

	__END_CATCH
}

void Vampire::setResurrectZoneIDEx(ZoneID_t id)
	throw()
{
	__BEGIN_TRY

	setResurrectZoneID(id);

	/*
	StringStream sql;
	sql << "ResurrectZone = " << (int)id;

	tinysave(sql.toString());
	*/

	// by sigi. 2002.5.15
	char pField[80];
	sprintf(pField, "ResurrectZone=%d", id);
	tinysave(pField);


	__END_CATCH
}

void Vampire::saveAlignment(Alignment_t alignment)
	    throw()
{
	__BEGIN_TRY

	setAlignment(alignment);

	/*
	StringStream sql;
	sql << "Alignment = " << (int)alignment;

	tinysave(sql.toString());
	*/
	// by sigi. 2002.5.15
	char pField[80];
	sprintf(pField, "Alignment=%d", alignment);
	tinysave(pField);

	__END_CATCH
}




//----------------------------------------------------------------------
// get debug string
//----------------------------------------------------------------------
string Vampire::toString () const
	throw ()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "Vampire("
		//<< "ObjectID:"   << (int)getObjectID()
		<< ",Name:"      << m_Name
		<< ",BatColor:" << (int)m_BatColor
		<< ",SkinColor:" << (int)m_SkinColor
		<< ",STR:"       << (int)m_STR[ATTR_CURRENT] << "/" << (int)m_STR[ATTR_MAX]
		<< ",DEX:"       << (int)m_DEX[ATTR_CURRENT] << "/" << (int)m_DEX[ATTR_MAX]
		<< ",INT:"       << (int)m_INT[ATTR_CURRENT] << "/" << (int)m_INT[ATTR_MAX]
		<< ",HP:"        << (int)m_HP[ATTR_CURRENT] << "/" << (int)m_HP[ATTR_MAX]
		<< ",Fame:"      << (int)m_Fame
//		<< ",Exp:"       << (int)m_Exp
//		<< ",ExpOffset:" << (int)m_ExpOffset
		<< ",Rank:"       << (int)getRank()
		<< ",RankGoalExp:" << (int)getRankGoalExp()
		<< ",Level:"     << (int)m_Level
		<< ",Bonus:"     << (int)m_Bonus
		//<< ",InMagics:'" << ??? << "'"
		<< ",Gold:"      << (int)m_Gold
		<< ",ZoneID:"    << (int)getZoneID()
		<< ",XCoord:"    << (int)m_X
		<< ",YCoord:"    << (int)m_Y
		<< ",Sight:"     << (int)m_Sight
		<< ")";

	return msg.toString();

	__END_CATCH
}

void Vampire::saveSkills(void) const 
	throw (Error)
{
	__BEGIN_TRY

	map<SkillType_t, VampireSkillSlot*>::const_iterator itr = m_SkillSlot.begin();
	for (; itr != m_SkillSlot.end(); itr++)
	{
		VampireSkillSlot* pVampireSkillSlot = itr->second;
		Assert(pVampireSkillSlot != NULL);

		// �⺻ ���� ��ų�� �ƴ϶���...
		if (pVampireSkillSlot->getSkillType() >= SKILL_DOUBLE_IMPACT)
		{
			pVampireSkillSlot->save(m_Name);
		}
	}

	__END_CATCH
}

IP_t Vampire::getIP(void) const
{
	Assert(m_pPlayer != NULL);
	Socket* pSocket = m_pPlayer->getSocket();
	Assert(pSocket != NULL);
	return pSocket->getHostIP();
}

void Vampire::saveGears(void) const
    throw (Error)
{
	__BEGIN_TRY

	// �����ϰ� �ִ� �����۵�� �����Ѵ�.
	char pField[80];

	for (int i=0; i < Vampire::VAMPIRE_WEAR_MAX; i++)
	{
		Item* pItem = m_pWearItem[i];
		if (pItem != NULL)
		{
			Durability_t maxDurability = computeMaxDurability(pItem);
			if (pItem->getDurability() < maxDurability)
			{
				//pItem->save(m_Name, STORAGE_GEAR, 0, i, 0);
				// item���� ����ȭ. by sigi. 2002.5.13
				sprintf(pField, "Durability=%d", pItem->getDurability());
				pItem->tinysave(pField);
			}
		}
	}

	__END_CATCH
}


void Vampire::saveExps(void) const
    throw (Error)
{
	__BEGIN_TRY

	// ��ų �ڵ鷯���� ���� ���ڸ� ���̱� ��ؼ� 10��� ������ �κе��,
	// ���� �ٿ��� ���� �ʰ�, �������� �α׾ƿ��ϴ� ���쿡 
	// ���̺긦 ��������� ������ ����� 10 ���� �ö��� �κ�� ���ư� �������� �ȴ�.
	// �׷��Ƿ� ���⼭ ���̺긦 �� �ش�. 
	/*
	StringStream sql;
	sql << "UPDATE Vampire SET "
		<< "Alignment = " << m_Alignment
		<< ",Fame = " << m_Fame
		<< ",Exp = " << m_Exp
		<< ",GoalExp = " << m_GoalExp;

	if (m_SilverDamage != 0)
	{
		sql << ",SilverDamage = " << m_SilverDamage;
	}

	sql << " WHERE Name = '" << m_Name << "'";
	*/

	Statement* pStmt = NULL;

	char silverDam[40];
	if (m_SilverDamage != 0)
	{
		sprintf(silverDam, ",SilverDamage = %d", m_SilverDamage);
	}
	else silverDam[0]='\0';

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery( "UPDATE Vampire SET Alignment=%d, Fame=%d, GoalExp=%lu%s, Rank=%d, RankGoalExp=%lu WHERE Name='%s'",
							m_Alignment, m_Fame, m_GoalExp, silverDam, getRank(), getRankGoalExp(), m_Name.c_str());

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	__END_CATCH
}


//----------------------------------------------------------------------
// getShapeInfo
//----------------------------------------------------------------------
// login�Ҷ� ó���� �����ϱ� ��ؼ���.
//----------------------------------------------------------------------
// �ϴ� 32bit�� 32������ ǥ���ϴ°ɷε� �����ϴٰ� ����.
// �����? over�Ǹ� bitset� ���߰���..
//
// (!) ����� index������ �ƴϰ� optionType� �־ �����Ѵ�.
//     Ŭ���̾�Ʈ���� �ɼ���� ����� ã�Ƽ� ����.
//
// colors[1]� coatColor�� �ֱ� �����̴�.
//----------------------------------------------------------------------
void Vampire::getShapeInfo (DWORD& flag, Color_t colors[PCVampireInfo::VAMPIRE_COLOR_MAX]) const
//	throw ()
{
	__BEGIN_DEBUG

	Item* 						pItem;
	//OptionInfo* 				pOptionInfo;
	int							vampireBit;
	int							vampireColor;
	WearPart					Part;

	// �ʱ�ȭ
	flag = 0;

	//-----------------------------------------------------------------
	// ����
	//-----------------------------------------------------------------
	Part = WEAR_BODY;
	pItem = m_pWearItem[Part];
	vampireBit = 0;
	vampireColor = 0;

	if (pItem!=NULL && m_pRealWearingCheck[Part])
	{
		ItemType_t IType = pItem->getItemType();

		colors[vampireColor] = getItemShapeColor( pItem );

		//colors[vampireColor] = pItem->getOptionType();
		//flag |= (getVampireCoatType(IType) << vampireBit);

		// itemType� �־��ش�.
		flag = IType;
	} 
	else 
	{
		colors[vampireColor] = 377;
		//flag |= (VAMPIRE_COAT_BASIC << vampireBit);
		// �⺻ �� :  ���ڴ� 0, ���ڴ� 1
		flag = (m_Sex? 0 : 1);
	}

	__END_DEBUG
}


//----------------------------------------------------------------------
// save InitialRank
//----------------------------------------------------------------------
// Rank, RankExp, RankGoalExp�� �ʱⰪ� �����Ѵ�.
//----------------------------------------------------------------------
void Vampire::saveInitialRank(void)
	throw()
{
	VAMPIRE_RECORD prev;
	getVampireRecord(prev);

	int curRank = max(1, (m_Level+3) / 4);
	m_pRank->SET_LEVEL(curRank);

/*	RankExp_t accumExp = 0;

	if (curRank!=1)
	{
		RankEXPInfo* pBeforeExpInfo = g_pRankEXPInfoManager[RANK_TYPE_VAMPIRE]->getRankEXPInfo(curRank-1);
		accumExp = pBeforeExpInfo->getAccumExp();
	}
	
	RankEXPInfo* pNextExpInfo = g_pRankEXPInfoManager[RANK_TYPE_VAMPIRE]->getRankEXPInfo(curRank);
	Exp_t NextGoalExp = pNextExpInfo->getGoalExp();

	setRankGoalExp(NextGoalExp);
*/

	char pField[80];
	sprintf(pField, "Rank=%d, RankExp=%lu, RankGoalExp=%lu",
					getRank(), getRankExp(), getRankGoalExp());
	tinysave(pField);
	setRankExpSaveCount(0);
	/*
	sendModifyInfo(prev);

	if (m_pZone != NULL)
	{
		GCOtherModifyInfo gcOtherModifyInfo;
		gcOtherModifyInfo.setObjectID(getObjectID());
		gcOtherModifyInfo.addShortData(MODIFY_RANK, curRank);

		m_pZone->broadcastPacket(m_X, m_Y, &gcOtherModifyInfo, this);
	}
	*/
}

bool
Vampire::addShape(Item::ItemClass IClass, ItemType_t IType, Color_t color)
{
	bool bisChange = false;

	switch (IClass)
	{
		case Item::ITEM_CLASS_VAMPIRE_COAT:
		{
			bisChange = true;

			m_VampireInfo.setCoatColor( color );
			m_VampireInfo.setCoatType( IType );
		}
		break;

		default:
			break;
	}

	return bisChange;
}


bool
Vampire::removeShape(Item::ItemClass IClass, bool bSendPacket)
{
    bool bisChange = false;

	switch (IClass)
	{
		case Item::ITEM_CLASS_VAMPIRE_COAT :
		{
			m_VampireInfo.setCoatColor(377);
			m_VampireInfo.setCoatType( 0 );

			if (bSendPacket)	// by sigi. 2002.11.6
			{
				GCTakeOff pkt;
				pkt.setObjectID(getObjectID());
				pkt.setSlotID((SlotID_t)ADDON_COAT);
				m_pZone->broadcastPacket(getX(), getY(), &pkt, this);
			}
		}
		break;

		default :
			return false;
	}

	return bisChange;
}

Color_t 
Vampire::getItemShapeColor(Item* pItem, OptionInfo* pOptionInfo) const
{
	Color_t color;

	if (pItem->isTimeLimitItem())
	{
		// ����Ʈ�� Ư��� ������ ��ü�ؼ� ó���Ѵ�.
		color = QUEST_COLOR;
	}
	else if (pItem->isUnique())
	{
		// ���ũ�� Ư��� ����� ��ü�ؼ� ó���Ѵ�.
		color = UNIQUE_COLOR;
	}
	// �ܺο��� �̹� OptionInfo�� ã� ����
	else if (pOptionInfo != NULL) 
	{
		color = pOptionInfo->getColor();
	}
	// �ƴϸ�.. ù��° �ɼ��� ����� ����Ѵ�.
	else if (pItem->getFirstOptionType() != 0)
	{
		OptionInfo* pOptionInfo = g_pOptionInfoManager->getOptionInfo(pItem->getFirstOptionType());
		color = pOptionInfo->getColor();
	}
	else 
	{
		// default ��
		color = 377;
	}

	return color;
}

bool Vampire::canPlayFree()
	throw(Error)
{
	__BEGIN_TRY

	return m_Level <= g_pVariableManager->getVariable(FREE_PLAY_VAMPIRE_LEVEL);

	__END_CATCH
}


bool Vampire::isPayPlayAvaiable() 
	throw(Error)
{
	__BEGIN_TRY

	if (m_pPlayer==NULL)
		return false;

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(m_pPlayer);

#ifdef __CONNECT_BILLING_SYSTEM__
	if (pGamePlayer->isPayPlaying())
	{
		// ���� ���� ������. ����
		if (pGamePlayer->getPayType()==PAY_TYPE_FREE)
			return true;

		// ��ѵ� �������� play����
		if (m_Level <= g_pVariableManager->getVariable(FREE_PLAY_VAMPIRE_LEVEL))
		{
			return true;
		}
	}

	return false;

// �ֵ��� ����� �������� �ʰ� ������ ���� �ϴ� ����
#elif defined(__PAY_SYSTEM_FREE_LIMIT__)

	if (!pGamePlayer->isPayPlaying())
	{
		// ��ѵ� �������� play����
		if (m_Level <= g_pVariableManager->getVariable(FREE_PLAY_VAMPIRE_LEVEL))
		{
			return true;
		}

		return false;
	}

	return true;

#else

	return pGamePlayer->isPayPlaying();

#endif


	__END_CATCH
}

void Vampire::initPetQuestTarget()
{
	int minClass = 1, maxClass = 1;

	if ( getLevel() <= 50 )
	{
		minClass = 8; maxClass = 9;
	}
	else if ( getLevel() <= 60 )
	{
		minClass = maxClass = 9;
	}
	else if ( getLevel() <= 70 )
	{
		minClass = maxClass = 10;
	}
	else if ( getLevel() <= 80 )
	{
		minClass = 10; maxClass = 11;
	}
	else if ( getLevel() <= 90 )
	{
		minClass = 10; maxClass = 11;
	}
	else if ( getLevel() <= 110 )
	{
		minClass = 11; maxClass = 12;
	}
	else if ( getLevel() <= 130 )
	{
		minClass = 11; maxClass = 12;
	}
	else
	{
		minClass = 12; maxClass = 13;
	}

	m_TargetMonster = g_pMonsterInfoManager->getRandomMonsterByClass( minClass, maxClass );
	m_TargetNum = 80;
	m_TimeLimit = 3600;
}
