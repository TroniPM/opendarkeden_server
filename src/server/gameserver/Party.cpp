//////////////////////////////////////////////////////////////////////////////
// Filename    : PartyInvite.cpp
// Written by  : excel96
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "Party.h"
#include "CreatureUtil.h"
#include "StringStream.h"
#include "GamePlayer.h"
#include "Zone.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "StringStream.h"
#include "Effect.h"
#include "EffectManager.h"
#include "PCFinder.h"
#include "Item.h"
#include "PacketUtil.h"
#include <list>

#include "skill/SkillUtil.h"
#include "skill/EffectRevealer.h"
#include "skill/EffectDetectHidden.h"
#include "skill/EffectDetectInvisibility.h"
#include "skill/EffectExpansion.h"
#include "skill/EffectActivation.h"
#include "skill/EffectGnomesWhisper.h"
#include "skill/EffectHolyArmor.h"

#include "Gpackets/GCPartyLeave.h"
#include "Gpackets/GCPartyInvite.h"
#include "Gpackets/GCPartyJoined.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCOtherModifyInfo.h"
#include "Gpackets/GCOtherGuildName.h"

//////////////////////////////////////////////////////////////////////////////
// global varible 
//////////////////////////////////////////////////////////////////////////////
GlobalPartyManager* g_pGlobalPartyManager = NULL;

//////////////////////////////////////////////////////////////////////////////
//
// class PartyInviteInfo member methods
//
//////////////////////////////////////////////////////////////////////////////

string PartyInviteInfo::toString(void) const
	throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "PartyInviteInfo("
		<< "Host:" << m_HostName
		<< ",Guest:" << m_GuestName
		<< ")";
	return msg.toString();

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//
// class PartyInviteInfoManager member methods
//
//////////////////////////////////////////////////////////////////////////////

PartyInviteInfoManager::PartyInviteInfoManager()
	throw()
{
	__BEGIN_TRY

	m_Mutex.setName("PartyInviteInfoManager");

	__END_CATCH
}

PartyInviteInfoManager::~PartyInviteInfoManager()
	throw()
{
	__BEGIN_TRY

	map<string, PartyInviteInfo*>::iterator itr = m_InfoMap.begin();
	for (; itr != m_InfoMap.end(); itr++)
	{
		PartyInviteInfo* pInfo = itr->second;
		SAFE_DELETE(pInfo);
	}

	m_InfoMap.clear();
	
	__END_CATCH
}

bool PartyInviteInfoManager::hasInviteInfo(const string& HostName) 
	throw (Error)
{
	__BEGIN_TRY

	map<string, PartyInviteInfo*>::iterator itr = m_InfoMap.find(HostName);
	if (itr == m_InfoMap.end())
	{
		return false;
	}

	return true;

	__END_CATCH
}

bool PartyInviteInfoManager::canInvite(Creature* pHost, Creature* pGuest) 
	throw (Error)
{
	__BEGIN_TRY

	Assert(pHost != NULL && pGuest != NULL);

	// ���������� �ʴ븦 �ؾ� �Ѵ�.
	if (!pHost->isPC() || !pGuest->isPC()) return false;

	// �ٸ� �������� �ʴ��� �� ����.
	if (!isSameRace(pHost, pGuest)) return false;

	// �̹� �������� �ʴ��ϰ� �ְų�, �ʴ�ް� �ִٸ� �ʴ��� �� ����.
	PartyInviteInfo* pHostInfo  = getInviteInfo(pHost->getName());
	PartyInviteInfo* pGuestInfo = getInviteInfo(pGuest->getName());
	if (pHostInfo != NULL || pGuestInfo != NULL) return false;

	// �Խ�Ʈ�� �̹� ��Ƽ�� ���ԵǾ� �ִٸ� �ʴ��� �� ����.
	//if (pGuest->getPartyID() != 0) return false;

	return true;

	__END_CATCH
}

bool PartyInviteInfoManager::isInviting(Creature* pHost, Creature* pGuest) 
	throw (Error)
{
	__BEGIN_TRY

	Assert(pHost != NULL && pGuest != NULL);

	PartyInviteInfo* pHostInfo  = getInviteInfo(pHost->getName());
	PartyInviteInfo* pGuestInfo = getInviteInfo(pGuest->getName());

	if (pHostInfo == NULL || pGuestInfo == NULL) return false;

	// ���ΰ� �ֹ������ ���븦 ����Ű�� �־��� �Ѵ�.
	// A(Host)      | B(Guest)
	// Host  : shit | Host  : fuck
	// Guest : fuck | Guest : shit
	if ((pHostInfo->getGuestName()  == pGuestInfo->getHostName()) &&
		(pGuestInfo->getGuestName() == pHostInfo->getHostName())) return true;

	return false;

	__END_CATCH
}

void PartyInviteInfoManager::initInviteInfo(Creature* pHost, Creature* pGuest) 
	throw (Error)
{
	__BEGIN_TRY

	if (hasInviteInfo(pHost->getName()) || hasInviteInfo(pGuest->getName()))
	{
		// ���⼭ ������ ��ø ������ �Ͼ����. �׷��ϱ�, CGPartyInvite
		// ��Ŷ�� ���ؼ� ��Ƽ �ʴ� ����� �ʱ�ȭ�Ƿ�� ����ε�, �̹�
		// �ʴ� ����� ����Ѵٴ� ���̴�. ������ ������ ����� �ϴµ�,
		// ����� �� ���� ���, �� �ֹ��� ����� ������ ���������� �����ߴ�.
		cancelInvite(pHost, pGuest);
		return;
	}

	PartyInviteInfo* pHostInfo  = new PartyInviteInfo;
	pHostInfo->setHostName(pHost->getName());
	pHostInfo->setGuestName(pGuest->getName());

	if (!addInviteInfo(pHostInfo))
	{
		delete pHostInfo;
	}

	PartyInviteInfo* pGuestInfo  = new PartyInviteInfo;
	pGuestInfo->setHostName(pGuest->getName());
	pGuestInfo->setGuestName(pHost->getName());

	if (!addInviteInfo(pGuestInfo))
	{
		delete pHostInfo;
	}

	__END_CATCH
}

void PartyInviteInfoManager::cancelInvite(Creature* pHost, Creature* pGuest) 
	throw (Error)
{
	__BEGIN_TRY

	Assert(pHost != NULL && pGuest != NULL);

	int nCondition = 0;

	// �� �� ������ �ƴ϶��� �����Ѵ�.
	if (!pHost->isPC() || !pGuest->isPC()) nCondition = 1;
	if (!isSameRace(pHost, pGuest))        nCondition = 2;
	if (!isInviting(pHost, pGuest))        nCondition = 4;

	if (nCondition != 0)
	{
		cerr << "PartyInviteInfoManager::cancelInvite() : Error = " << nCondition << endl;
		// initInviteInfo()���� �Ͼ�� ������ ���������� ���⿡���� 
		// �� �ݴ��� ������ �Ͼ��, �ּ�ó���� ���ȴ�.
		//throw Error("PartyInviteInfoManager::cancelInvite()");
	}

	deleteInviteInfo(pHost->getName());
	deleteInviteInfo(pGuest->getName());

	__END_CATCH
}

void PartyInviteInfoManager::cancelInvite(Creature* pCreature) 
	throw (Error)
{
	__BEGIN_TRY

	Assert(pCreature != NULL);

	PartyInviteInfo* pInfo = getInviteInfo(pCreature->getName());

	if (pInfo != NULL)
	{
		Zone* pZone = pCreature->getZone();	// if �ۿ� �ִ��� �ű�. by sigi. 2002.5.8

		const string& HostName  = pInfo->getHostName();	// &�߰�. by sigi. 2002.5.8
		const string& GuestName = pInfo->getGuestName();

		Creature* pTargetCreature = NULL;
		/*
		try
		{
			pTargetCreature = pZone->getCreature(GuestName);
		}
		catch (NoSuchElementException)
		{
			pTargetCreature = NULL;
		}
		*/

		// NoSuch.. ���. by sigi. 2002.5.2
		pTargetCreature = pZone->getCreature(GuestName);

		// ��Ƽ �ʴ� ���밡 ��� ��� ����� ����, �����濡�� �ʴ밡 
		// �źεǾ��ٴ� ����� �����ش�.
		GCPartyInvite gcPartyInvite;
		gcPartyInvite.setTargetObjectID(pCreature->getObjectID());
		gcPartyInvite.setCode(GC_PARTY_INVITE_REJECT);

		if (pTargetCreature != NULL)
		{
			Player* pTargetPlayer = pTargetCreature->getPlayer();
			Assert(pTargetPlayer != NULL);
			pTargetPlayer->sendPacket(&gcPartyInvite);
		}
		
		deleteInviteInfo(HostName);
		deleteInviteInfo(GuestName);
	}
	/*
	else
	{
		cerr << "PartyInviteInfoManager::cancelInvite() : Error" << endl;
		throw ("PartyInviteInfoManager::cancelInvite() : Error");
	}
	*/

	__END_CATCH
}

bool PartyInviteInfoManager::addInviteInfo(PartyInviteInfo* pInfo) 
	throw (Error)
{
	__BEGIN_TRY

	map<string, PartyInviteInfo*>::iterator itr = m_InfoMap.find(pInfo->getHostName());
	if (itr != m_InfoMap.end())
	{
		cerr << "PartyInviteInfoManager::addInviteInfo() : DuplicatedException" << endl;
		//throw DuplicatedException("PartyInviteInfoManager::addInviteInfo() : DuplicatedException");

		// Exception���. by sigi. 2002.5.9
		return false;
	}

	m_InfoMap[pInfo->getHostName()] = pInfo;

	return true;

	__END_CATCH
}
	
void PartyInviteInfoManager::deleteInviteInfo(const string& HostName) 
	throw (NoSuchElementException, Error)
{
	__BEGIN_TRY

	map<string, PartyInviteInfo*>::iterator itr = m_InfoMap.find(HostName);
	if (itr != m_InfoMap.end())
	{
		m_InfoMap.erase(itr);
	}

	/*
	cerr << "PartyInviteInfoManager::deleteInviteInfo() : NoSuchElementException" << endl;
	throw NoSuchElementException("PartyInviteInfoManager::deleteInviteInfo() : NoSuchElementException");
	*/

	__END_CATCH
}
	
PartyInviteInfo* PartyInviteInfoManager::getInviteInfo(const string& HostName) 
	throw (NoSuchElementException, Error)
{
	__BEGIN_TRY

	map<string, PartyInviteInfo*>::iterator itr = m_InfoMap.find(HostName);

	if (itr == m_InfoMap.end())
	{
		return NULL;
	}
	/*
	{
		cerr << "PartyInviteInfoManager::getInviteInfo() : NoSuchElementException" << endl;
		throw NoSuchElementException("PartyInviteInfoManager::getInviteInfo() : NoSuchElementException");
	}
	*/


	return itr->second;

	__END_CATCH
}



//////////////////////////////////////////////////////////////////////////////
//
// class Party member methods
//
//////////////////////////////////////////////////////////////////////////////

Party::Party(Creature::CreatureClass CClass) 
	throw()
{
	__BEGIN_TRY

	// ��Ƽ�� ���� �� �ִ� ũ���� Ŭ������ ����ְ�...
	m_CreatureClass = CClass;

	m_bFamilyPay = false;

	// ���ؽ��� �̸�� �����Ѵ�. (��������)
	m_Mutex.setName("Party");

	__END_CATCH
}

Party::~Party() 
	throw()
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	m_MemberMap.clear();

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

// �̸���� ��Ƽ�� ������ ã�Ƽ� �����Ѵ�.
Creature* Party::getMember(const string& name) const
	throw (NoSuchElementException, Error)
{
	__BEGIN_TRY

	//cout << "Party::getMember() : BEGIN" << endl;

	Creature* pCreature = NULL;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map<string, Creature*>::const_iterator itr = m_MemberMap.find(name);
	if (itr == m_MemberMap.end())
	{
		cerr << "Party::getMember() : NoSuchElementException" << endl;
		throw NoSuchElementException("Party::getMember() : NoSuchElementException");
	}

	pCreature = itr->second;

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	//cout << "Party::getMember() : END" << endl;

	return pCreature;

	__END_CATCH
}

// ������ ���Ѵ�.
void Party::addMember(Creature* pCreature) 
	throw (DuplicatedException, Error)
{
	__BEGIN_TRY

	//cout << "Party::addMember() : BEGIN" << endl;

	// ��Ƽ�� ���� �� �ִ� ���� �ƴ϶���...
	if (pCreature->getCreatureClass() != m_CreatureClass)
	{
		cerr << "Party::addMember() : Invalid Creature Class" << endl;
		throw Error("Party::addMember() : Invalid Creature Class");
	}

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map<string, Creature*>::iterator itr = m_MemberMap.find(pCreature->getName());
	if (itr == m_MemberMap.end())
	{
		m_MemberMap[pCreature->getName()] = pCreature;
	}
	else
	{
		/*
		cerr << "Party::addMember() : DuplicatedException" << endl;
		throw DuplicatedException("Party::addMember() : DuplicatedException");
		*/
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	//cout << "Party::addMember() : END" << endl;

	__END_CATCH
}

// ��Ƽ���� ������ ����Ѵ�.
void Party::deleteMember(const string& name) 
	throw (NoSuchElementException, Error)
{
	__BEGIN_TRY

	//cout << "Party::deleteMember() : BEGIN" << endl;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map<string, Creature*>::iterator itr = m_MemberMap.find(name);
	if (itr == m_MemberMap.end())
	{
		//cerr << "Party::deleteMember() : NoSuchElementException" << endl;
		//throw NoSuchElementException("Party::deleteMember() : NoSuchElementException");

		m_Mutex.unlock();
		return;
	}

	m_MemberMap.erase(itr);

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	//cout << "Party::deleteMember() : END" << endl;

	__END_CATCH
}

// ��Ƽ�� Ư� �̸�� ���� ������ �ִ��� ����Ѵ�.
bool Party::hasMember(const string& name) const
	throw ()
{
	__BEGIN_TRY

	//cout << "Party::hasMember() : BEGIN" << endl;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map<string, Creature*>::const_iterator itr = m_MemberMap.find(name);
	if (itr == m_MemberMap.end())
	{
		//cout << "Party::hasMember() : END" << endl;

		m_Mutex.unlock();
		return false;
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	//cout << "Party::hasMember() : END" << endl;

	return true;

	__END_CATCH
}

// �۷ι� ��Ƽ �Ŵ��������� �����Ѵ�...
// ��Ƽ�� ��ü�ϱ� ���� ��Ƽ �������� ��Ƽ ID�� 0��� ������,
// ���� ��Ƽ �Ŵ������� �ش� ID�� ���� ��Ƽ�� ����Ѵ�.
void Party::destroyParty(void) 
	throw()
{
	__BEGIN_TRY

	//cout << "Party::destroyParty() : BEGIN" << endl;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map<string, Creature*>::const_iterator itr = m_MemberMap.begin();
	for (; itr != m_MemberMap.end(); itr++)
	{
		Creature* pCreature = itr->second;
		Assert(pCreature != NULL);
		pCreature->setPartyID(0);

		//cout << "��Ƽ�� �����ִ� ũ����[" << pCreature->getName() << "]�� ��Ƽ ID�� 0��� ��������ϴ�." << endl;

		// ������ ��� �ִ� ���� ��Ƽ �Ŵ������� �ش��ϴ� ��Ƽ ��ü�� ����Ѵ�.
		Zone* pZone = pCreature->getZone();
		if (pZone != NULL)
		{
			LocalPartyManager* pLocalPartyManager = pZone->getLocalPartyManager();
			Assert(pLocalPartyManager != NULL);
			pLocalPartyManager->deletePartyMember(m_ID, pCreature);
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	//cout << "Party::destroyParty() : END" << endl;

	__END_CATCH
}

// ��Ƽ ����鿡�� ��Ŷ� ������.
void Party::broadcastPacket(Packet* pPacket, Creature* pOwner) 
	throw (ProtocolException, Error)
{
	__BEGIN_TRY

	//cout << "Party::broadcastPacket() : BEGIN" << endl;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map<string, Creature*>::const_iterator itr = m_MemberMap.begin();
	for (; itr != m_MemberMap.end(); itr++)
	{
		Creature* pCreature = itr->second;
		Assert(pCreature != NULL);

		if (pCreature != pOwner) 
			pCreature->getPlayer()->sendPacket(pPacket);
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	//cout << "Party::broadcastPacket() : END" << endl;

	__END_CATCH
}

// ���ο� ��Ƽ���� �߰��Ǿ�� ��, ��Ƽ���鿡�� ���ư���
// GCPartyJoined ��Ŷ� �����Ѵ�.
void Party::makeGCPartyJoined(GCPartyJoined* pGCPartyJoined) const
	throw()
{
	__BEGIN_TRY

	//cout << "Party::makeGCPartyJoined() : BEGIN" << endl;

	Assert(pGCPartyJoined != NULL);

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map<string, Creature*>::const_iterator itr = m_MemberMap.begin();
	for (; itr != m_MemberMap.end(); itr++)
	{
		Creature* pCreature = itr->second;
		Assert(pCreature != NULL);

		PARTY_MEMBER_INFO* pInfo = new PARTY_MEMBER_INFO;

		if (pCreature->isSlayer())
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

			pInfo->name       = pSlayer->getName();
			pInfo->sex        = pSlayer->getSex();
			pInfo->hair_style = pSlayer->getHairStyle();
			pInfo->ip         = pSlayer->getIP();
		}
		else if (pCreature->isVampire())
		{
			Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);

			pInfo->name       = pVampire->getName();
			pInfo->sex        = pVampire->getSex();
			pInfo->hair_style = 0;
			pInfo->ip         = pVampire->getIP();
		}
		else if ( pCreature->isOusters() )
		{
			// �ƿ콺�ͽ� �߰�. by bezz 2003.04.19
			Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);

			pInfo->name			= pOusters->getName();
			pInfo->sex			= pOusters->getSex();
			pInfo->hair_style	= 0;
			pInfo->ip			= pOusters->getIP();
		}
		else
		{
			Assert(false);
		}

		pGCPartyJoined->addMemberInfo(pInfo);
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	//cout << "Party::makeGCPartyJoined() : END" << endl;

	__END_CATCH
}

int Party::getSize(void) const 
	throw()
{
	__BEGIN_TRY

	return m_MemberMap.size();

	__END_CATCH
}

map<string, Creature*> Party::getMemberMap(void) throw() 
{ 
	__BEGIN_TRY

	return m_MemberMap; 

	__END_CATCH
}

int Party::getAdjacentMemberSize(Creature* pLeader) const 
	throw()
{
	__BEGIN_TRY

	//cout << "Party::getAdjacentMemberSize() : BEGIN" << endl;

	Zone* pZone = pLeader->getZone();
	Assert(pZone != NULL);

	ZoneCoord_t cx = pLeader->getX();
	ZoneCoord_t cy = pLeader->getY();

	int rValue = 0;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map<string, Creature*>::const_iterator itr = m_MemberMap.begin();
	for (; itr != m_MemberMap.end(); itr++)
	{
		Creature* pCreature = itr->second;
		Assert(pCreature != NULL);

		// ��Ƽ�� ���ڿ��� �ڽŵ� ���ԵǱ� ������ 
		// ��� ������ �ٸ� �������� üũ���� �ʴ´�.
		Zone* pTZone = pCreature->getZone();

		// � �����Ͱ� ��ġ�Ѵٸ� ��� ��� �ִٴ� ��� �ǹ��Ѵ�.
		if (pTZone == pZone && pCreature->getDistance(cx, cy) <= 8) rValue++;
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	// �ڽŵ� ���ԵǹǷ� ��� 1���ٴ� Ŀ�� �Ѵ�.
	//Assert(rValue >= 1);
	if (rValue == 0) rValue = 1;

	//cout << "Party::getAdjacentMemberSize() : END" << endl;

	return rValue;

	__END_CATCH
}

int Party::getAdjacentMemberSize_LOCKED(Creature* pLeader) const 
	throw()
{
	__BEGIN_TRY

	//cout << "Party::getAdjacentMemberSize() : BEGIN" << endl;

	Zone* pZone = pLeader->getZone();
	Assert(pZone != NULL);

	ZoneCoord_t cx = pLeader->getX();
	ZoneCoord_t cy = pLeader->getY();

	int rValue = 0;

	//__ENTER_CRITICAL_SECTION(m_Mutex)

	map<string, Creature*>::const_iterator itr = m_MemberMap.begin();
	for (; itr != m_MemberMap.end(); itr++)
	{
		Creature* pCreature = itr->second;
		Assert(pCreature != NULL);

		// ��Ƽ�� ���ڿ��� �ڽŵ� ���ԵǱ� ������ 
		// ��� ������ �ٸ� �������� üũ���� �ʴ´�.
		Zone* pTZone = pCreature->getZone();

		// � �����Ͱ� ��ġ�Ѵٸ� ��� ��� �ִٴ� ��� �ǹ��Ѵ�.
		if (pTZone == pZone && pCreature->getDistance(cx, cy) <= 8) rValue++;
	}

	//__LEAVE_CRITICAL_SECTION(m_Mutex)

	// �ڽŵ� ���ԵǹǷ� ��� 1���ٴ� Ŀ�� �Ѵ�.
	Assert(rValue >= 1);

	//cout << "Party::getAdjacentMemberSize() : END" << endl;

	return rValue;

	__END_CATCH
}

// ���� �� ��Ƽ������ �ɷ�ġ ����ġ�� �ø���.
// ������ �ö��� ����ġ�� LeaderModifyInfo���� �����ְ�, 
// ������ �������� �ö��� ����ġ�� ��Ŷ� ���� ������ ������.
int Party::shareAttrExp(Creature* pLeader, int amount, int STRMultiplier, int DEXMultiplier, int INTMultiplier, ModifyInfo& LeaderModifyInfo) const 
	throw()
{
	__BEGIN_TRY

	Assert(pLeader != NULL);
	Assert(pLeader->isSlayer());

	ZoneCoord_t cx = pLeader->getX();
	ZoneCoord_t cy = pLeader->getY();

	list<Creature*> MemberList;
	int LevelSum = 0;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ��ó�� �ִ� (����ġ�� �÷���) ��Ƽ���� ����Ʈ�� ����´�.
	map<string, Creature*>::const_iterator mitr = m_MemberMap.begin();
	for (; mitr != m_MemberMap.end(); mitr++)
	{
		Creature* pCreature = mitr->second;
		Assert(pCreature != NULL);

		// ���� ��Ƽ �Ŵ����� ���ؼ��� �Ҹ��� �Լ��̱� ������, 
		// �� ��Ƽ�� ���� ���� ��Ƽ���� ����� �� �ִ�.
		// ���� ��Ƽ ���ο����� ��� ��� �ִ����� �˻��� �ʿ䰡 ���� ������
		// �Ÿ� �˻縸� �Ѵ�.
		// ���� �Ź� ���� ������ �̷��� �Ÿ� ����� �Ѵٴ� ��� �ణ�
		// ������ �ִٰ� �����ϴµ�, ��� ��� ����� ����ġ ���ʽ��� �޴�
		// ���� ���� �����? -- �輺��
		if (pCreature->getDistance(cx, cy) <= 8)
		{
			//Assert(pCreature->getZone() == pLeader->getZone());

			// ���򰡿���(�Ƹ� PCManager::killCreature�ΰ� �����)
			// Zone�� �ٲ���. -_-;
			// ã� �ð��� ��� �ϴ� �̷��� ����. by sigi. 2002.5.8
			if (pCreature->getZone()==pLeader->getZone())
			{
				MemberList.push_back(pCreature);

				// ��ó�� �ִ� ��Ƽ�� �˻��ϴ� �迡 ��Ƽ������ ���� �յ� ���صд�.
				if (pCreature->isSlayer())
				{
					Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);
					LevelSum += pSlayer->getSlayerLevel();
				}
				else if (pCreature->isVampire())
				{
					// �����̾� ��Ƽ�� �����̾ ��� �� �����?
					Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);
					LevelSum += pVampire->getLevel();
				}
			}
		}
	}

	// ����ġ�� ��Ƽ���� ���ڿ� ������Ų��.
	int nMemberSize = MemberList.size();

	//cout << "��Ƽ���� ���� : " << nMemberSize << endl;
	//cout << "���� ����ġ : " << amount << endl;

	if (nMemberSize == 1)
	{
		m_Mutex.unlock();

		Assert(pLeader->isSlayer());
		Slayer* pLeaderSlayer = dynamic_cast<Slayer*>(pLeader);

		// ��Ƽ���� �ϳ����� (��ó�� �ٸ� ��Ƽ���� ���ٸ�) �׳� ȥ�� �÷��ְ�, �����Ѵ�.
		divideAttrExp(pLeaderSlayer, amount, 
			STRMultiplier, DEXMultiplier, INTMultiplier, 
			LeaderModifyInfo, nMemberSize);	// ��Ƽ���� ����

		return 0;
	}

	switch (nMemberSize)
	{
		case 2: amount = getPercentValue(amount, 150); break;
		case 3: amount = getPercentValue(amount, 195); break;
		case 4: amount = getPercentValue(amount, 225); break;
		case 5: amount = getPercentValue(amount, 250); break;
		case 6: amount = getPercentValue(amount, 270); break;
		default: break;
	}

	//cout << "������ ����ġ : " << amount << endl;
	//cout << "��Ƽ���� ������ : " << LevelSum << endl;

	// ������ ��Ƽ������ ����ġ�� �÷��ش�.
	list<Creature*>::iterator itr = MemberList.begin();
	for (; itr != MemberList.end(); itr++)
	{
		Creature* pCreature = (*itr);
		Assert(pCreature != NULL);
		Assert(pCreature->isSlayer());

		Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);
		int myQuota = (int)((float)amount * (float)pSlayer->getSlayerLevel() / (float)LevelSum);

		//cout << "���� �� : " << myQuota << endl;

		if (pCreature->getName() != pLeader->getName())
		{
			//cout << "����[" << pCreature->getName() << "]�� �ƴ϶��� ��Ŷ� ����ϴ�." << endl;

			Item* pWeapon = pSlayer->getWearItem(Slayer::WEAR_RIGHTHAND);
			if (pWeapon != NULL)
			{
				Item::ItemClass IClass = pWeapon->getItemClass();
				int _STR = 0, _DEX = 0, _INT = 0;
				switch (IClass)
				{
					case Item::ITEM_CLASS_SWORD:
					case Item::ITEM_CLASS_BLADE:
						_STR = 8; _DEX = 1; _INT = 1; 
						break;
					case Item::ITEM_CLASS_SG:
					case Item::ITEM_CLASS_SMG:
					case Item::ITEM_CLASS_AR:
					case Item::ITEM_CLASS_SR:
						_STR = 1; _DEX = 8; _INT = 1; 
						break;
					case Item::ITEM_CLASS_MACE: 
					case Item::ITEM_CLASS_CROSS:
						_STR = 1; _DEX = 1; _INT = 8;
						break;
					default:
						Assert(false);
						break;
				}

				// ������ �ƴ϶���...
				GCModifyInformation gcModifyInformation;
				divideAttrExp(pSlayer, myQuota, _STR, _DEX, _INT, 
					gcModifyInformation, nMemberSize);

				pSlayer->getPlayer()->sendPacket(&gcModifyInformation);
			}
		}
		else
		{
			//cout << "����[" << pCreature->getName() << "]�̶��� ��Ŷ �غ��� �մϴ�." << endl;

			// �����̶��� �ϴ� ���߿� ������ ���, ���⸸ �Ѵ�.
			divideAttrExp(pSlayer, myQuota, 
				STRMultiplier, DEXMultiplier, INTMultiplier, 
				LeaderModifyInfo, nMemberSize);
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return 0;

	__END_CATCH
}

int Party::shareVampireExp(Creature* pLeader, int amount, ModifyInfo& LeaderModifyInfo) const 
	throw()
{
	__BEGIN_TRY

	Assert(pLeader != NULL);
	Assert(pLeader->isVampire());

	ZoneCoord_t cx = pLeader->getX();
	ZoneCoord_t cy = pLeader->getY();

	list<Creature*> MemberList;
	int LevelSum = 0;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ��ó�� �ִ� (����ġ�� �÷���) ��Ƽ���� ����Ʈ�� ����´�.
	map<string, Creature*>::const_iterator mitr = m_MemberMap.begin();
	for (; mitr != m_MemberMap.end(); mitr++)
	{
		Creature* pCreature = mitr->second;
		Assert(pCreature != NULL);

		// ���� ��Ƽ �Ŵ����� ���ؼ��� �Ҹ��� �Լ��̱� ������, 
		// �� ��Ƽ�� ���� ���� ��Ƽ���� ����� �� �ִ�.
		// ���� ��Ƽ ���ο����� ��� ��� �ִ����� �˻��� �ʿ䰡 ���� ������
		// �Ÿ� �˻縸� �Ѵ�.
		// ���� �Ź� ���� ������ �̷��� �Ÿ� ���� �Ѵٴ� ��� �ణ�
		// ������ �ִٰ� �����ϴµ�, ��� ��� ����� ����ġ ���ʽ��� �޴�
		// ���� ���� �����? -- �輺��
		// �������¿����� ��Ƽ����ġ �� �Դ´�. by Sequoia
		if (pCreature->getDistance(cx, cy) <= 8 && !pCreature->isFlag( Effect::EFFECT_CLASS_TRANSFORM_TO_BAT ) )
		{
			MemberList.push_back(pCreature);

			// ��ó�� �ִ� ��Ƽ�� �˻��ϴ� �迡 ��Ƽ������ ���� �յ� ���صд�.
			if (pCreature->isSlayer())
			{
				// �����̾� ��Ƽ�� �����̾ ��� �� �����?
				Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);
				LevelSum += pSlayer->getSlayerLevel();
			}
			else if (pCreature->isVampire())
			{
				Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);
				LevelSum += pVampire->getLevel();
			}
		}
	}

	// ����ġ�� ��Ƽ���� ���ڿ� ������Ų��.
	int nMemberSize = MemberList.size();

	//cout << "��Ƽ���� ���� : " << nMemberSize << endl;
	//cout << "���� ����ġ : " << amount << endl;

	if (nMemberSize == 1)
	{
		m_Mutex.unlock();

		Assert(pLeader->isVampire());
		Vampire* pLeaderVampire = dynamic_cast<Vampire*>(pLeader);

		// ��Ƽ���� �ϳ����� (��ó�� �ٸ� ��Ƽ���� ���ٸ�) �׳� ȥ�� �÷��ְ�, �����Ѵ�.
		increaseVampExp(pLeaderVampire, amount, LeaderModifyInfo);
		return 0;
	}

	switch (nMemberSize)
	{
		case 2: amount = getPercentValue(amount, 150); break;
		case 3: amount = getPercentValue(amount, 195); break;
		case 4: amount = getPercentValue(amount, 225); break;
		case 5: amount = getPercentValue(amount, 250); break;
		case 6: amount = getPercentValue(amount, 270); break;
		default: break;
	}

	//cout << "������ ����ġ : " << amount << endl;
	//cout << "��Ƽ������ ���� �� : " << LevelSum << endl;

	// ������ ��Ƽ������ ����ġ�� �÷��ش�.
	list<Creature*>::iterator itr = MemberList.begin();
	for (; itr != MemberList.end(); itr++)
	{
		Creature* pCreature = (*itr);
		Assert(pCreature != NULL);
		Assert(pCreature->isVampire());

		Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);
		int myQuota = (int)( (float)amount * (float)pVampire->getLevel() / (float)LevelSum );

		//cout << "���� �� : " << myQuota << endl;

		if (pCreature != pLeader)
		{
			//cout << "������ �ƴ϶��� ��Ŷ� ����ϴ�." << endl;

			// ������ �ƴ϶���...
			GCModifyInformation gcModifyInformation;
			increaseVampExp(pVampire, myQuota, gcModifyInformation);
			pVampire->getPlayer()->sendPacket(&gcModifyInformation);
		}
		else
		{
			//cout << "�����̶��� ��Ŷ� ������ �ʽ�ϴ�." << endl;

			// �����̶��� �ϴ� ���߿� ������ ���, ���⸸ �Ѵ�.
			increaseVampExp(pVampire, myQuota, LeaderModifyInfo);
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return 0;

	__END_CATCH
}

int Party::shareOustersExp(Creature* pLeader, int amount, ModifyInfo& LeaderModifyInfo) const 
	throw()
{
	__BEGIN_TRY

	Assert(pLeader != NULL);
	Assert(pLeader->isOusters());

	ZoneCoord_t cx = pLeader->getX();
	ZoneCoord_t cy = pLeader->getY();

	list<Creature*> MemberList;
	int LevelSum = 0;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ��ó�� �ִ� (����ġ�� �÷���) ��Ƽ���� ����Ʈ�� ����´�.
	map<string, Creature*>::const_iterator mitr = m_MemberMap.begin();
	for (; mitr != m_MemberMap.end(); mitr++)
	{
		Creature* pCreature = mitr->second;
		Assert(pCreature != NULL);

		// ���� ��Ƽ �Ŵ����� ���ؼ��� �Ҹ��� �Լ��̱� ������, 
		// �� ��Ƽ�� ���� ���� ��Ƽ���� ����� �� �ִ�.
		// ���� ��Ƽ ���ο����� ��� ��� �ִ����� �˻��� �ʿ䰡 ���� ������
		// �Ÿ� �˻縸� �Ѵ�.
		// ���� �Ź� ���� ������ �̷��� �Ÿ� ����� �Ѵٴ� ��� �ణ�
		// ������ �ִٰ� �����ϴµ�, ��� ��� ����� ����ġ ���ʽ��� �޴�
		// ���� ���� �����? -- �輺��
		if (pCreature->getDistance(cx, cy) <= 8)
		{
			MemberList.push_back(pCreature);

			// ��ó�� �ִ� ��Ƽ�� �˻��ϴ� �迡 ��Ƽ������ ���� �յ� ���صд�.
			if (pCreature->isOusters())
			{
				Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);
				LevelSum += pOusters->getLevel();
			}
		}
	}

	// ����ġ�� ��Ƽ���� ���ڿ� ������Ų��.
	int nMemberSize = MemberList.size();

	//cout << "��Ƽ���� ���� : " << nMemberSize << endl;
	//cout << "���� ����ġ : " << amount << endl;

	if (nMemberSize == 1)
	{
		m_Mutex.unlock();

		Assert(pLeader->isOusters());
		Ousters* pLeaderOusters = dynamic_cast<Ousters*>(pLeader);

		// ��Ƽ���� �ϳ����� (��ó�� �ٸ� ��Ƽ���� ���ٸ�) �׳� ȥ�� �÷��ְ�, �����Ѵ�.
		increaseOustersExp(pLeaderOusters, amount, LeaderModifyInfo);
		return 0;
	}

	switch (nMemberSize)
	{
		case 2: amount = getPercentValue(amount, 150); break;
		case 3: amount = getPercentValue(amount, 195); break;
		case 4: amount = getPercentValue(amount, 225); break;
		case 5: amount = getPercentValue(amount, 250); break;
		case 6: amount = getPercentValue(amount, 270); break;
		default: break;
	}

	// ������ ��Ƽ������ ����ġ�� �÷��ش�.
	list<Creature*>::iterator itr = MemberList.begin();
	for (; itr != MemberList.end(); itr++)
	{
		Creature* pCreature = (*itr);
		Assert(pCreature != NULL);
		Assert(pCreature->isOusters());

		Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);
		int myQuota = (int)( (float)amount * (float)pOusters->getLevel() / (float)LevelSum );

		if (pCreature != pLeader)
		{
			//cout << "������ �ƴ϶��� ��Ŷ� ����ϴ�." << endl;

			// ������ �ƴ϶���...
			GCModifyInformation gcModifyInformation;
			increaseOustersExp(pOusters, myQuota, gcModifyInformation);
			pOusters->getPlayer()->sendPacket(&gcModifyInformation);
		}
		else
		{
			//cout << "�����̶��� ��Ŷ� ������ �ʽ�ϴ�." << endl;

			// �����̶��� �ϴ� ���߿� ������ ���, ���⸸ �Ѵ�.
			increaseOustersExp(pOusters, myQuota, LeaderModifyInfo);
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return 0;

	__END_CATCH
}

void Party::shareRankExp(Creature* pLeader, int otherLevel) 
	throw()
{
	__BEGIN_TRY

	Assert(pLeader != NULL);
	Assert(pLeader->isPC());

	ZoneCoord_t cx = pLeader->getX();
	ZoneCoord_t cy = pLeader->getY();

	list<Creature*> MemberList;
	int LevelSum = 0;

	int LevelSum2 = 0;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ��ó�� �ִ� (����ġ�� �÷���) ��Ƽ���� ����Ʈ�� ����´�.
	map<string, Creature*>::const_iterator mitr = m_MemberMap.begin();
	for (; mitr != m_MemberMap.end(); mitr++)
	{
		Creature* pCreature = mitr->second;
		Assert(pCreature != NULL);

		// ���� ��Ƽ �Ŵ����� ���ؼ��� �Ҹ��� �Լ��̱� ������, 
		// �� ��Ƽ�� ���� ���� ��Ƽ���� ����� �� �ִ�.
		// ���� ��Ƽ ���ο����� ��� ��� �ִ����� �˻��� �ʿ䰡 ���� ������
		// �Ÿ� �˻縸� �Ѵ�.
		// ���� �Ź� ���� ������ �̷��� �Ÿ� ����� �Ѵٴ� ��� �ణ�
		// ������ �ִٰ� �����ϴµ�, ��� ��� ����� ����ġ ���ʽ��� �޴�
		// ���� ���� �����? -- �輺��
		if (pCreature->getDistance(cx, cy) <= 8)
		{
			MemberList.push_back(pCreature);

			// ��ó�� �ִ� ��Ƽ�� �˻��ϴ� �迡 ��Ƽ������ ���� �յ� ���صд�.
			if (pCreature->isSlayer())
			{
				Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);
				LevelSum += pSlayer->getSlayerLevel();

				LevelSum2 += pSlayer->getHighestSkillDomainLevel();
			}
			else if (pCreature->isVampire())
			{
				Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);
				LevelSum += pVampire->getLevel();

				LevelSum2 += pVampire->getLevel();
			}
			else if ( pCreature->isOusters() )
			{
				Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);
				LevelSum += pOusters->getLevel();

				LevelSum2 += pOusters->getLevel();
			}
		}
	}

	// ����ġ�� ��Ƽ���� ���ڿ� ������Ų��.
	int nMemberSize = MemberList.size();

	// ��Ƽ�� ���� ������ ���� ����ġ�� ���Ѵ�.
	int amount = (int) computeRankExp( LevelSum2 / nMemberSize, otherLevel );

	//cout << "��Ƽ���� ���� : " << nMemberSize << endl;
	//cout << "���� ����ġ : " << amount << endl;

	if (nMemberSize == 1)
	{
		m_Mutex.unlock();

		PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pLeader);

		// ��Ƽ���� �ϳ����� (��ó�� �ٸ� ��Ƽ���� ���ٸ�) �׳� ȥ�� �÷��ְ�, �����Ѵ�.
		pPC->increaseRankExp(amount);
		return;
	}

	switch (nMemberSize)
	{
		case 2: amount = getPercentValue(amount, 150); break;
		case 3: amount = getPercentValue(amount, 195); break;
		case 4: amount = getPercentValue(amount, 225); break;
		case 5: amount = getPercentValue(amount, 250); break;
		case 6: amount = getPercentValue(amount, 270); break;
		default: break;
	}

	//cout << "������ ����ġ : " << amount << endl;
	//cout << "��Ƽ������ ���� �� : " << LevelSum << endl;

	// ������ ��Ƽ������ ����ġ�� �÷��ش�.
	list<Creature*>::iterator itr = MemberList.begin();
	for (; itr != MemberList.end(); itr++)
	{
		Creature* pCreature = (*itr);
		Assert(pCreature != NULL);

		// ��ó�� �ִ� ��Ƽ�� �˻��ϴ� �迡 ��Ƽ������ ���� �յ� ���صд�.
		int level = 0;
		if (pCreature->isSlayer())
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);
			level = pSlayer->getSlayerLevel();

			int myQuota = amount * level / LevelSum;
			pSlayer->increaseRankExp(myQuota);
		}
		else if (pCreature->isVampire())
		{
			Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);
			level = pVampire->getLevel();

			int myQuota = amount * level / LevelSum;
			pVampire->increaseRankExp(myQuota);
		}
		else if ( pCreature->isOusters() )
		{
			Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);
			level = pOusters->getLevel();

			int myQuota = amount * level / LevelSum;
			pOusters->increaseRankExp(myQuota);
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return;

	__END_CATCH
}

void Party::shareRevealer(Creature* pCaster, int Duration) 
	throw (Error)
{
	__BEGIN_TRY

	Zone*       pZone = pCaster->getZone();
	ZoneCoord_t cx    = pCaster->getX();
	ZoneCoord_t cy    = pCaster->getY();

	list<Creature*> MemberList;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ��ó�� �ִ� ����Ʈ�� �ɾ��� ��Ƽ���� ����Ʈ�� ����´�.
	map<string, Creature*>::const_iterator mitr = m_MemberMap.begin();
	for (; mitr != m_MemberMap.end(); mitr++)
	{
		Creature* pCreature = mitr->second;
		Assert(pCreature != NULL);
		if (pCreature->getDistance(cx, cy) <= 8)
		{
			MemberList.push_back(pCreature);
		}
	}

	if (MemberList.size() == 1)
	{
		m_Mutex.unlock();
		return;
	}

	if ( !pCaster->isFlag( Effect::EFFECT_CLASS_REVEALER ) )
	{
		throw Error( "Revealer ����Ʈ�� �ɷ� ���� ���" );
	}

	// Caster �� Revelaer ��ų ����� ����´�
	Slayer* pSlayer = dynamic_cast<Slayer*>(pCaster);
	Assert( pSlayer != NULL );
	SkillSlot* pSkillSlot = pSlayer->getSkill( SKILL_REVEALER );
	Assert( pSkillSlot != NULL );
	ExpLevel_t ExpLevel = pSkillSlot->getExpLevel();

	list<Creature*>::iterator litr = MemberList.begin();
	for (; litr != MemberList.end(); litr++)
	{
		Creature* pCreature = (*litr);
		Assert(pCreature != NULL);
		Assert(pCreature->isSlayer());

		if (pCreature != pCaster)
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

			EffectRevealer* pEffectRevealer = new EffectRevealer(pSlayer);
			pEffectRevealer->setSkillLevel( ExpLevel );
			pEffectRevealer->setDeadline(Duration);
			EffectManager* pEffectManager = pSlayer->getEffectManager();
			pEffectManager->addEffect(pEffectRevealer);
			pSlayer->setFlag(Effect::EFFECT_CLASS_REVEALER);

			pZone->updateMineScan(pSlayer);
//			pZone->updateInvisibleScan( pSlayer );
			pZone->updateHiddenScan( pSlayer );

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(pSlayer->getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_REVEALER);
			gcAddEffect.setDuration(Duration);
			pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(), &gcAddEffect);
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

void Party::shareActivation(Creature* pCaster, int Duration) 
	throw (Error)
{
	__BEGIN_TRY

	Zone*       pZone = pCaster->getZone();
	ZoneCoord_t cx    = pCaster->getX();
	ZoneCoord_t cy    = pCaster->getY();

	list<Creature*> MemberList;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ��ó�� �ִ� ����Ʈ�� �ɾ��� ��Ƽ���� ����Ʈ�� ����´�.
	map<string, Creature*>::const_iterator mitr = m_MemberMap.begin();
	for (; mitr != m_MemberMap.end(); mitr++)
	{
		Creature* pCreature = mitr->second;
		Assert(pCreature != NULL);
		if (pCreature->getDistance(cx, cy) <= 8)
		{
			MemberList.push_back(pCreature);
		}
	}

	if (MemberList.size() == 1)
	{
		m_Mutex.unlock();
		return;
	}

	list<Creature*>::iterator litr = MemberList.begin();
	for (; litr != MemberList.end(); litr++)
	{
		Creature* pCreature = (*litr);
		Assert(pCreature != NULL);
		Assert(pCreature->isSlayer());

		if (pCreature != pCaster)
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

			EffectActivation* pEffectActivation = new EffectActivation(pSlayer);
			pEffectActivation->setDeadline(Duration);
			EffectManager* pEffectManager = pSlayer->getEffectManager();
			pEffectManager->addEffect(pEffectActivation);
			pSlayer->setFlag(Effect::EFFECT_CLASS_ACTIVATION);

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(pSlayer->getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_ACTIVATION);
			gcAddEffect.setDuration(Duration);
			pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(), &gcAddEffect);
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}


void Party::shareGnomesWhisper(Creature* pCaster, int Duration, int SkillLevel )
	throw (Error)
{
	__BEGIN_TRY

	Zone*       pZone = pCaster->getZone();
	ZoneCoord_t cx    = pCaster->getX();
	ZoneCoord_t cy    = pCaster->getY();

	list<Creature*> MemberList;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ��ó�� �ִ� ����Ʈ�� �ɾ��� ��Ƽ���� ����Ʈ�� ����´�.
	map<string, Creature*>::const_iterator mitr = m_MemberMap.begin();
	for (; mitr != m_MemberMap.end(); mitr++)
	{
		Creature* pCreature = mitr->second;
		Assert(pCreature != NULL);
		if (pCreature->getDistance(cx, cy) <= 8)
		{
			MemberList.push_back(pCreature);
		}
	}

	if (MemberList.size() == 1)
	{
		m_Mutex.unlock();
		return;
	}

	list<Creature*>::iterator litr = MemberList.begin();
	for (; litr != MemberList.end(); litr++)
	{
		Creature* pCreature = (*litr);
		Assert(pCreature != NULL);
		Assert(pCreature->isOusters());

		if (pCreature != pCaster)
		{
			Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);
            // ����Ʈ Ŭ������ ������ ���δ�.
			EffectGnomesWhisper* pEffect = new EffectGnomesWhisper(pOusters);
			pEffect->setDeadline( Duration );
			pEffect->setLevel( SkillLevel );
			pOusters->addEffect(pEffect);
			pOusters->setFlag(Effect::EFFECT_CLASS_GNOMES_WHISPER);

			pZone->updateDetectScan( pOusters );

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(pOusters->getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_GNOMES_WHISPER);
			gcAddEffect.setDuration(Duration);
			pZone->broadcastPacket(pOusters->getX(), pOusters->getY(), &gcAddEffect);
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

void Party::shareHolyArmor(Creature* pCaster, int DefBonus, int SkillLevel )
	throw (Error)
{
	__BEGIN_TRY

	Zone*       pZone = pCaster->getZone();
	ZoneCoord_t cx    = pCaster->getX();
	ZoneCoord_t cy    = pCaster->getY();

	list<Creature*> MemberList;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ��ó�� �ִ� ����Ʈ�� �ɾ��� ��Ƽ���� ����Ʈ�� ����´�.
	map<string, Creature*>::const_iterator mitr = m_MemberMap.begin();
	for (; mitr != m_MemberMap.end(); mitr++)
	{
		Creature* pCreature = mitr->second;
		Assert(pCreature != NULL);
		if (pCreature->getDistance(cx, cy) <= 8)
		{
			MemberList.push_back(pCreature);
		}
	}

	if (MemberList.size() == 1)
	{
		m_Mutex.unlock();
		return;
	}

	list<Creature*>::iterator litr = MemberList.begin();
	for (; litr != MemberList.end(); litr++)
	{
		Creature* pCreature = (*litr);
		Assert(pCreature != NULL);
		Assert(pCreature->isSlayer());

		if (pCreature != pCaster)
		{
			int Duration = (30 + SkillLevel/2) * 10;
			Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);
            // ����Ʈ Ŭ������ ������ ���δ�.
			EffectHolyArmor* pEffect = new EffectHolyArmor(pSlayer);
			pEffect->setDeadline( Duration );
			pEffect->setDefBonus( DefBonus );
			pSlayer->addEffect(pEffect);
			pSlayer->setFlag(Effect::EFFECT_CLASS_HOLY_ARMOR);

			SLAYER_RECORD prev;
			pSlayer->getSlayerRecord(prev);
			pSlayer->initAllStat();
			pSlayer->sendModifyInfo(prev);

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(pSlayer->getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_HOLY_ARMOR);
			gcAddEffect.setDuration(Duration);
			pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(), &gcAddEffect);
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}
	
bool Party::shareWaterElementalHeal(Creature* pCaster, int HealPoint)
	throw (Error)
{
	__BEGIN_TRY

	Zone*       pZone = pCaster->getZone();
	ZoneCoord_t cx    = pCaster->getX();
	ZoneCoord_t cy    = pCaster->getY();

	list<Creature*> MemberList;

	bool ret = false;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ��ó�� �ִ� ����Ʈ�� �ɾ��� ��Ƽ���� ����Ʈ�� ����´�.
	map<string, Creature*>::const_iterator mitr = m_MemberMap.begin();
	for (; mitr != m_MemberMap.end(); mitr++)
	{
		Creature* pCreature = mitr->second;
		Assert(pCreature != NULL);
		if (pCreature->getDistance(cx, cy) <= 13)
		{
			MemberList.push_back(pCreature);
		}
	}

	if (MemberList.size() == 1)
	{
		m_Mutex.unlock();
		return false;
	}

	list<Creature*>::iterator litr = MemberList.begin();
	for (; litr != MemberList.end(); litr++)
	{
		Creature* pCreature = (*litr);
		Assert(pCreature != NULL);
		Assert(pCreature->isOusters());

		Ousters* pTargetOusters = dynamic_cast<Ousters*>(pCreature);
		Assert(pTargetOusters != NULL );

		if (pTargetOusters != pCaster && pTargetOusters->getHP() < pTargetOusters->getHP( ATTR_MAX ) && pTargetOusters->getHP() > 0 )
		{
			ret = true;
			GCModifyInformation gcMI;
			HP_t final = min( (int)pTargetOusters->getHP(ATTR_MAX), pTargetOusters->getHP() + HealPoint );
			if ( final > pTargetOusters->getHP(ATTR_MAX) - pTargetOusters->getSilverDamage() )
			{
				pTargetOusters->setSilverDamage( pTargetOusters->getHP(ATTR_MAX) - final );
				gcMI.addShortData(MODIFY_SILVER_DAMAGE, pTargetOusters->getSilverDamage());
			}

			if ( pTargetOusters->getHP() != final )
			{
				pTargetOusters->setHP( final );
				gcMI.addShortData(MODIFY_CURRENT_HP, final);
			}

			GCStatusCurrentHP gcHP;
			gcHP.setObjectID( pTargetOusters->getObjectID() );
			gcHP.setCurrentHP( final );

			pZone->broadcastPacket(pTargetOusters->getX(), pTargetOusters->getY(), &gcHP);
			
			pTargetOusters->getPlayer()->sendPacket( &gcMI );

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(pTargetOusters->getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_WATER_ELEMENTAL_HEALED);
			gcAddEffect.setDuration(0);
			pZone->broadcastPacket(pTargetOusters->getX(), pTargetOusters->getY(), &gcAddEffect);
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)
	
	return ret;

	__END_CATCH
}


void Party::shareDetectHidden(Creature* pCaster, int Duration) 
	throw (Error)
{
	__BEGIN_TRY

	Zone*       pZone = pCaster->getZone();
	ZoneCoord_t cx    = pCaster->getX();
	ZoneCoord_t cy    = pCaster->getY();

	list<Creature*> MemberList;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ��ó�� �ִ� ����Ʈ�� �ɾ��� ��Ƽ���� ����Ʈ�� ����´�.
	map<string, Creature*>::const_iterator mitr = m_MemberMap.begin();
	for (; mitr != m_MemberMap.end(); mitr++)
	{
		Creature* pCreature = mitr->second;
		Assert(pCreature != NULL);
		if (pCreature->getDistance(cx, cy) <= 8)
		{
			MemberList.push_back(pCreature);
		}
	}

	if (MemberList.size() == 1)
	{
		m_Mutex.unlock();
		return;
	}

	list<Creature*>::iterator litr = MemberList.begin();
	for (; litr != MemberList.end(); litr++)
	{
		Creature* pCreature = (*litr);
		Assert(pCreature != NULL);
		Assert(pCreature->isSlayer());

		if (pCreature != pCaster)
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

			EffectDetectHidden* pEffectDetectHidden = new EffectDetectHidden(pSlayer);
			pEffectDetectHidden->setDeadline(Duration);
			EffectManager* pEffectManager = pSlayer->getEffectManager();
			pEffectManager->addEffect(pEffectDetectHidden);
			pSlayer->setFlag(Effect::EFFECT_CLASS_DETECT_HIDDEN);

			pZone->updateHiddenScan(pSlayer);

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(pSlayer->getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_DETECT_HIDDEN);
			gcAddEffect.setDuration(Duration);
			pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(), &gcAddEffect);
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

void Party::shareDetectInvisibility(Creature* pCaster, int Duration) 
	throw (Error)
{
	__BEGIN_TRY

	Zone*       pZone = pCaster->getZone();
	ZoneCoord_t cx    = pCaster->getX();
	ZoneCoord_t cy    = pCaster->getY();

	list<Creature*> MemberList;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ��ó�� �ִ� ����Ʈ�� �ɾ��� ��Ƽ���� ����Ʈ�� ����´�.
	map<string, Creature*>::const_iterator mitr = m_MemberMap.begin();
	for (; mitr != m_MemberMap.end(); mitr++)
	{
		Creature* pCreature = mitr->second;
		Assert(pCreature != NULL);
		if (pCreature->getDistance(cx, cy) <= 8)
		{
			MemberList.push_back(pCreature);
		}
	}

	if (MemberList.size() == 1)
	{
		m_Mutex.unlock();
		return;
	}

	list<Creature*>::iterator litr = MemberList.begin();
	for (; litr != MemberList.end(); litr++)
	{
		Creature* pCreature = (*litr);
		Assert(pCreature != NULL);
		Assert(pCreature->isSlayer());

		if (pCreature != pCaster)
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

			EffectDetectInvisibility* pEffectDetectInvisibility = new EffectDetectInvisibility(pSlayer);
			pEffectDetectInvisibility->setDeadline(Duration);
			EffectManager* pEffectManager = pSlayer->getEffectManager();
			pEffectManager->addEffect(pEffectDetectInvisibility);
			pSlayer->setFlag(Effect::EFFECT_CLASS_DETECT_INVISIBILITY);

			pZone->updateInvisibleScan(pSlayer);

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(pSlayer->getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_DETECT_INVISIBILITY);
			gcAddEffect.setDuration(Duration);
			pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(), &gcAddEffect);
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

void Party::shareExpansion(Creature* pCaster, int Duration, int Percent) 
	throw (Error)
{
	__BEGIN_TRY

	Zone*       pZone = pCaster->getZone();
	ZoneCoord_t cx    = pCaster->getX();
	ZoneCoord_t cy    = pCaster->getY();

	list<Creature*> MemberList;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ��ó�� �ִ� ����Ʈ�� �ɾ��� ��Ƽ���� ����Ʈ�� ����´�.
	map<string, Creature*>::const_iterator mitr = m_MemberMap.begin();
	for (; mitr != m_MemberMap.end(); mitr++)
	{
		Creature* pCreature = mitr->second;
		Assert(pCreature != NULL);
		if (pCreature->getDistance(cx, cy) <= 8)
		{
			MemberList.push_back(pCreature);
		}
	}

	if (MemberList.size() == 1)
	{
		m_Mutex.unlock();
		return;
	}

	list<Creature*>::iterator litr = MemberList.begin();
	for (; litr != MemberList.end(); litr++)
	{
		Creature* pCreature = (*litr);
		Assert(pCreature != NULL);
		Assert(pCreature->isSlayer());

		if (pCreature != pCaster && pCreature->isSlayer())
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

			// �̹� ��� ����Ʈ�� ����Ѵٸ� ������ ����Ʈ�� ������־��� �Ѵ�.
			if (pSlayer->isFlag(Effect::EFFECT_CLASS_EXPANSION))
			{
				pSlayer->deleteEffect(Effect::EFFECT_CLASS_EXPANSION);
			}

			EffectExpansion* pEffectExpansion = new EffectExpansion(pSlayer);
			pEffectExpansion->setDeadline(Duration);
			pEffectExpansion->setHPBonus(Percent);
			pSlayer->addEffect(pEffectExpansion);
			pSlayer->setFlag(Effect::EFFECT_CLASS_EXPANSION);

			// ����Ʈ�� �ٿ����, �ɷ�ġ�� �������Ѵ�.
			// �׸��� ���ο��� ��ȭ�� ����� �˷��ش�.
			SLAYER_RECORD prev;
			pSlayer->getSlayerRecord(prev);
			pSlayer->initAllStat();
			pSlayer->sendRealWearingInfo();
			pSlayer->sendModifyInfo(prev);

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(pSlayer->getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_EXPANSION);
			gcAddEffect.setDuration(Duration);
			pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(), &gcAddEffect);

			// �Ƹ��� �ִ� ü���� �����Ǿ�� �״�, HP ���� ���ε�ĳ�����Ѵ�.
			GCOtherModifyInfo gcOtherModifyInfo;
			makeGCOtherModifyInfo(&gcOtherModifyInfo, pSlayer, &prev);
			pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(), &gcOtherModifyInfo, pSlayer);
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

void Party::refreshFamilyPay()
{
	bool oldFamilyPay = m_bFamilyPay;
	m_bFamilyPay = false;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map<string, Creature*>::const_iterator mitr = m_MemberMap.begin();
	for (; mitr != m_MemberMap.end(); mitr++)
	{
		Creature* pCreature = mitr->second;
		Assert( pCreature->isPC() );
		GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pCreature->getPlayer());
		Assert( pGamePlayer != NULL );

		if ( pGamePlayer->isFamilyPayAvailable() )
		{
			m_bFamilyPay = true;
			break;
		}
	}

	// �йи� ����� ������ �ٲ��� ���� ��Ƽ���鿡�� ������Ų��.
	// �� �йи� ����� �����ڴ� ����Ѵ�.
	if ( oldFamilyPay != m_bFamilyPay )
	{
		mitr = m_MemberMap.begin();

		for (; mitr != m_MemberMap.end(); mitr++)
		{
			Creature* pCreature = mitr->second;
			Assert( pCreature->isPC() );
			GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pCreature->getPlayer());
			Assert( pGamePlayer != NULL );

			if ( !pGamePlayer->isFamilyPayAvailable() )
			{
				if ( m_bFamilyPay )
				{
					// �йи� ����� ����
					pGamePlayer->setFamilyPayPartyType( FAMILY_PAY_PARTY_TYPE_FREE_PASS );
				}
				else
				{
					// �йи� ����� ������ ������ �˷���Ѵ�.
					pGamePlayer->setFamilyPayPartyType( FAMILY_PAY_PARTY_TYPE_FREE_PASS_END );
				}
			}
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)
}

string Party::toString(void) const 
	throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "Party("
		<< "ID:" << m_ID
		<< ",CClass:" << m_CreatureClass
		<< ",Member(";

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map<string, Creature*>::const_iterator itr = m_MemberMap.begin();
	for (; itr != m_MemberMap.end(); itr++)
	{
		Creature* pCreature = itr->second;
		Assert(pCreature != NULL);
		msg << pCreature->getName() << ",";
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	msg << "))";


	return msg.toString();

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//
// class PartyManager member methods
//
//////////////////////////////////////////////////////////////////////////////

PartyManager::PartyManager()
	throw()
{
	__BEGIN_TRY

	m_Mutex.setName("PartyManager");

	__END_CATCH
}

PartyManager::~PartyManager()
	throw()
{
	__BEGIN_TRY
	__END_CATCH
}

bool PartyManager::createParty(int ID, Creature::CreatureClass CClass) 
	throw (DuplicatedException, Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ��ø�Ǵ� ��Ƽ�� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(ID);
	if (itr != m_PartyMap.end())
	{
		m_Mutex.unlock();
		return false;
	}

	Party* pParty = new Party(CClass);
	pParty->setID(ID);

	m_PartyMap[ID] = pParty;

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return true;

	__END_CATCH
}

Party* PartyManager::getParty(int ID) 	// by sigi. 2002.10.14
	throw (NoSuchElementException, Error)
{
	__BEGIN_TRY

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(ID);
	if (itr == m_PartyMap.end())
	{
		return NULL;
	}

	return itr->second;
	
	__END_CATCH
}


bool PartyManager::addPartyMember(int ID, Creature* pCreature) 
	throw (NoSuchElementException, DuplicatedException, Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(ID);
	if (itr == m_PartyMap.end())
	{
		// ���ٸ� ���⼭ �������ش�.
		Party* pNewParty = new Party(pCreature->getCreatureClass());
		pNewParty->setID(ID);

		m_PartyMap[ID] = pNewParty;

		// �ǹ̰� �ִ� üũ�ϱ�...-_-
		if (pNewParty->getSize() >= PARTY_MAX_SIZE)
		{
			m_Mutex.unlock();
			return false;
		}

		pNewParty->addMember(pCreature);
	}
	else
	{
		Party* pParty = itr->second;
		Assert(pParty != NULL);

		if (pParty->getSize() >= PARTY_MAX_SIZE)
		{
			m_Mutex.unlock();
			return false;
		}

		pParty->addMember(pCreature);
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return true;

	__END_CATCH
}

bool PartyManager::deletePartyMember(int ID, Creature* pCreature) 
	throw (NoSuchElementException, Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(ID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return false;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	pParty->deleteMember(pCreature->getName());

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return true;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//
// class LocalPartyManager member methods
//
//////////////////////////////////////////////////////////////////////////////

LocalPartyManager::LocalPartyManager()
	throw()
{
	__BEGIN_TRY

	m_Mutex.setName("LocalPartyManager");

	__END_CATCH
}

LocalPartyManager::~LocalPartyManager()
	throw()
{
	__BEGIN_TRY
	__END_CATCH
}

void LocalPartyManager::heartbeat(void)
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex);

	map<int, Party*>::iterator before  = m_PartyMap.end();
	map<int, Party*>::iterator current = m_PartyMap.begin(); 
	
	while (current != m_PartyMap.end()) 
	{
		Party* pParty = current->second;
		Assert(pParty != NULL);

		if (pParty->getSize() == 0)
		{
			//cout << "������Ƽ�� ����� 0�� �Ǿ, ��Ƽ ��ü[" << pParty->getID() << "]�� ����մϴ�." << endl;

			SAFE_DELETE(pParty);

			m_PartyMap.erase(current);

			if (before == m_PartyMap.end()) 	// first element
			{
				current = m_PartyMap.begin();
			}
			else // !first element
			{
				current = before;
				current ++;
			}
		}
		else
		{
			before = current ++;
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	__END_CATCH
}

int LocalPartyManager::getAdjacentMemberSize(int PartyID, Creature* pLeader) const 
	throw()
{
	__BEGIN_TRY

	int size = 0;

	__ENTER_CRITICAL_SECTION(m_Mutex);

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(PartyID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return 0;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	size = pParty->getAdjacentMemberSize(pLeader);

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	return size;

	__END_CATCH
}

int LocalPartyManager::shareAttrExp(int PartyID, Creature* pLeader, int amount, 
		int STRMultiplier, int DEXMultiplier, int INTMultiplier, 
		ModifyInfo& LeaderModifyInfo) const 
	throw()
{
	__BEGIN_TRY

	int rvalue = 0;

	__ENTER_CRITICAL_SECTION(m_Mutex);

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(PartyID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return 0;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	rvalue = pParty->shareAttrExp(pLeader, amount, STRMultiplier, DEXMultiplier, INTMultiplier, LeaderModifyInfo);

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	return rvalue;

	__END_CATCH
}

int LocalPartyManager::shareVampireExp(int PartyID, Creature* pLeader, int amount, ModifyInfo& LeaderModifyInfo) const 
	throw()
{
	__BEGIN_TRY

	int rvalue = 0;

	__ENTER_CRITICAL_SECTION(m_Mutex);

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(PartyID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return 0;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	rvalue = pParty->shareVampireExp(pLeader, amount, LeaderModifyInfo);

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	return rvalue;

	__END_CATCH
}

int LocalPartyManager::shareOustersExp(int PartyID, Creature* pLeader, int amount, ModifyInfo& LeaderModifyInfo) const 
	throw()
{
	__BEGIN_TRY

	int rvalue = 0;

	__ENTER_CRITICAL_SECTION(m_Mutex);

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(PartyID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return 0;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	rvalue = pParty->shareOustersExp(pLeader, amount, LeaderModifyInfo);

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	return rvalue;

	__END_CATCH
}

int LocalPartyManager::shareRankExp(int PartyID, Creature* pLeader, int amount) const 
	throw()
{
	__BEGIN_TRY

	//int rvalue = 0;

	__ENTER_CRITICAL_SECTION(m_Mutex);

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(PartyID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return 0;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	pParty->shareRankExp(pLeader, amount);

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	return 0;

	__END_CATCH
}

void LocalPartyManager::shareRevealer(int PartyID, Creature* pCaster, int Duration) 
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex);

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(PartyID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	pParty->shareRevealer(pCaster, Duration);

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	__END_CATCH
}

void LocalPartyManager::shareDetectHidden(int PartyID, Creature* pCaster, int Duration) 
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex);

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(PartyID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	pParty->shareDetectHidden(pCaster, Duration);

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	__END_CATCH
}

void LocalPartyManager::shareDetectInvisibility(int PartyID, Creature* pCaster, int Duration) 
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex);

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(PartyID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	pParty->shareDetectInvisibility(pCaster, Duration);

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	__END_CATCH
}

void LocalPartyManager::shareExpansion(int PartyID, Creature* pCaster, int Duration, int percent) 
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex);

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(PartyID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	pParty->shareExpansion(pCaster, Duration, percent);

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	__END_CATCH
}

void LocalPartyManager::shareActivation(int PartyID, Creature* pCaster, int Duration) 
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex);

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(PartyID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	pParty->shareActivation(pCaster, Duration);

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	__END_CATCH
}

void LocalPartyManager::shareGnomesWhisper(int PartyID, Creature* pCaster, int Duration, int SkillLevel)
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex);

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(PartyID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	pParty->shareGnomesWhisper(pCaster, Duration, SkillLevel);

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	__END_CATCH
}

void LocalPartyManager::shareHolyArmor(int PartyID, Creature* pCaster, int DefBonus, int SkillLevel)
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex);

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(PartyID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	pParty->shareHolyArmor(pCaster, DefBonus, SkillLevel);

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	__END_CATCH
}

bool LocalPartyManager::shareWaterElementalHeal(int PartyID, Creature* pCaster, int HealPoint)
	throw (Error)
{
	__BEGIN_TRY

	bool ret = false;

	__ENTER_CRITICAL_SECTION(m_Mutex);

	// �ش��ϴ� ��Ƽ�� �ִ��� ã�ƺ���.
	map<int, Party*>::const_iterator itr = m_PartyMap.find(PartyID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return false;
	}

	Party* pParty = itr->second;
	Assert(pParty != NULL);

	ret = pParty->shareWaterElementalHeal(pCaster, HealPoint);

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	return ret;

	__END_CATCH
}

string LocalPartyManager::toString(void) const
	throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "LocalPartyManager(";

	__ENTER_CRITICAL_SECTION(m_Mutex);

	map<int, Party*>::const_iterator itr = m_PartyMap.begin();
	for (; itr != m_PartyMap.end(); itr++)
	{
		Party* pParty = itr->second;
		Assert(pParty != NULL);
		msg << pParty->toString() << ",";
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex);

	msg << ")";
	return msg.toString();

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//
// class GlobalPartyManager member methods
//
//////////////////////////////////////////////////////////////////////////////

GlobalPartyManager::GlobalPartyManager()
	throw()
{
	__BEGIN_TRY

	m_PartyIDRegistry = 0;
	m_Mutex.setName("GlobalPartyManager");

	__END_CATCH
}

GlobalPartyManager::~GlobalPartyManager()
	throw()
{
	__BEGIN_TRY
	__END_CATCH
}

bool GlobalPartyManager::canAddMember(int ID) 
	throw (NoSuchElementException, Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map<int, Party*>::iterator itr = m_PartyMap.find(ID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();
		return false;
	}

	Party* pParty = itr->second;

	if (pParty->getSize() >= PARTY_MAX_SIZE)
	{
		m_Mutex.unlock();
		return false;
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return true;

	__END_CATCH
}

bool GlobalPartyManager::addPartyMember(int ID, Creature* pCreature) 
	throw (NoSuchElementException, DuplicatedException, Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	//cout << "GlobalPartyManager::addPartyMember() : BEGIN" << endl;

	// ���� �ش���Ƽ�� ã�Ƽ� ��Ƽ���� ���ڸ� Ȯ���Ѵ�.
	map<int, Party*>::iterator itr = m_PartyMap.find(ID);
	if (itr == m_PartyMap.end())
	{
		m_Mutex.unlock();

		//cerr << "GlobalPartyManager::addPartyMember() : NoSuchElementException" << endl;
		//throw NoSuchElementException("GlobalPartyManager::addPartyMember() : NoSuchElementException");

		// NoSuch���. by sigi. 2002.5.13
		return false;
	}

	Party* pParty = itr->second;

	if (pParty->getSize() >= PARTY_MAX_SIZE)
	{
		m_Mutex.unlock();

		//cout << "��Ƽ �ƽ� ����� �ʰ�" << endl;
		//cout << "GlobalPartyManager::addPartyMember() : END" << endl;
		return false;
	}

	// ��Ƽ��� �߰��Ѵ�.
	pParty->addMember(pCreature);
	pCreature->setPartyID(pParty->getID());

	// �ٸ� �����鿡�� ��Ƽ���� �߰��Ǿ��ٴ� ����� �˷��ش�.
	// ���ʿ� 2���� ��Ƽ�� ������ ����, 1��� ���� ����� �� ����������
	// �Ѹ� �̸����� ��� �ִ� ��Ƽ ����Ʈ�� ���ư��� �ȴ�.
	// �� ��� 2��° ������ ����� 2���� 2���� ��� �ִ� ����Ʈ�� 
	// ���ʷ� ���ư��� �ȴ�.
	// �׷��Ƿ� ��Ƽ���� 1���� ���� ������ �ʾƾ�, ��Ƽ ����Ʈ�� 2��
	// ���ư��� ��� ������ �� �ִ�.
	if (pParty->getSize() != 1)
	{
		GCPartyJoined gcPartyJoined;
		pParty->makeGCPartyJoined(&gcPartyJoined);
		pParty->broadcastPacket(&gcPartyJoined);

		map<string, Creature*> memberMap = pParty->getMemberMap();
		map<string, Creature*>::iterator itr = memberMap.begin();
		GCOtherGuildName gcOtherGuildName;

		for ( ; itr != memberMap.end() ; ++itr )
		{
			Creature* pTargetCreature = itr->second;
			if ( pTargetCreature != NULL && pTargetCreature->isPC() )
			{
				PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pTargetCreature);

				if ( pPC != NULL && pPC->getGuildID() != pPC->getCommonGuildID() )
				{
					gcOtherGuildName.setObjectID( pPC->getObjectID() );
					gcOtherGuildName.setGuildID( pPC->getGuildID() );
					gcOtherGuildName.setGuildName( pPC->getGuildName() );

					pParty->broadcastPacket( &gcOtherGuildName );
				}
			}
		}
	}

	// �йи� ����� ���� ó��
	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pCreature->getPlayer());
	if ( pGamePlayer != NULL )
	{
		if ( pParty->isFamilyPay() && !pGamePlayer->isFamilyPayAvailable() )
		{
			// �йи� ����� ���� ��Ƽ���� ���� ���Ա�� �ش�.
			pGamePlayer->setFamilyPayPartyType( FAMILY_PAY_PARTY_TYPE_FREE_PASS );
		}
		else if ( pGamePlayer->isFamilyPayAvailable() )
		{
			// �йи� ������ ��Ƽ���� �����ϰ� �� ���� ��Ƽ�� �йи� ����� ���� ��Ƽ�� ������.
			pParty->refreshFamilyPay();
		}
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	//cout << "GlobalPartyManager::addPartyMember() : END" << endl;

	return true;

	__END_CATCH
}

bool GlobalPartyManager::deletePartyMember(int ID, Creature* pCreature) 
	throw (NoSuchElementException, Error)
{
	__BEGIN_TRY

	//cout << "GlobalPartyManager::deletePartyMember() : BEGIN" << endl;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map<int, Party*>::iterator itr = m_PartyMap.find(ID);
	if (itr == m_PartyMap.end())
	{
		//m_Mutex.unlock();

		cerr << "GlobalPartyManager::deletePartyMember() : NoSuchElementException" << endl;
		//throw NoSuchElementException("GlobalPartyManager::deletePartyMember() : NoSuchElementException");

		// �ܺο��� NoSuchó���� ���ϴµ� -_-; by sigi. 2002.5.9
		m_Mutex.unlock();
		return false;
	}

	Party* pParty = itr->second;

	//cout << "��Ƽ�� ã�Ҵ�." << endl;
	//cout << pParty->toString() << endl;
	//cout << "��������ϴ� ���� �̸��:" << pCreature->getName() << endl;

	// �����鿡�� ��Ƽ���� ��Ƽ���� �߹��Ǿ��ٴ� ����� �˷��ش�.
	GCPartyLeave gcPartyLeave;
	gcPartyLeave.setExpellee(pCreature->getName());
	gcPartyLeave.setExpeller("");
	pParty->broadcastPacket(&gcPartyLeave);

	// ������ �����ڿ��Ե� GCPartyLeave�� ���ư����ϱ� ������,
	// ���� ��Ŷ� ���ε�ĳ������ �����, ����� ��Ƽ���� ������ش�.
	pParty->deleteMember(pCreature->getName());
	pCreature->setPartyID(0);

	// �йи� ����� ���� ó��
	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pCreature->getPlayer());
	if ( pGamePlayer != NULL )
	{
		if ( pGamePlayer->isFamilyPayAvailable() )
		{
			// �йи� ������� ��Ƽ���� �����ϰ� �� ���� �йи� ����� ����� ���� �����Ѵ�.
			pParty->refreshFamilyPay();
		}
		else if ( pParty->isFamilyPay() )
		{
			// �йи� ����� ���� ��Ƽ�� ���� �йи� ����� ������.
			pGamePlayer->setFamilyPayPartyType( FAMILY_PAY_PARTY_TYPE_FREE_PASS_END );
		}
	}

	// ��Ƽ�� ����� 1�� �Ǿ��ٸ� ����Ѵ�.
	if (pParty->getSize() == 1)
	{
		//cout << "�۷ι���Ƽ�� ����� 0�� �Ǿ, ��Ƽ ��ü[" << pParty->getID() << "]�� ����մϴ�." << endl;

		m_PartyMap.erase(itr);

		// ��� ��Ƽ������ ��Ƽ ID�� 0��� ������,
		// ������ ���� ��Ƽ �Ŵ������� ��Ƽ�� ����Ѵ�.
		pParty->destroyParty();

		// ��ü�� ������.
		SAFE_DELETE(pParty);
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	//cout << "GlobalPartyManager::deletePartyMember() : END" << endl;

	return true;

	__END_CATCH
}

bool GlobalPartyManager::expelPartyMember(int ID, Creature* pExpeller, const string& ExpelleeName) 
	throw (NoSuchElementException, Error)
{
	__BEGIN_TRY

	//cout << "GlobalPartyManager::expelPartyMember() : BEGIN" << endl;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ���� �ش���Ƽ�� ã�´�.
	map<int, Party*>::iterator itr = m_PartyMap.find(ID);
	if (itr == m_PartyMap.end())
	{
		cerr << "GlobalPartyManager::expelPartyMember() : NoSuchElementException" << endl;

		// �ܺο��� NoSuchó���� ���ϴµ� -_-; by sigi. 2002.5.9
		//throw NoSuchElementException("GlobalPartyManager::expelPartyMember() : NoSuchElementException");

		m_Mutex.unlock();
		return false;
	}

	Party* pParty = itr->second;

	// �߹��ϴ� ���� �� ��Ƽ�� �ִ��� �˻��ؾ� �Ѵ�.
	if (!pParty->hasMember(pExpeller->getName()))
	{
		m_Mutex.unlock();

		// �����ε�...?
		//cout << "�߹��ϴ� ���� ��Ƽ�� ������� ���" << endl;
		//cout << "GlobalPartyManager::expelPartyMember() : END" << endl;
		return false;
	}

	// �߹����� ���� ��Ƽ�� ����ϴ����� üũ�ؾ� �Ѵ�.
	if (!pParty->hasMember(ExpelleeName))
	{
		m_Mutex.unlock();

		// �����ε�...?
		//cout << "�߹����ϴ� ���� ��Ƽ�� ������� ���" << endl;
		//cout << "GlobalPartyManager::expelPartyMember() : END" << endl;
		return false;
	}

	// �����鿡�� ��Ƽ���� ��Ƽ���� �߹��Ǿ��ٴ� ����� �˷��ش�.
	GCPartyLeave gcPartyLeave;
	gcPartyLeave.setExpellee(ExpelleeName);
	gcPartyLeave.setExpeller(pExpeller->getName());
	pParty->broadcastPacket(&gcPartyLeave);

	//cout << "�����鿡�� ��Ƽ���� ��Ƽ���� �߹��Ǿ��ٴ� ����� �˷��ش�." << endl;

	// �߹����� ��� ��Ƽ���� ����Ѵ�.
	// * NOTE *
	// ��Ƽ���� ���� ������� �ʰ�, ��Ŷ� ���� ����� ����ϴ� �����
	// �߹����� �𿡰� ���� ��Ŷ�̳�, �ٸ� �����鿡�� �߹��Ǿ��ٰ� �˷��ִ�
	// ��Ŷ�̳� ��� ��Ŷ� ���� �����̴�. 
	Creature* pExpellee = pParty->getMember(ExpelleeName);
	pExpellee->setPartyID(0);
	pParty->deleteMember(ExpelleeName);

	// �йи� ����� ���� ó��
	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pExpellee->getPlayer());
	if ( pGamePlayer != NULL )
	{
		if ( pGamePlayer->isFamilyPayAvailable() )
		{
			// �йи� ������� ��Ƽ���� �����ϰ� �� ���� �йи� ����� ����� ���� �����Ѵ�.
			pParty->refreshFamilyPay();
		}
		else if ( pParty->isFamilyPay() )
		{
			// �йи� ����� ���� ��Ƽ�� ���� �йи� ����� ������.
			pGamePlayer->setFamilyPayPartyType( FAMILY_PAY_PARTY_TYPE_FREE_PASS_END );
		}
	}

	//cout << "��Ƽ���� [" << pExpellee->getName() << "]�� ����ߴ�." << endl;

	// ��Ƽ�� ����� 1�� �Ǿ��ٸ� ����Ѵ�.
	if (pParty->getSize() == 1)
	{
		//cout << "��Ƽ ����� 1�� �Ǿ ��Ƽ�� ����Ѵ�." << endl;

		m_PartyMap.erase(itr);

		//cout << "itr� ���" << endl;

		// ��� ��Ƽ������ ��Ƽ ID�� 0��� ������,
		// ������ ���� ��Ƽ �Ŵ������� ��Ƽ�� ����Ѵ�.
		pParty->destroyParty();

		//cout << "After Party::destroyParty()" << endl;

		// ��ü�� ������.
		SAFE_DELETE(pParty);

		//cout << "After object deletion" << endl;
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	//cout << "GlobalPartyManager::expelPartyMember() : END" << endl;

	return true;

	__END_CATCH
}

void GlobalPartyManager::refreshFamilyPay( int ID )
{
	__ENTER_CRITICAL_SECTION(m_Mutex)

	// ���� �ش���Ƽ�� ã�´�.
	map<int, Party*>::iterator itr = m_PartyMap.find(ID);
	if (itr == m_PartyMap.end())
	{
		cerr << "GlobalPartyManager::refreshFamilyPay() : NoSuchElementException" << endl;

		m_Mutex.unlock();
		return;
	}

	Party* pParty = itr->second;

	pParty->refreshFamilyPay();

	__LEAVE_CRITICAL_SECTION(m_Mutex)
}

int GlobalPartyManager::registerParty(void) 
	throw (Error)
{
	__BEGIN_TRY

	int PartyID = 0;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	PartyID = ++m_PartyIDRegistry;

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return PartyID;

	__END_CATCH
}

string GlobalPartyManager::toString(void) const
	throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "GlobalPartyManager(";

	__ENTER_CRITICAL_SECTION(m_Mutex)

	map<int, Party*>::const_iterator itr = m_PartyMap.begin();
	for (; itr != m_PartyMap.end(); itr++)
	{
		Party* pParty = itr->second;
		Assert(pParty != NULL);
		msg << pParty->toString() << ",";
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	msg << ")";
	return msg.toString();

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//
// ���Ǹ� ��� ���� �Լ���...
//
//////////////////////////////////////////////////////////////////////////////
void deleteAllPartyInfo(Creature* pCreature)
	throw()
{
	__BEGIN_TRY

	//cout << "DeleteAllPartyInfo BEGIN" << endl;

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	PartyInviteInfoManager* pPIIM = pZone->getPartyInviteInfoManager();
	Assert(pPIIM != NULL);

	// Ŭ������ ����� ����, �ش��ϴ� ��Ƽ ��û ����� ����ؾ� ��� ����,
	// ��Ƽ ��û ���뿡�Ե� �� ����� �˷����� �Ѵ�.
	PartyInviteInfo* pInviteInfo = pPIIM->getInviteInfo(pCreature->getName());
	if (pInviteInfo != NULL)
	{
		pPIIM->cancelInvite(pCreature);
	}

	int PartyID = pCreature->getPartyID();

	// ��Ƽ�� ������� ���쿡�� ��Ƽ���� �ڽ�� ����ϰ�, 
	// �ٸ� ��Ƽ���鿡�� �˷�� �Ѵ�.
	if (PartyID != 0)
	{
		// �۷ι� ��Ƽ���� ����ϰ�, ��Ƽ���鿡�� �˸���.
		g_pGlobalPartyManager->deletePartyMember(PartyID, pCreature);

		// ���� �����ִ� ��� ������Ƽ�Ŵ������� ����� ����Ѵ�.
		// Zone::deleteCreature() �Լ� ���ο��� Ư� ũ���İ� 
		// �� �� ���� ����, LocalPartyManager ���ο��� �� ũ���İ�
		// ���� ��Ƽ���� ũ���ĸ� �����ֹǷ�, ���⼭ ������ �ʿ䰡 ����.
		//
		// ���������� �Ȯ�ϰ� �� ���� �����, ���𿡼��� ���� ��Ƽ����
		// �����͸� Ȯ���� �������� �ʴ� ������ �߻��ϴ� �� �ϴ�.
		// �׷��� ���� �ּ�ó���ߴ� �κ��̾����, �ٽ� �ּ�ó���� ����Ѵ�.
		// -- 2002.01.08 �輺��
		Zone* pZone = pCreature->getZone();
		if (pZone != NULL)
		{
			// ���� ��Ƽ���� ����Ѵ�.
			LocalPartyManager* pLocalPartyManager = pZone->getLocalPartyManager();
			Assert(pLocalPartyManager != NULL);
			pLocalPartyManager->deletePartyMember(PartyID, pCreature);
		}

		// �۷ι� ��Ƽ ���ο��� ��Ƽ ID�� 0��� ��������,
		// Ȯ���ϰ� ���ִ� �ǹ̿��� �ٽ��ѹ� 0��� �������ش�.
		pCreature->setPartyID(0);
	}

	//cout << "DeleteAllPartyInfo END" << endl;

	__END_CATCH
}
