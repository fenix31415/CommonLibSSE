#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/C/CombatBehaviorThread.h"

namespace RE
{
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;

	class CombatBehaviorTreeNode
	{
	public:
		virtual ~CombatBehaviorTreeNode() = default;
		virtual const char*          GetName() const { return name.c_str(); }
		virtual void                 Enter(CombatBehaviorThread*) {}
		virtual void                 Exit(CombatBehaviorThread*) {}
		virtual void                 Update(CombatBehaviorThread* thread) { thread->Ascend(); }
		virtual void                 Abort(CombatBehaviorThread* thread) { thread->Ascend(); }
		virtual void                 SaveGame(CombatBehaviorThread*, BGSSaveFormBuffer*) {}
		virtual void                 LoadGame(CombatBehaviorThread*, BGSLoadFormBuffer*) {}
		virtual bool                 Validate(CombatBehaviorTreeNode*) const { return true; }
		virtual const BSFixedString& GetType() const { return name; }

		CombatBehaviorTreeNode();
		CombatBehaviorTreeNode(const CombatBehaviorTreeNode&) = delete;
		CombatBehaviorTreeNode& operator=(CombatBehaviorTreeNode&) = delete;
		void                    AddChild(class CombatBehaviorTreeNode*);
		CombatBehaviorTreeNode* GetRoot();
		void                    SetVftable(REL::ID id);

		TES_HEAP_REDEFINE_NEW();

		// members
		BSFixedString                          name;      // 08
		CombatBehaviorTreeNode*                parent;    // 10
		BSStaticArray<CombatBehaviorTreeNode*> children;  // 18
	};
	static_assert(sizeof(CombatBehaviorTreeNode) == 0x28);

	class CombatBehaviorBranch
	{
	public:
		static bool Validate(CombatBehaviorTreeNode*);
	};
}
