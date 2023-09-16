#include "RE/C/CombatBehaviorController.h"

namespace RE
{
	bool CombatBehaviorController::GetResource(const BSFixedString& name, NiPointer<CombatBehaviorResource>& resource)
	{
		using func_t = decltype(&CombatBehaviorController::GetResource);
		REL::Relocation<func_t> func{ RELOCATION_ID(46105, 0) };  // I do not know for AE
		return func(this, name, resource);
	}
}
