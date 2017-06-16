//////////////////////////////////////////////////////////////////////////////
// Filename    : PrecedenceTable.cpp
// Written by  : excel96
// Description : 
// "����" ������ ��� �켱�� ����� ��� Ŭ�����̴�.
// �������� ������ ��ü �ȿ� ����ϴٰ�, �����Ͱ� �װų� ���� ���� ���� 
// �Ǹ� �÷��̾ ������� �԰ų�, ����� �� �� �ִ� ����� �Ǹ��� ������
// �ִ����� �˻��Ѵ�.
//////////////////////////////////////////////////////////////////////////////

#include "PrecedenceTable.h"
#include "Creature.h"
#include "StringStream.h"

//////////////////////////////////////////////////////////////////////////////
// class PrecedenceElement member methods
//////////////////////////////////////////////////////////////////////////////

PrecedenceElement::PrecedenceElement()
{
	m_Name     = "";
	m_PartyID  = -1;
	m_Damage   = 0;

	getCurrentTime(m_Deadline);
}

void PrecedenceElement::setNextTime(void)
{
	getCurrentTime(m_Deadline);
	m_Deadline.tv_sec += 30;
}

string PrecedenceElement::toString(void) const
{
	StringStream msg;
	msg << "PrecedenceElement("
		<< "Name:" << m_Name
		<< ",PartyID:" << m_PartyID
		<< ",Damage:" << m_Damage
		<< ")";
	return msg.toString();
}


//////////////////////////////////////////////////////////////////////////////
// class PrecedenceTable member methods
//////////////////////////////////////////////////////////////////////////////

PrecedenceTable::PrecedenceTable()
{
	m_FirstAttackerName    = "";
	m_FirstAttackerPartyID = 0;
	m_HostName             = "";
	m_HostPartyID          = 0;
	m_bComputeFlag         = false;
}

PrecedenceTable::~PrecedenceTable()
{
	// ũ���� ��� ������.
	map<string, PrecedenceElement*>::iterator itr = m_CreatureMap.begin();
	for (; itr != m_CreatureMap.end(); itr++)
	{
		SAFE_DELETE(itr->second);
	}
	m_CreatureMap.clear();

	// ��Ƽ ��� ������.
	map<int, PrecedenceElement*>::iterator itr2 = m_PartyMap.begin();
	for (; itr2 != m_PartyMap.end(); itr2++)
	{
		SAFE_DELETE(itr2->second);
	}
	m_PartyMap.clear();
}
/*
void PrecedenceTable::addPrecedence(Creature* pCreature, int damage)
{
	Assert(pCreature != NULL);

	// ũ���� ���� �����ִٴ� ���, ������ �����ڶ��� ���̴�.
	if (m_CreatureMap.empty())
	{
		// �������� �̸�� ������ �ְ�...
		m_FirstAttackerName = pCreature->getName();

		// ũ���� �ʿ��� �����͸� �߰��Ѵ�.
		PrecedenceElement* pElement = new PrecedenceElement;
		pElement->setName(pCreature->getName());
		pElement->setPartyID(-1);
		pElement->setDamage(damage);
		pElement->setNextTime();
		m_CreatureMap[pCreature->getName()] = pElement;
	}
	else
	{
		map<string, PrecedenceElement*>::iterator itr = m_CreatureMap.find(pCreature->getName());
		if (itr == m_CreatureMap.end())
		{
			// ������ ����� ���� �ʾҴٸ� �����͸� ���� ������ �ش�. 
			PrecedenceElement* pElement = new PrecedenceElement;
			pElement->setName(pCreature->getName());
			pElement->setPartyID(-1);
			pElement->setDamage(damage);
			pElement->setNextTime();
			m_CreatureMap[pCreature->getName()] = pElement;
		}
		else
		{
			// ������ ����� �ߴٸ� �����͸� ������ �ش�.
			PrecedenceElement* pElement = itr->second;
			pElement->setDamage(pElement->getDamage() + damage);
			pElement->setNextTime();
		}
	}

	// ��Ƽ�� ���� ���굵 ���ش�.
	// ��Ƽ�� ���ԵǾ� ���� �ʴٸ� ��Ƽ ID�� 0�̴�.
	// �ᱹ 0�� ��� ��Ƽ�� ���ԵǾ� ���� ��� �ڵ��� ���� �������� ���̴�.
	int PartyID = pCreature->getPartyID();
	if (m_PartyMap.empty())
	{
		PrecedenceElement* pElement = new PrecedenceElement;
		pElement->setPartyID(PartyID);
		pElement->setDamage(damage);
		pElement->setNextTime();
		m_PartyMap[PartyID] = pElement;
	}
	else
	{
		map<int, PrecedenceElement*>::iterator itr = m_PartyMap.find(PartyID);
		if (itr == m_PartyMap.end())
		{
			PrecedenceElement* pElement = new PrecedenceElement;
			pElement->setPartyID(PartyID);
			pElement->setDamage(damage);
			pElement->setNextTime();
			m_PartyMap[PartyID] = pElement;
		}
		else
		{
			PrecedenceElement* pElement = itr->second;
			pElement->setDamage(pElement->getDamage() + damage);
			pElement->setNextTime();
		}
	}
}
*/

void PrecedenceTable::addPrecedence(const string & Name, int PartyID, int damage)
{
	// ũ���� ���� �����ִٴ� ���, ������ �����ڶ��� ���̴�.
	if (m_CreatureMap.empty())
	{
		// �������� �̸�� ������ �ְ�...
		m_FirstAttackerName = Name;

		// ũ���� �ʿ��� �����͸� �߰��Ѵ�.
		PrecedenceElement* pElement = new PrecedenceElement;
		pElement->setName(Name);
		pElement->setPartyID(-1);
		pElement->setDamage(damage);
		pElement->setNextTime();
		m_CreatureMap[Name] = pElement;
	}
	else
	{
		map<string, PrecedenceElement*>::iterator itr = m_CreatureMap.find(Name);
		if (itr == m_CreatureMap.end())
		{
			// ������ ����� ���� �ʾҴٸ� �����͸� ���� ������ �ش�. 
			PrecedenceElement* pElement = new PrecedenceElement;
			pElement->setName(Name);
			pElement->setPartyID(-1);
			pElement->setDamage(damage);
			pElement->setNextTime();
			m_CreatureMap[Name] = pElement;
		}
		else
		{
			// ������ ����� �ߴٸ� �����͸� ������ �ش�.
			PrecedenceElement* pElement = itr->second;
			pElement->setDamage(pElement->getDamage() + damage);
			pElement->setNextTime();
		}
	}

	// ��Ƽ�� ���� ���굵 ���ش�.
	// ��Ƽ�� ���ԵǾ� ���� �ʴٸ� ��Ƽ ID�� 0�̴�.
	// �ᱹ 0�� ��� ��Ƽ�� ���ԵǾ� ���� ��� �ڵ��� ���� �������� ���̴�.
//	int PartyID = PartyID;
	if (m_PartyMap.empty())
	{
		PrecedenceElement* pElement = new PrecedenceElement;
		pElement->setPartyID(PartyID);
		pElement->setDamage(damage);
		pElement->setNextTime();
		m_PartyMap[PartyID] = pElement;
	}
	else
	{
		map<int, PrecedenceElement*>::iterator itr = m_PartyMap.find(PartyID);
		if (itr == m_PartyMap.end())
		{
			PrecedenceElement* pElement = new PrecedenceElement;
			pElement->setPartyID(PartyID);
			pElement->setDamage(damage);
			pElement->setNextTime();
			m_PartyMap[PartyID] = pElement;
		}
		else
		{
			PrecedenceElement* pElement = itr->second;
			pElement->setDamage(pElement->getDamage() + damage);
			pElement->setNextTime();
		}
	}

	// �ٽ� �����ϵ��� �ϱ� ��ؼ�.. by sigi. 2002.10.14
	m_bComputeFlag = false;
}

void PrecedenceTable::heartbeat(const Timeval& currentTime)
{
	map<string, PrecedenceElement*>::iterator c_before = m_CreatureMap.end();
	map<string, PrecedenceElement*>::iterator c_current = m_CreatureMap.begin();

	while (c_current != m_CreatureMap.end())
	{
		PrecedenceElement* pElement = c_current->second;
		Assert(pElement != NULL);

		if (pElement->getDeadline() < currentTime)
		{
			if (c_before == m_CreatureMap.end())
			{
				m_CreatureMap.erase(c_current);
				c_current = m_CreatureMap.begin();
			}
			else
			{
				m_CreatureMap.erase(c_current);
				c_current = c_before;
				c_current++;
			}
		}
		else
		{
			c_before = c_current++;
		}
	}

	map<string, PrecedenceElement*>::iterator p_before = m_CreatureMap.end();
	map<string, PrecedenceElement*>::iterator p_current = m_CreatureMap.begin();

	while (p_current != m_CreatureMap.end())
	{
		PrecedenceElement* pElement = p_current->second;
		Assert(pElement != NULL);

		if (pElement->getDeadline() < currentTime)
		{
			if (p_before == m_CreatureMap.end())
			{
				m_CreatureMap.erase(p_current);
				p_current = m_CreatureMap.begin();
			}
			else
			{
				m_CreatureMap.erase(p_current);
				p_current = p_before;
				p_current++;
			}
		}
		else
		{
			p_before = p_current++;
		}
	}
}

void PrecedenceTable::compute(void)
{
	// �̹� ��������� ���Ѵ�. by sigi. 2002.10.14
	if (m_bComputeFlag)
		return;

	int    MaxDamage           = 0;
	string MaxDamageName       = "";
	string SecondDamageName    = "";
	int    MaxDamagePartyID    = 0;
	int    SecondDamagePartyID = 0;

	Damage_t TotalDamage = 0;

	// ���� ũ���� ��� �˻��Ѵ�.
	map<string, PrecedenceElement*>::const_iterator itr = m_CreatureMap.begin();
	for (; itr != m_CreatureMap.end(); itr++)
	{
		PrecedenceElement* pElement = itr->second;
		Assert(pElement != NULL);

		if (MaxDamage < pElement->getDamage())
		{
			if (MaxDamageName == "")
			{
				MaxDamageName = pElement->getName();
				MaxDamage     = pElement->getDamage();
			}
			else
			{
				SecondDamageName = MaxDamageName;
				MaxDamageName    = pElement->getName();
				MaxDamage        = pElement->getDamage();
			}
		}

		TotalDamage += pElement->getDamage();
	}

	m_TotalDamage = TotalDamage;

	if (MaxDamageName != "")
	{
		// �ְ��� �������� �� �ڰ� �����ڶ���,
		// 40+20 = 60 �� �Ǿ� ������ �ȴ�.
		if (MaxDamageName == m_FirstAttackerName)
		{
			m_HostName = MaxDamageName;
		}
		// �ִ� �������� �� �ڰ� �����ڰ� �ƴ϶���,
		// �ι�°�� �������� ���� �� �ڰ�, �������� ���� 30+20�� �Ǿ� ������ �ȴ�.
		// �ι�°�� �������� ���� �� �ڰ� �����ڰ� �ƴ϶���, 
		// �ִ� �������� �� �ڰ� ������ �ȴ�.
		else
		{
			if (SecondDamageName != "" && SecondDamageName == m_FirstAttackerName)
			{
				m_HostName = SecondDamageName;
			}
			else
			{
				m_HostName = MaxDamageName;
			}
		}
	}
	else
	{
		// �ִ� �������� �� �ڰ� ��� ���� ��������,
		// Ȥ�ö��� �׷� ���찡 �ִٸ� �����ڸ� ������� �Ѵ�.
		m_HostName = m_FirstAttackerName;
	}

	// ��Ƽ�� ���� ����� ������ �־��� �Ѵ�.
	// ��Ƽ ��� ���꿡 �־ ����� �� ��Ƽ ID�� 0�� ����, 
	// �� ��Ƽ�� ���ԵǾ� ���� ��� �ڵ��� �������� ���� �����Ѵٴ� ��̴�.
	// ���� �ִ� �������� ���� ��ƼID�� 0�̶���, �� ��Ƽ�� ���ԵǾ� ���� ���
	// �������� �ִ� �������� �����ٸ�, HostPartyID�� 0�� �ȴ�.
	// �� ���쿡�� ��Ƽ�� ���ԵǾ� ���� ��� ������� ���� �Ǹ��� ������� �����ϴ�.
	// �׷��Ƿ� canLoot�� canDrainBlood���� ��Ƽ ID�� 0�� �ƴ����� �˻��ؾ� �� ���̴�.
	MaxDamage        = 0;
	MaxDamagePartyID = -1;
	SecondDamagePartyID    = -1;

	map<int, PrecedenceElement*>::const_iterator itr2 = m_PartyMap.begin();
	for (; itr2 != m_PartyMap.end(); itr2++)
	{
		PrecedenceElement* pElement = itr2->second;
		Assert(pElement != NULL);

		if (MaxDamage < pElement->getDamage())
		{
			if (MaxDamagePartyID == -1)
			{
				MaxDamagePartyID = pElement->getPartyID();
				MaxDamage        = pElement->getDamage();
			}
			else
			{
				SecondDamagePartyID = MaxDamagePartyID;
				MaxDamagePartyID    = pElement->getPartyID();
				MaxDamage           = pElement->getDamage();
			}
		}
	}

	if (MaxDamagePartyID != -1)
	{
		// �ְ��� �������� �� ��Ƽ�� ���� ��Ƽ����,
		// 40+20 = 60 �� �Ǿ� ������ �ȴ�.
		if (MaxDamagePartyID == m_FirstAttackerPartyID)
		{
			m_HostPartyID = MaxDamagePartyID;
		}
		// �ִ� �������� �� ��Ƽ�� �����ڰ� �ƴ϶���,
		// �ι�°�� �������� ���� �� ��Ƽ��, ������Ƽ�� ���� 30+20�� �Ǿ� ������ �ȴ�.
		// �ι�°�� �������� ���� �� ��Ƽ�� ������Ƽ�� �ƴ϶���, 
		// �ִ� �������� �� ��Ƽ�� ������ �ȴ�.
		else
		{
			if (SecondDamagePartyID != -1 && SecondDamagePartyID == m_FirstAttackerPartyID)
			{
				m_HostPartyID = SecondDamagePartyID;
			}
			else
			{
				m_HostPartyID = MaxDamagePartyID;
			}
		}
	}
	else
	{
		// �ִ� �������� �� �ڰ� ��� ���� ��������,
		// Ȥ�ö��� �׷� ���찡 �ִٸ� �����ڸ� ������� �Ѵ�.
		m_HostPartyID = m_FirstAttackerPartyID;
	}

	m_bComputeFlag = true;
}

bool PrecedenceTable::canLoot(Creature* pCreature) const
{
	// �켱��� ���� �ڶ��� ��Ʈ�� �� �ִ�.
	if (m_HostName == pCreature->getName()) return true;

	// �켱��� ���� ��Ƽ�� ���ԵǾ� �ִٸ� ��Ʈ�� �� �ִ�.
	int PartyID = pCreature->getPartyID();
	if (PartyID != 0 && m_HostPartyID == PartyID) return true;

	return false;
}

bool PrecedenceTable::canDrainBlood(Creature* pCreature) const
{
	// �켱��� ���� �ڶ��� ��Ʈ�� �� �ִ�.
	if (m_HostName == pCreature->getName()) return true;

	// �켱��� ���� ��Ƽ�� ���ԵǾ� �ִٸ� ��Ʈ�� �� �ִ�.
	int PartyID = pCreature->getPartyID();
	if (PartyID != 0 && m_HostPartyID == PartyID) return true;

	return false;
}

bool PrecedenceTable::canGainRankExp(Creature* pCreature) const
{
	// �����Ͱ� ��� �������� ���տ��� 1/4� �ʰ��� ��ŭ �������� ���ٸ� ���� ����ġ�� ��� �� �ִ�.
	map<string, PrecedenceElement*>::const_iterator itr = m_CreatureMap.find( pCreature->getName() );
	if ( itr == m_CreatureMap.end() )
		return false;

	return ( m_TotalDamage >> 2 ) < itr->second->getDamage();
}

double PrecedenceTable::getDamagePercent(const string& Name, int PartyID) const
{
	if ( m_TotalDamage == 0 )
		return 0.0;

	double ownDamage = 0.0;
	map<string, PrecedenceElement*>::const_iterator itr = m_CreatureMap.find(Name);
	if ( itr != m_CreatureMap.end() )
	{
		ownDamage = (double)(itr->second->getDamage());
	}

	double partyDamage = 0.0;
	if ( PartyID != 0 )
	{
		map<int, PrecedenceElement*>::const_iterator itr = m_PartyMap.find(PartyID);
		if ( itr != m_PartyMap.end() )
		{
			partyDamage = (double)(itr->second->getDamage());
		}
	}

	double maxDamage = ( ownDamage > partyDamage ? ownDamage : partyDamage );

	return maxDamage / (double)m_TotalDamage;
}

string PrecedenceTable::toString(void) const
{
	StringStream msg;
	msg << "PrecedenceTable("
		<< "FirstAttackerName:" << m_FirstAttackerName
		<< ",FirstAttackerPartyID:" << m_FirstAttackerPartyID
		<< ",HostName:" << m_HostName
		<< ",HostPartyID:" << m_HostPartyID
		<< ",ComputeFlag:" << m_bComputeFlag;

	msg << "\n,CreatureMap:\n";

	map<string, PrecedenceElement*>::const_iterator itr1 = m_CreatureMap.begin();
	for (; itr1 != m_CreatureMap.end(); itr1++)
	{
		msg << itr1->second->toString() << ",";
	}

	msg << "\n,PartyMap:\n";

	map<int, PrecedenceElement*>::const_iterator itr2 = m_PartyMap.begin();
	for (; itr2 != m_PartyMap.end(); itr2++)
	{
		msg << itr2->second->toString() << ",";
	}

	msg << ")";

	return msg.toString();
}
