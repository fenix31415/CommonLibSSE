#pragma once

#include "RE/H/hkbGenerator.h"
#include "RE/H/hkStringPtr.h"

namespace RE
{
	class hkbBehaviorGraph;

	class hkbBehaviorReferenceGenerator : public hkbGenerator
	{
	public:
		// members
		hkStringPtr       behaviorName;  // 48
		hkbBehaviorGraph* behavior;      // 50
	};
	static_assert(sizeof(hkbBehaviorReferenceGenerator) == 0x58);

}
