#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"

namespace RE
{
	class CombatCoverEdge;
	class CombatCoverLocation;
	class CombatCoverReservation;
	class CombatCoverSearchData;

	class CombatCoverMap
	{
		bool FindCoverReservations(const CombatCoverEdge& edge, const CombatCoverSearchData& search_data, BSScrapArray<float>& ans) const;
		CombatCoverLocation* ReserveCover(const CombatCoverEdge& edge, const CombatCoverSearchData& search_data, float pos);
		bool ReserveCover(CombatCoverLocation* cover);
		void UnreserveCover(CombatCoverLocation* cover);

		// members
		BSTHashMap<uint32_t, CombatCoverReservation*> targets;  // 00
		mutable BSReadWriteLock                       lock;     // 30
	};
	static_assert(sizeof(CombatCoverMap) == 0x38);
}
