//////////////////////////////////////////////////////////////////////////////
// Filename    : MonsterAI.cpp
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "MonsterAI.h"
#include "Zone.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Monster.h"
#include "MonsterInfo.h"
#include "EffectManager.h"
#include "SkillInfo.h"
#include "skill/SkillHandlerManager.h"
#include "Directive.h"
#include "ZoneUtil.h"
#include "Tile.h"
#include "MonsterManager.h"
#include "MasterLairManager.h"
#include "VariableManager.h"
#include "Effect.h"

#include "Profile.h"

#define ABS(X) ((X)>=0)?X:-X

//#define __PROFILE_MONSTER__

#ifdef __PROFILE_MONSTER__
	#define __BEGIN_PROFILE_MONSTER(name)	beginProfileEx(name);
	#define __END_PROFILE_MONSTER(name)		endProfileEx(name);
#else
	#define __BEGIN_PROFILE_MONSTER(name)	((void)0);
	#define __END_PROFILE_MONSTER(name)		((void)0);
#endif

TPOINT getSafeTile(Zone* pZone, ZoneCoord_t x, ZoneCoord_t y)
{
	TPOINT ptAcid;
	ptAcid = findSuitablePositionForEffect( pZone, x, y, Effect::EFFECT_CLASS_ACID_SWAMP );

	/*
	TPOINT ptBloody;
	ptBloody = findSuitablePositionForEffect( pZone, x, y, Effect::EFFECT_CLASS_BLOODY_WALL );
	*/

	return ptAcid;
}

int getStrongValue(Creature* pCreature)
{
	HP_t currentHP = 0;
	HP_t maxHP = 0;
	int  strongValue = 0;

	if (pCreature->isSlayer())
	{
		Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

		currentHP = pSlayer->getHP(ATTR_CURRENT);
		maxHP = pSlayer->getHP(ATTR_MAX);

		strongValue = pSlayer->getSTR() + 
						pSlayer->getDEX() + 
						pSlayer->getINT() + 
						pSlayer->getProtection() + 
						pSlayer->getDefense();
	}
	else if (pCreature->isVampire())
	{
		Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);

		currentHP = pVampire->getHP(ATTR_CURRENT);
		maxHP = pVampire->getHP(ATTR_MAX);

		strongValue = pVampire->getSTR() + 
						pVampire->getDEX() + 
						pVampire->getINT() +
						pVampire->getProtection() + 
						pVampire->getDefense();
	}
	else if (pCreature->isOusters())
	{
		Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);

		currentHP = pOusters->getHP(ATTR_CURRENT);
		maxHP = pOusters->getHP(ATTR_MAX);

		strongValue = pOusters->getSTR() + 
						pOusters->getDEX() + 
						pOusters->getINT() +
						pOusters->getProtection() + 
						pOusters->getDefense();
	}
	else if (pCreature->isMonster())
	{
		Monster* pMonster = dynamic_cast<Monster*>(pCreature);

		currentHP = pMonster->getHP(ATTR_CURRENT);
		maxHP = pMonster->getHP(ATTR_MAX);

		strongValue = pMonster->getSTR() + 
						pMonster->getDEX() + 
						pMonster->getINT() +
						pMonster->getProtection() + 
						pMonster->getDefense();
	}
	else return 0;

	// pCreature HP�� 120�̻� 
	if (currentHP>=120)
	{
		strongValue += 200;
	}
	
	// HP percentage�� 60% �̻��̶��� 
	if (currentHP*100 >= maxHP*60)
	{
		strongValue += 200;
	}

	return strongValue;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
TPOINT randPos(int ox, int oy, int threshold, Zone* pZone) 
	throw()
{
	int tx = ox + (rand()%(threshold*2)) - threshold;
	int ty = oy + (rand()%(threshold*2)) - threshold;

	if (tx < 0) tx = 0;
	else if (tx >= pZone->getWidth()) tx = pZone->getWidth() - 1;

	if (ty < 0) ty = 0;
	else if (ty >= pZone->getHeight()) ty = pZone->getHeight() - 1;

	TPOINT pt;
	pt.x = tx;
	pt.y = ty;

	return pt;
}


//////////////////////////////////////////////////////////////////////////////
// ������/�Ҹ���
//////////////////////////////////////////////////////////////////////////////

MonsterAI::MonsterAI(Monster* pMonster, uint type)
	throw()
{
	__BEGIN_TRY

	Assert(pMonster != NULL);	// by sigi

	m_pBody         = pMonster;
	m_AIType        = type;
	m_Panic         = 5;
	m_PanicMax      = 5;
	m_Courage       = 20;
	m_CourageMax    = 20;
	m_bDamaged      = false;
	m_LastAction    = LAST_ACTION_NONE;

	m_MoveRule 		= MOVE_RULE_NORMAL;
	m_BlockedDir	= DIR_NONE;
	m_WallCount		= 0;

	m_pDirectiveSet = g_pDirectiveSetManager->getDirectiveSet(type);

	m_pCondChecker[DIRECTIVE_COND_ENEMY_RANGE_MELEE]           = checkEnemyRangeMelee;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_RANGE_MISSILE]         = checkEnemyRangeMissile;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_RANGE_CLOSE]           = checkEnemyRangeClose;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_RANGE_OUT_OF_SIGHT]    = checkEnemyRangeOutOfSight;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_DYING]                 = checkEnemyDying;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_NOT_BLOOD_DRAINED]     = checkEnemyNotBloodDrained;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_NOT_GREEN_POISONED]    = checkEnemyNotGreenPoisoned;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_NOT_YELLOW_POISONED]   = checkEnemyNotYellowPoisoned;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_NOT_DARKBLUE_POISONED] = checkEnemyNotDarkbluePoisoned;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_NOT_GREEN_STALKERED]   = checkEnemyNotGreenStalkered;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_NOT_PARALYZED]         = checkEnemyNotParalyzed;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_NOT_DOOMED]            = checkEnemyNotDoomed;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_NOT_BLINDED]           = checkEnemyNotBlinded;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_NOT_IN_DARKNESS]       = checkEnemyNotInDarkness;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_NOT_SEDUCTION]      = checkEnemyNotSeduction;
	m_pCondChecker[DIRECTIVE_COND_IM_OK]                       = checkImOK;
	m_pCondChecker[DIRECTIVE_COND_IM_DYING]                    = checkImDying;
	m_pCondChecker[DIRECTIVE_COND_IM_DAMAGED]                  = checkImDamaged;
	m_pCondChecker[DIRECTIVE_COND_IM_HIDING]                   = checkImHiding;
	m_pCondChecker[DIRECTIVE_COND_IM_WOLF]                     = checkImWolf;
	m_pCondChecker[DIRECTIVE_COND_IM_BAT]                      = checkImBat;
	m_pCondChecker[DIRECTIVE_COND_IM_INVISIBLE]                = checkImInvisible;
	m_pCondChecker[DIRECTIVE_COND_IM_WALKING_WALL]             = checkImWalkingWall;
	m_pCondChecker[DIRECTIVE_COND_TIMING_BLOOD_DRAIN]          = checkTimingBloodDrain;
	m_pCondChecker[DIRECTIVE_COND_MASTER_SUMMON_TIMING]        = checkMasterSummonTiming;
	m_pCondChecker[DIRECTIVE_COND_MASTER_NOT_READY]            = checkMasterNotReady;
	m_pCondChecker[DIRECTIVE_COND_IM_IN_BAD_POSITION]          = checkImInBadPosition;
	m_pCondChecker[DIRECTIVE_COND_FIND_WEAK_ENEMY]             = checkFindWeakEnemy;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_NOT_DEATH]            = checkEnemyNotDeath;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_NOT_HALLUCINATION]    = checkEnemyNotHallucination;
	m_pCondChecker[DIRECTIVE_COND_TIMING_MASTER_BLOOD_DRAIN]  = checkTimingMasterBloodDrain;
	m_pCondChecker[DIRECTIVE_COND_TIMING_DUPLICATE_SELF]  	   = checkTimingDuplicateSelf;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_RANGE_IN_MISSILE]         = checkEnemyRangeInMissile;
	m_pCondChecker[DIRECTIVE_COND_POSSIBLE_SUMMON_MONSTERS]   = checkPossibleSummonMonsters;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_TILE_NOT_ACID_SWAMP]	= checkEnemyTileNotAcidSwamp;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_ON_AIR]					= checkEnemyOnAir;
	m_pCondChecker[DIRECTIVE_COND_ENEMY_ON_SAFE_ZONE]			= checkEnemyOnSafeZone;

	__END_CATCH
}

MonsterAI::~MonsterAI()
	throw()
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void MonsterAI::addDirective(Directive* pDirective)
	throw()
{
	__BEGIN_TRY

	m_pDirectiveSet->addDirective(pDirective);

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// ��� �Լ�
//////////////////////////////////////////////////////////////////////////////

bool MonsterAI::checkCondition(int condition, Creature* pEnemy)
	throw()
{
	__BEGIN_TRY

	Assert(0 <= condition && condition < DIRECTIVE_COND_MAX);
//	cout << m_pBody->toString() << " check condition " << condition << " to" << pEnemy->toString() << endl;
	return m_pCondChecker[condition](m_pBody, pEnemy);

	__END_CATCH
}

bool MonsterAI::checkDirective(Directive* pDirective, Creature* pEnemy)
	throw()
{
	__BEGIN_TRY

	if (pDirective == NULL) return false;

	// ����� ����Ʈ�� �����...
	list<int>& conditionList = pDirective->getConditions();
	bool       rValue        = true;

	// ��� �߿� �ϳ����� ������� �ʴ� ���� �ִٸ�,
	// false�� �����Ѵ�.
	list<int>::iterator itr = conditionList.begin();
	for (; itr != conditionList.end(); itr++)
	{
		if (checkCondition(*itr, pEnemy) == false)
		{
			rValue = false;
			break;
		}
	}

	return rValue;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// ������ ������
//////////////////////////////////////////////////////////////////////////////

bool MonsterAI::moveNormal(ZoneCoord_t ex, ZoneCoord_t ey, ZoneCoord_t& nx, ZoneCoord_t& ny, Dir_t& ndir)
	throw()
{
	//Zone*       pZone   = m_pBody->getZone();
	Dir_t       bestDir = DIR_NONE;

	Dir_t curDir = m_pBody->getDir();

	////////////////////////////////////////////////////////////
	// ���������� ���ϴ� �ּ��� ����� ã�´�.
	////////////////////////////////////////////////////////////
	if (m_pBody->getX() < ex) 
	{
		if (m_pBody->getY() < ey)      bestDir = RIGHTDOWN;
		else if (m_pBody->getY() > ey) bestDir = RIGHTUP;
		else                           bestDir = RIGHT;// m_pBody->getY() == ey
	} 
	else if (m_pBody->getX() > ex) 
	{
		if (m_pBody->getY() < ey)      bestDir = LEFTDOWN;
		else if (m_pBody->getY() > ey) bestDir = LEFTUP;
		else                           bestDir = LEFT;// m_pBody->getY() == ey
	} 
	else 
	{	
		if (m_pBody->getY() < ey)      bestDir = DOWN; // m_pBody->getX() == ex
		else if (m_pBody->getY() > ey) bestDir = UP;
		else                           bestDir = DIR_NONE; // m_pBody->getY() == ey
	}

	////////////////////////////////////////////////////////////
	// search surrounding tiles
	////////////////////////////////////////////////////////////

	int diffLevel = 0;

	// ������ ���� ������ ���̸� ��Ÿ����. diffLevel == 1 ����, diff == 0 �̱� ��ؼ�
	// 0 ��� �ʱ�ȭ�ؾ� �Ѵ�. �׷��� �����, garbage ����� ���� ����� ���� �ȴ�.
	int diff = 0;

	// ��� ������ �߰ߵǾ��°�?
	bool found = false;

	// �켱 bestDir ���� üũ�غ���. unsigned type �� �Ǿ�� �ȵȴ�.
	ndir = bestDir;

	// ��� ��ǥ
	nx = m_pBody->getX() + dirMoveMask[ndir].x;
	ny = m_pBody->getY() + dirMoveMask[ndir].y;

	bool bBlocked[DIR_MAX] = { false, };

	const Dir_t DIR_MAX_1 = DIR_MAX - 1;

	// bestDir ������ ���� �ִٸ�, previous Dir ����� ������� +- �ϸ鼭 üũ�Ѵ�.
	// �̶� ��� ���踦 �Ѿ���� üũ�� �ؾ� �Ѵ�.
	bool bCanMove = m_pBody->canMove(nx,ny);

	// �������� ���쿡�� �ٴڿ� �� ����� ������ �Ѵ�. - -; by sigi. 2002.9.12
	/*
	if (bCanMove && m_pBody->isMaster())
	{
		Tile& tile = m_pBody->getZone()->getTile(nx, ny);
		if (tile.hasEffect())
		{
			if (tile.getEffect(Effect::EFFECT_CLASS_ACID_SWAMP)!=NULL
				&& tile.getEffect(Effect::EFFECT_CLASS_GROUND_ATTACK)!=NULL)
			{
			}
			else bCanMove = false;
		}
	}
	*/

	if (!bCanMove)
	{
		bBlocked[ndir] = true;

		// best direction�� ���̶��� ������� ��Ÿ�⸦ �Ѵ�.
		// ���㳪 hide���� �ƴϾ��� �Ѵ�.
		if (!m_pBody->isBlockedByCreature(nx,ny)
			&& !m_pBody->isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_BAT)
			&& !m_pBody->isFlag(Effect::EFFECT_CLASS_HIDE))
		{
			setMoveRule( MOVE_RULE_RIGHTWALL ); // ���ⲫ �� �ǹ̾���.
			m_BlockedDir = bestDir;

			// �̹� �Ͽ��� �׳� �� ����� ����ϸ� �ȴ�.
		}

		while (true) 
		{
			// ������ ����, diffLevel == 1 �� �ȴ�. �̴� m_pBody->getDir() ����� üũ�϶��� ���̴�.
			diffLevel ++;

			// ������ ����� ã�Ұų�, ���̻� ã� �� ���ٸ� ������.
			if (found || diffLevel > 8) break;

			////////////////////////////////////////////////////////////
			// diffLevel � 2 �� ���� ���� ���ٴ� ���, ���� ��Ī�Ǵ�
			// �����̶��� ���̴�.  �� �� ¦���� ������ ���ʷ� diff �� 
			// �����ؼ� ���� ����� üũ�ϸ�, Ȧ���� ������ ���� �������
			// �ݴ��� ������ üũ�Ǿ��ٴ� ���̹Ƿ�, ������ diff ��
			// ����� �����ؼ� �ٸ��� ����� üũ�ϸ� �ǰڴ�.
			////////////////////////////////////////////////////////////
			if ((diffLevel & 0x00000001) == 0) 	// % 2 �ε�.. �ٲ���.. ���� by sigi 
			{
				//diff = (int)(diffLevel >> 1) * (bSelectLeft ? 1 : -1);
				diff = diffLevel >> 1;

				Dir_t dir1 = (m_pBody->getDir() + diff) & DIR_MAX_1;
				Dir_t dir2 = (m_pBody->getDir() + DIR_MAX - diff) & DIR_MAX_1;

				// bestDir�� ������ ��� ���� �����غ���.
				if ((abs(ndir+DIR_MAX-dir1) & DIR_MAX_1) 
						< (abs(ndir+DIR_MAX-dir2) & DIR_MAX_1))
				{
					ndir = dir1;
				}
				else
				{
					diff = -diff;
					ndir = dir2;
				}
			} 
			else ndir = m_pBody->getDir() + DIR_MAX - diff;

			////////////////////////////////////////////////////////////
			// ndir �� overflow, underflow �� ���� ��� ��������� �Ѵ�.
			// overflow  : -1 -> 7 , -2 -> 6 , -3 -> 5 , ...
			// underflow :  8 -> 0 ,  9 -> 1 , 10 -> 2 , ...
			////////////////////////////////////////////////////////////
			//if (ndir >= DIR_MAX) // overflow
			//{	
			//	ndir = Directions(DIR_MAX - ndir);
			//} 
			//else if (ndir < 0) // underflow
			//{	
			//	ndir = Directions(DIR_MAX + ndir);
			//}
			ndir &= DIR_MAX_1;

			// ��� ��ǥ�� ���Ѵ�.
			nx = m_pBody->getX() + dirMoveMask[ndir].x;
			ny = m_pBody->getY() + dirMoveMask[ndir].y;

			// ��� ������ �������, ����� ������� �� �ִ�.
			// �̶� ��� ���踦 �Ѿ���� üũ�� �ؾ� �Ѵ�.
			if (m_pBody->canMove(nx,ny))
			{
				// �������� ���쿡�� �ٴڿ� �� ����� ������ �Ѵ�. - -; by sigi. 2002.9.12
				/*
				if (m_pBody->isMaster())
				{
					Tile& tile = m_pBody->getZone()->getTile(nx, ny);
					if (tile.hasEffect())
					{
						if (tile.getEffect(Effect::EFFECT_CLASS_ACID_SWAMP)!=NULL
							&& tile.getEffect(Effect::EFFECT_CLASS_GROUND_ATTACK)!=NULL)
						{
							found = true;
						}
					}
				}
				else
				*/
				{
					found = true;
				}
			}

			bBlocked[ndir] = true;
		}//while
	} 
	else found = true;

	// �¼�/������ Ȯ���� ������ش�.
	if (found 
		&& m_MoveRule!=MOVE_RULE_NORMAL)
	{
		bool leftWall = bBlocked[(ndir+2) & DIR_MAX_1];
		bool rightWall = bBlocked[(ndir+DIR_MAX-2) & DIR_MAX_1];

		// �� �� ������� ���⿡ ������.. ���ٻ���
		if (leftWall && rightWall)
		{
			if (ndir>curDir && ndir<curDir+4
				|| curDir>4 && (ndir>curDir || ndir<curDir-4))
			{
				setMoveRule( MOVE_RULE_RIGHTWALL );
				//cout << "set RightWall : " << (int)curDir << " to " << (int)ndir << " - " << (int)m_BlockedDir << " - " << m_pBody->getName() << endl;
			}
			else
			{
				setMoveRule( MOVE_RULE_LEFTWALL );
				//cout << "set LeftWall : " << (int)curDir << " to " << (int)ndir << " - " << (int)m_BlockedDir << " - " << m_pBody->getName() << endl;
			}
		}
		// �¼��� ����
		else if (leftWall)
		{
			setMoveRule( MOVE_RULE_LEFTWALL );
			//cout << "set LeftWall : " << (int)curDir << " to " << (int)ndir << " - " << (int)m_BlockedDir << " - " << m_pBody->getName() << endl;
		}
		// ����� ����
		else if (rightWall)
		{
			setMoveRule( MOVE_RULE_RIGHTWALL );
			//cout << "set RightWall : " << (int)curDir << " to " << (int)ndir << " - " << (int)m_BlockedDir << " - " << m_pBody->getName() << endl;
		}
		// ���� ���ٸ� ��Ÿ�� ���Ѵ�.
		else
		{
			setMoveRule( MOVE_RULE_NORMAL );
		}
	}
	else
	{
		setMoveRule( MOVE_RULE_NORMAL );
	}

	return found;
}

//////////////////////////////////////////////////////////////////////////////
// ��Ÿ�� �̵��ϱ�
//////////////////////////////////////////////////////////////////////////////

bool MonsterAI::moveWall(ZoneCoord_t ex, ZoneCoord_t ey, ZoneCoord_t& nx, ZoneCoord_t& ny, Dir_t& ndir, bool bLeft)
	throw()
{
	//Zone*       pZone   = m_pBody->getZone();
	//cout << "MoveWall[" << (bLeft? "Left" : "Right") << "] : " << m_pBody->getName() << endl;

	////////////////////////////////////////////////////////////
	// search surrounding tiles
	////////////////////////////////////////////////////////////
	// �켱 ��ǥ ������� ������� �Ѵ�.
	ndir = m_BlockedDir;

	// ��� ��ǥ
	nx = m_pBody->getX() + dirMoveMask[ndir].x;
	ny = m_pBody->getY() + dirMoveMask[ndir].y;

	m_WallCount++;

	// ��ǥ�� ������� �� �� �ִ� ����
	bool bCanMove = m_pBody->canMove(nx,ny); 

	// �������� ���쿡�� �ٴڿ� �� ����� ������ �Ѵ�. - -; by sigi. 2002.9.12
	/*
	if (bCanMove && m_pBody->isMaster())
	{
		Tile& tile = m_pBody->getZone()->getTile(nx, ny);
		if (tile.hasEffect())
		{
			if (tile.getEffect(Effect::EFFECT_CLASS_ACID_SWAMP)!=NULL
				&& tile.getEffect(Effect::EFFECT_CLASS_GROUND_ATTACK)!=NULL)
			{
			}
			else bCanMove = false;
		}
	}
	*/

	if (bCanMove)
	{
		/*
		Dir_t bestDir;

		////////////////////////////////////////////////////////////
		// (nx, ny)���� ���������� ���ϴ� �ּ��� ����� ã�´�.
		////////////////////////////////////////////////////////////
		if (nx < ex) 
		{
			if (ny < ey)      bestDir = RIGHTDOWN;
			else if (ny > ey) bestDir = RIGHTUP;
			else              bestDir = RIGHT;// m_pBody->getY() == ey
		} 
		else if (nx > ex) 
		{
			if (ny < ey)      bestDir = LEFTDOWN;
			else if (ny > ey) bestDir = LEFTUP;
			else              bestDir = LEFT;// m_pBody->getY() == ey
		} 
		else 
		{	
			if (ny < ey)      bestDir = DOWN; // m_pBody->getX() == ex
			else if (ny > ey) bestDir = UP;
			else              bestDir = DIR_NONE; // m_pBody->getY() == ey
		}

		ZoneCoord_t bx = nx + dirMoveMask[bestDir].x;
		ZoneCoord_t by = ny + dirMoveMask[bestDir].y;
		*/

		// �� ĭ �̵��������
		// best������ block�� �Ǿ����� ��� ���쿡�� ��Ÿ�⸦ �׸��д�.
		//if (m_pBody->canMove(bx,by)) 
		{
			// ��Ÿ�⸦ �׸��д�.
			//cout << "FindBest : " << (int)m_BlockedDir << " - " << m_pBody->getName() << endl;
			setMoveRule( MOVE_RULE_NORMAL );
		}

		return true;
	}


	const Dir_t DIR_MAX_1 = DIR_MAX-1;

	Dir_t dirInc, dirWallInc;

	if (bLeft)	
	{
		// �¼���
		dirInc = 7;		//	+DIR_MAX-1;
		dirWallInc = 2;	// ���� �־����ϴ� ����
	}
	else		
	{
		// ������
		dirInc = 1;
		dirWallInc = 6;	// +DIR_MAX-3 ���� �־����ϴ� ����
	}

	// ���� �־����ϴ� �������� üũ
	ndir = (m_pBody->getDir() + dirWallInc) & DIR_MAX_1;
	
	//----------------------------------------------------------
	// ����� ������� �� �� ����� ���� �ȴ�.
	// 
	// �� �� ���� ����� �ʿ� ���� block�� �ƴ� �����̸� 
	//        ��Ÿ�⸦ �׸��д�.
	//----------------------------------------------------------
	for (int i=0; i<DIR_MAX; i++)
	{
		// ��� ��ǥ
		nx = m_pBody->getX() + dirMoveMask[ndir].x;
		ny = m_pBody->getY() + dirMoveMask[ndir].y;

		if (m_pBody->canMove(nx,ny))
		{
			// ����� ���������� �ȴ�.
			// ���� �־��� �Ǵ� �ġ
			//Dir_t 		dirWall = (ndir + dirWallInc) & DIR_MAX_1;
			//ZoneCoord_t wallx 	= m_pBody->getX() + dirMoveMask[dirWall].x;
			//ZoneCoord_t wally 	= m_pBody->getY() + dirMoveMask[dirWall].y;

			// �� �� ���� creature�� ���� block�� �ƴϸ� ���̴�.
			//if (!m_pBody->canMove(wallx,wally)
			//	&& !m_pBody->isBlockedByCreature(wallx,wally)) 
			{
				//cout << "FindWay : " << (int)dirWall << " - go : " << (int)ndir << " - " << m_pBody->getName() << endl;
				return true;
			}
		}
		// �ٸ� creature�� ���ؼ� �� �� ���ٸ� ��Ÿ�⸦ �׸��д�.
		else if (m_pBody->isBlockedByCreature(nx,ny))
		{
			break;
		}

		// ��� ����
		ndir = (ndir+dirInc) & DIR_MAX_1;
	}

	// ��Ÿ���� �ƹ����� �� �� ���ٸ� ��Ÿ�⸦ �׸��д�. 
	setMoveRule( MOVE_RULE_NORMAL );

	//cout << "Can't go Wall : " << m_pBody->getName() << endl;

	return false;
}


//////////////////////////////////////////////////////////////////////////////
// �ൿ �Լ� (���� ����)
//////////////////////////////////////////////////////////////////////////////

bool MonsterAI::move(ZoneCoord_t ex, ZoneCoord_t ey)
	throw()
{
	Zone*       pZone   = m_pBody->getZone();

	// ���̵� ���¿����� �����̸� �����ϴ�...
	//if (m_pBody->isFlag(Effect::EFFECT_CLASS_HIDE))
	//{
	//	m_LastAction = LAST_ACTION_MOVE;
	//	return true;
	//}
	
	// �̵��� �ġ,����
	ZoneCoord_t nx, ny; 
	Dir_t ndir;

	// �̵� ������ ������ �̵��� ��� ����Ѵ�.
	bool found = false;
	switch (m_MoveRule)
	{
		// ������ �̵�
		case MOVE_RULE_NORMAL :
			found = moveNormal(ex, ey, nx, ny, ndir);
		break;

		// �¼���
		case MOVE_RULE_LEFTWALL :
			found = moveWall(ex, ey, nx, ny, ndir, true);		// true�� left�����̴�.
		break;

		// ������
		case MOVE_RULE_RIGHTWALL :
			found = moveWall(ex, ey, nx, ny, ndir, false);	// false�� right�����̴�.
		break;

		default :
		break;
	}

	// 1. ��� ������ �߰ߵǾ���,
	// 2. ���� ���밡 �ƴ϶���... 
	if ((found) && !(pZone->getZoneLevel(nx, ny) & SAFE_ZONE))
	{
		// ���ο��� ũ��ó�� ��ǥ�� ����� �����ϸ�, ���ε�ĳ��Ʈ�� �˾Ƽ� ���ش�.
		// �̹� Q(nx,ny)�� �����Ǿ� ����Ƿ� ���� �������� �ʿ��� ����.
		pZone->moveCreature(m_pBody, nx, ny, ndir);
	}

	m_LastAction = LAST_ACTION_MOVE;

	return true;
}

bool MonsterAI::move(Creature* pEnemy, bool bRetreat)
	throw()
{
	__BEGIN_TRY

	Zone*       pZone   = m_pBody->getZone();
	ZoneCoord_t enemyX  = pEnemy->getX();
	ZoneCoord_t enemyY  = pEnemy->getY();
	ZoneCoord_t myX     = m_pBody->getX();
	ZoneCoord_t myY     = m_pBody->getY();
	int         xOffset = enemyX - myX;
	int         yOffset = enemyY - myY;
	ZoneCoord_t ex      = pEnemy->getX();
	ZoneCoord_t ey      = pEnemy->getY();

	// ����� ĥ ���쿡�� ���� �ݴ� ��ǥ�� ���� �ִٰ� 
	// �����ϰ�, �����̸� �ȴ�.
	if (bRetreat)
	{
		////////////////////////////////////////////////////////////
		// (enemyX, enemyY)          
		//
		//                  myX, myY
		//
		//                           (ex, ey)
		//                           
		// ���� �ִ� ������(enemyX, enemyY)���� 
		// �밢�� �ݴ� ������� ����� ģ��.
		////////////////////////////////////////////////////////////
		int xOffset2 = xOffset<<1;	// by sigi
		int yOffset2 = yOffset<<1;	// by sigi

		if (enemyX - xOffset2 < 0) ex = 0;
		else if (enemyX - xOffset2 > (int)pZone->getWidth()) ex = pZone->getWidth();
		else ex = enemyX - xOffset2;

		if (enemyY - yOffset2 < 0) ey = 0;
		else if (enemyY - yOffset2 > (int)pZone->getHeight()) ey = pZone->getHeight();
		else ey = enemyY - yOffset2;

		setMoveRule( MOVE_RULE_NORMAL );	// ������� �̵�
	}

	return move(ex, ey);

	__END_CATCH
}

bool MonsterAI::flee(Creature* pEnemy)
	throw()
{
	__BEGIN_TRY

	if (m_Panic == 0)
	{
		if (m_Courage == 0)
		{
			m_Panic   = m_PanicMax;
			m_Courage = m_CourageMax;
		}
		else
		{
			m_Courage--;
		}
	}
	else m_Panic--;

	if (m_Panic > 0)
	{
		// ����ģ��.
		move(pEnemy, true);
		return true;
	}

	return false;

	__END_CATCH
}

int MonsterAI::useSkill(Creature* pEnemy, SkillType_t SkillType, int ratio) 
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Assert(pEnemy != NULL);

	ZoneCoord_t ex = pEnemy->getX();
	ZoneCoord_t ey = pEnemy->getY();
	Distance_t  dist = m_pBody->getDistance(ex , ey);

	// � �ൿ� ���� ���� �� �ൿ� ���� Ȯ���� ���ƿ´�.
	if (rand()%100 >= ratio) return SKILL_FAILED_RATIO;
 
	// [ test code ]
	//	Zone* pZone = m_pBody->getZone();
	// Assert( pZone != NULL );

	//cout << "ZoneID=" << (int)pZone->getZoneID()
    //    << ", MonsterCount=" << (int)pZone->getMonsterCount() << endl;


	//----------------------------------------------------------
	// skill� �����ϱ� �Ұ����� ���¶��� 
	// �ϴ� ������ ���·� �������� �Ѵ�.
	// Directive�� �־ ������, ���� ���� �����ϱ� ������...
	//
	// Slayer��/Vampire����� ������ �����.. ��� - -;
	//----------------------------------------------------------
	// Hide���¶��� Ƣ��;� �Ѵ�.
	if (m_pBody->isFlag( Effect::EFFECT_CLASS_HIDE ))
	{
		SkillType = SKILL_UN_BURROW;
	}
	// �������¶��� �ٽ� ����
	else if (m_pBody->isFlag( Effect::EFFECT_CLASS_TRANSFORM_TO_BAT ))
	{
		SkillType = SKILL_UN_TRANSFORM;
	}
	// invisible���¶��� Ǯ���� �Ѵ�.
	else if (m_pBody->isFlag( Effect::EFFECT_CLASS_INVISIBILITY ))
	{
		SkillType = SKILL_UN_INVISIBILITY;
	}
	// ����� �������� �ȵǴµ�.. - -;

	SkillHandler* pSkillHandler = g_pSkillHandlerManager->getSkillHandler(SkillType);
	Assert(pSkillHandler != NULL);

	SkillInfo* pSkillInfo = NULL;

	Timeval delay;

	switch (SkillType)
	{
		////////////////////////////////////////////////////////////
		// �ٰŸ� ������
		////////////////////////////////////////////////////////////
		case SKILL_ATTACK_MELEE:
		case SKILL_ACID_TOUCH:
		case SKILL_BLOOD_DRAIN:
		case SKILL_SINGLE_BLOW:
		case SKILL_BLOODY_NAIL:
			if (dist > m_pBody->getMeleeRange()) return SKILL_FAILED_RANGE;
			pSkillHandler->execute(m_pBody, pEnemy);
			break;
		////////////////////////////////////////////////////////////
		// ���Ÿ� ������
		////////////////////////////////////////////////////////////
		case SKILL_ATTACK_ARMS:
			if (dist > m_pBody->getMissileRange()) return SKILL_FAILED_RANGE;
			pSkillHandler->execute(m_pBody, pEnemy);
			break;
		////////////////////////////////////////////////////////////
		// ���Ÿ� ������ (with delay)
		////////////////////////////////////////////////////////////
		case SKILL_GREEN_POISON:
		case SKILL_YELLOW_POISON:
		case SKILL_DARKBLUE_POISON:
		case SKILL_GREEN_STALKER:
		case SKILL_ACID_BOLT:
		case SKILL_ACID_BALL:
		case SKILL_BLOODY_BALL:
		case SKILL_BLOODY_WAVE:
		case SKILL_BLOODY_MASTER_WAVE:
		case SKILL_BLOODY_WARP:
		case SKILL_PARALYZE:
		case SKILL_DOOM:
		case SKILL_SEDUCTION:
		case SKILL_DEATH:
		case SKILL_DARKNESS:
		case SKILL_BLOODY_KNIFE:
		case SKILL_BLOODY_SPEAR:
		case SKILL_BLOODY_STORM:
		case SKILL_ACID_STORM:
		case SKILL_POISON_STORM:
		case SKILL_HALLUCINATION:
		// 2003.04.13-14 �����Ͱ� ������ �� �ֵ��� �߰�.
		case SKILL_METEOR_STRIKE:
		case SKILL_BLOODY_WALL:
		case SKILL_BLOODY_SNAKE:
		case SKILL_BLOODY_BREAKER:
		case SKILL_ACID_SWAMP:
		case SKILL_POISON_STRIKE:
		case SKILL_ACID_STRIKE:
		case SKILL_HANDS_OF_WISDOM:
		case SKILL_POISONOUS_HANDS:
		case SKILL_BLOODY_ZENITH:
		case SKILL_ACID_ERUPTION:
		case SKILL_ICE_FIELD:

			pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);
			Assert(pSkillInfo != NULL);

			if (dist > pSkillInfo->getRange()) return SKILL_FAILED_RANGE;
			//cout << "useSkill: " << pSkillInfo->getName().c_str() << endl;
			pSkillHandler->execute(m_pBody, pEnemy);
			//cout << "useSkillOK: " << pSkillInfo->getName().c_str() << endl;

			// �̻��� ���� �ӵ��� �ʹ� ������ ������ �������ð�� ������ �ش�.
			if (m_pBody->isMaster()
#ifdef __UNDERWORLD__
				|| m_pBody->getMonsterType() == 599
#endif
			)		// �����ʹ� delay�� � ���δ�. by sigi. 2002.9.13
			{
				delay.tv_sec  = 0;
				delay.tv_usec = 700000;
			}
			else
			{
				delay.tv_sec  = 1;
				delay.tv_usec = 500000;
			}
			m_pBody->addAccuDelay(delay);
			break;
		////////////////////////////////////////////////////////////
		// ���� ������
		////////////////////////////////////////////////////////////
		case SKILL_HIDE:
		case SKILL_UN_BURROW:
		case SKILL_UN_TRANSFORM:
		case SKILL_TRANSFORM_TO_WOLF:
		case SKILL_TRANSFORM_TO_BAT:
		case SKILL_INVISIBILITY:
		case SKILL_UN_INVISIBILITY:
		case SKILL_DUPLICATE_SELF:
			pSkillHandler->execute(m_pBody);

			// delay���
			delay.tv_sec  = 1;
			delay.tv_usec = 500000;
			m_pBody->addAccuDelay(delay);
			break;

		case SKILL_SUMMON_MONSTERS:
			if ( !checkPossibleSummonMonsters(m_pBody, NULL) && !m_pBody->isMaster() ) return SKILL_FAILED_RANGE;
			
			pSkillHandler->execute(m_pBody);

			// delay���
			delay.tv_sec  = 1;
			delay.tv_usec = 500000;
			m_pBody->addAccuDelay(delay);
			break;

		case SKILL_CRITICAL_GROUND:
			pSkillHandler->execute(m_pBody);

			// delay���
			delay.tv_sec  = 1;
			delay.tv_usec = 0;
			m_pBody->addAccuDelay(delay);
			break;


		////////////////////////////////////////////////////////////
		// QuickFire - -;
		////////////////////////////////////////////////////////////
		case SKILL_QUICK_FIRE:
			pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);
			Assert(pSkillInfo != NULL);

			if (dist > pSkillInfo->getRange()) return SKILL_FAILED_RANGE;
			pSkillHandler->execute(m_pBody, pEnemy);
			
			break;


		////////////////////////////////////////////////////////////
		// �������� �ʴ� ����
		////////////////////////////////////////////////////////////
		default:
			cerr << "MonsterAI::useSkill() : Try to use unavailable skill!" << endl;
			Assert(false);
			break;
	}

	m_LastAction = LAST_ACTION_SKILL;

	return 0;

	__END_DEBUG
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
// �ൿ ���� ���� �Լ�
//////////////////////////////////////////////////////////////////////////////

void MonsterAI::deal(Creature* pEnemy, const Timeval& currentTime)
	throw()
{
	__BEGIN_TRY

	Assert(pEnemy != NULL);	// by sigi

	// ���̷�Ƽ�� ����Ʈ�� �����.
	const list<Directive*>& directiveList = m_pDirectiveSet->getDirectives();
	int rValue = 0;
	int parameter = 0;
	int ratio = 0;

	// ���̷�Ƽ�� ����Ʈ�� �ϳ��� �˻��ϸ鼭,
	// ����� ����Ǵ� ���� �ִ��� üũ�Ѵ�.
	list<Directive*>::const_iterator itr = directiveList.begin();
	for (; itr != directiveList.end(); itr++)
	{
		Directive* pDirective = *itr;

		// ����� ����ϴ� ���̷�Ƽ�갡 �ִٸ�,
		// �׿� �ش��ϴ� �׼�� �����Ѵ�.
		if (checkDirective(pDirective, pEnemy))
		{
			switch (pDirective->getAction())
			{
				// ������ �ٰ�����.
				case DIRECTIVE_ACTION_APPROACH:
					__BEGIN_PROFILE_MONSTER("DIRECTIVE_ACTION_APPROACH");
					approach(pEnemy);
					__END_PROFILE_MONSTER("DIRECTIVE_ACTION_APPROACH");
					//cout << "[" << (int)currentTime.tv_sec << "." << (int)currentTime.tv_usec << "] approach" << endl;
					break;

				// ����κ��� ����ģ��.
				case DIRECTIVE_ACTION_FLEE:
					__BEGIN_PROFILE_MONSTER("DIRECTIVE_ACTION_FLEE");
					if (!flee(pEnemy))
					{
						setMoveRule( MOVE_RULE_NORMAL );	// ������� �̵�
						rValue = useSkill(pEnemy, SKILL_ATTACK_MELEE, 100);
						if (rValue != 0) approach(pEnemy);
						//cout << "[" << (int)currentTime.tv_sec << "." << (int)currentTime.tv_usec << "] !free" << endl;
					}
					else
					{
						//cout << "[" << (int)currentTime.tv_sec << "." << (int)currentTime.tv_usec << "] free" << endl;
					}
					__END_PROFILE_MONSTER("DIRECTIVE_ACTION_FLEE");
					break;

				// ��ų� �����Ѵ�. ��� �����ϰų�, ���� ����...
				case DIRECTIVE_ACTION_USE_SKILL:
					__BEGIN_PROFILE_MONSTER("DIRECTIVE_ACTION_USE_SKILL");
					// Block Head �ɷ�������� ��ų� ������ �� ����.
					if ( m_pBody->isFlag( Effect::EFFECT_CLASS_BLOCK_HEAD ) || m_pBody->isFlag( Effect::EFFECT_CLASS_TENDRIL ) ) continue;
					parameter = pDirective->getParameter();
					ratio     = pDirective->getRatio();
					rValue    = useSkill(pEnemy, (SkillType_t)parameter, ratio);
					__END_PROFILE_MONSTER("DIRECTIVE_ACTION_USE_SKILL");

					if (rValue != 0) 
					{
						//cout << "[" << (int)currentTime.tv_sec << "." << (int)currentTime.tv_usec << "] !" << SkillTypes2String[parameter] << endl;
						continue;
					}

					//cout << "[" << (int)currentTime.tv_sec << "." << (int)currentTime.tv_usec << "] " << SkillTypes2String[parameter] << endl;


					setMoveRule( MOVE_RULE_NORMAL );	// ������� �̵�

					break;
				
				// ��� �����Ѵ�.
				case DIRECTIVE_ACTION_FORGET:
					__BEGIN_PROFILE_MONSTER("DIRECTIVE_ACTION_FORGET");
					// by sigi. 2002.10.7
					if (!m_pBody->getEnemies().empty())
						m_pBody->getEnemies().pop_front();

					setMoveRule( MOVE_RULE_NORMAL );	// ������� �̵�
					//cout << "[" << (int)currentTime.tv_sec << "." << (int)currentTime.tv_usec << "] forget" << endl;
					__END_PROFILE_MONSTER("DIRECTIVE_ACTION_FORGET");

					break;

				// ���ο� PrimaryEnemy�� ã�Ƽ� üũ�Ѵ�.
				case DIRECTIVE_ACTION_CHANGE_ENEMY :
					{
						ratio = pDirective->getParameter();

						// ��� �� �ٲ۴�.
						if (rand()%100 >= ratio)
						{
							//cout << "[" << (int)currentTime.tv_sec << "." << (int)currentTime.tv_usec << "] !changeEnemy" << endl;
							continue;
						}

						__BEGIN_PROFILE_MONSTER("DIRECTIVE_ACTION_CHANGE_ENEMY");
						
						Creature* pNewEnemy = m_pBody->getPrimaryEnemy();
						if (pNewEnemy!=NULL)
						{
							pEnemy = pNewEnemy;
						}
						else
						{
							// ���ٸ�.. checkFindWeakEnemy���� delete�ϰ� 
							// ���ο� ���� �߰��� ���� �ʾҴٴ� �ǹ��̴�.
							// ����� ��� �ٽ� �߰��Ѵ�.
							// by sigi. 2002.10.7
							if (m_pBody->getEnemies().empty())
							{
								m_pBody->addEnemy( pEnemy );
							}
						}

						__END_PROFILE_MONSTER("DIRECTIVE_ACTION_CHANGE_ENEMY");

						// ��� AI�� �Լ� �����Ѵ�.
						//cout << "[" << (int)currentTime.tv_sec << "." << (int)currentTime.tv_usec << "] changeEnemy" << endl;
						continue;
					}
					break;

				// ��ó�� ���򰡷� �̵��Ѵ�.
				case DIRECTIVE_ACTION_MOVE_RANDOM :
					{
						ratio = pDirective->getParameter();

						// ���򰡷� �̵����� �ʴ´�.
						if (rand()%100 >= ratio)
						{
							//cout << "[" << (int)currentTime.tv_sec << "." << (int)currentTime.tv_usec << "] !moveRandom" << endl;
							continue;
						}

						ZoneCoord_t x;
						ZoneCoord_t y;
						TPOINT p;

						__BEGIN_PROFILE_MONSTER("DIRECTIVE_ACTION_MOVE_RANDOM_GET_SAFE_TILE");

						x = m_pBody->getX();
						y = m_pBody->getY();

						p = getSafeTile(m_pBody->getZone(), x, y);

						__END_PROFILE_MONSTER("DIRECTIVE_ACTION_MOVE_RANDOM_GET_SAFE_TILE");

						// �ڸ��� ���ٸ�.. �� ���� - -;
						if (p.x==-1)
						{
							///cout << "[" << (int)currentTime.tv_sec << "." << (int)currentTime.tv_usec << "] moveRandom : no position" << endl;
							continue;
						}

						__BEGIN_PROFILE_MONSTER("DIRECTIVE_ACTION_MOVE_RANDOM_MOVE");

						ZoneCoord_t x1 = p.x;//x + rand()%7 - 3;
						ZoneCoord_t y1 = p.y;//y + rand()%7 - 3;
						
						if (x!=x1 || y!=y1)
							move(x1, y1);

						__END_PROFILE_MONSTER("DIRECTIVE_ACTION_MOVE_RANDOM_MOVE");
						//cout << "[" << (int)currentTime.tv_sec << "." << (int)currentTime.tv_usec << "] moveRandom" << endl;
					}
					break;

				// ���� �����Ѵ�.
				case DIRECTIVE_ACTION_WAIT :
					{
						__BEGIN_PROFILE_MONSTER("DIRECTIVE_ACTION_WAIT");
						Timeval delay;
						delay.tv_sec  = 2;
						delay.tv_usec = 0;
						m_pBody->addAccuDelay(delay);
						__END_PROFILE_MONSTER("DIRECTIVE_ACTION_WAIT");
						//cout << "[" << (int)currentTime.tv_sec << "." << (int)currentTime.tv_usec << "] wait" << endl;
					}
					break;

				case DIRECTIVE_ACTION_FAST_FLEE :
					{
						bool result = false;

						__BEGIN_PROFILE_MONSTER("DIRECTIVE_ACTION_FAST_FLEE");
						int myX = m_pBody->getX();
						int myY = m_pBody->getY();

						int nmX = pEnemy->getX();
						int nmY = pEnemy->getY();

						int diffX = myX - nmX;
						int diffY = myY - nmY;

						float ratio = 5.0 / ( ABS(diffX) + ABS(diffY) );

						int newX = myX + diffX * ratio;
						int newY = myY + diffY * ratio;

						if ( isValidZoneCoord( m_pBody->getZone(), newX, newY ) )
							result = m_pBody->getZone()->moveFastMonster( m_pBody, myX, myY, newX, newY, SKILL_RAPID_GLIDING );

/*						if ( newX > 0 ) continue;
						if ( newY < 0 ) continue;
						if ( newX >= m_pBody->getZone()->getWidth() ) continue;
						if ( newY >= m_pBody->getZone()->getHeight() ) continue;

						if ( !m_pBody->getZone()->moveFastMonster( m_pBody, myX, myY, newX, newY, SKILL_RAPID_GLIDING ) ) continue;*/
						__END_PROFILE_MONSTER("DIRECTIVE_ACTION_FAST_FLEE");

						if ( !result ) continue;
					}
					break;
			}
			break;
		}
	}

	__BEGIN_PROFILE_MONSTER("MAI_POST_DEAL");

	// �̹� �Ͽ� � �ൿ� �ߴ�Ŀ� ���� �ൿ ���� �ð�� �������ش�.
	switch (m_LastAction)
	{
		case LAST_ACTION_NONE:
		case LAST_ACTION_MOVE:
			setDelay(currentTime);
			break;
		case LAST_ACTION_SKILL:
			setAttackDelay(currentTime);
			break;
	}

	// �ൿ ������ ���� ������ �ش�.
	m_LastAction = LAST_ACTION_NONE;
	
	// ����� ���� ������ Ȯ������� ���� �������ش�.
	if ((rand() & 0x0000007F) > 64)	//%100 > 50)
	{
		if (m_bDamaged)
		{
			m_bDamaged = false;
			m_Panic    = m_PanicMax;
			m_Courage  = m_CourageMax;
		}
	}

	__END_PROFILE_MONSTER("MAI_POST_DEAL");

	__END_CATCH
}

// ��� ���� �ൿ� ���Ѵ�.
void MonsterAI::actDeadAction(Creature* pEnemy) 
	throw()
{
	__BEGIN_TRY

	// MonsterAI�� �Ѱ��� ����,
	// ���� ��� ���쿡 ���� �� �ִ� �׼ǿ��� �Ѱ谡 �ִ�.
	if (pEnemy != NULL)
	{
		// ���̷�Ƽ�� ����Ʈ�� �����.
		const list<Directive*>& directiveList = m_pDirectiveSet->getDeadDirectives();
		bool bContinue = true;

		// ���̷�Ƽ�� ����Ʈ�� �ϳ��� �˻��ϸ鼭,
		// ����� ����Ǵ� ���� �ִ��� üũ�Ѵ�.
		list<Directive*>::const_iterator itr = directiveList.begin();
		for (; itr != directiveList.end() && bContinue; itr++)
		{
			Directive* pDirective = *itr;

			if (pDirective->getAction() == DIRECTIVE_ACTION_USE_SKILL)
			{
				SkillType_t SkillType = pDirective->getParameter();
				int         ratio     = pDirective->getRatio();

				SkillHandler* pSkillHandler = g_pSkillHandlerManager->getSkillHandler(SkillType);
				Assert(pSkillHandler != NULL);

				if ((rand()%ratio) < 100)
				{
					switch (SkillType)
					{
						case SKILL_GREEN_POISON:
							pSkillHandler->execute(m_pBody);
							bContinue = false;
							break;
						default:
							Assert(false);
							break;
					}
				}
				else
				{
					// ���� ������ Ȯ�� üũ�� ���� �����ߴٸ� ��� �׼���� �Ѿ��.
					continue;
				}
			}
		}
	}

	__END_CATCH
}

void MonsterAI::setDelay(const Timeval& currentTime)
	throw()
{
	__BEGIN_TRY

	// ����� ���� �ð�� �̿��Ѵ�. ���� ���Ϸ��. - -; by sigi. 2002.5.6
	//Timeval currentTime;
	//getCurrentTime(currentTime);

	int delay    = m_pBody->getDelay();

	if (m_pBody->isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_BAT))
	{
		delay = 200; // 250
	}
	else if (m_pBody->isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_WOLF))
	{
		delay = 300; // 375
	}

	int modifier = (rand()%41)-20;

	delay = delay*1000;
	delay = delay + delay*modifier/100;

	Timeval nexttime;
	nexttime.tv_sec  = delay/1000000;
	nexttime.tv_usec = delay%1000000;

	nexttime = nexttime + m_pBody->getAccuDelay();

	m_pBody->clearAccuDelay();

	if ( m_pBody->isFlag( Effect::EFFECT_CLASS_ICE_FIELD_TO_CREATURE ) 
	||	m_pBody->isFlag( Effect::EFFECT_CLASS_JABBING_VEIN ) )
	{
		m_pBody->setNextTurn(currentTime + nexttime + nexttime);
	}
	else
	{
		m_pBody->setNextTurn(currentTime + nexttime);
	}

	/*
	Timeval currentTime;
	Timeval delay;

	getCurrentTime(currentTime);

	delay.tv_sec  = m_pBody->getDelay()/1000;
	delay.tv_usec = (m_pBody->getDelay()%1000)*1000 + rand()%200000;

	delay = delay + m_pBody->getAccuDelay();

	m_pBody->clearAccuDelay();
	m_pBody->setNextTurn(currentTime + delay);
	*/
	
	/*
	Timeval delay;
	delay.tv_sec = 0;
	delay.tv_usec = m_pBody->getDelay()* 1000 + rand() % 200000;
	m_pBody->setNextTurn(m_pBody->getNextTurn() + delay);
	*/

	__END_CATCH
}

void MonsterAI::setAttackDelay(const Timeval& currentTime)
	throw()
{
	__BEGIN_TRY

	// ����� ���� �ð�� �̿��Ѵ�. ���� ���Ϸ��. - -; by sigi. 2002.5.6
	//Timeval currentTime;
	//getCurrentTime(currentTime);

	int delay    = m_pBody->getAttackDelay();
	int modifier = (rand()%21);

	delay = delay*1000;
	delay = delay + delay*modifier/100;

	Timeval nexttime;
	nexttime.tv_sec  = delay/1000000;
	nexttime.tv_usec = delay%1000000;

	nexttime = nexttime + m_pBody->getAccuDelay();

	m_pBody->clearAccuDelay();

	if ( m_pBody->isFlag( Effect::EFFECT_CLASS_ICE_OF_SOUL_STONE ) )
	{
		m_pBody->setNextTurn(currentTime + nexttime + nexttime);
	}
	else
	{
		m_pBody->setNextTurn(currentTime + nexttime);
	}

	
	/*
	Timeval currentTime;
	Timeval delay;

	getCurrentTime(currentTime);

	delay.tv_sec  = m_pBody->getAttackDelay()/1000;
	delay.tv_usec = (m_pBody->getAttackDelay()%1000)*1000 + rand()%200000;

	delay = delay + m_pBody->getAccuDelay();

	m_pBody->clearAccuDelay();
	m_pBody->setNextTurn(currentTime + delay);
	*/

	/*
	Timeval delay;
	delay.tv_sec = 0;
	delay.tv_usec = m_pBody->getAttackDelay()* 1000 + rand() % 200000;
	m_pBody->setNextTurn(m_pBody->getNextTurn() + delay);
	*/

	__END_CATCH
}




bool checkEnemyRangeMelee(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	Distance_t dist = pMonster->getDistance(pEnemy->getX(), pEnemy->getY());
	if (dist <= pMonster->getMeleeRange()) return true;
	return false;
}

bool checkEnemyRangeMissile(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	Distance_t dist = pMonster->getDistance(pEnemy->getX(), pEnemy->getY());
	if (dist > pMonster->getMeleeRange() && dist <= pMonster->getSight()) return true;
	return false;
}

bool checkEnemyRangeInMissile(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	Distance_t dist = pMonster->getDistance(pEnemy->getX(), pEnemy->getY());
	if (dist <= pMonster->getSight()) return true;
	return false;
}

bool checkEnemyRangeClose(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	Distance_t dist = pMonster->getDistance(pEnemy->getX(), pEnemy->getY());
	if (dist <= 1) return true;
	return false;
}


bool checkEnemyRangeOutOfSight(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	Distance_t dist = pMonster->getDistance(pEnemy->getX(), pEnemy->getY());
	if (dist > pMonster->getSight()) return true;
	return false;
}

bool checkEnemyDying(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;

	HP_t EnemyCurHP = 0;
	HP_t EnemyMaxHP = 0;

	if (pEnemy->isSlayer())
	{
		Slayer* pSlayer = dynamic_cast<Slayer*>(pEnemy);
		EnemyCurHP = pSlayer->getHP(ATTR_CURRENT);
		EnemyMaxHP = pSlayer->getHP(ATTR_MAX);
	}
	else if (pEnemy->isVampire())
	{
		Vampire* pVampire = dynamic_cast<Vampire*>(pEnemy);
		EnemyCurHP = pVampire->getHP(ATTR_CURRENT);
		EnemyMaxHP = pVampire->getHP(ATTR_MAX);
	}
	else if (pEnemy->isOusters())
	{
		Ousters* pOusters = dynamic_cast<Ousters*>(pEnemy);
		EnemyCurHP = pOusters->getHP(ATTR_CURRENT);
		EnemyMaxHP = pOusters->getHP(ATTR_MAX);
	}
	else if (pEnemy->isMonster())
	{
		Monster* pEnemyMonster = dynamic_cast<Monster*>(pEnemy);
		EnemyCurHP = pEnemyMonster->getHP(ATTR_CURRENT);
		EnemyMaxHP = pEnemyMonster->getHP(ATTR_MAX);
	}

	if (EnemyCurHP*5 < EnemyMaxHP) return true;

	return false;
}

bool checkEnemyNotBloodDrained(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	if (pEnemy->isVampire()) return false;
	if (!pEnemy->isFlag(Effect::EFFECT_CLASS_BLOOD_DRAIN)) return true;
	return false;
}

bool checkEnemyNotGreenPoisoned(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	if (pEnemy->isVampire()) return false;
	if (!pEnemy->isFlag(Effect::EFFECT_CLASS_POISON)) return true;
	return false;
}

bool checkEnemyNotYellowPoisoned(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	if (pEnemy->isVampire()) return false;
	if (!pEnemy->isFlag(Effect::EFFECT_CLASS_YELLOW_POISON_TO_CREATURE)) return true;
	return false;
}

bool checkEnemyNotDarkbluePoisoned(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	if (pEnemy->isVampire()) return false;
	if (!pEnemy->isFlag(Effect::EFFECT_CLASS_DARKBLUE_POISON)) return true;
	return false;
}

bool checkEnemyNotGreenStalkered(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	if (pEnemy->isVampire()) return false;
	if (!pEnemy->isFlag(Effect::EFFECT_CLASS_GREEN_STALKER)) return true;
	return false;
}

bool checkEnemyNotParalyzed(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	if (!pEnemy->isFlag(Effect::EFFECT_CLASS_PARALYZE)) return true;
	return false;
}

bool checkEnemyNotDoomed(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	if (!pEnemy->isFlag(Effect::EFFECT_CLASS_DOOM)) return true;
	return false;
}

bool checkEnemyNotBlinded(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	return false;
}

bool checkEnemyNotInDarkness(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	if (pEnemy->isVampire()) return false;
	if (!pEnemy->isFlag(Effect::EFFECT_CLASS_DARKNESS)) return true;
	return false;
}

bool checkEnemyNotSeduction(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	if (!pEnemy->isFlag(Effect::EFFECT_CLASS_SEDUCTION)) return true;
	return false;
}

bool checkEnemyNotDeath(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	if (!pEnemy->isFlag(Effect::EFFECT_CLASS_DEATH)) return true;
	return false;
}

bool checkImOK(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	HP_t CurHP = pMonster->getHP(ATTR_CURRENT);
	HP_t MaxHP = pMonster->getHP(ATTR_MAX);
	if (CurHP > MaxHP/3) return true;
	return false;
}

bool checkImDying(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	HP_t CurHP = pMonster->getHP(ATTR_CURRENT);
	HP_t MaxHP = pMonster->getHP(ATTR_MAX);
	if (CurHP*4 < MaxHP) return true;
	return false;
}

bool checkImDamaged(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	return pMonster->getBrain()->getDamaged();
}

bool checkImHiding(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	return pMonster->isFlag(Effect::EFFECT_CLASS_HIDE);
}

bool checkImWolf(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	return pMonster->isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_WOLF);
}

bool checkImBat(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	return pMonster->isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_BAT);
}

bool checkImInvisible(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	return pMonster->isFlag(Effect::EFFECT_CLASS_INVISIBILITY);
}


bool checkImWalkingWall(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	MonsterAI* pAI = pMonster->getBrain();

	Assert(pAI != NULL);

	if (pAI->getWallCount() > 3 
		&& (pAI->getMoveRule()==MOVE_RULE_LEFTWALL 
			|| pAI->getMoveRule()==MOVE_RULE_RIGHTWALL))
	{
		return true;
	}

	return false;
}

bool checkTimingBloodDrain(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	// �����Ͱ� slayer�� �ƴ϶��� �����ϰ� ���. by sigi. 2002.9.14
	if (pEnemy == NULL
		// Slayer�� �ƴϸ� �������� �ʴ´�.
		|| pEnemy->isNPC()
		// �̹� ����������� �������� �ʴ´�.
		|| pEnemy->isFlag(Effect::EFFECT_CLASS_BLOOD_DRAIN)
		// ����. ���� �鿪. by sigi. 2002.9.14
		|| pEnemy->isFlag(Effect::EFFECT_CLASS_NO_DAMAGE)
		|| pEnemy->isFlag(Effect::EFFECT_CLASS_IMMUNE_TO_BLOOD_DRAIN)) 
	{
		return false;
	}

	// �����Ÿ��� �Ǵ��� Ȯ���Ѵ�.
	Distance_t dist = pMonster->getDistance(pEnemy->getX(), pEnemy->getY());
	if (dist > pMonster->getMeleeRange()) return false;

	HP_t EnemyCurHP = 0;
	HP_t EnemyMaxHP = 0;

	if (pEnemy->isSlayer())
	{
		Slayer* pSlayer = dynamic_cast<Slayer*>(pEnemy);
		EnemyCurHP = pSlayer->getHP(ATTR_CURRENT);
		EnemyMaxHP = pSlayer->getHP(ATTR_MAX);
	}
	else if (pEnemy->isVampire())
	{
		Vampire* pVampire = dynamic_cast<Vampire*>(pEnemy);
		EnemyCurHP = pVampire->getHP(ATTR_CURRENT);
		EnemyMaxHP = pVampire->getHP(ATTR_MAX);
	}
	else if (pEnemy->isOusters())
	{
		Ousters* pOusters = dynamic_cast<Ousters*>(pEnemy);
		EnemyCurHP = pOusters->getHP(ATTR_CURRENT);
		EnemyMaxHP = pOusters->getHP(ATTR_MAX);
	}
	else if (pEnemy->isMonster())
	{
		Monster* pMonster = dynamic_cast<Monster*>(pEnemy);
		EnemyCurHP = pMonster->getHP(ATTR_CURRENT);
		EnemyMaxHP = pMonster->getHP(ATTR_MAX);
	}

	// HP�� 1/5�̻� ������� �������� �ʴ´�.
	if (EnemyCurHP*5 >= EnemyMaxHP) return false;

	// ��ħ��... �����Ѵ�~
	return true;

}

bool checkTimingMasterBloodDrain(Monster* pMonster, Creature* pEnemy)
{
	// 20% üũ
	// ���� ��ü�� ���ùǷ�..
	//if (rand()%100 > 10)
	//	return false;

	Assert(pMonster != NULL);

	if ((!pMonster->isMaster()
#ifdef __UNDERWORLD__
		&& pMonster->getMonsterType() != 599
#endif
		)
		|| pEnemy == NULL)
	{
		return false;
	}

	int masterHPPercent = pMonster->getHP(ATTR_CURRENT)*100/pMonster->getHP(ATTR_MAX);

	// ���� Ȯ��
	//int startHPPercent 	= 70,	startBDPercent 	= 10;
	//int endHPPercent 	= 30, 	endBDPercent 	= 30;
	int startHPPercent 	= g_pVariableManager->getMasterBloodDrainStartHP();
	int startBDPercent 	= g_pVariableManager->getMasterBloodDrainStartBD();
	int endHPPercent 	= g_pVariableManager->getMasterBloodDrainEndHP();	
	int endBDPercent 	= g_pVariableManager->getMasterBloodDrainEndBD();

	// HP�� 70% �̻��̸� �������� �ʴ´�.
	if (masterHPPercent >= startHPPercent)
		return false;

	int ratio = rand()%100;

	// HP�� 30% �����̸�.. 30%�� Ȯ���� �����Ѵ�.
	if (masterHPPercent <= endHPPercent)
	{
		return ratio < endBDPercent;
	}

	// HP�� 30~70%�̸� 10~30%�� Ȯ���� �����Ѵ�.
	int maxBDPercent = max( startBDPercent, endBDPercent );
	int gapHPPercent = startHPPercent - endHPPercent;
	int gapBDPercent = abs( endBDPercent - startBDPercent );

	//int permitRatio = maxBDPercent - (masterHPPercent-endHPPercent)/2;
	int permitRatio = maxBDPercent - gapBDPercent * (masterHPPercent-endHPPercent) / gapHPPercent;

	return ratio < permitRatio;

	/*
	if (masterHPPercent < 3 || masterHPPercent > 70)
	{
		return false;
	}
	*/

	// �ƹ��� ������ �� ����Ƿ�.. - -;
	//return true;

	/*
	int x = pEnemy->getX();
	int y = pEnemy->getY();
	int Splash = 30; // �׳� 30������ üũ�Ѵ�.
	int range = 3; // 7x7   //5;	// 11x11
	list<Creature*> creatureList;
	getSplashVictims(pMonster->getZone(), x, y, Creature::CREATURE_CLASS_MAX, creatureList, Splash, range);

	list<Creature*>::iterator itr = creatureList.begin();
	for (; itr != creatureList.end(); itr++)
	{
		Creature* pTargetCreature = (*itr);
		Assert(pTargetCreature != NULL);
	
		if (pMonster!=pTargetCreature
			&& pTargetCreature->isNPC()
			// �̹� ����������� �������� �ʴ´�. �����Ͱ� �̷��� �����ڳ� �; ����.
			//&& pTargetCreature->isFlag(Effect::EFFECT_CLASS_BLOOD_DRAIN)
			// ����. ���� �鿪. by sigi. 2002.9.14
			&& pTargetCreature->isFlag(Effect::EFFECT_CLASS_NO_DAMAGE)
			&& pTargetCreature->isFlag(Effect::EFFECT_CLASS_IMMUNE_TO_BLOOD_DRAIN)) 
		{
			HP_t EnemyCurHP = 0;
			HP_t EnemyMaxHP = 0;

			if (pTargetCreature->isSlayer())
			{
				Slayer* pSlayer = dynamic_cast<Slayer*>(pTargetCreature);
				EnemyCurHP = pSlayer->getHP(ATTR_CURRENT);
				EnemyMaxHP = pSlayer->getHP(ATTR_MAX);
			}
			else if (pTargetCreature->isVampire())
			{
				Vampire* pVampire = dynamic_cast<Vampire*>(pTargetCreature);
				EnemyCurHP = pVampire->getHP(ATTR_CURRENT);
				EnemyMaxHP = pVampire->getHP(ATTR_MAX);
			}
			else if (pTargetCreature->isMonster())
			{
				Monster* pMonster = dynamic_cast<Monster*>(pTargetCreature);
				EnemyCurHP = pMonster->getHP(ATTR_CURRENT);
				EnemyMaxHP = pMonster->getHP(ATTR_MAX);
			}
	
			// ü�� 50% �̸�� �������Ѵ�
			if (EnemyCurHP*2 < EnemyMaxHP) 
				return true;
		}
	}
	*/

	return true;

}

//----------------------------------------------------------------------
//
// bool checkMasterSummonTiming(Monster* pMonster, Creature* pEnemy)
//
//----------------------------------------------------------------------
// ��ȯ ����� ���� �ҷ�� �ϴµ�..
// ���� ��� ������ �����̰�.. 
// �ٸ� ���� ������ �Ѵ�.
//----------------------------------------------------------------------
bool checkMasterSummonTiming(Monster* pMonster, Creature* pEnemy)
{
	//cout << "checkMasterSummonTiming: ";

	Assert(pMonster != NULL);

	// �����Ͱ� �ƴϸ� �ҿ�����.
	if (!pMonster->isMaster())
		//|| !pMonster->hasNextMonsterSummonInfo())
	{
		//cout << "not Master" << endl;
		return false;
	}

	// �����Ͱ� �ִ� ��� �����ͷ������� Ȯ���Ѵ�.
	Zone* pZone = pMonster->getZone();
	Assert(pZone!=NULL);

	// ������ ��� �ƴϸ� �ǹ̾���.
	if (!pZone->isMasterLair())
	{
		//cout << "not MasterLair" << endl;
		return false;
	}

	MasterLairManager* pMasterLairManager = pZone->getMasterLairManager();
	Assert(pMasterLairManager!=NULL);

	// ���� �����Ͱ� �ο��� ���°� �ƴϰ�
	// ��� ������ �̿��� �����Ͱ� ���� ���� ��ȯ�� �� �ִ�.
	bool bSummonTiming = !pMasterLairManager->isMasterReady() && 
						pZone->getMonsterManager()->getSize() <= 1;

	/*
	if (bSummonTiming)
		cout << "Master Not Ready" << endl;
	else
		cout << "Master Ready" << endl;
		*/

	return bSummonTiming;
}

//----------------------------------------------------------------------
//
// bool checkMasterNotReady(Monster* pMonster, Creature* pEnemy)
//
//----------------------------------------------------------------------
bool checkMasterNotReady(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	// �����Ͱ� �ƴϸ� �ҿ�����.
	if (!pMonster->isMaster())
	{
		return false;
	}

	// �����Ͱ� �ִ� ��� �����ͷ������� Ȯ���Ѵ�.
	Zone* pZone = pMonster->getZone();
	Assert(pZone!=NULL);

	// ������ ��� �ƴϸ� �ǹ̾���.
	if (!pZone->isMasterLair())
	{
		return false;
	}

	MasterLairManager* pMasterLairManager = pZone->getMasterLairManager();
	Assert(pMasterLairManager!=NULL);

	// ���� �����Ͱ� �ο��� ���°� �ƴϰ�
	// ��� ������ �̿��� �����Ͱ� ���� ���� ��ȯ�� �� �ִ�.
	return !pMasterLairManager->isMasterReady();
}

//----------------------------------------------------------------------
//
// bool checkImInBadPosition(Monster* pMonster, Creature* pEnemy)
//
//----------------------------------------------------------------------
// ���� �ġ�� �� ��� ���ΰ�?
//
// pMonster�� �ִ� Ÿ�Ͽ� AcidSwamp�� �ѷ�� �ִ� ����
//----------------------------------------------------------------------
bool checkImInBadPosition(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster!=NULL);

	Zone* pZone = pMonster->getZone();
	Assert(pZone!=NULL);

	Tile& rTile = pZone->getTile( pMonster->getX(), pMonster->getY() );

	// ���� ���°� �ƴϰ�
	if (!pMonster->isFlag(Effect::EFFECT_CLASS_NO_DAMAGE)

			// Acid �鿪�� �ƴϰ� �ٴڿ� AcidSwap�� �����ִٸ� �� ����. - -;
		&& (!pMonster->isFlag(Effect::EFFECT_CLASS_IMMUNE_TO_ACID)
				&& rTile.getEffect(Effect::EFFECT_CLASS_ACID_SWAMP)!=NULL

			|| rTile.getEffect(Effect::EFFECT_CLASS_BLOODY_WALL)!=NULL
			|| rTile.getEffect(Effect::EFFECT_CLASS_GROUND_ATTACK)!=NULL)
		)
	{
		return true;
	}

	return false;
}

//----------------------------------------------------------------------
//
// bool checkFindWeakEnemy(Monster* pMonster, Creature* pEnemy)
//
//----------------------------------------------------------------------
// �� ���� ��� ã� �� �ֳ�?
//
// pEnemy�� HP�� 100�̻��̰� HP percentage�� 60% �̻��̶��� 
// �ٸ� ���� ��� �� ã�ƺ���.
//----------------------------------------------------------------------
bool checkFindWeakEnemy(Monster* pMonster, Creature* pEnemy)
{
	// �ϴ�
	//return false;

	try
	{
		if (pEnemy==NULL) return false;

		Assert(pMonster!=NULL);

		Zone* pZone = pMonster->getZone();
		Assert(pZone!=NULL);

		int strongValue = getStrongValue(pEnemy);

		if (strongValue==0) return false;

		// ���� ��� � ����..���� �Ǵ�� �ϰ�. --;
		// ���ο� ���� ��� ã�´�.
		Creature* pWeakestCreature = NULL;

		// ��� �˻�
		ZoneCoord_t cx = pMonster->getX();
		ZoneCoord_t cy = pMonster->getY();;
		ZoneCoord_t ix = 0;
		ZoneCoord_t iy = 0;
		ZoneCoord_t endx = 0;
		ZoneCoord_t endy = 0;

		// ������ �þ� ������� ã�´�.
		Sight_t sight = pMonster->getSight();	

		endx = min(pZone->getWidth() - 1, cx + sight + 1);
		endy = min(pZone->getHeight() - 1, cy + sight  + 1);

		for (ix =  max(0, cx - sight - 1); ix <= endx ; ix++) 
		{
			for (iy = max(0, cy - sight - 1); iy <= endy ; iy++) 
			{
				Tile& rTile = pZone->getTile(ix, iy);

				// Ÿ�Ͽ� ũ��ó�� �ִ� ���쿡��
				if (rTile.hasCreature()) 
				{
					const list<Object*> & objectList = rTile.getObjectList();

					for (list<Object*>::const_iterator itr = objectList.begin() ; 
						itr != objectList.end() && (*itr)->getObjectPriority() <= OBJECT_PRIORITY_BURROWING_CREATURE; 
						itr++) 
					{
						Creature* pCreature = dynamic_cast<Creature*>(*itr);		
						Assert(pCreature != NULL);

						// pMonster, pEnemy�� �ƴ϶���..
						// Player���� �����ϰ� �ȴ�.
						if (pCreature != pMonster 
							&& pCreature != pEnemy
							&& pCreature->isPC()
							&& pMonster->isRealEnemy(pCreature))
						{
							int checkStrongValue = getStrongValue( pCreature );

							// �� ���ѳ�� pWeakestCreature�� �Ӹ�~�Ѵ�
							if (checkStrongValue < strongValue)
							{
								pWeakestCreature = pCreature;
								strongValue = checkStrongValue;
							}
						} 
					}
				}
			}
		}

		// � ���ѳ�� ã� ����..
		if (pWeakestCreature!=NULL)
		{
			pMonster->deleteAllEnemy();
			pMonster->addEnemy( pWeakestCreature );

			return true;
		}
		else
		{
		}

	} catch (Throwable& t) {
		// ���� exception� �����Ѵ�.
		filelog("monsterAIBug.txt", "%s", t.toString().c_str());
	}

	return false;
}

bool checkEnemyNotHallucination(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	if (pEnemy == NULL) return false;
	if (!pEnemy->isFlag(Effect::EFFECT_CLASS_HALLUCINATION)) return true;
	return false;
}

bool checkTimingDuplicateSelf(Monster* pMonster, Creature* pEnemy)
{
	Assert(pMonster != NULL);

	// �����Ͱ� �ƴϸ� �ҿ�����.
	if (!pMonster->isMaster())
	{
		return false;
	}

	// �����Ͱ� �ִ� ��� �����ͷ������� Ȯ���Ѵ�.
	Zone* pZone = pMonster->getZone();
	Assert(pZone!=NULL);

	/*
	// ������ ��� �ƴϸ� �ǹ̾���.
	if (!pZone->isMasterLair())
	{
		return false;
	}
	*/

	HP_t currentHP = pMonster->getHP(ATTR_CURRENT);
	HP_t maxHP = pMonster->getHP(ATTR_MAX);

	// HP�� 70%�� ����� �������Ѵ�.
	if (currentHP*100/maxHP > 70)
	{
		return false;
	}

	// 12���� �̻��̸� �� ��ȯ ���Ѵ�.
	if (pZone->getMonsterManager()->getSize() > 12)
	{
		return false;
	}

	return true;
}

//----------------------------------------------------------------------
//
// bool checkPossibleSummonMonsters(Monster* pMonster, Creature* pEnemy)
//
//----------------------------------------------------------------------
// ��ȯ ����� ���� �ҷ�� �ϴµ�..
//----------------------------------------------------------------------
bool checkPossibleSummonMonsters(Monster* pMonster, Creature* pEnemy)
{
	//cout << "checkMasterSummonTiming: ";

	Assert(pMonster != NULL);

	return pMonster->hasNextMonsterSummonInfo();
}

bool checkEnemyTileNotAcidSwamp(Monster* pMonster, Creature* pEnemy)
{
	Zone* pZone = pEnemy->getZone();
	Assert( pZone != NULL );

	Tile& rTile = pZone->getTile( pEnemy->getX(), pEnemy->getY() );
	if ( rTile.getEffect( Effect::EFFECT_CLASS_ACID_SWAMP ) == NULL ) return true;

	return false;
}

bool checkEnemyOnAir(Monster* pMonster, Creature* pEnemy)
{
	if ( pEnemy == NULL ) return false;
	if ( pEnemy->getMoveMode() == Creature::MOVE_MODE_FLYING ) return true;
	return false;
}

bool checkEnemyOnSafeZone(Monster* pMonster, Creature* pEnemy)
{
	if ( pEnemy==NULL ) return false;
	return ( ( pEnemy->getZone()->getZoneLevel( pEnemy->getX(), pEnemy->getY() ) & SAFE_ZONE ) != 0 );
}
