#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSContainer.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CombatTargetArc.h"

namespace RE
{
	class CombatTargetLocation;

	class CombatTargetReservation
	{
	public:
		bool                  CanReserveTarget(const ActorHandle& owner, const CombatTargetLocationAngle& angle) const;
		void                  ClearReservation(BSScrapArray<CombatTargetArc>& a_arcs, const ActorHandle& owner) const;
		bool                  FindTargetReservations(const ActorHandle& owner, int32_t count, BSScrapArray<CombatTargetLocationAngle>& ans) const;
		void                  ForEachArc(const std::function<BSContainer::ForEachResult(const CombatTargetArc&)> fun) const;
		bool                  GetReservedAngle(const ActorHandle& owner, CombatTargetLocationAngle& ans) const;
		bool                  GetUnreservedAngle(const ActorHandle& owner, float angle, CombatTargetLocationAngle& ans) const;
		void                  ReserveArc(CombatTargetLocation* loc, uint32_t ind);
		CombatTargetLocation* ReserveTarget(const ActorHandle& owner, const CombatTargetLocationAngle& angle);
		bool                  ReserveTarget(CombatTargetLocation* loc);
		bool                  UnreserveTarget(CombatTargetLocation* loc);

		// members
		FormID                    target;  // 00
		uint32_t                  pad04;   // 04
		BSTArray<CombatTargetArc> arcs;    // 08
	};
	static_assert(sizeof(CombatTargetReservation) == 0x20);
}
