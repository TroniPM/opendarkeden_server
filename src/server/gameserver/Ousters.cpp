//////////////////////////////////////////////////////////////////////////////
// Filename    : Ousters.cpp
// Written By  : Elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "Ousters.h"
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
#include "OustersEXPInfo.h"
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
#include <stdio.h>

#include "item/AR.h"
#include "item/SR.h"
#include "item/SG.h"
#include "item/SMG.h"
#include "item/Belt.h"
#include "item/Skull.h"
#include "item/OustersWristlet.h"
#include "item/OustersStone.h"
#include "item/OustersArmsband.h"

#include "skill/EffectBless.h"
#include "skill/EffectParalyze.h"
#include "skill/EffectDoom.h"
#include "skill/EffectTransformToWolf.h"
#include "skill/EffectTransformToBat.h"
#include "EffectGrandMasterOusters.h"
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

const Level_t MAX_OUSTERS_LEVEL = 150;

//////////////////////////////////////////////////////////////////////////////
// incraseOustersExp
//////////////////////////////////////////////////////////////////////////////
/*void Ousters::increaseOustersExp(Exp_t Point)
{
	if (Point <= 0) return;

	Level_t curLevel = getLevel();

	if (curLevel >= OUSTERS_MAX_LEVEL) 
	{
		// ���� �Ѱ迡 �����ص� ����ġ�� �װ� ���ش�.
		// by sigi. 2002.8.31
		Exp_t NewExp = getExp() + Point;

		WORD ExpSaveCount = getExpSaveCount();
		if (ExpSaveCount > OUSTERS_EXP_SAVE_PERIOD)
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
	if (NewGoalExp == 0 && curLevel < OUSTERS_MAX_LEVEL)
	{
		curLevel++;

		setLevel(curLevel);

		// add bonus point
		Bonus_t bonus = getBonus();

		if ((getSTR(ATTR_BASIC) + getDEX(ATTR_BASIC) + getINT(ATTR_BASIC) + getBonus() - 45) < ((getLevel() - 1) * 3)) 
		{
			// ������ ����ġ �ʰ�, ����� 3��� �����Ǿ���.
			// 2001.12.12 �輺��
			bonus += 3;
		}

		setBonus(bonus);

		OustersEXPInfo* pBeforeExpInfo = g_pOustersEXPInfoManager->getOustersEXPInfo(curLevel-1);
		OustersEXPInfo* pNextExpInfo = g_pOustersEXPInfoManager->getOustersEXPInfo(curLevel);
		Exp_t NextGoalExp = pNextExpInfo->getGoalExp();

		setGoalExp(NextGoalExp);

		char pField[80];
		sprintf(pField, "Level=%d, Exp=%u, GoalExp=%lu, Bonus=%d", 
						curLevel, pBeforeExpInfo->getAccumExp(), NextGoalExp, bonus);
		tinysave(pField);
		setExpSaveCount(0);
	}
	else
	{
		// �ֱ������ �����Ѵ�.
		WORD ExpSaveCount = getExpSaveCount();
		if (ExpSaveCount > OUSTERS_EXP_SAVE_PERIOD)
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
/*void Ousters::increaseRankExp(RankExp_t Point)
{
	if (Point <= 0) return;

	// PK� �ȿ����� ����ġ�� ���� �ʴ´�.
	if ( g_pPKZoneInfoManager->isPKZone( getZoneID() ) )
		return;

	Rank_t curRank = getRank();

	if (curRank >= OUSTERS_MAX_RANK)
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
	if (NewGoalExp == 0 && curRank < OUSTERS_MAX_RANK)
	{
		OUSTERS_RECORD prev;
		getOustersRecord(prev);

		curRank++;

		setRank(curRank);
		setRankExp(NewExp);
		setRankGoalExp(NewGoalExp);

		RankEXPInfo* pBeforeExpInfo = g_pRankEXPInfoManager[RANK_TYPE_OUSTERS]->getRankEXPInfo(curRank-1);
		RankEXPInfo* pNextExpInfo = g_pRankEXPInfoManager[RANK_TYPE_OUSTERS]->getRankEXPInfo(curRank);
		Exp_t NextGoalExp = pNextExpInfo->getGoalExp();

		setRankGoalExp(NextGoalExp);

		char pField[80];
		sprintf(pField, "Rank=%d, RankExp=%u, RankGoalExp=%lu",
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



Ousters::Ousters () 
	throw () 
: PlayerCreature(0, NULL)
{
	__BEGIN_TRY

	m_CClass = CREATURE_CLASS_OUSTERS;

	m_Mutex.setName("Ousters");

	// AttackMelee ��� �⺻ ����� �����־��ش�.
	for (int i=0; i<SKILL_DOUBLE_IMPACT; i++)
	{
		OustersSkillSlot* pOustersSkillSlot = new OustersSkillSlot;
		pOustersSkillSlot->setName(m_Name);
		pOustersSkillSlot->setSkillType(i);
		pOustersSkillSlot->setInterval(5);
		pOustersSkillSlot->setRunTime();

		addSkill(pOustersSkillSlot);
	}

	//////////////////////////////////////
	// �⺻ ��ų
	//////////////////////////////////////
	{
		OustersSkillSlot* pOustersSkillSlot = new OustersSkillSlot;
		pOustersSkillSlot->setName(m_Name);
		pOustersSkillSlot->setSkillType(SKILL_ABSORB_SOUL);
		pOustersSkillSlot->setExpLevel(1);
		pOustersSkillSlot->setInterval(5);
		pOustersSkillSlot->setRunTime();

		addSkill(pOustersSkillSlot);
	}
	{
		OustersSkillSlot* pOustersSkillSlot = new OustersSkillSlot;
		pOustersSkillSlot->setName(m_Name);
		pOustersSkillSlot->setSkillType(SKILL_SUMMON_SYLPH);
		pOustersSkillSlot->setExpLevel(1);
		pOustersSkillSlot->setInterval(5);
		pOustersSkillSlot->setRunTime();

		addSkill(pOustersSkillSlot);
	}

    for (int i = 0; i < OUSTERS_WEAR_MAX; i++) 
        m_pWearItem[i] = NULL;

	getCurrentTime(m_MPRegenTime);

	// ����ġ ���̺� ī��Ʈ �ʱ�ȭ
//	m_RankExpSaveCount		= 0;
	m_ExpSaveCount			= 0;
	m_FameSaveCount			= 0;
	m_AlignmentSaveCount	= 0;

	__END_CATCH
}

Ousters::~Ousters() 
    throw ()
{
	__BEGIN_TRY

	// ���� ����� �����صд�. by sigi. 2002.6.18
	char pField[128];
	sprintf(pField, "CoatType=%d,ArmType=%d,CoatColor=%d,ArmColor=%d,BootsColor=%d",
					m_OustersInfo.getCoatType(),
					m_OustersInfo.getArmType(),
					m_OustersInfo.getCoatColor(),
					m_OustersInfo.getArmColor(),
					m_OustersInfo.getBootsColor() );

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
	map<SkillType_t, OustersSkillSlot*>::iterator itr = m_SkillSlot.begin();
	for (; itr != m_SkillSlot.end(); itr++)
	{
		OustersSkillSlot* pOustersSkillSlot = itr->second;
		SAFE_DELETE(pOustersSkillSlot);
	}

	__END_CATCH
}

// registerObject
// Zone�� ��ӵ� ObjectRegistry�� �����ؼ�, Ousters �� ��������۵���
// ObjectID�� �Ҵ��޴´�.
void Ousters::registerObject ()
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

	// �켱 �ƿ콺�ͽ��� OID�� ���Ϲ޴´�.
	OR.registerObject_NOLOCKED(this);

	// �κ��丮�� �����۵��� OID�� ���Ϲ޴´�.
	registerInventory(OR);

	// Goods Inventory�� �����۵��� OID�� ���Ϲ޴´�.
	registerGoodsInventory(OR);

	// �����ϰ� �ִ� �����۵��� OID�� ���Ϲ޴´�.
	for (int i = 0; i < OUSTERS_WEAR_MAX; i++) 
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

	m_OustersInfo.setObjectID(m_ObjectID);

    __END_CATCH
}

// Zone�� ��ӵ� ObjectRegistry�� �����ؼ�, Ousters �� ��������۵���
// ObjectID�� �Ҵ��޴´�. ItemTrace �� ������ ���� ���� ��� ���� ����
void Ousters::registerInitObject ()
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

	// �켱 �ƿ콺�ͽ��� OID�� ���Ϲ޴´�.
	OR.registerObject_NOLOCKED(this);

	// �κ��丮�� �����۵��� OID�� ���Ϲ޴´�.
	registerInitInventory(OR);

	// Goods Inventory�� �����۵��� OID�� ���Ϲ޴´�.
	registerGoodsInventory(OR);

	// �����ϰ� �ִ� �����۵��� OID�� ���Ϲ޴´�.
	for (int i = 0; i < OUSTERS_WEAR_MAX; i++) 
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

	m_OustersInfo.setObjectID(m_ObjectID);

    __END_CATCH
}

// �ð���� ������� üũ�Ѵ�.
// ���� �������� �̹� register �Ǿ��־��� �Ѵ�.
void Ousters::checkItemTimeLimit() throw (Error)
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
		for (int i = 0; i < OUSTERS_WEAR_MAX; i++) 
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
//	Ousters�� Slayer������ ����� ��ؼ�
//	���� �ε�� ���� ó���Ѵ�.
//
void Ousters::loadItem( bool checkTimeLimit )
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

	PlayerCreature::loadGoods();

	// �ε��� �����۵�� ���Ͻ�Ű��
    registerInitObject();

	// ó� ����� ������ ���� �ʺ��ڿ� �����ۼ�Ʈ�� �ϴ� �� ���..
	if( !m_pFlagSet->isOn( FLAGSET_RECEIVE_NEWBIE_ITEM_AUTO ) )
	{
		addNewbieItemToInventory( this );
		addNewbieGoldToInventory( this );
		addNewbieItemToGear( this );
		// �־�� ���� ���ٴ� �÷��׸� ���ش�.
		m_pFlagSet->turnOn( FLAGSET_RECEIVE_NEWBIE_ITEM_AUTO );
		m_pFlagSet->save( getName() );
	}

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
bool Ousters::load ()
	throw (InvalidProtocolException, Error)
{
	__BEGIN_TRY

	Statement* pStmt   = NULL;
	Result*    pResult = NULL;

	BEGIN_DB
	{
		pStmt   = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery(
			"SELECT Name, Sex,"
			"STR, DEX, INTE, HP, CurrentHP, MP, CurrentMP, Fame, "
			"GoalExp, Level, Bonus, SkillBonus, Gold, GuildID,"
			"ZoneID, XCoord, YCoord, Sight, Alignment, "
			"StashGold, StashNum, Competence, CompetenceShape, ResurrectZone, SilverDamage,"
			"Rank, RankGoalExp, HairColor FROM Ousters WHERE Name = '%s' AND Active = 'ACTIVE'",
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

		setMP(pResult->getInt(++i) , ATTR_MAX);
		setMP(getMP(ATTR_MAX) , ATTR_BASIC);
		setMP(pResult->getInt(++i) , ATTR_CURRENT);
		
		setFame(pResult->getInt(++i));

//		setExp(pResult->getInt(++i));
		setGoalExp(pResult->getInt(++i));
//		setExpOffset(pResult->getInt(++i));
		setLevel(pResult->getInt(++i));
		setBonus(pResult->getInt(++i));
		setSkillBonus(pResult->getInt(++i));

		setGold(pResult->getInt(++i));
		setGuildID(pResult->getInt(++i));

		ZoneID_t zoneID = pResult->getInt(++i);
		setX(pResult->getInt(++i));
		setY(pResult->getInt(++i));

		setSight (pResult->getInt(++i));

		setAlignment(pResult->getInt(++i));

		setStashGold(pResult->getInt(++i));
		setStashNum(pResult->getBYTE(++i));
		
		m_Competence = pResult->getBYTE(++i);

		if ( m_Competence >= 4 )
			m_Competence = 3;

		m_CompetenceShape = pResult->getBYTE(++i);

		setResurrectZoneID(pResult->getInt(++i));
		setSilverDamage(pResult->getInt(++i));

		Rank_t CurRank               = pResult->getInt(++i);
		RankExp_t RankGoalExp        = pResult->getInt(++i);

		m_pRank = new Rank( CurRank, RankGoalExp, RankExpTable::s_RankExpTables[RANK_TYPE_OUSTERS] );

//		setRank( pResult->getInt(++i) );
//		setRankExp( pResult->getInt(++i) );
//		setRankGoalExp( pResult->getInt(++i) );

		setHairColor(pResult->getInt(++i));

		// maxHP�� �ٽ� �����ؼ� ������ش�.
		// 2002.7.15 by sigi
		// ���� �ٲ��� AbilityBalance.cpp�� computeHP�� ����ؾ��Ѵ�.
		int maxHP = m_STR[ATTR_CURRENT]*2 + m_INT[ATTR_CURRENT] + m_DEX[ATTR_CURRENT] + m_Level;
		maxHP = min((int)maxHP, OUSTERS_MAX_HP);
		setHP( maxHP, ATTR_MAX );

		setZoneID( zoneID );

		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

	//----------------------------------------------------------------------
	// Ousters Outlook Information � �����Ѵ�.
	//----------------------------------------------------------------------
	// �ƿ콺�ͽ��� �ε��Ҷ� ObjectID�� ���� �ϵ��� �Ѵ�.
	m_OustersInfo.setObjectID(m_ObjectID);
	m_OustersInfo.setName(m_Name);
	m_OustersInfo.setSex(m_Sex);
	m_OustersInfo.setHairColor(m_HairColor);

	m_OustersInfo.setCompetence(m_CompetenceShape);

    //----------------------------------------------------------------------
	// ��ų� �ε��Ѵ�.
	//----------------------------------------------------------------------
	BEGIN_DB
	{
		pStmt   = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery("SELECT SkillType, SkillLevel, Delay, CastingTime, NextTime FROM OustersSkillSave WHERE OwnerID = '%s'", m_Name.c_str());
	
		while(pResult->next()) 
		{
			int         i          = 0;
			SkillType_t SkillType = pResult->getInt(++i);

			if (hasSkill(SkillType) == NULL) 
			{
				OustersSkillSlot* pOustersSkillSlot = new OustersSkillSlot();
		
				pOustersSkillSlot->setName(m_Name);
				pOustersSkillSlot->setSkillType(SkillType);
				pOustersSkillSlot->setExpLevel(pResult->getInt(++i));
				pOustersSkillSlot->setInterval (pResult->getInt(++i));
				pOustersSkillSlot->setCastingTime (pResult->getInt(++i));
				pOustersSkillSlot->setRunTime();
		
				addSkill(pOustersSkillSlot);
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
		if (!isFlag(Effect::EFFECT_CLASS_GRAND_MASTER_OUSTERS))
		{
			EffectGrandMasterOusters* pEffect = new EffectGrandMasterOusters(this);
			pEffect->setDeadline(999999);
			getEffectManager()->addEffect( pEffect );
			setFlag(Effect::EFFECT_CLASS_GRAND_MASTER_OUSTERS);
		}
	}

	//----------------------------------------------------------------------
	// �÷��� ��� �ε��Ѵ�.
	//----------------------------------------------------------------------
	m_pFlagSet->load(getName());

	//----------------------------------------------------------------------
	// Ousters Outlook Information � �ʱ�ȭ�Ѵ�.
	//----------------------------------------------------------------------
	m_OustersInfo.setCoatType(OUSTERS_COAT_BASIC);
	m_OustersInfo.setArmType(OUSTERS_ARM_GAUNTLET);
	m_OustersInfo.setSylphType(OUSTERS_SYLPH_NONE);
	m_OustersInfo.setHairColor(m_HairColor);

	m_OustersInfo.setCoatColor( 377 );

	// �߸��� ����ġ�� ���� ���ش�.
/*	OustersEXPInfo* pOustersEXPInfo = g_pOustersEXPInfoManager->getOustersEXPInfo(m_Level);

	if ( (pOustersEXPInfo->getAccumExp() != m_Exp + m_GoalExp) 
		&& m_Level > 1 && m_Level < OUSTERS_MAX_LEVEL ) 
	{
		// ���� ���� ����ġ = ���� ������ �� ����ġ - ��ǥ ����ġ
		m_Exp = pOustersEXPInfo->getAccumExp() - m_GoalExp;

		char pField[80];
		sprintf(pField, "Exp=%lu", m_Exp);
		tinysave(pField);
	}
*/
	// rank�� 0�̸� �ʱⰪ�� ������� �ʾҴٴ� �ǹ��̴�. by sigi. 2002.9.13
	if (getRank()==0)
	{
		saveInitialRank();
	}


	// �߸��� ����� ���� ���ش�.
/*	RankEXPInfo* pRankEXPInfo = g_pRankEXPInfoManager[RANK_TYPE_OUSTERS]->getRankEXPInfo(m_Rank);

	if ((pRankEXPInfo->getAccumExp() != m_RankExp + m_RankGoalExp) 
		&& m_Rank > 1 && m_Rank < OUSTERS_MAX_RANK) 
	{
		m_RankExp = pRankEXPInfo->getAccumExp() - m_RankGoalExp;

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
void Ousters::save () const
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	Statement* pStmt;

	//--------------------------------------------------------------------------------
	// �ƿ콺�ͽ� ����� �����Ѵ�.
	//--------------------------------------------------------------------------------
	BEGIN_DB
	{
		StringStream sql;
		sql << "UPDATE Ousters SET"
			<< " CurrentHP = " << (int)m_HP[ATTR_CURRENT]
			<< ", HP = " << (int)m_HP[ATTR_MAX]
			<< ", CurrentMP = " << (int)m_MP[ATTR_CURRENT]
			<< ", MP = " << (int)m_MP[ATTR_MAX]
			<< ", ZoneID = " << (int)getZoneID()
			<< ", XCoord = " << (int)m_X
			<< ", YCoord = " << (int)m_Y
			<< " WHERE Name = '" << m_Name << "'";
		
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		pStmt->executeQuery(sql.toString());

		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

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
void Ousters::tinysave(const string & field)	// by sigi. 2002.5.15
	    const throw(Error)
{
    __BEGIN_TRY

    Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery("UPDATE Ousters SET %s WHERE Name='%s'", field.c_str(), m_Name.c_str());
		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

    __END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ������ skill bonus ����Ʈ�� �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////
SkillBonus_t Ousters::getSumOfUsedSkillBonus() const
	throw()
{
	__BEGIN_TRY

	return 0;

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
OustersSkillSlot* Ousters::getSkill (SkillType_t SkillType) const 
	throw()
{
	__BEGIN_TRY

	map<SkillType_t, OustersSkillSlot*>::const_iterator itr = m_SkillSlot.find(SkillType);
	if (itr != m_SkillSlot.end())
	{
		return itr->second;
	}

	return NULL;

	__END_CATCH
}

// Ư� Skill� add �Ѵ�
void Ousters::addSkill(SkillType_t SkillType)
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
		case SKILL_HOWL:
			filelog("OustersError.log", "SkillType[%d], %s", SkillType, toString().c_str());
			Assert(false);
			break;
		default:
			break;
	}

	map<SkillType_t, OustersSkillSlot*>::iterator itr = m_SkillSlot.find(SkillType);

	if (itr == m_SkillSlot.end())
	{
		SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);
		Turn_t Delay = pSkillInfo->getMaxDelay();

		OustersSkillSlot* pOustersSkillSlot = new OustersSkillSlot;

		pOustersSkillSlot->setName(m_Name);
		pOustersSkillSlot->setSkillType(SkillType);
		pOustersSkillSlot->setInterval(Delay);
		pOustersSkillSlot->setRunTime();
		pOustersSkillSlot->setExpLevel(1);
		pOustersSkillSlot->create(m_Name);

		m_SkillSlot[SkillType] = pOustersSkillSlot;
	}

	__END_CATCH
}

// Ư� SkillSlot� �ڵ���� �� ����� ã�� �ִ´�.
void Ousters::addSkill(OustersSkillSlot* pOustersSkillSlot)
	throw()
{
	__BEGIN_TRY

	SkillType_t SkillType = pOustersSkillSlot->getSkillType();
	switch (SkillType)
	{
		case SKILL_UN_BURROW:
		case SKILL_UN_TRANSFORM:
		case SKILL_UN_INVISIBILITY:
		case SKILL_THROW_HOLY_WATER:
		case SKILL_EAT_CORPSE:
		case SKILL_HOWL:
			filelog("OustersError.log", "SkillType[%d], %s", SkillType, toString().c_str());
			Assert(false);
			break;
		default:
			break;
	}

	map<SkillType_t, OustersSkillSlot*>::iterator itr = m_SkillSlot.find(pOustersSkillSlot->getSkillType());
	
	if (itr == m_SkillSlot.end())
	{
		m_SkillSlot[pOustersSkillSlot->getSkillType()] = pOustersSkillSlot;
	}
	// 2002.1.16 by sigi
	else
	{
		delete pOustersSkillSlot;
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
// Ousters::WearItem()
//
// Item� ����â�� ������Ű�� �ɷ�ġ�� �����Ѵ�.
//
//----------------------------------------------------------------------
void Ousters::wearItem(WearPart Part, Item* pItem)
	throw()
{
	__BEGIN_TRY

	Assert(pItem != NULL);

	Item* pPrevItem = NULL;
	Item* pLeft = NULL;
	Item* pRight = NULL;

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
				sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
				pItem->tinysave(pField);

				// ���� �ִ� ������� ���콺 �����Ϳ� �޾� �ش�.
				addItemToExtraInventorySlot(pLeft);
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
		// ���տ� ������� ���� ���� ��� ����
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
				sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
				pItem->tinysave(pField);

				// ���� �ִ� ������� ���콺 �����Ϳ� �޾� �ش�.
				addItemToExtraInventorySlot(pRight);
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
				sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
				pItem->tinysave(pField);

				// ���� �ִ� ������� ���콺 �����Ϳ� �޾� �ش�.
				addItemToExtraInventorySlot(pLeft);
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
			sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
			pItem->tinysave(pField);

			addItemToExtraInventorySlot(pPrevItem);
			sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
			pPrevItem->tinysave(pField);
		}
		else
		{
			// �䱸�� ������� ���� ����Ʈ�� �ִ´�.
			m_pWearItem[Part] = pItem;

			// by sigi. 2002.5.15
			char pField[80];
			sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
			pItem->tinysave(pField);
		}
	}

	// ���̶��� �ʿ� ���� ����� ����ش�.
	// ���߿����� �� Ÿ���� ���� ������ �� �� ������� �����ϴµ�,
	// �����μ��� �� Ÿ���� �ϳ��̹Ƿ�, ������ �������ش�.
	switch ( pItem->getItemClass() )
	{
		case Item::ITEM_CLASS_OUSTERS_COAT:
			// item type� ������ش�. 
			m_OustersInfo.setCoatType( getOustersCoatType( pItem->getItemType() ) );
			m_OustersInfo.setCoatColor( getItemShapeColor( pItem ) );
			break;
		case Item::ITEM_CLASS_OUSTERS_CHAKRAM:
			m_OustersInfo.setArmType( OUSTERS_ARM_CHAKRAM );
			m_OustersInfo.setArmColor( getItemShapeColor( pItem ) );
			break;
		case Item::ITEM_CLASS_OUSTERS_WRISTLET:
			m_OustersInfo.setArmType( OUSTERS_ARM_GAUNTLET );
			m_OustersInfo.setArmColor( getItemShapeColor( pItem ) );
			break;
		case Item::ITEM_CLASS_OUSTERS_BOOTS:
			m_OustersInfo.setBootsColor( getItemShapeColor( pItem ) );
			break;
		default:
			break;
	}

	__END_CATCH
}


//----------------------------------------------------------------------
// Ousters::WearItem()
// Item� ����â�� ������Ű�� �ɷ�ġ�� �����Ѵ�.
//----------------------------------------------------------------------
void Ousters::wearItem(WearPart Part)
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
	OUSTERS_RECORD prev;
	getOustersRecord(prev);

	char pField[80];

	// ���� ������ ���쿡�� ���� ����â���� �ϳ��� ������ �����͸� �Ҵ�...
	if (isTwohandWeapon(pItem))
	{
		// ���տ� ������� ���� ��� ���
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
				sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
				pItem->tinysave(pField);

				// �䱸�� ������� ���콺 �����Ϳ��� ����Ѵ�.
				deleteItemFromExtraInventorySlot();
				// ���� �ִ� ������� ���콺 �����Ϳ� �޾� �ش�.
				addItemToExtraInventorySlot(pLeft);
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

				// by sigi. 2002.5.15
				sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
				pItem->tinysave(pField);

				// �䱸�� ������� ���콺 �����Ϳ��� ����Ѵ�.
				deleteItemFromExtraInventorySlot();
				// ���� �ִ� ������� ���콺 �����Ϳ� �޾� �ش�.
				addItemToExtraInventorySlot(pRight);
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
				sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
				pItem->tinysave(pField);

				// �䱸�� ������� ���콺 �����Ϳ��� ����Ѵ�.
				deleteItemFromExtraInventorySlot();
				// ���� �ִ� ������� ���콺 �����Ϳ� �޾� �ش�.
				addItemToExtraInventorySlot(pLeft);
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
			sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
			pItem->tinysave(pField);

			deleteItemFromExtraInventorySlot();
			addItemToExtraInventorySlot(pPrevItem);

			sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
			pPrevItem->tinysave(pField);
		}
		else
		{
			m_pWearItem[Part] = pItem;
			deleteItemFromExtraInventorySlot();

			// by sigi. 2002.5.15
			sprintf(pField, "Storage=%d, X=%d", STORAGE_GEAR, Part);
			pItem->tinysave(pField);
		}
	}

	initAllStat();
	sendRealWearingInfo();
	sendModifyInfo(prev);

	// ��� �����Ǵ� �����۸� ����� �ٲ۴�. by sigi. 2002.10.30
	if (m_pRealWearingCheck[Part])
	{
		if ( pItem->getItemClass() == Item::ITEM_CLASS_OUSTERS_COAT
			|| pItem->getItemClass() == Item::ITEM_CLASS_OUSTERS_WRISTLET
			|| pItem->getItemClass() == Item::ITEM_CLASS_OUSTERS_CHAKRAM
			|| pItem->getItemClass() == Item::ITEM_CLASS_OUSTERS_BOOTS ) 
		{
			Color_t color = getItemShapeColor( pItem );

			// ��� �����Ծ����, ������ٰ� �� �����Ծ��ٰ� ����� ������.
			GCChangeShape pkt;
			pkt.setObjectID(getObjectID());
			pkt.setItemClass(pItem->getItemClass());
			pkt.setItemType(pItem->getItemType());
			pkt.setOptionType(pItem->getFirstOptionType());
			pkt.setAttackSpeed(m_AttackSpeed[ATTR_CURRENT]);

			if ( color == QUEST_COLOR )
				pkt.setFlag( SHAPE_FLAG_QUEST );

			Zone* pZone = getZone();
			pZone->broadcastPacket(m_X, m_Y , &pkt, this);

			// PCOustersInfo3 ����� �ٲ��ش�.
			switch ( pItem->getItemClass() )
			{
				case Item::ITEM_CLASS_OUSTERS_COAT:
					// item type� ������ش�. 
					m_OustersInfo.setCoatType( getOustersCoatType( pItem->getItemType() ) );
					m_OustersInfo.setCoatColor( color );
					break;
				case Item::ITEM_CLASS_OUSTERS_CHAKRAM:
					m_OustersInfo.setArmType( OUSTERS_ARM_CHAKRAM );
					m_OustersInfo.setArmColor( color );
					break;
				case Item::ITEM_CLASS_OUSTERS_WRISTLET:
					m_OustersInfo.setArmType( OUSTERS_ARM_GAUNTLET );
					m_OustersInfo.setArmColor( color );
					break;
				case Item::ITEM_CLASS_OUSTERS_BOOTS:
					m_OustersInfo.setBootsColor( color );
					break;
				default:
					break;
			}
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
// Ousters::takeOffItem()
//
//----------------------------------------------------------------------
void Ousters::takeOffItem(WearPart Part, bool bAddOnMouse, bool bSendModifyInfo)
	throw()
{
	__BEGIN_TRY

	OUSTERS_RECORD prev;

	// ����â�� �ִ� ������� �޾ƿ´�.
	Item* pItem = m_pWearItem[Part];
	Assert(pItem != NULL);

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
		getOustersRecord(prev);
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
		// item���� ����ȭ. by sigi. 2002.5.13
		char pField[80];
        sprintf(pField, "Storage=%d, Durability=%d", STORAGE_EXTRASLOT, pItem->getDurability());
        pItem->tinysave(pField);
	}

	switch ( pItem->getItemClass() )
	{
		case Item::ITEM_CLASS_OUSTERS_COAT:
			{
				m_OustersInfo.setCoatType( OUSTERS_COAT_BASIC );
				m_OustersInfo.setCoatColor( 377 );
				GCTakeOff pkt;
				pkt.setObjectID(getObjectID());
				pkt.setSlotID((SlotID_t)ADDON_COAT);
				m_pZone->broadcastPacket(getX(), getY(), &pkt, this);
			}
			break;
		case Item::ITEM_CLASS_OUSTERS_CHAKRAM:
			{
				m_OustersInfo.setArmType( OUSTERS_ARM_GAUNTLET );
				m_OustersInfo.setArmColor( 377 );
				GCTakeOff pkt;
				pkt.setObjectID(getObjectID());
				pkt.setSlotID((SlotID_t)ADDON_LEFTHAND);
				m_pZone->broadcastPacket(getX(), getY(), &pkt, this);
			}
			break;
		case Item::ITEM_CLASS_OUSTERS_WRISTLET:
			{
				m_OustersInfo.setArmType( OUSTERS_ARM_GAUNTLET );
				m_OustersInfo.setArmColor( 377 );
				GCTakeOff pkt;
				pkt.setObjectID(getObjectID());
				pkt.setSlotID((SlotID_t)ADDON_LEFTHAND);
				m_pZone->broadcastPacket(getX(), getY(), &pkt, this);
			}
			break;
		case Item::ITEM_CLASS_OUSTERS_BOOTS:
			{
				m_OustersInfo.setBootsColor( 377 );
				GCTakeOff pkt;
				pkt.setObjectID(getObjectID());
				pkt.setSlotID((SlotID_t)ADDON_TROUSER);
				m_pZone->broadcastPacket(getX(), getY(), &pkt, this);
			}
			break;
		default:
			break;
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
void Ousters::destroyGears() 
	throw ()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	for (int j = 0; j < OUSTERS_WEAR_MAX; j++) 
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
bool Ousters::isRealWearing(WearPart part) const
	throw()
{
	__BEGIN_TRY

	if (part >= OUSTERS_WEAR_MAX) throw("Ousters::isRealWearing() : invalid wear point!");

	if (m_pWearItem[part] == NULL) return false;

	return isRealWearing(m_pWearItem[part]);

	__END_CATCH
}

//----------------------------------------------------------------------
//----------------------------------------------------------------------
bool Ousters::isRealWearing(Item* pItem) const
	throw()
{
	__BEGIN_TRY

	if (pItem == NULL) return false;

	// �ð���Ѿ������ ��� ���ũ�� ���������ڵ� �� �� �ִ�....... 2003.5.4
	if ( pItem->isTimeLimitItem() )
	{
		return true;
	}

	// ����̾� ������� ��������ڸ� ���ũ/���� �������� �����ȴ�.
	// Ŀ�ø��� ��������ڸ� �� �� �ִ�. by Sequoia 2003. 3. 5.
	if (getZone()->isPremiumZone()
		&& (pItem->isUnique() || pItem->getOptionTypeSize()>1  ) )
			//pItem->getItemClass() == Item::ITEM_CLASS_COUPLE_RING || pItem->getItemClass() == Item::ITEM_CLASS_OUSTERS_COUPLE_RING))
	{
		GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(getPlayer());
		if (!pGamePlayer->isPayPlaying() 
			&& !pGamePlayer->isPremiumPlay())
		{
			return false;
		}
	}

	Item::ItemClass IClass    = pItem->getItemClass();
	ItemInfo*       pItemInfo = g_pItemInfoManager->getItemInfo(IClass, pItem->getItemType());
	Level_t         ReqLevel  = pItemInfo->getReqLevel();
	Attr_t			ReqSTR    = pItemInfo->getReqSTR();
	Attr_t			ReqDEX    = pItemInfo->getReqDEX();
	Attr_t			ReqINT    = pItemInfo->getReqINT();
	Attr_t			ReqSum    = pItemInfo->getReqSum();

	// �������� �ɼ�� ������ �ִٸ�,
	// �ɼ��� ����� ������ �ɷ�ġ ���� �÷��ش�.
	const list<OptionType_t>& optionTypes = pItem->getOptionTypeList();
	list<OptionType_t>::const_iterator itr;

	for (itr=optionTypes.begin(); itr!=optionTypes.end(); itr++)
	{
		OptionInfo* pOptionInfo = g_pOptionInfoManager->getOptionInfo( *itr );
		if (ReqLevel != 0) ReqLevel += pOptionInfo->getReqLevel();
		if (ReqSTR != 0) ReqSTR += (pOptionInfo->getReqSum() * 2);
		if (ReqDEX != 0) ReqDEX += (pOptionInfo->getReqSum() * 2);
		if (ReqINT != 0) ReqINT += (pOptionInfo->getReqSum() * 2);
		if (ReqSum != 0) ReqSum += pOptionInfo->getReqSum();
	}

	ReqLevel = min(ReqLevel, MAX_OUSTERS_LEVEL );
//	ReqSum = min((int)ReqSum, OUSTERS_MAX_SUM);
//	ReqSTR = min((int)ReqSTR, OUSTERS_MAX_ATTR);
//	ReqDEX = min((int)ReqDEX, OUSTERS_MAX_ATTR);
//	ReqINT = min((int)ReqINT, OUSTERS_MAX_ATTR);

	// �ɷ�ġ ����� �ϳ����� �ִٸ�,
	// �� �ɷ�� �����Ű���� �˻��ؾ� �Ѵ�.
	Attr_t CSTR = m_STR[ATTR_CURRENT];
	Attr_t CDEX = m_DEX[ATTR_CURRENT];
	Attr_t CINT = m_INT[ATTR_CURRENT];
	Attr_t CSUM = CSTR + CDEX + CINT;

	if ( CSTR < ReqSTR || CDEX < ReqDEX || CINT < ReqINT || CSUM < ReqSum || m_Level < ReqLevel )
	{
		return false;
	}

	return true;

	__END_CATCH
}

//----------------------------------------------------------------------
//----------------------------------------------------------------------
bool Ousters::isRealWearingEx(WearPart part) const
{
	if (part >= OUSTERS_WEAR_MAX) return false;
	return m_pRealWearingCheck[part];
}

DWORD Ousters::sendRealWearingInfo(void) const
	throw()
{
	__BEGIN_TRY

	DWORD info = 0;
	DWORD flag = 1;

	for (int i=0; i<OUSTERS_WEAR_MAX; i++)
	{
		if (isRealWearing((Ousters::WearPart)i)) info |= flag;
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

PCOustersInfo2* Ousters::getOustersInfo2 ()
	throw ()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	PCOustersInfo2* pInfo = new PCOustersInfo2();

	pInfo->setObjectID(m_ObjectID);
	pInfo->setName(m_Name);
	pInfo->setLevel(m_Level);
	pInfo->setSex(m_Sex);
	pInfo->setHairColor(m_HairColor);

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
	pInfo->setMP(m_MP[ATTR_CURRENT] , m_MP[ATTR_MAX]);
	pInfo->setSilverDamage( m_SilverDamage );

	pInfo->setFame(m_Fame);
	pInfo->setExp(m_GoalExp);
	pInfo->setGold(m_Gold);
	pInfo->setSight(m_Sight);
	pInfo->setBonus(m_Bonus);
	pInfo->setSkillBonus(m_SkillBonus);

	// by sigi. 2002.8.30
	pInfo->setRank(getRank());
	pInfo->setRankExp(getRankGoalExp());

	pInfo->setCompetence(m_CompetenceShape);
	pInfo->setGuildID(m_GuildID);
	pInfo->setGuildName( getGuildName() );
	pInfo->setGuildMemberRank( getGuildMemberRank() );

	return pInfo;

	__END_DEBUG
	__END_CATCH
}


//----------------------------------------------------------------------
// Ousters Outlook Information
//----------------------------------------------------------------------
PCOustersInfo3 Ousters::getOustersInfo3 () const 
	throw ()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	m_OustersInfo.setObjectID(m_ObjectID);
	m_OustersInfo.setX(m_X);
	m_OustersInfo.setY(m_Y);
	m_OustersInfo.setDir(m_Dir);
	m_OustersInfo.setCurrentHP(m_HP[ATTR_CURRENT]);
	m_OustersInfo.setMaxHP(m_HP[ATTR_MAX]);
	m_OustersInfo.setAttackSpeed(m_AttackSpeed[ATTR_CURRENT]);
	m_OustersInfo.setAlignment(m_Alignment);
	m_OustersInfo.setGuildID(m_GuildID);

	// by sigi. 2002.9.10
	m_OustersInfo.setRank(getRank());

    m_OustersInfo.setHairColor(m_HairColor);

	return m_OustersInfo;

	__END_DEBUG
	__END_CATCH
}

//----------------------------------------------------------------------
//
// get Extra Info
//
//----------------------------------------------------------------------
ExtraInfo* Ousters::getExtraInfo() const
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	BYTE ItemCount = 0;

	ExtraInfo* pExtraInfo = new ExtraInfo();

	Item* pItem = m_pExtraInventorySlot->getItem();

	if (pItem != NULL) {
	
	//	Item::ItemClass IClass = pItem->getItemClass();

		ExtraSlotInfo* pExtraSlotInfo = new ExtraSlotInfo();
		pItem->makePCItemInfo( *pExtraSlotInfo );

/*		pExtraSlotInfo->setObjectID(pItem->getObjectID());
		pExtraSlotInfo->setItemClass(pItem->getItemClass());
		pExtraSlotInfo->setItemType(pItem->getItemType());
		pExtraSlotInfo->setOptionType(pItem->getOptionTypeList());
		pExtraSlotInfo->setDurability(pItem->getDurability());
		pExtraSlotInfo->setSilver(pItem->getSilver());
		pExtraSlotInfo->setSilver(pItem->getEnchantLevel());
		pExtraSlotInfo->setItemNum(pItem->getNum());

		// �Ͻ��������� Sub �������� �߰� ����� �ʿ��ϴ�.
		if (IClass == Item::ITEM_CLASS_OUSTERS_ARMSBAND) 
		{
			OustersArmsband* pOustersArmsband = dynamic_cast<OustersArmsband*>(pItem);
			Inventory* pOustersArmsbandInventory = ((OustersArmsband*)pItem)->getInventory();
			BYTE SubItemCount = 0;

			// ������ ���ڸ�ŭ �������� ����� �о� ���δ�.
			for (int i = 0; i < pOustersArmsband->getPocketCount(); i++) 
			{
				Item* pOustersArmsbandItem = pOustersArmsbandInventory->getItem(i, 0);

				if (pOustersArmsbandItem != NULL) 
				{
					SubItemInfo* pSubItemInfo = new SubItemInfo();
					pSubItemInfo->setObjectID(pOustersArmsbandItem->getObjectID());
					pSubItemInfo->setItemClass(pOustersArmsbandItem->getItemClass());
					pSubItemInfo->setItemType(pOustersArmsbandItem->getItemType());
					pSubItemInfo->setItemNum(pOustersArmsbandItem->getNum());
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
GearInfo* Ousters::getGearInfo() const
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	int ItemCount = 0;

	GearInfo* pGearInfo = new GearInfo();

	for (int i = 0; i < OUSTERS_WEAR_MAX; i++) 
	{
		Item* pItem = m_pWearItem[i];

		if (pItem != NULL) 
		{
			//Item::ItemClass IClass = pItem->getItemClass();

			GearSlotInfo* pGearSlotInfo = new GearSlotInfo();
			pItem->makePCItemInfo( *pGearSlotInfo );
			pGearSlotInfo->setSlotID(i);
/*
			pGearSlotInfo->setObjectID(pItem->getObjectID());
			pGearSlotInfo->setItemClass(pItem->getItemClass());
			pGearSlotInfo->setItemType(pItem->getItemType());
			pGearSlotInfo->setOptionType(pItem->getOptionTypeList());
			pGearSlotInfo->setDurability(pItem->getDurability());
			pGearSlotInfo->setSilver(pItem->getSilver());
			pGearSlotInfo->setEnchantLevel(pItem->getEnchantLevel());

			// �Ͻ��������� Sub �������� �߰� ����� �ʿ��ϴ�.
			if (pItem->getItemClass() == Item::ITEM_CLASS_OUSTERS_ARMSBAND)
			{
				// ������ ������ �޾ƿ´�.
				ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo(pItem->getItemClass(), pItem->getItemType());

				// ������ ���ڸ� �޾ƿ´�.
				BYTE PocketNum = ((OustersArmsbandInfo*)pItemInfo)->getPocketCount();

				// ��Ʈ�� �κ��丮�� �޾ƿ´�.
				Inventory* pOustersArmsbandInventory = ((OustersArmsband*)pItem)->getInventory();

				BYTE SubItemCount = 0;

				// ������ ���ڸ�ŭ �������� ����� �о� ���δ�.
				for (int i = 0; i < PocketNum ; i++)
				{
					Item* pOustersArmsbandItem = pOustersArmsbandInventory->getItem(i, 0);
					if (pOustersArmsbandItem != NULL)
					{
						SubItemInfo* pSubItemInfo = new SubItemInfo();
						pSubItemInfo->setObjectID(pOustersArmsbandItem->getObjectID());
						pSubItemInfo->setItemClass(pOustersArmsbandItem->getItemClass());
						pSubItemInfo->setItemType(pOustersArmsbandItem->getItemType());
						pSubItemInfo->setItemNum(pOustersArmsbandItem->getNum());
						pSubItemInfo->setSlotID(i);

						pGearSlotInfo->addListElement(pSubItemInfo);

						SubItemCount++;
					}
				}
				pGearSlotInfo->setListNum(SubItemCount);
			}

			pGearSlotInfo->setSlotID(i);
	
			// ���� ���� Main Color ����� �׳� 0 ��� ���� �صд�.
			pGearSlotInfo->setMainColor(0);*/
		
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
InventoryInfo* Ousters::getInventoryInfo() const
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
				//Item::ItemClass IClass = pItem->getItemClass();
				list<Item*>::iterator itr = find(ItemList.begin() , ItemList.end() , pItem);

				if (itr == ItemList.end()) 
				{
					ItemList.push_back(pItem);

					// InventorySlotInfo�� ����
					InventorySlotInfo* pInventorySlotInfo = new InventorySlotInfo();
					pItem->makePCItemInfo( *pInventorySlotInfo );
					pInventorySlotInfo->setInvenX(i);
					pInventorySlotInfo->setInvenY(j);
/*
					pInventorySlotInfo->setObjectID(pItem->getObjectID());
					pInventorySlotInfo->setItemClass(pItem->getItemClass());
					pInventorySlotInfo->setItemType(pItem->getItemType());
					pInventorySlotInfo->setOptionType(pItem->getOptionTypeList());
					pInventorySlotInfo->setSilver(pItem->getSilver());
					pInventorySlotInfo->setDurability(pItem->getDurability());
					pInventorySlotInfo->setEnchantLevel(pItem->getEnchantLevel());
					pInventorySlotInfo->setInvenX(i);
					pInventorySlotInfo->setInvenY(j);
					pInventorySlotInfo->setItemNum(pItem->getNum());

					// �Ͻ��������� Sub �������� �߰� ����� �ʿ��ϴ�.
					if (IClass == Item::ITEM_CLASS_OUSTERS_ARMSBAND) 
					{
						OustersArmsband* pOustersArmsband = dynamic_cast<OustersArmsband*>(pItem);
						Inventory* pOustersArmsbandInventory = ((OustersArmsband*)pItem)->getInventory();

						BYTE SubItemCount = 0;

						// ������ ���ڸ�ŭ �������� ����� �о� ���δ�.
						for (int i = 0; i < pOustersArmsband->getPocketCount() ; i++) 
						{
							Item* pOustersArmsbandItem = pOustersArmsbandInventory->getItem(i, 0);
							if (pOustersArmsbandItem != NULL) 
							{
								SubItemInfo* pSubItemInfo = new SubItemInfo();
								pSubItemInfo->setObjectID(pOustersArmsbandItem->getObjectID());
								pSubItemInfo->setItemClass(pOustersArmsbandItem->getItemClass());
								pSubItemInfo->setItemType(pOustersArmsbandItem->getItemType());
								pSubItemInfo->setItemNum(pOustersArmsbandItem->getNum());
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
void Ousters::sendOustersSkillInfo()
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	OustersSkillInfo* pOustersSkillInfo = new OustersSkillInfo();

	BYTE SkillCount = 0;

	// ���� �ð�, ��� ĳ���� Ÿ��� �����ϱ� ���
	Timeval currentTime;
	getCurrentTime( currentTime );

	map<SkillType_t, OustersSkillSlot*>::const_iterator itr = m_SkillSlot.begin();
	for (; itr != m_SkillSlot.end(); itr++)
	{
		OustersSkillSlot* pOustersSkillSlot = itr->second;
		Assert(pOustersSkillSlot != NULL);

		// AttackMelee ���� �⺻ ���� ���� ����� �������� �ʾƾ� �Ѵ�.
		if (pOustersSkillSlot->getSkillType() >= SKILL_DOUBLE_IMPACT)
		{
			SubOustersSkillInfo* pSubOustersSkillInfo = new SubOustersSkillInfo();
			pSubOustersSkillInfo->setSkillType(pOustersSkillSlot->getSkillType());
			pSubOustersSkillInfo->setExpLevel(pOustersSkillSlot->getExpLevel());
			pSubOustersSkillInfo->setSkillTurn(pOustersSkillSlot->getInterval());
			pSubOustersSkillInfo->setCastingTime(pOustersSkillSlot->getRemainTurn( currentTime ) );

			pOustersSkillInfo->addListElement(pSubOustersSkillInfo);

			SkillCount++;
		}
	}

	GCSkillInfo gcSkillInfo;
	gcSkillInfo.setPCType(PC_OUSTERS);
	SkillType_t LearnSkillType = g_pSkillInfoManager->getSkillTypeByLevel(SKILL_DOMAIN_OUSTERS , m_Level);

	// ���� �������� ���� �� �ִ� ������ �ִ��� ����.
	if (LearnSkillType != 0) 
	{
		// ���� �� �ִ� ������ �ְ� ������ ��� ���¶��� �������� �˷��ش�.
		if (hasSkill(LearnSkillType) == NULL) 
		{
			pOustersSkillInfo->setLearnNewSkill(true);
		}
	}

	pOustersSkillInfo->setListNum(SkillCount);

	gcSkillInfo.addListElement(pOustersSkillInfo);

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
void Ousters::setGold(Gold_t gold)
	throw()
{
	__BEGIN_TRY

    // MAX_MONEY �� �Ѿ�� �� ���´�
	// 2003.1.8  by bezz.
	m_Gold = min( (Gold_t)MAX_MONEY, gold );

	__END_CATCH
}

void Ousters::setGoldEx(Gold_t gold)
	throw()
{
	__BEGIN_TRY

	setGold(gold);

	// by sigi. 2002.5.15
	char pField[80];
	sprintf(pField, "Gold=%ld", m_Gold);
	tinysave(pField);

	__END_CATCH
}

void Ousters::increaseGoldEx(Gold_t gold)
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
		pStmt->executeQuery("UPDATE Ousters SET Gold=Gold+%u WHERE NAME='%s'", gold, m_Name.c_str());
		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)


	__END_DEBUG
	__END_CATCH
}

void Ousters::decreaseGoldEx(Gold_t gold)
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
		pStmt->executeQuery("UPDATE Ousters SET Gold=Gold-%u WHERE NAME='%s'", gold, m_Name.c_str());
		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

	__END_DEBUG
	__END_CATCH
}

void Ousters::saveSilverDamage(Silver_t damage)
	    throw()
{
	__BEGIN_TRY

	setSilverDamage(damage);

	// by sigi. 2002.5.15
	char pField[80];
	sprintf(pField, "SilverDamage=%d", m_SilverDamage);
	tinysave(pField);

	__END_CATCH
}

bool Ousters::checkGoldIntegrity()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	bool ret = false;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pResult = pStmt->executeQuery("SELECT Gold FROM Ousters WHERE NAME='%s'", m_Name.c_str());

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

bool Ousters::checkStashGoldIntegrity()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	bool ret = false;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pResult = pStmt->executeQuery("SELECT StashGold FROM Ousters WHERE NAME='%s'", m_Name.c_str());

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


//////////////////////////////////////////////////////////////////////////////
// ��� ������ hearbeat
//////////////////////////////////////////////////////////////////////////////
void Ousters::heartbeat(const Timeval& currentTime)
    throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	PlayerCreature::heartbeat( currentTime );

	OustersSkillSlot* pDriftingSoul = hasSkill(SKILL_DRIFTING_SOUL);

	if ( pDriftingSoul != NULL && m_MPRegenTime < currentTime )
	{
		SkillLevel_t level = pDriftingSoul->getExpLevel();
		int bonus = 0;

		if ( level <= 15 ) bonus +=1;
		else if ( level <= 25 ) bonus += 2;
		else if ( level <= 29 ) bonus += 3;
		else if ( level <= 30 ) bonus += 4;

		MP_t oldMP = getMP();
		MP_t newMP = min( (int)getMP(ATTR_MAX), oldMP + bonus );

		if ( oldMP != newMP )
		{
			setMP(newMP);

			GCModifyInformation gcMI;
			gcMI.addShortData(MODIFY_CURRENT_MP, newMP);
			m_pPlayer->sendPacket(&gcMI);
		}

		// 1�� ����� ��Ʈ��Ʈ ��Ų��. 
		m_MPRegenTime.tv_sec = currentTime.tv_sec + 2;
		m_MPRegenTime.tv_usec = currentTime.tv_usec;
	}

	__END_DEBUG
	__END_CATCH
}

void Ousters::getOustersRecord(OUSTERS_RECORD& record) const
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

	record.pMP[0]      = m_MP[0];
	record.pMP[1]      = m_MP[1];

	record.pDamage[0]  = m_Damage[0];
	record.pDamage[1]  = m_Damage[1];

	record.Rank     = getRank();

	record.Defense     = m_Defense[0];
	record.ToHit       = m_ToHit[0];
	record.Protection  = m_Protection[0];
	record.AttackSpeed = m_AttackSpeed[0];

	__END_CATCH
}

void Ousters::setResurrectZoneIDEx(ZoneID_t id)
	throw()
{
	__BEGIN_TRY

	setResurrectZoneID(id);

	// by sigi. 2002.5.15
	char pField[80];
	sprintf(pField, "ResurrectZone=%d", id);
	tinysave(pField);


	__END_CATCH
}

void Ousters::saveAlignment(Alignment_t alignment)
	    throw()
{
	__BEGIN_TRY

	setAlignment(alignment);

	// by sigi. 2002.5.15
	char pField[80];
	sprintf(pField, "Alignment=%d", alignment);
	tinysave(pField);

	__END_CATCH
}


//----------------------------------------------------------------------
// get debug string
//----------------------------------------------------------------------
string Ousters::toString () const
	throw ()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "Ousters("
		//<< "ObjectID:"   << (int)getObjectID()
		<< ",Name:"      << m_Name
		<< ",HairColor:" << (int)m_HairColor
		<< ",STR:"       << (int)m_STR[ATTR_CURRENT] << "/" << (int)m_STR[ATTR_MAX]
		<< ",DEX:"       << (int)m_DEX[ATTR_CURRENT] << "/" << (int)m_DEX[ATTR_MAX]
		<< ",INT:"       << (int)m_INT[ATTR_CURRENT] << "/" << (int)m_INT[ATTR_MAX]
		<< ",HP:"        << (int)m_HP[ATTR_CURRENT] << "/" << (int)m_HP[ATTR_MAX]
		<< ",MP:"        << (int)m_MP[ATTR_CURRENT] << "/" << (int)m_MP[ATTR_MAX]
		<< ",Fame:"      << (int)m_Fame
//		<< ",Exp:"       << (int)m_Exp
//		<< ",ExpOffset:" << (int)m_ExpOffset
		<< ",Rank:"       << (int)getRank()
		<< ",RankGoalExp:" << (int)getRankGoalExp()
		<< ",Level:"     << (int)m_Level
		<< ",Bonus:"     << (int)m_Bonus
		<< ",Gold:"      << (int)m_Gold
		<< ",ZoneID:"    << (int)getZoneID()
		<< ",XCoord:"    << (int)m_X
		<< ",YCoord:"    << (int)m_Y
		<< ",Sight:"     << (int)m_Sight
		<< ")";

	return msg.toString();

	__END_CATCH
}

void Ousters::saveSkills(void) const 
	throw (Error)
{
	__BEGIN_TRY

	map<SkillType_t, OustersSkillSlot*>::const_iterator itr = m_SkillSlot.begin();
	for (; itr != m_SkillSlot.end(); itr++)
	{
		OustersSkillSlot* pOustersSkillSlot = itr->second;
		Assert(pOustersSkillSlot != NULL);

		// �⺻ ���� ��ų�� �ƴ϶���...
		if (pOustersSkillSlot->getSkillType() >= SKILL_DOUBLE_IMPACT)
		{
			pOustersSkillSlot->save(m_Name);
		}
	}

	__END_CATCH
}

Sight_t Ousters::getEffectedSight() throw()
{
	__BEGIN_TRY

	Sight_t sight = Creature::getEffectedSight();

	if ( sight == DEFAULT_SIGHT )
	{
//		if ( isFlag( Effect::EFFECT_CLASS_BLOOD_DRAIN ) )
//		{
//			sight = (Sight_t) 3;
//		}
	}

	return sight;

	__END_CATCH
}

IP_t Ousters::getIP(void) const
{
	Assert(m_pPlayer != NULL);
	Socket* pSocket = m_pPlayer->getSocket();
	Assert(pSocket != NULL);
	return pSocket->getHostIP();
}

void Ousters::saveGears(void) const
    throw (Error)
{
	__BEGIN_TRY

	// �����ϰ� �ִ� �����۵�� �����Ѵ�.
	char pField[80];

	for (int i=0; i < Ousters::OUSTERS_WEAR_MAX; i++)
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


void Ousters::saveExps(void) const
    throw (Error)
{
	__BEGIN_TRY

	// ��ų �ڵ鷯���� ���� ���ڸ� ���̱� ��ؼ� 10��� ������ �κе��,
	// ���� �ٿ��� ���� �ʰ�, �������� �α׾ƿ��ϴ� ���쿡 
	// ���̺긦 ��������� ������ ����� 10 ���� �ö��� �κ�� ���ư� �������� �ȴ�.
	// �׷��Ƿ� ���⼭ ���̺긦 �� �ش�. 
	Statement* pStmt = NULL;

/*	char silverDam[40];
	if (m_SilverDamage != 0)
	{
		sprintf(silverDam, ",SilverDamage = %d", m_SilverDamage);
	}
	else silverDam[0]='\0'; */

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery( "UPDATE Ousters SET Alignment=%d, Fame=%d, GoalExp=%lu, SilverDamage = %d, Rank=%d, RankGoalExp=%lu WHERE Name='%s'",
							m_Alignment, m_Fame, m_GoalExp, m_SilverDamage, getRank(), getRankGoalExp(), m_Name.c_str());

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
void Ousters::getShapeInfo (DWORD& flag, Color_t colors[PCOustersInfo::OUSTERS_COLOR_MAX]) const
//	throw ()
{
	__BEGIN_DEBUG

	Item* 						pItem;
	//OptionInfo* 				pOptionInfo;
	int							oustersBit;
	int							oustersColor;
	WearPart					Part;

	// �ʱ�ȭ
	flag = 0;

	//-----------------------------------------------------------------
	// ����
	//-----------------------------------------------------------------
	Part = WEAR_COAT;
	pItem = m_pWearItem[Part];
	oustersBit = 0;
	oustersColor = 0;

	if (pItem!=NULL && m_pRealWearingCheck[Part])
	{
		ItemType_t IType = pItem->getItemType();

		colors[oustersColor] = getItemShapeColor( pItem );

		// itemType� �־��ش�.
		flag = IType;
	} 
	else 
	{
		colors[oustersColor] = 377;
		flag = (m_Sex? 0 : 1);
	}

	__END_DEBUG
}


//----------------------------------------------------------------------
// save InitialRank
//----------------------------------------------------------------------
// Rank, RankExp, RankGoalExp�� �ʱⰪ� �����Ѵ�.
//----------------------------------------------------------------------
void Ousters::saveInitialRank(void)
	throw()
{
	OUSTERS_RECORD prev;
	getOustersRecord(prev);

	int curRank = max(1, (m_Level+3) / 4);
	m_pRank->SET_LEVEL(curRank);

/*	RankExp_t accumExp = 0;

	if (curRank!=1)
	{
		RankEXPInfo* pBeforeExpInfo = g_pRankEXPInfoManager[RANK_TYPE_OUSTERS]->getRankEXPInfo(curRank-1);
		accumExp = pBeforeExpInfo->getAccumExp();
	}
	
	RankEXPInfo* pNextExpInfo = g_pRankEXPInfoManager[RANK_TYPE_OUSTERS]->getRankEXPInfo(curRank);
	Exp_t NextGoalExp = pNextExpInfo->getGoalExp();

	setRankGoalExp(NextGoalExp);
*/
	char pField[80];
	sprintf(pField, "Rank=%d, RankExp=%lu, RankGoalExp=%lu",
					getRank(), getRankExp(), getRankGoalExp());
	tinysave(pField);
	setRankExpSaveCount(0);
}

bool
Ousters::addShape(Item::ItemClass IClass, ItemType_t IType, Color_t color)
{
	bool bisChange = false;

	switch (IClass)
	{
		/*case Item::ITEM_CLASS_OUSTERS_COAT:
		{
			bisChange = true;

			m_OustersInfo.setCoatColor( color );
			m_OustersInfo.setCoatType( IType );
		}
		break;
*/
		default:
			break;
	}

	return bisChange;
}


bool
Ousters::removeShape(Item::ItemClass IClass, bool bSendPacket)
{
    bool bisChange = false;

	switch (IClass)
	{
		/*case Item::ITEM_CLASS_OUSTERS_COAT :
		{
			m_OustersInfo.setCoatColor(377);
			m_OustersInfo.setCoatType( 0 );

			if (bSendPacket)	// by sigi. 2002.11.6
			{
				GCTakeOff pkt;
				pkt.setObjectID(getObjectID());
				pkt.setSlotID((SlotID_t)ADDON_COAT);
				m_pZone->broadcastPacket(getX(), getY(), &pkt, this);
			}
		}
		break;
*/
		default :
			return false;
	}

	return bisChange;
}

Color_t 
Ousters::getItemShapeColor(Item* pItem, OptionInfo* pOptionInfo) const
{
	Color_t color;

	if (pItem->isTimeLimitItem())
	{
		color = QUEST_COLOR;
	}
	else if (pItem->isUnique())
	{
		// ���ũ�� Ư��� ������ ��ü�ؼ� ó���Ѵ�.
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

bool Ousters::canPlayFree()
	throw(Error)
{
	__BEGIN_TRY

	return m_Level <= g_pVariableManager->getVariable(FREE_PLAY_OUSTERS_LEVEL);

	__END_CATCH
}

bool Ousters::satisfySkillRequire( SkillInfo* pSkillInfo )
{
	if ( isFlag(Effect::EFFECT_CLASS_SUMMON_SYLPH) )
		return false;
	if ( pSkillInfo->getRequireFire() > m_ElementalFire )
		return false;
	if ( pSkillInfo->getRequireWater() > m_ElementalWater )
		return false;
	if ( pSkillInfo->getRequireEarth() > m_ElementalEarth )
		return false;
	if ( pSkillInfo->getRequireWind() > m_ElementalWind )
		return false;
	if ( pSkillInfo->getRequireSum() > getElementalSum() )
		return false;

	if ( pSkillInfo->getRequireWristletElemental() != ELEMENTAL_ANY )
	{
		if ( !isRealWearing(WEAR_LEFTHAND)
				|| m_pWearItem[WEAR_LEFTHAND]->getItemClass() != Item::ITEM_CLASS_OUSTERS_WRISTLET )
			return false;

		OustersWristlet* pWristlet = dynamic_cast<OustersWristlet*>(m_pWearItem[WEAR_LEFTHAND]);
		Assert( pWristlet != NULL );

		if ( pSkillInfo->getRequireWristletElemental() != pWristlet->getElementalType() )
			return false;
	}

	if ( pSkillInfo->getRequireStone1Elemental() != ELEMENTAL_ANY )
	{
		if ( !isRealWearing(WEAR_STONE1)
				|| m_pWearItem[WEAR_STONE1]->getItemClass() != Item::ITEM_CLASS_OUSTERS_STONE )
			return false;

		OustersStone* pStone = dynamic_cast<OustersStone*>(m_pWearItem[WEAR_STONE1]);
		Assert( pStone != NULL );

		if ( pSkillInfo->getRequireStone1Elemental() != pStone->getElementalType() )
			return false;
	}

	if ( pSkillInfo->getRequireStone2Elemental() != ELEMENTAL_ANY )
	{
		if ( !isRealWearing(WEAR_STONE2)
				|| m_pWearItem[WEAR_STONE2]->getItemClass() != Item::ITEM_CLASS_OUSTERS_STONE )
			return false;

		OustersStone* pStone = dynamic_cast<OustersStone*>(m_pWearItem[WEAR_STONE2]);
		Assert( pStone != NULL );

		if ( pSkillInfo->getRequireStone2Elemental() != pStone->getElementalType() )
			return false;
	}

	if ( pSkillInfo->getRequireStone3Elemental() != ELEMENTAL_ANY )
	{
		if ( !isRealWearing(WEAR_STONE3)
				|| m_pWearItem[WEAR_STONE3]->getItemClass() != Item::ITEM_CLASS_OUSTERS_STONE )
			return false;

		OustersStone* pStone = dynamic_cast<OustersStone*>(m_pWearItem[WEAR_STONE3]);
		Assert( pStone != NULL );

		if ( pSkillInfo->getRequireStone3Elemental() != pStone->getElementalType() )
			return false;
	}

	if ( pSkillInfo->getRequireStone4Elemental() != ELEMENTAL_ANY )
	{
		if ( !isRealWearing(WEAR_STONE4)
				|| m_pWearItem[WEAR_STONE4]->getItemClass() != Item::ITEM_CLASS_OUSTERS_STONE )
			return false;

		OustersStone* pStone = dynamic_cast<OustersStone*>(m_pWearItem[WEAR_STONE4]);
		Assert( pStone != NULL );

		if ( pSkillInfo->getRequireStone4Elemental() != pStone->getElementalType() )
			return false;
	}

	return true;
}

bool Ousters::isPayPlayAvaiable() 
	throw(Error)
{
	__BEGIN_TRY

	if (m_pPlayer==NULL)
		return false;

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(m_pPlayer);

#ifdef __CONNECT_BILLING_SYSTEM__
	if (pGamePlayer->isPayPlaying())
	{
		// ���� ���� �����. ����
		if (pGamePlayer->getPayType()==PAY_TYPE_FREE)
			return true;

		// ��ѵ� �������� play����
		if (m_Level <= g_pVariableManager->getVariable(FREE_PLAY_OUSTERS_LEVEL))
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
		if (m_Level <= g_pVariableManager->getVariable(FREE_PLAY_OUSTERS_LEVEL))
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

void Ousters::initPetQuestTarget()
{
	int minClass = 1, maxClass = 1;

	if ( getLevel() <= 50 )
	{
		minClass = 6; maxClass = 7;
	}
	else if ( getLevel() <= 60 )
	{
		minClass = 7; maxClass = 8;
	}
	else if ( getLevel() <= 70 )
	{
		minClass = maxClass = 9;
	}
	else if ( getLevel() <= 80 )
	{
		minClass = 9; maxClass = 10;
	}
	else if ( getLevel() <= 90 )
	{
		minClass = maxClass = 10;
	}
	else if ( getLevel() <= 110 )
	{
		minClass = 10; maxClass = 11;
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
