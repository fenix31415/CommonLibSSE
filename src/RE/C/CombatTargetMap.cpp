#include "RE/C/CombatTargetMap.h"

#include "RE/C/CombatTargetReservation.h"

namespace RE
{
	bool CombatTargetMap::CanReserveTarget(FormID target, const ActorHandle& owner, const CombatTargetLocationAngle& angle) const
	{
		using func_t = decltype(&CombatTargetMap::CanReserveTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(45731, 0) };  // I do not know for AE
		return func(this, target, owner, angle);
	}

	bool CombatTargetMap::FindTargetReservations(FormID target, const ActorHandle& owner, int32_t count, BSScrapArray<CombatTargetLocationAngle>& ans) const
	{
		using func_t = decltype(&CombatTargetMap::FindTargetReservations);
		REL::Relocation<func_t> func{ RELOCATION_ID(45730, 0) };  // I do not know for AE
		return func(this, target, owner, count, ans);
	}

	void CombatTargetMap::ForEachTargetArc(FormID target, std::function<BSContainer::ForEachResult(const CombatTargetArc&)> fun) const
	{
		lock.LockForRead();
		if (auto found = targets.find(target); found != targets.end()) {
			found->second->ForEachArc(fun);
		}
		lock.UnlockForRead();
	}

	bool CombatTargetMap::GetReservedAngle(FormID target, const ActorHandle& owner, CombatTargetLocationAngle& ans) const
	{
		using func_t = decltype(&CombatTargetMap::GetReservedAngle);
		REL::Relocation<func_t> func{ RELOCATION_ID(45735, 0) };  // I do not know for AE
		return func(this, target, owner, ans);
	}

	bool CombatTargetMap::GetUnreservedAngle(FormID target, const ActorHandle& owner, float angle, CombatTargetLocationAngle& ans)
	{
		using func_t = decltype(&CombatTargetMap::GetUnreservedAngle);
		REL::Relocation<func_t> func{ RELOCATION_ID(45735, 0) };  // I do not know for AE
		return func(this, target, owner, angle, ans);
	}

	bool CombatTargetMap::ReserveTarget(CombatTargetLocation* loc)
	{
		using func_t = bool (CombatTargetMap*, CombatTargetLocation*);
		REL::Relocation<func_t> func{ RELOCATION_ID(45734, 0) };  // I do not know for AE
		return func(this, loc);
	}

	CombatTargetLocation* CombatTargetMap::ReserveTarget(FormID target, const ActorHandle& owner, const CombatTargetLocationAngle& angle)
	{
		using func_t = CombatTargetLocation*(CombatTargetMap*, FormID, const ActorHandle&, const CombatTargetLocationAngle&);
		REL::Relocation<func_t> func{ RELOCATION_ID(45732, 0) };  // I do not know for AE
		return func(this, target, owner, angle);
	}

	void CombatTargetMap::UnreserveTarget(CombatTargetLocation* loc)
	{
		using func_t = decltype(&CombatTargetMap::UnreserveTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(45733, 0) };  // I do not know for AE
		return func(this, loc);
	}
}
