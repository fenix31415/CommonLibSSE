#pragma once

namespace RE
{
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;
	class CombatBehaviorThread;
	class CombatBehaviorTreeNode;

	class CombatBehavior
	{
	public:
		static bool Validate(CombatBehaviorTreeNode* node);  // ch.empty

		void                  Abort();  // Ascend
		bool                  CheckTargetChanged();
		CombatBehaviorThread* CreateChildThread(uint32_t child_ind, bool isControlChild);
		void                  Enter() {}
		void                  Exit() {}
		void                  LoadGame(BGSLoadFormBuffer*) {}
		void                  SaveGame(BGSSaveFormBuffer*) {}
		void                  StartChildThread(CombatBehaviorThread* thread, uint32_t child_ind, bool isControlChild);
		void                  Update();  // Ascend
	};
}
