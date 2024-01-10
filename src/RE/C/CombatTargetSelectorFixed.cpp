#include "RE/C/CombatTargetSelectorFixed.h"

namespace RE
{
	CombatTargetSelectorFixed* CombatTargetSelectorFixed::Create(CombatController* control, Actor* a_target, PRIORITY priority)
	{
		return RE::malloc<CombatTargetSelectorFixed>()->Ctor(control, a_target, priority);
	}

	CombatTargetSelectorFixed* CombatTargetSelectorFixed::Ctor(CombatController* control, Actor* a_target, PRIORITY a_priority)
	{
		using func_t = CombatTargetSelectorFixed*(CombatTargetSelectorFixed*, CombatController*, Actor*, PRIORITY);
		REL::Relocation<func_t> func{ RELOCATION_ID(45924, 0) };  // I do not know for AE
		return func(this, control, a_target, a_priority);
	}
}
