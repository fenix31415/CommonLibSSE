#include "RE/C/CombatTargetLocationSearch.h"

namespace RE
{
	CombatTargetLocationSearch::CombatTargetLocationSearch(Actor* actor, Actor* target, float R)
	{
		using func_t = CombatTargetLocationSearch*(CombatTargetLocationSearch*, Actor*, Actor*, float);
		REL::Relocation<func_t> func{ RELOCATION_ID(46627, 0) };  // I do not know for AE
		func(this, actor, target, R);
	}
}
