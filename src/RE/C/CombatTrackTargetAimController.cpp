#include "RE/C/CombatTrackTargetAimController.h"

namespace RE
{
	CombatTrackTargetAimController* CombatTrackTargetAimController::Create(CombatController* control, PRIORITY priority, float R, bool a5)
	{
		return malloc<CombatTrackTargetAimController>()->Ctor(control, priority, R, a5);
	}

	CombatTrackTargetAimController* RE::CombatTrackTargetAimController::Ctor(CombatController* control, PRIORITY priority, float R, bool a5)
	{
		using func_t = decltype(&CombatTrackTargetAimController::Ctor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43147, 0) };  // I do not know for AE
		return func(this, control, priority, R, a5);
	}
}
