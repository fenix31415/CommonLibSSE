#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BSSpeedSamplerDBManager : public BSISpeedSamplerDB
	{
	public:
		struct SpeedData
		{
			// members
			float val;    // 00
			float speed;  // 04
		};
		static_assert(sizeof(SpeedData) == 0x8);

		struct DirectionData
		{
			// members
			float               direction;  // 00
			char                pad04[4];   // 04
			BSTArray<SpeedData> speeds;     // 08 - sorted by speed (2nd field)
		};
		static_assert(sizeof(DirectionData) == 0x20);

		struct StateData
		{
			// members
			uint32_t                state;       // 00
			char                    pad04[4];    // 04
			BSTArray<DirectionData> directions;  // 08 - sorted by direction (1st field)
		};
		static_assert(sizeof(StateData) == 0x20);

		struct ProjectData : public BSIntrusiveRefCounted
		{
			// members
			BSTArray<StateData> states;  // 08 - sorted by state (1st field)
		};
		static_assert(sizeof(ProjectData) == 0x20);

		float QuerySpeed(hkbContext* ctx, int32_t iState, float direction, float goalSpeed) override;

		static BSSpeedSamplerDBManager* GetSingleton()
		{
			return reinterpret_cast<BSSpeedSamplerDBManager*>(REL::Relocation<BSSpeedSamplerDBManager*>(REL::ID(516431)).address());
		}

		// members
		uint64_t                                                unk08;     // 08
		BSTHashMap<BSFixedString, BSTSmartPointer<ProjectData>> projects;  // 10
		mutable BSSpinLock                                      lock;      // 40
	};
	static_assert(sizeof(BSSpeedSamplerDBManager) == 0x48);
}
