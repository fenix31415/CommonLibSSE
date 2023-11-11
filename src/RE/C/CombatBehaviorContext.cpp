#include "RE/C/CombatBehaviorContext.h"

#include "RE/C/CombatBehaviorTreeNode.h"

namespace RE
{
	bool CombatBehaviorContext::Validate(CombatBehaviorTreeNode* node)
	{
		return CombatBehaviorBranch::Validate(node);
	}
}
