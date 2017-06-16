//////////////////////////////////////////////////////////////////////////////
// Filename    : ParkingCenter.h
// Written By  : Reiot
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __PARKING_CENTER_H__
#define __PARKING_CENTER_H__

#include "Types.h"
#include "Exception.h"
#include "Zone.h"
#include "item/Motorcycle.h"
#include "Mutex.h"
#include <map>
#include <list>

//////////////////////////////////////////////////////////////////////////////
// class MotorcycleBox
//////////////////////////////////////////////////////////////////////////////

class MotorcycleBox 
{
public:
	MotorcycleBox(Motorcycle* pMotorcycle, Zone* pZone, ZoneCoord_t X, ZoneCoord_t Y) throw();
	virtual ~MotorcycleBox() throw();

public:
	Motorcycle* getMotorcycle() throw() { return m_pMotorcycle; }
	void setMotorcycle(Motorcycle* pMotorcycle) throw() { m_pMotorcycle = pMotorcycle; }

	Zone* getZone() const throw() { return m_pZone; }
	void setZone(Zone* pZone) throw() { m_pZone = pZone; }

	ZoneCoord_t getX() const throw() { return m_X; }
	void setX(ZoneCoord_t X) throw() { m_X = X; }

	ZoneCoord_t getY() const throw() { return m_Y; }
	void setY(ZoneCoord_t Y) throw() { m_Y = Y; }

	ItemID_t getItemID() const throw() { return m_pMotorcycle->getItemID(); }

	// �ٸ� zone��� �̵����� ��������
	bool isTransport() const throw() 		{ return m_bTransport; }
	void setTransport(bool bTransport=true) { m_bTransport = bTransport; }

private:
	// ��������Ŭ ��ü
	Motorcycle* m_pMotorcycle;

	// ���� ��������Ŭ�� �ִ� �ġ
	Zone* m_pZone;
	ZoneCoord_t m_X;
	ZoneCoord_t m_Y;

	// �ٸ� zone��� �̵� ��. by sigi. 2002.5.23
	bool m_bTransport;
};

//////////////////////////////////////////////////////////////////////////////
// class ParkingCenter;
//////////////////////////////////////////////////////////////////////////////

class ParkingCenter 
{
public: 
	ParkingCenter() throw();
	virtual ~ParkingCenter() throw();
	
public:
	void addMotorcycleBox(MotorcycleBox* pMotorcycleBox) throw(DuplicatedException, Error);

	// ���⼭ keyID�� ������ TargetID�� ���Ѵ�. ���� Motorcycle�� ItemID�̱⵵ �ϴ�.
	void deleteMotorcycleBox(ItemID_t keyTargetID) throw(NoSuchElementException, Error);

	// ���⼭ keyID�� ������ TargetID�� ���Ѵ�. ���� Motorcycle�� ItemID�̱⵵ �ϴ�.
	bool hasMotorcycleBox(ItemID_t keyTargetID) throw(NoSuchElementException, Error);

	// ���⼭ keyID�� ������ TargetID�� ���Ѵ�. ���� Motorcycle�� ItemID�̱⵵ �ϴ�.
	MotorcycleBox* getMotorcycleBox(ItemID_t keyTargetID) const throw(NoSuchElementException, Error);

	// �ַ� RemoveMotorcycles�� ó�����ش�. by sigi. 2003.2.26
	void	heartbeat() throw (Error);

private:
	// ���⼭ ItemID_t�� ���������� ItemID�� ���Ѵ�.
	map< ItemID_t, MotorcycleBox* > 	m_Motorcycles;
	list< MotorcycleBox* > 					m_RemoveMotorcycles;

	mutable Mutex m_Mutex;
	mutable Mutex m_MutexRemove;
};

// global variable declaration
extern ParkingCenter* g_pParkingCenter;

#endif
