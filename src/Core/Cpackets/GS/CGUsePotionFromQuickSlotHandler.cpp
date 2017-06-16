//////////////////////////////////////////////////////////////////////////////
// Filename    : CGUsePotionFromQuickSlotHandler.cc
// Written By  : elca@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "CGUsePotionFromQuickSlot.h"

#ifdef __GAME_SERVER__
	#include "GamePlayer.h"
	#include "Zone.h"
	#include "Slayer.h"
	#include "Ousters.h"
	#include "Inventory.h"
	#include "Item.h"
	#include "ItemInfo.h"
	#include "ItemUtil.h"
	#include <math.h>
	#include "EffectHPRecovery.h"
	#include "EffectMPRecovery.h"

	#include "item/Belt.h"
	#include "item/OustersArmsband.h"
	#include "item/Potion.h"
	#include "item/Pupa.h"
	#include "item/ComposMei.h"

	#include "Gpackets/GCHPRecoveryStartToSelf.h"
	#include "Gpackets/GCHPRecoveryStartToOthers.h"
	#include "Gpackets/GCMPRecoveryStart.h"
	#include "Gpackets/GCUseOK.h"
	#include "Gpackets/GCCannotUse.h"
#endif

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void CGUsePotionFromQuickSlotHandler::execute (CGUsePotionFromQuickSlot* pPacket , Player* pPlayer)
	throw (ProtocolException, Error)
{
	__BEGIN_TRY __BEGIN_DEBUG_EX

#ifdef __GAME_SERVER__

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);
	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
	Creature*   pCreature   = pGamePlayer->getCreature();

	try 
	{
		if ( pCreature->isSlayer() )
		{
			GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
			Creature*   pCreature   = pGamePlayer->getCreature();

			if (!pCreature->isSlayer()) return;

			// 코마 상태라면 사용할 수 없다.
			if (pCreature->isFlag(Effect::EFFECT_CLASS_COMA))
			{
				GCCannotUse _GCCannotUse;
				_GCCannotUse.setObjectID(pPacket->getObjectID());
				pGamePlayer->sendPacket(&_GCCannotUse);
				return;
			}

			Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);
			Zone*   pZone   = pSlayer->getZone();
			Item*   pBelt   = pSlayer->getWearItem(Slayer::WEAR_BELT);
			
			if (pBelt == NULL)
			{
				GCCannotUse _GCCannotUse;
				_GCCannotUse.setObjectID(pPacket->getObjectID());
				pGamePlayer->sendPacket(&_GCCannotUse);
				return;
			}

			// 벨트의 인벤토리를 받아온다.
			Inventory* pBeltInventory = ((Belt*)pBelt)->getInventory();
			
			// SlotID를 받는다.
			SlotID_t SlotID = pPacket->getSlotID();

			// 슬랏의 범위를 초과하면 사용할 수 없다.
			if (SlotID >= pBeltInventory->getWidth())
			{
				GCCannotUse _GCCannotUse;
				_GCCannotUse.setObjectID(pPacket->getObjectID());
				pGamePlayer->sendPacket(&_GCCannotUse);
				return;
			}
			
			// 벨트의 지정 슬랏의 아이템을 받아온다.
			Item* pBeltItem = pBeltInventory->getItem(SlotID, 0);
			
			// 아이템이 없으면 당연히 사용할 수 없다.
			if (pBeltItem == NULL)
			{
				GCCannotUse _GCCannotUse;
				_GCCannotUse.setObjectID(pPacket->getObjectID());
				pGamePlayer->sendPacket(&_GCCannotUse);
				return;
			}
			
			// 슬랏에 있는 아이템의 Object를 받는다.
			ObjectID_t ItemObjectID = pBeltItem->getObjectID();

			// 데이터가 일치하지 않거나, 포션이 아니라면 사용할 수 없다.
			if (ItemObjectID != pPacket->getObjectID() || pBeltItem->getItemClass() != Item::ITEM_CLASS_POTION)
			{
				GCCannotUse _GCCannotUse;
				_GCCannotUse.setObjectID(pPacket->getObjectID());
				pGamePlayer->sendPacket(&_GCCannotUse);
				return;
			}

			HP_t    MaxHP        = pSlayer->getHP(ATTR_MAX);
			HP_t    CurrentHP    = pSlayer->getHP(ATTR_CURRENT);
			MP_t    MaxMP        = pSlayer->getMP(ATTR_MAX);
			MP_t    CurrentMP    = pSlayer->getMP(ATTR_CURRENT);
			Potion* pPotion      = dynamic_cast<Potion*>(pBeltItem);

			// 한턴에 회복되는 양
			int		HPQuantity = pPotion->getHPQuantity();
			int		MPQuantity = pPotion->getMPQuantity();

			// 한턴이 몇초 인가.
			int		HPDelayProvider = pPotion->getHPDelay();
			int		MPDelayProvider = pPotion->getMPDelay();

			Attr_t INT = pSlayer->getINT();

			HP_t    PotionHPAmount = 0, PotionMPAmount = 0;

			PotionHPAmount = pPotion->getHPAmount();
			PotionMPAmount = pPotion->getMPAmount();

			int     HPAmount     = min(MaxHP - CurrentHP , (int)PotionHPAmount);
			int     MPAmount     = min(MaxMP - CurrentMP , (int)(pPotion->getMPAmount()* (1 + (double)((double)INT / 300.0))));
			bool    notRecoverHP = false;
			bool    notRecoverMP = false;

			// Activation Effect가 걸려있다면 회복속도가 2배가 된다.
			if (pSlayer->isFlag(Effect::EFFECT_CLASS_ACTIVATION))
			{
				if ( pPotion->getItemType() >= 14 && pPotion->getItemType() <= 17 )
				{
				}
				else
				{
					HPDelayProvider = (HPDelayProvider>>1);
					MPDelayProvider = (MPDelayProvider>>1);

					HPDelayProvider = max(HPDelayProvider, 1);
					MPDelayProvider = max(MPDelayProvider, 1);
				}
			}


			// HP 회복양이 존재한다면...
			if (HPAmount != 0 && HPQuantity != 0)
			{
				if (CurrentHP < MaxHP) 
				{
					EffectManager* pEffectManager = pSlayer->getEffectManager();

					double temp     = (double)((double)HPAmount/(double)HPQuantity);
					uint   Period   = (uint)ceil(temp);
					Turn_t Deadline = Period* HPDelayProvider;

					if (pSlayer->isFlag(Effect::EFFECT_CLASS_HP_RECOVERY)) 
					{
						Effect* pEffect = pEffectManager->findEffect(Effect::EFFECT_CLASS_HP_RECOVERY);
						EffectHPRecovery* pEffectHPRecoveryEffect = dynamic_cast<EffectHPRecovery*>(pEffect);

						// 기존의 단위양과 횟수로 채우는 HP양을 계산한다.
						// 그것을 현재 회복양에 더한다.
						int PrevHPAmount = pEffectHPRecoveryEffect->getHPQuantity()* pEffectHPRecoveryEffect->getPeriod();
						HPAmount = min((int)(HPAmount + PrevHPAmount), MaxHP - CurrentHP);

						// 둘 중에 큰 단위회복양과 작은 딜레이를 얻어낸다.
						HPQuantity      = max(HPQuantity,      (int)(pEffectHPRecoveryEffect->getHPQuantity()));
						HPDelayProvider = min(HPDelayProvider, (int)(pEffectHPRecoveryEffect->getDelay()));

						// 현재 회복양을 가지고, 얼마씩 몇번에 회복할 것인가를 결정한다.
						temp     = (double)((double)HPAmount/(double)HPQuantity);
						Period   = (uint)ceil(temp);
						Deadline = Period* HPDelayProvider;

						// HP Recovery effect를 갱신한다.
						pEffectHPRecoveryEffect->setDeadline(Deadline);
						pEffectHPRecoveryEffect->setDelay(HPDelayProvider);
						pEffectHPRecoveryEffect->setHPQuantity(HPQuantity);
						pEffectHPRecoveryEffect->setPeriod(Period);

						// 회복 시작하라는 패킷을 자신에게 보낸다.
						GCHPRecoveryStartToSelf gcHPRecoveryStartToSelf;
						gcHPRecoveryStartToSelf.setPeriod(pEffectHPRecoveryEffect->getPeriod());
						gcHPRecoveryStartToSelf.setDelay(pEffectHPRecoveryEffect->getDelay());
						gcHPRecoveryStartToSelf.setQuantity(pEffectHPRecoveryEffect->getHPQuantity());

						pGamePlayer->sendPacket(&gcHPRecoveryStartToSelf);

						// 회복 시작하라는 패킷을 다른이들에게 보낸다.
						// 회복 갱신 패킷, 시작과 똑 같은 패킷을 보낸다.
						GCHPRecoveryStartToOthers gcHPRecoveryStartToOthers;
						gcHPRecoveryStartToOthers.setObjectID(pSlayer->getObjectID());
						gcHPRecoveryStartToOthers.setPeriod(pEffectHPRecoveryEffect->getPeriod());
						gcHPRecoveryStartToOthers.setDelay(pEffectHPRecoveryEffect->getDelay());
						gcHPRecoveryStartToOthers.setQuantity(pEffectHPRecoveryEffect->getHPQuantity());

						pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(), &gcHPRecoveryStartToOthers, pSlayer);
						GCUseOK _GCUseOK;
						pGamePlayer->sendPacket(&_GCUseOK);
					} 
					else 
					{
						EffectHPRecovery* pEffectHPRecovery = new EffectHPRecovery();

						pEffectHPRecovery->setTarget(pSlayer);
						pEffectHPRecovery->setDeadline(Deadline);
						pEffectHPRecovery->setDelay(HPDelayProvider);
						pEffectHPRecovery->setNextTime(0);
						pEffectHPRecovery->setHPQuantity(HPQuantity);
						pEffectHPRecovery->setPeriod(Period);

						pEffectManager->addEffect(pEffectHPRecovery);

						// 회복 시작하라는 패킷을 자신에게 보낸다.
						GCHPRecoveryStartToSelf gcHPRecoveryStartToSelf;
						gcHPRecoveryStartToSelf.setPeriod(Period);
						gcHPRecoveryStartToSelf.setDelay(HPDelayProvider);
						gcHPRecoveryStartToSelf.setQuantity(HPQuantity);

						pGamePlayer->sendPacket(&gcHPRecoveryStartToSelf);

						// 회복 시작하라는 패킷을 보는이들에게 보낸다.
						GCHPRecoveryStartToOthers gcHPRecoveryStartToOthers;
						gcHPRecoveryStartToOthers.setObjectID(pSlayer->getObjectID());
						gcHPRecoveryStartToOthers.setPeriod(Period);
						gcHPRecoveryStartToOthers.setDelay(HPDelayProvider);
						gcHPRecoveryStartToOthers.setQuantity(HPQuantity);

						pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(), &gcHPRecoveryStartToOthers, pSlayer);
						GCUseOK _GCUseOK;
						pGamePlayer->sendPacket(&_GCUseOK);
					}
				} 
				else 
				{
					GCCannotUse _GCCannotUse;
					_GCCannotUse.setObjectID(pPacket->getObjectID());
					pGamePlayer->sendPacket(&_GCCannotUse);
					return;
				}
			} 
			else 
			{
				notRecoverHP = true;
			}

			// MP 회복양이 존재한다면...
			if (MPAmount != 0 && MPQuantity != 0 )
			{
				// 얼마씩 몇번 몇초마다.
				if (CurrentMP < MaxMP) 
				{
					EffectManager* pEffectManager = pSlayer->getEffectManager();

					double temp     = (double)((double)MPAmount/(double)MPQuantity);
					uint   Period   = (uint)ceil(temp);
					Turn_t Deadline = Period* MPDelayProvider;

					if (pSlayer->isFlag(Effect::EFFECT_CLASS_MP_RECOVERY)) 
					{
						Effect* pEffect = pEffectManager->findEffect(Effect::EFFECT_CLASS_MP_RECOVERY);
						EffectMPRecovery* pEffectMPRecoveryEffect = dynamic_cast<EffectMPRecovery*>(pEffect);

						// 기존의 단위양과 횟수로 채우는 MP양을 계산한다.
						// 그것을 현재 회복양에 더한다.
						int PrevMPAmount = pEffectMPRecoveryEffect->getMPQuantity()* pEffectMPRecoveryEffect->getPeriod();
						MPAmount = min((int)(MPAmount + PrevMPAmount), MaxMP - CurrentMP);

						// 둘 중에 큰 단위회복양과 작은 딜레이를 얻어낸다.
						MPQuantity      = max(MPQuantity,      (int)(pEffectMPRecoveryEffect->getMPQuantity()));
						MPDelayProvider = min(MPDelayProvider, (int)(pEffectMPRecoveryEffect->getDelay()));

						// 현재 회복양을 가지고, 얼마씩 몇번에 회복할 것인가를 결정한다.
						temp     = (double)((double)MPAmount/(double)MPQuantity);
						Period   = (uint)ceil(temp);
						Deadline = Period* MPDelayProvider;

						// MP Recovery effect를 갱신한다.
						pEffectMPRecoveryEffect->setDeadline(Deadline);
						pEffectMPRecoveryEffect->setDelay(MPDelayProvider);
						pEffectMPRecoveryEffect->setMPQuantity(MPQuantity);
						pEffectMPRecoveryEffect->setPeriod(Period);

						// 회복 시작하라는 패킷을 자신에게 보낸다.
						GCMPRecoveryStart gcMPRecoveryStart;
						gcMPRecoveryStart.setPeriod(pEffectMPRecoveryEffect->getPeriod());
						gcMPRecoveryStart.setDelay(pEffectMPRecoveryEffect->getDelay());
						gcMPRecoveryStart.setQuantity(pEffectMPRecoveryEffect->getMPQuantity());

						pGamePlayer->sendPacket(&gcMPRecoveryStart);

						GCUseOK _GCUseOK;
						pGamePlayer->sendPacket(&_GCUseOK);
					} 
					else 
					{
						EffectMPRecovery* pEffectMPRecovery = new EffectMPRecovery();

						pEffectMPRecovery->setTarget(pSlayer);
						pEffectMPRecovery->setDeadline(Deadline);
						pEffectMPRecovery->setDelay(MPDelayProvider);
						pEffectMPRecovery->setNextTime(0);
						pEffectMPRecovery->setMPQuantity(MPQuantity);
						pEffectMPRecovery->setPeriod(Period);

						pEffectManager->addEffect(pEffectMPRecovery);

						// 회복 시작하라는 패킷을 자신에게 보낸다.
						GCMPRecoveryStart gcMPRecoveryStart;
						gcMPRecoveryStart.setPeriod(Period);
						gcMPRecoveryStart.setDelay(MPDelayProvider);
						gcMPRecoveryStart.setQuantity(MPQuantity);

						pGamePlayer->sendPacket(&gcMPRecoveryStart);

						GCUseOK _GCUseOK;
						pGamePlayer->sendPacket(&_GCUseOK);
					}
				} 
				else 
				{
					GCCannotUse _GCCannotUse;
					_GCCannotUse.setObjectID(pPacket->getObjectID());
					pGamePlayer->sendPacket(&_GCCannotUse);
					return;
				}
			} 
			else 
			{
				notRecoverMP = true;
			}

			if (notRecoverHP && notRecoverMP) 
			{
				GCCannotUse _GCCannotUse;
				_GCCannotUse.setObjectID(pPacket->getObjectID());
				pGamePlayer->sendPacket(&_GCCannotUse);
				return;
			}
			else
			{
				decreaseItemNum(pBeltItem, pBeltInventory, pSlayer->getName(), STORAGE_BELT, pBelt->getItemID(), SlotID, 0);
			}
		}
		else if ( pCreature->isOusters() )
		{
			Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);
			Zone*   pZone   = pOusters->getZone();

			// SlotID를 받는다.
			SlotID_t SlotID = pPacket->getSlotID();

			Ousters::WearPart part = ( SlotID > 2 ? Ousters::WEAR_ARMSBAND2 : Ousters::WEAR_ARMSBAND1 );
			if ( SlotID > 2 ) SlotID -= 3;

			Item* pOustersArmsband = pOusters->getWearItem(part);
			
			if (pOustersArmsband == NULL)
			{
				GCCannotUse _GCCannotUse;
				_GCCannotUse.setObjectID(pPacket->getObjectID());
				pGamePlayer->sendPacket(&_GCCannotUse);
				return;
			}

			// 벨트의 인벤토리를 받아온다.
			Inventory* pOustersArmsbandInventory = ((OustersArmsband*)pOustersArmsband)->getInventory();
			
			// 슬랏의 범위를 초과하면 사용할 수 없다.
			if (SlotID >= pOustersArmsbandInventory->getWidth())
			{
				GCCannotUse _GCCannotUse;
				_GCCannotUse.setObjectID(pPacket->getObjectID());
				pGamePlayer->sendPacket(&_GCCannotUse);
				return;
			}
			
			// 벨트의 지정 슬랏의 아이템을 받아온다.
			Item* pOustersArmsbandItem = pOustersArmsbandInventory->getItem(SlotID, 0);
			
			// 아이템이 없으면 당연히 사용할 수 없다.
			if (pOustersArmsbandItem == NULL)
			{
				GCCannotUse _GCCannotUse;
				_GCCannotUse.setObjectID(pPacket->getObjectID());
				pGamePlayer->sendPacket(&_GCCannotUse);
				return;
			}
			
			// 슬랏에 있는 아이템의 Object를 받는다.
			ObjectID_t ItemObjectID = pOustersArmsbandItem->getObjectID();

			// 데이터가 일치하지 않거나, 푸파나 콤포스메이가 아니라면 사용할 수 없다.
			if (ItemObjectID != pPacket->getObjectID()
				|| ( pOustersArmsbandItem->getItemClass() != Item::ITEM_CLASS_PUPA && pOustersArmsbandItem->getItemClass() != Item::ITEM_CLASS_COMPOS_MEI )
				)
			{
				GCCannotUse _GCCannotUse;
				_GCCannotUse.setObjectID(pPacket->getObjectID());
				pGamePlayer->sendPacket(&_GCCannotUse);
				return;
			}

			if ( pOustersArmsbandItem->getItemClass() == Item::ITEM_CLASS_PUPA )
			{
				HP_t  MaxHP     = pOusters->getHP(ATTR_MAX);
				HP_t  CurrentHP = pOusters->getHP(ATTR_CURRENT);
				Pupa* pPupa     = dynamic_cast<Pupa*>(pOustersArmsbandItem);

				// 한턴에 회복되는 양
				int		HPQuantity = pPupa->getHPQuantity();

				// 한턴이 몇초 인가.
				int		HPDelayProvider = pPupa->getHPDelay();

				HP_t    PupaHPAmount = 0;

				PupaHPAmount = pPupa->getHPAmount();

				int     HPAmount     = min(MaxHP - CurrentHP , (int)PupaHPAmount);
				bool    notRecoverHP = false;


				// HP 회복양이 존재한다면...
				if (HPAmount != 0 && HPQuantity != 0)
				{
					if (CurrentHP < MaxHP) 
					{
						EffectManager* pEffectManager = pOusters->getEffectManager();

						double temp     = (double)((double)HPAmount/(double)HPQuantity);
						uint   Period   = (uint)ceil(temp);
						Turn_t Deadline = Period* HPDelayProvider;

						if (pOusters->isFlag(Effect::EFFECT_CLASS_HP_RECOVERY)) 
						{
							Effect* pEffect = pEffectManager->findEffect(Effect::EFFECT_CLASS_HP_RECOVERY);
							EffectHPRecovery* pEffectHPRecoveryEffect = dynamic_cast<EffectHPRecovery*>(pEffect);

							// 기존의 단위양과 횟수로 채우는 HP양을 계산한다.
							// 그것을 현재 회복양에 더한다.
							int PrevHPAmount = pEffectHPRecoveryEffect->getHPQuantity()* pEffectHPRecoveryEffect->getPeriod();
							HPAmount = min((int)(HPAmount + PrevHPAmount), MaxHP - CurrentHP);

							// 둘 중에 큰 단위회복양과 작은 딜레이를 얻어낸다.
							HPQuantity      = max(HPQuantity,      (int)(pEffectHPRecoveryEffect->getHPQuantity()));
							HPDelayProvider = min(HPDelayProvider, (int)(pEffectHPRecoveryEffect->getDelay()));

							// 현재 회복양을 가지고, 얼마씩 몇번에 회복할 것인가를 결정한다.
							temp     = (double)((double)HPAmount/(double)HPQuantity);
							Period   = (uint)ceil(temp);
							Deadline = Period* HPDelayProvider;

							// HP Recovery effect를 갱신한다.
							pEffectHPRecoveryEffect->setDeadline(Deadline);
							pEffectHPRecoveryEffect->setDelay(HPDelayProvider);
							pEffectHPRecoveryEffect->setHPQuantity(HPQuantity);
							pEffectHPRecoveryEffect->setPeriod(Period);

							// 회복 시작하라는 패킷을 자신에게 보낸다.
							GCHPRecoveryStartToSelf gcHPRecoveryStartToSelf;
							gcHPRecoveryStartToSelf.setPeriod(pEffectHPRecoveryEffect->getPeriod());
							gcHPRecoveryStartToSelf.setDelay(pEffectHPRecoveryEffect->getDelay());
							gcHPRecoveryStartToSelf.setQuantity(pEffectHPRecoveryEffect->getHPQuantity());

							pGamePlayer->sendPacket(&gcHPRecoveryStartToSelf);

							// 회복 시작하라는 패킷을 다른이들에게 보낸다.
							// 회복 갱신 패킷, 시작과 똑 같은 패킷을 보낸다.
							GCHPRecoveryStartToOthers gcHPRecoveryStartToOthers;
							gcHPRecoveryStartToOthers.setObjectID(pOusters->getObjectID());
							gcHPRecoveryStartToOthers.setPeriod(pEffectHPRecoveryEffect->getPeriod());
							gcHPRecoveryStartToOthers.setDelay(pEffectHPRecoveryEffect->getDelay());
							gcHPRecoveryStartToOthers.setQuantity(pEffectHPRecoveryEffect->getHPQuantity());

							pZone->broadcastPacket(pOusters->getX(), pOusters->getY(), &gcHPRecoveryStartToOthers, pOusters);
							GCUseOK _GCUseOK;
							pGamePlayer->sendPacket(&_GCUseOK);
						} 
						else 
						{
							EffectHPRecovery* pEffectHPRecovery = new EffectHPRecovery();

							pEffectHPRecovery->setTarget(pOusters);
							pEffectHPRecovery->setDeadline(Deadline);
							pEffectHPRecovery->setDelay(HPDelayProvider);
							pEffectHPRecovery->setNextTime(0);
							pEffectHPRecovery->setHPQuantity(HPQuantity);
							pEffectHPRecovery->setPeriod(Period);

							pEffectManager->addEffect(pEffectHPRecovery);

							// 회복 시작하라는 패킷을 자신에게 보낸다.
							GCHPRecoveryStartToSelf gcHPRecoveryStartToSelf;
							gcHPRecoveryStartToSelf.setPeriod(Period);
							gcHPRecoveryStartToSelf.setDelay(HPDelayProvider);
							gcHPRecoveryStartToSelf.setQuantity(HPQuantity);

							pGamePlayer->sendPacket(&gcHPRecoveryStartToSelf);

							// 회복 시작하라는 패킷을 보는이들에게 보낸다.
							GCHPRecoveryStartToOthers gcHPRecoveryStartToOthers;
							gcHPRecoveryStartToOthers.setObjectID(pOusters->getObjectID());
							gcHPRecoveryStartToOthers.setPeriod(Period);
							gcHPRecoveryStartToOthers.setDelay(HPDelayProvider);
							gcHPRecoveryStartToOthers.setQuantity(HPQuantity);

							pZone->broadcastPacket(pOusters->getX(), pOusters->getY(), &gcHPRecoveryStartToOthers, pOusters);
							GCUseOK _GCUseOK;
							pGamePlayer->sendPacket(&_GCUseOK);
						}
					} 
					else 
					{
						GCCannotUse _GCCannotUse;
						_GCCannotUse.setObjectID(pPacket->getObjectID());
						pGamePlayer->sendPacket(&_GCCannotUse);
						return;
					}
				} 
				else 
				{
					notRecoverHP = true;
				}

				if (notRecoverHP) 
				{
					GCCannotUse _GCCannotUse;
					_GCCannotUse.setObjectID(pPacket->getObjectID());
					pGamePlayer->sendPacket(&_GCCannotUse);
					return;
				}
				else
				{
					decreaseItemNum(pOustersArmsbandItem, pOustersArmsbandInventory, pOusters->getName(), STORAGE_BELT, pOustersArmsband->getItemID(), SlotID, 0);
				}
			}
			else if ( pOustersArmsbandItem->getItemClass() == Item::ITEM_CLASS_COMPOS_MEI )
			{
				MP_t    MaxMP        = pOusters->getMP(ATTR_MAX);
				MP_t    CurrentMP    = pOusters->getMP(ATTR_CURRENT);
				ComposMei* pComposMei      = dynamic_cast<ComposMei*>(pOustersArmsbandItem);

				// 한턴에 회복되는 양
				int		MPQuantity = pComposMei->getMPQuantity();

				// 한턴이 몇초 인가.
				int		MPDelayProvider = pComposMei->getMPDelay();

				Attr_t INT = pOusters->getINT();

				MP_t    ComposMeiMPAmount = 0;

				ComposMeiMPAmount = pComposMei->getMPAmount();

				int     MPAmount     = min(MaxMP - CurrentMP , (int)(pComposMei->getMPAmount()* (1 + (double)((double)INT / 300.0))));
				bool    notRecoverMP = false;

				// MP 회복양이 존재한다면...
				if (MPAmount != 0 && MPQuantity != 0 )
				{
					// 얼마씩 몇번 몇초마다.
					if (CurrentMP < MaxMP) 
					{
						EffectManager* pEffectManager = pOusters->getEffectManager();

						double temp     = (double)((double)MPAmount/(double)MPQuantity);
						uint   Period   = (uint)ceil(temp);
						Turn_t Deadline = Period* MPDelayProvider;

						if (pOusters->isFlag(Effect::EFFECT_CLASS_MP_RECOVERY)) 
						{
							Effect* pEffect = pEffectManager->findEffect(Effect::EFFECT_CLASS_MP_RECOVERY);
							EffectMPRecovery* pEffectMPRecoveryEffect = dynamic_cast<EffectMPRecovery*>(pEffect);

							// 기존의 단위양과 횟수로 채우는 MP양을 계산한다.
							// 그것을 현재 회복양에 더한다.
							int PrevMPAmount = pEffectMPRecoveryEffect->getMPQuantity()* pEffectMPRecoveryEffect->getPeriod();
							MPAmount = min((int)(MPAmount + PrevMPAmount), MaxMP - CurrentMP);

							// 둘 중에 큰 단위회복양과 작은 딜레이를 얻어낸다.
							MPQuantity      = max(MPQuantity,      (int)(pEffectMPRecoveryEffect->getMPQuantity()));
							MPDelayProvider = min(MPDelayProvider, (int)(pEffectMPRecoveryEffect->getDelay()));

							// 현재 회복양을 가지고, 얼마씩 몇번에 회복할 것인가를 결정한다.
							temp     = (double)((double)MPAmount/(double)MPQuantity);
							Period   = (uint)ceil(temp);
							Deadline = Period* MPDelayProvider;

							// MP Recovery effect를 갱신한다.
							pEffectMPRecoveryEffect->setDeadline(Deadline);
							pEffectMPRecoveryEffect->setDelay(MPDelayProvider);
							pEffectMPRecoveryEffect->setMPQuantity(MPQuantity);
							pEffectMPRecoveryEffect->setPeriod(Period);

							// 회복 시작하라는 패킷을 자신에게 보낸다.
							GCMPRecoveryStart gcMPRecoveryStart;
							gcMPRecoveryStart.setPeriod(pEffectMPRecoveryEffect->getPeriod());
							gcMPRecoveryStart.setDelay(pEffectMPRecoveryEffect->getDelay());
							gcMPRecoveryStart.setQuantity(pEffectMPRecoveryEffect->getMPQuantity());

							pGamePlayer->sendPacket(&gcMPRecoveryStart);

							GCUseOK _GCUseOK;
							pGamePlayer->sendPacket(&_GCUseOK);
						} 
						else 
						{
							EffectMPRecovery* pEffectMPRecovery = new EffectMPRecovery();

							pEffectMPRecovery->setTarget(pOusters);
							pEffectMPRecovery->setDeadline(Deadline);
							pEffectMPRecovery->setDelay(MPDelayProvider);
							pEffectMPRecovery->setNextTime(0);
							pEffectMPRecovery->setMPQuantity(MPQuantity);
							pEffectMPRecovery->setPeriod(Period);

							pEffectManager->addEffect(pEffectMPRecovery);

							// 회복 시작하라는 패킷을 자신에게 보낸다.
							GCMPRecoveryStart gcMPRecoveryStart;
							gcMPRecoveryStart.setPeriod(Period);
							gcMPRecoveryStart.setDelay(MPDelayProvider);
							gcMPRecoveryStart.setQuantity(MPQuantity);

							pGamePlayer->sendPacket(&gcMPRecoveryStart);

							GCUseOK _GCUseOK;
							pGamePlayer->sendPacket(&_GCUseOK);
						}
					} 
					else 
					{
						GCCannotUse _GCCannotUse;
						_GCCannotUse.setObjectID(pPacket->getObjectID());
						pGamePlayer->sendPacket(&_GCCannotUse);
						return;
					}
				} 
				else 
				{
					notRecoverMP = true;
				}

				if (notRecoverMP) 
				{
					GCCannotUse _GCCannotUse;
					_GCCannotUse.setObjectID(pPacket->getObjectID());
					pGamePlayer->sendPacket(&_GCCannotUse);
					return;
				}
				else
				{
					decreaseItemNum(pOustersArmsbandItem, pOustersArmsbandInventory, pOusters->getName(), STORAGE_BELT, pOustersArmsband->getItemID(), SlotID, 0);
				}
			}
		}
	} 
	catch (Throwable & t) 
	{
			//cout << t.toString();
	}
	
#endif	// __GAME_SERVER__

    __END_DEBUG_EX __END_CATCH
}
