#include "RE/C/CombatBehaviorParallel.h"

#include "RE/C/CombatBehaviorTreeNode.h"

namespace RE
{
	bool RE::CombatBehaviorParallel::Validate(CombatBehaviorTreeNode* node)
	{
		return CombatBehaviorNode::Validate(node);
	}

	void CombatBehaviorParallel::Abort()
	{
		using func_t = decltype(&CombatBehaviorParallel::Abort);
		REL::Relocation<func_t> func{ RELOCATION_ID(46170, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorParallel::Enter()
	{
		using func_t = decltype(&CombatBehaviorParallel::Enter);
		REL::Relocation<func_t> func{ RELOCATION_ID(46168, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorParallel::Update()
	{
		using func_t = decltype(&CombatBehaviorParallel::Enter);
		REL::Relocation<func_t> func{ RELOCATION_ID(46169, 0) };  // I do not know for AE
		return func(this);
	}
}
