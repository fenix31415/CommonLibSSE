#pragma once

#include "RE/H/hkbBindable.h"

namespace RE
{
	class hkbBoneWeightArray;
	class hkbGenerator;

	class BSBoneSwitchGeneratorBoneData : public hkbBindable
	{
	public:
		// members
		hkbGenerator*       pGenerator;    // 30
		hkbBoneWeightArray* spBoneWeight;  // 38
	};
	static_assert(sizeof(BSBoneSwitchGeneratorBoneData) == 0x40);
}
