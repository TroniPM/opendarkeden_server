//////////////////////////////////////////////////////////////////////////////
// Filename    : CGNPCAskAnswer.cpp
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "CGNPCAskAnswer.h"

#ifdef __GAME_SERVER__
	#include "GamePlayer.h"
	#include "NPC.h"
	#include <fstream>

	#include "quest/TriggerManager.h"
	#include "quest/Trigger.h"
	#include "quest/Condition.h"
	#include "quest/Action.h"

	#include "Gpackets/GCNPCResponse.h"
#endif

//////////////////////////////////////////////////////////////////////////////
// �÷��̾ NPC�� Ŭ���� ����, Ŭ���̾�Ʈ�� CGNPCAskAnswer ��Ŷ�
// ������ �����Ѵ�.  ������ �� ��Ŷ� �ڵ鸵�� ��,
// NPC�� CONDITION_TALKED_BY ����� �÷��װ� ��� �����,
// Ʈ���Ÿ� Ž���ϸ鼭 ������ Ʈ���Ÿ� ã�Ƽ� ������ �׼�� �����Ѵ�.
//////////////////////////////////////////////////////////////////////////////
void CGNPCAskAnswerHandler::execute (CGNPCAskAnswer* pPacket , Player* pPlayer)
	 throw (ProtocolException , Error)
{
	__BEGIN_TRY __BEGIN_DEBUG_EX

#ifdef __GAME_SERVER__

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
	Creature*   pPC         = pGamePlayer->getCreature();
	Creature*   pCreature   = NULL;

	if (pPC == NULL) return;

	Zone* pZone = pPC->getZone();

	if (pZone == NULL) return; 

	/*
	try 
	{
		pCreature = pZone->getCreature(pPacket->getObjectID());
	} 
	catch (NoSuchElementException) 
	{
		//cout << "���� NPC ����~" << endl;
		pCreature = NULL;
	}
	*/
	//cout << pPacket->toString().c_str() << endl;

	// NoSuch���. by sigi. 2002.5.2
	pCreature = pZone->getCreature(pPacket->getObjectID());

	if (pCreature == NULL || !pCreature->isNPC())
	{
		GCNPCResponse okpkt;
		pPlayer->sendPacket(&okpkt);

		//cout << okpkt.toString().c_str() << endl;

		return;
	}

	NPC* pNPC = dynamic_cast<NPC*>(pCreature);

	COND_ANSWERED_BY cond;
	cond.ScriptID = pPacket->getScriptID();
	cond.AnswerID = pPacket->getAnswerID();

	// get NPC's trigger manager
	const TriggerManager & triggerManager = pNPC->getTriggerManager();

	// check main condition
	if (triggerManager.hasCondition(Condition::CONDITION_ANSWERED_BY))
	{
		const list<Trigger*> & triggers = triggerManager.getTriggers();
		for (list<Trigger*>::const_iterator itr = triggers.begin() ; itr != triggers.end() ; itr ++)
		{
			Trigger* pTrigger = *itr;
			if (pTrigger == NULL) 
			{ 
				//cout << "*** shit trigger is NULL ***"; 
				return; 
			}

			// check all condition after check main condition
			if (pTrigger->hasCondition(Condition::CONDITION_ANSWERED_BY) && 
			     pTrigger->isAllSatisfied(Trigger::PASSIVE_TRIGGER , pNPC , pPC, (void*)&cond)) 
			{
				// ���ʷ� �߰ߵ� Ʈ���Ÿ� ������ ��� break �Ѵ�.
				pTrigger->activate(pNPC , pPC);
				break;
			}
		}
	}

#endif

	__END_DEBUG_EX __END_CATCH
}
