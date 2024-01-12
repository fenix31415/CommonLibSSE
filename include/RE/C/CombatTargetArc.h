#pragma once

#include "RE/C/CombatTargetLocationAngle.h"

namespace RE
{
	class CombatTargetLocation;

	class CombatTargetArc
	{
	public:
		CombatTargetArc() = default;
		CombatTargetArc(float angle, float width);
		CombatTargetArc(CombatTargetLocation* targetLocation, const CombatTargetLocationAngle& angle);

		bool isFree() const;

		// members
		CombatTargetLocationAngle angle;           // 00
		CombatTargetLocation*     targetLocation;  // 10
	};
	static_assert(sizeof(CombatTargetArc) == 0x18);
}
