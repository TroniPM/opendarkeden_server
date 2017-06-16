//////////////////////////////////////////////////////////////////////////////
// Filename    : DestructionSpear.cpp
// Written by  : elca@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "DestructionSpear.h"
#include "SimpleMeleeSkill.h"
#include "RankBonus.h"
#include "Gpackets/GCAddEffect.h"
#include "EffectDestructionSpear.h"

//////////////////////////////////////////////////////////////////////////////
// 뱀파이어 오브젝트 핸들러
//////////////////////////////////////////////////////////////////////////////
void DestructionSpear::execute(Ousters* pOusters, ObjectID_t TargetObjectID, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	__BEGIN_TRY

	Zone* pZone = pOusters->getZone();
	Assert( pZone != NULL );

	Creature* pTargetCreature = pZone->getCreature( TargetObjectID );

	int targetLevel = 0;

	if (pTargetCreature==NULL
		|| pTargetCreature->isFlag(Effect::EFFECT_CLASS_NO_DAMAGE) // by sigi. 2002.10.30
		|| pTargetCreature->isNPC())
	{
		executeSkillFailException(pOusters, getSkillType());
		return;
	}

	if ( pTargetCreature->isSlayer() )
	{
		Slayer* pSlayer = dynamic_cast<Slayer*>(pTargetCreature);
		targetLevel = pSlayer->getHighestSkillDomainLevel();
	}
	else
	{
		targetLevel = pTargetCreature->getLevel();
	}

	SkillInput input(pOusters, pOustersSkillSlot);
	SkillOutput output;
	computeOutput(input, output);

	Item* pWeapon = pOusters->getWearItem( Ousters::WEAR_RIGHTHAND );
	if ( pWeapon == NULL )
	{
		executeSkillFailException( pOusters, getSkillType() );
		return;
	}

	SIMPLE_SKILL_INPUT param;
	param.SkillType     = getSkillType();
	param.SkillDamage   = output.Damage;

	param.Delay         = output.Delay;
	param.ItemClass     = Item::ITEM_CLASS_OUSTERS_CHAKRAM;
	param.STRMultiplier = 0;
	param.DEXMultiplier = 0;
	param.INTMultiplier = 0;
	param.bMagicHitRoll = false;
	param.bMagicDamage  = false;
	param.bAdd = true;

	SIMPLE_SKILL_OUTPUT result;

	g_SimpleMeleeSkill.execute(pOusters, TargetObjectID, pOustersSkillSlot, param, result, CEffectID );

	if ( !pTargetCreature->isFlag( Effect::EFFECT_CLASS_DESTRUCTION_SPEAR ) && result.bSuccess )
	{
		int ratio = 0;

		if ( input.SkillLevel <= 15 )
		{
			ratio = max(20, min(80, (int)( pOusters->getLevel() + (input.SkillLevel * 8.0 / 3.0) - targetLevel ) ));
		}
		else
		{
			ratio = max(20, min(80, (int)( pOusters->getLevel() + 20.0 + (input.SkillLevel * 4.0 / 3.0) - targetLevel ) ));
		}

		if ( rand() % 100 < ratio )
		{

			EffectDestructionSpear* pEffect = new EffectDestructionSpear( pTargetCreature );
			Assert( pEffect != NULL );

			pEffect->setDamage( 2 + ( input.SkillLevel/3 ) );
			pEffect->setNextTime(20);
			pEffect->setCasterID( pOusters->getObjectID() );
			pEffect->setDeadline( output.Duration );

			pTargetCreature->setFlag( Effect::EFFECT_CLASS_DESTRUCTION_SPEAR );
			pTargetCreature->addEffect( pEffect );

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID( TargetObjectID );
			gcAddEffect.setEffectID( pEffect->getSendEffectClass() );
			gcAddEffect.setDuration( output.Duration );

			pZone->broadcastPacket( pTargetCreature->getX(), pTargetCreature->getY(), &gcAddEffect );
		}
	}

	__END_CATCH
}

DestructionSpear g_DestructionSpear;
