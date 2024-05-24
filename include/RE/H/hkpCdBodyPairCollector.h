#pragma once

namespace RE
{
	class hkpCdBodyPairCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpCdBodyPairCollector;
		inline static constexpr auto VTABLE = VTABLE_hkpCdBodyPairCollector;

		hkpCdBodyPairCollector()
		{
			stl::emplace_vtable(this);
		}

		virtual ~hkpCdBodyPairCollector() = default;  // 00

		// add
		virtual void addCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB) = 0;  // 01
		virtual void reset() { earlyOut = false; }                                       // 02

		// members
		bool earlyOut;  // 08
		char pad09[7];  // 07
	};
	static_assert(sizeof(hkpCdBodyPairCollector) == 0x10);
}
