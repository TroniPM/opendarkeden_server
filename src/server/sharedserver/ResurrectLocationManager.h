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

	void addSlayerPosition(ZoneID_t id, const ZONE_COORD& coord) throw(DuplicatedException, Error);
	void addVampirePosition(ZoneID_t id, const ZONE_COORD& coord) throw(DuplicatedException, Error);


protected:
	map<ZoneID_t, ZONE_COORD> m_SlayerPosition;
	map<ZoneID_t, ZONE_COORD> m_VampirePosition;
};


//////////////////////////////////////////////////////////////////////////////
// global variable
//////////////////////////////////////////////////////////////////////////////
extern ResurrectLocationManager* g_pResurrectLocationManager;

#endif
