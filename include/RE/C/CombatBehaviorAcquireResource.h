#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/C/CombatBehavior.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class CombatBehaviorResource;
	class CombatBehaviorThread;

	class CombatBehaviorAcquireResource : public CombatBehavior
	{
	public:
		enum class Flags : uint32_t
		{
			kMaySuspendOwner = 1 << 0,
			kSingleTry = 1 << 1,
			kUnk2 = 1 << 2,
			kOwning = (uint32_t)1 << 31
		};
		using FLAG = stl::enumeration<Flags, uint32_t>;

		static bool Validate(CombatBehaviorTreeNode* node);

		CombatBehaviorAcquireResource(const BSFixedString& name, uint32_t priority, FLAG flags);

		void Abort();
		void Enter();
		void Exit();
		void Update();

		// members
		NiPointer<CombatBehaviorResource> resource;      // 00
		uint32_t                          priority;      // 08
		FLAG                              flags;         // 0C
		CombatBehaviorThread*             child_thread;  // 10
	};
	static_assert(sizeof(CombatBehaviorAcquireResource) == 0x18);
}
