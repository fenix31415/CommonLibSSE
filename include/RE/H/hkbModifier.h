#pragma once

#include "RE/H/hkbNode.h"

namespace RE
{
	class hkClass;

	class hkbModifier : public hkbNode
	{
	public:
		// TODO: add vfuncts

		static const hkClass& staticClass()
		{
			return *REL::Relocation<hkClass*>(REL::ID(521711));
		}

		// members
		bool enable;    // 48
		char pad49[7];  // 49
	};
	static_assert(sizeof(hkbModifier) == 0x50);
}
