#include "RE/C/CombatCoverSearch.h"

namespace RE
{
	void CombatCoverSearch::ClearSearchResult()
	{
		using func_t = decltype(&CombatCoverSearch::ClearSearchResult);
		REL::Relocation<func_t> func{ RELOCATION_ID(43393, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatCoverSearch::SetCoverLocation(const NiPointer<class CombatCoverLocation>& loc)
	{
		using func_t = decltype(&CombatCoverSearch::SetCoverLocation);
		REL::Relocation<func_t> func{ RELOCATION_ID(43392, 0) };  // I do not know for AE
		return func(this, loc);
	}

	void CombatCoverSearch::StartedSearch()
	{
		using func_t = decltype(&CombatCoverSearch::StartedSearch);
		REL::Relocation<func_t> func{ RELOCATION_ID(43391, 0) };  // I do not know for AE
		return func(this);
	}
}
