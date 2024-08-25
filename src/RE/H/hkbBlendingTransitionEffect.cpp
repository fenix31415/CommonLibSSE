#include "RE/H/hkbBlendingTransitionEffect.h"

#include "RE/H/hkContainerAllocators.h"

namespace RE
{
	hkbBlendingTransitionEffect* hkbBlendingTransitionEffect::Create(float duration, Flags flags, EndMode endMode)
	{
		auto ans = hk_malloc<hkbBlendingTransitionEffect>();
		std::memset(ans, 0, sizeof(hkbBlendingTransitionEffect));
		return ctor(ans, duration, flags, endMode);
	}

	hkbBlendingTransitionEffect* hkbBlendingTransitionEffect::ctor(hkbBlendingTransitionEffect* _this, float duration, Flags flags, EndMode endMode)
	{
		using func_t = decltype(&hkbBlendingTransitionEffect::ctor);
		REL::Relocation<func_t> func{ RELOCATION_ID(59274, 0) };  // I do not know for AE
		return func(_this, duration, flags, endMode);
	}
}
