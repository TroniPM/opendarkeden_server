//////////////////////////////////////////////////////////////////////////////
// Filename    : PrecedenceTable.h
// Written by  : excel96
// Description : 
// "����" ������ ��� �켱�� ����� ��� Ŭ�����̴�.
// �������� ������ ��ü �ȿ� ����ϴٰ�, �����Ͱ� �װų� ���� ���� ���� 
// �Ǹ� �÷��̾ ������� �԰ų�, ����� �� �� �ִ� ����� �Ǹ��� ������
// �ִ����� �˻��Ѵ�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __PRECEDENCETABLE_H__
#define __PRECEDENCETABLE_H__

#include "Types.h"
#include "Timeval.h"
#include <map>

//////////////////////////////////////////////////////////////////////////////
// Forward declaration
//////////////////////////////////////////////////////////////////////////////
class Creature;

//////////////////////////////////////////////////////////////////////////////
// class PrecedenceElement;
// PrecedenceTable �ȿ� ����� ��ü�μ� ������ �÷��̾ �����Ϳ��� ����
// ������ ���� ��������� �������� ���� �ð�, �׸��� �� �÷��̾�� ����
// ����� ������ �δ� �� ���δ�.
//////////////////////////////////////////////////////////////////////////////

class PrecedenceElement
{
public:
	PrecedenceElement();

public:
	string getName(void) const { return m_Name; }
	void setName(const string& name) { m_Name = name; }

	int getPartyID(void) const { return m_PartyID; }
	void setPartyID(int PartyID) { m_PartyID = PartyID; }
	
	int getDamage(void) const { return m_Damage; }
	void setDamage(int Damage) { m_Damage = Damage; }

	Timeval getDeadline(void) const { return m_Deadline; }
	void setDeadline(const Timeval& deadline) { m_Deadline = deadline; }
	void setNextTime(void);

	string toString(void) const;

public:
	string  m_Name;
	int     m_PartyID;
	int     m_Damage;
	Timeval m_Deadline;

};

//////////////////////////////////////////////////////////////////////////////
// class PrecedenceTable;
// PrecedenceElement�� ����ü�μ� ������ ��ü �ȿ� composition �������
// ���Եȴ�. addPrecedence �Լ��� �̿��� ������ �÷��̾ �� ��������
// �����ϰ� �ִٰ�, compute �Լ��� �̿��� ���� �� ���Ϳ��� ����� ������ 
// �Ǵ� ������ ���ؼ� �켱��� ������ �ִ� ���� �Ǵ��� �����ϰ� �ִ´�.
//////////////////////////////////////////////////////////////////////////////

class PrecedenceTable
{
public:
	PrecedenceTable();
	~PrecedenceTable();

public:
//	void addPrecedence(Creature* pCreature, int damage);
	void addPrecedence(const string & Name, int PartyID, int damage);
	void heartbeat(const Timeval& currentTime);
	void compute(void);

public:
	bool canLoot(Creature* pCreature) const;
	bool canDrainBlood(Creature* pCreature) const;
	bool canGainRankExp(Creature* pCreature) const;

	string getHostName(void) const { return m_HostName; }
	int getHostPartyID(void) const { return m_HostPartyID; }

	bool getComputeFlag(void) const { return m_bComputeFlag; }
	void setComputeFlag(bool bFlag) { m_bComputeFlag = bFlag; }

	string getQuestHostName() const { return m_QuestHostName; }
	void setQuestHostName( const string& name ) { m_QuestHostName = name; }

	double getDamagePercent(const string& Name, int PartyID) const;

	string toString(void) const;

protected:
	map<string, PrecedenceElement*> m_CreatureMap;
	map<int, PrecedenceElement*> m_PartyMap;

	string m_FirstAttackerName; // ��� ���� ����� ���� ���� �̸�
	int m_FirstAttackerPartyID; // ��� ���� ����� ���� ���� ��Ƽ ID

	string m_HostName; // ������ �̸�
	int m_HostPartyID; // ������ ��Ƽ ID

	string m_QuestHostName; // ����Ʈ �������� ���� �̸�

	bool m_bComputeFlag; // ����� ��ģ �����ΰ�...?

	Damage_t m_TotalDamage;	// ������ ����
};

#endif
