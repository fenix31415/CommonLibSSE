#include "RE/C/CombatBehaviorIdle.h"

namespace RE
{
	CombatBehaviorIdle::CombatBehaviorIdle(float interval)
	{
		using func_t = CombatBehaviorIdle*(CombatBehaviorIdle*, float);
		REL::Relocation<func_t> func{ RELOCATION_ID(46187, 0) };  // I do not know for AE
		func(this, interval);
	}

	void CombatBehaviorIdle::Update()
	{
		using func_t = decltype(&CombatBehaviorIdle::Update);
		REL::Relocation<func_t> func{ RELOCATION_ID(32436, 0) };  // I do not know for AE
		return func(this);
	}
}
