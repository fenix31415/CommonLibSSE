#pragma once

#include "RE/C/ChildSelectorBase.h"

namespace RE
{
	class CombatBehaviorTreeNode;

	class WeightedRandomChildSelector : public ChildSelectorBase
	{
	public:
		static bool Validate(CombatBehaviorTreeNode* node);

		uint32_t GetSelected() const { return selected_ind; }
		uint32_t SelectChild(CombatBehaviorTreeNode* node, uint32_t selected_ind);
		void     SetSelected(uint32_t ind) { selected_ind = ind; }

		//members
		uint32_t tried_mask;    // 00
		uint32_t selected_ind;  // 04
	};
	static_assert(sizeof(WeightedRandomChildSelector) == 0x8);
}
