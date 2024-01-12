#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSContainer.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/C/CombatTargetLocationAngle.h"

namespace RE
{
	class CombatTargetArc;
	class CombatTargetLocation;
	class CombatTargetReservation;

	class CombatTargetMap
	{
	public:
		bool                  CanReserveTarget(FormID target, const ActorHandle& owner, const CombatTargetLocationAngle& angle) const;
		bool                  FindTargetReservations(FormID target, const ActorHandle& owner, int32_t count, BSScrapArray<CombatTargetLocationAngle>& ans) const;
		void                  ForEachTargetArc(FormID target, std::function<BSContainer::ForEachResult(const CombatTargetArc&)> fun) const;
		bool                  GetReservedAngle(FormID target, const ActorHandle& owner, CombatTargetLocationAngle& ans) const;
		bool                  GetUnreservedAngle(FormID target, const ActorHandle& owner, float angle, CombatTargetLocationAngle& ans);
		bool                  ReserveTarget(CombatTargetLocation* loc);
		CombatTargetLocation* ReserveTarget(FormID target, const ActorHandle& owner, const CombatTargetLocationAngle& angle);
		void                  UnreserveTarget(CombatTargetLocation* loc);

		// members
		BSTHashMap<FormID, CombatTargetReservation*> targets;  // 00
		mutable BSReadWriteLock                      lock;     // 30
	};
	static_assert(sizeof(CombatTargetMap) == 0x38);
}
