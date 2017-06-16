//////////////////////////////////////////////////////////////////////////////
// Filename    : ZoneInfoManager.h
// Written By  : Reiot
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __ZONE_INFO_MANAGER_H__
#define __ZONE_INFO_MANAGER_H__

#include "Types.h"
#include "Exception.h"
#include "Zone.h"
#include "ZoneInfo.h"
#include <map>

//////////////////////////////////////////////////////////////////////////////
// class ZoneInfoManager;
// ZoneID �� Ű����� �ؼ� � ����� �˻��� �� �ִ� ����� ����Ѵ�.
//////////////////////////////////////////////////////////////////////////////

class ZoneInfoManager 
{
public:
	ZoneInfoManager() throw();
	~ZoneInfoManager() throw();

public:
	void init() throw(Error);
	void load() throw(Error);
	
	void addZoneInfo(ZoneInfo* pZoneInfo) throw(Error);
	void deleteZoneInfo(ZoneID_t zoneID) throw(NoSuchElementException);
	ZoneInfo* getZoneInfo(ZoneID_t zoneID) throw(NoSuchElementException);
	ZoneInfo* getZoneInfoByName(const string & ZoneName);
	int  size() const	{ return m_ZoneInfos.size(); }

	vector<Zone*> getNormalFields() const;

	string toString() const throw();

private:
	map<ZoneID_t, ZoneInfo*> m_ZoneInfos; // zone info �� �ؽ���
	map<string, ZoneInfo*> m_FullNameMap;
	map<string, ZoneInfo*> m_ShortNameMap;
};

extern ZoneInfoManager* g_pZoneInfoManager;

#endif
