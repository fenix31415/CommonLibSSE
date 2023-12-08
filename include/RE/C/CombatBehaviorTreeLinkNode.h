#pragma once

#include "RE/C/CombatBehaviorTreeNode.h"

namespace RE
{
	class CombatBehaviorTreeLinkNode : public CombatBehaviorTreeNode
	{
	public:
		void                 Enter(CombatBehaviorThread* thread) override;
		bool                 Validate(CombatBehaviorTreeNode* node) const override;
		const BSFixedString& GetType() const override;

		// members
		BSFixedString link_name;
	};
	static_assert(sizeof(CombatBehaviorTreeLinkNode) == 0x30);
}
