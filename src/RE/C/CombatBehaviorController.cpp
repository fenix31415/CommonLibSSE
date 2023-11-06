#include "RE/C/CombatBehaviorController.h"

namespace RE
{
	Actor* CombatBehaviorController::GetCurrentAttacker()
	{
		using func_t = decltype(&CombatBehaviorController::GetCurrentAttacker);
		REL::Relocation<func_t> func{ RELOCATION_ID(46114, 0) };  // I do not know for AE
		return func();
	}

	CombatController* CombatBehaviorController::GetCurrentCombatController()
	{
		using func_t = decltype(&CombatBehaviorController::GetCurrentCombatController);
		REL::Relocation<func_t> func{ RELOCATION_ID(46113, 0) };  // I do not know for AE
		return func();
	}

	CombatGroup* CombatBehaviorController::GetCurrentCombatGroup()
	{
		using func_t = decltype(&CombatBehaviorController::GetCurrentCombatGroup);
		REL::Relocation<func_t> func{ RELOCATION_ID(46112, 0) };  // I do not know for AE
		return func();
	}

	CombatInventory* CombatBehaviorController::GetCurrentCombatInventory()
	{
		using func_t = decltype(&CombatBehaviorController::GetCurrentCombatInventory);
		REL::Relocation<func_t> func{ RELOCATION_ID(46111, 0) };  // I do not know for AE
		return func();
	}

	CombatState* CombatBehaviorController::GetCurrentCombatState()
	{
		using func_t = decltype(&CombatBehaviorController::GetCurrentCombatState);
		REL::Relocation<func_t> func{ RELOCATION_ID(46110, 0) };  // I do not know for AE
		return func();
	}

	bool CombatBehaviorController::GetResource(const BSFixedString& name, NiPointer<CombatBehaviorResource>& resource)
	{
		using func_t = decltype(&CombatBehaviorController::GetResource);
		REL::Relocation<func_t> func{ RELOCATION_ID(46105, 0) };  // I do not know for AE
		return func(this, name, resource);
	}

	CombatBehaviorThread* CombatBehaviorController::GetThread(uint32_t ind) const
	{
		using func_t = decltype(&CombatBehaviorController::GetThread);
		REL::Relocation<func_t> func{ RELOCATION_ID(46104, 0) };  // I do not know for AE
		return func(this, ind);
	}
}
