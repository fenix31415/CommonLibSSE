#include "RE/C/CombatBehaviorPause.h"

namespace RE
{
	void CombatBehaviorPause::Enter()
	{
		using func_t = decltype(&CombatBehaviorPause::Enter);
		REL::Relocation<func_t> func{ RELOCATION_ID(46190, 0) };  // I do not know for AE
		return func(this);
	}
}
