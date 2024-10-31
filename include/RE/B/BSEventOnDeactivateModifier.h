#pragma once

#include "RE/H/hkbEventBase.h"
#include "RE/H/hkbModifier.h"

namespace RE
{
	class BSEventOnDeactivateModifier : public hkbModifier
	{
	public:
		// members
		hkbEventBase event;  // 50
	};
	static_assert(sizeof(BSEventOnDeactivateModifier) == 0x60);
}
