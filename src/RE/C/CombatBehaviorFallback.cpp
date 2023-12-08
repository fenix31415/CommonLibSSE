#include "RE/C/CombatBehaviorFallback.h"

namespace RE
{
	void CombatBehaviorFallback::Enter()
	{
		using func_t = decltype(&CombatBehaviorFallback::Enter);
		REL::Relocation<func_t> func{ RELOCATION_ID(46712, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorFallback::Update()
	{
		using func_t = decltype(&CombatBehaviorFallback::Update);
		REL::Relocation<func_t> func{ RELOCATION_ID(46713, 0) };  // I do not know for AE
		return func(this);
	}
}
