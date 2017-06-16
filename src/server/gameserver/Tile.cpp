//////////////////////////////////////////////////////////////////////////////
// FileName 	: Tile.cpp
// Written By	: reiot@ewestsoft.com
// Description	:
//////////////////////////////////////////////////////////////////////////////

#include "Tile.h"
#include "Assert.h"
#include "Player.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "Sector.h"
#include "Creature.h"
#include "GamePlayer.h"
#include "StringStream.h"
#include <algorithm>

#include "EffectYellowPoison.h"
#include "EffectGreenPoison.h"
#include "EffectDarkness.h"
#include "EffectTryingPosition.h"

//////////////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////////////
Tile::Tile (WORD wFlags , WORD wOption)
    throw ()
{
	__BEGIN_TRY

	m_wFlags = wFlags;
	m_wOption = wOption;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////////////
Tile::~Tile ()
	throw ()
{
	__BEGIN_TRY

	// �Ҽӵ� ���� ��ü��� ����Ѵ�.
	while (!m_Objects.empty()) 
	{
		Object* pObj = m_Objects.front();
		SAFE_DELETE(pObj);
		m_Objects.pop_front();
	}

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// ũ��ó�� ����Ʈ�� �߰��Ѵ�. 
//
// return��� �׳� �̵��ΰ�(true), Portal� activate ��Ų�ǰ�(false)�� ���� ��
//////////////////////////////////////////////////////////////////////////////
bool Tile::addCreature (Creature* pCreature, bool bCheckEffect, bool bCheckPortal) 
	throw (GameException , DuplicatedException , Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Assert(pCreature != NULL);

	// ũ��ó�� MoveMode { WALKING | FLYING | BURROWING }� ������ �´�.
	Creature::MoveMode mode = pCreature->getMoveMode();	

	// �߰��Ϸ�� ũ��ó�� ��� MoveMode�� �ش��ϴ� ���� blocking���� �ʾƾ� �Ѵ�.
	Assert(! isBlocked(mode));

	// �߰��Ϸ�� ũ��ó�� ��� MoveMode�� ���� ũ��ó�� Ÿ�ϳ��� ������ �Ѵ�.
	//Assert(! hasCreature(mode));
	if (hasCreature(mode))
	{
		StringStream msg;

		Creature* pWalkingCreature = getCreature( Creature::MOVE_MODE_WALKING );
		Creature* pFlyingCreature = getCreature( Creature::MOVE_MODE_FLYING );
		Creature* pBurrowingCreature = getCreature( Creature::MOVE_MODE_BURROWING );
		Item* pItem = getItem();

		msg << "TileInfo: ";

		if (pWalkingCreature!=NULL) 
		{
			msg << "Walking(" << pWalkingCreature->toString().c_str() << ") ";
		}
		if (pFlyingCreature!=NULL) 
		{
			msg << "Flying(" << pFlyingCreature->toString().c_str() << ") ";
		}
		if (pBurrowingCreature!=NULL) 
		{
			msg << "Burrowing(" << pBurrowingCreature->toString().c_str() << ") ";
		}
		if (pItem!=NULL) 
		{
			msg << "Item(" << pItem->toString().c_str() << ") ";
		}

		filelog("tileError.txt", "%s", msg.toString().c_str());

		Assert(false);
	}

	// ũ��ó�� ����Ʈ�� �����ִ´�.
	addObject(pCreature);

	// �ش��ϴ� ũ��ó �÷��׸� �Ҵ�.
	FLAG_SET(m_wFlags , TILE_WALKING_CREATURE + mode);

	// �ش��ϴ� blocking �÷��׸� �Ҵ�.
	FLAG_SET(m_wFlags , TILE_GROUND_BLOCKED + mode);

	Assert(isBlocked(mode));
	Assert(hasCreature(mode));

	if (bCheckPortal)
	{
		// ���� ��Ż�� ����鼭, ũ��ó�� PC�� ����.. (�����Ϳ� NPC�� ��Ż �̵�� ���� �ʴ´�.)
		if (hasPortal() && pCreature->isPC()) 
		{
			Portal* pPortal = getPortal();

			if (pCreature->isSlayer()) 
			{
				Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

				if (pPortal->getPortalClass() != PORTAL_CLASS_MULTI) 
				{
					if (pPortal->getObjectType() == PORTAL_NORMAL || pPortal->getObjectType() == PORTAL_SLAYER 
							|| pPortal->getObjectType() == PORTAL_GUILD || pPortal->getObjectType() == PORTAL_BATTLE)
					{
						// Ʈ���ŵ� ��Ż�� ���쿡�� Ʈ���� ���� �������� ����, 
						// portal exception� ������.
						if (pPortal->getPortalClass() == PORTAL_CLASS_TRIGGERED)
						{
							if (pPortal->activate(pSlayer)) 
							{
								//throw PortalException();
								// PortalException���. by sigi. 2002.5.6
								return false;
							}
						}

						else if (!(pSlayer->hasRideMotorcycle() && pPortal->getObjectType() == PORTAL_SLAYER)) 
						{
							if (pPortal->activate(pSlayer))
							{
								//throw PortalException();
								// PortalException���. by sigi. 2002.5.6
								return false;
							}
						}
					}
				}
			} 
			else if (pCreature->isVampire()) 
			{
				Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);

				if (pPortal->getPortalClass() != PORTAL_CLASS_MULTI) 
				{
					if (pPortal->getObjectType() == PORTAL_NORMAL || pPortal->getObjectType() == PORTAL_VAMPIRE
							|| pPortal->getObjectType() == PORTAL_GUILD || pPortal->getObjectType() == PORTAL_BATTLE)
					{
						// Ʈ���ŵ� ��Ż�� ���쿡�� Ʈ���� ���� �������� ����,
						// portal exception� ������.
						if (pPortal->getPortalClass() == PORTAL_CLASS_TRIGGERED)
						{
							if (pPortal->activate(pVampire))
							{
								//throw PortalException();
								// PortalException���. by sigi. 2002.5.6
								return false;
							}
						}
						else
						{
							if (pPortal->activate(pVampire))
							{
								//throw PortalException();
								// PortalException���. by sigi. 2002.5.6
								return false;
							}
						}
					}
				}
			}
			else if (pCreature->isOusters()) 
			{
				Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);

				if (pPortal->getPortalClass() != PORTAL_CLASS_MULTI) 
				{
					if (pPortal->getObjectType() == PORTAL_NORMAL || pPortal->getObjectType() == PORTAL_OUSTERS
							|| pPortal->getObjectType() == PORTAL_GUILD || pPortal->getObjectType() == PORTAL_BATTLE)
					{
						// Ʈ���ŵ� ��Ż�� ���쿡�� Ʈ���� ���� �������� ����,
						// portal exception� ������.
						if (pPortal->getPortalClass() == PORTAL_CLASS_TRIGGERED)
						{
							if (pPortal->activate(pOusters))
							{
								//throw PortalException();
								// PortalException���. by sigi. 2002.5.6
								return false;
							}
						}
						else
						{
							if (pPortal->activate(pOusters))
							{
								//throw PortalException();
								// PortalException���. by sigi. 2002.5.6
								return false;
							}
						}
					}
				}
			}
		}
	}

	// effect �˻�.
	if (hasEffect())
	{
		if (bCheckEffect)
		{
			EffectGreenPoison* pEGP = (EffectGreenPoison*)getEffect(Effect::EFFECT_CLASS_GREEN_POISON);
			//if (pCreature->isSlayer() && (pEGP = (EffectGreenPoison*)getEffect(Effect::EFFECT_CLASS_GREEN_POISON)))
			if (pEGP != NULL)
			{
				pEGP->affectCreature(pCreature, true);
			}
			EffectYellowPoison* pEYP = NULL;
			if ( (pCreature->isSlayer() || pCreature->isOusters() ) && (pEYP = (EffectYellowPoison*)getEffect(Effect::EFFECT_CLASS_YELLOW_POISON)))
			{
				pEYP->affectCreature(pCreature, true);
			}
			// ����� �����Ǿ� �Ǵ� �Ÿ� ������Ų��
			else if ( (pEYP = (EffectYellowPoison*)getEffect(Effect::EFFECT_CLASS_YELLOW_POISON)) && pEYP->isForce() )
			{
				pEYP->affectCreature(pCreature, true);
			}

			EffectDarkness* pDarkness = NULL;
			if (pCreature->isSlayer() && (pDarkness = (EffectDarkness*)getEffect(Effect::EFFECT_CLASS_DARKNESS)))
			{
				pDarkness->affectObject(pCreature, true);
			}

			EffectTryingPosition* pTP;
			if ( pCreature->isPC() && (pTP = dynamic_cast<EffectTryingPosition*>(getEffect(Effect::EFFECT_CLASS_TRYING_POSITION))) )
			{
				pTP->affect( pCreature );
			}
		}
	}
	else
	{
		if ( ( pCreature->isOusters() || pCreature->isSlayer() ) && pCreature->isFlag(Effect::EFFECT_CLASS_DARKNESS))
		{
			pCreature->removeFlag(Effect::EFFECT_CLASS_DARKNESS);
		}
	}

	// PortalException���. by sigi. 2002.5.6
	return true;

	__END_DEBUG
	__END_CATCH
}

//////////////////////////////////////////////////////////////
// Ư� ID�� ���� ũ��ó�� ����Ʈ���� ����Ѵ�.
// ����ȭ�� �ʿ䰡 �ִ�. (�˻� + ���)
//////////////////////////////////////////////////////////////
void Tile::deleteCreature (ObjectID_t creatureID) 
	throw (NoSuchElementException , Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	try 
	{
		// ���� ũ��ó�� ���� ���򰡰� �ѱ��� blocking �Ǿ��� �Ѵ�.
		Assert(isGroundBlocked() || isAirBlocked() || isUndergroundBlocked());

		// ���� ũ��ó�� ���򰡿� ����ؾ� �Ѵ�.
		//Assert(hasWalkingCreature() || hasFlyingCreature() || hasBurrowingCreature());
		Assert(hasCreature());	// by sigi. 2002.5.8

		Creature* pCreature = dynamic_cast<Creature*>(getObject(creatureID));

		// ����Ʈ�� ����� ����, ũ��ó���Լ� ������.
		/*
		if (hasEffect()) 
		{
			Effect* pEffect = getEffect();
			pEffect->unaffect(pCreature);
		}
		*/

		// NoSuch���. by sigi. 2002.5.2
		if (pCreature==NULL)
		{
			return;
		}

		if ( hasEffect() )
		{
			EffectTryingPosition* pTP;
			if ( pCreature->isPC() && (pTP = dynamic_cast<EffectTryingPosition*>(getEffect(Effect::EFFECT_CLASS_TRYING_POSITION))) )
			{
				pTP->unaffect( pCreature );
			}
		}


		// ���带 ����Ѵ�.
		deleteObject(creatureID);

		// �ش��ϴ� ũ��ó �÷��׸� ����.
		FLAG_CLEAR(m_wFlags , TILE_WALKING_CREATURE + pCreature->getMoveMode());
		
		// �ش��ϴ� blocking �÷��׸� ����.
		FLAG_CLEAR(m_wFlags , TILE_GROUND_BLOCKED + pCreature->getMoveMode());
	} 
	catch (Throwable & t) 
	{
		//cerr << "Delete Creature ����.." << endl;
		//cerr << t.toString() << endl;
		filelog("tileError.txt", "Tile::deleteCreature - %s", t.toString().c_str());
	}

	__END_DEBUG
	__END_CATCH
}

//////////////////////////////////////////////////////////////
// Ư� �ġ(���)�� ũ��ó�� ����Ʈ���� ����Ѵ�.
//////////////////////////////////////////////////////////////
void Tile::deleteCreature (Creature::MoveMode mode) 
	throw (NoSuchElementException , Error)
{
	__BEGIN_TRY

	// ���� ũ��ó�� ���� blocking �Ǿ��� �Ѵ�.
	Assert(isBlocked(mode));

	// ���� ũ��ó�� ����ؾ� �Ѵ�.
	Assert(hasCreature(mode));

	if ( hasEffect() )
	{
		EffectTryingPosition* pTP;
		Creature* pCreature = getCreature( mode );
		if ( pCreature != NULL && pCreature->isPC() && (pTP = dynamic_cast<EffectTryingPosition*>(getEffect(Effect::EFFECT_CLASS_TRYING_POSITION))) )
		{
			pTP->unaffect( pCreature );
		}
	}

	// ��ü�� ����Ѵ�.
	deleteObject(OBJECT_PRIORITY_WALKING_CREATURE + mode);

	// �ش��ϴ� ũ��ó �÷��׸� ����.
	FLAG_CLEAR(m_wFlags , TILE_WALKING_CREATURE + mode);
	
	// �ش��ϴ� blocking �÷��׸� ����.
	FLAG_CLEAR(m_wFlags , TILE_GROUND_BLOCKED + mode);

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// Ư� ID�� ���� ũ��ó�� �����Ѵ�.
//////////////////////////////////////////////////////////////
Creature* Tile::getCreature (ObjectID_t creatureID) 
	throw (NoSuchElementException , Error)
{
	__BEGIN_TRY

	Assert(hasWalkingCreature() || hasFlyingCreature() || hasBurrowingCreature());

	return (Creature*)(getObject(creatureID));

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// Ư� �ġ(���)�� ũ��ó�� �����Ѵ�.
//////////////////////////////////////////////////////////////
Creature* Tile::getCreature (Creature::MoveMode mode) 
	throw (NoSuchElementException , Error)
{
	__BEGIN_TRY

	Assert(hasCreature(mode));
	return (Creature*)getObject(ObjectPriority(OBJECT_PRIORITY_WALKING_CREATURE + mode));

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// ������� Ÿ�Ͽ� �߰��Ѵ�. �̹� �������� Ÿ�Ͽ� �ִٸ� Dup ���ܸ� ������.
// (������� Ÿ�ϴ� �ϳ���.)
//////////////////////////////////////////////////////////////
void Tile::addItem (Item* pItem) 
	throw (DuplicatedException , Error)
{
	__BEGIN_TRY

	Assert(pItem != NULL);

	Assert(! hasItem());
	Assert(! hasBuilding());
	Assert(! hasObstacle());
	Assert(! hasPortal());
/*	
	EffectDarkness* pDarkness;
	if ((pDarkness = getEffect(Effect::EFFECT_CLASS_DARKNESS)))
	{
		pDarkness->affectObject(pItem, false);
	}
*/
	addObject(pItem);

	FLAG_SET(m_wFlags , TILE_ITEM);

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// ������� Ÿ�Ͽ��� ����Ѵ�. ������ �ϳ��ۿ� ����Ƿ� Ư���� ����� �ʿ䰡 ����.
//////////////////////////////////////////////////////////////
void Tile::deleteItem () 
	throw (NoSuchElementException , Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	//Assert(hasItem());
	if (!hasItem())
	{
		//cerr << "Tile::hasItem() : �������� ����ϴ�." << endl;
		return;
	}

	deleteObject(OBJECT_PRIORITY_ITEM);

	FLAG_CLEAR(m_wFlags , TILE_ITEM);

	__END_DEBUG
	__END_CATCH
}

//////////////////////////////////////////////////////////////
// Ÿ���� ������� �����Ѵ�. ������ �ϳ��ۿ� ����Ƿ� Ư���� ����� �ʿ䰡 ����.
//////////////////////////////////////////////////////////////
Item* Tile::getItem () 
	throw (NoSuchElementException , Error)
{
	__BEGIN_TRY

	//Assert(hasItem());
	if (!hasItem()) return NULL;

	return (Item*)getObject(OBJECT_PRIORITY_ITEM);

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// ���ֹ�� Ÿ�Ͽ� �߰��Ѵ�.
//////////////////////////////////////////////////////////////
void Tile::addObstacle (Obstacle* pObstacle) 
	throw (DuplicatedException , Error)
{
	__BEGIN_TRY

	Assert(pObstacle != NULL);

	// must be empty tile...
	Assert(! hasWalkingCreature());
	Assert(! hasFlyingCreature());
	Assert(! hasBurrowingCreature());
	Assert(! hasEffect());
	Assert(! hasObstacle());
	Assert(! hasItem());
	Assert(! hasBuilding());
	Assert(! hasPortal());
	Assert(! isTerrain());

	FLAG_SET(m_wFlags , TILE_OBSTACLE);

	addObject(pObstacle);

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// ���ֹ�� Ÿ�Ͽ��� ����Ѵ�. ������ �ϳ��ۿ� ����Ƿ� Ư���� ����� �ʿ䰡 ����.
//////////////////////////////////////////////////////////////
void Tile::deleteObstacle () 
	throw (NoSuchElementException , Error)
{
	__BEGIN_TRY

	Assert(hasObstacle());

	deleteObject(OBJECT_PRIORITY_OBSTACLE);

	FLAG_CLEAR(m_wFlags , TILE_OBSTACLE);

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// Ÿ���� ���ֹ�� �����Ѵ�. ������ �ϳ��ۿ� ����Ƿ� Ư���� ����� �ʿ䰡 ����.
//////////////////////////////////////////////////////////////
Obstacle* Tile::getObstacle () 
	throw (NoSuchElementException , Error)
{
	__BEGIN_TRY

	Assert(hasObstacle());

	return (Obstacle*)getObject(OBJECT_PRIORITY_OBSTACLE);

	__END_CATCH
}

bool Tile::canAddEffect() 
	throw(Error)
{
	return !(hasObstacle() || hasBuilding() || hasPortal());
}

//////////////////////////////////////////////////////////////
// ���� ȿ���� Ÿ�Ͽ� �߰��Ѵ�.
// ���� Ÿ�Ͽ� ũ��ó�� �������� ����Ѵٸ�, ������ ȿ���� ��
// ũ��ó�� �����ۿ� �ο��Ѵ�.
// �ߺ��Ǵ� ������ ���� �å�� �ʿ��ϴ�.... (��� ����� ���ڸ���..)
//////////////////////////////////////////////////////////////
void Tile::addEffect (Effect* pEffect) 
	throw (DuplicatedException , Error)
{
	__BEGIN_TRY

	Assert(pEffect != NULL);

	Assert(! hasObstacle());
	Assert(! hasBuilding());
	Assert(! hasPortal());

	addObject(pEffect);
	
	// ���⼭ ���� Ÿ�Ͽ� ���� ũ��ó�� �����ۿ��� ȿ���� ��ģ��.
	// pEffect->affectTile();

	FLAG_SET(m_wFlags , TILE_EFFECT);

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// Ư� ID�� ���� ���� ȿ���� Ÿ�Ͽ��� ����Ѵ�. 
// ���ÿ� ���� Ÿ���� ũ��ó�� �����ۿ��� �ο��� ���� ȿ�� ����
// ����ؾ� �Ѵ�.
// ���� ȿ���� ����� ��, �ٸ� ������ �����ִٸ� TILE_EFFECT 
// �÷��׸� ���� �ʾƾ� �Ѵ�!
// ����ȭ�� �ʿ伺�� �ִ�.. (search - unaffect - flag clear�� �ѹ���..)
//////////////////////////////////////////////////////////////
void Tile::deleteEffect (ObjectID_t effectID) 
	throw (NoSuchElementException , Error)
{
	__BEGIN_TRY

	Assert(hasEffect());

	// ���� ȿ���� �ϳ� �̻��� �� ����Ƿ�, deleteObject(OBJECT_PRIORITY_EFFECT) � ������ �� ����.
	deleteObject(effectID);

	// ���� Ÿ�Ͽ� ��ģ ����� ���� ������. �� ũ��ó�� �����ۿ� �ο���
	// ���� ȿ���� �����ؾ� �Ѵ�.
	// effect->unaffectTile();

	// �ٸ� ������ ���ٸ� �÷��׸� ����.
	/*
	try 
	{
		getObject(OBJECT_PRIORITY_EFFECT);	
	} 
	catch (NoSuchElementException) 
	{
		// ������ ����Ƿ� ����.
		FLAG_CLEAR(m_wFlags , TILE_EFFECT);
	}
	*/

	// NoSuch���. by sigi. 2002.5.2
	if (getObject(OBJECT_PRIORITY_EFFECT)==NULL)
	{
		FLAG_CLEAR(m_wFlags , TILE_EFFECT);
	}

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// Ư� ID�� ���� ���� ȿ���� �����Ѵ�.
//////////////////////////////////////////////////////////////
Effect* Tile::getEffect (ObjectID_t effectID) 
	throw (NoSuchElementException , Error)
{
	__BEGIN_TRY

	if (hasEffect() == false) return NULL;
	return (Effect*)getObject(effectID);

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// EffectClass�� ���� ���� ȿ���� �����Ѵ�.
//////////////////////////////////////////////////////////////
Effect* Tile::getEffect (Effect::EffectClass effectClass) 
	throw (Error)
{
	__BEGIN_TRY

	if (hasEffect())
	{
		for (list<Object*>::const_iterator itr = m_Objects.begin() ; 
			itr != m_Objects.end() ; 
			itr ++) 
		{
			Effect* pEffect = NULL;
			if ((*itr)->getObjectClass() == Object::OBJECT_CLASS_EFFECT) 
			{
				if (effectClass == ((Effect*)(*itr))->getEffectClass()) 
				{
					// �׷� id �� ���� ��ü�� �߰��� ����
					pEffect = dynamic_cast<Effect*>(*itr);
					return pEffect;
				}
			}
		}
	}

	return NULL;

	__END_CATCH
}



//////////////////////////////////////////////////////////////
// ���� Ÿ��� �ǹ��� ����Ѵ�. 
//////////////////////////////////////////////////////////////
void Tile::addBuilding (BuildingID_t buildingID) 
	throw (Error)
{
	__BEGIN_TRY

	Assert(! hasWalkingCreature());
	Assert(! hasFlyingCreature());
	Assert(! hasBurrowingCreature());
	Assert(! hasEffect());
	Assert(! hasObstacle());
	Assert(! hasItem());
	Assert(! hasBuilding());
	Assert(! hasPortal());
	Assert(! isTerrain());

	FLAG_SET(m_wFlags , TILE_BUILDING);

	m_wOption = buildingID;

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// ���� Ÿ�Ͽ��� �ǹ�� ����Ѵ�. ������ �ϳ��̹Ƿ� Ư���� ����� �ʿ��� ����.
//////////////////////////////////////////////////////////////
void Tile::deleteBuilding () 
	throw (Error)
{
	__BEGIN_TRY

	Assert(hasBuilding());

	FLAG_CLEAR(m_wFlags , TILE_BUILDING);

	m_wOption = 0;

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// ���� Ÿ�Ͽ� �ش��ϴ� �ǹ� ���̵��� �����Ѵ�.
//////////////////////////////////////////////////////////////
BuildingID_t Tile::getBuilding () const 
	throw (Error)
{
	__BEGIN_TRY

	Assert(hasBuilding());

	return m_wOption;

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// ��Ż� Ÿ�Ͽ� �߰��Ѵ�.
//////////////////////////////////////////////////////////////
void Tile::addPortal (Portal* pPortal) 
	throw (Error)
{
	__BEGIN_TRY

	Assert(pPortal != NULL);

	// �ϴ�� ���ƴٴϴ� ũ��ó�� ���ӿ� �����ִ� ũ��ó�� ��Ż�� ����� ��� ���ΰ�? �� ���ΰ�?
	// ��ư �ƹ� �͵� ���� �� Ÿ���̾��� �Ѵ�!!!!!!!!!!!!!!!!!!!!
	Assert(!hasWalkingCreature());
	Assert(!hasFlyingCreature());
	Assert(!hasBurrowingCreature());
	Assert(!hasEffect());
	Assert(!hasObstacle());
	Assert(!hasItem());
	Assert(!hasBuilding());
	Assert(!hasPortal());
	Assert(!isTerrain());

	addObject(pPortal);

	FLAG_SET(m_wFlags , TILE_PORTAL);

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// ��Ż� Ÿ�Ͽ��� ����Ѵ�. ������ �ϳ��̹Ƿ� Ư���� ����� �ʿ䰡 ����.
//////////////////////////////////////////////////////////////
void Tile::deletePortal () 
	throw (Error)
{
	__BEGIN_TRY

	Assert(hasPortal());

	deleteObject(OBJECT_PRIORITY_PORTAL);

	FLAG_CLEAR(m_wFlags , TILE_PORTAL);

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// ��Ż ��ü�� �����Ѵ�.
//////////////////////////////////////////////////////////////
Portal* Tile::getPortal () const 
	throw (Error)
{
	__BEGIN_TRY

	Assert(hasPortal());

	return (Portal*)getObject(OBJECT_PRIORITY_PORTAL);

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// terrain � Ÿ�Ͽ� �߰��Ѵ�. 
//////////////////////////////////////////////////////////////
void Tile::addTerrain (TerrainID_t terrainID) 
	throw (Error)
{
	__BEGIN_TRY

	// ���� Ÿ�Ͽ� m_wOption � �����ϴ� ��ü�� ���ֹ�, �ǹ�, ��Ż
	// ���� �ִٸ� ������.. �� ������� üũ������ �Ѵ�.
	Assert(! hasObstacle());
	Assert(! hasBuilding());
	Assert(! hasPortal());

	// Terrain �÷��׸� �Ҵ�.
	FLAG_SET(m_wFlags , TILE_TERRAIN);

	// �ɼ�� Terrain ID �� ����Ѵ�.
	m_wOption = terrainID;

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// terrain � Ÿ�Ͽ��� ����Ѵ�.
//////////////////////////////////////////////////////////////
void Tile::deleteTerrain () 
	throw (Error)
{
	__BEGIN_TRY

	Assert(isTerrain());

	// Terrain �÷��׸� �Ҵ�.
	FLAG_CLEAR(m_wFlags , TILE_TERRAIN);

	// �ɼ�� Ŭ�����Ѵ�.
	m_wOption = 0;

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// terrain ���̵��� �����Ѵ�.
//////////////////////////////////////////////////////////////
TerrainID_t Tile::getTerrain () const 
	throw (Error)
{
	__BEGIN_TRY

	Assert(isTerrain());

	return m_wOption;

	__END_CATCH
}


//////////////////////////////////////////////////////////////
// get debug string
//////////////////////////////////////////////////////////////
string Tile::toString () const 
	throw ()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "Tile(";
	msg << "Flag:" << m_wFlags;
	msg << "\nObjects:";
	list<Object*>::const_iterator itr = m_Objects.begin();
	for (; itr != m_Objects.end(); itr++)
	{
		msg << (*itr)->toString() << "\n";
	}

	msg << "TileOption:" << (int)m_wOption;
	msg << ")";

	return msg.toString();

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// add object into object list
//////////////////////////////////////////////////////////////
void Tile::addObject (Object* pObject) 
	throw (DuplicatedException)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Assert(pObject != NULL);
	Assert(pObject->getObjectID()!= 0);

	list<Object*>::iterator before = m_Objects.end();
	list<Object*>::iterator current = m_Objects.begin();

	/*
	// �켱 ���Ϳ� �����ִ´�.
	m_pSector->addObject(pObject);
	*/

	for (; current != m_Objects.end() ; before = current , current ++) 
	{
		// ��ü ����Ʈ�� ����������� ��ĵǾ� �ִ�.
		// ������, �����Ϸ�� ��ü�� ObjectPriority�� ���� iterator�� ����Ű��
		// ��ü�� ObjectPriority���� ��� ������ ����� ����� �Ѵ�.

		if (pObject->getObjectPriority() < (*current)->getObjectPriority()) 
		{
			if (before == m_Objects.end()) 
			{
				// ��ü�� Ÿ�� �켱����� ���� ����Ƿ� ����Ʈ�� �� �տ� �ִ´�.
				m_Objects.push_front(pObject);
			} 
			else 
			{
				// ����Ʈ�� ����� �ִ´�.
				// O(1) insertion
				m_Objects.insert(current , pObject);
			}
			return;
		} 
		else if (pObject->getObjectPriority() == (*current)->getObjectPriority()) 
		{
			// effect�� �ߺ��� �� �ִ�.
			if (pObject->getObjectPriority() == OBJECT_PRIORITY_EFFECT)
			{
				if (before == m_Objects.end())
				{
					m_Objects.push_front(pObject);
				}
				else
				{
					m_Objects.insert(current , pObject);
				}
				return;
			}
			else
			{	
				cerr << toString() << endl;
				cerr << "������ tile priority ��� = " << (int)pObject->getObjectPriority() << endl;
				cerr << "�÷��� ��� = " << m_wFlags << endl;
				filelog("TILEBUG.log", "%s", toString().c_str());
				throw DuplicatedException("tile priority duplicated");
			}
		}
	}

	// ��� ������� ������ �ġ�� ã�� ����� ������ 
	// (1) ����Ʈ�� ��ü�� �ϳ��� ���� ����, 
	// (2) ����Ʈ�� �� �ڿ� �־��� �Ǵ� ����.. �� �ִ�.
	if (current == m_Objects.end()) 
	{
		if (before == m_Objects.end())
		{
			// ����Ʈ�� ���� �ֱ� ������, ����Ʈ�� �� �տ� �ִ´�.
			m_Objects.push_front(pObject);
		}
		else
		{
			// OBJECT_PRIORITY�� ���� ū ��ü�̹Ƿ�, ����Ʈ�� �� �ڿ� �ִ´�.
			// O(1) insertion
			m_Objects.insert(current , pObject);
		}
	}

	__END_DEBUG
	__END_CATCH
}
	
//////////////////////////////////////////////////////////////
// Delete object from object list
//////////////////////////////////////////////////////////////
void Tile::deleteObject (ObjectID_t objectID) 
	throw (NoSuchElementException)
{
	__BEGIN_TRY

	/*
	// ���� ���Ϳ��� ����Ѵ�.
	m_pSector->deleteObject(objectID);
	*/
/*
	list<Object*>::iterator before = m_Objects.end();
	list<Object*>::iterator current = m_Objects.begin();

	int i = 0;
	for (; current != m_Objects.end() ; before = current++) 
	{
		if (objectID == (*current)->getObjectID()) 
		{
			// �׷� id �� ���� ��ü�� �߰��� ����
			if (before == m_Objects.end()) 
			{
				// Delete first node
				m_Objects.pop_front();
			}
			else 
			{
				// O(1) deletion
				//m_Objects.erase_after(before);
				m_Objects.
			}

			return;
		}
		i++;
	}
*/

	for(list<Object*>::iterator it= m_Objects.begin(); it != m_Objects.end(); it++)
	{
		if(objectID == (*it)->getObjectID())
		{
			m_Objects.erase(it);
			return;
		}
	}

	Assert(false);
	
	/*
	if (before == m_Objects.end())
	{
		cout << objectID << "�ƹ��͵� ����" << endl;
	}
	else
	{
		cout << objectID << " " << (*before)->getObjectID() << endl;
	}
	*/

	// NoSuch���. by sigi. 2002.5.2
	//throw NoSuchElementException("invalid object id");

	__END_CATCH
}
	
//////////////////////////////////////////////////////////////
// Ư� Tile Priority�� ���� ��ü�� ����Ѵ�.
//////////////////////////////////////////////////////////////
void Tile::deleteObject (ObjectPriority objectPriority) 
	throw (NoSuchElementException)
{
	__BEGIN_TRY


	/*
	// ���� ���Ϳ��� �������...
	Object* pObject = getObject(objectPriority);
	m_pSector->deleteObject(pObject->getObjectID());
	*/
/*
	list<Object*>::iterator before = m_Objects.end();
	list<Object*>::iterator current = m_Objects.begin() ;
	for (; current != m_Objects.end() ; before = current ++) 
	{
		if (objectPriority == (*current)->getObjectPriority()) 
		{
			// �׷� tp �� ���� ��ü�� �߰��� ����
			if (before == m_Objects.end()) 
			{
				// Delete first node
				m_Objects.pop_front();
			} 
			else 
			{
				// O(1) deletion
				m_Objects.erase_after(before);
			}

			return;
		} 
		else if (objectPriority < (*current)->getObjectPriority()) 
		{
			// ����Ʈ�� ��ü�� tp �� ����������� ��ĵǾ� ����Ƿ�,
			// ã���� �ϴ� ��ü�� tp ���� ���� iterator�� tp �� ũ�ٸ�
			// �׷� id �� ���� ��ü�� ������� �ʴ´�.
			// ex> [0] - [3] - [4] ���� [3]� iterator�� ����ų ��, ���� tp �� 2�� ����
			break;
		}
	}
*/
	for(list<Object*>::iterator it= m_Objects.begin(); it != m_Objects.end(); it++)
	{
		if(objectPriority == (*it)->getObjectPriority())
		{
			m_Objects.erase(it);
			return;
		} else if (objectPriority < (*it)->getObjectPriority())
		{
			break;
		}
	}

	// NoSuch���. by sigi. 2002.5.2
	//throw NoSuchElementException("invalid object priority");

	__END_CATCH
}
//////////////////////////////////////////////////////////////
// ���� Ÿ�Ͽ��� Ư� ID�� ���� ����Ʈ�� �����Ѵ�.
// ����Ʈ�� ���� �˻��ؾ� �Ѵ�.
//////////////////////////////////////////////////////////////
Object* Tile::getObject (ObjectID_t objectID) const
	throw (NoSuchElementException)
{
	__BEGIN_TRY

	for (list<Object*>::const_iterator itr = m_Objects.begin(); itr != m_Objects.end() ; itr ++) 
	{
		if (objectID == (*itr)->getObjectID()) 
		{
			// �׷� id �� ���� ��ü�� �߰��� ����
			return *itr;
		}
	}

	// �׷� id �� ���� ��ü�� ������� �ʴ´�.
	// NoSuch���. by sigi. 2002.5.2
	//throw NoSuchElementException("invalid object id");

	// warning ������.. - -;
	return NULL;

	__END_CATCH
}

//////////////////////////////////////////////////////////////
// Ư� Tile Priority �� ���� ��ü�� �����Ѵ�.
//////////////////////////////////////////////////////////////
Object* Tile::getObject (ObjectPriority objectPriority) const
	throw (NoSuchElementException)
{
	__BEGIN_TRY

	for (list<Object*>::const_iterator itr = m_Objects.begin() ; itr != m_Objects.end() ; itr ++) 
	{
		if (objectPriority == (*itr)->getObjectPriority()) 
		{
			// �׷� id �� ���� ��ü�� �߰��� ����
			return *itr;
		} 
		else if (objectPriority < (*itr)->getObjectPriority()) 
		{
			// ����Ʈ�� ��ü�� tp �� ����������� ��ĵǾ� ����Ƿ�,
			// ã���� �ϴ� ��ü�� tp ���� ���� iterator�� tp �� ũ�ٸ�
			// �׷� id �� ���� ��ü�� ������� �ʴ´�.
			// ex> [0] - [3] - [4] ���� [3]� iterator�� ����ų ��, ���� tp �� 2�� ����
			break;
		}
	}

	// NoSuch���. by sigi. 2002.5.2
	//throw NoSuchElementException("invalid tile priority");
	return NULL;

	__END_CATCH
}
