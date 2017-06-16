//////////////////////////////////////////////////////////////////////////////
// Filename    : RankBonus.h
// Written by  :
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __RANK_BONUS_H__
#define __RANK_BONUS_H__

#include "Types.h"


class RankBonus
{
public:
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	enum RankBonusType
	{
		RANK_BONUS_DEADLY_SPEAR,
		RANK_BONUS_BEHEMOTH_ARMOR,
		RANK_BONUS_DRAGON_EYE,
		RANK_BONUS_IMMORTAL_HEART,
		RANK_BONUS_RELIANCE_BRAIN,
		RANK_BONUS_SLAYING_KNIFE,
		RANK_BONUS_HAWK_WING,
		RANK_BONUS_HOLY_SMASHING,
		RANK_BONUS_SOUL_SMASHING,
		RANK_BONUS_SAPPHIRE_BLESS,
		RANK_BONUS_RUBY_BLESS,
		RANK_BONUS_DIAMOND_BLESS,
		RANK_BONUS_EMERALD_BLESS,
		RANK_BONUS_MAGIC_BRAIN,
		RANK_BONUS_WIGHT_HAND,
		RANK_BONUS_SEIREN_HAND,
		RANK_BONUS_FORTUNE_HAND,

		RANK_BONUS_IMMORTAL_BLOOD,
		RANK_BONUS_BEHEMOTH_SKIN,
		RANK_BONUS_SAFE_ROBE,
		RANK_BONUS_CROW_WING,
		RANK_BONUS_WISDOM_OF_BLOOD,
		RANK_BONUS_TIGER_NAIL,
		RANK_BONUS_URANUS_BLESS,
		RANK_BONUS_DISRUPTION_STORM,
		RANK_BONUS_WIDE_STORM,
		RANK_BONUS_KNOWLEDGE_OF_POISON,
		RANK_BONUS_KNOWLEDGE_OF_ACID,
		RANK_BONUS_KNOWLEDGE_OF_CURSE,
		RANK_BONUS_KNOWLEDGE_OF_BLOOD,
		RANK_BONUS_KNOWLEDGE_OF_INNATE,
		RANK_BONUS_KNOWLEDGE_OF_SUMMON,
		RANK_BONUS_WISDOM_OF_SWAMP,
		RANK_BONUS_WISDOM_OF_SILENCE,
		RANK_BONUS_WISDOM_OF_DARKNESS,
		RANK_BONUS_WIDE_DARKNESS,

		RANK_BONUS_WOOD_SKIN,
		RANK_BONUS_WIND_SENSE,
		RANK_BONUS_HOMING_EYE,
		RANK_BONUS_LIFE_ENERGY,
		RANK_BONUS_SOUL_ENERGY,
		RANK_BONUS_STONE_MAUL,
		RANK_BONUS_SWIFT_ARM,
		RANK_BONUS_FIRE_ENDOW,
		RANK_BONUS_WATER_ENDOW,
		RANK_BONUS_EARTH_ENDOW,
		RANK_BONUS_ANTI_ACID_SKIN,
		RANK_BONUS_ANTI_BLOODY_SKIN,
		RANK_BONUS_ANTI_CURSE_SKIN,
		RANK_BONUS_ANTI_POISON_SKIN,
		RANK_BONUS_ANTI_SILVER_DAMAGE_SKIN,
		RANK_BONUS_BLESS_OF_NATURE,
		RANK_BONUS_LIFE_ABSORB,
		RANK_BONUS_SOUL_ABSORB,
		RANK_BONUS_MYSTIC_RULE,

		RANK_BONUS_MAX
	};

public:
	RankBonus() throw();
	RankBonus( DWORD type, DWORD point, Rank_t rank ) throw();
	~RankBonus() throw();

public:
	DWORD getType() const throw() { return m_Type; }
	void setType( DWORD type ) throw() { m_Type = type; }

	DWORD getPoint() const throw() { return m_Point; }
	void setPoint( DWORD point ) throw() { m_Point = point; }

	Rank_t getRank() const throw() { return m_Rank; }
	void setRank( Rank_t rank ) throw() { m_Rank = rank; }

protected:
	DWORD m_Type;
	DWORD m_Point;
	Rank_t m_Rank;

};

#endif
