#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/B/BSAtomic.h"
#include "RE/B/BSContainer.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/C/CombatMathUtilities.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class Actor;
	class BGSExplosion;
	class CombatThreat;
	class Projectile;
	class NiPoint3;
	class TESForm;
	class TESObjectREFR;

	class CombatThreatMap
	{
	public:
		void          AddThreat(Projectile* proj);
		void          AddThreat(TESObjectREFR* refr, BGSExplosion* expl, float expl_time);
		void          AddThreat(TESObjectREFR* refr, float range, float expl_time, float damage);
		float         FindAnticipatedThreats(Actor* actor, float time, BSScrapArray<CombatThreat*>& ans) const;
		float         FindThreats(Actor* actor, const NiPoint3& actor_pos, float time, BSScrapArray<CombatThreat*>& ans);
		float         FindThreats(Actor* actor, const CombatMathUtilities::MovingCapsule& actor_capsule, float time, BSScrapArray<CombatThreat*>& ans);
		void          ForEachThreat(std::function<BSContainer::ForEachResult(const CombatThreat&)> fun) const;
		CombatThreat* GetThreat(FormID threat);
		void          RemoveAllThreats();
		void          RemoveThreat(TESForm* threat);
		uint32_t      ThreatCount() const;
		void          UpdateThreats();

		// members
		BSTHashMap<FormID, NiPointer<CombatThreat>> threats;                   // 00
		mutable BSReadWriteLock                     lock;                      // 30
		AITimeStamp                                 lastThreatAddedTimeStamp;  // 38
	};
	static_assert(sizeof(CombatThreatMap) == 0x40);
}
