//////////////////////////////////////////////////////////////////////////////
// Filename    : AlignmentManager.cpp
// Written By  :
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "AlignmentManager.h"
#include "Assert.h"
#include "DB.h"
#include <algorithm>

AlignmentManager* g_pAlignmentManager = NULL;

//////////////////////////////////////////////////////////////////////////////
// class AlignmentManager member methods
//////////////////////////////////////////////////////////////////////////////

AlignmentManager::AlignmentManager()
	throw()
{
	__BEGIN_TRY
	__END_CATCH
}

AlignmentManager::~AlignmentManager()
	throw()
{
	__BEGIN_TRY
	__END_CATCH
}

Alignment AlignmentManager::getAlignmentType(Alignment_t Alignment)
	throw()
{
	__BEGIN_TRY

	if (Alignment <= -10000)
	{
		return LESS_EVIL;
	}
	if (Alignment >= -10000 && Alignment < -7500) 
	{
		return LESS_EVIL;
	} 
	else if (Alignment >= -7500 && Alignment < -2500) 
	{
		return EVIL;
	} 
	else if (Alignment >= -2500 && Alignment < 2500) 
	{
		return NEUTRAL;
	}
	else if (Alignment >= 2500 && Alignment < 7500) 
	{
		return GOOD;
	} 
	else if (Alignment >= 7500 && Alignment <= 10000) 
	{
		return MORE_GOOD;
	} 
	else 
	{
		return MORE_GOOD;
	}
	
	__END_CATCH
}

int AlignmentManager::getMultiplier(Alignment_t AttackerAlignment, Alignment_t DefenderAlignment)
	throw()
{
	__BEGIN_TRY
	
	Alignment AAlignmentType = getAlignmentType(AttackerAlignment);
	Alignment DAlignmentType = getAlignmentType(DefenderAlignment);

	// �������� ������ Good, More Good �̸�
	if (AAlignmentType >= GOOD) 
	{
		// �������� ������ GOOD, More Good �̸�
		if (DAlignmentType >= GOOD) 
		{
			// �������� ������ ���� ���̸� -2
			if (AttackerAlignment > DefenderAlignment) 
			{
				return -200;
			} 
			// �������� ������ ���� ���̸� -3
			else if (AttackerAlignment <= DefenderAlignment) 
			{
				return -300;
			}
		} 
		// �������� ������ NEUTRAL �̸�,
		else if (DAlignmentType == NEUTRAL) 
		{
			return -100;
		} 
		// �������� ������ Evil, Less Evil �̸�,
		else if (DAlignmentType <= EVIL) {
			return 200;
		}
	} 
	else if (getAlignmentType(AttackerAlignment) == NEUTRAL) 
	{
		// �������� ������ GOOD, More Good �̸�
		if (DAlignmentType >= GOOD) 
		{
			return -300;
		} 
		// �������� ������ NEUTRAL �̸�,
		else if (DAlignmentType == NEUTRAL) 
		{
			// �������� ������ ���� ���̸� -1
			if (AttackerAlignment > DefenderAlignment) 
			{
				return -100;
			} 
			// �������� ������ ���� ���̸� -2
			else if (AttackerAlignment <= DefenderAlignment) 
			{
				return -200;
			}
		} 
		// �������� ������ Evil, Less Evil �̸�,
		else if (DAlignmentType <= EVIL) 
		{
			return 100;
		}
	} 
	else if (getAlignmentType(AttackerAlignment) <= EVIL) 
	{
		// �������� ������ GOOD, More Good �̸�
		if (DAlignmentType >= GOOD) 
		{
			return -300;
		} 
		// �������� ������ NEUTRAL �̸�,
		else if (DAlignmentType == NEUTRAL) 
		{
			return -200;
		} 
		// �������� ������ Evil, Less Evil �̸�,
		else if (DAlignmentType <= EVIL) 
		{
			// �������� ������ ���� ���̸� 2
			if (AttackerAlignment > DefenderAlignment) 
			{
				return 200;
			} 
			// �������� ������ ���� ���̸� 1
			else if (AttackerAlignment <= DefenderAlignment) {
				return 100;
			}
		}
	} 
	else 
	{
		return -300;
	}

	return -300;

	__END_CATCH
}

BYTE AlignmentManager::getDropItemNum(Alignment_t Alignment, bool isPK)
	throw()
{
	__BEGIN_TRY

	int Count = 0;

	if (Alignment > -10000 && Alignment < -7500) 
	{
		Count = 2;
	}
	else if (Alignment >= -7500 && Alignment < -2500) 
	{
		Count = 1;
	}
	else if (Alignment == -10000) 
	{
		Count = 3;
	}

	/*
	��� ������ ���� �� �� ������, ������ ���� ������ ������� �����߸���
	���� �߻��ϱ� �����ߴ�. PCManager.cpp�� killCreature() �κ���
	�ּ�� � �����ٰ� ������ ���� �ִ� ��� ���� �� �����,
	�ϴ� ������ ���� ������ ������� �����߸��� �ʰ� �ϱ� ��ؼ� �� �κ��
	�ּ�ó���Ѵ�. -- 2001.12.25 �輺��
	int Percent = getDropBonusPercentage(Alignment);

	if (isPK) 
	{
		Count = max(0, Count - 1);
		Percent = Percent/2;
	}

	Count = max(0, Count);
	Count = min(5, Count);

	if (Random(1, 100) < Percent) 
	{
		Count++;
	}
	*/

	return (BYTE)Count;

	__END_CATCH
}

BYTE AlignmentManager::getDropBonusPercentage(Alignment_t Alignment)
	throw()
{
	__BEGIN_TRY
	return 0;

	int Percent = (10000 - Alignment) / 400;

	Percent = max(0, Percent);
	Percent = min(50, Percent);

	return (BYTE)Percent;

	__END_CATCH
}

BYTE AlignmentManager::getMoneyDropPenalty(Alignment_t Alignment)
	throw()
{
	__BEGIN_TRY

	BYTE Penalty = 0;

	if (Alignment == 10000) 
	{
		Penalty = 0;
	}
	else if (Alignment >=  7500  && Alignment < 10000) 
	{
		Penalty = 1;
	} 
	else if (Alignment >=  2500  && Alignment <  7500) 
	{
		Penalty = 2;
	}
	else if (Alignment >= -2500  && Alignment <  2500) 
	{
		Penalty = 4;
	} 
	else if (Alignment >= -7500  && Alignment < -2500) 
	{
		Penalty = 8;
	}
	else if (Alignment >= -10000 && Alignment < -7500) 
	{
		Penalty = 16;
	} 
	else 
	{
		Penalty = 32;
	}

	return Penalty;

	__END_CATCH
}

string AlignmentManager::toString() const
	throw()
{
	__BEGIN_TRY
	
	StringStream msg;
	msg << "AlignmentManager ("
			<< ")";
	return msg.toString();

	__END_CATCH
}


