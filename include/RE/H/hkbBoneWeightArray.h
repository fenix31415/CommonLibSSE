#pragma once

#include "RE/H/hkbBindable.h"

namespace RE
{
	class hkbBoneWeightArray : public hkbBindable
	{
	public:
		// members
		hkArray<float> weights;  // 30
	};
	static_assert(sizeof(hkbBoneWeightArray) == 0x40);
}
