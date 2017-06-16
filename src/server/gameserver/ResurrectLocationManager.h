//////////////////////////////////////////////////////////////////////////////
// Filename    : ResurrectLocationManager.h
// Written by  : excel96
// Description : 
// �÷��̾ �׾�� �� �ٽ� �¾�� ��Ȱ �ġ�� � ���� �����ϰ�
// �ִ� ���̴�. 
//////////////////////////////////////////////////////////////////////////////

#ifndef __RESURRECTMANAGER_H__
#define __RESURRECTMANAGER_H__

#include "Types.h"
#include "Exception.h"
#include <map>

//////////////////////////////////////////////////////////////////////////////
// class ResurrectLocationManager
//
// �÷��̾ �׾�� �� �ٽ� �¾�� ��Ȱ �ġ�� � ���� �����ϰ�
// �ִ� ���̴�. 
//
// �����̾� �� �����̾� ���� �⺻ ��Ȱ �ġ�� ����� �� �ִ� 
// �Լ��� �־��� �Ѵ�. ������ Resurrect.cpp�� �ҽ� ������ ��� �ִ�.
//////////////////////////////////////////////////////////////////////////////

class PlayerCreature;

class ResurrectLocationManager
{
public:
	ResurrectLocationManager() throw();
	~ResurrectLocationManager() throw();

public:
	void init() throw();
	void load() throw();

public:
	bool getSlayerPosition(ZoneID_t id, ZONE_COORD& zoneCoord) const throw();//NoSuchElementException);
	bool getVampirePosition(ZoneID_t id, ZONE_COORD& zoneCoord) const throw();//NoSuchElementException);
	bool getOustersPosition(ZoneID_t id, ZONE_COORD& zoneCoord) const throw();//NoSuchElementException);
	bool getRaceDefaultPosition(Race_t, ZONE_COORD& zoneCoord) const throw();

	bool getPosition(PlayerCreature* pPC, ZONE_COORD& zondCoord) const throw(Error);
	bool getBasicPosition(PlayerCreature* pPC, ZONE_COORD& zondCoord) const throw(Error);

	void addSlayerPosition(ZoneID_t id, const ZONE_COORD& coord) throw(DuplicatedException, Error);
	void addVampirePosition(ZoneID_t id, const ZONE_COORD& coord) throw(DuplicatedException, Error);
	void addOustersPosition(ZoneID_t id, const ZONE_COORD& coord) throw(DuplicatedException, Error);


protected:
	map<ZoneID_t, ZONE_COORD> m_SlayerPosition;
	map<ZoneID_t, ZONE_COORD> m_VampirePosition;
	map<ZoneID_t, ZONE_COORD> m_OustersPosition;
};


//////////////////////////////////////////////////////////////////////////////
// global variable
//////////////////////////////////////////////////////////////////////////////
extern ResurrectLocationManager* g_pResurrectLocationManager;

#endif
