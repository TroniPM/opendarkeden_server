////////////////////////////////////////////////////////////////////////////////
// Filename    : CastleInfoManager.cpp
// Written By  : 
// Description : �ƴ��� ���� ��ó�� �ִ� ���� ���� ���
////////////////////////////////////////////////////////////////////////////////

#include "CastleInfoManager.h"
#include "PlayerCreature.h"
#include "ItemUtil.h"
#include <stdio.h>
#include "Properties.h"
#include "ZoneInfoManager.h"
#include "ZoneGroupManager.h"
#include "VariableManager.h"
#include "Guild.h"
#include "GuildManager.h"
//#include "HolyLandRaceBonus.h"
#include "ZoneUtil.h"
#include "NPCManager.h"
#include "Zone.h"
#include "War.h"
#include "WarSystem.h"
#include "WarScheduler.h"
#include "ClientManager.h"
#include "PCManager.h"
#include "EventRefreshHolyLandPlayer.h"
#include "ShrineInfoManager.h"
#include "EffectHasBloodBible.h"
#include "CastleSkillInfo.h"
#include "GamePlayer.h"

#include "DB.h"
#include "StringPool.h"

#include "Skill.h"

#include "Gpackets/GCSystemMessage.h"
#include "Gpackets/GCNoticeEvent.h"
#include "Gpackets/GCModifyInformation.h"

CastleInfo::CastleInfo() : m_Name(""), m_BonusOptionList() , m_CastleZoneIDList()
{
	m_ZoneID = 0;
	m_ShrineID = 0;
	m_GuildID = 0;
	m_ItemTaxRatio = 0;
	m_EntranceFee = 0;
	m_TaxBalance = 0;
}

CastleInfo::~CastleInfo()
{
}

Gold_t CastleInfo::increaseTaxBalance( Gold_t tax )
{
	if( tax > GUILD_TAX_BALANCE_MAX - m_TaxBalance ) // ������ ����� ����
	{
		tax = GUILD_TAX_BALANCE_MAX - m_TaxBalance;
	}

	m_TaxBalance = min( GUILD_TAX_BALANCE_MAX, m_TaxBalance + tax );

	return m_TaxBalance;
}

Gold_t CastleInfo::decreaseTaxBalance( Gold_t tax )
{
	if( tax > m_TaxBalance ) tax = m_TaxBalance;

	m_TaxBalance = max( 0, (int)m_TaxBalance - (int)tax );
	return m_TaxBalance;
}

Gold_t CastleInfo::increaseTaxBalanceEx( Gold_t tax )
	throw(Error)
{
	__BEGIN_TRY

	static char query[100];

	increaseTaxBalance(tax);

	if( !isCommon() )
	{
		sprintf( query, "TaxBalance=%d", (int)getTaxBalance() );
		g_pCastleInfoManager->tinysave( getZoneID(), query );
	}

	return getTaxBalance();

	__END_CATCH
}

Gold_t CastleInfo::decreaseTaxBalanceEx( Gold_t tax )
	throw(Error)
{
	__BEGIN_TRY

	static char query[100];

	decreaseTaxBalance(tax);

	if( !isCommon() )
	{
		sprintf( query, "TaxBalance=%d", (int)getTaxBalance() );
		g_pCastleInfoManager->tinysave( getZoneID(), query );
	}
	
	return getTaxBalance();

	__END_CATCH
}

void CastleInfo::setOptionTypeList( const string& options )
	throw()
{
	__BEGIN_TRY

	makeOptionList( options, m_BonusOptionList );

	__END_CATCH
}

void CastleInfo::setZoneIDList( const string& zoneIDs ) 
	throw()
{
	__BEGIN_TRY

	makeZoneIDList( zoneIDs, m_CastleZoneIDList );

	__END_CATCH
}

void CastleInfo::setResurrectPosition( ResurrectPriority resurrectPriority, const ZONE_COORD& zoneCoord )
{
	m_ResurrectPosition[resurrectPriority].set( zoneCoord.id, zoneCoord.x, zoneCoord.y );
}

void CastleInfo::getResurrectPosition( ResurrectPriority resurrectPriority, ZONE_COORD& zoneCoord )
{
	zoneCoord.set( m_ResurrectPosition[resurrectPriority].id, m_ResurrectPosition[resurrectPriority].x, m_ResurrectPosition[resurrectPriority].y );
}

void CastleInfo::broadcast(Packet* pPacket) const
	throw (Error)
{
	__BEGIN_TRY

	Assert( pPacket != NULL );

	list<ZoneID_t>::const_iterator itr = m_CastleZoneIDList.begin();

	for ( ; itr != m_CastleZoneIDList.end() ; itr++)
	{
		Zone* pCastleZone = getZoneByZoneID( *itr );
		pCastleZone->broadcastPacket( pPacket );
	}

	__END_CATCH
}

bool CastleInfo::isCastleZone(ZoneID_t targetZoneID) const 
	throw (Error)
{
	__BEGIN_TRY

	list<ZoneID_t>::const_iterator itr = m_CastleZoneIDList.begin();

	for ( ; itr != m_CastleZoneIDList.end() ; itr++)
	{
		ZoneID_t zoneID = *itr;

		if (zoneID==targetZoneID)
			return true;
	}

	return false;

	__END_CATCH
}


string CastleInfo::toString() const
	throw()
{
	__BEGIN_TRY
	
	StringStream msg;
	msg << "CastleInfo("
		<< "ZoneID:" << m_ZoneID
		<< ",Item Tax Ratie:" << m_ItemTaxRatio
		<< ",Entrance Fee:" << m_EntranceFee
		<< ",Tax Balance:" << m_TaxBalance
		<< ")";
	return msg.toString();

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////////////
CastleInfoManager::CastleInfoManager () 
{
	__BEGIN_TRY
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////////////
CastleInfoManager::~CastleInfoManager () 
{
	__BEGIN_TRY

	map< ZoneID_t , CastleInfo *>::iterator itr = m_CastleInfos.begin();
	for (; itr != m_CastleInfos.end(); itr++)
	{
		CastleInfo* pInfo = itr->second;
		SAFE_DELETE(pInfo);
	}
	
	// �ؽ��ʾȿ� �ִ� ���� pair ��� ����Ѵ�.
	m_CastleInfos.clear();

	__END_CATCH
}
	

//////////////////////////////////////////////////////////////////////////////
// initialize zone info manager
//////////////////////////////////////////////////////////////////////////////
void CastleInfoManager::init () 
	throw (Error)
{
	__BEGIN_TRY

	// init == load
	load();
			
	__END_CATCH
}

	
//void testMaxMemory();

//////////////////////////////////////////////////////////////////////////////
// load from database
//////////////////////////////////////////////////////////////////////////////
void CastleInfoManager::load ()
	throw (Error)
{
	__BEGIN_TRY

	clearCastleZoneIDs();

	Statement* pStmt = NULL;

	BEGIN_DB
	{

		// create statement
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		Result* pResult = pStmt->executeQuery(
			"SELECT ZoneID, ShrineID, GuildID, Name, Race, ItemTaxRatio, EntranceFee, TaxBalance, BonusOptionType, FirstResurrectZoneID, FirstResurrectX, FirstResurrectY, SecondResurrectZoneID, SecondResurrectX, SecondResurrectY, ThirdResurrectZoneID, ThirdResurrectX, ThirdResurrectY, ZoneIDList FROM CastleInfo WHERE ServerID = %d",
			g_pConfig->getPropertyInt( "ServerID" ) );

		ZoneCoord_t x, y;
		ZONE_COORD zoneCoord;

		while (pResult->next()) 
		{
			uint i = 0;

			ZoneID_t zoneID = pResult->getInt(++i);

			ZoneInfo* pZoneInfo = g_pZoneInfoManager->getZoneInfo( zoneID );
			Assert( pZoneInfo!=NULL );

			pZoneInfo->setCastle();

			CastleInfo* pCastleInfo = new CastleInfo();
			//cout << "new OK" << endl;

			pCastleInfo->setZoneID( zoneID );
			pCastleInfo->setShrineID( pResult->getInt(++i) );
			pCastleInfo->setGuildID( pResult->getInt(++i) );
			pCastleInfo->setName( pResult->getString(++i) );
			pCastleInfo->setRace( pResult->getInt(++i) );
			pCastleInfo->setItemTaxRatio( pResult->getInt(++i) );
			pCastleInfo->setEntranceFee( pResult->getInt(++i) );
			pCastleInfo->setTaxBalance( pResult->getInt(++i) );
			pCastleInfo->setOptionTypeList( pResult->getString(++i) );

			zoneID	= pResult->getInt( ++i );
			x		= pResult->getInt( ++i );
			y		= pResult->getInt( ++i );

			zoneCoord.set( zoneID, x, y );
			pCastleInfo->setResurrectPosition( CastleInfo::CASTLE_RESURRECT_PRIORITY_FIRST, zoneCoord );

			zoneID	= pResult->getInt( ++i );
			x		= pResult->getInt( ++i );
			y		= pResult->getInt( ++i );

			zoneCoord.set( zoneID, x, y );
			pCastleInfo->setResurrectPosition( CastleInfo::CASTLE_RESURRECT_PRIORITY_SECOND, zoneCoord );

			zoneID	= pResult->getInt( ++i );
			x		= pResult->getInt( ++i );
			y		= pResult->getInt( ++i );

			zoneCoord.set( zoneID, x, y );
			pCastleInfo->setResurrectPosition( CastleInfo::CASTLE_RESURRECT_PRIORITY_THIRD, zoneCoord );

			pCastleInfo->setZoneIDList( pResult->getString(++i) );

			addCastleInfo(pCastleInfo);

			cout << pCastleInfo->toString().c_str() << endl;

		}
			
		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

	__END_CATCH
}

void CastleInfoManager::save( ZoneID_t zoneID )
	throw(Error)
{
	__BEGIN_TRY

	CastleInfo* pCastleInfo = getCastleInfo( zoneID );
	if( pCastleInfo == NULL ) return;

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		// create statement
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		pStmt->executeQuery(
			"UPDATE CastleInfo SET GuildID=%d, Name='%s', Race=%d, ItemTaxRatio=%d, EntranceFee=%d, TaxBalance=%d WHERE ServerID=%d AND ZoneID=%d",
							(int)pCastleInfo->getGuildID(), 
							pCastleInfo->getName().c_str(), 
							(int)pCastleInfo->getRace(), 
							pCastleInfo->getItemTaxRatio(), 
							(int)pCastleInfo->getEntranceFee(), 
							(int)pCastleInfo->getTaxBalance(), 
							(int)g_pConfig->getPropertyInt( "ServerID" ),
							(int)zoneID );

		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

	__END_CATCH

}

//////////////////////////////////////////////////////////////////////////////
// add zone info to zone info manager
//////////////////////////////////////////////////////////////////////////////
void CastleInfoManager::addCastleInfo (CastleInfo* pCastleInfo) 
	throw (Error)
{
	__BEGIN_TRY

	// �ϴ� ��� ���̵��� ��� �ִ��� üũ�غ���.
	map< ZoneID_t , CastleInfo *>::iterator itr = m_CastleInfos.find(pCastleInfo->getZoneID());
	
	if (itr != m_CastleInfos.end())
		// �Ȱ�� ���̵��� �̹� ����Ѵٴ� �Ҹ���. - -;
		throw Error("duplicated zone id");

	m_CastleInfos[ pCastleInfo->getZoneID() ] = pCastleInfo;

	// ���� ���õ� ���� ZoneID�� �����Ѵ�.
	const list<ZoneID_t>& zoneIDs = pCastleInfo->getZoneIDList();
	list<ZoneID_t>::const_iterator iZoneID = zoneIDs.begin();

	for (; iZoneID!=zoneIDs.end(); iZoneID++)
	{
		ZoneID_t zoneID = *iZoneID;
		setCastleZoneID(zoneID, pCastleInfo->getZoneID());
	}

	__END_CATCH
}

	
//////////////////////////////////////////////////////////////////////////////
// Delete zone info from zone info manager
//////////////////////////////////////////////////////////////////////////////
void CastleInfoManager::deleteCastleInfo (ZoneID_t zoneID) 
	throw (Error)
{
	__BEGIN_TRY
		
	map< ZoneID_t , CastleInfo *>::iterator itr = m_CastleInfos.find(zoneID);
	
	if (itr != m_CastleInfos.end()) 
	{
		// �� ����Ѵ�.
		SAFE_DELETE(itr->second);

		// pair�� ����Ѵ�.
		m_CastleInfos.erase(itr);
	} 
	else 
	{
		// �׷� � ���̵��� ã� �� ����� ��
		return;
	}

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// get zone from zone info manager
//////////////////////////////////////////////////////////////////////////////
CastleInfo* CastleInfoManager::getCastleInfo (ZoneID_t zoneID) const
	throw (Error)
{
	__BEGIN_TRY
		
	CastleInfo* pCastleInfo = NULL;

	map< ZoneID_t , CastleInfo *>::const_iterator itr = m_CastleInfos.find(zoneID);
	
	if (itr != m_CastleInfos.end()) {

		pCastleInfo = itr->second;

	} else {

		// �׷� � ���̵��� ã� �� ����� ��

		return NULL;

	}

	return pCastleInfo;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// get debug string
//////////////////////////////////////////////////////////////////////////////
string CastleInfoManager::toString () const
	throw ()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "CastleInfoManager(";

	if (m_CastleInfos.empty()) msg << "EMPTY";
	else 
	{
		for (map< ZoneID_t , CastleInfo* >::const_iterator itr = m_CastleInfos.begin() ; itr != m_CastleInfos.end() ; itr ++) 
		{
			msg << itr->second->toString();
		}
	}

	msg << ")";

	return msg.toString();

	__END_CATCH
}

bool CastleInfoManager::modifyCastleOwner(ZoneID_t zoneID, PlayerCreature* pPC )
	throw(Error)
{
	__BEGIN_TRY

	Assert( pPC != NULL );

	Race_t 		race 	= pPC->getRace();
	GuildID_t 	guildID = pPC->getGuildID();

	return modifyCastleOwner( zoneID, race, guildID );

	__END_CATCH
}

bool CastleInfoManager::modifyCastleOwner(ZoneID_t zoneID, Race_t race, GuildID_t guildID )
	throw(Error)
{
	__BEGIN_TRY

	CastleInfo* pCastleInfo = getCastleInfo( zoneID );
	if( pCastleInfo == NULL ) return false;

	Race_t oldRace = pCastleInfo->getRace();

	pCastleInfo->setGuildID( guildID );
	pCastleInfo->setRace( race );
	pCastleInfo->setTaxBalance( 0 );

	Zone* pZone = getZoneByZoneID(zoneID);

	if( pCastleInfo->isCommon() )
	{
		pCastleInfo->setEntranceFee( g_pVariableManager->getVariable( COMMON_CASTLE_ENTRANCE_FEE ) );
		setItemTaxRatio( pZone, g_pVariableManager->getVariable( COMMON_CASTLE_ITEM_TAX_RATIO ) );
	}
	else
	{
		pCastleInfo->setEntranceFee( g_pVariableManager->getVariable( GUILD_CASTLE_ENTRANCE_FEE ) );
		setItemTaxRatio( pZone, g_pVariableManager->getVariable( GUILD_CASTLE_ITEM_TAX_RATIO ) );
	}

	StringStream msg;

	msg << "GuildID = " << (int)pCastleInfo->getGuildID()
		<< ",Race = " << (int)pCastleInfo->getRace()
		<< ",TaxBalance = " << (int)pCastleInfo->getTaxBalance()
		<< ",ItemTaxRatio = " << (int)pCastleInfo->getItemTaxRatio()
		<< ",EntranceFee = " << (int)pCastleInfo->getEntranceFee();

	if( tinysave( zoneID, msg.toString() ) )
	{
//		StringStream msg;
		char msg[100];
		if( guildID == SlayerCommon )
		{
//			msg << pCastleInfo->getName() << "���� �����̾� ���� ���� �Ǿ���ϴ�.";
			sprintf( msg, g_pStringPool->c_str( STRID_BECOME_SLAYER_COMMON_CASTLE ),
							pCastleInfo->getName().c_str() );
		}
		else if ( guildID == VampireCommon )
		{
//			msg << pCastleInfo->getName() << "���� �����̾� ���� ���� �Ǿ���ϴ�.";
			sprintf( msg, g_pStringPool->c_str( STRID_BECOME_VAMPIRE_COMMON_CASTLE ),
							pCastleInfo->getName().c_str() );
		}
		else if ( guildID == OustersCommon )
		{
			sprintf( msg, "%s ���� �ƿ콺���� ���� ���� �Ǿ���ϴ�.", pCastleInfo->getName().c_str() );
		}
		else
		{
			Guild* pGuild = g_pGuildManager->getGuild( guildID );

			if( pGuild == NULL )
			{
				filelog( "CastleError.log", "�� �� ���� ����ID : %d", (int)guildID );
			}
			else
			{
				if ( pGuild->getRace() == Guild::GUILD_RACE_SLAYER )
				{
//					msg << pGuild->getName() << " ���� ";
					sprintf( msg, g_pStringPool->c_str( STRID_BECOME_SLAYER_GUILD_CASTLE ),
								pGuild->getName().c_str(), pCastleInfo->getName().c_str() );
				}
				else
				{
//					msg << pGuild->getName() << " Ŭ���� ";
					sprintf( msg, g_pStringPool->c_str( STRID_BECOME_VAMPIRE_GUILD_CASTLE ),
								pGuild->getName().c_str(), pCastleInfo->getName().c_str() );
				}
			}

//			msg << pCastleInfo->getName() << " ��� ����߽�ϴ�.";
		}

		// ��� ����� ���� �ٲ� ������ ó��
		if ( oldRace != race )
		{
			// �� ���� ���ʽ� �缳�
			//g_pHolyLandRaceBonus->refresh();

			// [NPC �缳�] --> War���� �Ѵ�.
			/*
			Zone* pZone = getZoneByZoneID( zoneID );

			// ���� NPC�� ���� ������.
			pZone->deleteNPCs( oldRace );

			// ���� NPC�� �ٽ� Load�Ѵ�.
			pZone->loadNPCs( race );
			*/

			// ���� ���� ������� ���� �����Ѵ�.
			WarScheduler* pWarScheduler = pZone->getWarScheduler();
			Assert(pWarScheduler!=NULL);

			// ������ ������� ���� �����Ѵ�.
			pWarScheduler->cancelGuildSchedules();
		}

		filelog( "WarLog.txt", "[CastleZoneID:%u]%s", (uint)pCastleInfo->getZoneID(), msg );

		// Holy Land Race Bonus �� Player ���� �ٷ� �����ǵ��� �Ѵ�.
		EventRefreshHolyLandPlayer* pEvent = new EventRefreshHolyLandPlayer( NULL );
		pEvent->setDeadline(0);
		g_pClientManager->addEvent( pEvent );

		GCSystemMessage gcSystemMessage;
		gcSystemMessage.setType( SYSTEM_MESSAGE_HOLY_LAND );
		gcSystemMessage.setMessage( msg );
		g_pZoneGroupManager->broadcast( &gcSystemMessage );
	}

	return true;

	__END_CATCH
}

bool CastleInfoManager::increaseTaxBalance( ZoneID_t zoneID, Gold_t tax )
	throw(Error)
{
	__BEGIN_TRY

	CastleInfo* pCastleInfo = getCastleInfo( zoneID );
	if ( pCastleInfo == NULL) return false;

	Gold_t TaxBalance = pCastleInfo->increaseTaxBalance(tax);

	char str[40];
	sprintf(str, "TaxBalance=%d", (int)TaxBalance );

	return tinysave( zoneID, str );

	__END_CATCH
}
bool CastleInfoManager::decreaseTaxBalance( ZoneID_t zoneID, Gold_t tax ) 
	throw(Error)
{
	__BEGIN_TRY

	CastleInfo* pCastleInfo = getCastleInfo( zoneID );
	if ( pCastleInfo == NULL) return false;

	Gold_t TaxBalance = pCastleInfo->decreaseTaxBalance(tax);

	char str[40];
	sprintf(str, "TaxBalance=%d", (int)TaxBalance );

	return tinysave( zoneID, str );

	__END_CATCH
}

bool CastleInfoManager::setItemTaxRatio( Zone* pZone, int itemTaxRatio ) 
	throw(Error)
{
	__BEGIN_TRY

	Assert(pZone != NULL);
	CastleInfo* pCastleInfo = getCastleInfo( pZone->getZoneID() );
	if ( pCastleInfo == NULL) return false;

	pCastleInfo->setItemTaxRatio( itemTaxRatio );

	char str[40];
	sprintf(str,"ItemTaxRatio=%d", (int)itemTaxRatio);

	tinysave( pZone->getZoneID(), str );

	GCNoticeEvent gcNoticeEvent;
	gcNoticeEvent.setCode(NOTICE_EVENT_SHOP_TAX_CHANGE);
	gcNoticeEvent.setParameter((uint)itemTaxRatio);

	pZone->broadcastPacket(&gcNoticeEvent);

	return true;

	__END_CATCH
}

int CastleInfoManager::getItemTaxRatio( PlayerCreature* pPC ) const
	throw(Error)
{
	__BEGIN_TRY

	Assert(pPC != NULL);
	Zone* pZone = pPC->getZone();
	const CastleInfo* pCastleInfo = getCastleInfo( pZone->getZoneID() );

	if (pCastleInfo != NULL) 
	{
		GuildID_t 	OwnerGuildID = pCastleInfo->getGuildID();
		GuildID_t 	PlayerGuildID = pPC->getGuildID();
		int			ItemTaxRatio = pCastleInfo->getItemTaxRatio();
		

		if ( PlayerGuildID == SlayerCommon 
			 || PlayerGuildID == VampireCommon
			 || PlayerGuildID == OustersCommon
			 || PlayerGuildID != OwnerGuildID )
		{
			return ItemTaxRatio;
		}
	}

	return 100;

	__END_CATCH
}

Gold_t CastleInfoManager::getEntranceFee( ZoneID_t zoneID, PlayerCreature* pPC ) const
	throw(Error)
{
	__BEGIN_TRY

    Assert(pPC != NULL);
    const CastleInfo* pCastleInfo = getCastleInfo( zoneID );

	// ���� ���� ���̶��� �����ᰡ 0 �̴�.
    if ( pCastleInfo != NULL && !g_pWarSystem->hasCastleActiveWar( zoneID ) && !g_pWarSystem->hasActiveRaceWar() )
    {
        GuildID_t   OwnerGuildID = pCastleInfo->getGuildID();
        GuildID_t   PlayerGuildID = pPC->getGuildID();
        Gold_t      EntranceFee = pCastleInfo->getEntranceFee();

        if ( PlayerGuildID == SlayerCommon
             || PlayerGuildID == VampireCommon
             || PlayerGuildID == OustersCommon
             || PlayerGuildID != OwnerGuildID )
        {
            return EntranceFee;
        }
    }

    return 0;

	__END_CATCH
}

bool CastleInfoManager::isCastleMember( PlayerCreature* pPC ) const
	throw(Error)
{
	__BEGIN_TRY

    Assert(pPC != NULL);
    Zone* pZone = pPC->getZone();
    const CastleInfo* pCastleInfo = getCastleInfo( pZone->getZoneID() );

    if (pCastleInfo != NULL)
    {
        GuildID_t   OwnerGuildID = pCastleInfo->getGuildID();
        GuildID_t   PlayerGuildID = pPC->getGuildID();

        if ( PlayerGuildID == SlayerCommon
             || PlayerGuildID == VampireCommon
			 || PlayerGuildID == OustersCommon
             || PlayerGuildID != OwnerGuildID )
        {
            return false;
        }
    }

    return true;

	__END_CATCH
}

bool CastleInfoManager::isCastleMember( ZoneID_t zoneID, PlayerCreature* pPC ) const
	throw(Error)
{
	__BEGIN_TRY

    Assert(pPC != NULL);
    const CastleInfo* pCastleInfo = getCastleInfo( zoneID );

    if (pCastleInfo != NULL)
    {
        GuildID_t   OwnerGuildID = pCastleInfo->getGuildID();
        GuildID_t   PlayerGuildID = pPC->getGuildID();

        if ( PlayerGuildID == SlayerCommon
             || PlayerGuildID == VampireCommon
             || PlayerGuildID == OustersCommon
             || PlayerGuildID != OwnerGuildID )
        {
            return false;
        }
    }
	else
		return false;

    return true;

	__END_CATCH
}

bool CastleInfoManager::hasOtherBloodBible( ZoneID_t zoneID, PlayerCreature* pPC ) const
	throw(Error)
{
	__BEGIN_TRY

	if ( pPC->isFlag( Effect::EFFECT_CLASS_HAS_BLOOD_BIBLE ) )
	{
		// �� ���� �ش����� �ʴ� ���� ������ ���� ����� �� ����� �ؾ� �Ѵ�.
		EffectHasBloodBible* pEffect = dynamic_cast<EffectHasBloodBible*>( pPC->findEffect( Effect::EFFECT_CLASS_HAS_BLOOD_BIBLE ) );
		Assert( pEffect != NULL );
		
		int part = pEffect->getPart();
		ShrineSet* pShrineSet = g_pShrineInfoManager->getShrineSet( part );
		if ( pShrineSet->getVampireGuardShrine().getZoneID() == zoneID
		||	 pShrineSet->getSlayerGuardShrine().getZoneID() == zoneID
		||	 pShrineSet->getOustersGuardShrine().getZoneID() == zoneID )
		{
			return false;
		}

		return true;
	}
	else
	{
		return false;
	}

	__END_CATCH
}
	
bool CastleInfoManager::isPossibleEnter( ZoneID_t zoneID, PlayerCreature* pPC ) const
	throw(Error)
{

    __BEGIN_TRY

    Assert(pPC != NULL);
    const CastleInfo* pCastleInfo = getCastleInfo( zoneID );

    if (pCastleInfo != NULL)
    {
        Race_t   OwnerRace = pCastleInfo->getRace();
        Race_t   PlayerRace = pPC->getRace();//(pPC->isSlayer()? RACE_SLAYER : RACE_VAMPIRE);

		if ( g_pWarSystem->hasActiveRaceWar() )
		{
			if ( hasOtherBloodBible( zoneID, pPC ) )
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else if ( OwnerRace == PlayerRace ) 
		{
			return true;
		}
		return false;
    }

    return true;

    __END_CATCH

}

bool CastleInfoManager::canPortalActivate( ZoneID_t zoneID, PlayerCreature* pPC ) const 
	throw(Error)
{
	__BEGIN_TRY

	const CastleInfo* pCastleInfo = getCastleInfo( zoneID );

	if ( pCastleInfo == NULL )
	{
		filelog( "CastleError.log", "CastleInfoManager::canPortalActivate() CastleInfo(%d)�� ����ϴ�.", (int)zoneID );
		Assert( false );
	}

	if ( g_pWarSystem->hasActiveRaceWar() )
	{
		if ( hasOtherBloodBible( zoneID, pPC ) )
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	if ( g_pWarSystem->hasCastleActiveWar( zoneID ) )
	{
		War* pWar = g_pWarSystem->getActiveWar( zoneID );
		
		if ( pWar != NULL )
		{
			return pPC->getRace() == pCastleInfo->getRace();
		}
	}

	return false;

	__END_CATCH
}

CastleInfo* CastleInfoManager::getGuildCastleInfo( GuildID_t guildID ) const
	throw(Error)
{

	__BEGIN_TRY

	if (guildID==SlayerCommon 
		|| guildID==VampireCommon
		|| guildID==OustersCommon
		)
	{
		return NULL;
	}

	map<ZoneID_t, CastleInfo*>::const_iterator itr = m_CastleInfos.begin();

	for (; itr!=m_CastleInfos.end(); itr++)
	{
		CastleInfo* pCastleInfo = itr->second;		

		if (pCastleInfo->getGuildID()==guildID)
		{
			return pCastleInfo;
		}
	}
	
	return NULL;

	__END_CATCH

}

list<CastleInfo*> CastleInfoManager::getGuildCastleInfos( GuildID_t guildID ) const
	throw(Error)
{

	__BEGIN_TRY

	list<CastleInfo*> castleList;

	if (guildID==SlayerCommon 
		|| guildID==VampireCommon
		|| guildID==OustersCommon
		)
	{
		return castleList;
	}

	map<ZoneID_t, CastleInfo*>::const_iterator itr = m_CastleInfos.begin();

	for (; itr!=m_CastleInfos.end(); itr++)
	{
		CastleInfo* pCastleInfo = itr->second;		

		if (pCastleInfo->getGuildID()==guildID)
		{
			castleList.push_back(pCastleInfo);
		}
	}
	
	return castleList;

	__END_CATCH

}

bool CastleInfoManager::getResurrectPosition( PlayerCreature* pPC, ZONE_COORD& zoneCoord ) 
	throw (Error)
{
	CastleInfo::ResurrectPriority resurrectPriority = CastleInfo::CASTLE_RESURRECT_PRIORITY_SECOND;

	ZoneID_t castleZoneID;
	bool isCastleZone = g_pCastleInfoManager->getCastleZoneID( pPC->getResurrectZoneID(), castleZoneID );

	if (!isCastleZone)
		return false;

	CastleInfo* pCastleInfo = getCastleInfo( castleZoneID );

	if ( pCastleInfo != NULL )
	{
		if ( pCastleInfo->getZoneID() != pPC->getResurrectZoneID() || g_pWarSystem->hasCastleActiveWar( castleZoneID ) )
		{
			// ��Ȱ�ġ�� ������� �Ǿ� �ִ� ����
			// ��Ȱ�ġ�� ���� ���� ������ �Ǿ� ����� ���ۿ� ��Ȱ�ġ�� ����� ����� �ν��Ѵ�.
			// �ʻ� �ϵ� �ڵ�. ��� ��Ȱ �ġ�� �ϳ��ۿ� ����� �� ��� �̷��� �ڵ��Ѵ�.
			// �ƴ��� ���� �����̳� ���� ��� ���쿡 �α��� �� ���� ���� ��Ȱ�ġ�� ���� ����� �� ����.�Ѥ�;
			// ��, ���� ���� ���� ���̶��� ���ۿ��� ��Ȱ�ϵ��� �Ѵ�.
			if ( isCastleMember( castleZoneID, pPC ) )
				resurrectPriority = CastleInfo::CASTLE_RESURRECT_PRIORITY_SECOND;
			else
				resurrectPriority = CastleInfo::CASTLE_RESURRECT_PRIORITY_THIRD;
		}
		else
		{
			// ��Ȱ�ġ�� ������� �Ǿ� �ִ� ����
			// �������� �ƴϸ� ����� �޴´�. ������ ���ڶ��� ���ۿ� ��Ȱ ��Ų��.
			if ( isCastleMember( castleZoneID, pPC ) )
				resurrectPriority = CastleInfo::CASTLE_RESURRECT_PRIORITY_FIRST;
			else
			{
				Gold_t fee = pCastleInfo->getEntranceFee();
				Gold_t remain = pPC->getGold();

				if ( remain < fee )
				{
					// ������ ����� ���� ���ۿ� ��Ȱ ��Ų��.
					resurrectPriority = CastleInfo::CASTLE_RESURRECT_PRIORITY_THIRD;
				}
				else
				{
					// ������ �ִٸ� ���� �ް� ���ȿ� ��Ȱ ��Ų��.
					pPC->decreaseGoldEx( fee );
					increaseTaxBalance( pCastleInfo->getZoneID(), fee );

					GCModifyInformation gcMI;
					gcMI.addLongData( MODIFY_GOLD, pPC->getGold() );

					GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPC->getPlayer());
					if ( pGamePlayer->getPlayerStatus() == GPS_NORMAL )
						pGamePlayer->sendPacket( &gcMI );

					resurrectPriority = CastleInfo::CASTLE_RESURRECT_PRIORITY_FIRST;
				}
			}
		}
	}
	else
	{
		return false;
	}

	pCastleInfo->getResurrectPosition( resurrectPriority, zoneCoord );

	return true;
}

bool CastleInfoManager::tinysave( ZoneID_t zoneID, const string& query )
	throw(Error)
{
	__BEGIN_TRY

	CastleInfo* pCastleInfo = getCastleInfo( zoneID );
	if( pCastleInfo == NULL ) return false;

	Statement* pStmt = NULL;
	bool isAffected = false;

	BEGIN_DB
	{
		// create statement
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		pStmt->executeQuery(
			"UPDATE CastleInfo SET %s WHERE ZoneID=%d AND ServerID=%d",
			query.c_str(), pCastleInfo->getZoneID(), g_pConfig->getPropertyInt("ServerID") );

		if( pStmt->getAffectedRowCount() > 0 )
			isAffected = true;

		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

	return isAffected;

	__END_CATCH
}

void    CastleInfoManager::deleteAllNPCs() 
	throw (Error)
{
	__BEGIN_TRY

	map<ZoneID_t, CastleInfo*>::const_iterator itr = m_CastleInfos.begin();

	for (; itr!=m_CastleInfos.end(); itr++)
	{
		CastleInfo* pCastleInfo = itr->second;		

		Zone* pZone = getZoneByZoneID( pCastleInfo->getZoneID() );
		Assert( pZone != NULL );

		__ENTER_CRITICAL_SECTION( (*pZone) )

		// NPC�� ���� ������.
		pZone->deleteNPCs( RACE_SLAYER );
		pZone->deleteNPCs( RACE_VAMPIRE );

		__LEAVE_CRITICAL_SECTION( (*pZone) )
	}

	__END_CATCH
}

void    CastleInfoManager::releaseAllSafeZone() 
	throw (Error)
{
	__BEGIN_TRY

	map<ZoneID_t, CastleInfo*>::const_iterator itr = m_CastleInfos.begin();

	for (; itr!=m_CastleInfos.end(); itr++)
	{
		CastleInfo* pCastleInfo = itr->second;		

		Zone* pZone = getZoneByZoneID( pCastleInfo->getZoneID() );
		Assert( pZone != NULL );

		__ENTER_CRITICAL_SECTION( (*pZone) )

		pZone->releaseSafeZone();

		__LEAVE_CRITICAL_SECTION( (*pZone) )
	}

	__END_CATCH
}

void    CastleInfoManager::resetAllSafeZone() 
	throw (Error)
{
	__BEGIN_TRY

	map<ZoneID_t, CastleInfo*>::const_iterator itr = m_CastleInfos.begin();

	for (; itr!=m_CastleInfos.end(); itr++)
	{
		CastleInfo* pCastleInfo = itr->second;		

		Zone* pZone = getZoneByZoneID( pCastleInfo->getZoneID() );
		Assert( pZone != NULL );

		__ENTER_CRITICAL_SECTION( (*pZone) )

		pZone->resetSafeZone();

		__LEAVE_CRITICAL_SECTION( (*pZone) )
	}

	__END_CATCH
}

void	CastleInfoManager::transportAllOtherRace()
	throw (Error)
{	
	__BEGIN_TRY

	map<ZoneID_t, CastleInfo*>::const_iterator itr = m_CastleInfos.begin();

	for (; itr!=m_CastleInfos.end(); itr++)
	{
		CastleInfo* pCastleInfo = itr->second;		

		// ���� ���õ� ���� ZoneID�� �����Ѵ�.
		const list<ZoneID_t>& zoneIDs = pCastleInfo->getZoneIDList();
		list<ZoneID_t>::const_iterator iZoneID = zoneIDs.begin();

		for (; iZoneID!=zoneIDs.end(); iZoneID++)
		{
			ZoneID_t zoneID = *iZoneID;

			Zone* pZone = getZoneByZoneID( zoneID );
			Assert( pZone != NULL );

			__ENTER_CRITICAL_SECTION( (*pZone) )

			// �������� �й��ڵ�� ��Ȱ �ġ�� ���� �Ѿƺ�����.
			Race_t otherRace = (pCastleInfo->getRace()==RACE_SLAYER? RACE_VAMPIRE : RACE_SLAYER);

			ZONE_COORD zoneCoord;
			pCastleInfo->getResurrectPosition( CastleInfo::CASTLE_RESURRECT_PRIORITY_SECOND, zoneCoord);

			PCManager* pPCManager = (PCManager*)(pZone->getPCManager());
			pPCManager->transportAllCreatures( zoneCoord.id, zoneCoord.x, zoneCoord.y, otherRace );

			__LEAVE_CRITICAL_SECTION( (*pZone) )
		}
	}

	__END_CATCH

}

void	CastleInfoManager::loadAllNPCs()
	throw (Error)
{	
	__BEGIN_TRY

	map<ZoneID_t, CastleInfo*>::const_iterator itr = m_CastleInfos.begin();

	for (; itr!=m_CastleInfos.end(); itr++)
	{
		CastleInfo* pCastleInfo = itr->second;		

		Zone* pZone = getZoneByZoneID( pCastleInfo->getZoneID() );
		Assert( pZone != NULL );

		__ENTER_CRITICAL_SECTION( (*pZone) )

		// NPC �ε�
		pZone->loadNPCs( pCastleInfo->getRace() );

		__LEAVE_CRITICAL_SECTION( (*pZone) )
	}

	__END_CATCH

}

ZoneID_t    CastleInfoManager::getCastleZoneID(ShrineID_t shrineID) const
	throw (Error)
{
	__BEGIN_TRY

	map<ZoneID_t, CastleInfo*>::const_iterator itr = m_CastleInfos.begin();

	for (; itr!=m_CastleInfos.end(); itr++)
	{
		CastleInfo* pCastleInfo = itr->second;		

		if (pCastleInfo->getShrineID()==shrineID)
		{
			return pCastleInfo->getZoneID();
		}
	}

	StringStream msg;
	msg << "�׷� ShrineID(" << (int)shrineID << ")�� ����ϴ�.";

	throw Error(msg.toString());

	return 0;

	__END_CATCH
}

void CastleInfoManager::broadcastShrinePacket(ShrineID_t shrineID, Packet* pPacket) const
	throw (Error)
{
	__BEGIN_TRY

	ZoneID_t castleZoneID = getCastleZoneID( shrineID );

	const CastleInfo* pCastleInfo = getCastleInfo( castleZoneID );
	Assert(pCastleInfo!=NULL);

	pCastleInfo->broadcast( pPacket );

	__END_CATCH
}

bool CastleInfoManager::isCastleZone(ZoneID_t castleZoneID, ZoneID_t targetZoneID) const
	throw (Error)
{
	__BEGIN_TRY

	const CastleInfo* pCastleInfo = getCastleInfo( castleZoneID );
	Assert(pCastleInfo!=NULL);

	return pCastleInfo->isCastleZone( targetZoneID );

	__END_CATCH
}

void  
CastleInfoManager::clearCastleZoneIDs()
	throw (Error)
{
	__BEGIN_TRY

	m_CastleZoneIDs.clear();

	__END_CATCH
}

bool 
CastleInfoManager::getCastleZoneID(ZoneID_t zoneID, ZoneID_t &castleZoneID) const
	throw (Error)
{
	__BEGIN_TRY

	map<ZoneID_t, ZoneID_t>::const_iterator itr = m_CastleZoneIDs.find( zoneID );

	if (itr!=m_CastleZoneIDs.end())
	{
		castleZoneID = itr->second;
		return true;
	}

	return false;

	__END_CATCH
}

void  
CastleInfoManager::setCastleZoneID(ZoneID_t zoneID, ZoneID_t castleZoneID)
	throw (Error)
{
	__BEGIN_TRY

	m_CastleZoneIDs[zoneID] = castleZoneID;

	__END_CATCH
}

bool        
CastleInfoManager::isSameCastleZone(ZoneID_t zoneID1, ZoneID_t zoneID2) const 
	throw (Error)
{
	__BEGIN_TRY

	ZoneID_t castleZoneID1, castleZoneID2;

	bool isCastle1 = getCastleZoneID(zoneID1, castleZoneID1);
	bool isCastle2 = getCastleZoneID(zoneID2, castleZoneID2);

	// �� �������� ���� �ƴϸ� ��� ���� ���� ��� �ƴϴ�.
	if (!isCastle1 || !isCastle2)
		return false;

	return castleZoneID1==castleZoneID2;

	__END_CATCH
}

SkillType_t CastleInfoManager::getCastleSkillType( ZoneID_t zoneID, GuildID_t guildID ) const
	throw (Error)
{
	__BEGIN_TRY

    const CastleInfo* pCastleInfo = getCastleInfo( zoneID );

    if (pCastleInfo != NULL)
    {
        GuildID_t   OwnerGuildID = pCastleInfo->getGuildID();

		// ���� ��� ���尡 �ƴϸ� ����.
        if ( guildID == SlayerCommon
             || guildID == VampireCommon
             || guildID == OustersCommon
             || guildID != OwnerGuildID )
        {
            return SKILL_MAX;
        }

		// ���� ���� ���� ���̶��� ����.
		if ( g_pWarSystem->hasCastleActiveWar( zoneID ) )
		{
			return SKILL_MAX;
		}

		return g_pCastleSkillInfoManager->getSkillType( zoneID );
    }

    return SKILL_MAX;

	__END_CATCH
}

// global variable definition
CastleInfoManager* g_pCastleInfoManager = NULL;
