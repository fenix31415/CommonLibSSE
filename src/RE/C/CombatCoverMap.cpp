#include "RE/C/CombatCoverMap.h"

namespace RE
{
	bool CombatCoverMap::FindCoverReservations(const CombatCoverEdge& edge, const CombatCoverSearchData& search_data, BSScrapArray<float>& ans) const
	{
		using func_t = decltype(&CombatCoverMap::FindCoverReservations);
		REL::Relocation<func_t> func{ RELOCATION_ID(43355, 0) };  // I do not know for AE
		return func(this, edge, search_data, ans);
	}

	CombatCoverLocation* CombatCoverMap::ReserveCover(const CombatCoverEdge& edge, const CombatCoverSearchData& search_data, float pos)
	{
		using func_t = CombatCoverLocation*(CombatCoverMap*, const CombatCoverEdge&, const CombatCoverSearchData&, float);
		REL::Relocation<func_t> func{ RELOCATION_ID(43356, 0) };  // I do not know for AE
		return func(this, edge, search_data, pos);
	}

	bool CombatCoverMap::ReserveCover(CombatCoverLocation* cover)
	{
		using func_t = bool(CombatCoverMap*, CombatCoverLocation*);
		REL::Relocation<func_t> func{ RELOCATION_ID(43358, 0) };  // I do not know for AE
		return func(this, cover);
	}

	void CombatCoverMap::UnreserveCover(CombatCoverLocation* cover)
	{
		using func_t = decltype(&CombatCoverMap::UnreserveCover);
		REL::Relocation<func_t> func{ RELOCATION_ID(43357, 0) };  // I do not know for AE
		return func(this, cover);
	}
}
