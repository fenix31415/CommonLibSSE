#pragma once

#include "RE/C/CombatTargetSelector.h"

namespace RE
{
	class Actor;

	class CombatTargetSelectorFixed : public CombatTargetSelector
	{
	public:
		~CombatTargetSelectorFixed();  // 00

		// override (CombatObject)
		std::uint32_t GetObjectType() override;  // 02

		// override (CombatTargetSelector)
		virtual void        Update() override;        // 05
		virtual ActorHandle SelectTarget() override;  // 06

		[[nodiscard]] static CombatTargetSelectorFixed* Create(CombatController* control, Actor* target, PRIORITY priority);

	private:
		CombatTargetSelectorFixed* Ctor(CombatController* control, Actor* target, PRIORITY priority);
	};
	static_assert(sizeof(CombatTargetSelectorFixed) == 0x28);
}
