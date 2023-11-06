#include "RE/C/CombatBehaviorContextFlee.h"

namespace RE
{
	bool CombatBehaviorContextFlee::CheckShouldFlee() const
	{
		using func_t = decltype(&CombatBehaviorContextFlee::CheckShouldFlee);
		REL::Relocation<func_t> func{ RELOCATION_ID(47404, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatBehaviorContextFlee::StartFlee() const
	{
		using func_t = decltype(&CombatBehaviorContextFlee::StartFlee);
		REL::Relocation<func_t> func{ RELOCATION_ID(47405, 0) };  // I do not know for AE
		return func(this);
	}
}
