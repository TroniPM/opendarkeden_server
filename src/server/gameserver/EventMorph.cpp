//////////////////////////////////////////////////////////////////////////////
// Filename    : EventMorph.cpp
// Written by  : Reiot
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EventMorph.h"
#include "GamePlayer.h"
#include "PCFinder.h"
#include "Vampire.h"
#include "Slayer.h"
#include "ItemUtil.h"
#include "Zone.h"
#include "ZoneInfoManager.h"
#include "ZoneGroupManager.h"
#include "IncomingPlayerManager.h"
#include "ZonePlayerManager.h"
#include "TimeManager.h"
#include <fstream>
#include "LogClient.h"
#include "PacketUtil.h"
#include "Party.h"
#include "TradeManager.h"
#include "GuildManager.h"
#include "Guild.h"
#include "ZoneUtil.h"
#include "RelicUtil.h"
#include "SharedServerManager.h"
#include "DB.h"
#include "CreatureUtil.h"

#include "Gpackets/GCUpdateInfo.h"
#include "Gpackets/GCMorph1.h"
#include "Gpackets/GCMorphVampire2.h"
#include "Gpackets/GSGuildMemberLogOn.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////////////
// class EventMorph member methods
//////////////////////////////////////////////////////////////////////////////

EventMorph::EventMorph(GamePlayer* pGamePlayer)
	throw()
	: Event(pGamePlayer)
{
	__BEGIN_TRY
	__END_CATCH
}

EventMorph::~EventMorph()
	throw()
{
	__BEGIN_TRY
	__END_CATCH
}

void EventMorph::activate () 
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Assert(m_pGamePlayer != NULL);

	Creature* pFromCreature = m_pGamePlayer->getCreature();
	Assert(pFromCreature->isSlayer());

	if (m_pGamePlayer->getPlayerStatus() != GPS_NORMAL)
	{
		// �÷��̾��� ���°� WAITING_FOR_CG_READY�ε�, morph�� 
		// activate�Ǿ� ���� ����� ũ���ĸ� ������ �κп��� ������ throw�Ǿ�
		// ������ �״� ���װ� �־���. �Ȯ�� ��� �ؼ� CG_READY���¿���
		// �̺�Ʈ�� activate�Ǵ����� �𸣰����, GamePlayer�� 
		// EventManager ��ü�� GPS_NORMAL�� ���� ���ư��� �ϸ�,
		// Resurrect�� ���� ����� �����ϱ� �ٶ���. �ᱹ GamePlayer ���ο���
		// üũ�� �ϱⰡ �����ϱ� ������ �� �κп���, ó���Ѵ�.
		StringStream msg;
		msg << "EventMorph::activate() : GamePlayer�� ���°� GPS_NORMAL�� �ƴմϴ�."
			<< "PlayerID[" << m_pGamePlayer->getID() << "]"
			<< "CreatureName[" << pFromCreature->getName() << "]";

		filelog("EventMorphError.log", "%s", msg.toString().c_str());
		return;
	}

	pFromCreature->removeFlag(Effect::EFFECT_CLASS_BLOOD_DRAIN);
	Zone* pZone = pFromCreature->getZone();

	// ���� Restore ����Ʈ�� �ɷ��ִٸ� ������ ���� �ʴ´�.
	if (pFromCreature->isFlag(Effect::EFFECT_CLASS_RESTORE))
	{
		return;
	}

	dropRelicToZone( pFromCreature );
	dropFlagToZone( pFromCreature );
	dropSweeperToZone( pFromCreature );

	//////////////////////////////////////////////////////////////////////
	// ��� � ���� ����� ����ؾ� �Ѵ�.
	//////////////////////////////////////////////////////////////////////
	
	// ��Ƽ �ʴ� ���̶��� ����� ����� �ش�.
	PartyInviteInfoManager* pPIIM = pZone->getPartyInviteInfoManager();
	Assert(pPIIM != NULL);
	pPIIM->cancelInvite(pFromCreature);

	// ��Ƽ ���� ����� ����� �ش�.
	uint PartyID = pFromCreature->getPartyID();
	if (PartyID != 0)
	{
		// ���� ���ÿ��� ����ϰ�...
		LocalPartyManager* pLPM = pZone->getLocalPartyManager();
		Assert(pLPM != NULL);
		pLPM->deletePartyMember(PartyID, pFromCreature);

		// �۷ι������� ����� �ش�.
		deleteAllPartyInfo(pFromCreature);
	}

	// Ʈ���̵� ���̾��ٸ� Ʈ���̵� ���� ����� ������ش�.
	TradeManager* pTM = pZone->getTradeManager();
	Assert(pTM != NULL);
	pTM->cancelTrade(pFromCreature);

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	Vampire* pVampire = new Vampire();
	
	GCMorph1 gcEventMorph1;	// ���� �����ڿ���..
	GCMorphVampire2 gcEventMorphVampire2;	// ���� �����۵鿡��..
		
	pVampire->setName(pFromCreature->getName());

	ObjectID_t fromObjectID = pFromCreature->getObjectID();
	pVampire->setObjectID(fromObjectID);

	Player* pPlayer = pFromCreature->getPlayer();
	dynamic_cast<GamePlayer*>(pPlayer)->setCreature(pVampire);
	pVampire->setPlayer(pPlayer);
	pVampire->setZone(pZone);
	pVampire->load();

	Coord_t x = pFromCreature->getX(), y = pFromCreature->getY();
	Dir_t dir = pFromCreature->getDir();
	pVampire->setXYDir(x, y, dir);
	pVampire->setMoveMode(pFromCreature->getMoveMode());
	
	// slayer to vampire
	Slayer* pSlayer = dynamic_cast<Slayer*>(pFromCreature);

	// �����̾��� �����Ҷ� Creature Pointer�� �޶����Ƿ�...
	// ���� ���� �Ǿ��ִ� �����ʹ� ���� �ȴ�...
	// ������ ���ο� Creature Pointer�� ���������� �Ѵ�.
	g_pPCFinder->deleteCreature(pFromCreature->getName());
	g_pPCFinder->addCreature(pVampire);

	// ���� ���� ��� ����Ʈ���� ����Ѵ�.
	if ( pSlayer->getGuildID() != 99 )
	{
		Guild* pGuild = g_pGuildManager->getGuild( pSlayer->getGuildID() );
		if ( pGuild != NULL )
		{
			pGuild->deleteCurrentMember( pSlayer->getName() );

			GSGuildMemberLogOn gsGuildMemberLogOn;
			gsGuildMemberLogOn.setGuildID( pGuild->getID() );
			gsGuildMemberLogOn.setName( pSlayer->getName() );
			gsGuildMemberLogOn.setLogOn( false );

			g_pSharedServerManager->sendPacket( &gsGuildMemberLogOn );
			
			Statement* pStmt = NULL;
			// ������ ������Ʈ �Ѵ�.
			BEGIN_DB
			{
				pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
				pStmt->executeQuery( "UPDATE GuildMember SET LogOn = 0 WHERE Name = '%s'", pSlayer->getName().c_str() );
			}
			END_DB(pStmt)
		}
		else
			filelog( "GuildMissing.log", "[NoSuchGuild] GuildID : %d, Name : %s\n", (int)pSlayer->getGuildID(), pSlayer->getName().c_str() );
	}

	// �κ��丮 ��ü.
	Inventory* pInventory = pSlayer->getInventory();
	pVampire->setInventory(pInventory);
	pSlayer->setInventory(NULL);

	// ������ ��ü
	pVampire->deleteStash();                 // ���� ��ü�� �����ְ�...
	pVampire->setStash(pSlayer->getStash()); // �����̾� �ɷ� �ٲ� �����
	pVampire->setStashNum(pSlayer->getStashNum());
	pVampire->setStashStatus(false);         // OID �Ҵ� ���¸� false��...
	pSlayer->setStash(NULL);                 // ������ ������ ���� ��� �����̾� ��� NULL��...

	/*
	// ������ ��ü
	while (true)
	{
		Item* pGarbage = pSlayer->popItemFromGarbage();

		// �� �̻� ���ٸ� �극��ũ...
		if (pGarbage == NULL) break;

		pVampire->addItemToGarbage(pGarbage);
	}
	*/


	// �÷��� �� ��ü
	pVampire->deleteFlagSet();
	pVampire->setFlagSet(pSlayer->getFlagSet());
	pSlayer->setFlagSet(NULL);

	Item* pItem = NULL;
	_TPOINT point;
	// ����� �κ��丮��..
    for(int part = 0; part < (int)Slayer::WEAR_MAX; part++)
   	{
       	pItem = pSlayer->getWearItem((Slayer::WearPart)part);
        if (pItem)
   	    {
			if (isTwohandWeapon(pItem))
            {
				Assert(((Slayer::WearPart)part == Slayer::WEAR_RIGHTHAND) || ((Slayer::WearPart)part == Slayer::WEAR_LEFTHAND));
				Assert(pSlayer->getWearItem(Slayer::WEAR_RIGHTHAND) == pSlayer->getWearItem(Slayer::WEAR_LEFTHAND));
				// ���� ����.
				pSlayer->deleteWearItem(Slayer::WEAR_RIGHTHAND);
				pSlayer->deleteWearItem(Slayer::WEAR_LEFTHAND);
            }
   	        else
       	    {
				pSlayer->deleteWearItem((Slayer::WearPart)part);
            }
	
			if (pInventory->getEmptySlot(pItem, point))
       	    {
				// �κ��丮�� ��� ������ �����..
				// �κ��丮�� �߰�
				pInventory->addItem(point.x, point.y, pItem);
				pItem->save(pVampire->getName(), STORAGE_INVENTORY, 0, point.x, point.y);
   	        }
       	    else if ( pItem->isTimeLimitItem() )
			{
				pSlayer->deleteItemByMorph( pItem );

				pItem->destroy();
				SAFE_DELETE(pItem);
			}
			else 
			{
				TPOINT pt;
				ZoneCoord_t ZoneX = pSlayer->getX();
				ZoneCoord_t ZoneY = pSlayer->getY();

				// ���� �Ѹ���.
   	            pt = pZone->addItem(pItem, ZoneX, ZoneY);

				if (pt.x != -1) 
				{
					pItem->save("", STORAGE_ZONE, pZone->getZoneID(), pt.x , pt.y);
					log(LOG_DROP_ITEM_MORPH, pSlayer->getName(), "", pItem->toString());

					// ItemTraceLog �� ������
					if ( pItem != NULL && pItem->isTraceItem() )
					{
						char zoneName[15];
						sprintf( zoneName, "%4d%3d%3d", pZone->getZoneID(), pt.x, pt.y);
						remainTraceLog( pItem, pFromCreature->getName(), zoneName, ITEM_LOG_MOVE, DETAIL_DROP);
					}
				} 
				else 
				{
					// ItemTraceLog �� ������
					if ( pItem != NULL && pItem->isTraceItem() )
					{
						remainTraceLog( pItem, pFromCreature->getName(), "GOD", ITEM_LOG_DELETE, DETAIL_DROP);
					}
					pItem->destroy();
					SAFE_DELETE(pItem);
				}
      	    }
        }
    }
	// ExtraInventorySlot���� �κ��丮��..
    pItem = pSlayer->getExtraInventorySlotItem();
   	if (pItem)
    {
   	    pSlayer->deleteItemFromExtraInventorySlot();

		if (pInventory->getEmptySlot(pItem, point))
        {
   	        pInventory->addItem(point.x, point.y, pItem);
			pItem->save(pVampire->getName(), STORAGE_INVENTORY, 0, point.x, point.y);
        }
		else if ( pItem->isTimeLimitItem() )
		{
			pSlayer->deleteItemByMorph( pItem );

			pItem->destroy();
			SAFE_DELETE(pItem);
		}
		else
		{

			TPOINT pt;
			ZoneCoord_t ZoneX = pSlayer->getX();
			ZoneCoord_t ZoneY = pSlayer->getY();

            pt = pZone->addItem(pItem, ZoneX, ZoneY); 

			if (pt.x != -1) 
			{
				pItem->save("", STORAGE_ZONE, pZone->getZoneID(), pt.x , pt.y);
				log(LOG_DROP_ITEM_MORPH, pSlayer->getName(), "");

				// ItemTraceLog �� ������
				if ( pItem != NULL && pItem->isTraceItem() )
				{
					char zoneName[15];
					sprintf( zoneName, "%4d%3d%3d", pZone->getZoneID(), pt.x, pt.y);
					remainTraceLog( pItem, pFromCreature->getName(), zoneName, ITEM_LOG_MOVE, DETAIL_DROP);
				}
			}
			else 
			{
				// ItemTraceLog �� ������
				if ( pItem != NULL && pItem->isTraceItem() )
				{
					remainTraceLog( pItem, pFromCreature->getName(), "GOD", ITEM_LOG_DELETE, DETAIL_DROP);
				}
				pItem->destroy();
				SAFE_DELETE(pItem);
			}
   	    }
    }

	if (pSlayer->hasRideMotorcycle()) {
		pSlayer->getOffMotorcycle();
	}

	pVampire->loadTimeLimitItem();

	// Vampire�� ��������� ��� �ʱ�ȭ�Ѵ�.
	//pVampire->setGoldEx(pSlayer->getGold());
	pVampire->setGoldEx(0);
	pVampire->setStashGoldEx(0);

	// set packet data
	gcEventMorph1.setPCInfo2(pVampire->getVampireInfo2());
	gcEventMorph1.setInventoryInfo(pVampire->getInventoryInfo());
	gcEventMorph1.setGearInfo(pVampire->getGearInfo());
	gcEventMorph1.setExtraInfo(pVampire->getExtraInfo());

	gcEventMorphVampire2.setVampireInfo(pVampire->getVampireInfo3());

	if (pFromCreature->isPC())
	{
		Player* pPlayer = pFromCreature->getPlayer();
		pPlayer->sendPacket(&gcEventMorph1);
	}

	pZone->broadcastPacket(x, y, &gcEventMorphVampire2, pFromCreature);

	Tile & tile = pZone->getTile(x, y);

	// Delete FromCreature from tile & PCManager
	tile.deleteCreature(fromObjectID);
	pZone->deletePC(pFromCreature);

	// add toCreature
	tile.addCreature(pVampire, false, false);
	pZone->addPC(pVampire);

//	pZone->addPC(pVampire, x, y, pVampire->getDir());
//	pZone->deleteCreature(pFromCreature, x, y);
//	pZone->morphCreature(pFromCreature, pVampire);

	// �þ� update..
	pZone->updateHiddenScan(pVampire);

	// ���� ����
	pVampire->sendVampireSkillInfo();

	m_pTargetCreature = NULL;

	// ����� ���ߴٴ� ����� Slayer Field�� �߰��Ѵ�.
	pSlayer->tinysave("Race='VAMPIRE'");

	// �����̾� ����� �̵���Ų��.
	uint ZoneNum = 1003;

	ZoneCoord_t ZoneX = 62;
	ZoneCoord_t ZoneY = 64;

	Assert((int)ZoneX < 256);
	Assert((int)ZoneY < 256);

	Assert(pVampire->isPC());

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pVampire->getPlayer());
//	Zone* pZone = pVampire->getZone();

	//--------------------------------------------------------------------------------
	// ������� ���� ����, ���� ��׷쿡 ���ϴ��� �˾ƺ���.
	//--------------------------------------------------------------------------------
	ZoneInfo* pZoneInfo;
	try 
	{
		pZoneInfo = g_pZoneInfoManager->getZoneInfo(ZoneNum);
	} 
	catch (NoSuchElementException&) 
	{
		cerr << "Critical Error : ��Ż�� ����� � ���̵� Ʋ���ų�, ZoneInfoManager�� �ش� ��� ������� �ʽ�ϴ�." << endl;
		throw Error("Critical Error : ��Ż�� ����� � ���̵��� Ʋ���ų�, ZoneInfoManager�� �ش� ��� ������� �ʽ�ϴ�.");
	}

	ZoneGroup* pZoneGroup;
	try 
	{
		pZoneGroup = g_pZoneGroupManager->getZoneGroup(pZoneInfo->getZoneGroupID());
	}
	catch (NoSuchElementException&) 
	{
		cerr << "Critical Error : �����δ� ���� ������ 1�����̴�.." << endl;

		// �ϴ�� ������ 1���̹Ƿ�.. �״��� ������...
		throw Error("Critical Error : �����δ� ���� ������ 1�����̴�..");
	}

	//--------------------------------------------------------------------------------
	// �켱 ���� ����� PC �� ����ϰ�, �÷��̾ ZPM -> IPM ��� �ű���.
	//--------------------------------------------------------------------------------
	try 
	{
		// ���, ����� PC�� ����Ѵ�.
		//
		// *CAUTION*
		//
		// pVampire ��ǥ�� ����� pVampire�� ����ϴ� Ÿ���� ��ǥ�� ���ƾ� �Ѵ�.
		// ������, �� �޽��带 ȣ���ϱ� ���� ��ǥ�� �� �ٲ����� �Ѵ�..
		//
		pZone->deleteCreature(pVampire, pVampire->getX() , pVampire->getY());

		// ��׷��� ZPM���� �÷��̾ ����Ѵ�.
		//pZone->getZoneGroup()->getZonePlayerManager()->deletePlayer_NOBLOCKED(pGamePlayer);
		//pZone->getZoneGroup()->getZonePlayerManager()->deletePlayer_NOBLOCKED(pGamePlayer->getSocket()->getSOCKET());
		pZone->getZoneGroup()->getZonePlayerManager()->deletePlayer(pGamePlayer->getSocket()->getSOCKET());

		//--------------------------------------------------
		// ũ��ó�� ���ο� ��ǥ�� ��Ż�� ���� ����̴�.
		//--------------------------------------------------
		// �ּ�ó�� by sigi. 2002.5.17
		//pVampire->setXY(ZoneX, ZoneY);
		//pVampire->setZone(NULL);

		// IPM��� �÷��̾ �ű���.
		//g_pIncomingPlayerManager->addPlayer(pGamePlayer);
		//g_pIncomingPlayerManager->pushPlayer(pGamePlayer);
		pZone->getZoneGroup()->getZonePlayerManager()->pushOutPlayer(pGamePlayer);

	} 
	catch (NoSuchElementException & nsee) 
	{
		cerr << nsee.toString() << endl;
		throw Error(nsee.toString());
	}

	// ũ��ó���ٰ� �� ������ش�. �̴� OID �� �Ҵ��ޱ� ��ؼ��̴�.
	Zone* pNewZone = pZoneGroup->getZone(ZoneNum);
	Assert(pNewZone != NULL);

	//pVampire->setZone(pZone);
	// �̵��� �� ����Ѵ�. by sigi. 2002.5.11
	pVampire->setNewZone(pNewZone);
	pVampire->setNewXY(ZoneX, ZoneY);


	// ũ��ó�� ����� �����Ѵ�.
	pVampire->setZone(pNewZone);
	pVampire->setXY(ZoneX, ZoneY);

	pVampire->save();

	pVampire->setZone(pZone);
	pVampire->setXY(x, y);

	// ũ��ó �ڽŰ� ��� �����۵��� OID�� �Ҵ��޴´�.
	//pVampire->registerObject();

	/*
	//--------------------------------------------------------------------------------
	// GCUpdateInfo ��Ŷ� �������д�.
	//--------------------------------------------------------------------------------
	GCUpdateInfo gcUpdateInfo;

	makeGCUpdateInfo(&gcUpdateInfo, pVampire);

	pGamePlayer->sendPacket(&gcUpdateInfo);
	*/

	//--------------------------------------------------
	// change player status
	//--------------------------------------------------
	pGamePlayer->setPlayerStatus(GPS_WAITING_FOR_CG_READY);


	// ���� ������.. ���� �ִ� EffectManager�� ���� �ǳ�? -_-;
	//----------------------------------

	/*
	Creature* pEventMorphCreature = m_pGamePlayer->getCreature();
	Assert(pEventMorphCreature != m_pTargetCreature);
	Assert(pEventMorphCreature != NULL);	// by sigi

	Zone* pZone = pEventMorphCreature->getZone();
	Assert(pZone != NULL);
	*/

	/*
	ofstream file("blood.txt", ios::out | ios::app);
	file << "�����̾� [" << pSlayer->getName() << "] ���ķ� ���ϴ� >> ";
	file << getCurrentTimeStringEx() << endl;
	file.close();
	*/

	log(LOG_SLAYER_TO_VAMPIRE, pFromCreature->getName(), "");

	SAFE_DELETE(pFromCreature);

	__END_DEBUG
	__END_CATCH
}
	
string EventMorph::toString () const 
	throw ()
{
	StringStream msg;
	msg << "EventMorph("
		<< ")";
	return msg.toString();
}
