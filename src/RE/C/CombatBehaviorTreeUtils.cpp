#include "RE/C/CombatBehaviorTreeUtils.h"

namespace RE
{
	CombatBehaviorTreeUtils::CombatBehaviorAttacker::operator Actor*()
	{
		using func_t = decltype(&CombatBehaviorTreeUtils::CombatBehaviorAttacker::operator Actor*);
		REL::Relocation<func_t> func{ RELOCATION_ID(46264, 0) };  // I do not know for AE
		return func(this);
	}

	CombatBehaviorTreeUtils::CombatBehaviorTarget::operator Actor*()
	{
		using func_t = decltype(&CombatBehaviorTreeUtils::CombatBehaviorTarget::operator Actor*);
		REL::Relocation<func_t> func{ RELOCATION_ID(46265, 0) };  // I do not know for AE
		return func(this);
	}
}
