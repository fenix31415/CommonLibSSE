#include "RE/C/CombatTargetReservation.h"

namespace RE
{
	bool CombatTargetReservation::CanReserveTarget(const ActorHandle& owner, const CombatTargetLocationAngle& angle) const
	{
		using func_t = decltype(&CombatTargetReservation::CanReserveTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(45720, 0) };  // I do not know for AE
		return func(this, owner, angle);
	}

	void CombatTargetReservation::ClearReservation(BSScrapArray<CombatTargetArc>& a_arcs, const ActorHandle& owner) const
	{
		using func_t = decltype(&CombatTargetReservation::ClearReservation);
		REL::Relocation<func_t> func{ RELOCATION_ID(45727, 0) };  // I do not know for AE
		return func(this, a_arcs, owner);
	}

	bool CombatTargetReservation::FindTargetReservations(const ActorHandle& owner, int32_t count, BSScrapArray<CombatTargetLocationAngle>& ans) const
	{
		using func_t = decltype(&CombatTargetReservation::FindTargetReservations);
		REL::Relocation<func_t> func{ RELOCATION_ID(45719, 0) };  // I do not know for AE
		return func(this, owner, count, ans);
	}

	void CombatTargetReservation::ForEachArc(std::function<BSContainer::ForEachResult(const CombatTargetArc&)> fun) const
	{
		for (const auto& arc : arcs) {
			if (fun(arc) == RE::BSContainer::ForEachResult::kStop)
				break;
		}
	}

	bool CombatTargetReservation::GetReservedAngle(const ActorHandle& owner, CombatTargetLocationAngle& ans) const
	{
		using func_t = decltype(&CombatTargetReservation::GetReservedAngle);
		REL::Relocation<func_t> func{ RELOCATION_ID(45724, 0) };  // I do not know for AE
		return func(this, owner, ans);
	}

	bool CombatTargetReservation::GetUnreservedAngle(const ActorHandle& owner, float angle, CombatTargetLocationAngle& ans) const
	{
		using func_t = decltype(&CombatTargetReservation::GetUnreservedAngle);
		REL::Relocation<func_t> func{ RELOCATION_ID(45725, 0) };  // I do not know for AE
		return func(this, owner, angle, ans);
	}

	void CombatTargetReservation::ReserveArc(CombatTargetLocation* loc, uint32_t ind)
	{
		using func_t = decltype(&CombatTargetReservation::ReserveArc);
		REL::Relocation<func_t> func{ RELOCATION_ID(45726, 0) };  // I do not know for AE
		return func(this, loc, ind);
	}

	CombatTargetLocation* CombatTargetReservation::ReserveTarget(const ActorHandle& owner, const CombatTargetLocationAngle& angle)
	{
		using func_t = CombatTargetLocation*(CombatTargetReservation*, const ActorHandle&, const CombatTargetLocationAngle&);
		REL::Relocation<func_t> func{ RELOCATION_ID(45721, 0) };  // I do not know for AE
		return func(this, owner, angle);
	}

	bool CombatTargetReservation::ReserveTarget(CombatTargetLocation* loc)
	{
		using func_t = bool(CombatTargetReservation*, CombatTargetLocation*);
		REL::Relocation<func_t> func{ RELOCATION_ID(45723, 0) };  // I do not know for AE
		return func(this, loc);
	}

	bool CombatTargetReservation::UnreserveTarget(CombatTargetLocation* loc)
	{
		using func_t = decltype(&CombatTargetReservation::UnreserveTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(45722, 0) };  // I do not know for AE
		return func(this, loc);
	}
}
