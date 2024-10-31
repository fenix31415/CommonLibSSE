#pragma once

#include "RE/H/hkStringPtr.h"

namespace RE
{
	/// An expression and its event mode.
	struct hkbExpressionData
	{
		// members
		hkStringPtr expression;               // 00 - "variablename = expression" or "eventname = boolean expression"
		int32_t     assignmentVariableIndex;  // 08 - This is the variable that we will assign result to (-1 if not found)
		int32_t     assignmentEventIndex;     // 0C - This is the event we will raise if result > 0 (-1 if not found)
		uint8_t     eventMode;                // 10 - Under what circumstances to send the event.
		bool        raisedEvent;              // 11 - Whether the event has been sent yet.
		bool        wasTrueInPreviousFrame;   // 12 - Whether the expression was true in the previous frame.
		char        pad13[5];                 // 13
	};
	static_assert(sizeof(hkbExpressionData) == 0x18);
}
