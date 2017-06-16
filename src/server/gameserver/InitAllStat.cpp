//////////////////////////////////////////////////////////////////////////////
// Filename    : InitAllStat.cpp
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "Monster.h"
#include "GamePlayer.h"
#include "Zone.h"
#include "AbilityBalance.h"
#include "Effect.h"
#include "OptionInfo.h"
#include "ItemUtil.h"
#include "ItemInfo.h"
#include "ItemInfoManager.h"
#include "Player.h"
#include "SkillInfo.h"
#include "CombatInfoManager.h"
#include "VariableManager.h"
#include "RankBonus.h"
#include "HolyLandRaceBonus.h"
#include "BloodBibleBonus.h"
#include "BloodBibleBonusManager.h"
#include "WarSystem.h"
#include "CastleInfoManager.h"
#include "DefaultOptionSetInfo.h"
#include "LevelWarZoneInfoManager.h"
#include "SweeperBonus.h"
#include "SweeperBonusManager.h"

#include "PetInfo.h"

#include "item/OustersWristlet.h"
#include "item/OustersStone.h"

#include "skill/CastleSkillSlot.h"
#include "skill/VampireCastleSkillSlot.h"
#include "skill/EffectBless.h"
#include "skill/EffectDancingSword.h"
#include "skill/EffectGhostBlade.h"
#include "skill/EffectChargingPower.h"
#include "skill/EffectPotentialExplosion.h"
#include "skill/EffectParalyze.h"
#include "skill/EffectDoom.h"
#include "skill/EffectSeduction.h"
#include "skill/EffectProtectionFromPoison.h"
#include "skill/EffectProtectionFromCurse.h"
#include "skill/EffectProtectionFromAcid.h"
#include "skill/EffectProtectionFromBlood.h"
#include "skill/EffectTransformToWolf.h"
#include "skill/EffectTransformToBat.h"
#include "skill/EffectMindControl.h"
#include "skill/EffectExpansion.h"
#include "skill/EffectBerserker.h"
#include "skill/EffectStriking.h"
#include "skill/EffectExtreme.h"
#include "skill/EffectDeath.h"
#include "skill/EffectMephisto.h"
#include "skill/EffectObservingEye.h"
#include "skill/EffectSummonCasket.h"
#include "skill/EffectConcealment.h"
#include "skill/EffectEvade.h"
#include "skill/EffectCrossGuard.h"
#include "skill/EffectBlunting.h"
#include "skill/EffectHandsOfFire.h"
#include "skill/EffectRingOfFlare.h"
#include "skill/EffectWaterBarrier.h"
#include "skill/EffectGnomesWhisper.h"
#include "skill/EffectRediance.h"
#include "skill/EffectHolyArmor.h"
#include "skill/EffectTransformToWerwolf.h"
#include "skill/EffectReactiveArmor.h"
#include "skill/EffectGroundBless.h"
#include "skill/EffectSharpChakram.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCRemoveEffect.h"
#include "Gpackets/GCChangeShape.h"

//////////////////////////////////////////////////////////////////////////////
//
// �����̾�
//
//////////////////////////////////////////////////////////////////////////////

void Slayer::initCastleSkill() throw()
{
	__BEGIN_TRY

	removeAllCastleSkill();

	if ( !getZone()->isHolyLand() ) return;

	list<CastleInfo*> pCastleInfoList = g_pCastleInfoManager->getGuildCastleInfos( getGuildID() );
	if ( pCastleInfoList.empty() ) return;

	list<CastleInfo*>::iterator itr = pCastleInfoList.begin();

	for ( ; itr != pCastleInfoList.end() ; itr++ )
	{
		SkillType_t CastleSkillType = g_pCastleInfoManager->getCastleSkillType( (*itr)->getZoneID(), getGuildID() );
		if ( CastleSkillType == SKILL_MAX ) 
			continue;

		SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo(CastleSkillType);
		Assert( pSkillInfo != NULL );

		Turn_t Delay = pSkillInfo->getMaxDelay();

		CastleSkillSlot* pCastleSkillSlot = new CastleSkillSlot();

		pCastleSkillSlot->setName( m_Name );
		pCastleSkillSlot->setSkillType( CastleSkillType );
		pCastleSkillSlot->setInterval(Delay);
		pCastleSkillSlot->setExpLevel(0);
		pCastleSkillSlot->setExp(1);
		pCastleSkillSlot->setRunTime();

		addSkill( pCastleSkillSlot );
	}

	__END_CATCH
}

void Slayer::initAllStat(int numPartyMember) throw()
{
	__BEGIN_TRY

	BASIC_ATTR attr;
	Creature::CreatureClass CClass = getCreatureClass();

	m_Resist[MAGIC_DOMAIN_NO_DOMAIN] = 0;
	m_Resist[MAGIC_DOMAIN_POISON]    = 0;
	m_Resist[MAGIC_DOMAIN_ACID]      = 0;
	m_Resist[MAGIC_DOMAIN_CURSE]     = 0;
	m_Resist[MAGIC_DOMAIN_BLOOD]     = 0;

	// BloodBible ���� ���ʽ� ��ġ�� �ʱ�ȭ
	m_ConsumeMPRatio	= 0;
	m_GamblePriceRatio	= 0;
	m_PotionPriceRatio	= 0;
	m_MagicBonusDamage	= 0;
	m_PhysicBonusDamage	= 0;

	//////////////////////////////////////////////////////////////////////////////
	// ��� ���� �⺻ �ɷ�ġ�� �ʱ�ȭ��Ű��, 
	// �⺻ �ɷ�ġ�� ����� �ִ� ����Ʈ�� �˻��Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	m_STR[ATTR_CURRENT] = m_STR[ATTR_MAX] = m_STR[ATTR_BASIC] = m_pAttrs[ATTR_KIND_STR]->getLevel();
	m_DEX[ATTR_CURRENT] = m_DEX[ATTR_MAX] = m_DEX[ATTR_BASIC] = m_pAttrs[ATTR_KIND_DEX]->getLevel();
	m_INT[ATTR_CURRENT] = m_INT[ATTR_MAX] = m_INT[ATTR_BASIC] = m_pAttrs[ATTR_KIND_INT]->getLevel();

	if (isFlag(Effect::EFFECT_CLASS_BLESS))
	{
		EffectBless* pBless = dynamic_cast<EffectBless*>(findEffect(Effect::EFFECT_CLASS_BLESS));
		if (pBless != NULL)
		{
			// STR, DEX�� �ø���.
//			m_STR[ATTR_CURRENT] += pBless->getSTRBonus();
//			m_DEX[ATTR_CURRENT] += pBless->getDEXBonus();
			m_STR[ATTR_CURRENT] += getPercentValue( m_STR[ATTR_CURRENT], pBless->getSTRBonus() );
			m_DEX[ATTR_CURRENT] += getPercentValue( m_DEX[ATTR_CURRENT], pBless->getDEXBonus() );
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_POTENTIAL_EXPLOSION))
	{
		EffectPotentialExplosion* pPotentialExplosion = dynamic_cast<EffectPotentialExplosion*>(findEffect(Effect::EFFECT_CLASS_POTENTIAL_EXPLOSION));
		if (pPotentialExplosion!= NULL)
		{
			// STR, DEX�� �ø���.
			m_STR[ATTR_CURRENT] += pPotentialExplosion->getDiffSTR();
			m_DEX[ATTR_CURRENT] += pPotentialExplosion->getDiffDEX();
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_REDIANCE))
	{
		EffectRediance* pRediance = dynamic_cast<EffectRediance*>(findEffect(Effect::EFFECT_CLASS_REDIANCE));
		if (pRediance!= NULL)
		{
			Item* pWeapon = m_pWearItem[Slayer::WEAR_RIGHTHAND];
			if ( pWeapon == NULL || pWeapon->getItemClass() != Item::ITEM_CLASS_SWORD || !isRealWearing( WEAR_RIGHTHAND ) )
			{
				pRediance->setDeadline(0);
			}
			else
			{
				m_DEX[ATTR_CURRENT] += pRediance->getDexBonus();
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// �ɷ�ġ ����� ��� �Ķ����͵�� �ʱ�ȭ�Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	attr.nSTR    = m_STR[ATTR_CURRENT];
	attr.nDEX    = m_DEX[ATTR_CURRENT];
	attr.nINT    = m_INT[ATTR_CURRENT];
	attr.pWeapon = m_pWearItem[WEAR_RIGHTHAND];

	m_HPStealAmount = 0;
	m_MPStealAmount = 0;
	m_HPStealRatio  = 0;
	m_MPStealRatio  = 0;
	m_HPRegen       = 0;
	m_MPRegen       = 0;
	m_Luck			= 0;

	for (int i=0; i<SKILL_DOMAIN_MAX; i++)
		attr.pDomainLevel[i] = m_SkillDomainLevels[i];

	//////////////////////////////////////////////////////////////////////////////
	// �ΰ����� �ɷ�ġ��� �����Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	m_HP[ATTR_MAX]                = computeHP(CClass, &attr);
	m_HP[ATTR_BASIC]              = 0;
	m_MP[ATTR_MAX]                = computeMP(CClass, &attr);
	m_MP[ATTR_BASIC]              = 0;
	m_ToHit[ATTR_CURRENT]         = computeToHit(CClass, &attr);
	m_ToHit[ATTR_MAX]             = 0;
	m_Defense[ATTR_CURRENT]       = computeDefense(CClass, &attr);
	m_Defense[ATTR_MAX]           = 0;
	m_Protection[ATTR_CURRENT]    = computeProtection(CClass, &attr);
	m_Protection[ATTR_MAX]        = 0;
	m_Damage[ATTR_CURRENT]        = computeMinDamage(CClass, &attr);
	m_Damage[ATTR_MAX]            = computeMaxDamage(CClass, &attr);
	m_Damage[ATTR_BASIC]          = 0;
	m_AttackSpeed[ATTR_CURRENT]   = computeAttackSpeed(CClass, &attr);
	m_AttackSpeed[ATTR_MAX]       = 0;
	m_CriticalRatio[ATTR_CURRENT] = computeCriticalRatio(CClass, &attr);
	m_CriticalRatio[ATTR_MAX]     = 0;

	//////////////////////////////////////////////////////////////////////////////
	// �ɷ�ġ�� ���� Damage �� ������ �д�. BERSER ������ ���ʽ� ����� ��ؼ�.
	//////////////////////////////////////////////////////////////////////////////
	Damage_t AttrMinDamage = m_Damage[ATTR_CURRENT];
	Damage_t AttrMaxDamage = m_Damage[ATTR_MAX];

	int DefBonus = 0;
	int ProBonus = 0;

	if ( isFlag( Effect::EFFECT_CLASS_CONCEALMENT ) )
	{
		EffectConcealment* pEffect = dynamic_cast<EffectConcealment*>( findEffect(Effect::EFFECT_CLASS_CONCEALMENT) );
		if ( pEffect != NULL )
		{
			if ( attr.pWeapon == NULL || !isArmsWeapon( attr.pWeapon ) )
			{
				pEffect->setDeadline(0);
			}
			else if ( isRealWearing( WEAR_RIGHTHAND ) )
			{
				DefBonus = (int)( (getDEX()/20) * ( 1.0f + ((float)pEffect->getLevel()/25.0f) ) );
				ProBonus = (int)( (getSTR()/10) * ( 1.0f + ((float)pEffect->getLevel()/25.0f) ) );
			}
		}
	}

	int RaceWarHPBonus = 0;

	if ( m_pZone->isHolyLand() || m_pZone->isLevelWarZone() )
	{
		RaceWarHPBonus = getPercentValue( m_HP[ATTR_MAX], g_pVariableManager->getRaceWarHPBonus() );
	}

	// Passive Skill : Will of Iron (���� HP * 1.15)
	SkillSlot* pFabulousSoul = getSkill(SKILL_FABULOUS_SOUL);
	SkillSlot* pWillOfIron = getSkill(SKILL_WILL_OF_IRON);

	int HPBonus_WillOfIron = 0;

	if( (pFabulousSoul != NULL && pFabulousSoul->canUse()) ||	
		(pWillOfIron != NULL && pWillOfIron->canUse()) )
	{
		HPBonus_WillOfIron = m_HP[ATTR_MAX] * 0.15;	
	}

	SkillSlot* pLiveness = getSkill(SKILL_LIVENESS);
	int HPBonusPercent = 0,
		LivenessHPBonus =0,
		LivenessDefenseBonus = 0;
		
	if(pLiveness != NULL && pLiveness->canUse())
	{
		int level = m_SkillDomainLevels[SKILL_DOMAIN_GUN];

#ifdef __CHINA_SERVER__
		switch (g_pSkillInfoManager->getGradeByDomainLevel(level))
		{
			case SKILL_GRADE_APPRENTICE:   HPBonusPercent = 0; 
										   LivenessDefenseBonus = 0;
										   break;
			case SKILL_GRADE_ADEPT:        HPBonusPercent = 10;
										   LivenessDefenseBonus = 10;
										   break;
			case SKILL_GRADE_EXPERT:       HPBonusPercent = 25;
										   LivenessDefenseBonus = 35;
										   break;
			case SKILL_GRADE_MASTER:       HPBonusPercent = 40;
										   LivenessDefenseBonus = 60;
										   break;
			case SKILL_GRADE_GRAND_MASTER: HPBonusPercent = 100;
										   LivenessDefenseBonus = 100;
										   break;
			default:                       break;
		}

//		if ( level >= 125 ) HPBonusPercent = 50;
#else
		switch (g_pSkillInfoManager->getGradeByDomainLevel(level))
		{
			case SKILL_GRADE_APPRENTICE:   HPBonusPercent = 0; 
										   LivenessDefenseBonus = 0;
										   break;
			case SKILL_GRADE_ADEPT:        HPBonusPercent = 10;
										   LivenessDefenseBonus = 10;
										   break;
			case SKILL_GRADE_EXPERT:       HPBonusPercent = 20;
										   LivenessDefenseBonus = 35;
										   break;
			case SKILL_GRADE_MASTER:       HPBonusPercent = 30;
										   LivenessDefenseBonus = 60;
										   break;
			case SKILL_GRADE_GRAND_MASTER: HPBonusPercent = 40;
										   LivenessDefenseBonus = 100;
										   break;
			default:                       break;
		}

		if ( level >= 125 ) HPBonusPercent = 50;
#endif

		LivenessHPBonus = getPercentValue( m_HP[ATTR_MAX], HPBonusPercent);
		//m_Defense[ATTR_CURRENT]  = min(SLAYER_MAX_DEFENSE, m_Defense[ATTR_CURRENT] + LivenessDefenseBonus);
	}


	////	// ���� ���ʽ�
	// ����� ���� ���п� �������� �������̵� ���ʽ��� ������ �� �ִ�. by sigi
	//if ( g_pCombatInfoManager->isSlayerBonus() )
	int HPBonus = 0;
	{
		int bonusRatio = g_pVariableManager->getCombatSlayerHPBonusRatio();
		//g_pCombatInfoManager->getSlayerHPModify();

		if (bonusRatio > 0)
		{
			HPBonus = getPercentValue( m_HP[ATTR_MAX], bonusRatio);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	// �ϴ� ���� üũ ������ �ʱ�ȭ�ؼ� ���� ��� �� ��� ����� �����ϰ� �����Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	bool pOldRealWearingCheck[WEAR_MAX];	// by sigi. 2002.10.31
	for (int i=0; i<WEAR_MAX; i++) 
	{
		pOldRealWearingCheck[i] = m_pRealWearingCheck[i];
		m_pRealWearingCheck[i] = false;
	}

	//////////////////////////////////////////////////////////////////////////////
	// ��� ����� ��� ���ʽ� �ɼ�� �ް� �ȴ�
	//////////////////////////////////////////////////////////////////////////////
	// Blood Bible ������ ���ʽ� �ɼ�� �޴� �ɷ� ���ƴ�.
/*	if (m_pZone->isHolyLand() )
	{
		const list<OptionType_t>& optionType = g_pHolyLandRaceBonus->getSlayerOptionTypeList();
		list<OptionType_t>::const_iterator itr;
		for (itr=optionType.begin(); itr!=optionType.end(); itr++)
		{
			computeOptionStat( *itr );
		}
	}*/

	//////////////////////////////////////////////////////////////////////////////
	// Blood Bible ������ ���ʽ� �ɼ�� �޴´�.
	//////////////////////////////////////////////////////////////////////////////
	if ( m_pZone->isHolyLand() && !g_pWarSystem->hasActiveRaceWar() )
	{
		const BloodBibleBonusHashMap& bloodBibleBonus = g_pBloodBibleBonusManager->getBloodBibleBonuses();
		BloodBibleBonusHashMapConstItor itr;
		for (itr=bloodBibleBonus.begin(); itr!=bloodBibleBonus.end(); itr++)
		{
			if ( itr->second->getRace() == RACE_SLAYER )
			{
				OptionTypeList optionTypes = itr->second->getOptionTypeList();
				OptionTypeListConstItor optionItr;
				
				for ( optionItr = optionTypes.begin(); optionItr != optionTypes.end(); optionItr++ )
				{
					computeOptionStat( *optionItr );
				}
			}
		}
	}

	if ( g_pSweeperBonusManager->isAble( getZoneID() ) && g_pLevelWarZoneInfoManager->isCreatureBonusZone( this, getZoneID() ))
	{
		const SweeperBonusHashMap& sweeperBonuses = g_pSweeperBonusManager->getSweeperBonuses();

		SweeperBonusHashMapConstItor itr = sweeperBonuses.begin();
		SweeperBonusHashMapConstItor endItr = sweeperBonuses.end();

		for (; itr!=endItr; itr++)
		{
			if ( itr->second->getRace() == RACE_SLAYER && itr->second->getLevel() == g_pLevelWarZoneInfoManager->getCreatureLevelGrade( this ) )
			{
				OptionTypeList optionTypes = itr->second->getOptionTypeList();
				OptionTypeListConstItor optionItr;
				
				for ( optionItr = optionTypes.begin(); optionItr != optionTypes.end(); optionItr++ )
				{
					computeOptionStat( *optionItr );
				}
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// �⺻����� ������ �ִ� �ɼǵ�� �����Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	list<DefaultOptionSetType_t>::iterator itr = m_DefaultOptionSet.begin();
	for ( ; itr != m_DefaultOptionSet.end(); itr++ )
	{
		DefaultOptionSetInfo* pDefaultOptionSetInfo = g_pDefaultOptionSetInfoManager->getDefaultOptionSetInfo( (*itr) );
		if ( pDefaultOptionSetInfo != NULL )
		{
			const list<OptionType_t>& optionList = pDefaultOptionSetInfo->getOptionTypeList();
			list<OptionType_t>::const_iterator citr;
			for ( citr = optionList.begin(); citr != optionList.end(); citr++ )
			{
				computeOptionStat( *citr );
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// ���� �ִ� ���ʽ��� �����Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	if ( m_pPetInfo != NULL )
	{
		if ( m_pPetInfo->getPetAttr() != 0xff ) computeOptionClassStat( (OptionClass)m_pPetInfo->getPetAttr(), (int)m_pPetInfo->getPetAttrLevel() );
		if ( m_pPetInfo->getPetOption() != 0 ) computeOptionStat( m_pPetInfo->getPetOption() );
	}

	//////////////////////////////////////////////////////////////////////////////
	// �԰� �ִ� ������� üũ�Ѵ�.
	// for �� �ι��� ����� ��������� �ö��� �ɷ�ġ�� ���ؼ�
	// ��� �� �ְ� �Ǵ� ������� üũ�ϱ� ��ؼ��̴�.
	//////////////////////////////////////////////////////////////////////////////
	for (int j=0; j<WEAR_MAX; j++)
	{
		int wearCount = 0;

		for (int i=0; i<WEAR_MAX; i++)
		{
			Item* pItem = m_pWearItem[i];

			// ���� ����Ʈ�� �������� �ְ�
			// �װͿ� ���� üũ�� ���� ���� �ʾҴٸ�...
			if (pItem != NULL && m_pRealWearingCheck[i] == false)
			{
				// ���� ��¥�� ��� �� �ִ� �������̶��� �ɷ�ġ�� �÷��ش�.
				if (isRealWearing(pItem))
				{
					computeItemStat(pItem);

					// ���� ��������, üũ�� �ι� ���� �ʵ���
					// ����, ����� ���� üũ ������ ����
					if (isTwohandWeapon(pItem))
					{
						m_pRealWearingCheck[WEAR_LEFTHAND] = true;
						m_pRealWearingCheck[WEAR_RIGHTHAND] = true;
					}
					else m_pRealWearingCheck[i] = true;

					wearCount ++;
				}
			}
		}

		if (wearCount==0)
			break;
	}

	// by sigi. 2002.11.6
	bool bSendPacket = false;

	if (m_pPlayer!=NULL)
	{	
		bSendPacket = (dynamic_cast<GamePlayer*>(m_pPlayer)->getPlayerStatus()==GPS_NORMAL);
	}

	// �ϴ� ����� �� �Ծ��µ�..
	// �ɷ�ġ�� ������ ������ ������ �ȵǴ� ������� ���� ����� ���ش�.
	// �������� �� �Ծ��µ� ����� ��� �� �ִٸ� ������ ��Ŷ� ������.
	// by sigi. 2002.10.30
	for (int i=0; i<WEAR_MAX; i++)
	{
		if (m_pRealWearingCheck[i])
		{
			// by sigi. 2002.10.31
			if (pOldRealWearingCheck[i]==false)
			{
				Item* pItem = m_pWearItem[i];
				if (pItem!=NULL)
				{
					Item::ItemClass IClass = pItem->getItemClass();
					ItemType_t		IType  = pItem->getItemType();

					Color_t color = getItemShapeColor( pItem );
					addShape(IClass, IType, color);

					if (bSendPacket)
					{
						GCChangeShape _GCChangeShape;
						_GCChangeShape.setObjectID(getObjectID());
						_GCChangeShape.setItemClass(IClass);
						_GCChangeShape.setItemType(IType);
						_GCChangeShape.setOptionType(pItem->getFirstOptionType());
						_GCChangeShape.setAttackSpeed(m_AttackSpeed[ATTR_CURRENT]);
						m_pZone->broadcastPacket(m_X, m_Y, &_GCChangeShape, this);
					}
				}
			}
		}
		else
		{
			Item* pItem = m_pWearItem[i];
			if (pItem!=NULL)
			{
				removeShape(pItem->getItemClass(), bSendPacket);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	// ���� ���ʽ��� �����Ѵ�.
	///////////////////////////////////////////////////////////////////////////////
	// ��ƿ Ȯ��� �����ϱ� ���� �̸� �����Ѵ�.
	///////////////////////////////////////////////////////////////////////////////
	if ( hasRankBonus( RankBonus::RANK_BONUS_WIGHT_HAND ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_WIGHT_HAND );
		Assert( pRankBonus != NULL );

		int StealBonus = pRankBonus->getPoint();

		m_HPStealAmount += StealBonus;
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_SEIREN_HAND ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_SEIREN_HAND );
		Assert( pRankBonus != NULL );

		int StealBonus = pRankBonus->getPoint();

		m_MPStealAmount += StealBonus;
	}

	//////////////////////////////////////////////////////////////////////////////
	// HP, MP ��ƿ Ȯ��� ������ �д�.
	//////////////////////////////////////////////////////////////////////////////
	m_HPStealRatio = computeStealRatio(CClass, m_HPStealAmount, &attr);
	m_MPStealRatio = computeStealRatio(CClass, m_MPStealAmount, &attr);

	Item* pWeapon = m_pWearItem[Slayer::WEAR_RIGHTHAND];
	Item* pShield = m_pWearItem[Slayer::WEAR_LEFTHAND];

	//////////////////////////////////////////////////////////////////////////////
	// �ΰ����� �ɷ�ġ�� ��� ����ϴ� ����Ʈ�� �˻��Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	if (isFlag(Effect::EFFECT_CLASS_STRIKING))
	{
		EffectStriking* pStriking = dynamic_cast<EffectStriking*>(findEffect(Effect::EFFECT_CLASS_STRIKING));
		if (pStriking != NULL)
		{
			Damage_t   DamageBonus  = pStriking->getDamageBonus();

			if (pWeapon != NULL && pStriking->isTargetItem( pWeapon ) )
			{
				m_Damage[ATTR_CURRENT] = min(SLAYER_MAX_DAMAGE, m_Damage[ATTR_CURRENT] + DamageBonus);
				m_Damage[ATTR_MAX]     = min(SLAYER_MAX_DAMAGE, m_Damage[ATTR_MAX] + DamageBonus);

				// ItemOID�� ��ġ�Ѵٴ� ��� ���� ��Ʈ����ŷ�� �ɷȰų�,
				// �ٸ� ���⸦ �����ٰ�, �ٽ� ��Ʈ����ŷ�� �ɸ� ���⸦
				// �����ٴ� ���̴�. �׷��Ƿ� ����Ʈ�� ���̶��� �������� �Ѵ�.
				GCAddEffect gcAddEffect;
				gcAddEffect.setObjectID(m_ObjectID);
				gcAddEffect.setEffectID(Effect::EFFECT_CLASS_STRIKING);
				gcAddEffect.setDuration(pStriking->getRemainDuration());
				m_pZone->broadcastPacket(m_X, m_Y, &gcAddEffect);
			}
			else
			{
				// ItemOID�� ��ġ���� �ʴ´ٴ� ��� ��Ʈ����ŷ�� �ɸ� ���¿���
				// �ٸ� ���⸦ �����ٴ� ���̴�. �׷��Ƿ� ������ �����̾�Դ�
				// ��Ʈ����ŷ�� �ɷ��ִ�. �� ����Ʈ�� ��������� �ϹǷ�...
				GCRemoveEffect gcRemoveEffect;
				gcRemoveEffect.setObjectID(m_ObjectID);
				gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_STRIKING);
				m_pZone->broadcastPacket(getX(), getY(), &gcRemoveEffect);
			}
		}
	}

	if (isFlag(Effect::EFFECT_CLASS_BLOOD_DRAIN))
	{
		int DefensePenalty    = getPercentValue(m_Defense[ATTR_CURRENT],    20);
		int ToHitPenalty      = getPercentValue(m_ToHit[ATTR_CURRENT],      20);
		int ProtectionPenalty = getPercentValue(m_Protection[ATTR_CURRENT], 20);
		int DamagePenalty1    = getPercentValue(m_Damage[ATTR_CURRENT],     20);
		int DamagePenalty2    = getPercentValue(m_Damage[ATTR_MAX],         20);

		m_Defense[ATTR_CURRENT]    = max(0, m_Defense[ATTR_CURRENT]    - DefensePenalty);
		m_ToHit[ATTR_CURRENT]      = max(0, m_ToHit[ATTR_CURRENT]      - ToHitPenalty);
		m_Protection[ATTR_CURRENT] = max(0, m_Protection[ATTR_CURRENT] - ProtectionPenalty);
		m_Damage[ATTR_CURRENT]     = max(0, m_Damage[ATTR_CURRENT]     - DamagePenalty1);
		m_Damage[ATTR_MAX]         = max(0, m_Damage[ATTR_MAX]         - DamagePenalty2);
	}
	if (isFlag(Effect::EFFECT_CLASS_DOOM))
	{
		EffectDoom* pDoom = dynamic_cast<EffectDoom*>(findEffect(Effect::EFFECT_CLASS_DOOM));
		if (pDoom!= NULL)
		{
			int DefensePenalty    = getPercentValue(m_Defense[ATTR_CURRENT], pDoom->getDefensePenalty());
			int ProtectionPenalty = getPercentValue(m_Protection[ATTR_CURRENT], pDoom->getProtectionPenalty());

			m_Defense[ATTR_CURRENT]    = max(0, m_Defense[ATTR_CURRENT]    - DefensePenalty);
			m_Protection[ATTR_CURRENT] = max(0, m_Protection[ATTR_CURRENT] - ProtectionPenalty);
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_SEDUCTION))
	{
		EffectSeduction* pSeduction = dynamic_cast<EffectSeduction*>(findEffect(Effect::EFFECT_CLASS_SEDUCTION));
		if (pSeduction!= NULL)
		{
			int ToHitPenalty   = getPercentValue(m_ToHit[ATTR_CURRENT],  pSeduction->getToHitPenalty());
			int DamagePenalty1 = getPercentValue(m_Damage[ATTR_CURRENT], pSeduction->getDamagePenalty());
			int DamagePenalty2 = getPercentValue(m_Damage[ATTR_MAX],     pSeduction->getDamagePenalty());

			m_ToHit[ATTR_CURRENT]  = max(0, m_ToHit[ATTR_CURRENT] - ToHitPenalty);
			m_Damage[ATTR_CURRENT] = max(0, m_Damage[ATTR_CURRENT] - DamagePenalty1);
			m_Damage[ATTR_MAX]     = max(0, m_Damage[ATTR_MAX] - DamagePenalty2);
		}
	}
/*	if (isFlag(Effect::EFFECT_CLASS_PARALYZE))
	{
		EffectParalyze* pParalyze = dynamic_cast<EffectParalyze*>(findEffect(Effect::EFFECT_CLASS_PARALYZE));
		if (pParalyze != NULL)
		{
			int DefensePenalty = getPercentValue(m_Defense[ATTR_CURRENT], pParalyze->getDefensePenalty());
			m_Defense[ATTR_CURRENT] = max(0, m_Defense[ATTR_CURRENT] - DefensePenalty);
		}
	}*/
	if (isFlag(Effect::EFFECT_CLASS_CHARGING_POWER))
	{
		EffectChargingPower* pChargingPower= dynamic_cast<EffectChargingPower*>(findEffect(Effect::EFFECT_CLASS_CHARGING_POWER));
		if (pChargingPower != NULL)
		{
			if (!isRealWearing(Slayer::WEAR_RIGHTHAND) || pWeapon == NULL || pWeapon->getItemClass() != Item::ITEM_CLASS_BLADE)
			{
				pChargingPower->setDeadline(0);
			}
			else 
	//		if (pChargingPower != NULL)
			{
				int DamageBonus = pChargingPower->getDamageBonus();

				m_Damage[ATTR_CURRENT] = min(SLAYER_MAX_DAMAGE, m_Damage[ATTR_CURRENT] + DamageBonus);
				m_Damage[ATTR_MAX]     = min(SLAYER_MAX_DAMAGE, m_Damage[ATTR_MAX] + DamageBonus);
			}
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_DANCING_SWORD))
	{
		EffectDancingSword* pDancingSword = dynamic_cast<EffectDancingSword*>(findEffect(Effect::EFFECT_CLASS_DANCING_SWORD));
		if (pDancingSword!= NULL)
		{
			m_ToHit[ATTR_CURRENT] = min(SLAYER_MAX_TOHIT, m_ToHit[ATTR_CURRENT] + pDancingSword->getToHitBonus());
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_GHOST_BLADE))
	{
		EffectGhostBlade* pGhostBlade = dynamic_cast<EffectGhostBlade*>(findEffect(Effect::EFFECT_CLASS_GHOST_BLADE));
		if (pGhostBlade != NULL)
		{
			m_ToHit[ATTR_CURRENT] = min(SLAYER_MAX_TOHIT, m_ToHit[ATTR_CURRENT] + pGhostBlade->getToHitBonus());
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_MIND_CONTROL))
	{
		EffectMindControl* pMindControl = dynamic_cast<EffectMindControl*>(findEffect(Effect::EFFECT_CLASS_MIND_CONTROL));
		if (pMindControl != NULL)
		{
			m_ToHit[ATTR_CURRENT]   = min(SLAYER_MAX_TOHIT, m_ToHit[ATTR_CURRENT] + pMindControl->getToHitBonus());
			m_Defense[ATTR_CURRENT] = min(SLAYER_MAX_DEFENSE, m_Defense[ATTR_CURRENT] + pMindControl->getDefenseBonus());
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_PROTECTION_FROM_POISON))
	{
		EffectProtectionFromPoison* pProtectionFromPoison = dynamic_cast<EffectProtectionFromPoison*>(findEffect(Effect::EFFECT_CLASS_PROTECTION_FROM_POISON));
		if (pProtectionFromPoison != NULL)
		{
			m_Resist[MAGIC_DOMAIN_POISON] += pProtectionFromPoison->getResist();
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_PROTECTION_FROM_CURSE))
	{
		EffectProtectionFromCurse* pProtectionFromCurse = dynamic_cast<EffectProtectionFromCurse*>(findEffect(Effect::EFFECT_CLASS_PROTECTION_FROM_CURSE));
		if (pProtectionFromCurse != NULL)
		{
			m_Resist[MAGIC_DOMAIN_CURSE] += pProtectionFromCurse->getResist();
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_PROTECTION_FROM_ACID))
	{
		EffectProtectionFromAcid* pProtectionFromAcid = dynamic_cast<EffectProtectionFromAcid*>(findEffect(Effect::EFFECT_CLASS_PROTECTION_FROM_ACID));
		if (pProtectionFromAcid != NULL)
		{
			m_Resist[MAGIC_DOMAIN_ACID] += pProtectionFromAcid->getResist();
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_PROTECTION_FROM_BLOOD))
	{
		EffectProtectionFromBlood* pProtectionFromBlood = dynamic_cast<EffectProtectionFromBlood*>(findEffect(Effect::EFFECT_CLASS_PROTECTION_FROM_BLOOD));
		if (pProtectionFromBlood != NULL)
		{
			m_Resist[MAGIC_DOMAIN_BLOOD] += pProtectionFromBlood->getResist();
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_EXPANSION))
	{
		EffectExpansion* pExpansion = dynamic_cast<EffectExpansion*>(findEffect(Effect::EFFECT_CLASS_EXPANSION));
		if (pExpansion != NULL)
		{
			int Bonus = pExpansion->getHPBonus();
			// ü��� ��Ƣ�� ���ش�...
			m_HP[ATTR_MAX] = m_HP[ATTR_MAX] + Bonus;
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_BERSERKER))
	{
		EffectBerserker* pBerserker= dynamic_cast<EffectBerserker*>(findEffect(Effect::EFFECT_CLASS_BERSERKER));
		if (pBerserker != NULL)
		{
			Damage_t BladeMinDamage = 0;
			Damage_t BladeMaxDamage = 0;

			if ( attr.pWeapon != NULL && attr.pWeapon->getItemClass() == Item::ITEM_CLASS_BLADE )
			{
				BladeMinDamage = attr.pWeapon->getMinDamage();
				BladeMaxDamage = attr.pWeapon->getMaxDamage();
			}

			// ������ �� ���� ���ʽ�, ���潺 �� ����ؼ� ����Ƽ�� �ۼ�Ʈ ���̴�.
			// �������� �ɷ�ġ�� ���� �������� ����(��) �������� �տ� ���� ����̴�.
			// �ٸ� ����Ʈ�� ���� �߰� �������� �� ���꿡�� ����Ѵ�.
			int ToHitBonus        = getPercentValue(m_ToHit[ATTR_CURRENT], pBerserker->getToHitBonus());
			int MinDamageBonus    = getPercentValue(AttrMinDamage+BladeMinDamage, pBerserker->getDamageBonus());
			int MaxDamageBonus    = getPercentValue(AttrMaxDamage+BladeMaxDamage, pBerserker->getDamageBonus());
			int DefensePenalty    = getPercentValue(m_Defense[ATTR_CURRENT], pBerserker->getDefensePenalty());
			int ProtectionPenalty = getPercentValue(m_Defense[ATTR_CURRENT], pBerserker->getProtectionPenalty());

/*			cout << "Damage Bonus : " << (int)pBerserker->getDamageBonus()
				 << " MinDamage : " << (int)(AttrMinDamage+BladeMinDamage)
				 << " MaxDamage : " << (int)(AttrMaxDamage+BladeMaxDamage)
				 << " MinDamageBonus : " << (int)MinDamageBonus
				 << " MaxDamageBonus : " << (int)MaxDamageBonus
				 << endl;
*/
			m_ToHit[ATTR_CURRENT]      = min(SLAYER_MAX_TOHIT, m_ToHit[ATTR_CURRENT] + ToHitBonus);
			m_Damage[ATTR_CURRENT]     = min(SLAYER_MAX_DAMAGE, m_Damage[ATTR_CURRENT] + MinDamageBonus);
			m_Damage[ATTR_MAX]         = min(SLAYER_MAX_DAMAGE, m_Damage[ATTR_MAX] + MaxDamageBonus);
			m_Defense[ATTR_CURRENT]    = max(0, m_Defense[ATTR_CURRENT] - DefensePenalty);
			m_Protection[ATTR_CURRENT] = max(0, m_Protection[ATTR_CURRENT] - ProtectionPenalty);
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_DEATH))
	{
		EffectDeath* pDeath = dynamic_cast<EffectDeath*>(findEffect(Effect::EFFECT_CLASS_DEATH));
		if (pDeath != NULL)
		{
			for (int i=0; i<MAGIC_DOMAIN_MAX; i++)
			{
				m_Resist[i] -= pDeath->getResistPenalty();
//				if ( m_Resist[i] < 0 ) m_Resist[i] = 0;
			}
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_BLUNTING))
	{
		EffectBlunting* pBlunting = dynamic_cast<EffectBlunting*>(findEffect(Effect::EFFECT_CLASS_BLUNTING));
		if ( pBlunting != NULL )
		{
			int DefensePenalty = pBlunting->getDefensePenalty();
			m_Defense[ATTR_CURRENT]    = max(0, m_Defense[ATTR_CURRENT] - DefensePenalty);
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_HOLY_ARMOR))
	{
		EffectHolyArmor* pHolyArmor = dynamic_cast<EffectHolyArmor*>(findEffect(Effect::EFFECT_CLASS_HOLY_ARMOR));

		if ( pHolyArmor != NULL )
		{
			m_Defense[ATTR_CURRENT] = m_Defense[ATTR_CURRENT] + pHolyArmor->getDefBonus();
		}
	}

	// �нú� ������ ���� �ö󰡴� �ɷ�ġ�� �����Ѵ�.
	if (pWeapon != NULL)
	{
		Item::ItemClass IClass = pWeapon->getItemClass();
		int DamageBonus = 0;
		int ToHitBonus = 0;
		int CriticalRatioBonus = 0;

		// ���� ����.. ObservingEyeüũ. by sigi. 2002.6.19
		if (pWeapon->isGun() && isFlag(Effect::EFFECT_CLASS_OBSERVING_EYE))
		{
			EffectObservingEye* pObservingEye= dynamic_cast<EffectObservingEye*>(findEffect(Effect::EFFECT_CLASS_OBSERVING_EYE));
			if (pObservingEye != NULL)
			{
				int DamageBonus = pObservingEye->getDamageBonus();

				m_Damage[ATTR_CURRENT] = min(SLAYER_MAX_DAMAGE, m_Damage[ATTR_CURRENT] + DamageBonus);
				m_Damage[ATTR_MAX]     = min(SLAYER_MAX_DAMAGE, m_Damage[ATTR_MAX] + DamageBonus);

				CriticalRatioBonus += pObservingEye->getCriticalHitBonus();

//				m_CriticalRatio[ATTR_CURRENT] = m_CriticalRatio[ATTR_CURRENT] + CriticalRatioBonus;
//				m_CriticalRatio[ATTR_MAX]     = m_CriticalRatio[ATTR_MAX] + CriticalRatioBonus;

				//int VisionBonus = pObservingEye->getVisionBonus();
				// �̰Ŵ� client���� ó���ϵ��� �Ѵ�. 
			}
		}

		// Liveness ���ʽ� �����ֱ�
		if ( pLiveness != NULL && pWeapon->isGun() )
		{
			m_HP[ATTR_MAX] = m_HP[ATTR_MAX] + LivenessHPBonus;
			m_Defense[ATTR_CURRENT]  = min(SLAYER_MAX_DEFENSE, m_Defense[ATTR_CURRENT] + LivenessDefenseBonus);
		}

		// Passive Skill : Will of Iron �����ֱ� : SWORD or BLADE �϶�
		if ( (pFabulousSoul != NULL && pWeapon->getItemClass() == Item::ITEM_CLASS_SWORD) ||
			 (pWillOfIron != NULL && pWeapon->getItemClass() == Item::ITEM_CLASS_BLADE) )
		{
			m_HP[ATTR_MAX] += HPBonus_WillOfIron;
		}

		if ( pWeapon->isGun() )
		{
			DamageBonus += getSkillDomainLevel( SKILL_DOMAIN_GUN ) / 10;
		}

		SkillSlot* pArmsMastery1 = getSkill(SKILL_ARMS_MASTERY_1);
		SkillSlot* pArmsMastery2 = getSkill(SKILL_ARMS_MASTERY_2);

		if (IClass == Item::ITEM_CLASS_AR)
		{
			SkillSlot* pARMastery = getSkill(SKILL_AR_MASTERY);
			if (pARMastery != NULL && pARMastery->canUse())
			{
				DamageBonus += 3;
				ToHitBonus += 5;
			}

			if ( pArmsMastery2 != NULL && pArmsMastery2->canUse() )
			{
				ToHitBonus += 6;
				DamageBonus += 5;
				CriticalRatioBonus += 6;
			}
			else if ( pArmsMastery1 != NULL && pArmsMastery1->canUse() )
			{
				ToHitBonus += 4;
				DamageBonus += 3;
				CriticalRatioBonus += 4;
			}

		}
		else if (IClass == Item::ITEM_CLASS_SMG)
		{
			SkillSlot* pSMGMastery = getSkill(SKILL_SMG_MASTERY);
			if (pSMGMastery != NULL && pSMGMastery->canUse())
			{
				DamageBonus += 3;
				ToHitBonus += 5;
			}

			if ( pArmsMastery2 != NULL && pArmsMastery2->canUse() )
			{
				ToHitBonus += 5;
				DamageBonus += 5;
				CriticalRatioBonus += 7;
			}
			else if ( pArmsMastery1 != NULL && pArmsMastery1->canUse() )
			{
				ToHitBonus += 3;
				DamageBonus += 3;
				CriticalRatioBonus += 5;
			}

		}
		else if (IClass == Item::ITEM_CLASS_SG)
		{
			SkillSlot* pSGMastery = getSkill(SKILL_SG_MASTERY);
			if (pSGMastery != NULL && pSGMastery->canUse())
			{
				DamageBonus += 3;
				ToHitBonus += 5;
			}

			if ( pArmsMastery2 != NULL && pArmsMastery2->canUse() )
			{
				ToHitBonus += 5;
				DamageBonus += 6;
				CriticalRatioBonus += 10;
			}
			else if ( pArmsMastery1 != NULL && pArmsMastery1->canUse() )
			{
				ToHitBonus += 3;
				DamageBonus += 5;
				CriticalRatioBonus += 9;
			}
		}
		else if (IClass == Item::ITEM_CLASS_SR)
		{
			SkillSlot* pSRMastery = getSkill(SKILL_SR_MASTERY);
			if (pSRMastery != NULL && pSRMastery->canUse())
			{
				DamageBonus += 3;
				ToHitBonus += 5;
			}

			if ( pArmsMastery2 != NULL && pArmsMastery2->canUse() )
			{
				ToHitBonus += 11;
				DamageBonus += 7;
				CriticalRatioBonus += 5;
			}
			else if ( pArmsMastery1 != NULL && pArmsMastery1->canUse() )
			{
				ToHitBonus += 9;
				DamageBonus += 5;
				CriticalRatioBonus += 3;
			}

			if (isFlag(Effect::EFFECT_CLASS_SNIPING_MODE))
			{
				//DamageBonus += 3;
				//ToHitBonus += 5;

				// by sigi. 2002.12.3
				SkillSlot* pSniping = getSkill(SKILL_SNIPING);

				if (pSniping!=NULL)
				{
					int level = pSniping->getExpLevel();

					int damage = m_Damage[ATTR_CURRENT];
					int toHit  = m_ToHit[ATTR_CURRENT];

					int damageBonusPercent = m_STR[ATTR_CURRENT]/20 * level/20;
					int toHitBonusPercent = m_DEX[ATTR_CURRENT]/10 * level/20;

					DamageBonus += damage * damageBonusPercent/100;
					ToHitBonus += toHit * toHitBonusPercent/100;
				}

			}
		}
		else if (IClass == Item::ITEM_CLASS_SWORD)	// by sigi. 2002.6.7
		{
			// SWORD_MASTERY
			SkillSlot* pMastery = getSkill(SKILL_SWORD_MASTERY);
			if (pMastery != NULL && pMastery->canUse())
			{
				int level = m_SkillDomainLevels[SKILL_DOMAIN_SWORD];

				/*
				switch (g_pSkillInfoManager->getGradeByDomainLevel(level))
				{
					case SKILL_GRADE_APPRENTICE:   DamageBonus += 2; break;
					case SKILL_GRADE_ADEPT:        DamageBonus += 3; break;
					case SKILL_GRADE_EXPERT:       DamageBonus += 4; break;
					case SKILL_GRADE_MASTER:       DamageBonus += 5; break;
					case SKILL_GRADE_GRAND_MASTER: DamageBonus += 6; break;
					default:                       break;
				}
				*/

				// by sigi. 2002.12.3
//				DamageBonus += level*10/125;
				DamageBonus += 3 + level/15;
			}
		}
		else if (IClass == Item::ITEM_CLASS_BLADE)	// by sigi. 2002.6.7
		{
			// CONCENTRATION
			SkillSlot* pSkill = getSkill(SKILL_CONCENTRATION);
			if (pSkill != NULL && pSkill->canUse())
			{
				int level = m_SkillDomainLevels[SKILL_DOMAIN_BLADE];

				/*
				switch (g_pSkillInfoManager->getGradeByDomainLevel(level))
				{
					case SKILL_GRADE_APPRENTICE:   ToHitBonus += 3; break;
					case SKILL_GRADE_ADEPT:        ToHitBonus += 6; break;
					case SKILL_GRADE_EXPERT:       ToHitBonus += 9; break;
					case SKILL_GRADE_MASTER:       ToHitBonus += 12; break;
					case SKILL_GRADE_GRAND_MASTER: ToHitBonus += 15; break;
					default:                       break;
				}
				*/
				// by sigi. 2002.12.3
//				ToHitBonus += level/6;
				ToHitBonus += 3+(level/10);
			}

			// EVASION
		 	pSkill = getSkill(SKILL_EVASION);
			if (pSkill != NULL && pSkill->canUse())
			{
				int level = m_SkillDomainLevels[SKILL_DOMAIN_BLADE];

				//  by sigi. 2002.12.3
//				Defense_t DefenseBonus = (level-20)/5;
				Defense_t DefenseBonus = 3 + (level-20)/5;
				/*
				switch (g_pSkillInfoManager->getGradeByDomainLevel(level))
				{
					case SKILL_GRADE_APPRENTICE:   DefenseBonus += 3; break;
					case SKILL_GRADE_ADEPT:        DefenseBonus += 6; break;
					case SKILL_GRADE_EXPERT:       DefenseBonus += 9; break;
					case SKILL_GRADE_MASTER:       DefenseBonus += 12; break;
					case SKILL_GRADE_GRAND_MASTER: DefenseBonus += 15; break;
					default:                       break;
				}
				*/

				// �ϴ� Evasion�� defense�� �ٲٹǷ� ���⼭�� ����.. by sigi
				m_Defense[ATTR_CURRENT]  = min(SLAYER_MAX_DEFENSE, m_Defense[ATTR_CURRENT] + DefenseBonus);
				m_Defense[ATTR_MAX]      = min(SLAYER_MAX_DEFENSE, m_Defense[ATTR_MAX] + DefenseBonus);
			}
		}

		//cout << "ToHitBonus = " << ToHitBonus << endl;

		if ( pWeapon->isGun() )
		{
			// Concealment ���ʽ� �����ֱ�
			m_Defense[ATTR_CURRENT] += DefBonus;
			m_Protection[ATTR_CURRENT] += ProBonus;
			m_Defense[ATTR_MAX] += DefBonus;
			m_Protection[ATTR_MAX] += ProBonus;
		}

		m_ToHit[ATTR_CURRENT]  = min(SLAYER_MAX_TOHIT, m_ToHit[ATTR_CURRENT] + ToHitBonus);
		m_ToHit[ATTR_MAX]      = min(SLAYER_MAX_TOHIT, m_ToHit[ATTR_MAX] + ToHitBonus);
		m_Damage[ATTR_CURRENT] = min(SLAYER_MAX_DAMAGE, m_Damage[ATTR_CURRENT] + DamageBonus);
		m_Damage[ATTR_MAX]     = min(SLAYER_MAX_DAMAGE, m_Damage[ATTR_MAX] + DamageBonus);
		m_CriticalRatio[ATTR_CURRENT] = m_CriticalRatio[ATTR_CURRENT] + CriticalRatioBonus;
		m_CriticalRatio[ATTR_MAX]     = m_CriticalRatio[ATTR_MAX] + CriticalRatioBonus;

	}

	// ���� üũ. by sigi. 2002.6.7
	if (pShield!=NULL && pShield->getItemClass()==Item::ITEM_CLASS_SHIELD)
	{
		int ProtectionBonus = 0;
		SkillSlot* pMastery = getSkill(SKILL_SHIELD_MASTERY);
		if (pMastery != NULL && pMastery->canUse())
		{
			int level = m_SkillDomainLevels[SKILL_DOMAIN_SWORD];
			/*
			switch (g_pSkillInfoManager->getGradeByDomainLevel(level))
			{
				case SKILL_GRADE_APPRENTICE:   ProtectionBonus += 3; break;
				case SKILL_GRADE_ADEPT:        ProtectionBonus += 6; break;
				case SKILL_GRADE_EXPERT:       ProtectionBonus += 9; break;
				case SKILL_GRADE_MASTER:       ProtectionBonus += 12; break;
				case SKILL_GRADE_GRAND_MASTER: ProtectionBonus += 15; break;
				default:                       break;
			}
			*/
			// by sigi. 2002.12.3
//			ProtectionBonus += (level-20)/5;
			ProtectionBonus += 5 + (level-20)/5;

			m_Protection[ATTR_CURRENT]  = min(SLAYER_MAX_PROTECTION, m_Protection[ATTR_CURRENT] + ProtectionBonus);
			m_Protection[ATTR_MAX]      = min(SLAYER_MAX_PROTECTION, m_Protection[ATTR_MAX] + ProtectionBonus);
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	// ���� ���ʽ��� �����Ѵ�.
	///////////////////////////////////////////////////////////////////////////////
	if ( hasRankBonus( RankBonus::RANK_BONUS_DEADLY_SPEAR ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_DEADLY_SPEAR );
		Assert( pRankBonus != NULL );

		int CriticalRatioBonus = pRankBonus->getPoint();

		m_CriticalRatio[ATTR_CURRENT] = m_CriticalRatio[ATTR_CURRENT] + CriticalRatioBonus;
		m_CriticalRatio[ATTR_MAX]     = m_CriticalRatio[ATTR_MAX] + CriticalRatioBonus;
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_BEHEMOTH_ARMOR ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_BEHEMOTH_ARMOR );
		Assert( pRankBonus != NULL );

		Defense_t DefenseBonus = pRankBonus->getPoint();

		m_Defense[ATTR_CURRENT]  = min(SLAYER_MAX_DEFENSE, m_Defense[ATTR_CURRENT] + DefenseBonus);
		m_Defense[ATTR_MAX]      = min(SLAYER_MAX_DEFENSE, m_Defense[ATTR_MAX] + DefenseBonus);
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_DRAGON_EYE ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_DRAGON_EYE );
		Assert( pRankBonus != NULL );

		int ToHitBonus = pRankBonus->getPoint();

		m_ToHit[ATTR_CURRENT]  = min(SLAYER_MAX_TOHIT, m_ToHit[ATTR_CURRENT] + ToHitBonus);
		m_ToHit[ATTR_MAX]      = min(SLAYER_MAX_TOHIT, m_ToHit[ATTR_MAX] + ToHitBonus);
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_IMMORTAL_HEART ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_IMMORTAL_HEART );
		Assert( pRankBonus != NULL );

		int HPBonus = pRankBonus->getPoint();

		m_HP[ATTR_MAX] = m_HP[ATTR_MAX] + HPBonus;
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_RELIANCE_BRAIN ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_RELIANCE_BRAIN );
		Assert( pRankBonus != NULL );

		int MPBonus = pRankBonus->getPoint();

		m_MP[ATTR_MAX] = min(SLAYER_MAX_MP, m_MP[ATTR_MAX] + MPBonus);
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_SLAYING_KNIFE ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_SLAYING_KNIFE );
		Assert( pRankBonus != NULL );

		int DamageBonus = pRankBonus->getPoint();

		m_Damage[ATTR_CURRENT] = min(SLAYER_MAX_DAMAGE, m_Damage[ATTR_CURRENT] + DamageBonus);
		m_Damage[ATTR_MAX]     = min(SLAYER_MAX_DAMAGE, m_Damage[ATTR_MAX] + DamageBonus);
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_HAWK_WING ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_HAWK_WING );
		Assert( pRankBonus != NULL );

		int AttackSpeedBonus = pRankBonus->getPoint();

		m_AttackSpeed[ATTR_CURRENT]	+= AttackSpeedBonus;
		m_AttackSpeed[ATTR_MAX] 	+= AttackSpeedBonus;
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_SAPPHIRE_BLESS ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_SAPPHIRE_BLESS );
		Assert( pRankBonus != NULL );

		int ResistBonus = pRankBonus->getPoint();

		m_Resist[MAGIC_DOMAIN_ACID] += ResistBonus;
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_RUBY_BLESS ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_RUBY_BLESS );
		Assert( pRankBonus != NULL );

		int ResistBonus = pRankBonus->getPoint();

		m_Resist[MAGIC_DOMAIN_BLOOD] += ResistBonus;
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_DIAMOND_BLESS ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_DIAMOND_BLESS );
		Assert( pRankBonus != NULL );

		int ResistBonus = pRankBonus->getPoint();

		m_Resist[MAGIC_DOMAIN_CURSE] += ResistBonus;
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_EMERALD_BLESS ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_EMERALD_BLESS );
		Assert( pRankBonus != NULL );

		int ResistBonus = pRankBonus->getPoint();

		m_Resist[MAGIC_DOMAIN_POISON] += ResistBonus;
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_FORTUNE_HAND ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_FORTUNE_HAND );
		Assert( pRankBonus != NULL );

		int LuckBonus = pRankBonus->getPoint();

		m_Luck += LuckBonus;
	}

	// ���� ���ʽ� ����
	if ( HPBonus > 0 )
	{
		m_HP[ATTR_MAX] = min( SLAYER_MAX_HP, m_HP[ATTR_MAX] + HPBonus );
	}

	if ( RaceWarHPBonus > 0 )
	{
		m_HP[ATTR_MAX] = min( SLAYER_MAX_HP, m_HP[ATTR_MAX] + RaceWarHPBonus );
	}

	// ������ų �ʱ�ȭ
	initCastleSkill();
//	cout << getName() << "�� Luck : " << m_Luck << endl;

	// ���� HP�� MAX HP���� �����
	/*
	if ( m_HP[ATTR_CURRENT] > m_HP[ATTR_MAX] )
	{
		m_HP[ATTR_CURRENT] = m_HP[ATTR_MAX];
	}
	*/

	// ��Ƽ�� ũ�⿡ ������ �ɷ�ġ�� ���� �� �ִ�.

	/*
	// ��Ƽ �ο����� �Ѿ����� ��� ������ �ٽ� �����Ѵ�.
	if (numPartyMember == -1)
	{
		if (m_PartyID != 0)
		{
			LocalPartyManager* pLPM = getLocalPartyManager();
			Assert(pLPM != NULL);
	
			numPartyMember = pLPM->getAdjacentMemberSize(m_PartyID, this);
		}
	}

	if (numPartyMember > 1)
	{

		uint ToHitBonus      = 0;
		uint DefenseBonus    = 0;
		uint ProtectionBonus = 0;
		uint DamageBonus     = 0;

		switch (numPartyMember)
		{
			case 2: ToHitBonus +=  2; DefenseBonus += 1; ProtectionBonus += 1; DamageBonus += 1; break;
			case 3: ToHitBonus +=  4; DefenseBonus += 2; ProtectionBonus += 2; DamageBonus += 1; break;
			case 4: ToHitBonus +=  6; DefenseBonus += 3; ProtectionBonus += 3; DamageBonus += 2; break;
			case 5: ToHitBonus +=  8; DefenseBonus += 4; ProtectionBonus += 4; DamageBonus += 2; break;
			case 6: ToHitBonus += 10; DefenseBonus += 5; ProtectionBonus += 5; DamageBonus += 3; break;
			default: break; 
		}

		m_ToHit[ATTR_CURRENT]      += ToHitBonus;
		m_Defense[ATTR_CURRENT]    += DefenseBonus;
		m_Protection[ATTR_CURRENT] += ProtectionBonus;
		m_Damage[ATTR_CURRENT]     += DamageBonus;
		m_Damage[ATTR_MAX]         += DamageBonus;
	}
	*/

	/*
	printf("BareMINDamage:%d\n", m_Damage[ATTR_CURRENT]);
	printf("BareMAXDamage:%d\n", m_Damage[ATTR_MAX]);
	if (pWeapon != NULL)
	{
		printf("+WeaponMINDamage:%d\n", m_Damage[ATTR_CURRENT] + pWeapon->getMinDamage());
		printf("+WeaponMAXDamage:%d\n", m_Damage[ATTR_MAX] + pWeapon->getMaxDamage());
	}
	*/

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// STR, DEX, INT�� ����
// CURRENT = �⺻ ��ġ + ������ ��ġ + ���� ��ġ
// MAX     = �⺻ ��ġ + ������ ��ġ
// BASIC   = �⺻ ��ġ
//
// HP, MP�� ����
// CURRENT = ���� ��ġ
// MAX     = ���� �ƽ�
// BASIC   = �����ۿ� ���� ��ȭ ��ġ
//
// Defense, Protection, ToHit�� ����
// CURRENT = ���� ��ġ
// MAX     = �����ۿ� ���� ��ȭ ��ġ
//
// Damage�� ����
// CURRENT = Min ������
// MAX     = Max ������
// BASIC   = �����ۿ� ���� ��ȭ ��ġ
//////////////////////////////////////////////////////////////////////////////
void Slayer::computeStatOffset(void) throw()
{
	__BEGIN_TRY

	Creature::CreatureClass CClass = getCreatureClass();
	BASIC_ATTR              cur_attr;

	cur_attr.nSTR    = m_STR[ATTR_CURRENT];
	cur_attr.nDEX    = m_DEX[ATTR_CURRENT];
	cur_attr.nINT    = m_INT[ATTR_CURRENT];
	cur_attr.pWeapon = m_pWearItem[WEAR_RIGHTHAND];

	for (int i=0; i<SKILL_DOMAIN_MAX; i++)
		cur_attr.pDomainLevel[i] = m_SkillDomainLevels[i];

	// ���ο��� STR, DEX, INT�� ���� ����� �� ���
	// ������ �Ǵ� ���� ��ġ�� ���Ѵ�.
	m_HP[ATTR_MAX] = computeHP(CClass, &cur_attr);
	m_HP[ATTR_MAX] += m_HP[ATTR_BASIC]; 

	m_MP[ATTR_MAX] = computeMP(CClass, &cur_attr);
	m_MP[ATTR_MAX] += m_MP[ATTR_BASIC]; 

	m_ToHit[ATTR_CURRENT] = computeToHit(CClass, &cur_attr);
	m_ToHit[ATTR_CURRENT] += m_ToHit[ATTR_MAX];

	m_Defense[ATTR_CURRENT] = computeDefense(CClass, &cur_attr);
	m_Defense[ATTR_CURRENT] += m_Defense[ATTR_MAX];

	m_Protection[ATTR_CURRENT] = computeProtection(CClass, &cur_attr);
	m_Protection[ATTR_CURRENT] += m_Protection[ATTR_MAX];

	m_Damage[ATTR_CURRENT] = computeMinDamage(CClass, &cur_attr);
	m_Damage[ATTR_MAX]     = computeMaxDamage(CClass, &cur_attr);

	m_Damage[ATTR_CURRENT] += m_Damage[ATTR_BASIC];
	m_Damage[ATTR_MAX] += m_Damage[ATTR_BASIC];

	m_AttackSpeed[ATTR_CURRENT] = computeAttackSpeed(CClass, &cur_attr);
	m_AttackSpeed[ATTR_CURRENT] += m_AttackSpeed[ATTR_MAX];

	m_CriticalRatio[ATTR_CURRENT] = computeCriticalRatio(CClass, &cur_attr);
	m_CriticalRatio[ATTR_CURRENT] += m_CriticalRatio[ATTR_MAX];

	__END_CATCH
}

void Slayer::computeItemStat(Item* pItem) throw()
{
	__BEGIN_TRY

	if (isSlayerWeapon(pItem->getItemClass()))
	{
		// �������� ���Ⱑ ������ �ӵ� �Ķ����͸� ���Ѵ�.
		ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo(pItem->getItemClass(), pItem->getItemType());
		m_AttackSpeed[ATTR_CURRENT] += pItemInfo->getSpeed();
		m_AttackSpeed[ATTR_MAX]     += pItemInfo->getSpeed();
	}

	m_Protection[ATTR_CURRENT] += pItem->getProtectionBonus();
	m_Protection[ATTR_MAX]     += pItem->getProtectionBonus();

	m_Defense[ATTR_CURRENT] += pItem->getDefenseBonus();
	m_Defense[ATTR_MAX]     += pItem->getDefenseBonus();

	m_ToHit[ATTR_CURRENT]   += pItem->getToHitBonus();
	m_ToHit[ATTR_MAX]       += pItem->getToHitBonus();

	m_MP[ATTR_MAX]          += pItem->getMPBonus();
	m_MP[ATTR_BASIC]        += pItem->getMPBonus();

	m_Luck					+= pItem->getLuck();

	// �ΰ����� �ɼǵ�
	const list<OptionType_t>& optionType = pItem->getOptionTypeList();
	list<OptionType_t>::const_iterator itr;
	for (itr=optionType.begin(); itr!=optionType.end(); itr++)
	{
		computeOptionStat( *itr );
	}

	// Item ��ü�� defaultOption� ������Ų��.
	const list<OptionType_t>& defaultOptions = pItem->getDefaultOptions();
	list<OptionType_t>::const_iterator iOptions;

	for (iOptions=defaultOptions.begin(); iOptions!=defaultOptions.end(); iOptions++)
	{
		computeOptionStat( *iOptions );
	}


	__END_CATCH
}

void Slayer::computeOptionStat(Item* pItem) throw()
{
	__BEGIN_TRY

	// Option Type� �޾ƿ´�.
//	OptionType_t  OptionType    = pItem->getOptionType();
//	computeOptionStat( OptionType );

	// �ΰ����� �ɼǵ�
	const list<OptionType_t>& optionType = pItem->getOptionTypeList();
	list<OptionType_t>::const_iterator itr;
	for (itr=optionType.begin(); itr!=optionType.end(); itr++)
	{
		computeOptionStat( *itr );
	}

	// Item ��ü�� defaultOption� ������Ų��.
	const list<OptionType_t>& defaultOptions = pItem->getDefaultOptions();
	list<OptionType_t>::const_iterator iOptions;

	for (iOptions=defaultOptions.begin(); iOptions!=defaultOptions.end(); iOptions++)
	{
		computeOptionStat( *iOptions );
	}



	__END_CATCH
}

void Slayer::computeOptionClassStat( OptionClass OClass, int PlusPoint )
{
	switch (OClass) 
	{
		case OPTION_STR:
			m_STR[ATTR_CURRENT] += PlusPoint;
			m_STR[ATTR_MAX]     += PlusPoint;
			computeStatOffset();
			break;
		case OPTION_DEX:
			m_DEX[ATTR_CURRENT] += PlusPoint;
			m_DEX[ATTR_MAX]     += PlusPoint;
			computeStatOffset();
			break;
		case OPTION_INT:
			m_INT[ATTR_CURRENT] += PlusPoint;
			m_INT[ATTR_MAX]     += PlusPoint;
			computeStatOffset();
			break;
		case OPTION_HP:
			m_HP[ATTR_MAX]   += PlusPoint;
			m_HP[ATTR_BASIC] += PlusPoint;
			break;
		case OPTION_MP:
			m_MP[ATTR_MAX]   += PlusPoint;
			m_MP[ATTR_BASIC] += PlusPoint;
			break;
		case OPTION_HP_STEAL:
			m_HPStealAmount += PlusPoint;
			break;
		case OPTION_MP_STEAL:
			m_MPStealAmount += PlusPoint;
			break;
		case OPTION_HP_REGEN:
			m_HPRegen += PlusPoint;
			break;
		case OPTION_MP_REGEN:
			m_MPRegen += PlusPoint;
			break;
		case OPTION_TOHIT:
			m_ToHit[ATTR_CURRENT] += PlusPoint;
			m_ToHit[ATTR_MAX]     += PlusPoint;
			break;
		case OPTION_DEFENSE:
			m_Defense[ATTR_CURRENT] += PlusPoint;
			m_Defense[ATTR_MAX]     += PlusPoint;
			break;
		case OPTION_DAMAGE:
			m_Damage[ATTR_CURRENT] += PlusPoint;
			m_Damage[ATTR_MAX]     += PlusPoint;
			m_Damage[ATTR_BASIC]   += PlusPoint;
			break;
		case OPTION_PROTECTION:
			m_Protection[ATTR_CURRENT] += PlusPoint;
			m_Protection[ATTR_MAX]     += PlusPoint;
			break;
		case OPTION_ATTACK_SPEED:
			m_AttackSpeed[ATTR_CURRENT] += PlusPoint;
			m_AttackSpeed[ATTR_MAX]     += PlusPoint;
			break;
		case OPTION_POISON:
			m_Resist[MAGIC_DOMAIN_POISON] += PlusPoint;
			break;
		case OPTION_ACID:
			m_Resist[MAGIC_DOMAIN_ACID] += PlusPoint;
			break;
		case OPTION_CURSE:
			m_Resist[MAGIC_DOMAIN_CURSE] += PlusPoint;
			break;
		case OPTION_BLOOD:
			m_Resist[MAGIC_DOMAIN_BLOOD] += PlusPoint;
			break;
		case OPTION_VISION:
			break;
		case OPTION_CRITICAL_HIT:
			m_CriticalRatio[ATTR_CURRENT] += PlusPoint;
			m_CriticalRatio[ATTR_MAX]     += PlusPoint;
			break;

		case OPTION_ALL_ATTR:
			m_STR[ATTR_CURRENT] += PlusPoint;
			m_STR[ATTR_MAX]     += PlusPoint;

			m_DEX[ATTR_CURRENT] += PlusPoint;
			m_DEX[ATTR_MAX]     += PlusPoint;

			m_INT[ATTR_CURRENT] += PlusPoint;
			m_INT[ATTR_MAX]     += PlusPoint;

			computeStatOffset();
			break;

		case OPTION_ALL_RES:
			m_Resist[MAGIC_DOMAIN_POISON] += PlusPoint;
			m_Resist[MAGIC_DOMAIN_ACID] += PlusPoint;
			m_Resist[MAGIC_DOMAIN_CURSE] += PlusPoint;
			m_Resist[MAGIC_DOMAIN_BLOOD] += PlusPoint;
			break;

		case OPTION_LUCK:
			m_Luck += PlusPoint;
		break;

		case OPTION_STR_TO_DEX:
		{
			int trans = getPercentValue( m_STR[ATTR_BASIC], PlusPoint );
			m_STR[ATTR_CURRENT]	-= trans;
			m_STR[ATTR_MAX]		-= trans;
			m_DEX[ATTR_CURRENT]	+= trans;
			m_DEX[ATTR_MAX]		+= trans;

			computeStatOffset();
			break;
		}

		case OPTION_STR_TO_INT:
		{
			int trans = getPercentValue( m_STR[ATTR_BASIC], PlusPoint );
			m_STR[ATTR_CURRENT]	-= trans;
			m_STR[ATTR_MAX]		-= trans;
			m_INT[ATTR_CURRENT] += trans;
			m_INT[ATTR_MAX]		+= trans;

			computeStatOffset();
			break;
		}

		case OPTION_DEX_TO_STR:
		{
			int trans = getPercentValue( m_DEX[ATTR_BASIC], PlusPoint );
			m_DEX[ATTR_CURRENT]	-= trans;
			m_DEX[ATTR_MAX]		-= trans;
			m_STR[ATTR_CURRENT] += trans;
			m_STR[ATTR_MAX]		+= trans;

			computeStatOffset();
			break;
		}

		case OPTION_DEX_TO_INT:
		{
			int trans = getPercentValue( m_DEX[ATTR_BASIC], PlusPoint );
			m_DEX[ATTR_CURRENT]	-= trans;
			m_DEX[ATTR_MAX]		-= trans;
			m_INT[ATTR_CURRENT] += trans;
			m_INT[ATTR_MAX]		+= trans;

			computeStatOffset();
			break;
		}

		case OPTION_INT_TO_STR:
		{
			int trans = getPercentValue( m_INT[ATTR_BASIC], PlusPoint );
			m_INT[ATTR_CURRENT]	-= trans;
			m_INT[ATTR_MAX]		-= trans;
			m_STR[ATTR_CURRENT] += trans;
			m_STR[ATTR_MAX]		+= trans;

			computeStatOffset();
			break;
		}

		case OPTION_INT_TO_DEX:
		{
			int trans = getPercentValue( m_INT[ATTR_BASIC], PlusPoint );
			m_INT[ATTR_CURRENT]	-= trans;
			m_INT[ATTR_MAX]		-= trans;
			m_DEX[ATTR_CURRENT] += trans;
			m_DEX[ATTR_MAX]		+= trans;

			computeStatOffset();
			break;
		}
		case OPTION_CONSUME_MP:
		{
			m_ConsumeMPRatio = PlusPoint;
			break;
		}
		case OPTION_MAGIC_DAMAGE:
		{
			m_MagicBonusDamage = PlusPoint;
			break;
		}
		case OPTION_PHYSIC_DAMAGE:
		{
			m_PhysicBonusDamage = PlusPoint;
			break;
		}
		case OPTION_GAMBLE_PRICE:
		{
			m_GamblePriceRatio = PlusPoint;
			break;
		}
		case OPTION_POTION_PRICE:
		{
			m_PotionPriceRatio = PlusPoint;
			break;
		}

		default:
			break;
	}

}

void Slayer::computeOptionStat(OptionType_t optionType) throw()
{
	__BEGIN_TRY

	OptionInfo*   pOptionInfo   = g_pOptionInfoManager->getOptionInfo(optionType);
	computeOptionClassStat( pOptionInfo->getClass(), pOptionInfo->getPlusPoint() );
//	OptionClass   OClass        = pOptionInfo->getClass();

/*	switch (OClass) 
	{
		case OPTION_STR:
			m_STR[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_STR[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			computeStatOffset();
			break;
		case OPTION_DEX:
			m_DEX[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_DEX[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			computeStatOffset();
			break;
		case OPTION_INT:
			m_INT[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_INT[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			computeStatOffset();
			break;
		case OPTION_HP:
			m_HP[ATTR_MAX]   += pOptionInfo->getPlusPoint();
			m_HP[ATTR_BASIC] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_MP:
			m_MP[ATTR_MAX]   += pOptionInfo->getPlusPoint();
			m_MP[ATTR_BASIC] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_HP_STEAL:
			m_HPStealAmount += pOptionInfo->getPlusPoint();
			break;
		case OPTION_MP_STEAL:
			m_MPStealAmount += pOptionInfo->getPlusPoint();
			break;
		case OPTION_HP_REGEN:
			m_HPRegen += pOptionInfo->getPlusPoint();
			break;
		case OPTION_MP_REGEN:
			m_MPRegen += pOptionInfo->getPlusPoint();
			break;
		case OPTION_TOHIT:
			m_ToHit[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_ToHit[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;
		case OPTION_DEFENSE:
			m_Defense[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_Defense[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;
		case OPTION_DAMAGE:
			m_Damage[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_Damage[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			m_Damage[ATTR_BASIC]   += pOptionInfo->getPlusPoint();
			break;
		case OPTION_PROTECTION:
			m_Protection[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_Protection[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;
		case OPTION_ATTACK_SPEED:
			m_AttackSpeed[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_AttackSpeed[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;
		case OPTION_POISON:
			m_Resist[MAGIC_DOMAIN_POISON] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_ACID:
			m_Resist[MAGIC_DOMAIN_ACID] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_CURSE:
			m_Resist[MAGIC_DOMAIN_CURSE] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_BLOOD:
			m_Resist[MAGIC_DOMAIN_BLOOD] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_VISION:
			break;
		case OPTION_CRITICAL_HIT:
			m_CriticalRatio[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_CriticalRatio[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;

		case OPTION_ALL_ATTR:
			m_STR[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_STR[ATTR_MAX]     += pOptionInfo->getPlusPoint();

			m_DEX[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_DEX[ATTR_MAX]     += pOptionInfo->getPlusPoint();

			m_INT[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_INT[ATTR_MAX]     += pOptionInfo->getPlusPoint();

			computeStatOffset();
			break;

		case OPTION_ALL_RES:
			m_Resist[MAGIC_DOMAIN_POISON] += pOptionInfo->getPlusPoint();
			m_Resist[MAGIC_DOMAIN_ACID] += pOptionInfo->getPlusPoint();
			m_Resist[MAGIC_DOMAIN_CURSE] += pOptionInfo->getPlusPoint();
			m_Resist[MAGIC_DOMAIN_BLOOD] += pOptionInfo->getPlusPoint();
			break;

		case OPTION_LUCK:
			m_Luck += pOptionInfo->getPlusPoint();
		break;

		case OPTION_STR_TO_DEX:
		{
			int trans = getPercentValue( m_STR[ATTR_BASIC], pOptionInfo->getPlusPoint() );
			m_STR[ATTR_CURRENT]	-= trans;
			m_STR[ATTR_MAX]		-= trans;
			m_DEX[ATTR_CURRENT]	+= trans;
			m_DEX[ATTR_MAX]		+= trans;

			computeStatOffset();
			break;
		}

		case OPTION_STR_TO_INT:
		{
			int trans = getPercentValue( m_STR[ATTR_BASIC], pOptionInfo->getPlusPoint() );
			m_STR[ATTR_CURRENT]	-= trans;
			m_STR[ATTR_MAX]		-= trans;
			m_INT[ATTR_CURRENT] += trans;
			m_INT[ATTR_MAX]		+= trans;

			computeStatOffset();
			break;
		}

		case OPTION_DEX_TO_STR:
		{
			int trans = getPercentValue( m_DEX[ATTR_BASIC], pOptionInfo->getPlusPoint() );
			m_DEX[ATTR_CURRENT]	-= trans;
			m_DEX[ATTR_MAX]		-= trans;
			m_STR[ATTR_CURRENT] += trans;
			m_STR[ATTR_MAX]		+= trans;

			computeStatOffset();
			break;
		}

		case OPTION_DEX_TO_INT:
		{
			int trans = getPercentValue( m_DEX[ATTR_BASIC], pOptionInfo->getPlusPoint() );
			m_DEX[ATTR_CURRENT]	-= trans;
			m_DEX[ATTR_MAX]		-= trans;
			m_INT[ATTR_CURRENT] += trans;
			m_INT[ATTR_MAX]		+= trans;

			computeStatOffset();
			break;
		}

		case OPTION_INT_TO_STR:
		{
			int trans = getPercentValue( m_INT[ATTR_BASIC], pOptionInfo->getPlusPoint() );
			m_INT[ATTR_CURRENT]	-= trans;
			m_INT[ATTR_MAX]		-= trans;
			m_STR[ATTR_CURRENT] += trans;
			m_STR[ATTR_MAX]		+= trans;

			computeStatOffset();
			break;
		}

		case OPTION_INT_TO_DEX:
		{
			int trans = getPercentValue( m_INT[ATTR_BASIC], pOptionInfo->getPlusPoint() );
			m_INT[ATTR_CURRENT]	-= trans;
			m_INT[ATTR_MAX]		-= trans;
			m_DEX[ATTR_CURRENT] += trans;
			m_DEX[ATTR_MAX]		+= trans;

			computeStatOffset();
			break;
		}
		case OPTION_CONSUME_MP:
		{
			m_ConsumeMPRatio = pOptionInfo->getPlusPoint();
			break;
		}
		case OPTION_MAGIC_DAMAGE:
		{
			m_MagicBonusDamage = pOptionInfo->getPlusPoint();
			break;
		}
		case OPTION_PHYSIC_DAMAGE:
		{
			m_PhysicBonusDamage = pOptionInfo->getPlusPoint();
			break;
		}
		case OPTION_GAMBLE_PRICE:
		{
			m_GamblePriceRatio = pOptionInfo->getPlusPoint();
			break;
		}
		case OPTION_POTION_PRICE:
		{
			m_PotionPriceRatio = pOptionInfo->getPlusPoint();
			break;
		}

		default:
			break;
	}*/

	__END_CATCH
}

void Slayer::addModifyInfo(const SLAYER_RECORD& prev, ModifyInfo& pkt) const
	throw()
{
	__BEGIN_TRY

	if (prev.pSTR[ATTR_CURRENT] != m_STR[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_STR, m_STR[ATTR_CURRENT]);
	if (prev.pSTR[ATTR_MAX    ] != m_STR[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_STR,     m_STR[ATTR_MAX]);
	if (prev.pSTR[ATTR_BASIC  ] != m_STR[ATTR_BASIC  ]) pkt.addShortData(MODIFY_BASIC_STR,   m_STR[ATTR_BASIC]);

	if (prev.pDEX[ATTR_CURRENT] != m_DEX[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_DEX, m_DEX[ATTR_CURRENT]);
	if (prev.pDEX[ATTR_MAX    ] != m_DEX[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_DEX,     m_DEX[ATTR_MAX]);
	if (prev.pDEX[ATTR_BASIC  ] != m_DEX[ATTR_BASIC  ]) pkt.addShortData(MODIFY_BASIC_DEX,   m_DEX[ATTR_BASIC]);

	if (prev.pINT[ATTR_CURRENT] != m_INT[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_INT, m_INT[ATTR_CURRENT]);
	if (prev.pINT[ATTR_MAX    ] != m_INT[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_INT,     m_INT[ATTR_MAX]);
	if (prev.pINT[ATTR_BASIC  ] != m_INT[ATTR_BASIC  ]) pkt.addShortData(MODIFY_BASIC_INT,   m_INT[ATTR_BASIC]);

	if (prev.pHP[ATTR_CURRENT] != m_HP[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_HP, m_HP[ATTR_CURRENT]);
	if (prev.pHP[ATTR_MAX    ] != m_HP[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_HP,     m_HP[ATTR_MAX]);

	if (prev.pMP[ATTR_CURRENT] != m_MP[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_MP, m_MP[ATTR_CURRENT]);
	if (prev.pMP[ATTR_MAX    ] != m_MP[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_MP,     m_MP[ATTR_MAX]);

	if (prev.pDamage[ATTR_CURRENT] != m_Damage[ATTR_CURRENT]) pkt.addShortData(MODIFY_MIN_DAMAGE, m_Damage[ATTR_CURRENT]);
	if (prev.pDamage[ATTR_MAX    ] != m_Damage[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_DAMAGE, m_Damage[ATTR_MAX]);

	if (prev.Defense     != m_Defense[ATTR_CURRENT])     pkt.addShortData(MODIFY_DEFENSE,      m_Defense[ATTR_CURRENT]);
	if (prev.Protection  != m_Protection[ATTR_CURRENT])  pkt.addShortData(MODIFY_PROTECTION,   m_Protection[ATTR_CURRENT]);
	if (prev.ToHit       != m_ToHit[ATTR_CURRENT])       pkt.addShortData(MODIFY_TOHIT,        m_ToHit[ATTR_CURRENT]);
	if (prev.AttackSpeed != m_AttackSpeed[ATTR_CURRENT]) pkt.addShortData(MODIFY_ATTACK_SPEED, m_AttackSpeed[ATTR_CURRENT]);

	// by sigi. 2002.9.10
	if (prev.Rank != getRank())
	{
		pkt.addShortData(MODIFY_RANK, getRank());
		pkt.addLongData(MODIFY_RANK_EXP, getRankGoalExp());
	}

	__END_CATCH
}

void Slayer::sendModifyInfo(const SLAYER_RECORD& prev) const
	throw()
{
	__BEGIN_TRY

	GCModifyInformation gcModifyInformation;
	addModifyInfo(prev, gcModifyInformation);
	m_pPlayer->sendPacket(&gcModifyInformation);

	__END_CATCH
}

void Slayer::initAllStatAndSend()
{
	SLAYER_RECORD prev;
	getSlayerRecord(prev);
	initAllStat();
	sendModifyInfo(prev);
}

//////////////////////////////////////////////////////////////////////////////
// 
// �����̾�
//
//////////////////////////////////////////////////////////////////////////////

void Vampire::initCastleSkill() throw()
{
	__BEGIN_TRY

	removeAllCastleSkill();

	if ( !getZone()->isHolyLand() ) return;

	list<CastleInfo*> pCastleInfoList = g_pCastleInfoManager->getGuildCastleInfos( getGuildID() );
	if ( pCastleInfoList.empty() ) return;

	list<CastleInfo*>::iterator itr = pCastleInfoList.begin();

	for ( ; itr != pCastleInfoList.end() ; itr++ )
	{
		SkillType_t CastleSkillType = g_pCastleInfoManager->getCastleSkillType( (*itr)->getZoneID(), getGuildID() );
		if ( CastleSkillType == SKILL_MAX ) 
			continue;

		SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo(CastleSkillType);
		Assert( pSkillInfo != NULL );

		Turn_t Delay = pSkillInfo->getMaxDelay();

		VampireCastleSkillSlot* pCastleSkillSlot = new VampireCastleSkillSlot();

		pCastleSkillSlot->setName( m_Name );
		pCastleSkillSlot->setSkillType( CastleSkillType );
		pCastleSkillSlot->setInterval(Delay);
		pCastleSkillSlot->setRunTime();

		addSkill( pCastleSkillSlot );
	}

	__END_CATCH
}

void Vampire::initAllStat(int numPartyMember)
	throw()
{
	__BEGIN_TRY

	BASIC_ATTR attr;
	Creature::CreatureClass CClass = getCreatureClass();

	m_Resist[MAGIC_DOMAIN_NO_DOMAIN] = 0;
	m_Resist[MAGIC_DOMAIN_POISON]    = 50;
	m_Resist[MAGIC_DOMAIN_ACID]      = 0;
	m_Resist[MAGIC_DOMAIN_CURSE]     = 0;
	m_Resist[MAGIC_DOMAIN_BLOOD]     = 0;

	// BloodBible ���� ���ʽ� ��ġ�� �ʱ�ȭ
	m_ConsumeMPRatio	= 0;
	m_GamblePriceRatio	= 0;
	m_PotionPriceRatio	= 0;
	m_MagicBonusDamage	= 0;
	m_PhysicBonusDamage	= 0;

	//////////////////////////////////////////////////////////////////////////////
	// ��� ���� �⺻ �ɷ�ġ�� �ʱ�ȭ��Ű��, 
	// �⺻ �ɷ�ġ�� ����� �ִ� ����Ʈ�� �˻��Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	m_STR[ATTR_CURRENT] = m_STR[ATTR_MAX] = m_STR[ATTR_BASIC];
	m_DEX[ATTR_CURRENT] = m_DEX[ATTR_MAX] = m_DEX[ATTR_BASIC];
	m_INT[ATTR_CURRENT] = m_INT[ATTR_MAX] = m_INT[ATTR_BASIC];

	//////////////////////////////////////////////////////////////////////////////
	// �ɷ�ġ ����� ��� �Ķ����͵�� �ʱ�ȭ�Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	attr.nSTR    = m_STR[ATTR_CURRENT];
	attr.nDEX    = m_DEX[ATTR_CURRENT];
	attr.nINT    = m_INT[ATTR_CURRENT];
	attr.pWeapon = NULL;
	attr.nLevel  = m_Level;
	
	m_HPStealRatio  = 0;
	m_HPStealAmount = 0;
	m_HPRegen       = 0;
	m_Luck			= 0;
	m_HPRegenBonus	= 0;

	////////////////////////////////////////////////////////////
	// �ΰ����� �ɷ�ġ��� �ٽ� �����Ѵ�.
	////////////////////////////////////////////////////////////
	m_HP[ATTR_MAX]                = computeHP(CClass, &attr);
	m_HP[ATTR_BASIC]              = 0;
	m_ToHit[ATTR_CURRENT]         = computeToHit(CClass, &attr);
	m_ToHit[ATTR_MAX]             = 0;
	m_Defense[ATTR_CURRENT]       = computeDefense(CClass, &attr);
	m_Defense[ATTR_MAX]           = 0;
	m_Protection[ATTR_CURRENT]    = computeProtection(CClass, &attr);
	m_Protection[ATTR_MAX]        = 0;
	m_Damage[ATTR_CURRENT]        = computeMinDamage(CClass, &attr);
	m_Damage[ATTR_MAX]            = computeMaxDamage(CClass, &attr);
	m_Damage[ATTR_BASIC]          = 0;
	m_AttackSpeed[ATTR_CURRENT]   = computeAttackSpeed(CClass, &attr);
	m_AttackSpeed[ATTR_MAX]       = 0;
	m_CriticalRatio[ATTR_CURRENT] = computeCriticalRatio(CClass, &attr);
	m_CriticalRatio[ATTR_MAX]     = 0;

	int RaceWarHPBonus = 0;

	if ( m_pZone->isHolyLand() || m_pZone->isLevelWarZone() )
	{
		RaceWarHPBonus = getPercentValue( m_HP[ATTR_MAX], g_pVariableManager->getRaceWarHPBonus() );
	}

	// ���� ���ʽ�
	// ����� ���� ���п� �������� �������̵� ���ʽ��� ������ �� �ִ�. by sigi
	//if ( g_pCombatInfoManager->isVampireBonus() )
	int HPBonus = 0;
	{
		int bonusRatio = g_pVariableManager->getCombatVampireHPBonusRatio();
		//g_pCombatInfoManager->getVampireHPModify();

		if (bonusRatio > 0)
		{
			HPBonus = getPercentValue( m_HP[ATTR_MAX], bonusRatio );
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// �ϴ� ���� üũ ������ �ʱ�ȭ�ؼ� ���� ��� �� ��� ����� �����ϰ� �����Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	bool pOldRealWearingCheck[VAMPIRE_WEAR_MAX];	// by sigi. 2002.10.31
	for (int i=0; i<VAMPIRE_WEAR_MAX; i++) 
	{
		pOldRealWearingCheck[i] = m_pRealWearingCheck[i];
		m_pRealWearingCheck[i] = false;
	}

	//////////////////////////////////////////////////////////////////////////////
	// ��� ����� ��� ���ʽ� �ɼ�� �ް� �ȴ�
	//////////////////////////////////////////////////////////////////////////////
	// Blood Bible ������ ���ʽ� �ɼ�� �޴� �ɷ� ���ƴ�.
/*	if (m_pZone->isHolyLand() )
	{
		const list<OptionType_t>& optionType = g_pHolyLandRaceBonus->getVampireOptionTypeList();
		list<OptionType_t>::const_iterator itr;
		for (itr=optionType.begin(); itr!=optionType.end(); itr++)
		{
			computeOptionStat( *itr );
		}
	}
*/
	//////////////////////////////////////////////////////////////////////////////
	// Blood Bilbe ������ ���ʽ� �ɼ�� �޴´�.
	//////////////////////////////////////////////////////////////////////////////
	if ( m_pZone->isHolyLand() && !g_pWarSystem->hasActiveRaceWar() )
	{
		const BloodBibleBonusHashMap& bloodBibleBonus = g_pBloodBibleBonusManager->getBloodBibleBonuses();
		BloodBibleBonusHashMapConstItor itr;
		for (itr=bloodBibleBonus.begin(); itr!=bloodBibleBonus.end(); itr++)
		{
			if ( itr->second->getRace() == RACE_VAMPIRE )
			{
				OptionTypeList optionTypes = itr->second->getOptionTypeList();
				OptionTypeListConstItor optionItr;
				
				for ( optionItr = optionTypes.begin(); optionItr != optionTypes.end(); optionItr++ )
				{
					computeOptionStat( *optionItr );
				}
			}
		}
	}

	if ( g_pSweeperBonusManager->isAble( getZoneID() ) && g_pLevelWarZoneInfoManager->isCreatureBonusZone( this, getZoneID() ))
	{
		const SweeperBonusHashMap& sweeperBonuses = g_pSweeperBonusManager->getSweeperBonuses();

		SweeperBonusHashMapConstItor itr = sweeperBonuses.begin();
		SweeperBonusHashMapConstItor endItr = sweeperBonuses.end();

		for (; itr!=endItr; itr++)
		{
			if ( itr->second->getRace() == RACE_VAMPIRE && itr->second->getLevel() == g_pLevelWarZoneInfoManager->getCreatureLevelGrade( this ) )
			{
				OptionTypeList optionTypes = itr->second->getOptionTypeList();
				OptionTypeListConstItor optionItr;
				
				for ( optionItr = optionTypes.begin(); optionItr != optionTypes.end(); optionItr++ )
				{
					computeOptionStat( *optionItr );
				}
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// �⺻����� ������ �ִ� �ɼǵ�� �����Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	list<DefaultOptionSetType_t>::iterator itr = m_DefaultOptionSet.begin();
	for ( ; itr != m_DefaultOptionSet.end(); itr++ )
	{
		DefaultOptionSetInfo* pDefaultOptionSetInfo = g_pDefaultOptionSetInfoManager->getDefaultOptionSetInfo( (*itr) );
		if ( pDefaultOptionSetInfo != NULL )
		{
			const list<OptionType_t>& optionList = pDefaultOptionSetInfo->getOptionTypeList();
			list<OptionType_t>::const_iterator citr;
			for ( citr = optionList.begin(); citr != optionList.end(); citr++ )
			{
				computeOptionStat( *citr );
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// ���� �ִ� ���ʽ��� �����Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	if ( m_pPetInfo != NULL )
	{
		if ( m_pPetInfo->getPetAttr() != 0xff ) computeOptionClassStat( (OptionClass)m_pPetInfo->getPetAttr(), (int)m_pPetInfo->getPetAttrLevel() );
		if ( m_pPetInfo->getPetOption() != 0 ) computeOptionStat( m_pPetInfo->getPetOption() );
	}

	//////////////////////////////////////////////////////////////////////////////
	// for �� �ι��� ����� ��������� �ö��� �ɷ�ġ�� ���ؼ�
	// ��� �� �ְ� �Ǵ� ������� üũ�ϱ� ��ؼ��̴�.
	//////////////////////////////////////////////////////////////////////////////
	for (int j=0; j<VAMPIRE_WEAR_MAX; j++)
	{
		int wearCount = 0;
		for (int i=0; i<VAMPIRE_WEAR_MAX; i++)
		{
			Item* pItem = m_pWearItem[i];
			// ���� ����Ʈ�� �������� �ְ�
			// �װͿ� ���� üũ�� ���� ���� �ʾҴٸ�...
			if (pItem != NULL && m_pRealWearingCheck[i] == false)
			{
				// ���� ��¥�� ��� �� �ִ� �������̶��� �ɷ�ġ�� �÷��ش�.
				if (isRealWearing(pItem))
				{
					computeItemStat(pItem);

					// ���� ��������, üũ�� �ι� ���� �ʵ���
					// ����, ����� ���� üũ ������ ����
					if (isTwohandWeapon(pItem))
					{
						m_pRealWearingCheck[WEAR_LEFTHAND] = true;
						m_pRealWearingCheck[WEAR_RIGHTHAND] = true;
					}
					else m_pRealWearingCheck[i] = true;

					wearCount ++;
				}
			}
		}

		if (wearCount==0)	// by sigi. 2002.10.30
			break;
	}

	// by sigi. 2002.11.6
	bool bSendPacket = false;

	if (m_pPlayer!=NULL)
	{	
		bSendPacket = (dynamic_cast<GamePlayer*>(m_pPlayer)->getPlayerStatus()==GPS_NORMAL);
	}

	// �ϴ� ����� �� �Ծ��µ�..
	// �ɷ�ġ�� ������ ������ ������ �ȵǴ� ������� ���� ����� ���ش�.
	// by sigi. 2002.10.30
	//for (int i=0; i<VAMPIRE_WEAR_MAX; i++)
	int i=WEAR_BODY;
	{
		if (m_pRealWearingCheck[i])
		{
			// by sigi. 2002.10.31
			if (pOldRealWearingCheck[i]==false)
			{
				Item* pItem = m_pWearItem[i];
				if (pItem!=NULL)
				{
					Item::ItemClass IClass = pItem->getItemClass();
					ItemType_t		IType  = pItem->getItemType();

					Color_t color = getItemShapeColor( pItem );
					addShape(IClass, IType, color);

					if (bSendPacket)
					{
						GCChangeShape pkt;
						pkt.setObjectID(getObjectID());
						pkt.setItemClass(IClass);
						pkt.setItemType(IType);
						pkt.setOptionType(pItem->getFirstOptionType());
						pkt.setAttackSpeed(m_AttackSpeed[ATTR_CURRENT]);

						m_pZone->broadcastPacket(m_X, m_Y , &pkt, this);
					}
				}
			}
		}
		else
		{
			Item* pItem = m_pWearItem[i];
			if (pItem!=NULL)
			{
				removeShape(pItem->getItemClass(), bSendPacket);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// HP, MP ��ƿ Ȯ��� ������ �д�.
	//////////////////////////////////////////////////////////////////////////////
	m_HPStealRatio = computeStealRatio(CClass, m_HPStealAmount, &attr);

	//////////////////////////////////////////////////////////////////////////////
	// �ΰ����� �ɷ�ġ�� ��� ����ϴ� ����Ʈ�� �˻��Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	if (isFlag(Effect::EFFECT_CLASS_DOOM))
	{
		EffectDoom* pDoom = dynamic_cast<EffectDoom*>(findEffect(Effect::EFFECT_CLASS_DOOM));
		if (pDoom!= NULL)
		{
			int DefensePenalty    = getPercentValue(m_Defense[ATTR_CURRENT],    pDoom->getDefensePenalty());
			int ProtectionPenalty = getPercentValue(m_Protection[ATTR_CURRENT], pDoom->getProtectionPenalty());

			m_Defense[ATTR_CURRENT]    = max(0, m_Defense[ATTR_CURRENT]    - DefensePenalty);
			m_Protection[ATTR_CURRENT] = max(0, m_Protection[ATTR_CURRENT] - ProtectionPenalty);
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_SEDUCTION))
	{
		EffectSeduction* pSeduction = dynamic_cast<EffectSeduction*>(findEffect(Effect::EFFECT_CLASS_SEDUCTION));
		if (pSeduction!= NULL)
		{
			int ToHitPenalty   = getPercentValue(m_ToHit[ATTR_CURRENT],  pSeduction->getToHitPenalty());
			int DamagePenalty1 = getPercentValue(m_Damage[ATTR_CURRENT], pSeduction->getDamagePenalty());
			int DamagePenalty2 = getPercentValue(m_Damage[ATTR_MAX],     pSeduction->getDamagePenalty());

			m_ToHit[ATTR_CURRENT]  = max(0, m_ToHit[ATTR_CURRENT]  - ToHitPenalty);
			m_Damage[ATTR_CURRENT] = max(0, m_Damage[ATTR_CURRENT] - DamagePenalty1);
			m_Damage[ATTR_MAX]     = max(0, m_Damage[ATTR_MAX]     - DamagePenalty2);
		}
	}
/*	if (isFlag(Effect::EFFECT_CLASS_PARALYZE))
	{
		EffectParalyze* pParalyze = dynamic_cast<EffectParalyze*>(findEffect(Effect::EFFECT_CLASS_PARALYZE));
		if (pParalyze != NULL)
		{
			int DefensePenalty = getPercentValue(m_Defense[ATTR_CURRENT], pParalyze->getDefensePenalty());
			m_Defense[ATTR_CURRENT] = max(0, m_Defense[ATTR_CURRENT] - DefensePenalty);
		}
	}*/
	if (isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_WOLF))
	{
		EffectTransformToWolf* pTransformToWolf= dynamic_cast<EffectTransformToWolf*>(findEffect(Effect::EFFECT_CLASS_TRANSFORM_TO_WOLF));
		if (pTransformToWolf != NULL)
		{
			int PenaltyRatio	  = (isFlag(Effect::EFFECT_CLASS_HOWL))?10:30;
			int ToHitBonus        = getPercentValue(m_ToHit[ATTR_CURRENT], 20);
			int MinDamageBonus    = m_DEX[ATTR_CURRENT]/8 + m_STR[ATTR_CURRENT]/30;//getPercentValue(m_Damage[ATTR_CURRENT], 20);
			int MaxDamageBonus    = m_DEX[ATTR_CURRENT]/8 + m_STR[ATTR_CURRENT]/30;//getPercentValue(m_Damage[ATTR_MAX], 20);
			int DefensePenalty    = getPercentValue(m_Defense[ATTR_CURRENT], PenaltyRatio);//50);
			int ProtectionPenalty = getPercentValue(m_Protection[ATTR_CURRENT], PenaltyRatio);//50);

			m_ToHit[ATTR_CURRENT]      = min(VAMPIRE_MAX_TOHIT, m_ToHit[ATTR_CURRENT] + ToHitBonus);
			m_Damage[ATTR_CURRENT]     = min(VAMPIRE_MAX_DAMAGE, m_Damage[ATTR_CURRENT] + MinDamageBonus);
			m_Damage[ATTR_MAX]         = min(VAMPIRE_MAX_DAMAGE, m_Damage[ATTR_MAX] + MaxDamageBonus);
			m_Defense[ATTR_CURRENT]    = max(0, m_Defense[ATTR_CURRENT] - DefensePenalty);
			m_Protection[ATTR_CURRENT] = max(0, m_Protection[ATTR_CURRENT] - ProtectionPenalty);
		}
	}
	else if ( isFlag( Effect::EFFECT_CLASS_HOWL ) )
	{
		Effect* pEffect = findEffect( Effect::EFFECT_CLASS_HOWL );
		if ( pEffect != NULL ) pEffect->setDeadline(0);
	}

	if (isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_WERWOLF))
	{
		EffectTransformToWerwolf* pTransformToWerwolf= dynamic_cast<EffectTransformToWerwolf*>(findEffect(Effect::EFFECT_CLASS_TRANSFORM_TO_WERWOLF));
		if (pTransformToWerwolf != NULL)
		{
			int ToHitBonus        = getPercentValue(m_ToHit[ATTR_CURRENT], 20);
			int MinDamageBonus    = m_DEX[ATTR_CURRENT]/6 + m_STR[ATTR_CURRENT]/40;//getPercentValue(m_Damage[ATTR_CURRENT], 20);
			int MaxDamageBonus    = m_DEX[ATTR_CURRENT]/6 + m_STR[ATTR_CURRENT]/40;//getPercentValue(m_Damage[ATTR_MAX], 20);
			int ResistBonus		  = 9;

			m_ToHit[ATTR_CURRENT]      = min(VAMPIRE_MAX_TOHIT, m_ToHit[ATTR_CURRENT] + ToHitBonus);
			m_Damage[ATTR_CURRENT]     = min(VAMPIRE_MAX_DAMAGE, m_Damage[ATTR_CURRENT] + MinDamageBonus);
			m_Damage[ATTR_MAX]         = min(VAMPIRE_MAX_DAMAGE, m_Damage[ATTR_MAX] + MaxDamageBonus);

			m_Resist[MAGIC_DOMAIN_POISON] += ResistBonus;
			m_Resist[MAGIC_DOMAIN_ACID] += ResistBonus;
			m_Resist[MAGIC_DOMAIN_CURSE] += ResistBonus;
			m_Resist[MAGIC_DOMAIN_BLOOD] += ResistBonus;
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_BAT))
	{
		EffectTransformToBat* pTransformToBat = dynamic_cast<EffectTransformToBat*>(findEffect(Effect::EFFECT_CLASS_TRANSFORM_TO_BAT));
		if (pTransformToBat != NULL)
		{
			int DefensePenalty    = getPercentValue(m_Defense[ATTR_CURRENT], 25);
			int ProtectionPenalty = getPercentValue(m_Protection[ATTR_CURRENT], 25);

			m_Defense[ATTR_CURRENT]    = max(0, m_Defense[ATTR_CURRENT]    - DefensePenalty);
			m_Protection[ATTR_CURRENT] = max(0, m_Protection[ATTR_CURRENT] - ProtectionPenalty);
		}
	}
	if(isFlag(Effect::EFFECT_CLASS_EXTREME))
	{
		EffectExtreme* pExtreme = dynamic_cast<EffectExtreme*>(findEffect(Effect::EFFECT_CLASS_EXTREME));
		if (pExtreme!= NULL)
		{
//			int DamageBonus = 4 + ((m_STR[ATTR_CURRENT]-20)/50);
			int DamageBonus = min(15,4 + ((m_STR[ATTR_CURRENT]-20)/30));
			int ToHitBonus = min(20,4 + ((m_STR[ATTR_CURRENT] + m_DEX[ATTR_CURRENT]) / 40));

			m_Damage[ATTR_CURRENT] = max(0, m_Damage[ATTR_CURRENT] + DamageBonus);
			m_Damage[ATTR_MAX]     = max(0, m_Damage[ATTR_MAX]     + DamageBonus);
			m_ToHit[ATTR_CURRENT]  = min(VAMPIRE_MAX_TOHIT, m_ToHit[ATTR_CURRENT] + ToHitBonus);
		}
	}

	if (isFlag(Effect::EFFECT_CLASS_DEATH))
	{
		EffectDeath* pDeath = dynamic_cast<EffectDeath*>(findEffect(Effect::EFFECT_CLASS_DEATH));
		if (pDeath != NULL)
		{
			for (int i=0; i<MAGIC_DOMAIN_MAX; i++)
			{
				m_Resist[i] -= pDeath->getResistPenalty();
//				if ( m_Resist[i] < 0 ) m_Resist[i] = 0;
			}
		}
	}

	if (isFlag(Effect::EFFECT_CLASS_MEPHISTO))
	{
		EffectMephisto* pMephisto = dynamic_cast<EffectMephisto*>(findEffect(Effect::EFFECT_CLASS_MEPHISTO));
		if (pMephisto != NULL)
		{
			int bonusPercent = 100 + pMephisto->getBonus();

			m_ToHit[ATTR_CURRENT]      = min(VAMPIRE_MAX_TOHIT, m_ToHit[ATTR_CURRENT] * bonusPercent / 100);
			m_Defense[ATTR_CURRENT]    = min(VAMPIRE_MAX_DEFENSE, m_Defense[ATTR_CURRENT] * bonusPercent / 100);
			m_Protection[ATTR_CURRENT] = min(VAMPIRE_MAX_PROTECTION, m_Protection[ATTR_CURRENT] * bonusPercent / 100);
		}
	}

	// by sigi. 2002.6.19
	// isEffect�� isFlag�� �ٲ�. 2003.3.27 by Sequoia
	if (isFlag(Effect::EFFECT_CLASS_CASKET))
	{
		EffectSummonCasket* pCasket = dynamic_cast<EffectSummonCasket*>(findEffect(Effect::EFFECT_CLASS_CASKET));
		if (pCasket!= NULL)
		{
			// pCasket->getType()�� ������ �ٸ� �� ����..
			// by sigi. 2002.12.3. 20 --> 30
			int DefenseBonus    = getPercentValue(m_Defense[ATTR_CURRENT],    30);
			int ProtectionBonus = getPercentValue(m_Protection[ATTR_CURRENT], 30);

			m_Defense[ATTR_CURRENT]    = max(0, m_Defense[ATTR_CURRENT]    + DefenseBonus);
			m_Protection[ATTR_CURRENT] = max(0, m_Protection[ATTR_CURRENT] + ProtectionBonus);
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_BLUNTING))
	{
		EffectBlunting* pBlunting = dynamic_cast<EffectBlunting*>(findEffect(Effect::EFFECT_CLASS_BLUNTING));
		if ( pBlunting != NULL )
		{
			int DefensePenalty = pBlunting->getDefensePenalty();
			m_Defense[ATTR_CURRENT]    = max(0, m_Defense[ATTR_CURRENT] - DefensePenalty);
		}
	}


	///////////////////////////////////////////////////////////////////////////////
	// ���� ���ʽ��� �����Ѵ�.
	///////////////////////////////////////////////////////////////////////////////
	if ( hasRankBonus( RankBonus::RANK_BONUS_IMMORTAL_BLOOD ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_IMMORTAL_BLOOD );
		Assert( pRankBonus != NULL );

		int HPBonus = pRankBonus->getPoint();

		m_HP[ATTR_MAX] = min(VAMPIRE_MAX_HP, m_HP[ATTR_MAX] + HPBonus );
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_BEHEMOTH_SKIN ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_BEHEMOTH_SKIN );
		Assert( pRankBonus != NULL );

		int DefenseBonus = pRankBonus->getPoint();

		m_Defense[ATTR_CURRENT] = min(VAMPIRE_MAX_DEFENSE, m_Defense[ATTR_CURRENT] + DefenseBonus ); 
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_SAFE_ROBE ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_SAFE_ROBE );
		Assert( pRankBonus != NULL );

		int ProtectionBonus = pRankBonus->getPoint();

		m_Protection[ATTR_CURRENT] = min(VAMPIRE_MAX_PROTECTION, m_Protection[ATTR_CURRENT] + ProtectionBonus );
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_CROW_WING ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_CROW_WING );
		Assert( pRankBonus != NULL );

		int AttackSpeedBonus = pRankBonus->getPoint();

		m_AttackSpeed[ATTR_CURRENT]	+= AttackSpeedBonus;
		m_AttackSpeed[ATTR_MAX]		+= AttackSpeedBonus;
	}
	if ( hasRankBonus( RankBonus::RANK_BONUS_URANUS_BLESS ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_URANUS_BLESS );
		Assert( pRankBonus != NULL );

		int HPRegenBonus = pRankBonus->getPoint();

		m_HPRegenBonus += HPRegenBonus;
	}

	// DEX �� ���� HPRegenBonus ����Ʈ
	if ( m_DEX[ATTR_BASIC] > 450 )
	{
		m_HPRegenBonus += 7;
	}
	else if ( m_DEX[ATTR_BASIC] > 390 )
	{
		m_HPRegenBonus += 6;
	}
	else if ( m_DEX[ATTR_BASIC] > 330 )
	{
		m_HPRegenBonus += 5;
	}
	else if ( m_DEX[ATTR_BASIC] > 260 )
	{
		m_HPRegenBonus += 4;
	}
	else if ( m_DEX[ATTR_BASIC] > 190 )
	{
		m_HPRegenBonus += 3;
	}
	else if ( m_DEX[ATTR_BASIC] > 120 )
	{
		m_HPRegenBonus += 2;
	}
	else if ( m_DEX[ATTR_BASIC] > 50 )
	{
		m_HPRegenBonus += 1;
	}

	// ��Ƽ�� ũ�⿡ ������ �ɷ�ġ�� ���� �� �ִ�.

	// ���� ���ʽ� ����
	if ( HPBonus > 0 )
	{
		m_HP[ATTR_MAX] = min( VAMPIRE_MAX_HP, m_HP[ATTR_MAX] + HPBonus );
	}

	if ( RaceWarHPBonus > 0 )
	{
		m_HP[ATTR_MAX] = min( VAMPIRE_MAX_HP, m_HP[ATTR_MAX] + RaceWarHPBonus );
	}

    // HP�� ����ġ�� HP�� �ְ�ġ�� �Ѵ� ����
    // ����ġ�� �ְ�ġ����� set
    if (m_HP[ATTR_CURRENT] > m_HP[ATTR_MAX])
    {
        m_HP[ATTR_CURRENT] = m_HP[ATTR_MAX];
		/*
        if (m_pZone)
        {
            GCStatusCurrentHP gcStatusCurrentHP;
            gcStatusCurrentHP.setObjectID(m_ObjectID);
            gcStatusCurrentHP.setCurrentHP (m_HP[ATTR_CURRENT]);
            m_pZone->broadcastPacket(m_X, m_Y, &gcStatusCurrentHP);
        }
		*/
    }

	//////////////////////////////////////////////////////////////////////////////
	// �нú� ����� �����Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	VampireSkillSlot* pNailMastery = getSkill( SKILL_NAIL_MASTERY );
	if ( pNailMastery != NULL )
	{
		int DamageBonus = 3 + ( (getLevel()-56) / 8 );

		m_Damage[ATTR_CURRENT] = max(0, m_Damage[ATTR_CURRENT] + DamageBonus);
		m_Damage[ATTR_MAX]     = max(0, m_Damage[ATTR_MAX]     + DamageBonus);
	}


	initCastleSkill();

	if ( isFlag( Effect::EFFECT_CLASS_TRANSFORM_TO_BAT ) )
	{
		m_Resist[MAGIC_DOMAIN_NO_DOMAIN] = 0;
		m_Resist[MAGIC_DOMAIN_POISON]    = 50;
		m_Resist[MAGIC_DOMAIN_ACID]      = 0;
		m_Resist[MAGIC_DOMAIN_CURSE]     = 0;
		m_Resist[MAGIC_DOMAIN_BLOOD]     = 0;
	}

//	cout << getName() << "�� Luck : " << m_Luck << endl;

	/*
	// ��Ƽ �ο����� �Ѿ����� ��� ������ �ٽ� �����Ѵ�.
	if (numPartyMember == -1)
	{
		if (m_PartyID != 0)
		{
			LocalPartyManager* pLPM = getLocalPartyManager();
			Assert(pLPM != NULL);

			numPartyMember = pLPM->getAdjacentMemberSize(m_PartyID, this);
		}
	}

	if (numPartyMember > 1)
	{
		uint ToHitBonus      = 0;
		uint DefenseBonus    = 0;
		uint ProtectionBonus = 0;
		uint DamageBonus     = 0;

		switch (numPartyMember)
		{
			case 2: ToHitBonus +=  2; DefenseBonus += 1; ProtectionBonus += 1; DamageBonus += 1; break;
			case 3: ToHitBonus +=  4; DefenseBonus += 2; ProtectionBonus += 2; DamageBonus += 1; break;
			case 4: ToHitBonus +=  6; DefenseBonus += 3; ProtectionBonus += 3; DamageBonus += 2; break;
			case 5: ToHitBonus +=  8; DefenseBonus += 4; ProtectionBonus += 4; DamageBonus += 2; break;
			case 6: ToHitBonus += 10; DefenseBonus += 5; ProtectionBonus += 5; DamageBonus += 3; break;
			default: break; 
		}

		m_ToHit[ATTR_CURRENT]      += ToHitBonus;
		m_Defense[ATTR_CURRENT]    += DefenseBonus;
		m_Protection[ATTR_CURRENT] += ProtectionBonus;
		m_Damage[ATTR_CURRENT]     += DamageBonus;
		m_Damage[ATTR_MAX]         += DamageBonus;
	}
	*/

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// STR, DEX, INT�� ����
// CURRENT = �⺻ ��ġ + ������ ��ġ + ���� ��ġ
// MAX     = �⺻ ��ġ + ������ ��ġ
// BASIC   = �⺻ ��ġ
//
// HP, MP�� ����
// CURRENT = ���� ��ġ
// MAX     = ���� �ƽ�
// BASIC   = �����ۿ� ���� ��ȭ ��ġ
//
// Defense, Protection, ToHit�� ����
// CURRENT = ���� ��ġ
// MAX     = �����ۿ� ���� ��ȭ ��ġ
//
// Damage�� ����
// CURRENT = Min ������
// MAX     = Max ������
// BASIC   = �����ۿ� ���� ��ȭ ��ġ
//////////////////////////////////////////////////////////////////////////////
void Vampire::computeStatOffset()
	throw()
{
	__BEGIN_TRY

	Creature::CreatureClass CClass = getCreatureClass();
	BASIC_ATTR              cur_attr;

	cur_attr.nSTR   = m_STR[ATTR_CURRENT];
	cur_attr.nDEX   = m_DEX[ATTR_CURRENT];
	cur_attr.nINT   = m_INT[ATTR_CURRENT];
	cur_attr.nLevel = m_Level;

	// ���ο��� STR, DEX, INT�� ���� ����� �� ���
	// ������ �Ǵ� ���� ��ġ�� ���Ѵ�. 
	m_HP[ATTR_MAX] = computeHP(CClass, &cur_attr);
	m_HP[ATTR_MAX] += m_HP[ATTR_BASIC];

	m_ToHit[ATTR_CURRENT] = computeToHit(CClass, &cur_attr);
	m_ToHit[ATTR_CURRENT] += m_ToHit[ATTR_MAX];

	m_Defense[ATTR_CURRENT] = computeDefense(CClass, &cur_attr);
	m_Defense[ATTR_CURRENT] += m_Defense[ATTR_MAX];

	m_Protection[ATTR_CURRENT] = computeProtection(CClass, &cur_attr);
	m_Protection[ATTR_CURRENT] += m_Protection[ATTR_MAX];

	m_Damage[ATTR_CURRENT] = computeMinDamage(CClass, &cur_attr);
	m_Damage[ATTR_MAX]     = computeMaxDamage(CClass, &cur_attr);

	m_Damage[ATTR_CURRENT] += m_Damage[ATTR_BASIC];
	m_Damage[ATTR_MAX] += m_Damage[ATTR_BASIC];

	m_AttackSpeed[ATTR_CURRENT] = computeAttackSpeed(CClass, &cur_attr);
	m_AttackSpeed[ATTR_CURRENT] += m_AttackSpeed[ATTR_MAX];

	m_CriticalRatio[ATTR_CURRENT] = computeCriticalRatio(CClass, &cur_attr);
	m_CriticalRatio[ATTR_CURRENT] += m_CriticalRatio[ATTR_MAX];
		
	__END_CATCH
}

void Vampire::computeItemStat(Item* pItem)
	throw()
{
	__BEGIN_TRY

	if (isVampireWeapon(pItem->getItemClass()))
	{
		// �������� ���Ⱑ ������ �ӵ� �Ķ����͸� ���Ѵ�.
		ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo(pItem->getItemClass(), pItem->getItemType());
		m_AttackSpeed[ATTR_CURRENT] += pItemInfo->getSpeed();
		m_AttackSpeed[ATTR_MAX]     += pItemInfo->getSpeed();
	}

	m_Protection[ATTR_CURRENT] += pItem->getProtectionBonus();
	m_Protection[ATTR_MAX]     += pItem->getProtectionBonus();

	m_Defense[ATTR_CURRENT] += pItem->getDefenseBonus();
	m_Defense[ATTR_MAX]     += pItem->getDefenseBonus();

	m_ToHit[ATTR_CURRENT] += pItem->getToHitBonus();
	m_ToHit[ATTR_MAX] += pItem->getToHitBonus();

	m_Luck	+= pItem->getLuck();

//	if (pItem->getOptionType()) computeOptionStat(pItem);
	// �ΰ����� �ɼǵ�
	const list<OptionType_t>& optionType = pItem->getOptionTypeList();
	list<OptionType_t>::const_iterator itr;
	for (itr=optionType.begin(); itr!=optionType.end(); itr++)
	{
		computeOptionStat( *itr );
	}

	// Item ��ü�� defaultOption� ������Ų��.
	const list<OptionType_t>& defaultOptions = pItem->getDefaultOptions();
	list<OptionType_t>::const_iterator iOptions;

	for (iOptions=defaultOptions.begin(); iOptions!=defaultOptions.end(); iOptions++)
	{
		computeOptionStat( *iOptions );
	}

	__END_CATCH
}

void Vampire::computeOptionStat(Item* pItem)
	throw()
{
	__BEGIN_TRY

	// Option Type� �޾ƿ´�.
	//OptionType_t  OptionType    = pItem->getOptionType();
	//computeOptionStat( OptionType );

	// �ΰ����� �ɼǵ�
	const list<OptionType_t>& optionType = pItem->getOptionTypeList();
	list<OptionType_t>::const_iterator itr;
	for (itr=optionType.begin(); itr!=optionType.end(); itr++)
	{
		computeOptionStat( *itr );
	}

	// Item ��ü�� defaultOption� ������Ų��.
	const list<OptionType_t>& defaultOptions = pItem->getDefaultOptions();
	list<OptionType_t>::const_iterator iOptions;

	for (iOptions=defaultOptions.begin(); iOptions!=defaultOptions.end(); iOptions++)
	{
		computeOptionStat( *iOptions );
	}

	__END_CATCH
}

void Vampire::computeOptionClassStat(OptionClass OClass, int PlusPoint)
{
	switch (OClass)
	{
		case OPTION_STR:
			m_STR[ATTR_CURRENT] += PlusPoint;
			m_STR[ATTR_MAX]     += PlusPoint;
			computeStatOffset();
			break;
		case OPTION_DEX:
			m_DEX[ATTR_CURRENT] += PlusPoint;
			m_DEX[ATTR_MAX]     += PlusPoint;
			computeStatOffset();
			break;
		case OPTION_INT:
			m_INT[ATTR_CURRENT] += PlusPoint;
			m_INT[ATTR_MAX]     += PlusPoint;
			computeStatOffset();
			break;
		case OPTION_HP:
			m_HP[ATTR_MAX]   += PlusPoint;
			m_HP[ATTR_BASIC] += PlusPoint;
			break;
		case OPTION_MP:
			m_HP[ATTR_MAX]   += PlusPoint;
			m_HP[ATTR_BASIC] += PlusPoint;
			break;
		// �����̾��� MP�����ɼ��� ��� �����۵� HP������ ó�����ش�.
		// 2003. 1. 17. Sequoia
		case OPTION_HP_STEAL:
		case OPTION_MP_STEAL:
			m_HPStealAmount += PlusPoint;
			break;
		case OPTION_HP_REGEN:
		case OPTION_MP_REGEN:
			m_HPRegen += PlusPoint;
			break;
		case OPTION_TOHIT:
			m_ToHit[ATTR_CURRENT] += PlusPoint;
			m_ToHit[ATTR_MAX]     += PlusPoint;
			break;
		case OPTION_DEFENSE:
			m_Defense[ATTR_CURRENT] += PlusPoint;
			m_Defense[ATTR_MAX]     += PlusPoint;
			break;
		case OPTION_DAMAGE:
			m_Damage[ATTR_CURRENT] += PlusPoint;
			m_Damage[ATTR_MAX]     += PlusPoint;
			m_Damage[ATTR_BASIC]   += PlusPoint;
			break;
		case OPTION_PROTECTION:
			m_Protection[ATTR_CURRENT] += PlusPoint;
			m_Protection[ATTR_MAX]     += PlusPoint;
			break;
		case OPTION_POISON:
			m_Resist[MAGIC_DOMAIN_POISON] += PlusPoint;
			break;
		case OPTION_ACID:
			m_Resist[MAGIC_DOMAIN_ACID] += PlusPoint;
			break;
		case OPTION_CURSE:
			m_Resist[MAGIC_DOMAIN_CURSE] += PlusPoint;
			break;
		case OPTION_BLOOD:
			m_Resist[MAGIC_DOMAIN_BLOOD] += PlusPoint;
			break;
		case OPTION_VISION:
			break;
		case OPTION_ATTACK_SPEED:
			m_AttackSpeed[ATTR_CURRENT] += PlusPoint;
			m_AttackSpeed[ATTR_MAX]     += PlusPoint;
			break;
		case OPTION_CRITICAL_HIT:
			m_CriticalRatio[ATTR_CURRENT] += PlusPoint;
			m_CriticalRatio[ATTR_MAX]     += PlusPoint;
			break;

		case OPTION_ALL_ATTR:
			m_STR[ATTR_CURRENT] += PlusPoint;
			m_STR[ATTR_MAX]     += PlusPoint;

			m_DEX[ATTR_CURRENT] += PlusPoint;
			m_DEX[ATTR_MAX]     += PlusPoint;

			m_INT[ATTR_CURRENT] += PlusPoint;
			m_INT[ATTR_MAX]     += PlusPoint;

			computeStatOffset();
			break;

		case OPTION_ALL_RES:
			m_Resist[MAGIC_DOMAIN_POISON] += PlusPoint;
			m_Resist[MAGIC_DOMAIN_ACID] += PlusPoint;
			m_Resist[MAGIC_DOMAIN_CURSE] += PlusPoint;
			m_Resist[MAGIC_DOMAIN_BLOOD] += PlusPoint;
			break;

		case OPTION_LUCK:
			m_Luck += PlusPoint;
			break;

		case OPTION_CONSUME_MP:
			m_ConsumeMPRatio = PlusPoint;
			break;

		case OPTION_MAGIC_DAMAGE:
			m_MagicBonusDamage = PlusPoint;
			break;

		case OPTION_PHYSIC_DAMAGE:
			m_PhysicBonusDamage = PlusPoint;
			break;

		case OPTION_GAMBLE_PRICE:
			m_GamblePriceRatio = PlusPoint;
			break;
			
		case OPTION_POTION_PRICE:
			m_PotionPriceRatio = PlusPoint;
			break;

		default:
			break;
	}
}

void Vampire::computeOptionStat(OptionType_t OptionType)
	throw()
{
	__BEGIN_TRY

	OptionInfo*   pOptionInfo   = g_pOptionInfoManager->getOptionInfo(OptionType);
	computeOptionClassStat( pOptionInfo->getClass(), pOptionInfo->getPlusPoint() );

/*	OptionClass   OClass        = pOptionInfo->getClass();

	switch (OClass)
	{
		case OPTION_STR:
			m_STR[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_STR[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			computeStatOffset();
			break;
		case OPTION_DEX:
			m_DEX[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_DEX[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			computeStatOffset();
			break;
		case OPTION_INT:
			m_INT[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_INT[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			computeStatOffset();
			break;
		case OPTION_HP:
			m_HP[ATTR_MAX]   += pOptionInfo->getPlusPoint();
			m_HP[ATTR_BASIC] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_MP:
			m_HP[ATTR_MAX]   += pOptionInfo->getPlusPoint();
			m_HP[ATTR_BASIC] += pOptionInfo->getPlusPoint();
			break;
		// �����̾��� MP�����ɼ��� ��� �����۵� HP������ ó�����ش�.
		// 2003. 1. 17. Sequoia
		case OPTION_HP_STEAL:
		case OPTION_MP_STEAL:
			m_HPStealAmount += pOptionInfo->getPlusPoint();
			break;
		case OPTION_HP_REGEN:
		case OPTION_MP_REGEN:
			m_HPRegen += pOptionInfo->getPlusPoint();
			break;
		case OPTION_TOHIT:
			m_ToHit[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_ToHit[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;
		case OPTION_DEFENSE:
			m_Defense[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_Defense[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;
		case OPTION_DAMAGE:
			m_Damage[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_Damage[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			m_Damage[ATTR_BASIC]   += pOptionInfo->getPlusPoint();
			break;
		case OPTION_PROTECTION:
			m_Protection[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_Protection[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;
		case OPTION_POISON:
			m_Resist[MAGIC_DOMAIN_POISON] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_ACID:
			m_Resist[MAGIC_DOMAIN_ACID] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_CURSE:
			m_Resist[MAGIC_DOMAIN_CURSE] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_BLOOD:
			m_Resist[MAGIC_DOMAIN_BLOOD] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_VISION:
			break;
		case OPTION_ATTACK_SPEED:
			m_AttackSpeed[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_AttackSpeed[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;
		case OPTION_CRITICAL_HIT:
			m_CriticalRatio[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_CriticalRatio[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;

		case OPTION_ALL_ATTR:
			m_STR[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_STR[ATTR_MAX]     += pOptionInfo->getPlusPoint();

			m_DEX[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_DEX[ATTR_MAX]     += pOptionInfo->getPlusPoint();

			m_INT[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_INT[ATTR_MAX]     += pOptionInfo->getPlusPoint();

			computeStatOffset();
			break;

		case OPTION_ALL_RES:
			m_Resist[MAGIC_DOMAIN_POISON] += pOptionInfo->getPlusPoint();
			m_Resist[MAGIC_DOMAIN_ACID] += pOptionInfo->getPlusPoint();
			m_Resist[MAGIC_DOMAIN_CURSE] += pOptionInfo->getPlusPoint();
			m_Resist[MAGIC_DOMAIN_BLOOD] += pOptionInfo->getPlusPoint();
			break;

		case OPTION_LUCK:
			m_Luck += pOptionInfo->getPlusPoint();
			break;

		case OPTION_CONSUME_MP:
			m_ConsumeMPRatio = pOptionInfo->getPlusPoint();
			break;

		case OPTION_MAGIC_DAMAGE:
			m_MagicBonusDamage = pOptionInfo->getPlusPoint();
			break;

		case OPTION_PHYSIC_DAMAGE:
			m_PhysicBonusDamage = pOptionInfo->getPlusPoint();
			break;

		case OPTION_GAMBLE_PRICE:
			m_GamblePriceRatio = pOptionInfo->getPlusPoint();
			break;
			
		case OPTION_POTION_PRICE:
			m_PotionPriceRatio = pOptionInfo->getPlusPoint();
			break;

		default:
			break;
	}
*/
	__END_CATCH
}

void Vampire::addModifyInfo(const VAMPIRE_RECORD& prev, ModifyInfo& pkt) const
	throw()
{
	__BEGIN_TRY

	if (prev.pSTR[ATTR_CURRENT] != m_STR[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_STR, m_STR[ATTR_CURRENT]);
	if (prev.pSTR[ATTR_MAX    ] != m_STR[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_STR,     m_STR[ATTR_MAX]);
	if (prev.pSTR[ATTR_BASIC  ] != m_STR[ATTR_BASIC  ]) pkt.addShortData(MODIFY_BASIC_STR,   m_STR[ATTR_BASIC]);

	if (prev.pDEX[ATTR_CURRENT] != m_DEX[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_DEX, m_DEX[ATTR_CURRENT]);
	if (prev.pDEX[ATTR_MAX    ] != m_DEX[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_DEX,     m_DEX[ATTR_MAX]);
	if (prev.pDEX[ATTR_BASIC  ] != m_DEX[ATTR_BASIC  ]) pkt.addShortData(MODIFY_BASIC_DEX,   m_DEX[ATTR_BASIC]);

	if (prev.pINT[ATTR_CURRENT] != m_INT[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_INT, m_INT[ATTR_CURRENT]);
	if (prev.pINT[ATTR_MAX    ] != m_INT[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_INT,     m_INT[ATTR_MAX]);
	if (prev.pINT[ATTR_BASIC  ] != m_INT[ATTR_BASIC  ]) pkt.addShortData(MODIFY_BASIC_INT,   m_INT[ATTR_BASIC]);

	if (prev.pHP[ATTR_CURRENT] != m_HP[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_HP, m_HP[ATTR_CURRENT]);
	if (prev.pHP[ATTR_MAX    ] != m_HP[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_HP,     m_HP[ATTR_MAX]);

	if (prev.pDamage[ATTR_CURRENT] != m_Damage[ATTR_CURRENT]) pkt.addShortData(MODIFY_MIN_DAMAGE, m_Damage[ATTR_CURRENT]);
	if (prev.pDamage[ATTR_MAX    ] != m_Damage[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_DAMAGE, m_Damage[ATTR_MAX]);

	if (prev.Defense     != m_Defense[ATTR_CURRENT])     pkt.addShortData(MODIFY_DEFENSE,      m_Defense[ATTR_CURRENT]);
	if (prev.Protection  != m_Protection[ATTR_CURRENT])  pkt.addShortData(MODIFY_PROTECTION,   m_Protection[ATTR_CURRENT]);
	if (prev.ToHit       != m_ToHit[ATTR_CURRENT])       pkt.addShortData(MODIFY_TOHIT,        m_ToHit[ATTR_CURRENT]);
	if (prev.AttackSpeed != m_AttackSpeed[ATTR_CURRENT]) pkt.addShortData(MODIFY_ATTACK_SPEED, m_AttackSpeed[ATTR_CURRENT]);

	// by sigi. 2002.9.10
	if (prev.Rank != getRank())
	{
		pkt.addShortData(MODIFY_RANK, getRank());
		pkt.addLongData(MODIFY_RANK_EXP, getRankGoalExp());
	}

	__END_CATCH
}

void Vampire::sendModifyInfo(const VAMPIRE_RECORD& prev) const
	throw()
{
	__BEGIN_TRY

	GCModifyInformation gcModifyInformation;
	addModifyInfo(prev, gcModifyInformation);
	m_pPlayer->sendPacket(&gcModifyInformation);

	__END_CATCH	
}

void Vampire::initAllStatAndSend()
{
	VAMPIRE_RECORD prev;
	getVampireRecord(prev);
	initAllStat();
	sendModifyInfo(prev);
}

//////////////////////////////////////////////////////////////////////////////
//
// ������
//
//////////////////////////////////////////////////////////////////////////////
void Monster::initAllStat(void)
	throw()
{
	__BEGIN_TRY

	const MonsterInfo* pMonsterInfo = g_pMonsterInfoManager->getMonsterInfo(m_MonsterType);

	Creature::CreatureClass CClass = getCreatureClass();
	BASIC_ATTR              attr;

	m_Resist[MAGIC_DOMAIN_NO_DOMAIN] = 0;
	m_Resist[MAGIC_DOMAIN_POISON]    = 50;
	m_Resist[MAGIC_DOMAIN_ACID]      = 0;
	m_Resist[MAGIC_DOMAIN_CURSE]     = 0;
	m_Resist[MAGIC_DOMAIN_BLOOD]     = 0;
	 
	////////////////////////////////////////////////////////////
	// ��� ���� �⺻ �ɷ�ġ�� �ʱ�ȭ��Ű��...
	////////////////////////////////////////////////////////////
	m_STR = pMonsterInfo->getSTR();
	m_DEX = pMonsterInfo->getDEX();
	m_INT = pMonsterInfo->getINT();

	////////////////////////////////////////////////////////////
	// �⺻ �ɷ¿� ����� �ִ� ����Ʈ�� �˻��Ѵ�.
	////////////////////////////////////////////////////////////
	attr.nSTR   = m_STR;
	attr.nDEX   = m_DEX;
	attr.nINT   = m_INT;
	attr.nLevel = pMonsterInfo->getLevel();

	////////////////////////////////////////////////////////////
	// �ΰ����� �ɷ�ġ��� �ٽ� �����Ѵ�.
	////////////////////////////////////////////////////////////
	m_HP[ATTR_MAX]         = computeHP(CClass, &attr, pMonsterInfo->getEnhanceHP());
	m_ToHit                = computeToHit(CClass, &attr, pMonsterInfo->getEnhanceToHit());
	m_Defense              = computeDefense(CClass, &attr, pMonsterInfo->getEnhanceDefense());
	m_Protection           = computeProtection(CClass, &attr, pMonsterInfo->getEnhanceProtection());
	m_Damage[ATTR_CURRENT] = computeMinDamage(CClass, &attr, pMonsterInfo->getEnhanceMinDamage());
	m_Damage[ATTR_MAX]     = computeMaxDamage(CClass, &attr, pMonsterInfo->getEnhanceMaxDamage());


//#ifdef __XMAS_EVENT_CODE__
	// ���� ũ�������� �̺�Ʈ�� ��ȹ�� ��������, ����� ���� ������ �����
	// ����ȴ�. 
	if (m_MonsterType == 358 || m_MonsterType == 359 || m_MonsterType == 360 || m_MonsterType == 361)
		m_HP[ATTR_MAX] = m_HP[ATTR_MAX] * 10;
//#endif
	
	////////////////////////////////////////////////////////////
	// �ΰ����� �ɷ�ġ��� ��� ����ϴ� ����Ʈ�� �˻��Ѵ�.
	////////////////////////////////////////////////////////////
	if (isFlag(Effect::EFFECT_CLASS_DOOM))
	{
		EffectDoom* pDoom = dynamic_cast<EffectDoom*>(findEffect(Effect::EFFECT_CLASS_DOOM));
		if (pDoom!= NULL)
		{
			int DefensePenalty    = getPercentValue(m_Defense,    pDoom->getDefensePenalty());
			int ProtectionPenalty = getPercentValue(m_Protection, pDoom->getProtectionPenalty());

			m_Defense    = max(0, m_Defense - DefensePenalty);
			m_Protection = max(0, m_Protection - ProtectionPenalty);
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_SEDUCTION))
	{
		EffectSeduction* pSeduction = dynamic_cast<EffectSeduction*>(findEffect(Effect::EFFECT_CLASS_SEDUCTION));
		if (pSeduction!= NULL)
		{
			int ToHitPenalty   = getPercentValue(m_ToHit,                pSeduction->getToHitPenalty());
			int DamagePenalty1 = getPercentValue(m_Damage[ATTR_CURRENT], pSeduction->getDamagePenalty());
			int DamagePenalty2 = getPercentValue(m_Damage[ATTR_MAX],     pSeduction->getDamagePenalty());

			m_ToHit                = max(0, m_ToHit - ToHitPenalty);
			m_Damage[ATTR_CURRENT] = max(0, m_Damage[ATTR_CURRENT] - DamagePenalty1);
			m_Damage[ATTR_MAX]     = max(0, m_Damage[ATTR_MAX] - DamagePenalty2);
		}
	}
/*	if (isFlag(Effect::EFFECT_CLASS_PARALYZE))
	{
		EffectParalyze* pParalyze = dynamic_cast<EffectParalyze*>(findEffect(Effect::EFFECT_CLASS_PARALYZE));
		if (pParalyze != NULL)
		{
			int DefensePenalty = getPercentValue(m_Defense, pParalyze->getDefensePenalty());
			m_Defense = max(0, m_Defense - DefensePenalty);
		}
	}*/
	if (isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_WOLF))
	{
		EffectTransformToWolf* pTransformToWolf= dynamic_cast<EffectTransformToWolf*>(findEffect(Effect::EFFECT_CLASS_TRANSFORM_TO_WOLF));
		if (pTransformToWolf != NULL)
		{
			int ToHitBonus        = getPercentValue(m_ToHit, 20);
			int MinDamageBonus    = getPercentValue(m_Damage[ATTR_CURRENT], 20);
			int MaxDamageBonus    = getPercentValue(m_Damage[ATTR_MAX], 20);
			int DefensePenalty    = getPercentValue(m_Defense, 50);
			int ProtectionPenalty = getPercentValue(m_Protection, 50);

			m_ToHit                = min(VAMPIRE_MAX_TOHIT, m_ToHit + ToHitBonus);
			m_Damage[ATTR_CURRENT] = min(VAMPIRE_MAX_DAMAGE, m_Damage[ATTR_CURRENT] + MinDamageBonus);
			m_Damage[ATTR_MAX]     = min(VAMPIRE_MAX_DAMAGE, m_Damage[ATTR_MAX] + MaxDamageBonus);
			m_Defense              = max(0, m_Defense - DefensePenalty);
			m_Protection           = max(0, m_Protection - ProtectionPenalty);
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_BAT))
	{
		EffectTransformToBat* pTransformToBat = dynamic_cast<EffectTransformToBat*>(findEffect(Effect::EFFECT_CLASS_TRANSFORM_TO_BAT));
		if (pTransformToBat != NULL)
		{
			int DefensePenalty    = getPercentValue(m_Defense, 25);
			int ProtectionPenalty = getPercentValue(m_Protection, 25);

			m_Defense    = max(0, m_Defense - DefensePenalty);
			m_Protection = max(0, m_Protection - ProtectionPenalty);
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_BLUNTING))
	{
		EffectBlunting* pBlunting = dynamic_cast<EffectBlunting*>(findEffect(Effect::EFFECT_CLASS_BLUNTING));
		if ( pBlunting != NULL )
		{
			int DefensePenalty = pBlunting->getDefensePenalty();
			m_Defense = max(0, m_Defense - DefensePenalty);
		}
	}

	
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// 
// �ƿ콺�ͽ�
//
//////////////////////////////////////////////////////////////////////////////

void Ousters::initAllStat(int numPartyMember)
	throw()
{
	__BEGIN_TRY

	BASIC_ATTR attr;
	Creature::CreatureClass CClass = getCreatureClass();

	m_Resist[MAGIC_DOMAIN_NO_DOMAIN] = 0;
	m_Resist[MAGIC_DOMAIN_POISON]    = 0;
	m_Resist[MAGIC_DOMAIN_ACID]      = 0;
	m_Resist[MAGIC_DOMAIN_CURSE]     = 0;
	m_Resist[MAGIC_DOMAIN_BLOOD]     = 0;

	// BloodBible ���� ���ʽ� ��ġ�� �ʱ�ȭ
	m_ConsumeMPRatio	= 0;
	m_GamblePriceRatio	= 0;
	m_PotionPriceRatio	= 0;
	m_MagicBonusDamage	= 0;
	m_PhysicBonusDamage	= 0;

	//////////////////////////////////////////////////////////////////////////////
	// ��� ���� �⺻ �ɷ�ġ�� �ʱ�ȭ��Ű��, 
	// �⺻ �ɷ�ġ�� ����� �ִ� ����Ʈ�� �˻��Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	m_STR[ATTR_CURRENT] = m_STR[ATTR_MAX] = m_STR[ATTR_BASIC];
	m_DEX[ATTR_CURRENT] = m_DEX[ATTR_MAX] = m_DEX[ATTR_BASIC];
	m_INT[ATTR_CURRENT] = m_INT[ATTR_MAX] = m_INT[ATTR_BASIC];

	//////////////////////////////////////////////////////////////////////////////
	// �ɷ�ġ ����� ��� �Ķ����͵�� �ʱ�ȭ�Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	attr.nSTR    = m_STR[ATTR_CURRENT];
	attr.nDEX    = m_DEX[ATTR_CURRENT];
	attr.nINT    = m_INT[ATTR_CURRENT];
	attr.pWeapon = getWearItem(WEAR_RIGHTHAND);
	attr.nLevel  = m_Level;
	
	m_HPStealRatio  = 0;
	m_MPStealRatio  = 0;

	m_HPStealAmount = 0;
	m_MPStealAmount = 0;

	m_HPRegen		= 0;
	m_MPRegen		= 0;
	m_Luck			= 0;

	m_FireDamage	= 0;
	m_WaterDamage	= 0;
	m_EarthDamage	= 0;

	m_SilverResist	= 0;

	m_ElementalFire = 0;
	m_ElementalWater = 0;
	m_ElementalEarth = 0;
	m_ElementalWind = 0;

	m_PassiveRatio = 0;

	////////////////////////////////////////////////////////////
	// �ΰ����� �ɷ�ġ��� �ٽ� �����Ѵ�.
	////////////////////////////////////////////////////////////
	m_HP[ATTR_MAX]                = computeHP(CClass, &attr);
	m_HP[ATTR_BASIC]              = 0;
	m_MP[ATTR_MAX]                = computeMP(CClass, &attr);
	m_MP[ATTR_BASIC]              = 0;
	m_ToHit[ATTR_CURRENT]         = computeToHit(CClass, &attr);
	m_ToHit[ATTR_MAX]             = 0;
	m_Defense[ATTR_CURRENT]       = computeDefense(CClass, &attr);
	m_Defense[ATTR_MAX]           = 0;
	m_Protection[ATTR_CURRENT]    = computeProtection(CClass, &attr);
	m_Protection[ATTR_MAX]        = 0;
	m_Damage[ATTR_CURRENT]        = computeMinDamage(CClass, &attr);
	m_Damage[ATTR_MAX]            = computeMaxDamage(CClass, &attr);
	m_Damage[ATTR_BASIC]          = 0;
	m_AttackSpeed[ATTR_CURRENT]   = computeAttackSpeed(CClass, &attr);
	m_AttackSpeed[ATTR_MAX]       = 0;
	m_CriticalRatio[ATTR_CURRENT] = computeCriticalRatio(CClass, &attr);
	m_CriticalRatio[ATTR_MAX]     = 0;

	int RaceWarHPBonus = 0;

	if ( m_pZone->isHolyLand() || m_pZone->isLevelWarZone() )
	{
		RaceWarHPBonus = getPercentValue( m_HP[ATTR_MAX], g_pVariableManager->getRaceWarHPBonus() );
	}

	//////////////////////////////////////////////////////////////////////////////
	// �ϴ� ���� üũ ������ �ʱ�ȭ�ؼ� ���� ��� �� ��� ����� �����ϰ� �����Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	bool pOldRealWearingCheck[OUSTERS_WEAR_MAX];	// by sigi. 2002.10.31
	for (int i=0; i<OUSTERS_WEAR_MAX; i++) 
	{
		pOldRealWearingCheck[i] = m_pRealWearingCheck[i];
		m_pRealWearingCheck[i] = false;
	}

	//////////////////////////////////////////////////////////////////////////////
	// Blood Bible ������ ���ʽ� �ɼ�� �޴´�.
	//////////////////////////////////////////////////////////////////////////////
	if ( m_pZone->isHolyLand() && !g_pWarSystem->hasActiveRaceWar() )
	{
		const BloodBibleBonusHashMap& bloodBibleBonus = g_pBloodBibleBonusManager->getBloodBibleBonuses();
		BloodBibleBonusHashMapConstItor itr;
		for (itr=bloodBibleBonus.begin(); itr!=bloodBibleBonus.end(); itr++)
		{
			if ( itr->second->getRace() == RACE_OUSTERS )
			{
				OptionTypeList optionTypes = itr->second->getOptionTypeList();
				OptionTypeListConstItor optionItr;
				
				for ( optionItr = optionTypes.begin(); optionItr != optionTypes.end(); optionItr++ )
				{
					computeOptionStat( *optionItr );
				}
			}
		}
	}

	if ( g_pSweeperBonusManager->isAble( getZoneID() ) && g_pLevelWarZoneInfoManager->isCreatureBonusZone( this, getZoneID() ))
	{
		const SweeperBonusHashMap& sweeperBonuses = g_pSweeperBonusManager->getSweeperBonuses();

		SweeperBonusHashMapConstItor itr = sweeperBonuses.begin();
		SweeperBonusHashMapConstItor endItr = sweeperBonuses.end();

		for (; itr!=endItr; itr++)
		{
			if ( itr->second->getRace() == RACE_OUSTERS && itr->second->getLevel() == g_pLevelWarZoneInfoManager->getCreatureLevelGrade( this ) )
			{
				OptionTypeList optionTypes = itr->second->getOptionTypeList();
				OptionTypeListConstItor optionItr;
				
				for ( optionItr = optionTypes.begin(); optionItr != optionTypes.end(); optionItr++ )
				{
					computeOptionStat( *optionItr );
				}
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// �⺻����� ������ �ִ� �ɼǵ�� �����Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	list<DefaultOptionSetType_t>::iterator itr = m_DefaultOptionSet.begin();
	for ( ; itr != m_DefaultOptionSet.end(); itr++ )
	{
		DefaultOptionSetInfo* pDefaultOptionSetInfo = g_pDefaultOptionSetInfoManager->getDefaultOptionSetInfo( (*itr) );
		if ( pDefaultOptionSetInfo != NULL )
		{
			const list<OptionType_t>& optionList = pDefaultOptionSetInfo->getOptionTypeList();
			list<OptionType_t>::const_iterator citr;
			for ( citr = optionList.begin(); citr != optionList.end(); citr++ )
			{
				computeOptionStat( *citr );
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// ���� �ִ� ���ʽ��� �����Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	if ( m_pPetInfo != NULL )
	{
		if ( m_pPetInfo->getPetAttr() != 0xff ) computeOptionClassStat( (OptionClass)m_pPetInfo->getPetAttr(), (int)m_pPetInfo->getPetAttrLevel() );
		if ( m_pPetInfo->getPetOption() != 0 ) computeOptionStat( m_pPetInfo->getPetOption() );
	}

	if ( isFlag( Effect::EFFECT_CLASS_GROUND_BLESS ) )
	{
		EffectGroundBless* pEffect = dynamic_cast<EffectGroundBless*>(findEffect(Effect::EFFECT_CLASS_GROUND_BLESS));

		if ( pEffect != NULL )
		{
			int bonus = pEffect->getBonus();
			m_STR[ATTR_CURRENT] += bonus;
			m_DEX[ATTR_CURRENT] += bonus;
			m_INT[ATTR_CURRENT] += bonus;
			m_STR[ATTR_MAX] += bonus;
			m_DEX[ATTR_MAX] += bonus;
			m_INT[ATTR_MAX] += bonus;

			computeStatOffset();
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// for �� �ι��� ����� ��������� �ö��� �ɷ�ġ�� ���ؼ�
	// ��� �� �ְ� �Ǵ� ������� üũ�ϱ� ��ؼ��̴�.
	//////////////////////////////////////////////////////////////////////////////
	for (int j=0; j<OUSTERS_WEAR_MAX; j++)
	{
		int wearCount = 0;
		for (int i=0; i<OUSTERS_WEAR_MAX; i++)
		{
			Item* pItem = m_pWearItem[i];
			// ���� ����Ʈ�� �������� �ְ�
			// �װͿ� ���� üũ�� ���� ���� �ʾҴٸ�...
			if (pItem != NULL && m_pRealWearingCheck[i] == false)
			{
				// ���� ��¥�� ��� �� �ִ� �������̶��� �ɷ�ġ�� �÷��ش�.
				if (isRealWearing(pItem))
				{
					computeItemStat(pItem);

					// ���� ��������, üũ�� �ι� ���� �ʵ���
					// ����, ����� ���� üũ ������ ����
					if (isTwohandWeapon(pItem))
					{
						m_pRealWearingCheck[WEAR_LEFTHAND] = true;
						m_pRealWearingCheck[WEAR_RIGHTHAND] = true;
					}
					else m_pRealWearingCheck[i] = true;

					wearCount ++;
				}
			}
		}

		if (wearCount==0)	// by sigi. 2002.10.30
			break;
	}

	// by sigi. 2002.11.6
	bool bSendPacket = false;

	if (m_pPlayer!=NULL)
	{	
		bSendPacket = (dynamic_cast<GamePlayer*>(m_pPlayer)->getPlayerStatus()==GPS_NORMAL);
	}

	// �ϴ� ����� �� �Ծ��µ�..
	// �ɷ�ġ�� ������ ������ ������ �ȵǴ� ������� ���� ����� ���ش�.
	// by sigi. 2002.10.30
	for (int i=0; i<OUSTERS_WEAR_MAX; i++)
	//int i=WEAR_COAT;
	{
		if (m_pRealWearingCheck[i])
		{
			// by sigi. 2002.10.31
			if (pOldRealWearingCheck[i]==false)
			{
				Item* pItem = m_pWearItem[i];
				if (pItem!=NULL)
				{
					Item::ItemClass IClass = pItem->getItemClass();
					ItemType_t		IType  = pItem->getItemType();

					Color_t color = getItemShapeColor( pItem );
					addShape(IClass, IType, color);

					if (bSendPacket)
					{
						GCChangeShape pkt;
						pkt.setObjectID(getObjectID());
						pkt.setItemClass(IClass);
						pkt.setItemType(IType);
						pkt.setOptionType(pItem->getFirstOptionType());
						pkt.setAttackSpeed(m_AttackSpeed[ATTR_CURRENT]);

						m_pZone->broadcastPacket(m_X, m_Y , &pkt, this);
					}
				}
			}
		}
		else
		{
			Item* pItem = m_pWearItem[i];
			if (pItem!=NULL)
			{
				removeShape(pItem->getItemClass(), bSendPacket);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// HP, MP ��ƿ Ȯ��� ������ �д�.
	//////////////////////////////////////////////////////////////////////////////
	if ( hasRankBonus( RankBonus::RANK_BONUS_LIFE_ABSORB ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_LIFE_ABSORB );
		Assert( pRankBonus != NULL );

		int StealBonus = pRankBonus->getPoint();

		m_HPStealAmount += StealBonus;
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_SOUL_ABSORB ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_SOUL_ABSORB );
		Assert( pRankBonus != NULL );

		int StealBonus = pRankBonus->getPoint();

		m_MPStealAmount += StealBonus;
	}

	m_HPStealRatio = computeStealRatio(CClass, m_HPStealAmount, &attr);
	m_MPStealRatio = computeStealRatio(CClass, m_MPStealAmount, &attr);
	//cout << getName() << " HPSteal : " << (int)m_HPStealAmount << endl;

	//////////////////////////////////////////////////////////////////////////////
	// �ΰ����� �ɷ�ġ�� ��� ����ϴ� ����Ʈ�� �˻��Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	if (isFlag(Effect::EFFECT_CLASS_DOOM))
	{
		EffectDoom* pDoom = dynamic_cast<EffectDoom*>(findEffect(Effect::EFFECT_CLASS_DOOM));
		if (pDoom!= NULL)
		{
			int DefensePenalty    = getPercentValue(m_Defense[ATTR_CURRENT], pDoom->getDefensePenalty());
			int ProtectionPenalty = getPercentValue(m_Protection[ATTR_CURRENT], pDoom->getProtectionPenalty());

			m_Defense[ATTR_CURRENT]    = max(0, m_Defense[ATTR_CURRENT]    - DefensePenalty);
			m_Protection[ATTR_CURRENT] = max(0, m_Protection[ATTR_CURRENT] - ProtectionPenalty);
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_SEDUCTION))
	{
		EffectSeduction* pSeduction = dynamic_cast<EffectSeduction*>(findEffect(Effect::EFFECT_CLASS_SEDUCTION));
		if (pSeduction!= NULL)
		{
			int ToHitPenalty   = getPercentValue(m_ToHit[ATTR_CURRENT],  pSeduction->getToHitPenalty());
			int DamagePenalty1 = getPercentValue(m_Damage[ATTR_CURRENT], pSeduction->getDamagePenalty());
			int DamagePenalty2 = getPercentValue(m_Damage[ATTR_MAX],     pSeduction->getDamagePenalty());

			m_ToHit[ATTR_CURRENT]  = max(0, m_ToHit[ATTR_CURRENT] - ToHitPenalty);
			m_Damage[ATTR_CURRENT] = max(0, m_Damage[ATTR_CURRENT] - DamagePenalty1);
			m_Damage[ATTR_MAX]     = max(0, m_Damage[ATTR_MAX] - DamagePenalty2);
		}
	}
	if (isFlag(Effect::EFFECT_CLASS_DEATH))
	{
		EffectDeath* pDeath = dynamic_cast<EffectDeath*>(findEffect(Effect::EFFECT_CLASS_DEATH));
		if (pDeath != NULL)
		{
			for (int i=0; i<MAGIC_DOMAIN_MAX; i++)
			{
				m_Resist[i] -= pDeath->getResistPenalty();
//				if ( m_Resist[i] < 0 ) m_Resist[i] = 0;
			}
		}
	}
	if ( isFlag( Effect::EFFECT_CLASS_EVADE ) )
	{
		EffectEvade* pEffect = dynamic_cast<EffectEvade*>(findEffect(Effect::EFFECT_CLASS_EVADE));

		if ( pEffect != NULL )
		{
			if ( attr.pWeapon != NULL && attr.pWeapon->getItemClass() == Item::ITEM_CLASS_OUSTERS_CHAKRAM )
				m_Defense[ATTR_CURRENT] += pEffect->getBonus();
			else
				pEffect->setDeadline(0);
		}
	}

	if ( isFlag( Effect::EFFECT_CLASS_CROSS_GUARD ) )
	{
		EffectCrossGuard* pEffect = dynamic_cast<EffectCrossGuard*>(findEffect(Effect::EFFECT_CLASS_CROSS_GUARD));

		if ( pEffect != NULL )
		{
			if ( attr.pWeapon != NULL && attr.pWeapon->getItemClass() == Item::ITEM_CLASS_OUSTERS_CHAKRAM )
				m_Protection[ATTR_CURRENT] += pEffect->getBonus();
			else
				pEffect->setDeadline(0);
		}
	}

	if (isFlag(Effect::EFFECT_CLASS_BLUNTING))
	{
		EffectBlunting* pBlunting = dynamic_cast<EffectBlunting*>(findEffect(Effect::EFFECT_CLASS_BLUNTING));
		if ( pBlunting != NULL )
		{
			if ( attr.pWeapon != NULL && attr.pWeapon->getItemClass() == Item::ITEM_CLASS_OUSTERS_CHAKRAM )
			{
				int DefensePenalty = pBlunting->getDefensePenalty();
				m_Defense[ATTR_CURRENT]    = max(0, m_Defense[ATTR_CURRENT] - DefensePenalty);
			}
			else
				pBlunting->setDeadline(0);
		}
	}

/*	if ( isFlag( Effect::EFFECT_CLASS_HANDS_OF_FIRE ) )
	{
		//cout << getName() << " ����������̾� �پ���" << endl;
		EffectHandsOfFire* pEffect = dynamic_cast<EffectHandsOfFire*>(findEffect(Effect::EFFECT_CLASS_HANDS_OF_FIRE));

		if ( pEffect != NULL )
		{
			if ( attr.pWeapon == NULL || attr.pWeapon->getItemClass() != Item::ITEM_CLASS_OUSTERS_WRISTLET )
				pEffect->setDeadline(0);
			else
			{
				m_FireDamage += pEffect->getBonus();
				//cout << getName() << " FireDamage : " << m_FireDamage << endl;
			}
		}
	}*/

	if ( isFlag( Effect::EFFECT_CLASS_RING_OF_FLARE ) )
	{
		EffectRingOfFlare* pEffect = dynamic_cast<EffectRingOfFlare*>(findEffect(Effect::EFFECT_CLASS_RING_OF_FLARE));

		if ( pEffect != NULL )
		{
			if ( attr.pWeapon == NULL || attr.pWeapon->getItemClass() != Item::ITEM_CLASS_OUSTERS_WRISTLET )
				pEffect->setDeadline(0);
		}
	}

	if ( isFlag( Effect::EFFECT_CLASS_WATER_BARRIER ) )
	{
		EffectWaterBarrier* pEffect = dynamic_cast<EffectWaterBarrier*>(findEffect(Effect::EFFECT_CLASS_WATER_BARRIER));

		if ( pEffect != NULL )
		{
			if ( attr.pWeapon == NULL || attr.pWeapon->getItemClass() != Item::ITEM_CLASS_OUSTERS_WRISTLET )
				pEffect->setDeadline(0);
		}
	}

/*	if ( isFlag( Effect::EFFECT_CLASS_GNOMES_WHISPER ) )
	{
		EffectGnomesWhisper* pEffect = dynamic_cast<EffectGnomesWhisper*>(findEffect(Effect::EFFECT_CLASS_GNOMES_WHISPER));

		if ( pEffect != NULL )
		{
			if ( attr.pWeapon == NULL || attr.pWeapon->getItemClass() != Item::ITEM_CLASS_OUSTERS_WRISTLET )
				pEffect->setDeadline(0);
		}
	}*/

	if (isFlag(Effect::EFFECT_CLASS_SUMMON_SYLPH))
	{
		int ProtectionBonus = max( 5,getLevel() / 10 );
		int ResistBonus = max( 5,getLevel() / 15 );

		m_Protection[ATTR_CURRENT] += ProtectionBonus;

		m_Resist[MAGIC_DOMAIN_NO_DOMAIN] += ResistBonus;
		m_Resist[MAGIC_DOMAIN_POISON]    += ResistBonus;
		m_Resist[MAGIC_DOMAIN_ACID]      += ResistBonus;
		m_Resist[MAGIC_DOMAIN_CURSE]     += ResistBonus;
		m_Resist[MAGIC_DOMAIN_BLOOD]     += ResistBonus;
	}

	if ( isFlag( Effect::EFFECT_CLASS_REACTIVE_ARMOR ) )
	{
		EffectReactiveArmor* pEffect = dynamic_cast<EffectReactiveArmor*>(findEffect(Effect::EFFECT_CLASS_REACTIVE_ARMOR));

		if ( pEffect != NULL )
		{
			int bonus = pEffect->getBonus();
			m_Protection[ATTR_CURRENT] += bonus;
			m_Defense[ATTR_CURRENT] += bonus;
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// �нú� ����� �����Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
	OustersSkillSlot* pHideSight = getSkill( SKILL_HIDE_SIGHT );
	if ( pHideSight != NULL && attr.pWeapon != NULL && attr.pWeapon->getItemClass() == Item::ITEM_CLASS_OUSTERS_CHAKRAM )
	{
		SkillLevel_t level = pHideSight->getExpLevel();

		if ( level <= 15 )
		{
//			m_ToHit[ATTR_CURRENT] += (int)((m_DEX[ATTR_CURRENT] / 20.0) * ( 1.0 + (level / 15.0) ));
			m_ToHit[ATTR_CURRENT] += ( 15 + (level * 8 / 9) );
		}
		else
		{
//			m_ToHit[ATTR_CURRENT] += (int)((m_DEX[ATTR_CURRENT] / 20.0) * ( 1.5 + (level / 30.0) ));
			int ToHitBonus = ( 35 + (level * 4 / 9) );
			if ( level == 30 ) ToHitBonus = (int)(ToHitBonus * 1.1);

			m_ToHit[ATTR_CURRENT] += ToHitBonus;
		}
	}


	///////////////////////////////////////////////////////////////////////////////
	// ���� ���ʽ��� �����Ѵ�.
	///////////////////////////////////////////////////////////////////////////////
	if ( hasRankBonus( RankBonus::RANK_BONUS_WOOD_SKIN ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_WOOD_SKIN );
		Assert( pRankBonus != NULL );

		int ProtectionBonus = pRankBonus->getPoint();

		m_Protection[ATTR_CURRENT]  = min(OUSTERS_MAX_PROTECTION, m_Protection[ATTR_CURRENT] + ProtectionBonus);
		m_Protection[ATTR_MAX]      = min(OUSTERS_MAX_PROTECTION, m_Protection[ATTR_MAX] + ProtectionBonus);
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_WIND_SENSE ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_WIND_SENSE );
		Assert( pRankBonus != NULL );

		int DefenseBonus = pRankBonus->getPoint();

		m_Defense[ATTR_CURRENT]  = min(OUSTERS_MAX_DEFENSE, m_Defense[ATTR_CURRENT] + DefenseBonus);
		m_Defense[ATTR_MAX]      = min(OUSTERS_MAX_DEFENSE, m_Defense[ATTR_MAX] + DefenseBonus);
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_HOMING_EYE ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_HOMING_EYE );
		Assert( pRankBonus != NULL );

		int ToHitBonus = pRankBonus->getPoint();

		m_ToHit[ATTR_CURRENT]  = min(OUSTERS_MAX_TOHIT, m_ToHit[ATTR_CURRENT] + ToHitBonus);
		m_ToHit[ATTR_MAX]      = min(OUSTERS_MAX_TOHIT, m_ToHit[ATTR_MAX] + ToHitBonus);
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_LIFE_ENERGY ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_LIFE_ENERGY );
		Assert( pRankBonus != NULL );

		int HPBonus = pRankBonus->getPoint();

		m_HP[ATTR_MAX]  = min(OUSTERS_MAX_HP, m_HP[ATTR_MAX] + HPBonus);
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_SOUL_ENERGY ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_SOUL_ENERGY );
		Assert( pRankBonus != NULL );

		int MPBonus = pRankBonus->getPoint();

		m_MP[ATTR_MAX]  = min(OUSTERS_MAX_MP, m_MP[ATTR_MAX] + MPBonus);
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_STONE_MAUL ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_STONE_MAUL );
		Assert( pRankBonus != NULL );

		int DamageBonus = pRankBonus->getPoint();

		m_Damage[ATTR_CURRENT]  = min(OUSTERS_MAX_DAMAGE, m_Damage[ATTR_CURRENT] + DamageBonus);
		m_Damage[ATTR_MAX]      = min(OUSTERS_MAX_DAMAGE, m_Damage[ATTR_MAX] + DamageBonus);
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_SWIFT_ARM ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_SWIFT_ARM );
		Assert( pRankBonus != NULL );

		int AttackSpeedBonus = pRankBonus->getPoint();

		m_AttackSpeed[ATTR_CURRENT]  += AttackSpeedBonus;
		m_AttackSpeed[ATTR_MAX]      += AttackSpeedBonus;
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_FIRE_ENDOW ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_FIRE_ENDOW );
		Assert( pRankBonus != NULL );

		int FireDamageBonus = pRankBonus->getPoint();

		m_FireDamage += FireDamageBonus;
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_WATER_ENDOW ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_WATER_ENDOW );
		Assert( pRankBonus != NULL );

		int WaterDamageBonus = pRankBonus->getPoint();

		m_WaterDamage += WaterDamageBonus;
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_EARTH_ENDOW ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_EARTH_ENDOW );
		Assert( pRankBonus != NULL );

		int EarthDamageBonus = pRankBonus->getPoint();

		m_EarthDamage += EarthDamageBonus;
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_ANTI_ACID_SKIN ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_ANTI_ACID_SKIN );
		Assert( pRankBonus != NULL );

		int ResistBonus = pRankBonus->getPoint();

		m_Resist[MAGIC_DOMAIN_ACID] += ResistBonus;
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_ANTI_BLOODY_SKIN ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_ANTI_BLOODY_SKIN );
		Assert( pRankBonus != NULL );

		int ResistBonus = pRankBonus->getPoint();

		m_Resist[MAGIC_DOMAIN_BLOOD] += ResistBonus;
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_ANTI_CURSE_SKIN ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_ANTI_CURSE_SKIN );
		Assert( pRankBonus != NULL );

		int ResistBonus = pRankBonus->getPoint();

		m_Resist[MAGIC_DOMAIN_CURSE] += ResistBonus;
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_ANTI_POISON_SKIN ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_ANTI_POISON_SKIN );
		Assert( pRankBonus != NULL );

		int ResistBonus = pRankBonus->getPoint();

		m_Resist[MAGIC_DOMAIN_POISON] += ResistBonus;
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_ANTI_SILVER_DAMAGE_SKIN ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_ANTI_SILVER_DAMAGE_SKIN );
		Assert( pRankBonus != NULL );

		int ResistBonus = pRankBonus->getPoint();

		m_SilverResist += ResistBonus;
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_BLESS_OF_NATURE ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_BLESS_OF_NATURE );
		Assert( pRankBonus != NULL );

		int MPAmount = pRankBonus->getPoint();

		m_ConsumeMPRatio -= MPAmount;
	}

	if ( hasRankBonus( RankBonus::RANK_BONUS_MYSTIC_RULE ) )
	{
		RankBonus* pRankBonus = getRankBonus( RankBonus::RANK_BONUS_MYSTIC_RULE );
		Assert( pRankBonus != NULL );

		int LuckBonus = pRankBonus->getPoint();

		m_Luck += LuckBonus;
	}

	// -_- %�� �����Ǵ� ��ų� ���������� ������Ų��.
	if ( isFlag( Effect::EFFECT_CLASS_SHARP_CHAKRAM ) )
	{
		EffectSharpChakram* pEffect = dynamic_cast<EffectSharpChakram*>(findEffect(Effect::EFFECT_CLASS_SHARP_CHAKRAM));

		if ( pEffect != NULL )
		{
			int bonus = pEffect->getBonus();
			m_ToHit[ATTR_CURRENT] += getPercentValue( m_ToHit[ATTR_CURRENT], bonus );
		}
	}

    // HP,MP�� ����ġ�� HP,MP�� �ְ�ġ�� �Ѵ� ����
    // ����ġ�� �ְ�ġ����� set
/*    if (m_HP[ATTR_CURRENT] > m_HP[ATTR_MAX])
    {
        m_HP[ATTR_CURRENT] = m_HP[ATTR_MAX];
    }
	if (m_MP[ATTR_CURRENT] > m_MP[ATTR_MAX])
	{
		m_MP[ATTR_CURRENT] = m_MP[ATTR_MAX];
	}
*/
	// �нú� ��ų �ʱ�ȭ
	bool bCanUsePassive = false;
	if ( hasSkill( SKILL_FIRE_OF_SOUL_STONE ) != NULL )
	{
		SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo( SKILL_FIRE_OF_SOUL_STONE );
		Assert( pSkillInfo != NULL );

		if ( satisfySkillRequire( pSkillInfo ) )
		{
			bCanUsePassive = true;

			m_PassiveSkillMap[SKILL_FIRE_OF_SOUL_STONE].first = true;
			m_PassiveSkillMap[SKILL_FIRE_OF_SOUL_STONE].second = (uint)(( getSTR() / 12.0 ) + ( getDEX() / 3.0 ));
		}
	}

	if ( !bCanUsePassive )
	{
		m_PassiveSkillMap[SKILL_FIRE_OF_SOUL_STONE].first = false;
		m_PassiveSkillMap[SKILL_FIRE_OF_SOUL_STONE].second = 0;
	}

	bCanUsePassive = false;
	if ( hasSkill( SKILL_ICE_OF_SOUL_STONE ) != NULL )
	{
		SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo( SKILL_ICE_OF_SOUL_STONE );
		Assert( pSkillInfo != NULL );

		if ( satisfySkillRequire( pSkillInfo ) )
		{
			bCanUsePassive = true;

			m_PassiveSkillMap[SKILL_ICE_OF_SOUL_STONE].first = true;
			m_PassiveSkillMap[SKILL_ICE_OF_SOUL_STONE].second = min(5,1 + getDEX() / 20) * 10;
		}
	}

	if ( !bCanUsePassive )
	{
		m_PassiveSkillMap[SKILL_ICE_OF_SOUL_STONE].first = false;
		m_PassiveSkillMap[SKILL_ICE_OF_SOUL_STONE].second = 0;
	}

	bCanUsePassive = false;
	if ( hasSkill( SKILL_SAND_OF_SOUL_STONE ) != NULL )
	{
		SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo( SKILL_SAND_OF_SOUL_STONE );
		Assert( pSkillInfo != NULL );

		if ( satisfySkillRequire( pSkillInfo ) )
		{
			bCanUsePassive = true;

			m_PassiveSkillMap[SKILL_SAND_OF_SOUL_STONE].first = true;
			m_PassiveSkillMap[SKILL_SAND_OF_SOUL_STONE].second = (uint)(( getSTR() / 15.0 ) + ( getDEX() / 5.0 ));
		}
	}

	if ( !bCanUsePassive )
	{
		m_PassiveSkillMap[SKILL_SAND_OF_SOUL_STONE].first = false;
		m_PassiveSkillMap[SKILL_SAND_OF_SOUL_STONE].second = 0;
	}

	bCanUsePassive = false;
	if ( hasSkill( SKILL_BLOCK_HEAD ) != NULL )
	{
		SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo( SKILL_BLOCK_HEAD );
		Assert( pSkillInfo != NULL );

		if ( satisfySkillRequire( pSkillInfo ) )
		{
			bCanUsePassive = true;

			m_PassiveSkillMap[SKILL_BLOCK_HEAD].first = true;
			m_PassiveSkillMap[SKILL_BLOCK_HEAD].second = min(4,1 + getDEX() / 30) * 10;
		}
	}

	if ( !bCanUsePassive )
	{
		m_PassiveSkillMap[SKILL_BLOCK_HEAD].first = false;
		m_PassiveSkillMap[SKILL_BLOCK_HEAD].second = 0;
	}

	bCanUsePassive = false;
	if ( hasSkill( SKILL_BLESS_FIRE ) != NULL )
	{
		SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo( SKILL_BLESS_FIRE );
		Assert( pSkillInfo != NULL );

		if ( satisfySkillRequire( pSkillInfo ) )
		{
			bCanUsePassive = true;

			m_PassiveSkillMap[SKILL_BLESS_FIRE].first = true;
			m_PassiveSkillMap[SKILL_BLESS_FIRE].second = (uint)(( getSTR() / 10.0 ) + ( getDEX() / 2.0 ));
		}
	}

	if ( !bCanUsePassive )
	{
		m_PassiveSkillMap[SKILL_BLESS_FIRE].first = false;
		m_PassiveSkillMap[SKILL_BLESS_FIRE].second = 0;
	}

	bCanUsePassive = false;
	if ( hasSkill( SKILL_WATER_SHIELD ) != NULL )
	{
		SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo( SKILL_WATER_SHIELD );
		Assert( pSkillInfo != NULL );

		if ( satisfySkillRequire( pSkillInfo ) )
		{
			bCanUsePassive = true;

			m_PassiveSkillMap[SKILL_WATER_SHIELD].first = true;
			m_PassiveSkillMap[SKILL_WATER_SHIELD].second = 0;
		}
	}

	if ( !bCanUsePassive )
	{
		m_PassiveSkillMap[SKILL_WATER_SHIELD].first = false;
		m_PassiveSkillMap[SKILL_WATER_SHIELD].second = 0;
	}

	bCanUsePassive = false;
	if ( hasSkill( SKILL_SAND_CROSS ) != NULL )
	{
		SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo( SKILL_SAND_CROSS );
		Assert( pSkillInfo != NULL );

		if ( satisfySkillRequire( pSkillInfo ) )
		{
			bCanUsePassive = true;

			m_PassiveSkillMap[SKILL_SAND_CROSS].first = true;
			m_PassiveSkillMap[SKILL_SAND_CROSS].second = (uint)(( getSTR() / 10.0 ) + ( getDEX() / 10.0 ));
		}
	}

	if ( !bCanUsePassive )
	{
		m_PassiveSkillMap[SKILL_SAND_CROSS].first = false;
		m_PassiveSkillMap[SKILL_SAND_CROSS].second = 0;
	}
	
	m_PassiveRatio = getElementalSum();

	for ( int i = WEAR_STONE1; i <= WEAR_STONE3; ++i )
	{
		Item* pItem = getWearItem((WearPart)i);

		if ( pItem == NULL || pItem->getItemClass() != Item::ITEM_CLASS_OUSTERS_STONE ) continue;
		OustersStone* pOustersStone = dynamic_cast<OustersStone*>(pItem);
		Assert( pOustersStone != NULL );

		m_PassiveRatio += pOustersStone->getElemental();
	}

	if ( RaceWarHPBonus > 0 )
	{
		m_HP[ATTR_MAX] = min( OUSTERS_MAX_HP, m_HP[ATTR_MAX] + RaceWarHPBonus );
	}

//	cout << getName() << "�� Luck : " << m_Luck << endl;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// STR, DEX, INT�� ����
// CURRENT = �⺻ ��ġ + ������ ��ġ + ���� ��ġ
// MAX     = �⺻ ��ġ + ������ ��ġ
// BASIC   = �⺻ ��ġ
//
// HP, MP�� ����
// CURRENT = ���� ��ġ
// MAX     = ���� �ƽ�
// BASIC   = �����ۿ� ���� ��ȭ ��ġ
//
// Defense, Protection, ToHit�� ����
// CURRENT = ���� ��ġ
// MAX     = �����ۿ� ���� ��ȭ ��ġ
//
// Damage�� ����
// CURRENT = Min ������
// MAX     = Max ������
// BASIC   = �����ۿ� ���� ��ȭ ��ġ
//////////////////////////////////////////////////////////////////////////////
void Ousters::computeStatOffset()
	throw()
{
	__BEGIN_TRY

	Creature::CreatureClass CClass = getCreatureClass();
	BASIC_ATTR              cur_attr;

	cur_attr.nSTR   = m_STR[ATTR_CURRENT];
	cur_attr.nDEX   = m_DEX[ATTR_CURRENT];
	cur_attr.nINT   = m_INT[ATTR_CURRENT];
	cur_attr.nLevel = m_Level;

	// ���ο��� STR, DEX, INT�� ���� ����� �� ���
	// ������ �Ǵ� ���� ��ġ�� ���Ѵ�. 
	m_HP[ATTR_MAX] = computeHP(CClass, &cur_attr);
	m_HP[ATTR_MAX] += m_HP[ATTR_BASIC];

	m_MP[ATTR_MAX] = computeMP(CClass, &cur_attr);
	m_MP[ATTR_MAX] += m_MP[ATTR_BASIC];

	m_ToHit[ATTR_CURRENT] = computeToHit(CClass, &cur_attr);
	m_ToHit[ATTR_CURRENT] += m_ToHit[ATTR_MAX];

	m_Defense[ATTR_CURRENT] = computeDefense(CClass, &cur_attr);
	m_Defense[ATTR_CURRENT] += m_Defense[ATTR_MAX];

	m_Protection[ATTR_CURRENT] = computeProtection(CClass, &cur_attr);
	m_Protection[ATTR_CURRENT] += m_Protection[ATTR_MAX];

	m_Damage[ATTR_CURRENT] = computeMinDamage(CClass, &cur_attr);
	m_Damage[ATTR_MAX]     = computeMaxDamage(CClass, &cur_attr);

	m_Damage[ATTR_CURRENT] += m_Damage[ATTR_BASIC];
	m_Damage[ATTR_MAX] += m_Damage[ATTR_BASIC];

	m_AttackSpeed[ATTR_CURRENT] = computeAttackSpeed(CClass, &cur_attr);
	m_AttackSpeed[ATTR_CURRENT] += m_AttackSpeed[ATTR_MAX];

	m_CriticalRatio[ATTR_CURRENT] = computeCriticalRatio(CClass, &cur_attr);
	m_CriticalRatio[ATTR_CURRENT] += m_CriticalRatio[ATTR_MAX];
		
	__END_CATCH
}

void Ousters::computeItemStat(Item* pItem)
	throw()
{
	__BEGIN_TRY

//	if (isOustersWeapon(pItem->getItemClass()))
	if ( pItem->getItemClass() == Item::ITEM_CLASS_OUSTERS_CHAKRAM )
	{
		// �������� ���Ⱑ ������ �ӵ� �Ķ����͸� ���Ѵ�.
		ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo(pItem->getItemClass(), pItem->getItemType());
		m_AttackSpeed[ATTR_CURRENT] += pItemInfo->getSpeed();
		m_AttackSpeed[ATTR_MAX]     += pItemInfo->getSpeed();
	}
	
	Elemental_t point = 0;
	ElementalType type = ELEMENTAL_MAX;

	if ( pItem->getItemClass() == Item::ITEM_CLASS_OUSTERS_WRISTLET )
	{
		OustersWristlet* pWristlet = dynamic_cast<OustersWristlet*>(pItem);
		Assert( pWristlet != NULL );

		point = pWristlet->getElemental();
		type = pWristlet->getElementalType();
	}
	else if ( pItem->getItemClass() == Item::ITEM_CLASS_OUSTERS_STONE )
	{
		OustersStone* pStone = dynamic_cast<OustersStone*>(pItem);
		Assert( pStone != NULL );

		point = pStone->getElemental();
		type = pStone->getElementalType();
	}

	if ( point != 0 && type != ELEMENTAL_MAX )
	{
		switch ( type )
		{
			case ELEMENTAL_FIRE:
				m_ElementalFire += point;
				break;
			case ELEMENTAL_WATER:
				m_ElementalWater += point;
				break;
			case ELEMENTAL_EARTH:
				m_ElementalEarth += point;
				break;
			case ELEMENTAL_WIND:
				m_ElementalWind += point;
				break;
			default:
				break;
		}
	}

	m_Protection[ATTR_CURRENT] += pItem->getProtectionBonus();
	m_Protection[ATTR_MAX]     += pItem->getProtectionBonus();

	m_Defense[ATTR_CURRENT] += pItem->getDefenseBonus();
	m_Defense[ATTR_MAX]     += pItem->getDefenseBonus();

	m_ToHit[ATTR_CURRENT] += pItem->getToHitBonus();
	m_ToHit[ATTR_MAX] += pItem->getToHitBonus();
	
	m_Luck	+= pItem->getLuck();

//	if (pItem->getOptionType()) computeOptionStat(pItem);
	// �ΰ����� �ɼǵ�
	const list<OptionType_t>& optionType = pItem->getOptionTypeList();
	list<OptionType_t>::const_iterator itr;
	for (itr=optionType.begin(); itr!=optionType.end(); itr++)
	{
		computeOptionStat( *itr );
	}

	// Item ��ü�� defaultOption� ������Ų��.
	const list<OptionType_t>& defaultOptions = pItem->getDefaultOptions();
	list<OptionType_t>::const_iterator iOptions;

	for (iOptions=defaultOptions.begin(); iOptions!=defaultOptions.end(); iOptions++)
	{
		computeOptionStat( *iOptions );
	}

	__END_CATCH
}

void Ousters::computeOptionStat(Item* pItem)
	throw()
{
	__BEGIN_TRY

	// �ΰ����� �ɼǵ�
	const list<OptionType_t>& optionType = pItem->getOptionTypeList();
	list<OptionType_t>::const_iterator itr;
	for (itr=optionType.begin(); itr!=optionType.end(); itr++)
	{
		computeOptionStat( *itr );
	}

	// Item ��ü�� defaultOption� ������Ų��.
	const list<OptionType_t>& defaultOptions = pItem->getDefaultOptions();
	list<OptionType_t>::const_iterator iOptions;

	for (iOptions=defaultOptions.begin(); iOptions!=defaultOptions.end(); iOptions++)
	{
		computeOptionStat( *iOptions );
	}

	__END_CATCH
}

void Ousters::computeOptionClassStat(OptionClass OClass, int PlusPoint)
{
	switch (OClass)
	{
		case OPTION_STR:
			m_STR[ATTR_CURRENT] += PlusPoint;
			m_STR[ATTR_MAX]     += PlusPoint;
			computeStatOffset();
			break;
		case OPTION_DEX:
			m_DEX[ATTR_CURRENT] += PlusPoint;
			m_DEX[ATTR_MAX]     += PlusPoint;
			computeStatOffset();
			break;
		case OPTION_INT:
			m_INT[ATTR_CURRENT] += PlusPoint;
			m_INT[ATTR_MAX]     += PlusPoint;
			computeStatOffset();
			break;
		case OPTION_HP:
			m_HP[ATTR_MAX]   += PlusPoint;
			m_HP[ATTR_BASIC] += PlusPoint;
			break;
		case OPTION_MP:
			m_MP[ATTR_MAX]   += PlusPoint;
			m_MP[ATTR_BASIC] += PlusPoint;
			break;
		case OPTION_HP_STEAL:
			m_HPStealAmount += PlusPoint;
			break;
		case OPTION_MP_STEAL:
			m_MPStealAmount += PlusPoint;
			break;
		case OPTION_HP_REGEN:
			m_HPRegen += PlusPoint;
			break;
		case OPTION_MP_REGEN:
			m_MPRegen += PlusPoint;
			break;
		case OPTION_TOHIT:
			m_ToHit[ATTR_CURRENT] += PlusPoint;
			m_ToHit[ATTR_MAX]     += PlusPoint;
			break;
		case OPTION_DEFENSE:
			m_Defense[ATTR_CURRENT] += PlusPoint;
			m_Defense[ATTR_MAX]     += PlusPoint;
			break;
		case OPTION_DAMAGE:
			m_Damage[ATTR_CURRENT] += PlusPoint;
			m_Damage[ATTR_MAX]     += PlusPoint;
			m_Damage[ATTR_BASIC]   += PlusPoint;
			break;
		case OPTION_PROTECTION:
			m_Protection[ATTR_CURRENT] += PlusPoint;
			m_Protection[ATTR_MAX]     += PlusPoint;
			break;
		case OPTION_POISON:
			m_Resist[MAGIC_DOMAIN_POISON] += PlusPoint;
			break;
		case OPTION_ACID:
			m_Resist[MAGIC_DOMAIN_ACID] += PlusPoint;
			break;
		case OPTION_CURSE:
			m_Resist[MAGIC_DOMAIN_CURSE] += PlusPoint;
			break;
		case OPTION_BLOOD:
			m_Resist[MAGIC_DOMAIN_BLOOD] += PlusPoint;
			break;
		case OPTION_VISION:
			break;
		case OPTION_ATTACK_SPEED:
			m_AttackSpeed[ATTR_CURRENT] += PlusPoint;
			m_AttackSpeed[ATTR_MAX]     += PlusPoint;
			break;
		case OPTION_CRITICAL_HIT:
			m_CriticalRatio[ATTR_CURRENT] += PlusPoint;
			m_CriticalRatio[ATTR_MAX]     += PlusPoint;
			break;

		case OPTION_ALL_ATTR:
			m_STR[ATTR_CURRENT] += PlusPoint;
			m_STR[ATTR_MAX]     += PlusPoint;

			m_DEX[ATTR_CURRENT] += PlusPoint;
			m_DEX[ATTR_MAX]     += PlusPoint;

			m_INT[ATTR_CURRENT] += PlusPoint;
			m_INT[ATTR_MAX]     += PlusPoint;

			computeStatOffset();
			break;

		case OPTION_ALL_RES:
			m_Resist[MAGIC_DOMAIN_POISON] += PlusPoint;
			m_Resist[MAGIC_DOMAIN_ACID] += PlusPoint;
			m_Resist[MAGIC_DOMAIN_CURSE] += PlusPoint;
			m_Resist[MAGIC_DOMAIN_BLOOD] += PlusPoint;
			break;

		case OPTION_LUCK:
			m_Luck += PlusPoint;
			break;

		case OPTION_CONSUME_MP:
			m_ConsumeMPRatio = PlusPoint;
			break;

		case OPTION_MAGIC_DAMAGE:
			m_MagicBonusDamage = PlusPoint;
			break;

		case OPTION_PHYSIC_DAMAGE:
			m_PhysicBonusDamage = PlusPoint;
			break;

		case OPTION_GAMBLE_PRICE:
			m_GamblePriceRatio = PlusPoint;
			break;
			
		case OPTION_POTION_PRICE:
			m_PotionPriceRatio = PlusPoint;
			break;

		default:
			break;
	}

}

void Ousters::computeOptionStat(OptionType_t OptionType)
	throw()
{
	__BEGIN_TRY

	OptionInfo*   pOptionInfo   = g_pOptionInfoManager->getOptionInfo(OptionType);
	computeOptionClassStat( pOptionInfo->getClass(), pOptionInfo->getPlusPoint() );
/*	OptionClass   OClass        = pOptionInfo->getClass();

	switch (OClass)
	{
		case OPTION_STR:
			m_STR[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_STR[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			computeStatOffset();
			break;
		case OPTION_DEX:
			m_DEX[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_DEX[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			computeStatOffset();
			break;
		case OPTION_INT:
			m_INT[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_INT[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			computeStatOffset();
			break;
		case OPTION_HP:
			m_HP[ATTR_MAX]   += pOptionInfo->getPlusPoint();
			m_HP[ATTR_BASIC] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_MP:
			m_MP[ATTR_MAX]   += pOptionInfo->getPlusPoint();
			m_MP[ATTR_BASIC] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_HP_STEAL:
			m_HPStealAmount += pOptionInfo->getPlusPoint();
			break;
		case OPTION_MP_STEAL:
			m_MPStealAmount += pOptionInfo->getPlusPoint();
			break;
		case OPTION_HP_REGEN:
			m_HPRegen += pOptionInfo->getPlusPoint();
			break;
		case OPTION_MP_REGEN:
			m_MPRegen += pOptionInfo->getPlusPoint();
			break;
		case OPTION_TOHIT:
			m_ToHit[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_ToHit[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;
		case OPTION_DEFENSE:
			m_Defense[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_Defense[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;
		case OPTION_DAMAGE:
			m_Damage[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_Damage[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			m_Damage[ATTR_BASIC]   += pOptionInfo->getPlusPoint();
			break;
		case OPTION_PROTECTION:
			m_Protection[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_Protection[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;
		case OPTION_POISON:
			m_Resist[MAGIC_DOMAIN_POISON] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_ACID:
			m_Resist[MAGIC_DOMAIN_ACID] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_CURSE:
			m_Resist[MAGIC_DOMAIN_CURSE] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_BLOOD:
			m_Resist[MAGIC_DOMAIN_BLOOD] += pOptionInfo->getPlusPoint();
			break;
		case OPTION_VISION:
			break;
		case OPTION_ATTACK_SPEED:
			m_AttackSpeed[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_AttackSpeed[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;
		case OPTION_CRITICAL_HIT:
			m_CriticalRatio[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_CriticalRatio[ATTR_MAX]     += pOptionInfo->getPlusPoint();
			break;

		case OPTION_ALL_ATTR:
			m_STR[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_STR[ATTR_MAX]     += pOptionInfo->getPlusPoint();

			m_DEX[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_DEX[ATTR_MAX]     += pOptionInfo->getPlusPoint();

			m_INT[ATTR_CURRENT] += pOptionInfo->getPlusPoint();
			m_INT[ATTR_MAX]     += pOptionInfo->getPlusPoint();

			computeStatOffset();
			break;

		case OPTION_ALL_RES:
			m_Resist[MAGIC_DOMAIN_POISON] += pOptionInfo->getPlusPoint();
			m_Resist[MAGIC_DOMAIN_ACID] += pOptionInfo->getPlusPoint();
			m_Resist[MAGIC_DOMAIN_CURSE] += pOptionInfo->getPlusPoint();
			m_Resist[MAGIC_DOMAIN_BLOOD] += pOptionInfo->getPlusPoint();
			break;

		case OPTION_LUCK:
			m_Luck += pOptionInfo->getPlusPoint();
			break;

		case OPTION_CONSUME_MP:
			m_ConsumeMPRatio = pOptionInfo->getPlusPoint();
			break;

		case OPTION_MAGIC_DAMAGE:
			m_MagicBonusDamage = pOptionInfo->getPlusPoint();
			break;

		case OPTION_PHYSIC_DAMAGE:
			m_PhysicBonusDamage = pOptionInfo->getPlusPoint();
			break;

		case OPTION_GAMBLE_PRICE:
			m_GamblePriceRatio = pOptionInfo->getPlusPoint();
			break;
			
		case OPTION_POTION_PRICE:
			m_PotionPriceRatio = pOptionInfo->getPlusPoint();
			break;

		default:
			break;
	}*/

	__END_CATCH
}

void Ousters::addModifyInfo(const OUSTERS_RECORD& prev, ModifyInfo& pkt) const
	throw()
{
	__BEGIN_TRY

	if (prev.pSTR[ATTR_CURRENT] != m_STR[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_STR, m_STR[ATTR_CURRENT]);
	if (prev.pSTR[ATTR_MAX    ] != m_STR[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_STR,     m_STR[ATTR_MAX]);
	if (prev.pSTR[ATTR_BASIC  ] != m_STR[ATTR_BASIC  ]) pkt.addShortData(MODIFY_BASIC_STR,   m_STR[ATTR_BASIC]);

	if (prev.pDEX[ATTR_CURRENT] != m_DEX[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_DEX, m_DEX[ATTR_CURRENT]);
	if (prev.pDEX[ATTR_MAX    ] != m_DEX[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_DEX,     m_DEX[ATTR_MAX]);
	if (prev.pDEX[ATTR_BASIC  ] != m_DEX[ATTR_BASIC  ]) pkt.addShortData(MODIFY_BASIC_DEX,   m_DEX[ATTR_BASIC]);

	if (prev.pINT[ATTR_CURRENT] != m_INT[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_INT, m_INT[ATTR_CURRENT]);
	if (prev.pINT[ATTR_MAX    ] != m_INT[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_INT,     m_INT[ATTR_MAX]);
	if (prev.pINT[ATTR_BASIC  ] != m_INT[ATTR_BASIC  ]) pkt.addShortData(MODIFY_BASIC_INT,   m_INT[ATTR_BASIC]);

	if (prev.pHP[ATTR_CURRENT] != m_HP[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_HP, m_HP[ATTR_CURRENT]);
	if (prev.pHP[ATTR_MAX    ] != m_HP[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_HP,     m_HP[ATTR_MAX]);

	if (prev.pMP[ATTR_CURRENT] != m_MP[ATTR_CURRENT]) pkt.addShortData(MODIFY_CURRENT_MP, m_MP[ATTR_CURRENT]);
	if (prev.pMP[ATTR_MAX    ] != m_MP[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_MP,     m_MP[ATTR_MAX]);

	if (prev.pDamage[ATTR_CURRENT] != m_Damage[ATTR_CURRENT]) pkt.addShortData(MODIFY_MIN_DAMAGE, m_Damage[ATTR_CURRENT]);
	if (prev.pDamage[ATTR_MAX    ] != m_Damage[ATTR_MAX    ]) pkt.addShortData(MODIFY_MAX_DAMAGE, m_Damage[ATTR_MAX]);

	if (prev.Defense     != m_Defense[ATTR_CURRENT])     pkt.addShortData(MODIFY_DEFENSE,      m_Defense[ATTR_CURRENT]);
	if (prev.Protection  != m_Protection[ATTR_CURRENT])  pkt.addShortData(MODIFY_PROTECTION,   m_Protection[ATTR_CURRENT]);
	if (prev.ToHit       != m_ToHit[ATTR_CURRENT])       pkt.addShortData(MODIFY_TOHIT,        m_ToHit[ATTR_CURRENT]);
	if (prev.AttackSpeed != m_AttackSpeed[ATTR_CURRENT]) pkt.addShortData(MODIFY_ATTACK_SPEED, m_AttackSpeed[ATTR_CURRENT]);

	// by sigi. 2002.9.10
	if (prev.Rank != getRank())
	{
		pkt.addShortData(MODIFY_RANK, getRank());
		pkt.addLongData(MODIFY_RANK_EXP, getRankGoalExp());
	}

	__END_CATCH
}

void Ousters::sendModifyInfo(const OUSTERS_RECORD& prev) const
	throw()
{
	__BEGIN_TRY

	GCModifyInformation gcModifyInformation;
	addModifyInfo(prev, gcModifyInformation);
	m_pPlayer->sendPacket(&gcModifyInformation);

	__END_CATCH	
}

void Ousters::initAllStatAndSend()
{
	OUSTERS_RECORD prev;
	getOustersRecord(prev);
	initAllStat();
	sendModifyInfo(prev);
}


