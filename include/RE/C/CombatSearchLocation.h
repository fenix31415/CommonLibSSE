#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/B/BGSWorldLocation.h"

namespace RE
{
	class CombatSearchLocation
	{
	public:
		// members
		BGSWorldLocation loc;        // 00
		AITimeStamp      timestamp;  // 18
		float            score;      // 20
	};
	static_assert(sizeof(CombatSearchLocation) == 0x20);
}
