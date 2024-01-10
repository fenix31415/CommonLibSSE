#pragma once

#include "RE/C/CombatTargetSelector.h"

namespace RE
{
	class Actor;

	class CombatTargetSelectorFixed : public CombatTargetSelector
	{
	public:
		virtual void        Update() override;
		virtual ActorHandle SelectTarget() override;

		static CombatTargetSelectorFixed* Create(CombatController* control, Actor* target, PRIORITY priority);

	private:
		CombatTargetSelectorFixed* Ctor(CombatController* control, Actor* target, PRIORITY priority);
	};
	static_assert(sizeof(CombatTargetSelectorFixed) == 0x28);
}
