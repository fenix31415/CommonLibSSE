#pragma once

#include "RE/H/hkbBehaviorGraphStringData.h"

namespace RE
{
	class hkbVariableInfo;
	class hkbEventInfo;
	class hkbVariableBounds;
	class hkbVariableValueSet;

	// Constant data associated with a behavior.
	class hkbBehaviorGraphData : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbBehaviorGraphData;
		inline static constexpr auto VTABLE = VTABLE_hkbBehaviorGraphData;

		virtual ~hkbBehaviorGraphData() = default;  // 00

		// members
		hkArray<float>                       attributeDefaults;       // 10 - The default values for the behavior's attributes.
		hkArray<hkbVariableInfo>             variableInfos;           // 20 - Definitions of variables used by the behavior.
		hkArray<hkbVariableInfo>             characterPropertyInfos;  // 30 - Definitions of the character properties that this behavior requires to be linked.
		hkArray<hkbVariableInfo>             eventInfos;              // 40 - The information that influences how each event behaviors.
		hkArray<hkbVariableBounds>           variableBounds;          // 50 - The min and max values of variables that fit into a word. For all other variables, this array stores zero.
		uint64_t                             unk60;                   // 60
		uint64_t                             unk68;                   // 68
		hkbVariableValueSet*                 variableInitialValues;   // 70 - The initial values of the variables.
		hkRefPtr<hkbBehaviorGraphStringData> stringData;              // 78 - The strings associated with a behavior.
	};
	static_assert(sizeof(hkbBehaviorGraphData) == 0x80);
}
