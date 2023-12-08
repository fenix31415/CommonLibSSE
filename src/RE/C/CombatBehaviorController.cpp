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

	void CombatBehaviorController::Abort()
	{
		using func_t = decltype(&CombatBehaviorController::Abort);
		REL::Relocation<func_t> func{ RELOCATION_ID(46099, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorController::AddResource(CombatBehaviorResource* resource)
	{
		using func_t = decltype(&CombatBehaviorController::AddResource);
		REL::Relocation<func_t> func{ RELOCATION_ID(46106, 0) };  // I do not know for AE
		return func(this, resource);
	}

	void CombatBehaviorController::AddThread(CombatBehaviorThread* thread)
	{
		using func_t = decltype(&CombatBehaviorController::AddThread);
		REL::Relocation<func_t> func{ RELOCATION_ID(46100, 0) };  // I do not know for AE
		return func(this, thread);
	}

	void CombatBehaviorController::AddThreads(const BSTArray<CombatBehaviorThread*>& threads)
	{
		using func_t = decltype(&CombatBehaviorController::AddThreads);
		REL::Relocation<func_t> func{ RELOCATION_ID(46101, 0) };  // I do not know for AE
		return func(this, threads);
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

	void CombatBehaviorController::RemoveResource(CombatBehaviorResource* resource)
	{
		using func_t = decltype(&CombatBehaviorController::RemoveResource);
		REL::Relocation<func_t> func{ RELOCATION_ID(46107, 0) };  // I do not know for AE
		return func(this, resource);
	}

	void CombatBehaviorController::RemoveThread(CombatBehaviorThread* thread)
	{
		using func_t = decltype(&CombatBehaviorController::RemoveThread);
		REL::Relocation<func_t> func{ RELOCATION_ID(46103, 0) };  // I do not know for AE
		return func(this, thread);
	}

	void CombatBehaviorController::Start(CombatBehaviorTreeNode* start_node)
	{
		using func_t = decltype(&CombatBehaviorController::Start);
		REL::Relocation<func_t> func{ RELOCATION_ID(46096, 0) };  // I do not know for AE
		return func(this, start_node);
	}

	void CombatBehaviorController::QueueThread(CombatBehaviorThread* thread)
	{
		using func_t = decltype(&CombatBehaviorController::QueueThread);
		REL::Relocation<func_t> func{ RELOCATION_ID(46102, 0) };  // I do not know for AE
		return func(this, thread);
	}

	void CombatBehaviorController::Update()
	{
		using func_t = decltype(&CombatBehaviorController::Update);
		REL::Relocation<func_t> func{ RELOCATION_ID(46097, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorController::UpdateThread(CombatBehaviorThread* thread)
	{
		using func_t = decltype(&CombatBehaviorController::UpdateThread);
		REL::Relocation<func_t> func{ RELOCATION_ID(46098, 0) };  // I do not know for AE
		return func(this, thread);
	}
}
