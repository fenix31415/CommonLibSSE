#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BSAnimationGraphChannel;
	class BShkbAnimationGraph;
	struct BSAnimationGraphEvent;

	union hkbVariableValue
	{
		bool         b;
		std::int32_t i;
		float        f;
	};
	static_assert(sizeof(hkbVariableValue) == 0x4);

	struct AnimVariableCacheInfo
	{
	public:
		// members
		BSFixedString     variableName;  // 00
		hkbVariableValue* variable;      // 08
	};
	static_assert(sizeof(AnimVariableCacheInfo) == 0x10);

	struct BSAnimationGraphVariableCache
	{
	public:
		// members
		BSTArray<AnimVariableCacheInfo> variableCache;  // 00
		mutable BSSpinLock              updateLock;     // 18
#ifdef SKYRIM_SUPPORT_AE
		mutable BSSpinLock graphLock;  // 20
#endif
		BSTSmartPointer<BShkbAnimationGraph> animationGraph;  // 28 - smart ptr
	};
#ifndef SKYRIM_SUPPORT_AE
	static_assert(sizeof(BSAnimationGraphVariableCache) == 0x28);
#else
	static_assert(sizeof(BSAnimationGraphVariableCache) == 0x30);
#endif

	BSSmartPointer(BSAnimationGraphManager);

	class BSAnimationGraphManager :
		public BSTEventSink<BSAnimationGraphEvent>,  // 00
		public BSIntrusiveRefCounted                 // 08
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSAnimationGraphManager;

		struct AnimationVariable
		{
		public:
			union Value
			{
				bool         b;
				std::int32_t i;
				float        f;
			};
			static_assert(sizeof(Value) == 0x4);

			// members
			BSFixedString name;   // 00
			Value*        value;  // 08
		};
		static_assert(sizeof(AnimationVariable) == 0x10);

		class ClipData
		{
		public:
			BSFixedString clipName;
			float         time_scale;
			float         field_C;
			float         pos_scale;
			float         field_14;
			bool          Xneg;
			uint8_t       pad19[7];
		};
		static_assert(sizeof(ClipData) == 0x20);

		~BSAnimationGraphManager() override;  // 00

		// override (BSTEventSink<BSAnimationGraphEvent>)
		BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_eventSource) override;  // 01

		bool QueryAnimations(const BSScrapArray<BSFixedString>& events, int activeGraph_ind, BSFixedString& projectName, BSScrapArray<ClipData>& clips)
		{
			using func_t = bool(BSAnimationGraphManager*, const BSScrapArray<BSFixedString>&, int, BSFixedString&, BSScrapArray<ClipData>&);
			REL::Relocation<func_t> func{ RELOCATION_ID(62432, 0) };  // I do not know for AE
			return func(this, events, activeGraph_ind, projectName, clips);
		}

		bool QueryAnimations(float mb_from_time, BSFixedString& projectName, BSScrapArray<ClipData>& array, int activeGraph_ind)
		{
			using func_t = bool(BSAnimationGraphManager*, float, BSFixedString&, BSScrapArray<ClipData>&, int);
			REL::Relocation<func_t> func{ RELOCATION_ID(62431, 0) };  // I do not know for AE
			return func(this, mb_from_time, projectName, array, activeGraph_ind);
		}

		// members
		std::uint32_t                                       pad0C;                 // 0C
		BSTArray<BSTSmartPointer<BSAnimationGraphChannel>>  boundChannels;         // 10
		BSTArray<BSTSmartPointer<BSAnimationGraphChannel>>  bumpedChannels;        // 28
		BSTSmallArray<BSTSmartPointer<BShkbAnimationGraph>> graphs;                // 40
		BSTArray<BSAnimationGraphManagerPtr>                subManagers;           // 58
		BSAnimationGraphVariableCache                       variableCache;         // 70
		mutable BSSpinLock                                  updateLock;            // 98
		mutable BSSpinLock                                  dependentManagerLock;  // A0
		std::uint32_t                                       activeGraph;           // A8
		std::uint32_t                                       generateDepth;         // A8
	};
#ifndef SKYRIM_SUPPORT_AE
	static_assert(sizeof(BSAnimationGraphManager) == 0xB0);
#else
	static_assert(sizeof(BSAnimationGraphManager) == 0xB8);
#endif
}
