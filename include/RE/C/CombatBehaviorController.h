#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/C/CombatBehaviorResource.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class Actor;
	class CombatBehaviorThread;
	class CombatController;
	class CombatGroup;
	class CombatInventory;
	class CombatState;

	class CombatBehaviorController
	{
	public:
		static Actor*            GetCurrentAttacker();
		static CombatController* GetCurrentCombatController();
		static CombatGroup*      GetCurrentCombatGroup();
		static CombatInventory*  GetCurrentCombatInventory();
		static CombatState*      GetCurrentCombatState();

		bool                  GetResource(const BSFixedString& name, NiPointer<CombatBehaviorResource>& resource);
		CombatBehaviorThread* GetThread(uint32_t ind) const;

		// members
		CombatBehaviorThread*                                        mb_root_thread;  // 00 -- TODO unique_ptr?
		BSTArray<CombatBehaviorThread*>                              active_threads;  // 08
		CombatController*                                            combat_control;  // 20
		BSTHashMap<BSFixedString, NiPointer<CombatBehaviorResource>> resources;       // 28
		BSTArray<CombatBehaviorThread*>                              queued;          // 58
		uint32_t                                                     threads;         // 70
		uint32_t                                                     pad_74;          // 74
	};
	static_assert(sizeof(CombatBehaviorController) == 0x78);
}
