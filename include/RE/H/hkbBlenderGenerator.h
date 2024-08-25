#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkbBindable.h"

namespace RE
{
	class hkbBoneWeightArray;

	class hkbBlenderGeneratorChild : public hkbBindable
	{
	public:
		// members
		hkbGenerator*       generator;             // 30
		hkbBoneWeightArray* boneWeights;           // 38
		float               weight;                // 40
		float               worldFromModelWeight;  // 44
		uint64_t            field_48;              // 48
	};
	static_assert(sizeof(hkbBlenderGeneratorChild) == 0x50);

	class hkbBlenderGenerator : public hkbGenerator
	{
	public:
		struct ChildInternalState
		{
			bool isActive;       // 00
			bool syncNextFrame;  // 01
		};
		static_assert(sizeof(ChildInternalState) == 0x2);

		// members
		float                              referencePoseWeightThreshold;  // 48
		float                              blendParameter;                // 4C
		float                              minCyclicBlendParameter;       // 50
		float                              maxCyclicBlendParameter;       // 54
		uint16_t                           indexOfSyncMasterChild;        // 58
		uint16_t                           flags;                         // 5A
		uint32_t                           field5C;                       // 5C
		hkArray<hkbBlenderGeneratorChild*> children;                      // 60
		hkArray<ChildInternalState>        childrenInternalStates;        // 70
		hkArray<uint16_t>                  sortedChildren;                // 80
		float                              endIntervalWeight;             // 90
		uint32_t                           numActiveChildren;             // 94
		uint16_t                           beginIntervalIndex;            // 98
		uint16_t                           endIntervalIndex;              // 9A
		bool                               echo;                          // 9C
		char                               pad9D[3];                      // 9D
	};
	static_assert(sizeof(hkbBlenderGenerator) == 0xA0);
}
