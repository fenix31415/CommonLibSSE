#pragma once

namespace RE
{
	struct hkpCdPoint;

	class hkpCdPointCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpCdPointCollector;
		inline static constexpr auto VTABLE = VTABLE_hkpCdPointCollector;

		hkpCdPointCollector()
		{
			stl::emplace_vtable(this);
		}

		virtual ~hkpCdPointCollector() = default;  // 00

		// add
		virtual void addCdPoint(const hkpCdPoint& a_point) = 0;  // 01
		// 02
		virtual void reset() { earlyOutDistance = std::numeric_limits<float>::max(); }

		// members
		float         earlyOutDistance;  // 08
		std::uint32_t pad0C;             // 0C
	};
	static_assert(sizeof(hkpCdPointCollector) == 0x10);
}
