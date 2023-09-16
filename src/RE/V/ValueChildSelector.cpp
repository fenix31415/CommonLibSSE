#include "RE/V/ValueChildSelector.h"

namespace RE
{
	bool ValueChildSelector::Validate(CombatBehaviorTreeNode* node)
	{
		using func_t = decltype(&ValueChildSelector::Validate);
		REL::Relocation<func_t> func{ RELOCATION_ID(46164, 0) };  // I do not know for AE
		return func(node);
	}

	uint32_t ValueChildSelector::SelectChild(CombatBehaviorTreeNode* node, uint32_t a_selected_ind)
	{
		using func_t = decltype(&ValueChildSelector::SelectChild);
		REL::Relocation<func_t> func{ RELOCATION_ID(46163, 0) };  // I do not know for AE
		return func(this, node, a_selected_ind);
	}
}
