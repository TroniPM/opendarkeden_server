//////////////////////////////////////////////////////////////////////////////
// Filename    : DuplicateSelf.cpp
// Written by  : elca@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "DuplicateSelf.h"
#include "MonsterSummonInfo.h"
#include "ZoneUtil.h"
#include "MasterLairManager.h"
#include "MasterLairInfoManager.h"
#include "MonsterManager.h"
#include "Gpackets/GCSkillToTileOK5.h"
#include "Gpackets/GCFakeMove.h"
#include "Gpackets/GCSay.h"


//////////////////////////////////////////////////////////////////////////////
// ������
// ����ũ�� �ʱ�ȭ�Ѵ�.
//////////////////////////////////////////////////////////////////////////////
DuplicateSelf::DuplicateSelf()
	    throw()
{
	__BEGIN_TRY
	
	// ��.. �����Ϲ� ���̺��� ������.. -_-;
	m_DuplicateMonsterTypes[432] = 435;	 // ���丮 �н�
	m_DuplicateMonsterTypes[434] = 436;	 // ������ �н�

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// �����̾� ���� �ڵ鷯
//////////////////////////////////////////////////////////////////////////////
/*
void DuplicateSelf::execute(Vampire* pVampire, VampireSkillSlot* pSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	__BEGIN_TRY

	//cout << "TID[" << Thread::self() << "]" << getSkillHandlerName() << " Begin" << endl;

	Assert(pVampire != NULL);
	Assert(pSkillSlot != NULL);

	try 
	{
		Player* pPlayer = pVampire->getPlayer();
		Zone* pZone = pVampire->getZone();

		Assert(pPlayer != NULL);
		Assert(pZone != NULL);

		GCSkillToSelfOK1 _GCSkillToSelfOK1;
		GCSkillToSelfOK2 _GCSkillToSelfOK2;

		SkillType_t SkillType  = pSkillSlot->getSkillType();
		SkillInfo*  pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);

		ZoneCoord_t x = pVampire->getX();
		ZoneCoord_t y = pVampire->getY();

		int  RequiredMP     = decreaseConsumeMP(pVampire, pSkillInfo);
		bool bManaCheck     = hasEnoughMana(pVampire, RequiredMP);
		bool bTimeCheck     = verifyRunTime(pSkillSlot);
		bool bRangeCheck    = checkZoneLevelToUseSkill(pVampire);
		bool bHitRoll       = HitRoll::isSuccessMagic(pVampire, pSkillInfo, pSkillSlot);
		bool bTileCheck     = canBurrow(pZone, x, y);
		bool bMoveModeCheck = pVampire->isWalking();
		bool bEffected      = pVampire->isFlag(Effect::EFFECT_CLASS_HIDE);

		if (bManaCheck && bTimeCheck && bRangeCheck && bHitRoll && bTileCheck && bMoveModeCheck && !bEffected)
		{
			decreaseMana(pVampire, RequiredMP, _GCSkillToSelfOK1);
			
			// �����̾ �� ����� ����ϱ� ������ ���� ��Ŷ��� ������.
			_GCSkillToSelfOK1.setSkillType(SkillType);
			_GCSkillToSelfOK1.setCEffectID(CEffectID);
			_GCSkillToSelfOK1.setDuration(0);
		
			_GCSkillToSelfOK2.setXY(x, y);
			_GCSkillToSelfOK2.setSkillType(SkillType);
			_GCSkillToSelfOK2.setDuration(0);
		
			pPlayer->sendPacket(&_GCSkillToSelfOK1);
			pZone->broadcastPacket(x, y, &_GCSkillToSelfOK2, pVampire);

			// �� ��� �����ִ� �����̾� ����϶��� �˸���.
			GCDeleteObject gcDO;
			gcDO.setObjectID(pVampire->getObjectID());
			pZone->broadcastPacket(x, y, &gcDO, pVampire);

			// �� �ӿ��ٰ� �����̾ �߰��Ѵ�.
			addBurrowingCreature(pZone, pVampire, x, y);
			
			pSkillSlot->setRunTime();
		} 
		else 
		{
			executeSkillFailNormal(pVampire, getSkillType(), NULL);
		}
	} 
	catch(Throwable & t) 
	{
		executeSkillFailException(pVampire, getSkillType());
	}

	//cout << "TID[" << Thread::self() << "]" << getSkillHandlerName() << " End" << endl;

	__END_CATCH

}
*/

//////////////////////////////////////////////////////////////////////////////
// ������ ���� �ڵ鷯
//////////////////////////////////////////////////////////////////////////////
void DuplicateSelf::execute(Monster* pMonster)
	throw(Error)
{
	__BEGIN_TRY

	//cout << "TID[" << Thread::self() << "]" << getSkillHandlerName() << " Begin" << endl;

	//cout << "DuplicateSelf" << endl;
	MonsterType_t MType = pMonster->getMonsterType();

	map<MonsterType_t, MonsterType_t>::const_iterator itr = m_DuplicateMonsterTypes.find( MType );

	// �н��� MonsterType�� ����� �н� ������..
	if (itr==m_DuplicateMonsterTypes.end())
	{
		//cout <<"DuplicateSelf::noMonsterType: " << (int)MType << endl;
		return;
	}

	MonsterType_t DuplicateMType = itr->second;

	Assert(pMonster != NULL);

	try 
	{
		Zone* pZone = pMonster->getZone();
		Assert(pZone != NULL);

		if (pMonster->isFlag(Effect::EFFECT_CLASS_HIDE))
		{
			//cout << "DuplicateSelf: hide" << endl;
			return;
		}
		if (pMonster->isFlag(Effect::EFFECT_CLASS_INVISIBILITY))
		{
			addVisibleCreature(pZone, pMonster, true);
		}

		//GCSkillToSelfOK2 _GCSkillToSelfOK2;

		ZoneCoord_t x = pMonster->getX();
		ZoneCoord_t y = pMonster->getY();

		bool bRangeCheck    = checkZoneLevelToUseSkill(pMonster);
		//bool bMoveModeCheck = pMonster->isWalking();

		if (bRangeCheck)// && bMoveModeCheck)
		{
			//cout << "DuplicateSelf OK" << endl;
			GCSkillToTileOK5 _GCSkillToTileOK5;

			_GCSkillToTileOK5.setObjectID(pMonster->getObjectID());
			_GCSkillToTileOK5.setSkillType(getSkillType());
			_GCSkillToTileOK5.setX(x);
			_GCSkillToTileOK5.setY(y);
			_GCSkillToTileOK5.setDuration(  0);

			pZone->broadcastPacket(x, y,  &_GCSkillToTileOK5);

			//--------------------------------------------------------
			// ����� knockback�Ǵ¸´� �ֵ�� üũ���ش�.
			//--------------------------------------------------------
			//SkillInput input(pMonster);
			//SkillOutput output;
			//computeOutput(input, output);
			// �����͸� ��� �߰��Ѵ�.
			SUMMON_INFO		summonInfo;
			summonInfo.scanEnemy = true;
			summonInfo.hasItem = false;
			summonInfo.initHPPercent = pMonster->getHP(ATTR_CURRENT)*100/pMonster->getHP(ATTR_MAX);
			
			int numFake = min((1+rand()%3), pMonster->getINT()/100);

			//cout << "numDuplicate =  " << numFake<< endl;
			MonsterManager* pMonsterManager = pZone->getMonsterManager();
			Assert(pMonsterManager != NULL);

			list<Monster*> summonedMonsters;

			for (int i=0; i<numFake; i++)
			{
				int X = max(0, min((int)pZone->getWidth()-1, (x - 5 + rand()%11)));
				int Y = max(0, min((int)pZone->getHeight()-1, (y - 5 + rand()%11)));

				try
				{
					pMonsterManager->addMonsters(X, Y, DuplicateMType, 1, summonInfo, &summonedMonsters);
				}
				catch (Throwable& t)
				{
					cerr << t.toString() << endl;
				}
			}

			// �ܻ�� �����ش�.
			list<Monster*>::const_iterator iMonster = summonedMonsters.begin();

			for (; iMonster!=summonedMonsters.end(); iMonster++)
			{
				Monster* pFakeMonster = *iMonster;

				GCFakeMove gcFakeMove;
				gcFakeMove.setObjectID( pMonster->getObjectID() );
				gcFakeMove.setXY( pFakeMonster->getX(), pFakeMonster->getY() );
				
				pZone->broadcastPacket( x, y,  &gcFakeMove);
			}

			// ���� �����͵� ���򰡷� �̵��غ���.
			// 50�� �õ�..
			for (int i=0; i<50; i++)
			{
				int X = max(0, min((int)pZone->getWidth()-1, (x - 8 + rand()%11)));
				int Y = max(0, min((int)pZone->getHeight()-1, (y - 8 + rand()%11)));

				if (pZone->moveFastMonster(pMonster, x,y, X,Y, getSkillType()))
				{
					break;
				}
			}
		}
		else 
		{
			//cout << "RangeCheckFailed" << endl;
			executeSkillFailNormal(pMonster, getSkillType(), NULL);
		}
	} 
	catch(Throwable & t) 
	{
		executeSkillFailException(pMonster, getSkillType());
	}

	//cout << "TID[" << Thread::self() << "]" << getSkillHandlerName() << " End" << endl;

	__END_CATCH

}

DuplicateSelf g_DuplicateSelf;
