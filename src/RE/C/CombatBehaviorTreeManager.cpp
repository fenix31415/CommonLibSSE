#include "RE/C/CombatBehaviorTreeManager.h"

namespace RE
{
	const CombatBehaviorTree* CombatBehaviorTreeManager::FindTree(BSFixedString const& name) const
	{
		using func_t = decltype(&CombatBehaviorTreeManager::FindTree);
		REL::Relocation<func_t> func{ RELOCATION_ID(46272, 0) };  // I do not know for AE
		return func(this, name);
	}

	const CombatBehaviorTreeNode* CombatBehaviorTreeManager::FindRootNode(BSFixedString const& name) const
	{
		using func_t = decltype(&CombatBehaviorTreeManager::FindRootNode);
		REL::Relocation<func_t> func{ RELOCATION_ID(46273, 0) };  // I do not know for AE
		return func(this, name);
	}

	void CombatBehaviorTreeManager::RegisterBehaviorTree(CombatBehaviorTree* tree)
	{
		using func_t = decltype(&CombatBehaviorTreeManager::RegisterBehaviorTree);
		REL::Relocation<func_t> func{ RELOCATION_ID(46271, 0) };  // I do not know for AE
		return func(this, tree);
	}

	void CombatBehaviorTreeManager::Init()
	{
		using func_t = decltype(&CombatBehaviorTreeManager::Init);
		REL::Relocation<func_t> func{ RELOCATION_ID(46274, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorTreeManager::InitializeTrees()
	{
		using func_t = decltype(&CombatBehaviorTreeManager::InitializeTrees);
		REL::Relocation<func_t> func{ RELOCATION_ID(46275, 0) };  // I do not know for AE
		return func(this);
	}
}
