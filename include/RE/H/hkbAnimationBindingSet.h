#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkReferencedObject.h"

namespace RE
{
	template <class T>
	class hkRefPtr;

	class hkaAnimationBinding;
	class hkbAssetBundle;

	class hkbAnimationBindingWithTriggers : public RE::hkReferencedObject
	{
	public:
		struct Trigger
		{
			// members
			float    time;
			uint32_t field4;   // 04
			uint32_t field8;   // 08
			uint32_t fieldC;   // 0C
			uint64_t field10;  // 10
		};
		static_assert(sizeof(Trigger) == 0x18);

		// members
		hkRefPtr<hkaAnimationBinding> binding;   // 10
		hkArray<Trigger>              triggers;  // 18
	};
	static_assert(sizeof(hkbAnimationBindingWithTriggers) == 0x28);

	// A set of animation bindings with triggers that have been converted from annotations.
	class hkbAnimationBindingSet : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbAnimationBindingSet;
		inline static constexpr auto VTABLE = VTABLE_hkbAnimationBindingSet;

		// members
		hkArray<hkbAnimationBindingWithTriggers*> bindings;      // 10 - An array of bindings (a map from integers to bindings).
		hkArray<hkRefPtr<hkbAssetBundle>>         assetBundles;  // 20 - An array of bundles from which the bindings were loaded from.
	};
	static_assert(sizeof(hkbAnimationBindingSet) == 0x30);
}
