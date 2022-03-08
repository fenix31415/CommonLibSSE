#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSTSingleton.h"
#include "RE/C/CombatGroup.h"
#include "RE/N/NiTArray.h"

namespace RE
{
	class CombatManager : public BSTSingletonSDM<CombatManager>
	{
	public:
		[[nodiscard]] static CombatManager* GetSingleton()
		{
			REL::Relocation<CombatManager**> singleton{ REL::ID(405246) };
			return *singleton;
		}

		// members
		NiTPrimitiveArray<CombatGroup*> combatGroups;      // 00
		mutable BSReadWriteLock         lock;              // 18
		std::uint64_t                   unk20;             // 20
		std::uint64_t                   combatThreats;     // 28
		std::uint64_t                   unk30;             // 30
		std::uint64_t                   unk38;             // 38
		std::uint64_t                   unk40;             // 40
		float                           unk48;             // 48
		AITimer                         musicStopTimer;    // 4C
		AITimer                         musicUpdateTimer;  // 54
		std::uint32_t                   combatCount;       // 5C
		std::uint32_t                   groupCount;        // 60
		std::uint32_t                   unk64;             // 64
	};
	static_assert(sizeof(CombatManager) == 0x68);
}
