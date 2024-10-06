#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class NiAVObject;

	namespace BSUtilities
	{
		uint16_t    ConvertFloatToHalf(float val);
		float       ConvertHalfToFloat(uint16_t val);
		NiAVObject* GetObjectByName(NiAVObject* root, const BSFixedString& name, bool skip_Flattened_node = true);
	}
}
