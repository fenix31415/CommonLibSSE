#include "RE/P/PriorityChildSelector.h"

namespace RE
{
	bool PriorityChildSelector::Validate(CombatBehaviorTreeNode* node)
	{
		using func_t = decltype(&PriorityChildSelector::Validate);
		REL::Relocation<func_t> func{ RELOCATION_ID(46154, 0) };  // I do not know for AE
		return func(node);
	}

	uint32_t PriorityChildSelector::SelectChild(CombatBehaviorTreeNode* node, uint32_t selected)
	{
		using func_t = decltype(&PriorityChildSelector::SelectChild);
		REL::Relocation<func_t> func{ RELOCATION_ID(46153, 0) };  // I do not know for AE
		return func(this, node, selected);
	}
}
