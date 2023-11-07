#pragma once

#include "RE/C/CombatBehaviorContext.h"
#include "RE/N/NiSmartPointer.h"

class CombatAimController;
class CombatTargetLocation;

namespace RE
{
	class CombatBehaviorContextCloseMovement : public CombatBehaviorContext
	{
	public:
		bool CheckOutOfPosition() const;
		bool CheckOutOfRange() const;
		bool CheckShouldFallbackToRanged() const;

		// members
		NiPointer<CombatAimController> aim_controller;
		CombatTargetLocation*          target_loc;
	};
	static_assert(sizeof(CombatBehaviorContextCloseMovement) == 0x10);
}
