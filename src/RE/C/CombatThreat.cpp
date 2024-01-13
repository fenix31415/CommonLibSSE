#include "RE/C/CombatThreat.h"

namespace RE
{
	bool CombatThreat::CheckVelocityDirection(const NiPoint3& pos) const
	{
		// not in AddressLibrary
		return (pos - threatLocation).Dot(linearVelocity) > 0.0f;
	}

	bool CombatThreat::CheckCollision(const CombatMathUtilities::GenericShape& s, float time) const
	{
		using func_t = decltype(&CombatThreat::CheckCollision);
		REL::Relocation<func_t> func{ RELOCATION_ID(45955, 0) };  // I do not know for AE
		return func(this, s, time);
	}

	bool CombatThreat::CreateCollisionShape(float time, CombatMathUtilities::GenericShape& ans) const
	{
		using func_t = decltype(&CombatThreat::CreateCollisionShape);
		REL::Relocation<func_t> func{ RELOCATION_ID(45958, 0) };  // I do not know for AE
		return func(this, time, ans);
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
