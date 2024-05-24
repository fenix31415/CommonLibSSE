#pragma once

#include "RE/H/hkpRayHitCollector.h"
#include "RE/H/hkpWorldRayCastOutput.h"

namespace RE
{
	class hkpClosestRayHitCollector : public hkpRayHitCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpClosestRayHitCollector;
		inline static constexpr auto VTABLE = VTABLE_hkpClosestRayHitCollector;

		// override (hkpRayHitCollector)
		// 01
		void addRayHit(const hkpCdBody& a_body, const hkpShapeRayCastCollectorOutput& a_hitInfo) override
		{
			using func_t = decltype(&hkpClosestRayHitCollector::addRayHit);
			REL::Relocation<func_t> func{ RELOCATION_ID(59653, 0) };  // I do not know for AE
			return func(this, a_body, a_hitInfo);
		}

		~hkpClosestRayHitCollector() override = default;  // 00

		constexpr bool hasHit() noexcept { return rayHit.HasHit(); }

		constexpr void reset() noexcept
		{
			hkpRayHitCollector::reset();
			rayHit.Reset();
		}

		// members
		hkpWorldRayCastOutput rayHit;  // 10
	};
	static_assert(sizeof(hkpClosestRayHitCollector) == 0x70);
}
