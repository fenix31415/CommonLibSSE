#pragma once

#include "RE/C/CombatBehavior.h"

namespace RE {

	class CombatBehaviorNode : public CombatBehavior
	{
	public:
		static bool Validate(CombatBehaviorTreeNode*);
	};
}
