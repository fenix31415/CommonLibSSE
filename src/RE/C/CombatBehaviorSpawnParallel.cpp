#include "RE/C/CombatBehaviorSpawnParallel.h"

namespace RE
{
	void CombatBehaviorSpawnParallel::Enter()
	{
		using func_t = decltype(&CombatBehaviorSpawnParallel::Enter);
		REL::Relocation<func_t> func{ RELOCATION_ID(46173, 0) };  // I do not know for AE
		return func(this);
	}
}
