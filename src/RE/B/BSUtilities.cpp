#include "RE/B/BSFixedString.h"

namespace RE
{
	class NiAVObject;

	namespace BSUtilities
	{
		uint16_t ConvertFloatToHalf(float val)
		{
			using func_t = decltype(ConvertFloatToHalf);
			REL::Relocation<func_t> func{ RELOCATION_ID(74491, 0) };  // I do not know for AE
			return func(val);
		}

		float ConvertHalfToFloat(uint16_t val)
		{
			using func_t = decltype(ConvertHalfToFloat);
			REL::Relocation<func_t> func{ RELOCATION_ID(74492, 0) };  // I do not know for AE
			return func(val);
		}

		NiAVObject* GetObjectByName(NiAVObject* root, const BSFixedString& name, bool skip_Flattened_node)
		{
			using func_t = decltype(GetObjectByName);
			REL::Relocation<func_t> func{ RELOCATION_ID(74481, 0) };  // I do not know for AE
			return func(root, name, skip_Flattened_node);
		}
	}
}
