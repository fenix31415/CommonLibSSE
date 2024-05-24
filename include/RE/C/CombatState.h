#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/A/AITimer.h"
#include "RE/B/BGSWorldLocation.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class CombatController;
	class CombatThreat;

	struct UnreachableLocation
	{
	public:
		// members
		BGSWorldLocation loc;        // 00
		AITimeStamp      timestamp;  // 18
		std::uint32_t    pad1C;      // 1C
	};
	static_assert(sizeof(UnreachableLocation) == 0x20);

	class CombatState
	{
	public:
		bool CheckShouldFlee() const;
		bool CheckShouldHide() const;
		bool QTargetLost() const;

		// members
		float                             actor_threatRatio_fraction;   // 00
		bool                              isFleeing;                    // 04
		bool                              isDetected;                   // 05
		bool                              targetLost;                   // 06
		std::uint8_t                      unk07;                        // 07
		std::uint8_t                      unk08;                        // 08
		std::uint8_t                      hasTargetLOS;                 // 09
		std::uint8_t                      unk0A;                        // 0A
		std::uint8_t                      unk0B;                        // 0B
		std::uint32_t                     targeted_los_location;        // 0C
		NiPoint3                          lastSeenPos;                  // 10
		AITimeStamp                       activeCombatantLastSeenTime;  // 1C
		AITimeStamp                       unk20;                        // 20
		AITimeStamp                       last_attack;                  // 24
		AITimeStamp                       last_damaged;                 // 28
		AITimer                           attackDialogueTimer;          // 2C
		AITimer                           tauntDialogueTimer;           // 34
		AITimer                           bleedOutDialogueTimer;        // 3C
		AITimer                           fleeDialogueTimer;            // 44
		float                             total_threat_damage;          // 4C
		BSTArray<NiPointer<CombatThreat>> combatThreats;                // 50
		AITimeStamp                       threat_seen;                  // 68
		std::uint8_t                      confidence_another;           // 6C
		std::uint8_t                      confidence;                   // 6D
		uint16_t                          pad6E;                        // 6E
		float                             confidenceModifier;           // 70
		float                             threatValue;                  // 74
		float                             dps;                          // 78
		std::uint32_t                     unk7C;                        // 7C
		BSTArray<UnreachableLocation>     unreachableLocations;         // 80
		CombatController*                 controller;                   // 98
		std::uint8_t                      unkA0;                        // A0
		AITimer                           strengthUpdateTimer;          // A4
		AITimer                           threatRatioUpdateTimer;       // AC
		AITimer                           threatUpdateTimer;            // B4
		uint32_t                          padBC;                        // BC
	};
	static_assert(sizeof(CombatState) == 0xC0);
}
