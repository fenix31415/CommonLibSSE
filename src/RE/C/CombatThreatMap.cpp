#include "RE/C/CombatThreatMap.h"

namespace RE
{
	void CombatThreatMap::AddThreat(Projectile* proj)
	{
		using func_t = void(CombatThreatMap*, Projectile*);
		REL::Relocation<func_t> func{ RELOCATION_ID(45965, 0) };  // I do not know for AE
		return func(this, proj);
	}

	void CombatThreatMap::AddThreat(TESObjectREFR* refr, BGSExplosion* expl, float expl_time)
	{
		using func_t = void(CombatThreatMap*, TESObjectREFR*, BGSExplosion*, float);
		REL::Relocation<func_t> func{ RELOCATION_ID(45966, 0) };  // I do not know for AE
		return func(this, refr, expl, expl_time);
	}

	void CombatThreatMap::AddThreat(TESObjectREFR* refr, float range, float expl_time, float damage)
	{
		using func_t = void(CombatThreatMap*, TESObjectREFR*, float, float, float);
		REL::Relocation<func_t> func{ RELOCATION_ID(45973, 0) };  // I do not know for AE
		return func(this, refr, range, expl_time, damage);
	}

	float CombatThreatMap::FindAnticipatedThreats(Actor* actor, float time, BSScrapArray<CombatThreat*>& ans) const
	{
		using func_t = decltype(&CombatThreatMap::FindAnticipatedThreats);
		REL::Relocation<func_t> func{ RELOCATION_ID(45647, 0) };  // I do not know for AE
		return func(this, actor, time, ans);
	}

	float CombatThreatMap::FindThreats(Actor* actor, const NiPoint3& actor_pos, float time, BSScrapArray<CombatThreat*>& ans)
	{
		using func_t = float(CombatThreatMap*, Actor*, const NiPoint3&, float, BSScrapArray<CombatThreat*>& ans);
		REL::Relocation<func_t> func{ RELOCATION_ID(45969, 0) };  // I do not know for AE
		return func(this, actor, actor_pos, time, ans);
	}

	void CombatThreatMap::ForEachThreat(std::function<BSContainer::ForEachResult(const CombatThreat&)> fun) const
	{
		lock.LockForRead();
		for (const auto& threat : threats) {
			if (fun(*threat.second.get()) == RE::BSContainer::ForEachResult::kStop)
				break;
		}
		lock.UnlockForRead();
	}

	CombatThreat* CombatThreatMap::GetThreat(FormID threat)
	{
		using func_t = decltype(&CombatThreatMap::GetThreat);
		REL::Relocation<func_t> func{ RELOCATION_ID(45967, 0) };  // I do not know for AE
		return func(this, threat);
	}

	void CombatThreatMap::RemoveAllThreats()
	{
		using func_t = decltype(&CombatThreatMap::RemoveAllThreats);
		REL::Relocation<func_t> func{ RELOCATION_ID(45964, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatThreatMap::RemoveThreat(TESForm* threat)
	{
		using func_t = decltype(&CombatThreatMap::RemoveThreat);
		REL::Relocation<func_t> func{ RELOCATION_ID(45963, 0) };  // I do not know for AE
		return func(this, threat);
	}

	uint32_t CombatThreatMap::ThreatCount() const
	{
		return threats.size();
	}

	void CombatThreatMap::UpdateThreats()
	{
		using func_t = decltype(&CombatThreatMap::UpdateThreats);
		REL::Relocation<func_t> func{ RELOCATION_ID(45962, 0) };  // I do not know for AE
		return func(this);
	}
}
