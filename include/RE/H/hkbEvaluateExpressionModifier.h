#pragma once

#include "RE/H/hkbModifier.h"

namespace RE
{
	class hkbCompiledExpressionSet;
	class hkbExpressionDataArray;

	class hkbEvaluateExpressionModifier : public hkbModifier
	{
	public:
		struct InternalExpressionData
		{
			// members
			bool raisedEvent;             // 00 - has the event been raised
			bool wasTrueInPreviousFrame;  // 01 - was the expression true in the previous frame
		};

		// members
		hkRefPtr<hkbExpressionDataArray>   expressions;              // 50 - A set of expressions to be evaluated.
		hkRefPtr<hkbCompiledExpressionSet> compiledExpressionSet;    // 58
		hkArray<InternalExpressionData>    internalExpressionsData;  // 60 - One internal expression data for each expression
	};
	static_assert(sizeof(hkbEvaluateExpressionModifier) == 0x70);
}
