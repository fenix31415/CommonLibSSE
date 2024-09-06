#pragma once

#include "RE/N/NiObject.h"

namespace RE
{
	class NiBSplineData : public NiObject
	{
	public:
		// members
		std::unique_ptr<float>    data;       // 10
		std::unique_ptr<uint16_t> data_comp;  // 18
		uint32_t                  size;       // 20
		uint32_t                  size_comp;  // 24
	};
	static_assert(sizeof(NiBSplineData) == 0x28);
}
