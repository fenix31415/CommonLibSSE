#pragma once

#include "RE/H/hkpCdBodyPairCollector.h"
#include "RE/H/hkpRootCdBodyPair.h"

namespace RE
{
	class hkpFirstCdBodyPairCollector : public hkpCdBodyPairCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpFirstCdBodyPairCollector;
		inline static constexpr auto VTABLE = VTABLE_hkpFirstCdBodyPairCollector;

		hkpFirstCdBodyPairCollector()
		{
			stl::emplace_vtable(this);
		}

		~hkpFirstCdBodyPairCollector() override = default;  // 00

		// override (hkpCdBodyPairCollector)
		// 01
		void addCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB) override
		{
			using func_t = decltype(&hkpFirstCdBodyPairCollector::addCdBodyPair);
			REL::Relocation<func_t> func{ RELOCATION_ID(59678, 0) };  // I do not know for AE
			return func(this, bodyA, bodyB);
		}

		// members
		hkpRootCdBodyPair cdBodyPair;  // 010
	};
	static_assert(sizeof(hkpFirstCdBodyPairCollector) == 0x30);
}
