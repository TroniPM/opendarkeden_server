//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectGrandMasterOusters.cpp
// Written by  : ½­
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectGrandMasterOusters.h"
#include "Creature.h"
#include "Player.h"
#include "Zone.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCRemoveEffect.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectGrandMasterOusters::EffectGrandMasterOusters(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	setTarget(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGrandMasterOusters::affect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature*>(m_pTarget);
	affect( pCreature );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGrandMasterOusters::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature->isOusters());

	pCreature->setFlag(Effect::EFFECT_CLASS_GRAND_MASTER_OUSTERS);

	// ÁÖÀ§¿¡ »Ñ·ÁÁØ´Ù.
	GCAddEffect gcAddEffect;
	gcAddEffect.setObjectID(pCreature->getObjectID());
	gcAddEffect.setEffectID(Effect::EFFECT_CLASS_GRAND_MASTER_OUSTERS);
	gcAddEffect.setDuration(999999);
	pCreature->getZone()->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcAddEffect);

	__END_CATCH
}

void EffectGrandMasterOusters::unaffect() 
	throw(Error)
{
	__BEGIN_TRY	

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGrandMasterOusters::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Assert(pCreature != NULL);

	pCreature->removeFlag(Effect::EFFECT_CLASS_GRAND_MASTER_OUSTERS);

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pCreature->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_GRAND_MASTER_OUSTERS);
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcRemoveEffect);

	__END_DEBUG
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectGrandMasterOusters::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectGrandMasterOusters("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}
