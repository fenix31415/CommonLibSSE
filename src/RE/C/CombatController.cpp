#include "RE/C/CombatController.h"

namespace RE
{
	void CombatController::ActivatedReference(TESObjectREFR* refr, TESBoundObject* refr_base, int targetCount, bool a5)
	{
		using func_t = decltype(&CombatController::ActivatedReference);
		REL::Relocation<func_t> func{ RELOCATION_ID(32478, 0) };  // I do not know for AE
		return func(this, refr, refr_base, targetCount, a5);
	}

	void CombatController::AddAimController(CombatAimController* control)
	{
		using func_t = decltype(&CombatController::AddAimController);
		REL::Relocation<func_t> func{ RELOCATION_ID(32502, 0) };  // I do not know for AE
		return func(this, control);
	}

	void CombatController::AddCombatArea(CombatAreaStandard*)
	{
		// TODO: not in AddressLib
		//a1->areas.push_back(area);
	}

	void CombatController::AddTarget(Actor* target)
	{
		using func_t = decltype(&CombatController::AddTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(32481, 0) };  // I do not know for AE
		return func(this, target);
	}

	void CombatController::AddTargetSelector(CombatTargetSelector* selector)
	{
		using func_t = decltype(&CombatController::AddTargetSelector);
		REL::Relocation<func_t> func{ RELOCATION_ID(32490, 0) };  // I do not know for AE
		return func(this, selector);
	}

	void CombatController::AttackedBy(Actor* attacker)
	{
		using func_t = decltype(&CombatController::AttackedBy);
		REL::Relocation<func_t> func{ RELOCATION_ID(32473, 0) };  // I do not know for AE
		return func(this, attacker);
	}

	void CombatController::CacheActorHandles()
	{
		using func_t = decltype(&CombatController::CacheActorHandles);
		REL::Relocation<func_t> func{ RELOCATION_ID(32517, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatController::ChangeStance(COMBAT_STANCE a_stance)
	{
		using func_t = decltype(&CombatController::ChangeStance);
		REL::Relocation<func_t> func{ RELOCATION_ID(32494, 0) };  // I do not know for AE
		return func(this, a_stance);
	}

	bool RE::CombatController::CheckCombatArea(Actor* atatcker) const
	{
		using func_t = decltype(&CombatController::CheckCombatArea);
		REL::Relocation<func_t> func{ RELOCATION_ID(32508, 0) };  // I do not know for AE
		return func(this, atatcker);
	}

	bool CombatController::CheckLOS(const NiPoint3& P) const
	{
		using func_t = decltype(&CombatController::CheckLOS);
		REL::Relocation<func_t> func{ RELOCATION_ID(32507, 0) };  // I do not know for AE
		return func(this, P);
	}

	bool CombatController::CheckMovement(BGSWorldLocation* location, float radius) const
	{
		using func_t = decltype(&CombatController::CheckMovement);
		REL::Relocation<func_t> func{ RELOCATION_ID(32512, 0) };  // I do not know for AE
		return func(this, location, radius);
	}

	bool CombatController::CheckStraightPath(NiPoint3& dst, float dist, float min_dist) const
	{
		using func_t = decltype(&CombatController::CheckStraightPath);
		REL::Relocation<func_t> func{ RELOCATION_ID(32513, 0) };  // I do not know for AE
		return func(this, dst, dist, min_dist);
	}

	bool CombatController::CheckTargetReachable(float dist) const
	{
		using func_t = decltype(&CombatController::CheckTargetReachable);
		REL::Relocation<func_t> func{ RELOCATION_ID(32514, 0) };  // I do not know for AE
		return func(this, dist);
	}

	void CombatController::DamagedByAttacker(Actor* attacker, float damage)
	{
		using func_t = decltype(&CombatController::DamagedByAttacker);
		REL::Relocation<func_t> func{ RELOCATION_ID(32477, 0) };  // I do not know for AE
		return func(this, attacker, damage);
	}

	void CombatController::Disarmed()
	{
		using func_t = decltype(&CombatController::Disarmed);
		REL::Relocation<func_t> func{ RELOCATION_ID(32474, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatController::FiredProjectile()
	{
		using func_t = decltype(&CombatController::FiredProjectile);
		REL::Relocation<func_t> func{ RELOCATION_ID(32475, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatController::ForceUpdateCombatArea()
	{
		using func_t = decltype(&CombatController::ForceUpdateCombatArea);
		REL::Relocation<func_t> func{ RELOCATION_ID(32509, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatController::GetAimLocation(NiPoint3& aim) const
	{
		using func_t = bool(const CombatController*, NiPoint3&);
		REL::Relocation<func_t> func{ RELOCATION_ID(32483, 0) };  // I do not know for AE
		return func(this, aim);
	}

	bool CombatController::GetAimLocation(void* mcaster_or_weap, NiPoint3& aim) const
	{
		using func_t = bool(const CombatController*, void*, NiPoint3&);
		REL::Relocation<func_t> func{ RELOCATION_ID(32505, 0) };  // I do not know for AE
		return func(this, mcaster_or_weap, aim);
	}

	ActorHandle CombatController::GetAimTarget(void* mcaster_or_weap) const
	{
		using func_t = decltype(&CombatController::GetAimTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(32506, 0) };  // I do not know for AE
		return func(this, mcaster_or_weap);
	}

	bool CombatController::IsActoraCombatTarget(Actor* actor) const
	{
		using func_t = decltype(&CombatController::IsActoraCombatTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(32483, 0) };  // I do not know for AE
		return func(this, actor);
	}

	bool CombatController::IsSearching() const
	{
		using func_t = decltype(&CombatController::IsSearching);
		REL::Relocation<func_t> func{ RELOCATION_ID(32486, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatController::IsTargetReachable(float distance) const
	{
		using func_t = decltype(&CombatController::IsTargetReachable);
		REL::Relocation<func_t> func{ RELOCATION_ID(32515, 0) };  // I do not know for AE
		return func(this, distance);
	}

	void CombatController::PauseCombat()
	{
		using func_t = decltype(&CombatController::PauseCombat);
		REL::Relocation<func_t> func{ RELOCATION_ID(529274, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatController::PerformedMeleeAttack()
	{
		using func_t = decltype(&CombatController::PerformedMeleeAttack);
		REL::Relocation<func_t> func{ RELOCATION_ID(32476, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatController::ReloadingWeapon()
	{
		// TODO, not in AddressLib
		//this->state->ReloadingWeapon();
	}

	void CombatController::RemoveAimController(CombatAimController* control)
	{
		using func_t = decltype(&CombatController::RemoveAimController);
		REL::Relocation<func_t> func{ RELOCATION_ID(32503, 0) };  // I do not know for AE
		return func(this, control);
	}

	void CombatController::RemoveTarget(Actor* target)
	{
		using func_t = decltype(&CombatController::RemoveTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(32482, 0) };  // I do not know for AE
		return func(this, target);
	}

	void CombatController::RemoveTargetSelector(CombatTargetSelector* selector)
	{
		using func_t = decltype(&CombatController::RemoveTargetSelector);
		REL::Relocation<func_t> func{ RELOCATION_ID(32491, 0) };  // I do not know for AE
		return func(this, selector);
	}

	void CombatController::SetInactive(bool a_inactive)
	{
		using func_t = decltype(&CombatController::SetInactive);
		REL::Relocation<func_t> func{ RELOCATION_ID(32501, 0) };  // I do not know for AE
		return func(this, a_inactive);
	}

	void CombatController::SetInventoryDirty(bool dirty)
	{
		using func_t = decltype(&CombatController::SetInventoryDirty);
		REL::Relocation<func_t> func{ RELOCATION_ID(32495, 0) };  // I do not know for AE
		return func(this, dirty);
	}

	void CombatController::SetTarget(Actor* target)
	{
		using func_t = decltype(&CombatController::SetTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(32488, 0) };  // I do not know for AE
		return func(this, target);
	}

	void CombatController::SetupPathingRequest(CombatPathingRequest* request) const
	{
		using func_t = decltype(&CombatController::SetupPathingRequest);
		REL::Relocation<func_t> func{ RELOCATION_ID(32516, 0) };  // I do not know for AE
		return func(this, request);
	}

	bool CombatController::ShouldStopCombat()
	{
		using func_t = decltype(&CombatController::ShouldStopCombat);
		REL::Relocation<func_t> func{ RELOCATION_ID(32487, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatController::ShutdownCombat()
	{
		using func_t = decltype(&CombatController::ShutdownCombat);
		REL::Relocation<func_t> func{ RELOCATION_ID(32500, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatController::TargetChanged()
	{
		using func_t = decltype(&CombatController::TargetChanged);
		REL::Relocation<func_t> func{ RELOCATION_ID(32479, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatController::UnCacheActorHandles()
	{
		using func_t = decltype(&CombatController::UnCacheActorHandles);
		REL::Relocation<func_t> func{ RELOCATION_ID(32518, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatController::UnPauseCombat()
	{
		using func_t = decltype(&CombatController::UnPauseCombat);
		REL::Relocation<func_t> func{ RELOCATION_ID(529275, 0) };  // I do not know for AE
		return func(this);
	}
}
