#pragma once

#include "RE/H/hkbGenerator.h"

namespace RE
{
	class hkbManualSelectorGenerator : public hkbGenerator
	{
	public:
		// members
		hkArray<hkbGenerator*> options;                 // 48
		int8_t                 selectedGeneratorIndex;  // 58
		int8_t                 currentGeneratorIndex;   // 59
		char                   pad[6];                  // 5A
	};
	static_assert(sizeof(hkbManualSelectorGenerator) == 0x60);
}
