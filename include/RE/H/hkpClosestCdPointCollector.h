#pragma once

#include "RE/H/hkpCdPointCollector.h"
#include "RE/H/hkpRootCdPoint.h"

namespace RE
{
	class hkpClosestCdPointCollector : public hkpCdPointCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpClosestCdPointCollector;
		inline static constexpr auto VTABLE = VTABLE_hkpClosestCdPointCollector;

		hkpClosestCdPointCollector()
		{
			stl::emplace_vtable(this);
		}

		~hkpClosestCdPointCollector() override = default;  // 00

		// override (hkpCdPointCollector)
		// 01
		void addCdPoint(const hkpCdPoint& a_point) override
		{
			using func_t = decltype(&hkpClosestCdPointCollector::addCdPoint);
			REL::Relocation<func_t> func{ RELOCATION_ID(59686, 0) };  // I do not know for AE
			return func(this, a_point);
		}
		// 02
		void reset() override
		{
			hitPoint.rootCollidableA = nullptr;
			hitPoint.contact.separatingNormal.quad.m128_f32[3] = std::numeric_limits<float>::max();
			hkpCdPointCollector::reset();
		}

		bool hasHit() const
		{
			return hitPoint.rootCollidableA;
		}

		// members
		hkpRootCdPoint hitPoint;        // 10
		hkVector4      unweldedNormal;  // 50
	};
	static_assert(sizeof(hkpClosestCdPointCollector) == 0x60);
}
