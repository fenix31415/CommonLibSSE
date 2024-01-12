#pragma once

#include "RE/A/AITimer.h"
#include "RE/B/BSTHashMap.h"
#include "RE/C/CombatThreatMap.h"
#include "RE/N/NiTArray.h"

namespace RE
{
	class CombatGroup;

	class CombatManager
	{
	public:
		[[nodiscard]] static CombatManager* GetSingleton()
		{
			REL::Relocation<CombatManager**> singleton{ RELOCATION_ID(518706, 405246) };
			return *singleton;
		}

		// members
		NiTPrimitiveArray<CombatGroup*>    combatGroups;      // 00
		mutable BSReadWriteLock            lock;              // 18
		BSTHashMap<ActorHandle, uint64_t>* localActors;       // 20
		CombatThreatMap*                   combatThreatMap;   // 28
		std::uint64_t                      unk30;             // 30
		std::uint64_t                      unk38;             // 38
		std::uint64_t                      unk40;             // 40
		float                              unk48;             // 48
		AITimer                            musicStopTimer;    // 4C
		AITimer                            musicUpdateTimer;  // 54
		std::uint32_t                      combatCount;       // 5C
		std::uint32_t                      groupCount;        // 60
		std::uint32_t                      unk64;             // 64
	};
	static_assert(sizeof(CombatManager) == 0x68);
}
