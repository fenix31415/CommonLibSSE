#include "RE/C/CombatBehaviorSequence.h"

#include "RE/C/CombatBehaviorThread.h"
#include "RE/C/CombatBehaviorTreeNode.h"
#include "RE/T/TLSData.h"

namespace RE
{
	void CombatBehaviorSequence::Enter()
	{
		using func_t = decltype(&CombatBehaviorSequence::Enter);
		REL::Relocation<func_t> func{ RELOCATION_ID(46148, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorSequence::Update()
	{
		auto thread = GetStaticTLSData()->combatAIThread;
		++ind;
		if (thread->fail_state == RE::CombatBehaviorThread::FailState::kFailed || ind >= thread->active_node->children.size())
			thread->Ascend();
		else
			thread->Descend(ind);
	}
}
