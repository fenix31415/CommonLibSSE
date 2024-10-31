#pragma once

#include "RE/H/hkbGenerator.h"

namespace RE
{
	class BSOffsetAnimationGenerator : public hkbGenerator
	{
	public:
		// members
		uint64_t          field48;               // 48
		hkbGenerator*     pDefaultGenerator;     // 50
		void*             unk58;                 // 58
		hkbClipGenerator* pOffsetClipGenerator;  // 60
		float             fOffsetVariable;       // 68
		float             fOffsetRangeEnd;       // 6C
		float             fOffsetRangeStart;     // 70
		uint32_t          field_74;              // 74
		char              unk78[0x30];           // 78
	};
	static_assert(sizeof(BSOffsetAnimationGenerator) == 0xA8);
}
