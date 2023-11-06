#include "RE/C/CombatBehaviorStack.h"

namespace RE
{
	CombatBehaviorStack::ObjectPtr CombatBehaviorStack::Allocate(const CombatBehaviorExpression<CombatBehaviorMemberFunc<CombatBehaviorContextAcquireWeapon, CombatAcquireItem const& (CombatBehaviorContextAcquireWeapon::*)(void) const>>& arg1)
	{
		using func_t = CombatBehaviorStack::ObjectPtr (CombatBehaviorStack::*)(const CombatBehaviorExpression<CombatBehaviorMemberFunc<CombatBehaviorContextAcquireWeapon, CombatAcquireItem const& (CombatBehaviorContextAcquireWeapon::*)(void) const>>& arg1);
		REL::Relocation<func_t> func{ RELOCATION_ID(46359, 0) };  // I do not know for AE
		return func(this, arg1);
	}

	void CombatBehaviorStack::CheckBuffer(uint32_t a_size)
	{
		using func_t = decltype(&CombatBehaviorStack::CheckBuffer);
		REL::Relocation<func_t> func{ RELOCATION_ID(32426, 0) };  // I do not know for AE
		return func(this, a_size);
	}
}
