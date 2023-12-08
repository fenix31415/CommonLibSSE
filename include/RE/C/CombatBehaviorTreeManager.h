#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTHashMap.h"

namespace RE
{
	class CombatBehaviorTree;
	class CombatBehaviorTreeNode;

	class CombatBehaviorTreeManager
	{
	public:
		const CombatBehaviorTreeNode* FindRootNode(const BSFixedString& name) const;
		const CombatBehaviorTree*     FindTree(const BSFixedString& name) const;
		void                          Init();
		void                          InitializeTrees();
		void                          RegisterBehaviorTree(CombatBehaviorTree* tree);

		// members
		BSTHashMap<BSFixedString, CombatBehaviorTree*> trees;
	};
	static_assert(sizeof(CombatBehaviorTreeManager) == 0x30);
}
