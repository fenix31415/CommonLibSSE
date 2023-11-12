#include "RE/C/CombatController.h"

namespace RE
{
	bool RE::CombatController::CheckCombatArea(Actor* atatcker) const
	{
		using func_t = decltype(&CombatController::CheckCombatArea);
		REL::Relocation<func_t> func{ RELOCATION_ID(32508, 0) };  // I do not know for AE
		return func(this, atatcker);
	}
}
