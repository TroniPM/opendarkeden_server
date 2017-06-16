//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectIceField.cpp
// Written by  :
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "DB.h"
#include "EffectIceField.h"
#include "Slayer.h"
#include "Ousters.h"
#include "Monster.h"
#include "GamePlayer.h"
#include "SkillUtil.h"
#include "ZoneUtil.h"

#include "EffectIceFieldToCreature.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCAddEffect.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectIceField::EffectIceField(Zone* pZone, ZoneCoord_t zoneX, ZoneCoord_t zoneY) 
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
void EffectIceField::affect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectIceField" << "affect BEGIN" << endl;
	
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

			if (pCreature->getMoveMode() != Creature::MOVE_MODE_FLYING && !pCreature->isFlag(Effect::EFFECT_CLASS_ICE_FIELD_TO_CREATURE))
			{
				// ����Ʈ Ŭ������ ������ ���δ�.
				EffectIceFieldToCreature* pEffect = new EffectIceFieldToCreature(pCreature);
				pEffect->setDeadline(m_Duration);
				pCreature->addEffect(pEffect);
				pCreature->setFlag(Effect::EFFECT_CLASS_ICE_FIELD_TO_CREATURE);

				GCAddEffect gcAddEffect;
				gcAddEffect.setObjectID(pCreature->getObjectID());
				gcAddEffect.setEffectID(Effect::EFFECT_CLASS_ICE_FIELD_TO_CREATURE);
				gcAddEffect.setDuration(m_Duration);

				m_pZone->broadcastPacket( pCreature->getX(), pCreature->getY(), &gcAddEffect );
			}
		}
	}
	
	setNextTime(m_Tick);

	//cout << "EffectIceField" << "affect END" << endl;

	__END_CATCH 
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectIceField::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectIceField::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectIceField::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectIceField" << "unaffect BEGIN" << endl;

    Tile& tile = m_pZone->getTile(m_X, m_Y);
	tile.deleteEffect(m_ObjectID);

	//cout << "EffectIceField" << "unaffect END" << endl;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectIceField::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "EffectIceField("
		<< "ObjectID:" << getObjectID()
		<< ")";

	return msg.toString();

	__END_CATCH

}

void EffectIceFieldLoader::load(Zone* pZone)
	throw(Error)
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	Result* pResult = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery( "SELECT LeftX, TopY, RightX, BottomY, Value1, Value2, Value3 FROM ZoneEffectInfo WHERE ZoneID = %d AND EffectID = %d", pZone->getZoneID(), (int)Effect::EFFECT_CLASS_ICE_FIELD);

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
						EffectIceField* pEffect = new EffectIceField(pZone, X, Y);
						pEffect->setDuration( value1 );
						pEffect->setNextTime(0);
						pEffect->setTick(10);
						pEffect->setForce( true );

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

EffectIceFieldLoader* g_pEffectIceFieldLoader = NULL;
