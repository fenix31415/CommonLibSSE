#pragma once

#include "RE/H/hkReferencedObject.h"

namespace RE
{
	class hkbExpressionDataArray : public hkReferencedObject
	{
	public:
		// members
		hkArray<hkbExpressionData> expressionsData;  // 10 - One expression data for each expression.
	};
	static_assert(sizeof(hkbExpressionDataArray) == 0x20);
}
