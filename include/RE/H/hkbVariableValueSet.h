#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkReferencedObject.h"

namespace RE
{
	class hkbVariableValueSet : public hkReferencedObject
	{
	public:
		// members
		hkArray<hkbVariableValue> wordVariableValues;     // 10
		hkArray<hkVector4>        quadVariableValues;     // 20
		hkArray<hkRefVariant>     variantVariableValues;  // 30
	};
	static_assert(sizeof(hkbVariableValueSet) == 0x40);
}
