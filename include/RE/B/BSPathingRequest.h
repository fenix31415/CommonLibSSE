#pragma once

#include "RE/B/BSPathingActorAttributes.h"
#include "RE/B/BSPathingLocation.h"
#include "RE/B/BSPathingSearchParameters.h"
#include "RE/M/MovementActorAvoidanceParameters.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class BSPathingAvoidNode;
	class PathingLockData;
	class MovementParameters;

	class BSPathingRequest : public BSIntrusiveRefCounted
	{
	public:
		struct BSPathingStart
		{
			// members
			BSPathingLocation location;  // 00
			float             tangent;   // 30
			uint32_t          pad34;     // 34
		};
		static_assert(sizeof(BSPathingStart) == 0x38);

		struct BSPathingGoal
		{
			// members
			NiPoint3          P;       // 00
			float             zDelta;  // 0C
			BSPathingLocation loc;     // 10
			NiPoint3          P2;      // 40
			uint32_t          pad4C;   // 4C
		};
		static_assert(sizeof(BSPathingGoal) == 0x50);

		struct BSPathingSearchAreaRestrictions
		{
			// members
			float    area_pos;     // 00
			float    area_radius;  // 04
			uint32_t unk08;        // 08
			uint32_t unk0C;        // 0C
		};
		static_assert(sizeof(BSPathingSearchAreaRestrictions) == 0x10);

		struct BSPathingRestrictions
		{
			using ArrayRefCounted = std::pair<BSTArray<BSPathingAvoidNode>, uint32_t>;

			// members
			ArrayRefCounted*                avoid_array;               // 00
			BSPathingSearchAreaRestrictions search_area_restrictions;  // 08
		};
		static_assert(sizeof(BSPathingRestrictions) == 0x18);

		class BSPathingActorAttributes
		{
		public:
			enum class FLAG : uint32_t
			{
				kUnk0 = 1 << 0,
				kUnk1 = 1 << 1,
				kUnk2 = 1 << 2,
				kCantOpenDoors = 1 << 3,
				kWalks = 1 << 4,
				kFightsInWater = 1 << 5,
				kFlies = 1 << 6,
				kUnk7 = 1 << 7,
				kUnk8 = 1 << 8,
				kUnk9 = 1 << 9,
				kUnk10 = 1 << 10,
				kUnk11 = 1 << 11,
			};
			using FLAGS = stl::enumeration<FLAG, uint32_t>;

			float            width;
			float            height;
			PathingLockData* pathing_loc_data;
			FLAGS            flags;
			uint32_t         pad;
		};
		static_assert(sizeof(BSPathingActorAttributes) == 0x18);

		virtual ~BSPathingRequest();                       // 00

		// add
		virtual uint32_t GetType();                        // 01
		virtual void     CopyTo(BSPathingRequest& other);  // 02
		virtual void     Write(void* buf);                 // 03
		virtual void     Read(void* buf);                  // 04
		virtual void     CheckValid();                     // 05
		virtual void     PrintDebugText(void* a2);		   // 06

		// members
		BSPathingStart                   start;                     // 10
		BSPathingGoal                    goal;                      // 48
		BSPathingRestrictions            restrictions;              // 98
		BSPathingSearchParameters        searchParams;              // B0
		uint32_t                         field_BC;                  // BC
		BSPathingActorAttributes         actorAttributes;           // C0
		MovementActorAvoidanceParameters actorAvoidanceParameters;  // D8
		MovementParameters*              defaultParameters;         // F8
	};
	static_assert(sizeof(BSPathingRequest) == 0x100);
}
