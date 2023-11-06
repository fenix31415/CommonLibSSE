#include "RE/C/CombatBehaviorContextMagic.h"

namespace RE
{
	CombatBehaviorContextMagic::CombatBehaviorContextMagic(CombatInventoryItemMagic* citem)
	{
		using func_t = CombatBehaviorContextMagic*(CombatBehaviorContextMagic*, CombatInventoryItemMagic*);
		REL::Relocation<func_t> func{ RELOCATION_ID(48035, 0) };  // I do not know for AE
		func(this, citem);
	}

	MagicSystem::CastingType CombatBehaviorContextMagic::GetCastingType()
	{
		using func_t = decltype(&CombatBehaviorContextMagic::GetCastingType);
		REL::Relocation<func_t> func{ RELOCATION_ID(530050, 0) };  // I do not know for AE
		return func(this);
	}
}
