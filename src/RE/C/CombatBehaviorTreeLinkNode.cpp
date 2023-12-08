#include "RE/C/CombatBehaviorTreeLinkNode.h"

namespace RE
{
	void CombatBehaviorTreeLinkNode::Enter(CombatBehaviorThread* thread)
	{
		using func_t = decltype(&CombatBehaviorTreeLinkNode::Enter);
		REL::Relocation<func_t> func{ RELOCATION_ID(46330, 0) };  // I do not know for AE
		return func(this, thread);
	}

	bool CombatBehaviorTreeLinkNode::Validate(CombatBehaviorTreeNode* node) const
	{
		using func_t = decltype(&CombatBehaviorTreeLinkNode::Validate);
		REL::Relocation<func_t> func{ RELOCATION_ID(46331, 0) };  // I do not know for AE
		return func(this, node);
	}

	const BSFixedString& CombatBehaviorTreeLinkNode::GetType() const
	{
		using func_t = decltype(&CombatBehaviorTreeLinkNode::GetType);
		REL::Relocation<func_t> func{ RELOCATION_ID(46332, 0) };  // I do not know for AE
		return func(this);
	}
}
