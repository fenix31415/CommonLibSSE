#include "RE/C/CombatBehaviorResource.h"

namespace RE
{
	CombatBehaviorResource* CombatBehaviorResource::Ctor(CombatBehaviorResource* a_this, CombatBehaviorController* controller, const BSFixedString& name)
	{
		using func_t = decltype(&CombatBehaviorResource::Ctor);
		REL::Relocation<func_t> func{ RELOCATION_ID(46198, 0) };  // I do not know for AE
		return func(a_this, controller, name);
	}

	bool CombatBehaviorResource::AcquireResource(CombatBehaviorThread* thread, uint32_t priority, bool can_suspend)
	{
		using func_t = decltype(&CombatBehaviorResource::AcquireResource);
		REL::Relocation<func_t> func{ RELOCATION_ID(46200, 0) };  // I do not know for AE
		return func(this, thread, priority, can_suspend);
	}

	void CombatBehaviorResource::ClearOwner(CombatBehaviorThread* thread)
	{
		using func_t = decltype(&CombatBehaviorResource::ClearOwner);
		REL::Relocation<func_t> func{ RELOCATION_ID(46203, 0) };  // I do not know for AE
		return func(this, thread);
	}

	void CombatBehaviorResource::ReleaseResource(CombatBehaviorThread* thread)
	{
		using func_t = decltype(&CombatBehaviorResource::ReleaseResource);
		REL::Relocation<func_t> func{ RELOCATION_ID(46201, 0) };  // I do not know for AE
		return func(this, thread);
	}
}
