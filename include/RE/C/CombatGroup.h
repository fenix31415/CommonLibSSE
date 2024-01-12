#pragma once

#include "RE/A/AIProcess.h"
#include "RE/A/AITimeStamp.h"
#include "RE/A/AITimer.h"
#include "RE/B/BGSWorldLocation.h"
#include "RE/B/BSAtomic.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CombatGroupDetectionListener.h"
#include "RE/C/CombatSearchLocation.h"
#include "RE/D/DetectionPriorities.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class Actor;
	class BSPathingLOSGridMap;
	class DetectionState;
	class TESObjectREFR;

	class CombatTarget
	{
	public:
		enum class Flags
		{
			kNone = 0,
			kTargetKnown = 1 << 0,
			kTargetLost = 1 << 1
		};

		// members
		ActorHandle                            targetHandle;                // 00
		std::int32_t                           detectLevel;                 // 04
		float                                  stealthPoints;               // 08
		float                                  unk0C;                       // 0C
		BGSWorldLocation                       lastKnownLoc;                // 10
		BGSWorldLocation                       LastDetectedLocation;        // 28
		BGSWorldLocation                       LastDetectedEventLocation;   // 40
		BGSWorldLocation                       searchLoc;                   // 58
		BGSWorldLocation                       unk70;                       // 70
		AITimeStamp                            lastDetectedEventTimeStamp;  // 88
		AITimeStamp                            lastDetectedTimeStamp;       // 8C
		AITimeStamp                            lastKnownTimeStamp;          // 90
		AITimeStamp                            lostTimeStamp;               // 94
		AITimeStamp                            lastAttackedTimeStamp;       // 98 - unk58
		AITimeStamp                            unk9C;                       // 9C - unk70
		ActorHandle                            attackedMember;              // A0
		std::uint16_t                          attackerCount;               // A4
		stl::enumeration<Flags, std::uint16_t> flags;                       // A6
	};
	static_assert(sizeof(CombatTarget) == 0xA8);

	class CombatMember
	{
	public:
		// members
		ActorHandle memberHandle;              // 00
		float       groupStrengthUpdateTimer;  // 04
		float       threatValue;               // 08
	};
	static_assert(sizeof(CombatMember) == 0x0C);

	struct CombatSearchDoor
	{
	public:
		// members
		ObjectRefHandle doorHandle;        // 00
		ObjectRefHandle linkedDoorHandle;  // 04
		std::uint8_t    unk08;             // 08
		std::uint8_t    unk09;             // 09
		std::uint8_t    unk0A;             // 0A
	};
	static_assert(sizeof(CombatSearchDoor) == 0xC);

	class CombatGroup
	{
	public:
		CombatGroup() = delete;
		CombatGroup(uint32_t ind);

		void                  AddDetectionListenerForMember(Actor* member);
		void                  AddDetectionListenerForTarget(Actor* target);
		bool                  AddMember(Actor* member);
		void                  AddSearchDoor(TESObjectREFR* a2);
		void                  AddSearchLocation(BGSWorldLocation& loc, float score, float timestamp);
		bool                  AddTarget(Actor* target);
		void                  BuildSearchTeleportDoorArray();
		void                  BuildTargetLastSeenLocationArray(BSTArray<NiPoint3>& ans, float event_interval) const;
		void                  CalculateDetectionLevel(CombatTarget* ctarget) const;
		bool                  CanAddMember(Actor* member) const;
		void                  ChangeGuardCombatToAlarm() const;
		void                  ChangeMemberProcessLevel(Actor* member, [[maybe_unused]] PROCESS_TYPE from, PROCESS_TYPE to);
		bool                  CheckRemoveCombatTarget(CombatTarget* ctarget) const;
		bool                  CheckSplitGroupForTarget(Actor* target);
		bool                  CheckTarget(Actor* target) const;
		bool                  CheckTargetValid(Actor* target) const;
		void                  ClearSearch();
		float                 ComputeMemberHealthPercentage() const;
		void                  ComputeSearchArea();
		void                  CopyTargets(CombatGroup* other);
		void                  DecrementAttackerCount(Actor* target);
		void                  FailedToInvestigateSearchDoor(TESObjectREFR* a2);
		void                  FillMemberArray(BSTArray<ActorHandle>& array) const;
		void                  FillTargetArray(BSTArray<ActorHandle>& array) const;
		Actor*                FindClosestMemberToLocation(BGSWorldLocation& loc, Actor* toSkip, float maxRange) const;
		Actor*                FindClosestTargetToLocation(BGSWorldLocation& loc, Actor* toSkip, bool onlyAttacked) const;
		Actor*                FindMemberNearActor(Actor* a, float inRange) const;
		Actor*                FindMemberNearLocation(BGSWorldLocation& near_loc, float inRange, Actor* toSkip) const;
		Actor*                FindRandomMember(Actor* toSkip) const;
		TESObjectREFR*        FindSearchDoor(Actor* member, float maxRange) const;
		CombatSearchLocation* FindSearchLocation(Actor* member, int32_t min_score, float fromTimestamp);
		Actor*                FindTargetNearLocation(BGSWorldLocation& near_loc, float inRange, bool ignoreUnknown) const;
		bool                  GetCombatGroupIsAggressor();
		CombatMember*         GetCombatMemberForActor(Actor* member);
		CombatSearchDoor*     GetCombatSearchDoor(TESObjectREFR* a2);
		CombatTarget*         GetCombatTargetForActor(Actor* target);
		int                   GetDetectionLevel(Actor* actor, Actor* target) const;
		float                 GetDPSRatioOfActor(Actor* a);
		int32_t               GetMaxTargetDetectionLevel() const;
		bool                  GetTargetDetectionData(Actor* target, int32_t& detect_level, AITimeStamp& lastDetected, bool& known, bool& lost) const;
		int32_t               GetTargetDetectionLevel(Actor* target) const;
		bool                  GetTargetKnown(Actor* target) const;
		bool                  GetTargetLastDetectedEventLocation(Actor* target, BGSWorldLocation& ans, float maxInterval) const;
		bool                  GetTargetLastDetectedLocation(Actor* target, BGSWorldLocation& ans) const;
		AITimeStamp           GetTargetLastDetectedTimeStamp(Actor* target) const;
		bool                  GetTargetLastKnownLocation(Actor* target, BGSWorldLocation& ans) const;
		bool                  GetTargetLost(Actor* target) const;
		float                 GetTargetStealthPoints(Actor* target) const;
		float                 GetThreatRatioOfActor(Actor* a);
		void                  IncrementAttackerCount(Actor* target);
		void                  InvestigatedSearchDoor(TESObjectREFR* a2);
		void                  InvestigatedSearchLocation(const BGSWorldLocation& loc);
		bool                  IsEmpty() const;
		bool                  IsFleeing() const;
		Actor*                IsInCombatWithGuard() const;
		bool                  IsMember(Actor* a) const;
		bool                  IsMember(const ActorHandle& handle) const;
		bool                  IsSearching() const;
		bool                  IsTarget(Actor* a) const;
		bool                  IsTarget(const ActorHandle& target) const;
		bool                  MergeGroups(CombatGroup* other);
		void                  NotifyMemberAttacked(Actor* member, Actor* attacker);
		void                  NotifyMemberKilled(Actor* killer, Actor* member);
		void                  RemoveAllMembers();
		void                  RemoveMember(Actor* member);
		void                  RemoveTarget(Actor* target);
		void                  RemoveTarget(int32_t ind);
		void                  ReserveSearchDoor(TESObjectREFR* a2);
		void                  SetSearchingMember(Actor* member);
		void                  StartSearch();
		void                  StopCombat();
		void*                 UnreserveSearchDoor(TESObjectREFR* a2);
		void                  Update();
		void                  UpdateAttackerCounts();
		void                  UpdateCombatStrength();
		void                  UpdateCounts();
		DETECTION_PRIORITY    UpdateDetection(Actor* member, Actor* target, DetectionState* detect_state);
		void                  UpdateMembers();
		void                  UpdateSearch();
		bool                  UpdateSearchArea();
		void                  UpdateSearchLocations();
		void                  UpdateStealthPoints();
		void                  UpdateTargets();

		// members
		std::uint32_t                  groupID;                      // 000
		std::uint32_t                  groupIndex;                   // 004
		BSTArray<CombatTarget>         targets;                      // 008
		BSTArray<CombatMember>         members;                      // 020
		CombatGroupDetectionListener*  detectionListener;            // 038
		AITimer                        allyKilledTimer;              // 040
		AITimer                        avoidThreathTimer;            // 048
		AITimer                        UpdateStrenghtTimer;          // 050
		AITimer                        detectionDialogueTimers[11];  // 058
		AITimer                        updateTimer;                  // 0B0
		AITimer                        musicThreatRatioTimer;        // 0B8
		AITimer                        UpdateStealthTimer;           // 0C0
		float                          MembersThreatRatio;           // 0C8
		float                          dpsAvg;                       // 0CC
		float                          TargetsThreatRatio;           // 0D0
		float                          ThreatRatioAvg;               // 0D4
		std::uint32_t                  searchState;                  // 0D8
		std::uint32_t                  padDC;                        // 0DC
		BSPathingLOSGridMap*           gridMap;                      // 0E0
		AITimer                        searchUpdateTimer;            // 0E8
		AITimer                        searchAreaUpdateTimer;        // 0F0
		AITimeStamp                    unkF8;                        // 0F8
		ActorHandle                    searchingMember;              // 0FC
		BGSWorldLocation               searchTargetLoc;              // 100
		float                          searchRadius;                 // 118
		std::uint32_t                  unk11C;                       // 11C
		BSTArray<CombatSearchLocation> searchLocations;              // 120
		BSTArray<CombatSearchDoor>     searchDoors;                  // 138
		std::uint32_t                  unk150;                       // 150 - count
		std::uint32_t                  fleeCount;                    // 154
		std::uint32_t                  fightCount;                   // 158
		std::uint8_t                   musicState;                   // 15C
		std::uint8_t                   unk15D;                       // 15D
		std::uint8_t                   unk15E;                       // 15E
		std::uint8_t                   unk15F;                       // 15F
		mutable BSReadWriteLock        lock;                         // 160
	};
	static_assert(sizeof(CombatGroup) == 0x168);
}
