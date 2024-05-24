#pragma once

#include "RE/H/hkpCdBodyPairCollector.h"
#include "RE/H/hkpRootCdBodyPair.h"

namespace RE
{
	class hkpAllCdBodyPairCollector : public hkpCdBodyPairCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpAllCdBodyPairCollector;
		inline static constexpr auto VTABLE = VTABLE_hkpAllCdBodyPairCollector;

		hkpAllCdBodyPairCollector()
		{
			stl::emplace_vtable(this);
		}

		~hkpAllCdBodyPairCollector() override = default;  // 00

		// override (hkpCdBodyPairCollector)
		// 01
		void addCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB) override
		{
			using func_t = decltype(&hkpAllCdBodyPairCollector::addCdBodyPair);
			REL::Relocation<func_t> func{ RELOCATION_ID(59677, 0) };  // I do not know for AE
			return func(this, bodyA, bodyB);
		}
		// 02
		void reset() override
		{
			hits._size = 0;
			hkpCdBodyPairCollector::reset();
		}

		// members
		hkInplaceArray<hkpRootCdBodyPair, 16> hits;  // 010
	};
	static_assert(sizeof(hkpAllCdBodyPairCollector) == 0x220);
}
