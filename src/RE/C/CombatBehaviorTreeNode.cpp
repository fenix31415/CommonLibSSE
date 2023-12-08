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

	int32_t CombatBehaviorTreeNode::FindChildIndex(const BSFixedString& ch_name) const
	{
		using func_t = decltype(&CombatBehaviorTreeNode::FindChildIndex);
		REL::Relocation<func_t> func{ RELOCATION_ID(46307, 0) };  // I do not know for AE
		return func(this, ch_name);
	}

	CombatBehaviorTreeNode* CombatBehaviorTreeNode::FindChild(const BSFixedString& ch_name) const
	{
		using func_t = decltype(&CombatBehaviorTreeNode::FindChild);
		REL::Relocation<func_t> func{ RELOCATION_ID(46306, 0) };  // I do not know for AE
		return func(this, ch_name);
	}
}
