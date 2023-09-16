#pragma once

#include "RE/B/BSTArray.h"
#include "RE/C/CombatBehavior.h"

namespace RE
{
	class CombatBehaviorParallel : public CombatBehavior
	{
	public:
		enum class FLAGS : uint32_t
		{
			kNoAbortOnUpdate = 1 << 0,
			kCalledAbort = (uint32_t)1 << 31
		};

		static bool Validate(CombatBehaviorTreeNode* node);

		void Abort();
		void Enter();
		void Update();

		// members
		BSTArray<CombatBehaviorThread*>   child_threads;  // 00
		stl::enumeration<FLAGS, uint32_t> flags;          // 18
		uint32_t                          pad1C;          // 1C
	};
	static_assert(sizeof(CombatBehaviorParallel) == 0x20);
}
