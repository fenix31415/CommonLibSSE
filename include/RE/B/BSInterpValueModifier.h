#pragma once

#include "RE/H/hkbModifier.h"

namespace RE
{
	class BSInterpValueModifier : public hkbModifier
	{
	public:
		// members
		float source;    // 50
		float target;    // 54
		float result;    // 58
		float gain;      // 5C
		float timeStep;  // 60
		char  pad64[4];  // 64
	};
	static_assert(sizeof(BSInterpValueModifier) == 0x68);
}
