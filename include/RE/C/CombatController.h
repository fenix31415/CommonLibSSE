#pragma once

#include "RE/A/AITimer.h"
#include "RE/B/BSAtomic.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CombatState.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class Actor;
	struct BGSWorldLocation;
	class CombatAimController;
	class CombatAreaStandard;
	class CombatBehaviorController;
	class CombatBlackboard;
	class CombatGroup;
	class CombatInventory;
	class CombatPathingRequest;
	class CombatState;
	class CombatTargetSelector;
	class NiPoint3;
	class TESBoundObject;
	class TESCombatStyle;

	class CombatController
	{
	public:
		enum class COMBAT_STANCE : uint8_t
		{
			None,
			Sneak
		};

		void               ActivatedReference(TESObjectREFR* refr, TESBoundObject* refr_base, int targetCount, bool a5);
		void               AddAimController(CombatAimController* control);
		void               AddCombatArea(CombatAreaStandard* area);
		void               AddTarget(Actor* target);
		void               AddTargetSelector(CombatTargetSelector* selector);
		void               AttackedBy(Actor* attacker);
		void               CacheActorHandles();
		void               ChangeStance(COMBAT_STANCE stance);
		bool               CheckCombatArea(Actor* atatcker) const;
		bool               CheckLOS(const NiPoint3& P) const;
		bool               CheckMovement(BGSWorldLocation* location, float radius) const;
		bool               CheckStraightPath(NiPoint3& dst, float speed, float min_dist = -1.0f) const;
		bool               CheckTargetReachable(float dist) const;
		void               DamagedByAttacker(Actor* attacker, float damage);
		void               Disarmed();
		void               FiredProjectile();
		void               ForceUpdateCombatArea();
		bool               GetAimLocation(NiPoint3& aim) const;
		bool               GetAimLocation(void* mcaster_or_weap, NiPoint3& aim) const;
		ActorHandle        GetAimTarget(void* mcaster_or_weap) const;
		bool               IsActoraCombatTarget(Actor* actor) const;
		[[nodiscard]] bool IsFleeing() const { return state->isFleeing; }
		bool               IsSearching() const;
		bool               IsTargetReachable(float distance) const;
		void               PauseCombat();
		void               PerformedMeleeAttack();
		void               ReloadingWeapon();
		void               RemoveAimController(CombatAimController* control);
		void               RemoveTarget(Actor* target);
		void               RemoveTargetSelector(CombatTargetSelector* selector);
		void               SetInactive(bool inactive);
		void               SetInventoryDirty(bool dirty);
		void               SetTarget(Actor* target);
		void               SetupPathingRequest(CombatPathingRequest* request) const;
		bool               ShouldStopCombat();
		void               ShutdownCombat();
		void               TargetChanged();
		void               UnCacheActorHandles();
		void               UnPauseCombat();
		void               UpdateAimLocation();

		// members
		CombatGroup*                   combatGroup;           // 00
		CombatState*                   state;                 // 08
		CombatInventory*               inventory;             // 10
		CombatBlackboard*              blackboard;            // 18
		CombatBehaviorController*      behaviorController;    // 20
		ActorHandle                    attackerHandle;        // 28
		ActorHandle                    targetHandle;          // 2C
		ActorHandle                    previousTargetHandle;  // 30
		COMBAT_STANCE                  stance;                // 34
		bool                           startedCombat;         // 35
		std::uint8_t                   unk36;                 // 36
		std::uint8_t                   unk37;                 // 37
		TESCombatStyle*                combatStyle;           // 38
		bool                           stoppedCombat;         // 40
		bool                           unk41;                 // 41 - isbeingMeleeAttacked?
		bool                           ignoringCombat;        // 42
		bool                           inactive;              // 43
		AITimer                        unk44;                 // 44
		float                          unk4C;                 // 4C
		BSTArray<CombatAimController*> aimControllers;        // 50
#ifdef SKYRIM_SUPPORT_AE
		mutable BSSpinLock aimControllerLock;  // 68
#endif
		CombatAimController*            currentAimController;    // 68
		CombatAimController*            previousAimController;   // 70
		BSTArray<CombatAreaStandard*>   areas;                   // 78
		CombatAreaStandard*             currentArea;             // 90
		BSTArray<CombatTargetSelector*> targetSelectors;         // 98
		CombatTargetSelector*           currentTargetSelector;   // B0
		CombatTargetSelector*           previousTargetSelector;  // B8
		std::uint32_t                   handleCount;             // C0
		std::int32_t                    unkC4;                   // C4
		NiPointer<Actor>                cachedAttacker;          // C8 - attackerHandle
		NiPointer<Actor>                cachedTarget;            // D0 - targetHandle
	};
#ifndef SKYRIM_SUPPORT_AE
	static_assert(sizeof(CombatController) == 0xD8);
#else
	static_assert(sizeof(CombatController) == 0xE0);
#endif
}
