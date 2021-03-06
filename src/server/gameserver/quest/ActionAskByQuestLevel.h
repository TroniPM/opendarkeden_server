//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionAskByQuestLevel.h
// Written By  : excel96
// Description : 
// Creature가 PC에게 질문을 던진다. 이 대사는 NPC 대화창에 출력된다.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_ASK_BY_QUEST_LEVEL_H__
#define __ACTION_ASK_BY_QUEST_LEVEL_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionAskByQuestLevel
//////////////////////////////////////////////////////////////////////////////

class ActionAskByQuestLevel : public Action 
{
public:
	virtual ActionType_t getActionType() const throw() { return ACTION_ASK_BY_QUEST_LEVEL; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

public:
	ScriptID_t getScriptID( int index ) const throw() { return m_ScriptID[index]; }
	void setScriptID( int index, ScriptID_t scriptID ) throw() { m_ScriptID[index] = scriptID; }

private:
	ScriptID_t m_ScriptID[5];   // 말할 대사 아이디
};


//////////////////////////////////////////////////////////////////////////////
// class ActionAskByQuestLevelFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionAskByQuestLevelFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_ASK_BY_QUEST_LEVEL; }
	virtual string getActionName() const throw() { return "AskByQuestLevel"; }
	virtual Action* createAction() const throw() { return new ActionAskByQuestLevel(); }
};
#endif
