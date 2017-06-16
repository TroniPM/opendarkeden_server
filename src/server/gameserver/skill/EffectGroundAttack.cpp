//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectGroundAttack.cpp
// Written by  :
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectGroundAttack.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "Monster.h"
#include "GamePlayer.h"
#include "SkillUtil.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCSkillToObjectOK2.h"
#include "Gpackets/GCSkillToObjectOK4.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectGroundAttack::EffectGroundAttack(Zone* pZone, ZoneCoord_t zoneX, ZoneCoord_t zoneY) 
	throw(Error)
{
	__BEGIN_TRY

	m_pZone = pZone;
	m_X = zoneX;
	m_Y = zoneY;
	m_DamagePercent = 0;
//	m_CasterName = "";
	m_UserObjectID = 0;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGroundAttack::affect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectGroundAttack" << "affect BEGIN" << endl;

	//setNextTime(m_Delay);

	//cout << "EffectGroundAttack" << "affect END" << endl;

	__END_CATCH 
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGroundAttack::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGroundAttack::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGroundAttack::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectGroundAttack" << "unaffect BEGIN" << endl;
	Assert(m_pZone != NULL);

	// �����ڸ� ����´�.
	// !! �̹� �� ����� �� ����Ƿ� NULL�� �� �� �մ�.
	// by bezz. 2003.1.4
	Creature* pCastCreature = m_pZone->getCreature( m_UserObjectID );

	int Damage;
	int DamageLimit = 0xFFFF; //500;

	HP_t MaxHP = 0;

	VSRect rect(0, 0, m_pZone->getWidth()-1, m_pZone->getHeight()-1);

	// ���� ����Ʈ�� �پ��ִ� Ÿ��� �޾ƿ´�.
	// �߽�Ÿ�� + ���÷��� Ÿ��
	for (int x=-1; x<=1; x++)
	{
		for (int y=-1; y<=1; y++)
		{
			int X = m_X + x;
			int Y = m_Y + y;

			if (!rect.ptInRect(X, Y)) continue;
			Tile& tile = m_pZone->getTile(X, Y);

			// ����� 100%
			// ������� 50% damage
			bool bCenterEffect = (x==0 && y==0);
			int	DamagePercent = (bCenterEffect? m_DamagePercent : (m_DamagePercent>>1));

			// Ÿ�� �ȿ� ����ϴ� ����Ʈ��� �˻��Ѵ�.
			const list<Object*>& oList = tile.getObjectList();
			list<Object*>::const_iterator itr = oList.begin();
			for (; itr != oList.end(); itr++) 
			{
				Assert(*itr != NULL);

				Object* pObject = *itr;
				Assert(pObject != NULL);

				if (pObject->getObjectClass() == Object::OBJECT_CLASS_CREATURE)
				{
					Creature* pCreature = dynamic_cast<Creature*>(pObject);
					Assert(pCreature != NULL);

					// �������� üũ. by sigi. 2002.9.5
					if (pCreature->isFlag(Effect::EFFECT_CLASS_NO_DAMAGE))
					{
						continue;
					}

					if (pCreature->isSlayer()) 
					{
						Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

						MaxHP = pSlayer->getHP(ATTR_MAX);
						Damage = min(DamageLimit, MaxHP*DamagePercent/100);

						GCModifyInformation gcMI;
						::setDamage( pSlayer, Damage, pCastCreature, SKILL_GROUND_ATTACK, &gcMI );

						Player* pPlayer = pSlayer->getPlayer();
						Assert(pPlayer != NULL);
						pPlayer->sendPacket(&gcMI);
					} 
					else if (pCreature->isVampire())
					{
						Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);

						MaxHP = pVampire->getHP(ATTR_MAX);
						Damage = min(DamageLimit, MaxHP*DamagePercent/100);

						GCModifyInformation gcMI;
						::setDamage( pVampire, Damage, pCastCreature, SKILL_GROUND_ATTACK, &gcMI );

						Player* pPlayer = pVampire->getPlayer();
						Assert(pPlayer != NULL);
						pPlayer->sendPacket(&gcMI);
					}
					else if (pCreature->isOusters())
					{
						Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);

						MaxHP = pOusters->getHP(ATTR_MAX);
						Damage = min(DamageLimit, MaxHP*DamagePercent/100);

						GCModifyInformation gcMI;
						::setDamage( pOusters, Damage, pCastCreature, SKILL_GROUND_ATTACK, &gcMI );

						Player* pPlayer = pOusters->getPlayer();
						Assert(pPlayer != NULL);
						pPlayer->sendPacket(&gcMI);
					}
					else if (pCreature->isMonster())
					{
						Monster* pMonster = dynamic_cast<Monster*>(pCreature);

						MaxHP = pMonster->getHP(ATTR_MAX);
						Damage = min(DamageLimit, MaxHP*DamagePercent/100);

						::setDamage( pMonster, Damage, pCastCreature, SKILL_GROUND_ATTACK );
					}

					// user���״� �´� ����� �����ش�.
					if (pCreature->isPC())
					{
						GCSkillToObjectOK2 gcSkillToObjectOK2;
						gcSkillToObjectOK2.setObjectID( 1 );	// �ǹ� ����.
						gcSkillToObjectOK2.setSkillType( SKILL_ATTACK_MELEE );
						gcSkillToObjectOK2.setDuration(0);
						pCreature->getPlayer()->sendPacket(&gcSkillToObjectOK2);
					}

					GCSkillToObjectOK4 gcSkillToObjectOK4;
					gcSkillToObjectOK4.setTargetObjectID( pCreature->getObjectID() );
					gcSkillToObjectOK4.setSkillType( SKILL_ATTACK_MELEE );
					gcSkillToObjectOK4.setDuration(0);
					m_pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcSkillToObjectOK4, pCreature);

					// m_CasterName�� pCreature�� ���� ������ KillCount ó��
					// by sigi. 2002.8.31
/*					if (pCreature->isDead())
					{
						Creature* pAttacker = m_pZone->getCreature( m_CasterName );

						if (pAttacker!=NULL)
						{ 
							affectKillCount(pAttacker, pCreature);
						}
					}*/
				}
			}
		}
	}

	Tile& tile = m_pZone->getTile(m_X, m_Y);
	tile.deleteEffect(m_ObjectID);

	//cout << "EffectGroundAttack" << "unaffect END" << endl;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectGroundAttack::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "EffectGroundAttack("
		<< "ObjectID:" << getObjectID()
		<< ")";

	return msg.toString();

	__END_CATCH

}

EffectGroundAttackLoader* g_pEffectGroundAttackLoader = NULL;
