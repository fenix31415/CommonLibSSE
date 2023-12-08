#pragma once

#include "RE/B/BSPathingActorAttributes.h"
#include "RE/B/BSPathingLocation.h"
#include "RE/B/BSPathingSearchParameters.h"
#include "RE/M/MovementActorAvoidanceParameters.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class BSPathingAvoidNode;
	class MovementParameters;

	class BSPathingRequest : public BSIntrusiveRefCounted
	{
	public:
		virtual ~BSPathingRequest();

		using ArrayRefCounted = std::pair<BSTArray<BSPathingAvoidNode>, uint32_t>;

		// members
		BSPathingLocation                loc;                 // 10
		float                            field_40;            // 40
		float                            field_44;            // 44
		NiPoint3                         P;                   // 48
		float                            flt_54;              // 54
		BSPathingLocation                destination;         // 58
		float                            field_88;            // 88
		float                            radius;              // 8C
		uint32_t                         field_90;            // 90
		uint32_t                         field_94;            // 94
		ArrayRefCounted*                 avoidNodes;          // 98
		NiPoint3                         area_pos;            // A0
		float                            area_radius;         // AC
		BSPathingSearchParameters        search_params;       // B0
		uint32_t                         field_BC;            // BC
		BSPathingActorAttributes         actor_attrs;         // C0
		uint32_t                         field_D4;            // D4
		MovementActorAvoidanceParameters actor_avoid_params;  // D8
		MovementParameters*              movement_params;     // F8
	};
	static_assert(sizeof(BSPathingRequest) == 0x100);
}
