#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkpCdPointCollector.h"
#include "RE/H/hkpRootCdPoint.h"

namespace RE
{
	class hkpAllCdPointCollector : public hkpCdPointCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpAllCdPointCollector;
		inline static constexpr auto VTABLE = VTABLE_hkpAllCdPointCollector;

		hkpAllCdPointCollector()
		{
			stl::emplace_vtable(this);
		}

		~hkpAllCdPointCollector() override = default;  // 00

		// override (hkpCdPointCollector)
		// 01
		void addCdPoint(const hkpCdPoint& a_point) override
		{
			using func_t = decltype(&hkpAllCdPointCollector::addCdPoint);
			REL::Relocation<func_t> func{ RELOCATION_ID(59652, 0) };  // I do not know for AE
			return func(this, a_point);
		}
		// 02
		void reset() override
		{
			hits._size = 0;
			hkpCdPointCollector::reset();
		}

		bool hasHit() const
		{
			return !hits.empty();
		}

		void sortHits()
		{
			using func_t = decltype(&hkpAllCdPointCollector::sortHits);
			REL::Relocation<func_t> func{ RELOCATION_ID(59651, 0) };  // I do not know for AE
			return func(this);
		}

		// members
		hkInplaceArray<hkpRootCdPoint, 8> hits;  // 010
	};
	static_assert(sizeof(hkpAllCdPointCollector) == 0x220);
}
