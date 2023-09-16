#include "RE/C/CombatBehaviorAcquireResource.h"

#include "RE/C/CombatBehaviorController.h"
#include "RE/C/CombatBehaviorThread.h"
#include "RE/C/CombatBehaviorTreeNode.h"
#include "RE/T/TLSData.h"

namespace RE
{
	bool CombatBehaviorAcquireResource::Validate(CombatBehaviorTreeNode* node)
	{
		return CombatBehaviorBranch::Validate(node);
	}

	CombatBehaviorAcquireResource::CombatBehaviorAcquireResource(const BSFixedString& name, uint32_t priority, FLAG flags) :
		resource(nullptr), priority(priority), flags(flags), child_thread(child_thread)
	{
		GetStaticTLSData()->combatAIThread->control->GetResource(name, resource);
	}

	void CombatBehaviorAcquireResource::Abort()
	{
		using func_t = decltype(&CombatBehaviorAcquireResource::Abort);
		REL::Relocation<func_t> func{ RELOCATION_ID(46212, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorAcquireResource::Enter()
	{
		using func_t = decltype(&CombatBehaviorAcquireResource::Abort);
		REL::Relocation<func_t> func{ RELOCATION_ID(46209, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorAcquireResource::Exit()
	{
		using func_t = decltype(&CombatBehaviorAcquireResource::Abort);
		REL::Relocation<func_t> func{ RELOCATION_ID(46211, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorAcquireResource::Update()
	{
		using func_t = decltype(&CombatBehaviorAcquireResource::Abort);
		REL::Relocation<func_t> func{ RELOCATION_ID(46210, 0) };  // I do not know for AE
		return func(this);
	}
}
