#pragma once

namespace RE
{
	class hkbBehaviorGraphStringData : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbBehaviorGraphStringData;
		inline static constexpr auto VTABLE = VTABLE_hkbBehaviorGraphStringData;

		virtual ~hkbBehaviorGraphStringData() = default;  // 00

		// members
		hkArray<hkStringPtr> eventNames;              // 10 - The names (and implicit IDs) of the events used by the behavior.
		hkArray<hkStringPtr> attributeNames;          // 20 - The names (and implicit IDs) of the attributes of the behavior.
		hkArray<hkStringPtr> variableNames;           // 30 - The names (and implicit IDs) of the variables used by the behavior.
		hkArray<hkStringPtr> characterPropertyNames;  // 40 - The names (and implicit IDs) of the character properties that this behavior requires to be linked.
	};
	static_assert(sizeof(hkbBehaviorGraphStringData) == 0x50);
}
