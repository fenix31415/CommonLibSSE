#include "RE/C/CombatCoverReservation.h"

namespace RE
{
	CombatCoverSegment* CombatCoverReservation::FindClosestFreeSegment(float minWidth, float pos)
	{
		using func_t = decltype(&CombatCoverReservation::FindClosestFreeSegment);
		REL::Relocation<func_t> func{ RELOCATION_ID(43352, 0) };  // I do not know for AE
		return func(this, minWidth, pos);
	}

	bool CombatCoverReservation::FindCoverReservations(const CombatCoverSearchData& search_data, BSScrapArray<float>& ans) const
	{
		using func_t = decltype(&CombatCoverReservation::FindCoverReservations);
		REL::Relocation<func_t> func{ RELOCATION_ID(43347, 0) };  // I do not know for AE
		return func(this, search_data, ans);
	}

	CombatCoverLocation* CombatCoverReservation::ReserveCover(const CombatCoverSearchData& search_data, float pos)
	{
		using func_t = CombatCoverLocation*(CombatCoverReservation*, const CombatCoverSearchData&, float);
		REL::Relocation<func_t> func{ RELOCATION_ID(43348, 0) };  // I do not know for AE
		return func(this, search_data, pos);
	}

	bool CombatCoverReservation::ReserveCover(CombatCoverLocation* loc)
	{
		using func_t = CombatCoverLocation*(CombatCoverReservation*, CombatCoverLocation*);
		REL::Relocation<func_t> func{ RELOCATION_ID(43350, 0) };  // I do not know for AE
		return func(this, loc);
	}

	void CombatCoverReservation::ReserveCoverSegment(CombatCoverLocation* loc, uint32_t ind, float width)
	{
		using func_t = decltype(&CombatCoverReservation::ReserveCoverSegment);
		REL::Relocation<func_t> func{ RELOCATION_ID(43351, 0) };  // I do not know for AE
		return func(this, loc, ind, width);
	}

	bool CombatCoverReservation::UnreserveCover(CombatCoverLocation* loc)
	{
		using func_t = decltype(&CombatCoverReservation::UnreserveCover);
		REL::Relocation<func_t> func{ RELOCATION_ID(43349, 0) };  // I do not know for AE
		return func(this, loc);
	}
}
