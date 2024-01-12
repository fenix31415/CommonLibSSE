#include "RE/C/CombatTargetLocation.h"

namespace RE
{
	bool CombatTargetLocation::CheckPoint(const NiPoint3& target_pos, const NiPoint3& actor_pos, float width_mult) const
	{
		using func_t = decltype(&CombatTargetLocation::CheckPoint);
		REL::Relocation<func_t> func{ RELOCATION_ID(45697, 0) };  // I do not know for AE
		return func(this, target_pos, actor_pos, width_mult);
	}

	bool CombatTargetLocation::CheckAngle(const NiPoint3& target_pos, const NiPoint3& actor_pos, float width_mult) const
	{
		using func_t = decltype(&CombatTargetLocation::CheckAngle);
		REL::Relocation<func_t> func{ RELOCATION_ID(45698, 0) };  // I do not know for AE
		return func(this, target_pos, actor_pos, width_mult);
	}
}
