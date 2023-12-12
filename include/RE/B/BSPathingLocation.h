#pragma once

#include "RE/B/BSPathingCell.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	struct BSNavmeshInfo;

	class BSPathingLocation
	{
	public:
		// members
		NiPoint3                       P;             // 00
		uint32_t                       padC;          // 0C
		BSNavmeshInfo*                 navmesh_info;  // 10
		uint64_t                       field_18;      // 18
		BSTSmartPointer<BSPathingCell> cell;          // 20
		uint16_t                       mb_inside;     // 28
		uint8_t                        flags;         // 2A
		uint8_t                        flags1;        // 2B
		uint32_t                       pad2C;         // 2C
	};
	static_assert(sizeof(BSPathingLocation) == 0x30);
}
