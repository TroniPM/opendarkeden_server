//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectSanctuary.cpp
// Written by  : elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectSanctuary.h"
#include "Creature.h"
#include "Zone.h"
#include "Tile.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

EffectSanctuary::EffectSanctuary(Zone* pZone , ZoneCoord_t ZoneX, ZoneCoord_t ZoneY, ZoneCoord_t CenterX, ZoneCoord_t CenterY)
	throw(Error)
{
	__BEGIN_TRY

	m_pZone = pZone;
	m_X = ZoneX;
	m_Y = ZoneY;

	m_CenterX = CenterX;
	m_CenterY = CenterY;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// EffectSanctuary::affectCreature()
// bAffectByMove�� false�� ��ڸ����� ���ϴ� ���̹Ƿ�.. 
// �ܺ��� SkillOK���� modify info�� ������. ������ GCModifyInformation� 
// ���� �ʿ䰡 ����.
// pTarget�� �þ߰� ����  ���� true�� return
//////////////////////////////////////////////////////////////////////////////
bool EffectSanctuary::affectObject(Object* pTarget, bool bAffectByMove)
	throw(Error)
{
	__BEGIN_TRY

//	if (pTarget->getObjectClass() == Object::OBJECT_CLASS_CREATURE)
//	{
//		Creature* pTargetCreature = dynamic_cast<Creature*>(pTarget);
//		// �̹� �ɷ��ִ� ���쿡�� �ٽ� ���� �ʴ´�.
//		if (pTargetCreature->isFlag(Effect::EFFECT_CLASS_SANCTUARY))
//		{
//			return false;	
//		}
//
//		pTargetCreature->setFlag(Effect::EFFECT_CLASS_SANCTUARY);
//		return true;
//	}
//
	return false;
	
	__END_CATCH
}

void EffectSanctuary::unaffectObject(Object* pTarget, bool bUnaffectByMove)
	throw(Error)
{
	__BEGIN_TRY

//	Assert(pTarget != NULL);
//	
//	if (pTarget->getObjectClass() == Object::OBJECT_CLASS_CREATURE)
//	{
//		Creature* pTargetCreature = dynamic_cast<Creature*>(pTarget);
//
//		pTargetCreature->removeFlag(Effect::EFFECT_CLASS_SANCTUARY);
//	}

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// EffectSanctuary::affect()
//////////////////////////////////////////////////////////////////////////////
void EffectSanctuary::affect(Creature* pTargetCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// EffectSanctuary::affect()
//////////////////////////////////////////////////////////////////////////////
void EffectSanctuary::affect(Zone* pZone , ZoneCoord_t x , ZoneCoord_t y , Object* pObject)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// unaffect()
//////////////////////////////////////////////////////////////////////////////
void EffectSanctuary::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectSanctuary " << "unaffect BEGIN" << endl;

	Tile & tile = m_pZone->getTile(m_X, m_Y);
//
//	// unaffect creatures on tile
//	const list<Object*>& oList = tile.getObjectList();
//	for (list<Object*>::const_iterator itr = oList.begin(); itr != oList.end(); itr++) 
//	{
//		if (*itr != this) 
//		{
//			EffectSanctuary::unaffectObject((Object*)(*itr), false);
//		}
//	}

	tile.deleteEffect(m_ObjectID);

	//cout << "EffectSanctuary " << "unaffect END" << endl;

	__END_CATCH
}

void EffectSanctuary::unaffect(Zone* pZone , ZoneCoord_t x , ZoneCoord_t y , Object* pObject)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

string EffectSanctuary::toString() const 
	throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectSanctuary("
		<< "DayTime:" << m_Deadline.tv_sec
		<< ")";
	return msg.toString();

	__END_CATCH
}

