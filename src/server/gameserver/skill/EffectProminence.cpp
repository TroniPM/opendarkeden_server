//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectProminence.cpp
// Written by  :
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "DB.h"
#include "Effect.h"
#include "EffectProminence.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "Monster.h"
#include "GamePlayer.h"
#include "SkillUtil.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectProminence::EffectProminence(Zone* pZone, ZoneCoord_t zoneX, ZoneCoord_t zoneY) 
	throw(Error)
{
	__BEGIN_TRY

	m_pZone = pZone;
	m_X = zoneX;
	m_Y = zoneY;
	m_UserObjectID = 0;
	m_SendEffectClass = getEffectClass();
	m_bForce = false;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectProminence::affect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectProminence" << "affect BEGIN" << endl;
	
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
			if ( pCastCreature != NULL &&
				(pCreature->isFlag(Effect::EFFECT_CLASS_NO_DAMAGE)
				|| pCreature->isFlag(Effect::EFFECT_CLASS_COMA) 
				|| !canHit( pCastCreature, pCreature, SKILL_PROMINENCE, getLevel() ))
			)
			{
				continue;
			}

			// 2003.1.10 by Sequoia
			// �������� üũ
			if( !checkZoneLevelToHitTarget( pCreature ) ) continue;

			if (pCreature->getMoveMode() != Creature::MOVE_MODE_FLYING)
			{
				GCModifyInformation gcAttackerMI;
				GCModifyInformation gcDefenderMI;

				if (pCreature->isSlayer()) 
				{
					Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

					::setDamage( pSlayer, m_Damage, pCastCreature, SKILL_PROMINENCE, &gcDefenderMI, &gcAttackerMI );

					Player* pPlayer = pSlayer->getPlayer();
					Assert(pPlayer != NULL);
					pPlayer->sendPacket(&gcDefenderMI);
				} 
				else if (pCreature->isVampire())
				{
					Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);

					::setDamage( pVampire, m_Damage, pCastCreature, SKILL_PROMINENCE, &gcDefenderMI, &gcAttackerMI );

					Player* pPlayer = pVampire->getPlayer();
					Assert(pPlayer != NULL);
					pPlayer->sendPacket(&gcDefenderMI);
				}
				else if (pCreature->isMonster())
				{
					Monster* pMonster = dynamic_cast<Monster*>(pCreature);
				
					::setDamage( pMonster, m_Damage, pCastCreature, SKILL_PROMINENCE, NULL, &gcAttackerMI );
				}
				else if (pCreature->isOusters() && isForce() )
				{
					Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);

					::setDamage( pOusters, m_Damage, pCastCreature, SKILL_PROMINENCE, &gcDefenderMI, &gcAttackerMI );

					Player* pPlayer = pOusters->getPlayer();
					Assert(pPlayer != NULL);
					pPlayer->sendPacket(&gcDefenderMI);
				}
				else continue; // �ƿ콺��� NPC ������... -_-

				// �׾���� ����ġ�ش�. �.....
				if ( pCastCreature != NULL )
				{
					if (pCreature->isDead() && pCastCreature->isOusters())
					{
						Ousters* pCastOusters = dynamic_cast<Ousters*>( pCastCreature );
						Assert( pCastOusters != NULL );

						int exp = computeCreatureExp(pCreature, 100, pCastOusters);
						shareOustersExp(pCastOusters, exp, gcAttackerMI);
					}
				}

				// ���� �����ϱ�
/*				if ( pCastCreature != NULL
					&& pCastCreature->isPC()
					&& pCreature->isPC()
				)
				{
					computeAlignmentChange( pCreature, m_Damage, pCastCreature, &gcDefenderMI, &gcAttackerMI );
					modifiedAttacker = true;
				}*/

				if ( gcAttackerMI.getShortCount() != 0 || gcAttackerMI.getLongCount() != 0 ) pCastCreature->getPlayer()->sendPacket(&gcAttackerMI);
			}
		}
	}
	
	setNextTime(m_Tick);

	//cout << "EffectProminence" << "affect END" << endl;

	__END_CATCH 
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectProminence::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectProminence" << "unaffect BEGIN" << endl;

    Tile& tile = m_pZone->getTile(m_X, m_Y);
	tile.deleteEffect(m_ObjectID);

	//cout << "EffectProminence" << "unaffect END" << endl;

	__END_CATCH
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectProminence::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "EffectProminence("
		<< "ObjectID:" << getObjectID()
		<< ")";

	return msg.toString();

	__END_CATCH

}

void EffectProminenceLoader::load(Zone* pZone)
	throw(Error)
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	Result* pResult = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery( "SELECT LeftX, TopY, RightX, BottomY, Value1, Value2, Value3 FROM ZoneEffectInfo WHERE ZoneID = %d AND EffectID = %d", pZone->getZoneID(), (int)Effect::EFFECT_CLASS_PROMINENCE_3);

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
						EffectProminence* pEffect = new EffectProminence(pZone, X, Y);
						pEffect->setTick( value2 );
						pEffect->setDamage( value3 );
						pEffect->setNextTime(0);
						pEffect->setForce( true );
						pEffect->setSendEffectClass( Effect::EFFECT_CLASS_PROMINENCE_3 );

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

EffectProminenceLoader* g_pEffectProminenceLoader = NULL;
