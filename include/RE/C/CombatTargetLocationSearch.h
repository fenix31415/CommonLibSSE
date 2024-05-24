#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSCoreTypes.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CombatObject.h"
#include "RE/C/CombatTargetLocationAngle.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class Actor;
	class CombatTargetLocationSearchResult;

	class CombatTargetLocationSearch : public CombatObject
	{
	public:
		struct Array2_Item
		{
			// members
			float                     val;        // 00
			CombatTargetLocationAngle loc_angle;  // 04
			NiPoint3                  P;          // 14
		};
		static_assert(sizeof(Array2_Item) == 0x20);

		CombatTargetLocationSearch(Actor* actor, Actor* target, float R);

		CombatTargetLocationSearchResult* result;         // 10
		BSTArray<uint32_t>                array1;         // 18
		BSTArray<Array2_Item>             array2;         // 30
		ActorHandle                       actor;          // 48
		ActorHandle                       target;         // 4c
		FormID                            target_formid;  // 50
		NiPoint3                          P;              // 54
		float                             r;              // 60
		float                             me_r;           // 64
		uint32_t                          goal_found;     // 68
		uint32_t                          ind;            // 6C
		mutable BSReadWriteLock           lock;           // 70
	};
	static_assert(sizeof(CombatTargetLocationSearch) == 0x78);
}
