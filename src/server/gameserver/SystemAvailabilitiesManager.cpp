#include "SystemAvailabilitiesManager.h"
#include "DB.h"
#include "Assert.h"

void SystemAvailabilitiesManager::load() throw(Error)
{
	__BEGIN_TRY

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pResult = pStmt->executeQuery("SELECT * FROM SystemAvailabilities");

		while( pResult->next() )
		{
			int ID = pResult->getInt(1);
			bool Avail = pResult->getInt(2) != 0;

			if ( ID == OpenDegreeID )
			{
				m_ZoneOpenDegree = pResult->getInt(2);
				continue;
			}

			if ( ID == SkillLimitID )
			{
				m_SkillLevelLimit= pResult->getInt(2);
				continue;
			}

			if ( ID >= (int)SYSTEM_MAX )
			{
				cout << "SystemAvailabilitiesManager::load() : Invalid System Kind!" << ID << endl;
				Assert(false);
			}

			SystemKind kind = (SystemKind)ID;
			setAvailable( kind, Avail );
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	if ( m_pAvailabilitiesPacket == NULL ) m_pAvailabilitiesPacket = new GCSystemAvailabilities();
	m_pAvailabilitiesPacket->setFlag( (DWORD)m_SystemFlags.to_ulong() );
	m_pAvailabilitiesPacket->setOpenDegree( m_ZoneOpenDegree );
	m_pAvailabilitiesPacket->setSkillLimit( m_SkillLevelLimit );
	m_bEdited = false;

	__END_CATCH
}
