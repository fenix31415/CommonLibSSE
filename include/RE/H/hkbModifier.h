#pragma once

namespace RE
{
	class hkbModifier : public hkbNode
	{
	public:
		// TODO: add vfuncts

		// members
		uint64_t field48;  // 48
	};
	static_assert(sizeof(hkbModifier) == 0x50);
}
