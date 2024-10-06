#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class TESObjectREFR;

	struct BSAnimationGraphEvent
	{
	public:
		// members
		BSFixedString  tag;      // 00
		TESObjectREFR* holder;   // 08
		BSFixedString  payload;  // 10
	};
	static_assert(sizeof(BSAnimationGraphEvent) == 0x18);
}
