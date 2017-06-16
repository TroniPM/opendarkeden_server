//////////////////////////////////////////////////////////////////////////////
// Filename    : ResurrectLocationManager.cpp
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "ResurrectLocationManager.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Zone.h"
#include "GamePlayer.h"
#include "WarSystem.h"
#include "Effect.h"
#include "ZoneInfo.h"
#include "ZoneInfoManager.h"
#include "CastleInfoManager.h"
#include "PacketUtil.h"
#include "VariableManager.h"
#include "DB.h"

//////////////////////////////////////////////////////////////////////////////
// ZONEID const Variable
//////////////////////////////////////////////////////////////////////////////
const ZoneID_t SLAYER_NOVICE_ZONE_ID = 12;
const ZoneID_t SLAYER_DEFAULT_ZONE_ID = 13;
const ZoneID_t VAMPIRE_DEFAULT_ZONE_ID = 23;
const ZoneID_t OUSTERS_DEFAULT_ZONE_ID = 1311;

//////////////////////////////////////////////////////////////////////////////
// global variable
//////////////////////////////////////////////////////////////////////////////

ResurrectLocationManager* g_pResurrectLocationManager = NULL;

//////////////////////////////////////////////////////////////////////////////
// class ResurrectLocationManager member methods
//////////////////////////////////////////////////////////////////////////////

ResurrectLocationManager::ResurrectLocationManager()
	throw()
{
	__BEGIN_TRY
	__END_CATCH
}

ResurrectLocationManager::~ResurrectLocationManager()
	throw()
{
	__BEGIN_TRY

	m_SlayerPosition.clear();
	m_VampirePosition.clear();

	__END_CATCH
}

void ResurrectLocationManager::init() 
	throw ()
{
	__BEGIN_TRY

	load();

	__END_CATCH
}

void ResurrectLocationManager::load() 
	throw ()
{
	__BEGIN_TRY

	Statement* pStmt   = NULL;
	Result*    pResult = NULL;

	BEGIN_DB
	{
		pStmt   = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery("SELECT ZoneID, SResurrectZoneID, SResurrectX, SResurrectY, VResurrectZoneID, VResurrectX, VResurrectY, OResurrectZoneID, OResurrectX, OResurrectY FROM ZoneInfo");
		
		if (pResult->getRowCount() == 0)
		{
			//cerr << "ResurrectLocationManager::load() : TABLE DOES NOT EXIST!" << endl;
			throw ("ResurrectLocationManager::load() : TABLE DOES NOT EXIST!");
		}

		while (pResult->next())
		{
			ZoneID_t   ID = 0;
			ZONE_COORD slayer_coord;
			ZONE_COORD vampire_coord;
			ZONE_COORD ousters_coord;

			ID               = pResult->getInt(1);
			slayer_coord.id  = pResult->getInt(2);
			slayer_coord.x   = pResult->getInt(3);
			slayer_coord.y   = pResult->getInt(4);
			vampire_coord.id = pResult->getInt(5);
			vampire_coord.x  = pResult->getInt(6);
			vampire_coord.y  = pResult->getInt(7);
			ousters_coord.id = pResult->getInt(8);
			ousters_coord.x  = pResult->getInt(9);
			ousters_coord.y  = pResult->getInt(10);

			addSlayerPosition(ID, slayer_coord);
			addVampirePosition(ID, vampire_coord);
			addOustersPosition(ID, ousters_coord);
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	__END_CATCH
}

bool ResurrectLocationManager::getSlayerPosition(ZoneID_t id, ZONE_COORD& zoneCoord) const 
	throw ()//NoSuchElementException)
{
	__BEGIN_TRY

	map<ZoneID_t, ZONE_COORD>::const_iterator itr = m_SlayerPosition.find(id);

	if (itr == m_SlayerPosition.end())
	{
		//cerr << "ResurrectLocationManager::getPosition() : No Such ZoneID" << endl;
		//throw NoSuchElementException("ResurrectLocationManager::getPosition() : No Such ZoneID");

		// NoSuch���. by sigi. 2002.5.9
		return false;
	}

	//return itr->second;
	zoneCoord = itr->second;

	return true;

	__END_CATCH
}


void ResurrectLocationManager::addSlayerPosition(ZoneID_t id, const ZONE_COORD& coord) 
	throw (DuplicatedException, Error)
{
	__BEGIN_TRY

	map<ZoneID_t, ZONE_COORD>::const_iterator itr = m_SlayerPosition.find(id);

	if (itr != m_SlayerPosition.end())
	{
		//cerr << "ResurrectLocationManager::addPosition() : ZoneID already exist!" << endl;
		throw NoSuchElementException("ResurrectLocationManager::addPosition() : ZoneID already exist!");
	}

	m_SlayerPosition[id] = coord;

	__END_CATCH
}

bool ResurrectLocationManager::getVampirePosition(ZoneID_t id, ZONE_COORD& zoneCoord) const 
	throw ()//NoSuchElementException)
{
	__BEGIN_TRY

	map<ZoneID_t, ZONE_COORD>::const_iterator itr = m_VampirePosition.find(id);

	if (itr == m_VampirePosition.end())
	{
		//cerr << "ResurrectLocationManager::getPosition() : No Such ZoneID" << endl;
		// NoSuch���. by sigi. 2002.5.9
		//throw NoSuchElementException("ResurrectLocationManager::getPosition() : No Such ZoneID");
		return false;
	}

	//return itr->second;

	zoneCoord = itr->second;

	return true;

	__END_CATCH
}


void ResurrectLocationManager::addVampirePosition(ZoneID_t id, const ZONE_COORD& coord) 
	throw (DuplicatedException, Error)
{
	__BEGIN_TRY

	map<ZoneID_t, ZONE_COORD>::const_iterator itr = m_VampirePosition.find(id);

	if (itr != m_VampirePosition.end())
	{
		//cerr << "ResurrectLocationManager::addPosition() : ZoneID already exist!" << endl;
		throw NoSuchElementException("ResurrectLocationManager::addPosition() : ZoneID already exist!");
	}

	m_VampirePosition[id] = coord;

	__END_CATCH
}


bool ResurrectLocationManager::getOustersPosition(ZoneID_t id, ZONE_COORD& zoneCoord) const 
	throw ()//NoSuchElementException)
{
	__BEGIN_TRY

	map<ZoneID_t, ZONE_COORD>::const_iterator itr = m_OustersPosition.find(id);

	if (itr == m_OustersPosition.end())
	{
		return false;
	}

	zoneCoord = itr->second;

	return true;

	__END_CATCH
}


void ResurrectLocationManager::addOustersPosition(ZoneID_t id, const ZONE_COORD& coord) 
	throw (DuplicatedException, Error)
{
	__BEGIN_TRY

	map<ZoneID_t, ZONE_COORD>::const_iterator itr = m_OustersPosition.find(id);

	if (itr != m_OustersPosition.end())
	{
		throw DuplicatedException("ResurrectLocationManager::addPosition() : ZoneID already exist!");
	}

	m_OustersPosition[id] = coord;

	__END_CATCH
}

bool ResurrectLocationManager::getPosition( PlayerCreature* pPC, ZONE_COORD& zoneCoord ) const
	throw(Error)
{
	__BEGIN_TRY

	Assert( pPC != NULL );

	try
	{
		bool bFindPosition = false;

		ZoneID_t castleZoneID;
		bool isCastleZone = g_pCastleInfoManager->getCastleZoneID( pPC->getResurrectZoneID(), castleZoneID );

		if ( g_pWarSystem->hasActiveRaceWar() && pPC->getZone()->isHolyLand() )
		{
			if ( pPC->isSlayer() )
			{
				if ( rand()%2 ) castleZoneID = 1201;
				else castleZoneID = 1203;
			}
			else if ( pPC->isVampire() )
			{
				if ( rand()%2 ) castleZoneID = 1202;
				else castleZoneID = 1204;
			}
			else if ( pPC->isOusters() )
			{
				if ( rand()%2 ) castleZoneID = 1205;
				else castleZoneID = 1206;
			}
			else castleZoneID = 0;

			if ( castleZoneID != 0 )
			{
				CastleInfo* pCastleInfo = g_pCastleInfoManager->getCastleInfo( castleZoneID );
				if ( pCastleInfo != NULL )
				{
					pCastleInfo->getResurrectPosition( CastleInfo::CASTLE_RESURRECT_PRIORITY_FIRST, zoneCoord );
					bFindPosition = true;
				}
			}
		}

		// �� ������ �����߿� .. ���� �ο� ���� �Ѵٸ�
		if (!bFindPosition
			&& g_pWarSystem->hasActiveRaceWar()
			&& g_pVariableManager->isActiveRaceWarLimiter())
		{
			ZoneInfo* pResZoneInfo = NULL;

			if (pPC->getResurrectZoneID()!=0)
			{
				try {
					pResZoneInfo = g_pZoneInfoManager->getZoneInfo( pPC->getResurrectZoneID() );
				} catch (Throwable& t) {
					filelog( "ResurrectLocationError.txt", "%s", t.toString().c_str() );
				}
			}
	
			// �ƴ��� ������ ����� ����.. ���� ��û� �� �ߴٸ�..
			if ( ( pResZoneInfo!=NULL && pResZoneInfo->isHolyLand() 
					|| pPC->getZone()->isHolyLand() )
				&& !pPC->isFlag( Effect::EFFECT_CLASS_RACE_WAR_JOIN_TICKET ))
			{
				// �� ���� �⺻ ��Ȱ�ġ�� ������.
				if ( getRaceDefaultPosition( pPC->getRace(), zoneCoord ) )
				{
					bFindPosition = true;
				}
				else
				{
					throw Error("Critical Error : ResurrectInfo is not established!2");
				}
			}
		}

		if (!bFindPosition)
		{
			if ( isCastleZone )
			{
				if ( !g_pCastleInfoManager->getResurrectPosition( pPC, zoneCoord ) )
				{
					if ( !getRaceDefaultPosition( pPC->getRace(), zoneCoord ) )
					{
						throw Error("Critical Error : ResurrectInfo is not established!2");
					}
				}
			}
			else
			{
				if ( !getBasicPosition( pPC, zoneCoord ) )
				{
					throw Error("Critical Error : ResurrectInfo is not established!2");
				}
			}
		}

#if defined(__PAY_SYSTEM_ZONE__) || defined(__PAY_SYSTEM_FREE_LIMIT__)
		// ���� üũ
		ZoneInfo* pZoneInfo = g_pZoneInfoManager->getZoneInfo( zoneCoord.id );
		GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPC->getPlayer());
		Assert(pGamePlayer!=NULL);

		// ���ȭ ��̰� ��������ڰ� �ƴϸ�..
		if (pZoneInfo!=NULL
			&& (pZoneInfo->isPayPlay() || pZoneInfo->isPremiumZone())
			&& !pGamePlayer->isPayPlaying())
		{
			string connectIP = pGamePlayer->getSocket()->getHost();

			// ��� ������ ������ �����Ѱ�?
			if (pGamePlayer->loginPayPlay(connectIP, pGamePlayer->getID()))
			{
				sendPayInfo(pGamePlayer);
			}
			else if (pZoneInfo->isPayPlay() && !pGamePlayer->isFamilyFreePass())
			{
				// ��� ������ ���� �Ұ��� ����
				// �� ���� default ���� ����Ѵ�.
				if ( !getRaceDefaultPosition( pPC->getRace(), zoneCoord ) )
					throw Error("Critical Error : ResurrectInfo is not established!2");
			}
		}
#endif
	}
	catch ( Error& e )
	{
		filelog( "ResurrectLocationError.txt", "%s", e.toString().c_str() );
		return false;
	}
	catch ( Throwable& t )
	{
		filelog( "ResurrectLocationError.txt", "%s", t.toString().c_str() );
		return false;
	}

	return true;

	__END_CATCH
}

bool ResurrectLocationManager::getBasicPosition( PlayerCreature* pPC, ZONE_COORD& zoneCoord ) const
	throw(Error)
{
	__BEGIN_TRY

	// �ϴ� PlayerCreature�� ����Ǿ� �ִ� ��Ȱ �ġ�� ����´�.
	if ( pPC->isSlayer() )
	{
		Slayer* pSlayer = dynamic_cast<Slayer*>(pPC);
		Assert( pSlayer != NULL );

		// �ʺ��� �̸� �ʺ������ ��Ȱ�ϵ��� �Ѵ�.
		if ( pSlayer->isNovice() )
		{
			pPC->setResurrectZoneID( SLAYER_NOVICE_ZONE_ID );
		}

		if ( !getSlayerPosition( pPC->getResurrectZoneID(), zoneCoord ) )
		{
			// ���� ����� ��Ȱ ��� ���ٸ� ���� �ִ� ��� ��Ȱ �ġ�� ����´�.
			if ( !getSlayerPosition( pPC->getZone()->getZoneID(), zoneCoord ) )
			{
				// ���� ��� ���ٸ� Default ��.
				if ( !getSlayerPosition( SLAYER_DEFAULT_ZONE_ID, zoneCoord ) )
					throw Error("Critical Error : ResurrectInfo is not established!2");
			}
		}
	}
	else if ( pPC->isVampire() )
	{
		if ( !getVampirePosition( pPC->getResurrectZoneID(), zoneCoord ) )
		{
			// ���� ����� ��Ȱ ��� ���ٸ� ���� �ִ� ��� ��Ȱ �ġ�� ����´�.
			if ( !getVampirePosition( pPC->getZone()->getZoneID(), zoneCoord ) )
			{
				// ���� ��� ���ٸ� Default ��.
				if ( !getVampirePosition( VAMPIRE_DEFAULT_ZONE_ID, zoneCoord ) )
					throw Error("Critical Error : ResurrectInfo is not established!2");
			}
		}
	}
	else if ( pPC->isOusters() )
	{
		if ( !getOustersPosition( pPC->getResurrectZoneID(), zoneCoord ) )
		{
			// ���� ����� ��Ȱ ��� ���ٸ� ���� �ִ� ��� ��Ȱ �ġ�� ����´�.
			if ( !getOustersPosition( pPC->getZone()->getZoneID(), zoneCoord ) )
			{
				// ���� ��� ���ٸ� Default ��.
				if ( !getOustersPosition( OUSTERS_DEFAULT_ZONE_ID, zoneCoord ) )
					throw Error("Critical Error : ResurrectInfo is not established!2");
			}
		}
	}

	return true;

	__END_CATCH
}

bool ResurrectLocationManager::getRaceDefaultPosition( Race_t race, ZONE_COORD& zoneCoord ) const
	throw()
{
	__BEGIN_TRY

	if ( race == RACE_SLAYER )
		return getSlayerPosition( SLAYER_DEFAULT_ZONE_ID, zoneCoord );
	else if ( race == RACE_VAMPIRE )
		return getVampirePosition( VAMPIRE_DEFAULT_ZONE_ID, zoneCoord );
	else if ( race == RACE_OUSTERS )
		return getOustersPosition( OUSTERS_DEFAULT_ZONE_ID, zoneCoord );

	return false;

	__END_CATCH
}

