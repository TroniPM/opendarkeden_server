//////////////////////////////////////////////////////////////////////////////
// Filename    : MagicElusion.cpp
// Written by  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "MagicElusion.h"
#include "EffectMagicElusion.h"
#include "SkillUtil.h"
#include "Slayer.h"
#include "Player.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCSkillToTileOK1.h"
#include "Gpackets/GCSkillToTileOK2.h"
#include "Gpackets/GCSkillToTileOK3.h"
#include "Gpackets/GCSkillToTileOK4.h"
#include "Gpackets/GCSkillToTileOK5.h"
#include "Gpackets/GCSkillToTileOK6.h"
#include "Gpackets/GCAddEffectToTile.h"
#include "Gpackets/GCSkillFailed1.h"

//////////////////////////////////////////////////////////////////////////////
// �����̾� Ÿ�� �ڵ鷯
//////////////////////////////////////////////////////////////////////////////
void MagicElusion::execute(Slayer* pSlayer, ZoneCoord_t X, ZoneCoord_t Y, SkillSlot* pSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	__BEGIN_TRY

	//cout << "TID[" << Thread::self() << "]" << getSkillHandlerName() << " Begin" << endl;

	Assert(pSlayer != NULL);
	Assert(pSkillSlot != NULL);

	try 
	{
		Player* pPlayer = pSlayer->getPlayer();
		Zone* pZone = pSlayer->getZone();

		Assert(pPlayer != NULL);
		Assert(pZone != NULL);

		GCSkillToTileOK1 _GCSkillToTileOK1;
		GCSkillToTileOK2 _GCSkillToTileOK2;
		GCSkillToTileOK3 _GCSkillToTileOK3;
		GCSkillToTileOK4 _GCSkillToTileOK4;
		GCSkillToTileOK5 _GCSkillToTileOK5;
		GCSkillToTileOK6 _GCSkillToTileOK6;

		SkillType_t SkillType  = pSkillSlot->getSkillType();
		SkillInfo*  pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);

		ZoneCoord_t myX = pSlayer->getX();
		ZoneCoord_t myY = pSlayer->getY();

		int  RequiredMP  = (int)pSkillInfo->getConsumeMP();
		bool bManaCheck  = hasEnoughMana(pSlayer, RequiredMP);
		bool bTimeCheck  = verifyRunTime(pSkillSlot);
		bool bRangeCheck = verifyDistance(pSlayer, X, Y, pSkillInfo->getRange()) && checkZoneLevelToUseSkill(pSlayer);
		bool bHitRoll    = HitRoll::isSuccessMagicElusion(pSlayer);
		
		bool bTileCheck = false;
		VSRect rect(0, 0, pZone->getWidth()-1, pZone->getHeight()-1);
		if (rect.ptInRect(X, Y)) bTileCheck = true;

		// ����Ʈ�� ���ӽð�� �����Ѵ�.
		SkillInput input(pSlayer, pSkillSlot);
		SkillOutput output;
		computeOutput(input, output);


		if (bManaCheck && bTimeCheck && bRangeCheck && bHitRoll && bTileCheck)
		{
			decreaseMana(pSlayer, RequiredMP, _GCSkillToTileOK1);

			Range_t    Range    = 2;

			int oX, oY;
			
			list<Creature*> cList;	// denier list
			
			ObjectRegistry & objectregister = pZone->getObjectRegistry();

			// �ϴ� �̹� sanctuary�� �ִ��� �˻��Ѵ�.
			for(oY = -1; oY <= 1; oY++)
			for(oX = -1; oX <= 1; oX++)
			{
				int tileX = X+oX;
				int tileY = Y+oY;
				if (rect.ptInRect(tileX, tileY))
				{
					Tile& tile = pZone->getTile(tileX, tileY);

					if (tile.canAddEffect())
					{
						Effect* pOldEffect = tile.getEffect(Effect::EFFECT_CLASS_MAGIC_ELUSION);

						// �̹� �ִٸ�
						// ���� ���д�.
						if (pOldEffect != NULL)
						{
							executeSkillFailNormal(pSlayer, getSkillType(), NULL);

							return;
						}
					}
					else
					{
						executeSkillFailNormal(pSlayer, getSkillType(), NULL);
						return;
					}
				}
			}

			for(oY = -1; oY <= 1; oY++)
			for(oX = -1; oX <= 1; oX++)
			{
				int tileX = X+oX;
				int tileY = Y+oY;
				if (rect.ptInRect(tileX, tileY))
				{
					Tile& tile = pZone->getTile(tileX, tileY);

					// ����Ʈ Ŭ������ �����Ѵ�.
					EffectMagicElusion* pEffect = new EffectMagicElusion(pZone , tileX, tileY);
					pEffect->setDeadline(output.Duration);

					// Tile�� ���̴� Effect�� ObjectID�� ���Ϲ޾ƾ� �Ѵ�.
					objectregister.registerObject(pEffect);
					pZone->addEffect(pEffect);
					tile.addEffect(pEffect);

					if (oX==0 && oY==0)
					{
						pEffect->setBroadcastingEffect(true);
						GCAddEffectToTile gcAddEffectToTile;
						gcAddEffectToTile.setEffectID(pEffect->getEffectClass());
						gcAddEffectToTile.setObjectID(pEffect->getObjectID());
						gcAddEffectToTile.setXY(X, Y);
						gcAddEffectToTile.setDuration(output.Duration);

						pZone->broadcastPacket(X, Y, &gcAddEffectToTile, pSlayer);
					}
					else
					{
						// ��� ����Ʈ�� �ƴϸ� ���ε�ĳ���������� �ʴ´�.
						pEffect->setBroadcastingEffect(false);
					}

					const list<Object*>& oList = tile.getObjectList();
					for(list<Object*>::const_iterator itr = oList.begin(); itr != oList.end(); itr++) 
					{
						Object* pTarget = *itr;
						if ( pTarget->getObjectClass() == Object::OBJECT_CLASS_CREATURE )
						{
							Creature* pCreature = dynamic_cast<Creature*>(pTarget);
							Assert( pCreature != NULL );
							
							if ( pCreature->isVampire() )
							{
								Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);
								Assert( pVampire != NULL );

								GCModifyInformation gcMI;
								::setDamage( pVampire, output.Damage, pSlayer, pSkillSlot->getSkillType(), &gcMI );

								pVampire->getPlayer()->sendPacket( &gcMI );
								cList.push_back(pCreature);
							}
							else if ( pCreature->isMonster() )
							{
								::setDamage( pCreature, output.Damage, pSlayer, pSkillSlot->getSkillType() );
							}
						}
					}
				}
			}

			_GCSkillToTileOK1.setSkillType(SkillType);
			_GCSkillToTileOK1.setCEffectID(CEffectID);
			_GCSkillToTileOK1.setX(X);
			_GCSkillToTileOK1.setY(Y);
			_GCSkillToTileOK1.setDuration(output.Duration);
			_GCSkillToTileOK1.setRange(Range);

			_GCSkillToTileOK2.setObjectID(pSlayer->getObjectID());
			_GCSkillToTileOK2.setSkillType(SkillType);
			_GCSkillToTileOK2.setX(X);
			_GCSkillToTileOK2.setY(Y);
			_GCSkillToTileOK2.setDuration(output.Duration);
			_GCSkillToTileOK2.setRange(Range);

			_GCSkillToTileOK3.setObjectID(pSlayer->getObjectID());
			_GCSkillToTileOK3.setSkillType(SkillType);
			_GCSkillToTileOK3.setX(X);
			_GCSkillToTileOK3.setY(Y);

			_GCSkillToTileOK4.setSkillType(SkillType);
			_GCSkillToTileOK4.setX(X);
			_GCSkillToTileOK4.setY(Y);
			_GCSkillToTileOK4.setRange(Range);
			_GCSkillToTileOK4.setDuration(output.Duration);

			_GCSkillToTileOK5.setObjectID(pSlayer->getObjectID());
			_GCSkillToTileOK5.setSkillType(SkillType);
			_GCSkillToTileOK5.setX(X);
			_GCSkillToTileOK5.setY(Y);
			_GCSkillToTileOK5.setRange(Range);
			_GCSkillToTileOK5.setDuration(output.Duration);

			_GCSkillToTileOK6.setOrgXY(myX, myY);
			_GCSkillToTileOK6.setSkillType(SkillType);
			_GCSkillToTileOK6.setX(X);
			_GCSkillToTileOK6.setY(Y);
			_GCSkillToTileOK6.setDuration(output.Duration);
			_GCSkillToTileOK6.setRange(Range);

			for(list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); itr++)
			{
				Creature* pTargetCreature = *itr;
				if (canSee(pTargetCreature, pSlayer)) pTargetCreature->getPlayer()->sendPacket(&_GCSkillToTileOK2);
				else pTargetCreature->getPlayer()->sendPacket(&_GCSkillToTileOK6);
			}

			pPlayer->sendPacket(&_GCSkillToTileOK1);

			cList.push_back(pSlayer);

			list<Creature*> watcherList = pZone->getWatcherList(myX, myY, pSlayer);

			// watcherList���� cList�� ������ �ʰ�, caster(pSlayer)�� �� �� ���� ������
			// OK4�� ������.. cList�� �߰��Ѵ�.
			for(list<Creature*>::const_iterator itr = watcherList.begin(); itr != watcherList.end(); itr++)
			{
				bool bBelong = false;
				for(list<Creature*>::const_iterator tItr = cList.begin(); tItr != cList.end(); tItr++)
					if (*itr == *tItr)
						bBelong = true;

				Creature* pWatcher = (*itr);
				if (bBelong == false && canSee(pWatcher, pSlayer) == false)
				{
					//Assert(pWatcher->isPC());	// �翬 PC��.. Zone::getWatcherList�� PC�� return�Ѵ�
					if (pWatcher->isPC())
					{
						pWatcher->getPlayer()->sendPacket(&_GCSkillToTileOK4);
						cList.push_back(*itr);
					}
				}
			}

			cList = pZone->broadcastSkillPacket(myX, myY, X, Y, &_GCSkillToTileOK5, cList, false);

			pZone->broadcastPacket(myX, myY,  &_GCSkillToTileOK3 , cList);

			pZone->broadcastPacket(X, Y,  &_GCSkillToTileOK4 , cList);
		} 
		else 
		{
			executeSkillFailNormal(pSlayer, getSkillType(), NULL);
		}

		if ( bTimeCheck ) pSkillSlot->setRunTime(output.Delay);
	} 
	catch (Throwable & t) 
	{
		executeSkillFailException(pSlayer, getSkillType());
	}

	//cout << "TID[" << Thread::self() << "]" << getSkillHandlerName() << " End" << endl;


	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// �����̾� ���� �ڵ鷯
//////////////////////////////////////////////////////////////////////////////
void MagicElusion::execute(Slayer* pSlayer, SkillSlot* pSkillSlot, CEffectID_t CEffectID)
	throw (Error)
{
	execute(pSlayer, pSlayer->getX(), pSlayer->getY(), pSkillSlot, CEffectID);
}

MagicElusion g_MagicElusion;
