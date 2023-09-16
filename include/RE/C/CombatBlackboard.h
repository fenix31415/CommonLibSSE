#pragma once

#include "RE/B/BSTHashMap.h"
#include "RE/C/CombatBehaviorStack.h"

namespace RE
{
	class CombatBlackboardMemberBase;

	class CombatBlackboard
	{
	public:
		// members
		BSTHashMap<CombatBlackboardMemberBase*, uint32_t> keys_in_stack;  // 00
		CombatBehaviorStack                               stack;          // 30
		uint32_t                                          flags;          // 40 -- see CombatBlackboardFlag
		uint32_t                                          pad44;          // 44
	};
	static_assert(sizeof(CombatBlackboard) == 0x48);
}
