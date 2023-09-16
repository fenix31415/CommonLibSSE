#pragma once

#include "RE/C/CombatBehaviorChildSelector.h"
#include "RE/N/NextChildSelector.h"
#include "RE/W/WeightedRandomChildSelector.h"

namespace RE
{
	template <typename Selector>
	class CombatBehaviorFallbackSelector : public CombatBehaviorChildSelector<Selector>
	{
	public:
		static bool Validate(CombatBehaviorTreeNode* node)
		{
			return CombatBehaviorNode::Validate(node) && Selector::Validate(node);
		}

		void Update()
		{
			auto cur_thread = GetStaticTLSData()->combatAIThread;
			if (cur_thread->fail_state == CombatBehaviorThread::FailState::kFailed) {
				cur_thread->SetFailed(false);
				this->Enter();
			} else {
				cur_thread->Ascend();
			}
		}
	};
}
