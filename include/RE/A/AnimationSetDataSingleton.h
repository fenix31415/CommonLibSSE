#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"

namespace RE
{
	struct SetEventData;

	class AnimationSetData
	{
	public:
		struct Constraint
		{
			BSFixedString name;       // 00
			uint32_t      bounds[2];  // 08
		};
		static_assert(sizeof(Constraint) == 0x10);

		struct FilesInfo
		{
			// members
			BSTSmallArray<uint32_t>           crcs;  // 00 -- directory crc
			BSTSmallArray<BSTArray<uint32_t>> dirs;  // 18 -- file crc
		};

		// members
		BSTSmallArray<BSFixedString> triggerEvents;  // 00
		BSTArray<Constraint>         constraints;    // 18
		FilesInfo                    files_info;     // 30
		BSTArray<SetEventData>       setEventDatas;  // 70
	};
	static_assert(sizeof(AnimationSetData) == 0x88);

	class AnimationSetDataSingleton
	{
	public:
		static AnimationSetDataSingleton* GetSingleton()
		{
			return *REL::Relocation<AnimationSetDataSingleton**>(RELOCATION_ID(515415, 0));  // I do not know for AE
		}

		// members
		uint64_t                                               field0;  // 00
		BSTHashMap<BSFixedString, BSTArray<AnimationSetData>*> map;     // 08
	};
	static_assert(sizeof(AnimationSetDataSingleton) == 0x38);
}
