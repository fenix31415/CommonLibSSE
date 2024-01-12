#pragma once

#include "RE/A/AITimer.h"
#include "RE/C/CombatTargetSelector.h"

namespace RE
{
	class BGSEncounterZone;

	class CombatTargetSelectorStandard : public CombatTargetSelector
	{
	public:
		~CombatTargetSelectorStandard();  // 00

		// override (CombatObject)
		std::uint32_t GetObjectType() override;                     // 02
		void          SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void          LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04

		// override (CombatTargetSelector)
		ActorHandle SelectTarget() override;  // 06

		ActorHandle FindBestTarget() const;
		bool        IsValidTarget(Actor* actor, Actor* a_target, BGSEncounterZone* me_EncounterZone) const;

		static CombatTargetSelectorStandard* Create(CombatController* control, PRIORITY priority);

		// members
		AITimer updateTimer;  // 28

	private:
		CombatTargetSelectorStandard* Ctor(CombatController* control, PRIORITY priority);
	};
	static_assert(sizeof(CombatTargetSelectorStandard) == 0x30);
}
