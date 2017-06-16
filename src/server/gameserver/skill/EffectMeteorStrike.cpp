//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectMeteorStrike.cpp
// Written by  :
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectMeteorStrike.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Monster.h"
#include "GamePlayer.h"
#include "SkillUtil.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCSkillToObjectOK2.h"
#include "Gpackets/GCSkillToObjectOK4.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectMeteorStrike::EffectMeteorStrike(Zone* pZone, ZoneCoord_t zoneX, ZoneCoord_t zoneY, bool bPlayer) 
	throw(Error)
{
	__BEGIN_TRY

	m_pZone = pZone;
	m_X = zoneX;
	m_Y = zoneY;
	m_Damage = 0;
	m_UserObjectID = 0;
	m_bPlayer = bPlayer;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectMeteorStrike::affect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectMeteorStrike" << "affect BEGIN" << endl;

	//setNextTime(m_Delay);

	//cout << "EffectMeteorStrike" << "affect END" << endl;

	__END_CATCH 
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectMeteorStrike::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectMeteorStrike::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectMeteorStrike::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectMeteorStrike" << "unaffect BEGIN" << endl;
	Assert(m_pZone != NULL);

	// ����Ʈ�� �� ũ���ĸ� ����´�.
	// !! �� ����� ���� ����Ƿ� NULL �� �� �� �ִ�.
	Creature* pCastCreature = NULL;
	if ( m_bPlayer )
	{
		pCastCreature = m_pZone->getCreature( m_UserObjectID );
		if ( pCastCreature == NULL )
		{
			Tile& tile = m_pZone->getTile(m_X, m_Y);
			tile.deleteEffect(m_ObjectID);
			return;
		}
	}

	VSRect rect(0, 0, m_pZone->getWidth()-1, m_pZone->getHeight()-1);

	// ���� ����Ʈ�� �پ��ִ� Ÿ��� �޾ƿ´�.
	// �߽�Ÿ�� + ���÷��� Ÿ��
	for (int x=-2; x<=2; x++)
	{
		for (int y=-2; y<=2; y++)
		{
			int X = m_X + x;
			int Y = m_Y + y;

			if (!rect.ptInRect(X, Y)) continue;
			Tile& tile = m_pZone->getTile(X, Y);

			int Damage = 0;
			int splash = max(abs(x), abs(y));

			// ����� 100%
			if ( m_bPlayer )
			{
				if ( splash == 0 )
				{
					Damage = m_Damage;
				}
				else if ( splash == 1 )
				{
					Damage = getPercentValue( m_Damage, 85 );
				}
				else
				{
					Damage = getPercentValue( m_Damage, 70 );
				}
			}
			else
			{
				// ������� 50% damage
				if ( splash != 0 ) Damage = m_Damage >> splash;
			}

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

					// �ڽ�� ���� �ʴ´�
					// �������� üũ. by sigi. 2002.9.5
					if (pCreature->getObjectID()==m_UserObjectID
						|| pCreature->isFlag(Effect::EFFECT_CLASS_NO_DAMAGE)
						|| pCreature->isFlag(Effect::EFFECT_CLASS_COMA)
						|| !checkZoneLevelToHitTarget( pCreature )
					)
					{
						continue;
					}

					//GCModifyInformation gcMI;
					GCModifyInformation gcAttackerMI;
					GCSkillToObjectOK2 gcSkillToObjectOK2;

					if (pCreature->isSlayer()) 
					{
						Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

						::setDamage( pSlayer, Damage, pCastCreature, SKILL_METEOR_STRIKE, &gcSkillToObjectOK2, &gcAttackerMI);

/*						Player* pPlayer = pSlayer->getPlayer();
						Assert(pPlayer != NULL);
						pPlayer->sendPacket(&gcMI);*/

					} 
					else if (pCreature->isVampire())
					{
						// �����̾ ������� ���� �����̾��� �߽� Ÿ��� ����ϰ��� ���� �ʴ´�.
						if ( m_bPlayer )// && splash != 0 )
							continue;

						Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);

						::setDamage( pVampire, Damage, pCastCreature, SKILL_METEOR_STRIKE, &gcSkillToObjectOK2, &gcAttackerMI );

/*						Player* pPlayer = pVampire->getPlayer();
						Assert(pPlayer != NULL);
						pPlayer->sendPacket(&gcMI);*/
					}
					else if (pCreature->isOusters())
					{
						Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);

						::setDamage( pOusters, Damage, pCastCreature, SKILL_METEOR_STRIKE, &gcSkillToObjectOK2, &gcAttackerMI );

/*						Player* pPlayer = pOusters->getPlayer();
						Assert(pPlayer != NULL);
						pPlayer->sendPacket(&gcMI);*/
					}
					else if (pCreature->isMonster())
					{
						Monster* pMonster = dynamic_cast<Monster*>(pCreature);

						::setDamage( pMonster, Damage, pCastCreature, SKILL_METEOR_STRIKE, NULL, &gcAttackerMI );

						if ( pCastCreature != NULL ) pMonster->addEnemy( pCastCreature );
					}

					// ���밡 �׾��ٸ� ����ġ�� �÷��ش�.
					if ( pCreature->isDead() )
					{
						if ( pCastCreature != NULL && pCastCreature->isVampire() )
						{
							Vampire* pVampire = dynamic_cast<Vampire*>(pCastCreature);
							Assert( pVampire != NULL );

							int exp = computeCreatureExp(pCreature, KILL_EXP);
							shareVampExp(pVampire, exp, gcAttackerMI);
							computeAlignmentChange( pCreature, Damage, pCastCreature, &gcSkillToObjectOK2, &gcAttackerMI );

							pVampire->getPlayer()->sendPacket( &gcAttackerMI );
						}
					}

					// user���״� �´� ����� �����ش�.
					if (pCreature->isPC())
					{
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
					// setDamage �� �ҷ��� ó���Ѵ�. �ּ�ó��
					// by bezz. 2002.12.31
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

	//cout << "EffectMeteorStrike" << "unaffect END" << endl;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectMeteorStrike::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "EffectMeteorStrike("
		<< "ObjectID:" << getObjectID()
		<< ")";

	return msg.toString();

	__END_CATCH

}

EffectMeteorStrikeLoader* g_pEffectMeteorStrikeLoader = NULL;
