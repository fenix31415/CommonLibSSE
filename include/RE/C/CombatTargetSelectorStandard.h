#pragma once

#include "RE/A/AITimer.h"
#include "RE/C/CombatTargetSelector.h"

namespace RE
{
	class BGSEncounterZone;

	class CombatTargetSelectorStandard : public CombatTargetSelector
	{
	public:
		ActorHandle SelectTarget() override;

		static CombatTargetSelectorStandard* Create(CombatController* control, PRIORITY priority);

		ActorHandle FindBestTarget();
		bool        IsValidTarget(RE::Actor* actor, Actor* a_target, BGSEncounterZone* me_EncounterZone);

		// members
		AITimer updateTimer;  // 28

	private:
		CombatTargetSelectorStandard* Ctor(CombatController* control, PRIORITY priority);
	};
	static_assert(sizeof(CombatTargetSelectorStandard) == 0x30);
}
