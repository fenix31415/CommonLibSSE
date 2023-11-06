#include "RE/C/CombatBehaviorContextCloseMovement.h"

namespace RE
{
	bool CombatBehaviorContextCloseMovement::CheckOutOfPosition() const
	{
		using func_t = decltype(&CombatBehaviorContextCloseMovement::CheckOutOfPosition);
		REL::Relocation<func_t> func{ RELOCATION_ID(46697, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatBehaviorContextCloseMovement::CheckOutOfRange() const
	{
		using func_t = decltype(&CombatBehaviorContextCloseMovement::CheckOutOfRange);
		REL::Relocation<func_t> func{ RELOCATION_ID(46696, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatBehaviorContextCloseMovement::CheckShouldFallbackToRanged() const
	{
		using func_t = decltype(&CombatBehaviorContextCloseMovement::CheckOutOfRange);
		REL::Relocation<func_t> func{ RELOCATION_ID(46699, 0) };  // I do not know for AE
		return func(this);
	}
}
