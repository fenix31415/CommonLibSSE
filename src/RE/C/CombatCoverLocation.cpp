#include "RE/C/CombatCoverLocation.h"

namespace RE
{
	void CombatCoverLocation::UpdateCovers(const NiPoint3& a_cover1, const NiPoint3& a_cover2)
	{
		// not in AddressLibrary
		cover1 = a_cover1;
		cover2 = a_cover2;

		if (cover1 == cover2)
			flags &= ~4u;
		else
			flags |= 4u;
	}
}
