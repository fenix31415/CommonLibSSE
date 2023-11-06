#pragma once

#include "RE/C/CombatBehaviorContextMelee.h"

namespace RE {
	class CombatBehaviorContextBlock : public CombatBehaviorContextMelee
	{
	public:
		bool CheckStopBlocking();
	};
}
