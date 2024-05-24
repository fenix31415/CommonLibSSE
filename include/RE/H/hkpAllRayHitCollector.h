#pragma once

#include "RE/H/hkpRayHitCollector.h"
#include "RE/H/hkpWorldRayCastOutput.h"

namespace RE
{
	class hkpAllRayHitCollector : public hkpRayHitCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpAllRayHitCollector;
		inline static constexpr auto VTABLE = VTABLE_hkpAllRayHitCollector;

		hkpAllRayHitCollector()
		{
			stl::emplace_vtable(this);
		}

		// override (hkpRayHitCollector)
		// 01
		void addRayHit(const hkpCdBody& a_body, const hkpShapeRayCastCollectorOutput& a_hitInfo) override
		{
			using func_t = decltype(&hkpAllRayHitCollector::addRayHit);
			REL::Relocation<func_t> func{ RELOCATION_ID(77446, 0) };  // I do not know for AE
			return func(this, a_body, a_hitInfo);
		}

		~hkpAllRayHitCollector() override = default;  // 00

		// members
		hkInplaceArray<hkpWorldRayCastOutput, 8> hits;  // 010
	};
	static_assert(sizeof(hkpAllRayHitCollector) == 0x320);
}
