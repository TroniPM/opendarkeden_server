//////////////////////////////////////////////////////////////////////////////
// Filename    : CLCreatePCHandler.cc
// Written By  :
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "CLCreatePC.h"

#ifdef __LOGIN_SERVER__
	#include "LoginPlayer.h"
	#include "PCSlayerInfo.h"
	#include "Assert.h"
	#include "GameServerInfoManager.h"
	#include "DB.h"
	#include <list>
	#include "Lpackets/LCCreatePCOK.h"
	#include "Lpackets/LCCreatePCError.h"
	#include <string.h>

	#include "chinabilling/CBillingInfo.h"
#endif

bool isAvailableID(const char* pID);

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void CLCreatePCHandler::execute (CLCreatePC* pPacket , Player* pPlayer)
	 throw (ProtocolException , Error)
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
		
#ifdef __LOGIN_SERVER__

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

	LoginPlayer*    pLoginPlayer = dynamic_cast<LoginPlayer*>(pPlayer);
	Statement*      pStmt        = NULL;
	Result*         pResult      = NULL;
	LCCreatePCError lcCreatePCError;
	WorldID_t		WorldID      = pLoginPlayer->getWorldID();

#ifdef __CONNECT_CBILLING_SYSTEM__
	if ( pLoginPlayer->isCBillingVerified() )
	{
		if ( !pLoginPlayer->isPayPlayer() )
		{
			lcCreatePCError.setErrorID( CANNOT_CREATE_PC_BILLING );
			pLoginPlayer->sendPacket( &lcCreatePCError );
			return;
		}
	}
	else
	{
		lcCreatePCError.setErrorID( CANNOT_AUTHORIZE_BILLING );
		pLoginPlayer->sendPacket( &lcCreatePCError );
		return;
	}
#endif

	try 
	{
		pStmt = g_pDatabaseManager->getConnection( WorldID )->createStatement();

		// 시스템에서 사용하거나, 금지된 이름은 아닌기 검증한다.
		// NONE, ZONE***, INV***, QUICK...
		//string text = pPacket->getName();

		if (!isAvailableID( pPacket->getName().c_str() ))
		{
			lcCreatePCError.setErrorID(ALREADY_REGISTER_ID);
			throw DuplicatedException("이미 존재하는 아이디입니다.");
		}

		/*
		list<string>::const_iterator itr = InvalidTokenList.begin();
		for (; itr != InvalidTokenList.end(); itr++)
		{
			if (text.find(*itr) != string::npos)
			{
				lcCreatePCError.setErrorID(ALREADY_REGISTER_ID);
				throw DuplicatedException("이미 존재하는 아이디입니다.");
			}
		}
		*/

		// 이미 존재하는 캐릭터 이름이 아닌지 검증한다.
		///*
		pResult = pStmt->executeQuery("SELECT Name FROM Slayer WHERE Name = '%s'", pPacket->getName().c_str());
		if (pResult->getRowCount() != 0) 
		{
			lcCreatePCError.setErrorID(ALREADY_REGISTER_ID);
			throw DuplicatedException("이미 존재하는 아이디입니다.");
		}

		// 해당 슬랏에 캐릭터가 이미 있지는 않은지 검증한다.
		pResult = pStmt->executeQuery("SELECT Name FROM Slayer WHERE PlayerID ='%s' and Slot ='%s'", pLoginPlayer->getID().c_str(), Slot2String[pPacket->getSlot()].c_str() );
		if (pResult->getRowCount() != 0) 
		{
			lcCreatePCError.setErrorID(ALREADY_REGISTER_ID);
			throw DuplicatedException("이미 존재하는 아이디입니다.");
		}
		//*/
		// 두 쿼리를 하나로. 2002. 7. 13 by sigi. 이거 안좋다. - -;
		/*
		pResult = pStmt->executeQuery("SELECT Name FROM Slayer WHERE Name='%s' OR PlayerID='%s' AND Slot='%s'", 
											pPacket->getName().c_str(), 
											pLoginPlayer->getID().c_str(), 
											Slot2String[pPacket->getSlot()].c_str() );

		if (pResult->getRowCount() != 0) 
		{
			lcCreatePCError.setErrorID(ALREADY_REGISTER_ID);
			throw DuplicatedException("이미 존재하는 아이디입니다.");
		}
		*/


		// 잘못된 능력치를 가지고 캐릭터를 생성하려 하는 것은 아닌지 검증한다.
		

		bool bInvalidAttr = false;
		int  nSTR         = pPacket->getSTR();
		int  nSTRExp      = 0;
		int  nSTRGoalExp  = 0;
		int  nDEX         = pPacket->getDEX();
		int  nDEXExp      = 0;
		int  nDEXGoalExp  = 0;
		int  nINT         = pPacket->getINT();
		int  nINTExp      = 0;
		int  nINTGoalExp  = 0;

		//int  Rank         = 1;
		//int  RankExp      = 0;

		// 
		static int  RankGoalExpSlayer  = -1;
		static int  GoalExpVampire  = -1;	// by sigi. 2002.12.20
		static int  RankGoalExpVampire  = -1;
		static int  GoalExpOusters = -1;
		static int  RankGoalExpOusters = -1;

		if (RankGoalExpSlayer==-1)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM RankEXPInfo WHERE Level=1 AND RankType=0");
			if (pResult->next()) RankGoalExpSlayer = pResult->getInt(1);
		}

		if (GoalExpVampire==-1)	// by sigi. 2002.12.20
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM VampEXPBalanceInfo WHERE Level=1");
			if (pResult->next()) GoalExpVampire = pResult->getInt(1);
		}

		if (GoalExpOusters==-1)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM OustersEXPBalanceInfo WHERE Level=1");
			if (pResult->next()) GoalExpOusters = pResult->getInt(1);
		}

		if (RankGoalExpVampire==-1)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM RankEXPInfo WHERE Level=1 AND RankType=1");
			if (pResult->next()) RankGoalExpVampire = pResult->getInt(1);
		}

		if (RankGoalExpOusters==-1)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM RankEXPInfo WHERE Level=1 AND RankType=2");
			if (pResult->next()) RankGoalExpOusters = pResult->getInt(1);
		}

		if (pPacket->getRace() == RACE_SLAYER)
		{
			if (nSTR < 5 || nSTR > 20)  bInvalidAttr = true;
			if (nDEX < 5 || nDEX > 20)  bInvalidAttr = true;
			if (nINT < 5 || nINT > 20)  bInvalidAttr = true;
			if (nSTR + nDEX + nINT > 30) bInvalidAttr = true;

			//cout << "Slayer: " << nSTR << ", " << nDEX << ", " << nINT << endl;
		}
		else if ( pPacket->getRace() == RACE_VAMPIRE )	// vampire인 경우. 무조건 20. by sigi. 2002.10.31
		{
			if (nSTR != 20
				|| nDEX != 20
				|| nINT != 20) 
			{
				bInvalidAttr = true;
			}
			else
			{
				// 정상적인 vampire인 경우
				// Slayer의 능력치를 다시 설정해줘야 한다. -_-;
				// by sigi. 2002.11.7
				nSTR = 5 + rand()%16;	// 5~20
				nDEX = 5 + rand()%(21-nSTR);
				nINT = 30 - nSTR - nDEX;

				pPacket->setSTR(nSTR);
				pPacket->setDEX(nDEX);
				pPacket->setINT(nINT);
			}
			// 

			//cout << "Vampire: " << nSTR << ", " << nDEX << ", " << nINT << endl;
		}
		else if ( pPacket->getRace() == RACE_OUSTERS )
		{
			if ( nSTR + nDEX + nINT != 45 )
				bInvalidAttr = true;
		}

		if (bInvalidAttr)
		{
			SAFE_DELETE(pStmt);
			throw InvalidProtocolException("CLCreatePCHandler::too large character attribute");
		}

		// 모든 검사를 만족했다면 이제 캐릭터를 생성한다.
		ServerGroupID_t CurrentServerGroupID = pPlayer->getServerGroupID();

		// 우헤헤.. 일단 쿼리를 줄일려고 static으로 삽질을 했다.
		// 나중에 아예 로그인 서버 뜰때에 경험치 table들을 loading해 두도록해야할 것이다. 2002.7.13 by sigi
		static int STRGoalExp[100] = { 0, }; 
		static int STRAccumExp[100] = { 0, };
		static int DEXGoalExp[100] = { 0, }; 
		static int DEXAccumExp[100] = { 0, };
		static int INTGoalExp[100] = { 0, };
		static int INTAccumExp[100] = { 0, };

		nSTRGoalExp = STRGoalExp[nSTR];
		if (nSTRGoalExp==0)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM STRBalanceInfo WHERE Level = %d", nSTR);
			if (pResult->next()) nSTRGoalExp = STRGoalExp[nSTR] = pResult->getInt(1);
		}

		nSTRExp = STRAccumExp[nSTR-1];
		if (nSTRExp==0)
		{
			pResult = pStmt->executeQuery("SELECT AccumExp FROM STRBalanceInfo WHERE Level = %d", nSTR - 1);
			if (pResult->next()) nSTRExp = STRAccumExp[nSTR-1] = pResult->getInt(1);
		}

		nDEXGoalExp = DEXGoalExp[nDEX];
		if (nDEXGoalExp==0)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM DEXBalanceInfo WHERE Level = %d", nDEX);
			if (pResult->next()) nDEXGoalExp = DEXGoalExp[nDEX] = pResult->getInt(1);
		}

		nDEXExp = DEXAccumExp[nDEX-1];
		if (nDEXExp==0)
		{
			pResult = pStmt->executeQuery("SELECT AccumExp FROM DEXBalanceInfo WHERE Level = %d", nDEX - 1);
			if (pResult->next()) nDEXExp = DEXAccumExp[nDEX-1] = pResult->getInt(1);
		}

		nINTGoalExp = INTGoalExp[nINT];
		if (nINTGoalExp==0)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM INTBalanceInfo WHERE Level = %d", nINT);
			if (pResult->next()) nINTGoalExp = INTGoalExp[nINT] = pResult->getInt(1);
		}

		nINTExp = INTAccumExp[nINT-1];
		if (nINTExp==0)
		{
			pResult = pStmt->executeQuery("SELECT AccumExp FROM INTBalanceInfo WHERE Level = %d", nINT - 1);
			if (pResult->next()) nINTExp = INTAccumExp[nINT-1] = pResult->getInt(1);
		}

		// 일단 복장은 없고.. 남/녀 구분만..
		DWORD slayerShape = (pPacket->getSex()==1? 1 : 0);
		DWORD vampireShape = slayerShape;

		slayerShape |= (pPacket->getHairStyle() << PCSlayerInfo::SLAYER_BIT_HAIRSTYLE1);

		Color_t	HelmetColor = 0;
		Color_t JacketColor = 0;
		Color_t	PantsColor  = 0;
		Color_t	WeaponColor = 0;
		Color_t	ShieldColor = 0;

		/*
		StringStream slayerSQL;
		slayerSQL << "INSERT INTO Slayer ("
			<< " Race, Name, PlayerID, Slot, ServerGroupID, Active,"
			<< " Sex, HairStyle, HairColor, SkinColor, Phone, "
			<< " STR, STRExp, STRGoalExp, DEX, DEXExp, DEXGoalExp, INTE, INTExp, INTGoalExp, HP, CurrentHP, MP, CurrentMP,"
			<< " ZoneID, XCoord, YCoord, Sight, Gold, Alignment,"
			<< " Shape, HelmetColor, JacketColor, PantsColor, WeaponColor, ShieldColor,"
			<< " creation_date) VALUES ('"
			<< "SLAYER" << "', '"
			<< pPacket->getName() << "', '"
			<< pLoginPlayer->getID() << "', '"
			<< Slot2String[pPacket->getSlot()] << "', "
			<< (int)CurrentServerGroupID << " , "
			<< "'ACTIVE', '"
			<< Sex2String[pPacket->getSex()] << "', '"
			<< HairStyle2String[pPacket->getHairStyle()] << "', "
			<< (int)pPacket->getHairColor() << ", "
			<< (int)pPacket->getSkinColor() << ", '"
			<< (int)0 << "', "
			<< (int)pPacket->getSTR() << ", "
			<< nSTRExp << ", "
			<< nSTRGoalExp << ", "
			<< (int)pPacket->getDEX() << ", "
			<< nDEXExp << ", "
			<< nDEXGoalExp << ", "
			<< (int)pPacket->getINT() << ", "
			<< nINTExp << ", "
			<< nINTGoalExp << ", "
			<< (int)pPacket->getSTR()*2 << ","
			<< (int)pPacket->getSTR()*2 << ","
			<< (int)pPacket->getINT()*2 << ","
			<< (int)pPacket->getINT()*2 << ","
			<< "2101, 65, 45, 13, 0, 7500, "
			<< slayerShape << ", "
			<< (int)HelmetColor << ", "
			<< (int)JacketColor << ", "
			<< (int)PantsColor << ", "
			<< (int)WeaponColor << ", "
			<< (int)ShieldColor << ", "
			<< "now() "
			<< ")";

		StringStream vampireSQL;
		vampireSQL << "INSERT INTO Vampire ("
			<< " Name, PlayerID, Slot, ServerGroupID, Active,"
			<< " Sex, HairColor, SkinColor,"
			<< " STR, DEX, INTE, HP, CurrentHP,"
			<< " ZoneID, XCoord, YCoord, Sight, Alignment, Exp, GoalExp, Shape) VALUES ('"
			<< pPacket->getName() << "', '"
			<< pLoginPlayer->getID() << "', '"
			<< Slot2String[pPacket->getSlot()] << "', "
			<< (int)CurrentServerGroupID << " , "
			<< "'ACTIVE', '"
			<< Sex2String[pPacket->getSex()] << "', "
			<< (int)pPacket->getHairColor() << ", "
			<< (int)pPacket->getSkinColor() << ", "
			<< "20, 20, 20, 50, 50, "
			<< "2020, 233, 55, 13, 7500, 0, 125, "
			<< vampireShape
			<< ")";

		pStmt->executeQuery(slayerSQL.toString());
		pStmt->executeQuery(vampireSQL.toString());
		*/

		// 캐릭터 생성시에 뱀파이어를 선택할 수 있다.
		// by sigi. 2002.10.31
		string race;
		switch ( pPacket->getRace() )
		{
			case RACE_SLAYER:
				race = "SLAYER";
				break;
			case RACE_VAMPIRE:
				race = "VAMPIRE";
				break;
			case RACE_OUSTERS:
				race = "OUSTERS";
				break;
			default:
				lcCreatePCError.setErrorID(ETC_ERROR);
				pLoginPlayer->sendPacket(&lcCreatePCError); // 클라이언트에게 PC 생성 실패 패킷을 날린다.
				return;
		}

		pStmt->executeQuery(
				"INSERT INTO Slayer (Race, Name, PlayerID, Slot, ServerGroupID, Active, Sex, HairStyle, HairColor, SkinColor, Phone, STR, STRExp, STRGoalExp, DEX, DEXExp, DEXGoalExp, INTE, INTExp, INTGoalExp, Rank, RankExp, RankGoalExp, HP, CurrentHP, MP, CurrentMP, ZoneID, XCoord, YCoord, Sight, Gold, Alignment, Shape, HelmetColor, JacketColor, PantsColor, WeaponColor, ShieldColor, creation_date) VALUES ('%s', '%s', '%s', '%s', %d, 'ACTIVE', '%s', '%s', %d, %d, 0, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, 12, 237, 138, 13, 0, 7500, %d, %d, %d, %d, %d, %d, now())",
				race.c_str(),
				pPacket->getName().c_str(), 
				pLoginPlayer->getID().c_str(), 
				Slot2String[pPacket->getSlot()].c_str(), 
				(int)CurrentServerGroupID,
				Sex2String[pPacket->getSex()].c_str(), 
				HairStyle2String[pPacket->getHairStyle()].c_str(), 
				(int)pPacket->getHairColor(), 
				(int)pPacket->getSkinColor(),
				(int)pPacket->getSTR(), nSTRExp, nSTRGoalExp, 
				(int)pPacket->getDEX(), nDEXExp, nDEXGoalExp, 
				(int)pPacket->getINT(), nINTExp, nINTGoalExp,
				1, 0, RankGoalExpSlayer,
				(int)pPacket->getSTR()*2,
				(int)pPacket->getSTR()*2,
				(int)pPacket->getINT()*2,
				(int)pPacket->getINT()*2,
				slayerShape,
				(int)HelmetColor,
				(int)JacketColor,
				(int)PantsColor,
				(int)WeaponColor,
				(int)ShieldColor);

		// 생성 위치 변경. by sigi. 2002.10.31
		// 아우스터스로의 종족간 변신이 없으므로 둘중에 하나만 만든다.
		// 근데 왠지 종족간 변신이 들어갈지도 모른다는 불길한 예간이 들고
		// 항상 그런 예감들은 맞아 왔기때문에 언젠가 이 주석을 보고 둘다 풀어주는게....으아~~
		if (  pPacket->getRace() != RACE_OUSTERS )
		{
			pStmt->executeQuery(
					"INSERT INTO Vampire ( Name, PlayerID, Slot, ServerGroupID, Active, Sex, SkinColor, STR, DEX, INTE, HP, CurrentHP, ZoneID, XCoord, YCoord, Sight, Alignment, Exp, GoalExp, Rank, RankExp, RankGoalExp, Shape, CoatColor) VALUES ( '%s', '%s', '%s', %d, 'ACTIVE', '%s', %d, 20, 20, 20, 50, 50, 1003, 62, 64, 13, 7500, 0, %d, 1, 0, %d, %d, 377 )",
					pPacket->getName().c_str(),
					pLoginPlayer->getID().c_str(),
					Slot2String[pPacket->getSlot()].c_str(),
					(int)CurrentServerGroupID,
					Sex2String[pPacket->getSex()].c_str(),
					(int)pPacket->getSkinColor(),
					GoalExpVampire,	// by sigi. 2002.12.20
					RankGoalExpVampire,
					vampireShape);
		} else
		{
			pStmt->executeQuery(
					"INSERT INTO Ousters ( Name, PlayerID, Slot, ServerGroupID, Active, Sex, STR, DEX, INTE, BONUS, HP, CurrentHP, MP, CurrentMP, ZoneID, XCoord, YCoord, Sight, Alignment, Exp, GoalExp, Rank, RankExp, RankGoalExp, CoatColor, HairColor, ArmColor, BootsColor ) Values ( '%s', '%s', '%s', %d, 'ACTIVE', 'FEMALE', %d, %d, %d, 0, 50, 50, 50, 50, 1311, 24, 73, 13, 7500, 0, %d, 1, 0,	%d, 377, %d, 377, 377 )",
					pPacket->getName().c_str(),
					pLoginPlayer->getID().c_str(),
					Slot2String[pPacket->getSlot()].c_str(),
					(int)CurrentServerGroupID,
					(int)pPacket->getSTR(),
					(int)pPacket->getDEX(),
					(int)pPacket->getINT(),
					GoalExpOusters,
					RankGoalExpOusters,
					(int)pPacket->getHairColor() );
		}

		if (pPacket->getRace()==RACE_SLAYER)
		{
			pStmt->executeQuery("INSERT IGNORE INTO FlagSet (OwnerID, FlagData) VALUES ('%s','11110010001')", pPacket->getName().c_str());
		}
		else
		{
			pStmt->executeQuery("INSERT IGNORE INTO FlagSet (OwnerID, FlagData) VALUES ('%s','00000000001')", pPacket->getName().c_str());
		}

		// 클라이언트에게 PC 생성 성공 패킷을 날린다.
		LCCreatePCOK lcCreatePCOK;
		pLoginPlayer->sendPacket(&lcCreatePCOK);
		pLoginPlayer->setPlayerStatus(LPS_WAITING_FOR_CL_GET_PC_LIST);

		SAFE_DELETE(pStmt);
	} 
	catch (DuplicatedException & de) 
	{
		SAFE_DELETE(pStmt);
		pLoginPlayer->sendPacket(&lcCreatePCError); // 클라이언트에게 PC 생성 실패 패킷을 날린다.
	} 
	catch (SQLQueryException & sqe) 
	{
		SAFE_DELETE(pStmt);
		lcCreatePCError.setErrorID(ETC_ERROR);
		pLoginPlayer->sendPacket(&lcCreatePCError); // 클라이언트에게 PC 생성 실패 패킷을 날린다.
	}

#endif

	__END_DEBUG_EX __END_CATCH
}

bool
isAvailableID(const char* pID)
{
	const int maxInvalidID = 10;
	static const char* invalidID[maxInvalidID] =
	{
		"NONE",
		"관리자",
		"도우미",
		"담당자",
		"운영",
		"기획자",
		"개발자",
		"테스터",
		"직원",
		"GM"
	};
	
	// 좀 빠를까. - -; 2002.7.13 by sigi.
	for (int i=0; i<maxInvalidID; i++)
	{
		if (strstr(pID, invalidID[i])!=NULL) 
		{
			return false;
		}
	}

	return true;
}
