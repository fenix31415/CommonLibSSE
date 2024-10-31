#pragma once

#include "RE/H/hkbGenerator.h"

namespace RE
{
	class BSBoneSwitchGeneratorBoneData;

	class BSBoneSwitchGenerator : public hkbGenerator
	{
	public:
		// members
		uint64_t                                unk48;              // 48
		hkbGenerator*                           pDefaultGenerator;  // 50
		hkArray<BSBoneSwitchGeneratorBoneData*> ChildrenA;          // 58
	};
	static_assert(sizeof(BSBoneSwitchGenerator) == 0x68);
}
