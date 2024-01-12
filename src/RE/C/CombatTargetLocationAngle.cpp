#include "RE/C/CombatTargetLocationAngle.h"

namespace RE
{
	CombatTargetLocationAngle::CombatTargetLocationAngle(float a_angle, float width)
	{
		using func_t = CombatTargetLocationAngle*(CombatTargetLocationAngle*, float, float);
		REL::Relocation<func_t> func{ RELOCATION_ID(45776, 0) };  // I do not know for AE
		func(this, a_angle, width);
	}

	bool CombatTargetLocationAngle::CheckAngle(float a_angle, float width_mult) const
	{
		using func_t = decltype(&CombatTargetLocationAngle::CheckAngle);
		REL::Relocation<func_t> func{ RELOCATION_ID(45839, 0) };  // I do not know for AE
		return func(this, a_angle, width_mult);
	}
}
