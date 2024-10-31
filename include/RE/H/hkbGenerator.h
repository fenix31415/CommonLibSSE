#pragma once

#include "RE/H/hkbNode.h"

namespace RE
{
	class hkbGenerator : public hkbNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbGenerator;
		inline static constexpr auto VTABLE = VTABLE_hkbGenerator;

		~hkbGenerator() override;  // 00

		// add
		virtual void generate(const hkbContext& a_context) const = 0;          // 17
		virtual bool canRecycleOutput() const;                                 // 18 - { return false; }
		virtual void updateSync(const hkbContext& a_context, void* nodeInfo);  // 19
		virtual void setLocalTime(float time);                                 // 1A - { return; }
		virtual void startEcho();                                              // 1B - { return; }
	};
	static_assert(sizeof(hkbGenerator) == 0x48);
}
