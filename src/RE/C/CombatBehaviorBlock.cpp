#include "RE/C/CombatBehaviorBlock.h"

#include "RE/C/CombatBehaviorTreeNode.h"

namespace RE
{
	void CombatBehaviorBlock::Enter()
	{
		using func_t = decltype(&CombatBehaviorBlock::Enter);
		REL::Relocation<func_t> func{ RELOCATION_ID(46633, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorBlock::Exit()
	{
		using func_t = decltype(&CombatBehaviorBlock::Exit);
		REL::Relocation<func_t> func{ RELOCATION_ID(46635, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorBlock::Update()
	{
		using func_t = decltype(&CombatBehaviorBlock::Update);
		REL::Relocation<func_t> func{ RELOCATION_ID(46634, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatBehaviorBlock::Validate(CombatBehaviorTreeNode* node)
	{
		return CombatBehaviorBranch::Validate(node);
	}
}
