#include "RE/C/CombatBlackboardFlag.h"

namespace RE
{
	CombatBlackboardFlag::CombatBlackboardFlag()
	{
		using func_t = CombatBlackboardFlag*(CombatBlackboardFlag*);
		REL::Relocation<func_t> func{ RELOCATION_ID(43311, 0) };  // I do not know for AE
		func(this);
	}

	CombatBlackboardFlag* CombatBlackboardFlag::getHiding()
	{
		return REL::Relocation<CombatBlackboardFlag*>(RELOCATION_ID(518923, 0).address()).get();  // I do not know for AE
	}

	CombatBlackboardFlag* CombatBlackboardFlag::getUsingCover()
	{
		return REL::Relocation<CombatBlackboardFlag*>(RELOCATION_ID(519134, 0).address()).get();
	}
}
