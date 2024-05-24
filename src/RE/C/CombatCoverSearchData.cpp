#include "RE/C/CombatCoverSearchData.h"

namespace RE
{
	bool CombatCoverSearchData::CheckRange(const NiPoint3& coverPos, float maxRangeBuffer) const
	{
		// not in AddressLibrary
		float r = maxRangeBuffer + maximumRange;
		float dist2 = threatLocation.GetSquaredDistance(coverPos);
		return dist2 > optimalRange * optimalRange && dist2 < r * r;
	}

	bool CombatCoverSearchData::CheckSecondaryThreatDistance(const NiPoint3& coverPos, float minDistance)
	{
		using func_t = decltype(&CombatCoverSearchData::CheckSecondaryThreatDistance);
		REL::Relocation<func_t> func{ RELOCATION_ID(43386, 0) };  // I do not know for AE
		return func(this, coverPos, minDistance);
	}

}
