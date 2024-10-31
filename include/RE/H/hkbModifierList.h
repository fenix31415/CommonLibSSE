#pragma once

#include "RE/H/hkbModifier.h"

namespace RE
{
	class hkbModifierList : public hkbModifier
	{
	public:
		// members
		hkArray<hkbModifier*> modifiers;  // 50
	};
	static_assert(sizeof(hkbModifierList) == 0x60);
}
