#pragma once

#include "RE/C/ChildSelectorBase.h"

namespace RE
{
	class CombatBehaviorTreeNode;

	class NextChildSelector : public ChildSelectorBase
	{
	public:
		static bool Validate(CombatBehaviorTreeNode*) { return true; }

		uint32_t GetSelected() const { return selected_ind; }
		uint32_t SelectChild(CombatBehaviorTreeNode* node, uint32_t selected_ind);
		void     SetSelected(uint32_t ind) { selected_ind = ind; }

		// members
		uint32_t selected_ind; // 0
	};
	static_assert(sizeof(NextChildSelector) == 0x4);
}
