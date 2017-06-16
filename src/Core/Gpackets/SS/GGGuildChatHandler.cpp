//----------------------------------------------------------------------
//
// Filename    : GGGuildChatHandler.cpp
// Written By  : Reiot
// Description :
//
//----------------------------------------------------------------------

// include files
#include "GGGuildChat.h"

#ifdef __GAME_SERVER__

	#include "Player.h"
	#include "Creature.h"
	#include "GuildManager.h"
	#include "Guild.h"
	#include "PCFinder.h"
	#include "Gpackets/GCGuildChat.h"

#endif

//----------------------------------------------------------------------
// 
// GGGuildChatHander::execute()
// 
//----------------------------------------------------------------------
void GGGuildChatHandler::execute ( GGGuildChat * pPacket )
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
	__BEGIN_DEBUG
	
#ifdef __GAME_SERVER__

	// 길드의 현재 접속 중인 멤버를 가져온다.
	Guild* pGuild = g_pGuildManager->getGuild( pPacket->getGuildID() );

	if ( pGuild == NULL )
	{
		filelog( "GuildMissing.log", "[NoSuchGuild] GuildID : %d", (int)pPacket->getGuildID() );
		return;
	}

	// 길드 채팅 패킷을 만든다.
	GCGuildChat gcGuildChat;
	gcGuildChat.setSender( pPacket->getSender() );
	gcGuildChat.setColor( pPacket->getColor() );
	gcGuildChat.setMessage( pPacket->getMessage() );

	list<string> currentMembers = pGuild->getCurrentMembers();
	list<string>::const_iterator itr = currentMembers.begin();
	for ( ; itr != currentMembers.end() ; itr++ )
	{
		//g_pPCFinder->sendPacket( (*itr), &gcGuildChat );

		__ENTER_CRITICAL_SECTION((*g_pPCFinder))

		Creature* pCreature = g_pPCFinder->getCreature_LOCKED( (*itr) );
		if ( pCreature != NULL )
		{
			Player* pPlayer = pCreature->getPlayer();
			Assert( pPlayer != NULL );

			if (pPlayer->getSocket()!=NULL)
				pPlayer->sendPacket( &gcGuildChat );
		}

		__LEAVE_CRITICAL_SECTION((*g_pPCFinder))
	}


#endif
		
	__END_DEBUG
	__END_DEBUG_EX __END_CATCH
}
