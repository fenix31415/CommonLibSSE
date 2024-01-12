#include "RE/C/CombatTargetArc.h"

namespace RE
{
	CombatTargetArc::CombatTargetArc(float angle, float width) :
		angle(angle, width), targetLocation(nullptr)
	{}
	CombatTargetArc::CombatTargetArc(CombatTargetLocation* targetLocation, const CombatTargetLocationAngle& angle) :
		angle(angle), targetLocation(targetLocation)
	{}

	bool CombatTargetArc::isFree() const
	{
		return !targetLocation;
	}
}
