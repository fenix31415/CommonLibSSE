#pragma once

#include "RE/C/CombatBehavior.h"
#include "RE/C/CombatBehaviorThread.h"
#include "RE/C/CombatBehaviorTreeNode.h"
#include "RE/C/ConditionalChildSelector.h"
#include "RE/N/NextChildSelector.h"
#include "RE/R/RandomValueChildSelector.h"
#include "RE/T/TLSData.h"
#include "RE/V/ValueChildSelector.h"
#include "RE/W/WeightedRandomChildSelector.h"

#pragma warning(push)
#pragma warning(disable: 4324)  // padded

namespace RE
{
	template <typename Selector>
	class alignas(std::max(alignof(Selector), size_t(4))) CombatBehaviorChildSelector : public CombatBehavior
	{
	public:
		static bool Validate(CombatBehaviorTreeNode* node)
		{
			return CombatBehaviorNode::Validate(node) && Selector::Validate(node);
		}

		void Enter()
		{
			auto cur_thread = GetStaticTLSData()->combatAIThread;
			auto ind = selector.SelectChild(cur_thread->active_node, selector.GetSelected());
			selector.SetSelected(ind);
			if (ind == -1) {
				cur_thread->SetFailed(true);
				cur_thread->Ascend();
			} else {
				cur_thread->Descend(ind);
			}
		}

		// members
		char     unk00;     // 00
		Selector selector;  // 04
	};
}

#pragma warning(pop)  // padded
