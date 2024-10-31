#pragma once

namespace RE
{
	class hkaBone
	{
	public:
		// members
		hkStringPtr name;             // 00 - The name of the bone from the toolchain
		bool        lockTranslation;  // 08 - Whether or not this bone can move relative to its parent
	};
	static_assert(sizeof(hkaBone) == 0x10);
}
