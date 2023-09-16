#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "RE/N/NiRefObject.h"

namespace RE
{
	class CombatBehaviorController;
	class CombatBehaviorThread;

	class CombatBehaviorResource : public NiRefObject
	{
	public:
		~CombatBehaviorResource();

		static CombatBehaviorResource* Ctor(CombatBehaviorResource* a_this, CombatBehaviorController* controller, const BSFixedString& name);

		bool AcquireResource(CombatBehaviorThread* thread, uint32_t priority, bool can_suspend);
		void ClearOwner(CombatBehaviorThread* thread);
		void ReleaseResource(CombatBehaviorThread* thread);

		// members
		CombatBehaviorController*                      controller;     // 10
		BSFixedString                                  name;           // 18
		CombatBehaviorThread*                          owner;          // 20
		BSTArray<CombatBehaviorThread*>                suspended;      // 28
		BSTArray<BSTTuple<int, CombatBehaviorThread*>> subscribersPQ;  // 40
	};
	static_assert(sizeof(CombatBehaviorResource) == 0x58);
}
