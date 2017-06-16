//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectAcidSwamp.cpp
// Written by  :
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "DB.h"
#include "EffectAcidSwamp.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Monster.h"
#include "GamePlayer.h"
#include "SkillUtil.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectAcidSwamp::EffectAcidSwamp(Zone* pZone, ZoneCoord_t zoneX, ZoneCoord_t zoneY) 
	throw(Error)
{
	__BEGIN_TRY

	m_pZone = pZone;
	m_X = zoneX;
	m_Y = zoneY;
	m_UserObjectID = 0;
	m_bVampire = false;
	m_bForce = false;

	m_TargetObjectID[0] = 0;
	m_TargetObjectID[1] = 0;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectAcidSwamp::affect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectAcidSwamp" << "affect BEGIN" << endl;
	
	Assert(m_pZone != NULL);

	// ����Ʈ �����ڸ� ����´�.
	// ��� ��� �� ����Ƿ� NULL �� �� �� �ִ�.
	Creature * pCastCreature = m_pZone->getCreature( m_UserObjectID );

	if ( pCastCreature == NULL && !isForce() )
	{
		setNextTime(m_Tick);

		return;
	}

	// ���� ����Ʈ�� �پ��ִ� Ÿ��� �޾ƿ´�.
    Tile& tile = m_pZone->getTile(m_X, m_Y);

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
			// �� �鿪. by sigi. 2002.9.13
			if (pCreature->isFlag(Effect::EFFECT_CLASS_NO_DAMAGE)
				|| pCreature->isFlag(Effect::EFFECT_CLASS_IMMUNE_TO_ACID)
				|| pCreature->isFlag(Effect::EFFECT_CLASS_COMA) 
			)
			{
				continue;
			}

			// 2003.1.10 by Sequoia
			// �������� üũ
			if( !checkZoneLevelToHitTarget( pCreature ) ) continue;

			int AcidDamage = computeMagicDamage(pCreature, m_Damage, SKILL_ACID_SWAMP, m_bVampire);

			if (pCreature->getMoveMode() != Creature::MOVE_MODE_FLYING)
			{
				GCModifyInformation gcAttackerMI;
				GCModifyInformation gcDefenderMI;

				if (pCreature->isSlayer()) 
				{
					Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

					::setDamage( pSlayer, AcidDamage, pCastCreature, SKILL_ACID_SWAMP, &gcDefenderMI, &gcAttackerMI, false );

					Player* pPlayer = pSlayer->getPlayer();
					Assert(pPlayer != NULL);
					pPlayer->sendPacket(&gcDefenderMI);
				} 
				else if (pCreature->isVampire())
				{
					Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);

					::setDamage( pVampire, AcidDamage/2, pCastCreature, SKILL_ACID_SWAMP, &gcDefenderMI, &gcAttackerMI, false );

					Player* pPlayer = pVampire->getPlayer();
					Assert(pPlayer != NULL);
					pPlayer->sendPacket(&gcDefenderMI);
				}
				else if (pCreature->isOusters())
				{
					Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);

					::setDamage( pOusters, AcidDamage, pCastCreature, SKILL_ACID_SWAMP, &gcDefenderMI, &gcAttackerMI, false );

					Player* pPlayer = pOusters->getPlayer();
					Assert(pPlayer != NULL);
					pPlayer->sendPacket(&gcDefenderMI);
				}
				else if (pCreature->isMonster())
				{
					Monster* pMonster = dynamic_cast<Monster*>(pCreature);
				
					::setDamage( pMonster, AcidDamage, pCastCreature, SKILL_ACID_SWAMP, NULL, &gcAttackerMI, false );
				}

				bool modifiedAttacker = false;

				// �׾���� ����ġ�ش�. �.....
				if ( pCastCreature != NULL )
				{
					if (pCreature->isDead() && pCastCreature->isVampire())
					{
						int exp = computeCreatureExp(pCreature, KILL_EXP);
						Vampire* pCastVampire = dynamic_cast<Vampire*>( pCastCreature );
						Assert( pCastVampire != NULL );

						shareVampExp(pCastVampire, exp, gcAttackerMI);
						modifiedAttacker = true;
					}
				}

				// ���� �����ϱ�
				if ( pCastCreature != NULL
					&& pCastCreature->isPC()
					&& pCreature->isPC()
					&& ( pCreature->getObjectID() == m_TargetObjectID[0]
						|| pCreature->getObjectID() == m_TargetObjectID[1] )
				)
				{
					computeAlignmentChange( pCreature, AcidDamage, pCastCreature, &gcDefenderMI, &gcAttackerMI );
					modifiedAttacker = true;
				}

				if (modifiedAttacker) pCastCreature->getPlayer()->sendPacket( &gcAttackerMI );
			}
		}
	}
	
	setNextTime(m_Tick);

	//cout << "EffectAcidSwamp" << "affect END" << endl;

	__END_CATCH 
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectAcidSwamp::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectAcidSwamp::affect(Zone* pZone , ZoneCoord_t x , ZoneCoord_t y , Object* pObject)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectAcidSwamp::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectAcidSwamp::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectAcidSwamp" << "unaffect BEGIN" << endl;

    Tile& tile = m_pZone->getTile(m_X, m_Y);
	tile.deleteEffect(m_ObjectID);

	//cout << "EffectAcidSwamp" << "unaffect END" << endl;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectAcidSwamp::unaffect(Zone* pZone , ZoneCoord_t x , ZoneCoord_t y , Object* pObject)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectAcidSwamp::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "EffectAcidSwamp("
		<< "ObjectID:" << getObjectID()
		<< ")";

	return msg.toString();

	__END_CATCH

}

void EffectAcidSwampLoader::load(Zone* pZone)
	throw(Error)
{
	__BEGIN_TRY
	
	Statement* pStmt = NULL;
	Result* pResult = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery( "SELECT LeftX, TopY, RightX, BottomY, Value1, Value2, Value3 FROM ZoneEffectInfo WHERE ZoneID = %d AND EffectID = %d", pZone->getZoneID(), (int)Effect::EFFECT_CLASS_ACID_SWAMP);

		while (pResult->next())
		{
			int count = 0;
			
			ZoneCoord_t left 	= pResult->getInt( ++count );
			ZoneCoord_t top 	= pResult->getInt( ++count );
			ZoneCoord_t right 	= pResult->getInt( ++count );
			ZoneCoord_t	bottom	= pResult->getInt( ++count );
			int 		value1	= pResult->getInt( ++count );
			int 		value2	= pResult->getInt( ++count );
			int 		value3	= pResult->getInt( ++count );

			VSRect rect(0, 0, pZone->getWidth()-1, pZone->getHeight()-1);

			for ( int X = left ; X <= right ; X++ )
			for ( int Y = top ; Y <= bottom ; Y++ )
			{
				if ( rect.ptInRect(X, Y) )
				{
					Tile& tile = pZone->getTile(X,Y);
					if ( tile.canAddEffect() ) 
					{
						EffectAcidSwamp* pEffect = new EffectAcidSwamp(pZone, X, Y);
						pEffect->setForce(true);
						pEffect->setTick( value2 );
						pEffect->setDamage( value3 );
						pEffect->setNextTime(0);
						pEffect->setLevel( 100 );

						// � �� Ÿ�Ͽ��ٰ� ����Ʈ�� �߰��Ѵ�.
						pZone->registerObject(pEffect);
						pZone->addEffect(pEffect);
						tile.addEffect(pEffect);

					}

				}
			}

		}
	}
	END_DB(pStmt)

	__END_CATCH
}

EffectAcidSwampLoader* g_pEffectAcidSwampLoader = NULL;
