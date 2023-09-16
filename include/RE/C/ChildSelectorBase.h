#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class CombatBehaviorTreeNode;

	class ChildSelectorBase
	{
	public:
		static bool ValidateChildren(CombatBehaviorTreeNode* node, BSFixedString const& type);

		uint32_t GetSelected() const { return 0xFFFFFFFF; }
		uint32_t SelectChild([[maybe_unused]] CombatBehaviorTreeNode* node, [[maybe_unused]] uint32_t selected_ind) { return 0xFFFFFFFF; }
		void     SetSelected([[maybe_unused]] uint32_t ind) {}
	};
}
