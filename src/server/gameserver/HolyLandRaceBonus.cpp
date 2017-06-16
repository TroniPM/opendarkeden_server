#include "HolyLandRaceBonus.h"
#include "CastleInfoManager.h"

HolyLandRaceBonus* g_pHolyLandRaceBonus = NULL;

HolyLandRaceBonus::HolyLandRaceBonus()
{
	refresh();
}

HolyLandRaceBonus::~HolyLandRaceBonus()
{
}

void	
HolyLandRaceBonus::refresh()
	throw (Error)
{
	__BEGIN_TRY

	// ������� ������..
	clear();

	const map<ZoneID_t, CastleInfo*>& castleInfos = g_pCastleInfoManager->getCastleInfos();
	map<ZoneID_t, CastleInfo*>::const_iterator itr = castleInfos.begin();


	// ���� ���� ������� ���� ���ʽ��� ����Ѵ�.
	for (; itr!=castleInfos.end(); itr++)
	{
		CastleInfo* pCastleInfo = itr->second;

		if (pCastleInfo->getRace()==RACE_SLAYER)
		{
			const list<OptionType_t>& optionTypes = pCastleInfo->getOptionTypeList();
			m_SlayerOptionTypes.insert( m_SlayerOptionTypes.begin(), optionTypes.begin(), optionTypes.end() );
		}
		else if (pCastleInfo->getRace()==RACE_VAMPIRE)
		{
			const list<OptionType_t>& optionTypes = pCastleInfo->getOptionTypeList();
			m_VampireOptionTypes.insert( m_VampireOptionTypes.begin(), optionTypes.begin(), optionTypes.end() );
		}
		else
		{
			// ����
		}
	}

	__END_CATCH
}


