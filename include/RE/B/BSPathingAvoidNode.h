#pragma once

#include "RE/N/NiPoint3.h"

namespace RE
{
	class BSPathingAvoidNode
	{
	public:
		NiPoint3 P;                // 00
		uint32_t field_C;          // 0C
		uint32_t field_10;         // 10
		uint32_t field_14;         // 14
		float    R;                // 18
		float    CostPathfinding;  // 1C
		uint32_t field_20;         // 20
	};
	static_assert(sizeof(BSPathingAvoidNode) == 0x24);
}
