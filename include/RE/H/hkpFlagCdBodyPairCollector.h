#pragma once

#include "RE/H/hkpCdBodyPairCollector.h"

namespace RE
{
	class hkpFlagCdBodyPairCollector : public hkpCdBodyPairCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpFlagCdBodyPairCollector;
		inline static constexpr auto VTABLE = VTABLE_hkpFlagCdBodyPairCollector;

		hkpFlagCdBodyPairCollector()
		{
			stl::emplace_vtable(this);
		}

		~hkpFlagCdBodyPairCollector() override = default;  // 00

		// override (hkpCdBodyPairCollector)
		void addCdBodyPair(const hkpCdBody&, const hkpCdBody&) override { earlyOut = true; }  // 01
	};
	static_assert(sizeof(hkpFlagCdBodyPairCollector) == 0x10);
}
