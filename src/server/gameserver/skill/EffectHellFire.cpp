//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectHellFire.cpp
// Written by  :
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "DB.h"
#include "EffectHellFire.h"
#include "Slayer.h"
#include "Ousters.h"
#include "Monster.h"
#include "GamePlayer.h"
#include "SkillUtil.h"
#include "ZoneUtil.h"

#include "EffectHellFireToEnemy.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCAddEffect.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectHellFire::EffectHellFire(Zone* pZone, ZoneCoord_t zoneX, ZoneCoord_t zoneY) 
	throw(Error)
{
	__BEGIN_TRY

	m_pZone = pZone;
	m_X = zoneX;
	m_Y = zoneY;
	m_CasterName ="";
	m_CasterID = 0;
	m_bForce = false;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectHellFire::affect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectHellFire" << "affect BEGIN" << endl;
	
	Assert(m_pZone != NULL);

	// ����Ʈ�� ������ ũ���ĸ� ����´�.
	// !! �̹� �� ����� ���� ����Ƿ� NULL�� �� �� �ִ�.
	// by bezz. 2003.1.4

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
			// �������� üũ
			// 2003.1.10 by bezz, Sequoia
			if (pCreature->isFlag(Effect::EFFECT_CLASS_NO_DAMAGE)
				|| pCreature->isFlag(Effect::EFFECT_CLASS_COMA)
				|| pCreature->getObjectID()==m_CasterID
				|| !checkZoneLevelToHitTarget( pCreature )
			)
			{
				continue;
			}
			
			// ��� ���(--;)�̸� �� �´´�.
			if ( pCreature->isOusters() && !isForce() )
			{
				continue;
			}

			if (pCreature->getMoveMode() != Creature::MOVE_MODE_FLYING && !pCreature->isFlag(Effect::EFFECT_CLASS_HELLFIRE_TO_ENEMY))
			{
				// ����Ʈ Ŭ������ ������ ���δ�.
				EffectHellFireToEnemy* pEffect = new EffectHellFireToEnemy(pCreature);
				pEffect->setCasterOID(m_CasterID);
				pEffect->setDeadline(m_Duration);
				pEffect->setDamage(m_Damage);
				pEffect->setNextTime(10);
				pCreature->addEffect(pEffect);
				pCreature->setFlag(Effect::EFFECT_CLASS_HELLFIRE_TO_ENEMY);

				GCAddEffect gcAddEffect;
				gcAddEffect.setObjectID(pCreature->getObjectID());
				gcAddEffect.setEffectID(Effect::EFFECT_CLASS_HELLFIRE_TO_ENEMY);
				gcAddEffect.setDuration(m_Duration);

				m_pZone->broadcastPacket( pCreature->getX(), pCreature->getY(), &gcAddEffect );
			}
		}
	}
	
	setNextTime(m_Tick);

	//cout << "EffectHellFire" << "affect END" << endl;

	__END_CATCH 
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectHellFire::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectHellFire::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectHellFire::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectHellFire" << "unaffect BEGIN" << endl;

    Tile& tile = m_pZone->getTile(m_X, m_Y);
	tile.deleteEffect(m_ObjectID);

	//cout << "EffectHellFire" << "unaffect END" << endl;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectHellFire::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "EffectHellFire("
		<< "ObjectID:" << getObjectID()
		<< ")";

	return msg.toString();

	__END_CATCH

}


EffectHellFireLoader* g_pEffectHellFireLoader = NULL;
