#pragma once

#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkStringPtr.h"

namespace RE
{
	class hkbCompiledExpressionSet;
	class hkbContext;

	/// An object that evaluates to true or false.  Conditions do not get cloned when a behavior graph
	/// is shallow cloned, so you need to ensure that isTrue() is re-entrant and that your class
	/// does not include any character-specific state.
	class hkbCondition : public hkReferencedObject
	{
	public:
		/// Evaluates the condition.  Conditions do not get cloned when a behavior graph
		/// is shallow cloned, so you need to ensure that isTrue() is re-entrant and that your class
		/// does not include any character-specific state.
		virtual bool isTrue(const hkbContext& context) const = 0;
	};
	static_assert(sizeof(hkbCondition) == 0x10);

	/// A condition that is described by an expression string
	class hkbExpressionCondition : public hkbCondition
	{
	public:
		// members
		hkStringPtr               expression;             // 10
		hkbCompiledExpressionSet* compiledExpressionSet;  // 18
	};
	static_assert(sizeof(hkbExpressionCondition) == 0x20);
}
