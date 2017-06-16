//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectDarkness.cpp
// Written by  : elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectDarkness.h"
#include "Creature.h"
#include "Zone.h"
#include "Tile.h"
#include "DB.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

EffectDarkness::EffectDarkness(Zone* pZone , ZoneCoord_t ZoneX, ZoneCoord_t ZoneY)
	throw(Error)
{
	__BEGIN_TRY

	m_pZone = pZone;
	m_X = ZoneX;
	m_Y = ZoneY;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// EffectDarkness::affectCreature()
// bAffectByMove�� false�� ��ڸ����� ���ϴ� ���̹Ƿ�.. 
// �ܺ��� SkillOK���� modify info�� ������. ������ GCModifyInformation� 
// ���� �ʿ䰡 ����.
// pTarget�� �þ߰� ����  ���� true�� return
//////////////////////////////////////////////////////////////////////////////
bool EffectDarkness::affectObject(Object* pTarget, bool bAffectByMove)
	throw(Error)
{
	__BEGIN_TRY

	bool bAffected = false;
	if (pTarget->getObjectClass() == Object::OBJECT_CLASS_CREATURE)
	{
		Creature* pTargetCreature = dynamic_cast<Creature*>(pTarget);
		// �̹� �ɷ��ִ� ���쿡�� �ٽ� ���� �ʴ´�.
		if (pTargetCreature->isFlag(Effect::EFFECT_CLASS_DARKNESS))
		{
			return false;	
		}
		// �����̾��� ���쿡�� �ɸ���.
		if (pTargetCreature->isSlayer()||pTargetCreature->isOusters())
		{
			bAffected = true;
			pTargetCreature->setFlag(Effect::EFFECT_CLASS_DARKNESS);
		}
	}

	return bAffected;
	
	__END_CATCH
}

void EffectDarkness::unaffectObject(Object* pTarget, bool bUnaffectByMove)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pTarget != NULL);
	
	if (pTarget->getObjectClass() == Object::OBJECT_CLASS_CREATURE)
	{
		Creature* pTargetCreature = dynamic_cast<Creature*>(pTarget);

		if (pTargetCreature->isSlayer()||pTargetCreature->isOusters())
		{
			pTargetCreature->removeFlag(Effect::EFFECT_CLASS_DARKNESS);
		}
	}

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// EffectDarkness::affect()
//////////////////////////////////////////////////////////////////////////////
void EffectDarkness::affect(Creature* pTargetCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// EffectDarkness::affect()
//////////////////////////////////////////////////////////////////////////////
void EffectDarkness::affect(Zone* pZone , ZoneCoord_t x , ZoneCoord_t y , Object* pObject)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// unaffect()
//////////////////////////////////////////////////////////////////////////////
void EffectDarkness::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectDarkness " << "unaffect BEGIN" << endl;

	Tile & tile = m_pZone->getTile(m_X, m_Y);

	// unaffect creatures on tile
	const list<Object*>& oList = tile.getObjectList();
	for (list<Object*>::const_iterator itr = oList.begin(); itr != oList.end(); itr++) 
	{
		if (*itr != this) 
		{
			EffectDarkness::unaffectObject((Object*)(*itr), false);
		}
	}

	tile.deleteEffect(m_ObjectID);

	//cout << "EffectDarkness " << "unaffect END" << endl;

	__END_CATCH
}

void EffectDarkness::unaffect(Zone* pZone , ZoneCoord_t x , ZoneCoord_t y , Object* pObject)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

string EffectDarkness::toString() const 
	throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectDarkness("
		<< "DayTime:" << m_Deadline.tv_sec
		<< ")";
	return msg.toString();

	__END_CATCH
}

void EffectDarknessLoader::load( Zone* pZone )
	throw (Error)
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	Result* pResult = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery( "SELECT LeftX, TopY, RightX, BottomY FROM ZoneEffectInfo WHERE ZoneID = %u AND EffectID = %d", pZone->getZoneID(), Effect::EFFECT_CLASS_DARKNESS );

		VSRect rect( 0, 0, pZone->getWidth()-1, pZone->getHeight()-1 );

		while ( pResult->next() )
		{
			int left	= pResult->getInt(1);
			int top		= pResult->getInt(2);
			int right	= pResult->getInt(3);
			int bottom	= pResult->getInt(4);

			for ( int x = left ; x <= right ; x++ )
			{
				for ( int y = top ; y <= bottom ; y++ )
				{
					if ( !rect.ptInRect( x, y ) )
						continue;

					Tile& tile = pZone->getTile( x, y );

					if ( tile.canAddEffect() )
					{
						EffectDarkness* pEffect = new EffectDarkness( pZone, x, y );
						pEffect->setLevel(300);
						pEffect->setStartTime();

						pZone->registerObject( pEffect );
						pZone->addEffect( pEffect );
						tile.addEffect( pEffect );
					}
				}
			}
		}
	}
	END_DB( pStmt )

	__END_CATCH
}

EffectDarknessLoader* g_pEffectDarknessLoader = NULL;
