#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkRefPtr.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkStringPtr.h"
#include "RE/H/hkaAnimation.h"

namespace RE
{
	class hkaAnimationBinding : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkaAnimationBinding;
		inline static constexpr auto VTABLE = VTABLE_hkaAnimationBinding;

		// A hint to indicate how this animation should be blended.
		enum class BlendHint
		{
			kNormal = 0,
			kAdditive
		};

		// members
		hkStringPtr                               originalSkeletonName;          // 10 - The name of the skeleton from which the binding was constructed.
		hkRefPtr<hkaAnimation>                    animation;                     // 18 - A handle to the animation bound to the skeleton.
		hkArray<std::int16_t>                     transformTrackToBoneIndices;   // 20 - A mapping from animation track indices to bone indices.
		hkArray<std::int16_t>                     floatTrackToFloatSlotIndices;  // 30 - A mapping from animation float track indices to float slot indices.
		stl::enumeration<BlendHint, std::uint8_t> blendHint;                     // 40 - A hint to indicate how this animation should be blended.
		char                                      pad41[7];                      // 41
	};
	static_assert(sizeof(hkaAnimationBinding) == 0x48);
}
