#pragma once

#include "RE/N/NiPoint3.h"
#include "RE/N/NiRefObject.h"

namespace RE
{
	class DetectionState : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_DetectionState;

		~DetectionState() override;  // 00

		// members
		std::int32_t level;             // 10
		bool         isCurrent_target;  // 14
		bool         hasLos;            // 15
		bool         LOS;               // 16
		std::uint8_t pad17;             // 17
		float        RecentLOSTime;     // 18
		NiPoint3     LastSeenLocation;  // 1C
		float        timeStamp1;        // 28
		NiPoint3     P1;                // 2C
		float        timeStamp;         // 38
		NiPoint3     P;                 // 3C
	};
	static_assert(sizeof(DetectionState) == 0x48);
}
