#pragma once

#include "RE/C/CombatBehaviorTreeWrapperNode.h"

namespace RE
{
	template <typename T>
	class CombatBehaviorTreeValueNode : public CombatBehaviorTreeWrapperNode
	{
	public:
		virtual T GetValue() = 0;
	};
	static_assert(sizeof(CombatBehaviorTreeValueNode<void*>) == 0x30);
}
