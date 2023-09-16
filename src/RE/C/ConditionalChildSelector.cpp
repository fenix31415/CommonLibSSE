#include "RE/C/ConditionalChildSelector.h"

namespace RE
{
	bool ConditionalChildSelector::Validate(CombatBehaviorTreeNode* node)
	{
		using func_t = decltype(&ConditionalChildSelector::Validate);
		REL::Relocation<func_t> func{ RELOCATION_ID(46166, 0) };  // I do not know for AE
		return func(node);
	}

	uint32_t ConditionalChildSelector::SelectChild(CombatBehaviorTreeNode* node, uint32_t a_selected_ind)
	{
		using func_t = decltype(&ConditionalChildSelector::SelectChild);
		REL::Relocation<func_t> func{ RELOCATION_ID(46165, 0) };  // I do not know for AE
		return func(this, node, a_selected_ind);
	}
}
