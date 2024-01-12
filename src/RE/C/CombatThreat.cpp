#include "RE/C/CombatThreat.h"

namespace RE
{
	bool CombatThreat::CheckVelocityDirection(const NiPoint3& pos) const
	{
		// not in AddressLibrary
		return (pos - threatLocation).Dot(linearVelocity) > 0.0f;
	}

	void CombatThreat::Initialize(TESObjectREFR* refr, float a_radius, float a_damage, float expl_time)
	{
		using func_t = decltype(&CombatThreat::Initialize);
		REL::Relocation<func_t> func{ RELOCATION_ID(45953, 0) };  // I do not know for AE
		return func(this, refr, a_radius, a_damage, expl_time);
	}

	bool CombatThreat::Update()
	{
		using func_t = decltype(&CombatThreat::Update);
		REL::Relocation<func_t> func{ RELOCATION_ID(45954, 0) };  // I do not know for AE
		return func(this);
	}
}
