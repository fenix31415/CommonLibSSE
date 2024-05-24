#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class CombatAimController;

	class CombatCoverSearchData
	{
	public:
		bool CheckRange(const NiPoint3& coverPos, float maxRangeBuffer) const;
		bool CheckSecondaryThreatDistance(const NiPoint3& coverPos, float minDistance);

		// members
		ActorHandle                    actor;                 // 00
		uint32_t                       controllers_aim;       // 04
		float                          actorRadius;           // 08
		float                          actorMinimalHeight;    // 0C
		uint8_t                        cover_height;          // 10
		uint8_t                        cover_height_sneak;    // 11
		uint16_t                       pad12;                 // 12
		float                          optimalRange;          // 14
		float                          maximumRange;          // 18
		NiPoint3                       threatAimLocation;     // 1C
		NiPoint3                       threatLocation;        // 28
		uint32_t                       pad34;                 // 34
		BSTArray<NiPoint3>             secondaryThreatArray;  // 38
		NiPointer<CombatAimController> aimController;         // 50
	};
	static_assert(sizeof(CombatCoverSearchData) == 0x58);
}
