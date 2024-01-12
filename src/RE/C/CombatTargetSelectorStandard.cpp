#include "RE/C/CombatTargetSelectorStandard.h"

namespace RE
{
	CombatTargetSelectorStandard* CombatTargetSelectorStandard::Create(CombatController* control, PRIORITY priority)
	{
		return malloc<CombatTargetSelectorStandard>()->Ctor(control, priority);
	}

	ActorHandle CombatTargetSelectorStandard::FindBestTarget() const
	{
		using func_t = decltype(&CombatTargetSelectorStandard::FindBestTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(45922, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatTargetSelectorStandard::IsValidTarget(Actor* actor, Actor* a_target, BGSEncounterZone* me_EncounterZone) const
	{
		using func_t = decltype(&CombatTargetSelectorStandard::IsValidTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(45923, 0) };  // I do not know for AE
		return func(this, actor, a_target, me_EncounterZone);
	}

	CombatTargetSelectorStandard* CombatTargetSelectorStandard::Ctor(CombatController* control, PRIORITY a_priority)
	{
		using func_t = CombatTargetSelectorStandard*(CombatTargetSelectorStandard*, CombatController*, PRIORITY);
		REL::Relocation<func_t> func{ RELOCATION_ID(45917, 0) };  // I do not know for AE
		return func(this, control, a_priority);
	}
}
