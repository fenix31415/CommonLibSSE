#include "RE/C/CombatBehaviorTreeNode.h"

namespace RE
{
	CombatBehaviorTreeNode::CombatBehaviorTreeNode()
	{
		using func_t = CombatBehaviorTreeNode*(CombatBehaviorTreeNode*);
		REL::Relocation<func_t> func{ RELOCATION_ID(46301, 0) };  // I do not know for AE
		func(this);
	}

	void CombatBehaviorTreeNode::AddChild(CombatBehaviorTreeNode* node)
	{
		using func_t = decltype(&CombatBehaviorTreeNode::AddChild);
		REL::Relocation<func_t> func{ RELOCATION_ID(46304, 0) };  // I do not know for AE
		return func(this, node);
	}

	CombatBehaviorTreeNode* CombatBehaviorTreeNode::GetRoot()
	{
		CombatBehaviorTreeNode* cur = this;
		while (cur->parent)
			cur = cur->parent;
		return cur;
	}

	void CombatBehaviorTreeNode::SetVftable(REL::ID id)
	{
		*(uint64_t*)this = id.address();
	}

	bool CombatBehaviorBranch::Validate(CombatBehaviorTreeNode* node)
	{
		using func_t = decltype(&CombatBehaviorBranch::Validate);
		REL::Relocation<func_t> func{ RELOCATION_ID(46093, 0) };  // I do not know for AE
		return func(node);
	}
}
