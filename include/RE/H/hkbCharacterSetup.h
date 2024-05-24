#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkRefPtr.h"
#include "RE/H/hkReferencedObject.h"

namespace RE
{
	class hkaMirroredSkeleton;
	class hkaSkeleton;
	class hkaSkeletonMapper;
	class hkbAnimationBindingSet;
	class hkbCharacterData;
	class hkbSymbolIdMap;
	class hkCriticalSection;

	class hkbCharacterSetup : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbCharacterSetup;
		inline static constexpr auto VTABLE = VTABLE_hkbCharacterSetup;

		// members
		hkArray<hkRefPtr<const hkaSkeletonMapper>> retargetingSkeletonMappers;        // 10 - Array of skeleton mappers for animation retargeting.
		hkRefPtr<const hkaSkeleton>                animationSkeleton;                 // 20 - The animation skeleton. For the scaled character the reference pose inside this skeleton is scaled.
		hkRefPtr<const hkaSkeletonMapper>          ragdollToAnimationSkeletonMapper;  // 28 - A mapper from the ragdoll skeleton to the animation skeleton.
		hkRefPtr<const hkaSkeletonMapper>          animationToRagdollSkeletonMapper;  // 30 - A mapper from the animation skeleton to the ragdoll skeleton.
		hkRefPtr<hkbAnimationBindingSet>           animationBindingSet;               // 38
		hkRefPtr<hkbCharacterData>                 data;                              // 40
		hkRefPtr<const hkaSkeleton>                unscaledAnimationSkeleton;         // 48
		mutable hkRefPtr<hkaMirroredSkeleton>      mirroredSkeleton;                  // 50
		hkRefPtr<hkbSymbolIdMap>                   characterPropertyIdMap;            // 58
		mutable hkCriticalSection*                 criticalSection;                   // 60
	};
	static_assert(sizeof(hkbCharacterSetup) == 0x68);
}
