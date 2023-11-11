#include "RE/C/CombatBehaviorNode.h"

namespace RE
{
	bool CombatBehaviorNode::Validate(CombatBehaviorTreeNode* node)
	{
		using func_t = decltype(&CombatBehaviorNode::Validate);
		REL::Relocation<func_t> func{ RELOCATION_ID(46092, 0) };  // I do not know for AE
		return func(node);
	}
}
