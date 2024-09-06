#pragma once

#include "RE/N/NiObject.h"

namespace RE
{
	struct NiBSplineBasis
	{
		uint32_t quantity;   // 00
		float    values[4];  // 04
		float    lastTime;   // 14
		uint32_t min_ind;    // 18
		uint32_t max_ind;    // 1C
	};
	static_assert(sizeof(NiBSplineBasis) == 0x20);

	class NiBSplineBasisData : public NiObject
	{
	public:
		// members
		NiBSplineBasis basis;  // 10
	};
	static_assert(sizeof(NiBSplineBasisData) == 0x30);
}
