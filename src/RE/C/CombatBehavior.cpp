#include "RE/C/CombatBehavior.h"

#include "RE/C/CombatBehaviorThread.h"
#include "RE/C/CombatBehaviorTreeNode.h"
#include "RE/T/TLSData.h"

namespace RE
{
	bool CombatBehavior::Validate(CombatBehaviorTreeNode* node)
	{
		return node->children.empty();
	}

	void CombatBehavior::Abort()
	{
		GetStaticTLSData()->combatAIThread->Ascend();
	}

	bool CombatBehavior::CheckTargetChanged()
	{
		using func_t = decltype(&CombatBehavior::CheckTargetChanged);
		REL::Relocation<func_t> func{ RELOCATION_ID(46089, 0) };  // I do not know for AE
		return func(this);
	}

	CombatBehaviorThread* CombatBehavior::CreateChildThread(uint32_t child_ind, bool isControlChild)
	{
		using func_t = decltype(&CombatBehavior::CreateChildThread);
		REL::Relocation<func_t> func{ RELOCATION_ID(46090, 0) };  // I do not know for AE
		return func(this, child_ind, isControlChild);
	}

	void CombatBehavior::StartChildThread(CombatBehaviorThread* thread, uint32_t child_ind, bool isControlChild)
	{
		using func_t = decltype(&CombatBehavior::StartChildThread);
		REL::Relocation<func_t> func{ RELOCATION_ID(46091, 0) };  // I do not know for AE
		return func(this, thread, child_ind, isControlChild);
	}

	void CombatBehavior::Update()
	{
		GetStaticTLSData()->combatAIThread->Ascend();
	}
}
