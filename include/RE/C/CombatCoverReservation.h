#pragma once

#include "RE/B/BSTArray.h"
#include "RE/C/CombatCoverEdge.h"
#include "RE/C/CombatCoverSegment.h"

namespace RE
{
	class CombatCoverSearchData;

	class CombatCoverReservation
	{
	public:
		CombatCoverReservation(const CombatCoverEdge& edge) :
			coverEdge(edge), segments() {}

		CombatCoverSegment*  FindClosestFreeSegment(float minWidth, float pos);
		bool FindCoverReservations(const CombatCoverSearchData& search_data, BSScrapArray<float>& ans) const;
		CombatCoverLocation* ReserveCover(const CombatCoverSearchData& search_data, float pos);
		bool                 ReserveCover(CombatCoverLocation* loc);
		void                 ReserveCoverSegment(CombatCoverLocation* loc, uint32_t ind, float width);
		bool                 UnreserveCover(CombatCoverLocation* loc);

		// members
		CombatCoverEdge              coverEdge;  // 00
		BSTArray<CombatCoverSegment> segments;   // 58
	};
	static_assert(sizeof(CombatCoverReservation) == 0x70);
}
