#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/H/hkQuaternion.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	template <typename T>
	class StrangePointer
	{
		enum
		{
			kManaged = 1 << 0
		};

		void* ptr;

	public:
		StrangePointer() :
			ptr(nullptr) {}

		T* data()
		{
			return reinterpret_cast<T*>(reinterpret_cast<std::uintptr_t>(ptr) & ~kManaged);
		}

		const T* data() const
		{
			return reinterpret_cast<const T*>(reinterpret_cast<std::uintptr_t>(ptr) & ~kManaged);
		}
	};

	namespace BSUtilities
	{
		uint16_t ConvertFloatToHalf(float val);
		float ConvertHalfToFloat(uint16_t val);
	}

	template <typename Data>
	class BSTInterpolatorData
	{
	public:
		const uint16_t* times() const
		{
			return reinterpret_cast<const uint16_t*>(&data.data()[size]);
		}

		const Data* checkpoints() const
		{
			return data.data();
		}

		Data* checkpoints()
		{
			return data.data();
		}

		std::pair<float, Data> operator[](size_t ind) const
		{
			return { BSUtilities::ConvertHalfToFloat(times()[ind]), checkpoints()[ind] };
		}

		// members
		StrangePointer<Data> data;  // 00 - data[0..size-1] contains points/quats, &data[size] contains times (uint16 format, i.e. half)
		uint32_t             size;  // 08
		uint32_t             padC;  // 0C
	};

	class AnimationClipDataSingleton
	{
	public:
		class BoundAnimationData
		{
		public:
			// members
			BSTInterpolatorData<NiPoint3>     translation;  // 00
			BSTInterpolatorData<hkQuaternion> rotation;     // 10
			float                             duration;     // 20
			uint32_t                          pad24;        // 24
		};
		static_assert(sizeof(BoundAnimationData) == 0x28);

		struct ClipTriggerData
		{
			BSFixedString name;
			float         time;
			uint32_t      padC;
		};
		static_assert(sizeof(ClipTriggerData) == 0x10);

		class ClipData
		{
		public:
			bool GetEventTime(const BSFixedString& event_name, float& time);

			// members
			float           motionSpeed;     // 00
			uint16_t        bound_data_ind;  // 04
			uint16_t        numTriggers;     // 06
			ClipTriggerData triggerData[1];  // 08 -- actually [numTriggers]
		};
		static_assert(sizeof(ClipData) == 0x18);

		class AnimationClipData
		{
		public:
			ClipData*           clipGeneratorData;
			BoundAnimationData* boundAnimationData;
		};
		static_assert(sizeof(AnimationClipData) == 0x10);

		class AnimationData : public BSIntrusiveRefCounted
		{
		public:
			BSTHashMap<BSFixedString, ClipData*> clips;        // 08 -- key = clip_name
			BSTArray<BoundAnimationData>         bound_datas;  // 38
			BSTArray<BSFixedString>              hkxFiles;     // 50
		};
		static_assert(sizeof(AnimationData) == 0x68);

		static AnimationClipDataSingleton* GetSingleton();

		virtual ~AnimationClipDataSingleton();

		bool GetClipInformation(const BSFixedString& project_name, const BSFixedString& clip_name, AnimationClipData& ClipInformation);

		// members
		uint64_t                                            field_8;      // 08
		BSTHashMap<BSFixedString, NiPointer<AnimationData>> anim_datas;   // 10 -- key = project_name
		BSTArray<BSFixedString>                             mb_hkxFiles;  // 40
	};
	static_assert(sizeof(AnimationClipDataSingleton) == 0x58);
}
