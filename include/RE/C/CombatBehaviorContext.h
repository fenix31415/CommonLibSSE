#pragma once

#include "RE/T/TLSData.h"
#include "RE/C/CombatBehaviorThread.h"

#pragma warning(push)
#pragma warning(disable: 4324)  // structure was padded due to alignment specifier

namespace RE
{
	class alignas(4) CombatBehaviorContext
	{
	public:
		void Enter() {}
	};
}

#pragma warning(pop)
