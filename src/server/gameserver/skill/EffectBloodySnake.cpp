//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectBloodySnake.cpp
// Written by  :
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectBloodySnake.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Monster.h"
#include "GamePlayer.h"
#include "SkillUtil.h"
#include "ZoneUtil.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCAddEffectToTile.h"

POINT EffectBloodySnake::getNextPosition()
{
	Dir_t dir = m_Dir;
	if (rand()%5<2)
	{
		dir = (dir+(rand()%2==0? 1 : DIR_MAX-1))%DIR_MAX;
	}

	const POINT& pt = dirMoveMask[dir];

	return POINT(m_X+pt.x, m_Y+pt.y);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectBloodySnake::EffectBloodySnake(Zone* pZone, ZoneCoord_t zoneX, ZoneCoord_t zoneY) 
	throw(Error)
{
	__BEGIN_TRY

	m_pZone = pZone;
	m_X = zoneX;
	m_Y = zoneY;
	m_Dir = DOWN;
	m_CasterName ="";
	m_CasterID = 0;

	m_CreatureClass = Creature::CREATURE_CLASS_VAMPIRE;
	m_ClanID = 0;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBloodySnake::affect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectBloodySnake" << "affect BEGIN" << endl;
	
	Assert(m_pZone != NULL);

	// ��ų �����ڸ� ����´�.
	// !! �̹� �� ����� ���� ����Ƿ� NULL �� �� �� �ִ�.
	// by bezz. 2003.1.4
	Creature* pCastCreature = m_pZone->getCreature( m_CasterID );

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
			// �ڱ� �ڽ��̸� �� �´´�.
			if (pCreature->isFlag(Effect::EFFECT_CLASS_NO_DAMAGE)
				|| pCreature->getObjectID()==m_CasterID)
			{
				continue;
			}
			
			// ��� ���(--;)�̸� �� �´´�.
			if (m_CreatureClass==pCreature->getCreatureClass())
			{
				if (m_CreatureClass==Creature::CREATURE_CLASS_MONSTER)
				{
					Creature* pAttacker = m_pZone->getCreature( m_CasterID );
					if (pAttacker!=NULL)
					{
						Monster* pAttackMonster = dynamic_cast<Monster*>(pAttacker);
						Monster* pDefendMonster = dynamic_cast<Monster*>(pCreature);

						if (pAttackMonster->getClanType()==pDefendMonster->getClanType())
						{
							continue;
						}
					}
				}
			}

			int Damage = m_Damage;

			if (pCreature->getMoveMode() != Creature::MOVE_MODE_FLYING)
			{
				if (pCreature->isSlayer()) 
				{
					Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

					GCModifyInformation gcMI;
					::setDamage( pSlayer, Damage, pCastCreature, SKILL_BLOODY_SNAKE, &gcMI );

					Player* pPlayer = pSlayer->getPlayer();
					Assert(pPlayer != NULL);
					pPlayer->sendPacket(&gcMI);

					// knockbacküũ
					bool bKnockback = rand()%100 < 20;	// 20%�� Ȯ���� knockback
					if (bKnockback)
					{
						int x = pCreature->getX() + rand()%3 - 1;
						int y = pCreature->getY() + rand()%3 - 1;
						knockbackCreature(m_pZone, pCreature, x, y);
						// Tile�� oList�� �ٲ��� �ϹǷ� �� üũ���� �ʴ´�. 
						// �� Ÿ�Ͽ��� �ϳ��� knockback�Ǹ� �ڿ� üũ�� �ֵ�� �� �¾Ƶ� ��������~
						break;
					}
				} 
				else if (pCreature->isVampire())
				{
					Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);

					GCModifyInformation gcMI;
					::setDamage( pVampire, Damage, pCastCreature, SKILL_BLOODY_SNAKE, &gcMI );

					Player* pPlayer = pVampire->getPlayer();
					Assert(pPlayer != NULL);
					pPlayer->sendPacket(&gcMI);

					// knockbacküũ
					bool bKnockback = rand()%100 < 20;	// 20%�� Ȯ���� knockback
					if (bKnockback)
					{
						int x = pCreature->getX() + rand()%3 - 1;
						int y = pCreature->getY() + rand()%3 - 1;
						knockbackCreature(m_pZone, pCreature, x, y);
						// Tile�� oList�� �ٲ��� �ϹǷ� �� üũ���� �ʴ´�. 
						// �� Ÿ�Ͽ��� �ϳ��� knockback�Ǹ� �ڿ� üũ�� �ֵ�� �� �¾Ƶ� ��������~
						break;
					}
				}
				else if (pCreature->isOusters())
				{
					Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);

					GCModifyInformation gcMI;
					::setDamage( pOusters, Damage, pCastCreature, SKILL_BLOODY_SNAKE, &gcMI );

					Player* pPlayer = pOusters->getPlayer();
					Assert(pPlayer != NULL);
					pPlayer->sendPacket(&gcMI);

					// knockbacküũ
					bool bKnockback = rand()%100 < 20;	// 20%�� Ȯ���� knockback
					if (bKnockback)
					{
						int x = pCreature->getX() + rand()%3 - 1;
						int y = pCreature->getY() + rand()%3 - 1;
						knockbackCreature(m_pZone, pCreature, x, y);
						// Tile�� oList�� �ٲ��� �ϹǷ� �� üũ���� �ʴ´�. 
						// �� Ÿ�Ͽ��� �ϳ��� knockback�Ǹ� �ڿ� üũ�� �ֵ�� �� �¾Ƶ� ��������~
						break;
					}
				}
				else if (pCreature->isMonster())
				{
					Monster* pMonster = dynamic_cast<Monster*>(pCreature);

					::setDamage( pMonster, Damage, pCastCreature, SKILL_BLOODY_SNAKE );

					// knockbacküũ
					bool bKnockback = rand()%100 < 20;	// 20%�� Ȯ���� knockback
					if (bKnockback)
					{
						int x = pCreature->getX() + rand()%3 - 1;
						int y = pCreature->getY() + rand()%3 - 1;
						knockbackCreature(m_pZone, pCreature, x, y);
						// Tile�� oList�� �ٲ��� �ϹǷ� �� üũ���� �ʴ´�. 
						// �� Ÿ�Ͽ��� �ϳ��� knockback�Ǹ� �ڿ� üũ�� �ֵ�� �� �¾Ƶ� ��������~
						break;
					}
				}


				// m_CasterName�� pCreature�� ���� ������ KillCount ó��
				// by sigi. 2002.8.31
/*				if (pCreature->isDead())
				{
					Creature* pAttacker = m_pZone->getCreature( m_CasterID );

					if (pAttacker!=NULL)
					{ 
						affectKillCount(pAttacker, pCreature);
					}
				}*/
			}
		}
	}

	// ��� �̵� ��ǥ ����
	POINT pt = getNextPosition();

	/*
	cout << "EffectSnake(" << m_ObjectID << ")"
		<< "[" << Dir2String[m_Dir].c_str() << "] ("
		<< m_X << ", " << m_Y << ") --> ("
		<< pt.x << ", " << pt.y << ")" << endl;
	*/

	// ��� �̵��� Ÿ�Ͽ� �߰��Ѵ�.
	VSRect rect(0, 0, m_pZone->getWidth()-1, m_pZone->getHeight()-1);
	if (rect.ptInRect(pt.x, pt.y))
	{
		Tile& newTile = m_pZone->getTile( pt.x, pt.y );
		if ((!newTile.isGroundBlocked()
			|| newTile.hasCreature(Creature::MOVE_MODE_WALKING))
			&& newTile.canAddEffect())
		{
			// ��� effect�� ����� �����.
			Effect* pOldEffect = newTile.getEffect(Effect::EFFECT_CLASS_BLOODY_SNAKE);
			if (pOldEffect != NULL && pOldEffect!=this)
			{
				ObjectID_t effectID = pOldEffect->getObjectID();
				m_pZone->deleteEffect(effectID);// fix me
			}
		
			// ��� Ÿ�Ͽ��� ������
			tile.deleteEffect(m_ObjectID);
			
			// �� Ÿ�Ͽ� �߰��Ѵ�.
			newTile.addEffect(this);

			m_X = pt.x;
			m_Y = pt.y;

			GCAddEffectToTile gcAddEffectToTile;
			gcAddEffectToTile.setEffectID( Effect::EFFECT_CLASS_BLOODY_SNAKE );
			gcAddEffectToTile.setDuration( m_Tick+(m_Tick>>1) );
			gcAddEffectToTile.setObjectID( m_ObjectID );
			gcAddEffectToTile.setXY( m_X, m_Y );

			m_pZone->broadcastPacket(m_X, m_Y, &gcAddEffectToTile);
	
			setNextTime(m_Tick);
		}
		else
		{
			setDeadline( 0 );
		}
	}
	else
	{
		setDeadline( 0 );
	}

	//cout << "EffectBloodySnake" << "affect END" << endl;

	__END_CATCH 
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBloodySnake::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBloodySnake::affect(Zone* pZone , ZoneCoord_t x , ZoneCoord_t y , Object* pObject)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBloodySnake::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBloodySnake::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectBloodySnake" << "unaffect BEGIN" << endl;

    Tile& tile = m_pZone->getTile(m_X, m_Y);
	tile.deleteEffect(m_ObjectID);

	//cout << "EffectBloodySnake" << "unaffect END" << endl;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBloodySnake::unaffect(Zone* pZone , ZoneCoord_t x , ZoneCoord_t y , Object* pObject)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectBloodySnake::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "EffectBloodySnake("
		<< "ObjectID:" << getObjectID()
		<< ")";

	return msg.toString();

	__END_CATCH

}

EffectBloodySnakeLoader* g_pEffectBloodySnakeLoader = NULL;
