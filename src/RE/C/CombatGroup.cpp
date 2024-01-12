#include "RE/C/CombatGroup.h"

namespace RE
{
	CombatGroup::CombatGroup(uint32_t ind)
	{
		using func_t = CombatGroup*(CombatGroup*, uint32_t);
		REL::Relocation<func_t> func{ RELOCATION_ID(43479, 0) };  // I do not know for AE
		func(this, ind);
	}

	void CombatGroup::AddDetectionListenerForMember(Actor* member)
	{
		using func_t = decltype(&CombatGroup::AddDetectionListenerForMember);
		REL::Relocation<func_t> func{ RELOCATION_ID(43562, 0) };  // I do not know for AE
		return func(this, member);
	}

	void CombatGroup::AddDetectionListenerForTarget(Actor* target)
	{
		using func_t = decltype(&CombatGroup::AddDetectionListenerForTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(43563, 0) };  // I do not know for AE
		return func(this, target);
	}

	bool CombatGroup::AddMember(Actor* member)
	{
		using func_t = decltype(&CombatGroup::AddMember);
		REL::Relocation<func_t> func{ RELOCATION_ID(43489, 0) };  // I do not know for AE
		return func(this, member);
	}

	void CombatGroup::AddSearchDoor(TESObjectREFR* a2)
	{
		using func_t = decltype(&CombatGroup::AddSearchDoor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43547, 0) };  // I do not know for AE
		return func(this, a2);
	}

	void CombatGroup::AddSearchLocation(BGSWorldLocation& loc, float score, float timestamp)
	{
		using func_t = decltype(&CombatGroup::AddSearchLocation);
		REL::Relocation<func_t> func{ RELOCATION_ID(43544, 0) };  // I do not know for AE
		return func(this, loc, score, timestamp);
	}

	bool CombatGroup::AddTarget(Actor* target)
	{
		using func_t = decltype(&CombatGroup::AddTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(43482, 0) };  // I do not know for AE
		return func(this, target);
	}

	void CombatGroup::BuildSearchTeleportDoorArray()
	{
		using func_t = decltype(&CombatGroup::BuildSearchTeleportDoorArray);
		REL::Relocation<func_t> func{ RELOCATION_ID(43539, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatGroup::BuildTargetLastSeenLocationArray(BSTArray<NiPoint3>& ans, float event_interval) const
	{
		using func_t = decltype(&CombatGroup::BuildTargetLastSeenLocationArray);
		REL::Relocation<func_t> func{ RELOCATION_ID(43511, 0) };  // I do not know for AE
		return func(this, ans, event_interval);
	}

	void CombatGroup::CalculateDetectionLevel(CombatTarget* ctarget) const
	{
		using func_t = decltype(&CombatGroup::CalculateDetectionLevel);
		REL::Relocation<func_t> func{ RELOCATION_ID(43560, 0) };  // I do not know for AE
		return func(this, ctarget);
	}

	bool CombatGroup::CanAddMember(Actor* member) const
	{
		using func_t = decltype(&CombatGroup::CanAddMember);
		REL::Relocation<func_t> func{ RELOCATION_ID(43493, 0) };  // I do not know for AE
		return func(this, member);
	}

	void CombatGroup::ChangeGuardCombatToAlarm() const
	{
		using func_t = decltype(&CombatGroup::ChangeGuardCombatToAlarm);
		REL::Relocation<func_t> func{ RELOCATION_ID(43532, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatGroup::ChangeMemberProcessLevel(Actor* member, PROCESS_TYPE from, PROCESS_TYPE to)
	{
		using func_t = decltype(&CombatGroup::ChangeMemberProcessLevel);
		REL::Relocation<func_t> func{ RELOCATION_ID(43556, 0) };  // I do not know for AE
		return func(this, member, from, to);
	}

	bool CombatGroup::CheckRemoveCombatTarget(CombatTarget* ctarget) const
	{
		using func_t = decltype(&CombatGroup::CheckRemoveCombatTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(43567, 0) };  // I do not know for AE
		return func(this, ctarget);
	}

	bool CombatGroup::CheckSplitGroupForTarget(Actor* target)
	{
		using func_t = decltype(&CombatGroup::CheckSplitGroupForTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(43486, 0) };  // I do not know for AE
		return func(this, target);
	}

	bool CombatGroup::CheckTarget(Actor* target) const
	{
		using func_t = decltype(&CombatGroup::CheckTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(43568, 0) };  // I do not know for AE
		return func(this, target);
	}

	bool CombatGroup::CheckTargetValid(Actor* target) const
	{
		using func_t = decltype(&CombatGroup::CheckTargetValid);
		REL::Relocation<func_t> func{ RELOCATION_ID(43530, 0) };  // I do not know for AE
		return func(this, target);
	}

	void CombatGroup::ClearSearch()
	{
		using func_t = decltype(&CombatGroup::ClearSearch);
		REL::Relocation<func_t> func{ RELOCATION_ID(43540, 0) };  // I do not know for AE
		return func(this);
	}

	float CombatGroup::ComputeMemberHealthPercentage() const
	{
		using func_t = decltype(&CombatGroup::ComputeMemberHealthPercentage);
		REL::Relocation<func_t> func{ RELOCATION_ID(43529, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatGroup::ComputeSearchArea()
	{
		using func_t = decltype(&CombatGroup::ComputeSearchArea);
		REL::Relocation<func_t> func{ RELOCATION_ID(43537, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatGroup::CopyTargets(CombatGroup* other)
	{
		using func_t = decltype(&CombatGroup::CopyTargets);
		REL::Relocation<func_t> func{ RELOCATION_ID(43487, 0) };  // I do not know for AE
		return func(this, other);
	}

	void CombatGroup::DecrementAttackerCount(Actor* target)
	{
		using func_t = decltype(&CombatGroup::DecrementAttackerCount);
		REL::Relocation<func_t> func{ RELOCATION_ID(43499, 0) };  // I do not know for AE
		return func(this, target);
	}

	void CombatGroup::FailedToInvestigateSearchDoor(TESObjectREFR* a2)
	{
		using func_t = decltype(&CombatGroup::FailedToInvestigateSearchDoor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43549, 0) };  // I do not know for AE
		return func(this, a2);
	}

	void CombatGroup::FillMemberArray(BSTArray<ActorHandle>& array) const
	{
		using func_t = decltype(&CombatGroup::FillMemberArray);
		REL::Relocation<func_t> func{ RELOCATION_ID(43494, 0) };  // I do not know for AE
		return func(this, array);
	}

	void CombatGroup::FillTargetArray(BSTArray<ActorHandle>& array) const
	{
		using func_t = decltype(&CombatGroup::FillTargetArray);
		REL::Relocation<func_t> func{ RELOCATION_ID(43488, 0) };  // I do not know for AE
		return func(this, array);
	}

	Actor* CombatGroup::FindClosestMemberToLocation(BGSWorldLocation& loc, Actor* toSkip, float maxRange) const
	{
		using func_t = decltype(&CombatGroup::FindClosestMemberToLocation);
		REL::Relocation<func_t> func{ RELOCATION_ID(43521, 0) };  // I do not know for AE
		return func(this, loc, toSkip, maxRange);
	}

	Actor* CombatGroup::FindClosestTargetToLocation(BGSWorldLocation& loc, Actor* toSkip, bool onlyAttacked) const
	{
		using func_t = decltype(&CombatGroup::FindClosestTargetToLocation);
		REL::Relocation<func_t> func{ RELOCATION_ID(43520, 0) };  // I do not know for AE
		return func(this, loc, toSkip, onlyAttacked);
	}

	Actor* CombatGroup::FindMemberNearActor(Actor* a, float inRange) const
	{
		using func_t = decltype(&CombatGroup::FindMemberNearActor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43519, 0) };  // I do not know for AE
		return func(this, a, inRange);
	}

	Actor* CombatGroup::FindMemberNearLocation(BGSWorldLocation& near_loc, float inRange, Actor* toSkip) const
	{
		using func_t = decltype(&CombatGroup::FindMemberNearLocation);
		REL::Relocation<func_t> func{ RELOCATION_ID(43518, 0) };  // I do not know for AE
		return func(this, near_loc, inRange, toSkip);
	}

	Actor* CombatGroup::FindRandomMember(Actor* toSkip) const
	{
		using func_t = decltype(&CombatGroup::FindRandomMember);
		REL::Relocation<func_t> func{ RELOCATION_ID(43522, 0) };  // I do not know for AE
		return func(this, toSkip);
	}

	TESObjectREFR* CombatGroup::FindSearchDoor(Actor* member, float maxRange) const
	{
		using func_t = decltype(&CombatGroup::FindSearchDoor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43545, 0) };  // I do not know for AE
		return func(this, member, maxRange);
	}

	CombatSearchLocation* CombatGroup::FindSearchLocation(Actor* member, int32_t min_score, float fromTimestamp)
	{
		using func_t = decltype(&CombatGroup::FindSearchLocation);
		REL::Relocation<func_t> func{ RELOCATION_ID(43542, 0) };  // I do not know for AE
		return func(this, member, min_score, fromTimestamp);
	}

	Actor* CombatGroup::FindTargetNearLocation(BGSWorldLocation& near_loc, float inRange, bool ignoreUnknown) const
	{
		using func_t = decltype(&CombatGroup::FindTargetNearLocation);
		REL::Relocation<func_t> func{ RELOCATION_ID(43517, 0) };  // I do not know for AE
		return func(this, near_loc, inRange, ignoreUnknown);
	}

	bool CombatGroup::GetCombatGroupIsAggressor()
	{
		using func_t = decltype(&CombatGroup::GetCombatGroupIsAggressor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43553, 0) };  // I do not know for AE
		return func(this);
	}

	CombatMember* CombatGroup::GetCombatMemberForActor(Actor* member)
	{
		using func_t = decltype(&CombatGroup::GetCombatMemberForActor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43565, 0) };  // I do not know for AE
		return func(this, member);
	}

	CombatSearchDoor* CombatGroup::GetCombatSearchDoor(TESObjectREFR* a2)
	{
		using func_t = decltype(&CombatGroup::GetCombatSearchDoor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43546, 0) };  // I do not know for AE
		return func(this, a2);
	}

	CombatTarget* CombatGroup::GetCombatTargetForActor(Actor* target)
	{
		using func_t = decltype(&CombatGroup::GetCombatTargetForActor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43564, 0) };  // I do not know for AE
		return func(this, target);
	}

	int CombatGroup::GetDetectionLevel(Actor* actor, Actor* target) const
	{
		using func_t = decltype(&CombatGroup::GetDetectionLevel);
		REL::Relocation<func_t> func{ RELOCATION_ID(43561, 0) };  // I do not know for AE
		return func(this, actor, target);
	}

	float CombatGroup::GetDPSRatioOfActor(Actor* a)
	{
		using func_t = decltype(&CombatGroup::GetDPSRatioOfActor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43555, 0) };  // I do not know for AE
		return func(this, a);
	}

	int32_t CombatGroup::GetMaxTargetDetectionLevel() const
	{
		using func_t = decltype(&CombatGroup::GetMaxTargetDetectionLevel);
		REL::Relocation<func_t> func{ RELOCATION_ID(43512, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatGroup::GetTargetDetectionData(Actor* target, int32_t& detect_level, AITimeStamp& lastDetected, bool& known, bool& lost) const
	{
		using func_t = decltype(&CombatGroup::GetTargetDetectionData);
		REL::Relocation<func_t> func{ RELOCATION_ID(43503, 0) };  // I do not know for AE
		return func(this, target, detect_level, lastDetected, known, lost);
	}

	int32_t CombatGroup::GetTargetDetectionLevel(Actor* target) const
	{
		using func_t = decltype(&CombatGroup::GetTargetDetectionLevel);
		REL::Relocation<func_t> func{ RELOCATION_ID(43502, 0) };  // I do not know for AE
		return func(this, target);
	}

	bool CombatGroup::GetTargetKnown(Actor* target) const
	{
		using func_t = decltype(&CombatGroup::GetTargetKnown);
		REL::Relocation<func_t> func{ RELOCATION_ID(43505, 0) };  // I do not know for AE
		return func(this, target);
	}

	bool CombatGroup::GetTargetLastDetectedEventLocation(Actor* target, BGSWorldLocation& ans, float maxInterval) const
	{
		using func_t = decltype(&CombatGroup::GetTargetLastDetectedEventLocation);
		REL::Relocation<func_t> func{ RELOCATION_ID(43510, 0) };  // I do not know for AE
		return func(this, target, ans, maxInterval);
	}

	bool CombatGroup::GetTargetLastDetectedLocation(Actor* target, BGSWorldLocation& ans) const
	{
		using func_t = decltype(&CombatGroup::GetTargetLastDetectedLocation);
		REL::Relocation<func_t> func{ RELOCATION_ID(43508, 0) };  // I do not know for AE
		return func(this, target, ans);
	}

	AITimeStamp CombatGroup::GetTargetLastDetectedTimeStamp(Actor* target) const
	{
		using func_t = decltype(&CombatGroup::GetTargetLastDetectedTimeStamp);
		REL::Relocation<func_t> func{ RELOCATION_ID(43507, 0) };  // I do not know for AE
		return func(this, target);
	}

	bool CombatGroup::GetTargetLastKnownLocation(Actor* target, BGSWorldLocation& ans) const
	{
		using func_t = decltype(&CombatGroup::GetTargetLastKnownLocation);
		REL::Relocation<func_t> func{ RELOCATION_ID(43509, 0) };  // I do not know for AE
		return func(this, target, ans);
	}

	bool CombatGroup::GetTargetLost(Actor* target) const
	{
		using func_t = decltype(&CombatGroup::GetTargetLost);
		REL::Relocation<func_t> func{ RELOCATION_ID(43504, 0) };  // I do not know for AE
		return func(this, target);
	}

	float CombatGroup::GetTargetStealthPoints(Actor* target) const
	{
		using func_t = decltype(&CombatGroup::GetTargetStealthPoints);
		REL::Relocation<func_t> func{ RELOCATION_ID(43506, 0) };  // I do not know for AE
		return func(this, target);
	}

	float CombatGroup::GetThreatRatioOfActor(Actor* a)
	{
		using func_t = decltype(&CombatGroup::GetThreatRatioOfActor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43554, 0) };  // I do not know for AE
		return func(this, a);
	}

	void CombatGroup::IncrementAttackerCount(Actor* target)
	{
		using func_t = decltype(&CombatGroup::IncrementAttackerCount);
		REL::Relocation<func_t> func{ RELOCATION_ID(43498, 0) };  // I do not know for AE
		return func(this, target);
	}

	void CombatGroup::InvestigatedSearchDoor(TESObjectREFR* a2)
	{
		using func_t = decltype(&CombatGroup::InvestigatedSearchDoor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43548, 0) };  // I do not know for AE
		return func(this, a2);
	}

	void CombatGroup::InvestigatedSearchLocation(const BGSWorldLocation& loc)
	{
		using func_t = decltype(&CombatGroup::InvestigatedSearchLocation);
		REL::Relocation<func_t> func{ RELOCATION_ID(43543, 0) };  // I do not know for AE
		return func(this, loc);
	}

	bool CombatGroup::IsEmpty() const
	{
		using func_t = decltype(&CombatGroup::IsEmpty);
		REL::Relocation<func_t> func{ RELOCATION_ID(43497, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatGroup::IsFleeing() const
	{
		using func_t = decltype(&CombatGroup::IsFleeing);
		REL::Relocation<func_t> func{ RELOCATION_ID(43533, 0) };  // I do not know for AE
		return func(this);
	}

	Actor* CombatGroup::IsInCombatWithGuard() const
	{
		using func_t = decltype(&CombatGroup::IsInCombatWithGuard);
		REL::Relocation<func_t> func{ RELOCATION_ID(43531, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatGroup::IsMember(Actor* a) const
	{
		using func_t = bool(const CombatGroup*, Actor*);
		REL::Relocation<func_t> func{ RELOCATION_ID(48023, 0) };  // I do not know for AE
		return func(this, a);
	}

	bool CombatGroup::IsMember(const ActorHandle& handle) const
	{
		using func_t = bool(const CombatGroup*, const ActorHandle&);
		REL::Relocation<func_t> func{ RELOCATION_ID(43492, 0) };  // I do not know for AE
		return func(this, handle);
	}

	bool CombatGroup::IsSearching() const
	{
		using func_t = decltype(&CombatGroup::IsSearching);
		REL::Relocation<func_t> func{ RELOCATION_ID(48023, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatGroup::IsTarget(Actor* a) const
	{
		using func_t = bool(const CombatGroup*, Actor*);
		REL::Relocation<func_t> func{ RELOCATION_ID(43484, 0) };  // I do not know for AE
		return func(this, a);
	}

	bool CombatGroup::IsTarget(const ActorHandle& handle) const
	{
		using func_t = bool(const CombatGroup*, const ActorHandle&);
		REL::Relocation<func_t> func{ RELOCATION_ID(43485, 0) };  // I do not know for AE
		return func(this, handle);
	}

	bool CombatGroup::MergeGroups(CombatGroup* other)
	{
		using func_t = decltype(&CombatGroup::MergeGroups);
		REL::Relocation<func_t> func{ RELOCATION_ID(43500, 0) };  // I do not know for AE
		return func(this, other);
	}

	void CombatGroup::NotifyMemberAttacked(Actor* member, Actor* attacker)
	{
		using func_t = decltype(&CombatGroup::NotifyMemberAttacked);
		REL::Relocation<func_t> func{ RELOCATION_ID(43513, 0) };  // I do not know for AE
		return func(this, member, attacker);
	}

	void CombatGroup::NotifyMemberKilled(Actor* killer, Actor* member)
	{
		using func_t = decltype(&CombatGroup::NotifyMemberKilled);
		REL::Relocation<func_t> func{ RELOCATION_ID(43514, 0) };  // I do not know for AE
		return func(this, killer, member);
	}

	void CombatGroup::RemoveAllMembers()
	{
		using func_t = decltype(&CombatGroup::RemoveAllMembers);
		REL::Relocation<func_t> func{ RELOCATION_ID(43496, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatGroup::RemoveMember(Actor* member)
	{
		using func_t = decltype(&CombatGroup::RemoveMember);
		REL::Relocation<func_t> func{ RELOCATION_ID(43490, 0) };  // I do not know for AE
		return func(this, member);
	}

	void CombatGroup::RemoveTarget(Actor* target)
	{
		using func_t = void(CombatGroup*, Actor*);
		REL::Relocation<func_t> func{ RELOCATION_ID(43483, 0) };  // I do not know for AE
		return func(this, target);
	}

	void CombatGroup::RemoveTarget(int32_t ind)
	{
		using func_t = void(CombatGroup*, int32_t);
		REL::Relocation<func_t> func{ RELOCATION_ID(43566, 0) };  // I do not know for AE
		return func(this, ind);
	}

	void CombatGroup::ReserveSearchDoor(TESObjectREFR* a2)
	{
		using func_t = decltype(&CombatGroup::ReserveSearchDoor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43550, 0) };  // I do not know for AE
		return func(this, a2);
	}

	void CombatGroup::SetSearchingMember(Actor* member)
	{
		using func_t = decltype(&CombatGroup::SetSearchingMember);
		REL::Relocation<func_t> func{ RELOCATION_ID(43541, 0) };  // I do not know for AE
		return func(this, member);
	}

	void CombatGroup::StartSearch()
	{
		using func_t = decltype(&CombatGroup::StartSearch);
		REL::Relocation<func_t> func{ RELOCATION_ID(43536, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatGroup::StopCombat()
	{
		using func_t = decltype(&CombatGroup::StopCombat);
		REL::Relocation<func_t> func{ RELOCATION_ID(43495, 0) };  // I do not know for AE
		return func(this);
	}

	void* CombatGroup::UnreserveSearchDoor(TESObjectREFR* a2)
	{
		using func_t = decltype(&CombatGroup::UnreserveSearchDoor);
		REL::Relocation<func_t> func{ RELOCATION_ID(43551, 0) };  // I do not know for AE
		return func(this, a2);
	}

	void CombatGroup::Update()
	{
		using func_t = decltype(&CombatGroup::Update);
		REL::Relocation<func_t> func{ RELOCATION_ID(43481, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatGroup::UpdateAttackerCounts()
	{
		using func_t = decltype(&CombatGroup::UpdateAttackerCounts);
		REL::Relocation<func_t> func{ RELOCATION_ID(43570, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatGroup::UpdateCombatStrength()
	{
		using func_t = decltype(&CombatGroup::UpdateCombatStrength);
		REL::Relocation<func_t> func{ RELOCATION_ID(43552, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatGroup::UpdateCounts()
	{
		using func_t = decltype(&CombatGroup::UpdateCounts);
		REL::Relocation<func_t> func{ RELOCATION_ID(43569, 0) };  // I do not know for AE
		return func(this);
	}

	DETECTION_PRIORITY CombatGroup::UpdateDetection(Actor* member, Actor* target, DetectionState* detect_state)
	{
		using func_t = decltype(&CombatGroup::UpdateDetection);
		REL::Relocation<func_t> func{ RELOCATION_ID(43501, 0) };  // I do not know for AE
		return func(this, member, target, detect_state);
	}

	void CombatGroup::UpdateMembers()
	{
		using func_t = decltype(&CombatGroup::UpdateMembers);
		REL::Relocation<func_t> func{ RELOCATION_ID(43572, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatGroup::UpdateSearch()
	{
		using func_t = decltype(&CombatGroup::UpdateSearch);
		REL::Relocation<func_t> func{ RELOCATION_ID(43534, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatGroup::UpdateSearchArea()
	{
		using func_t = decltype(&CombatGroup::UpdateSearchArea);
		REL::Relocation<func_t> func{ RELOCATION_ID(43538, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatGroup::UpdateSearchLocations()
	{
		using func_t = decltype(&CombatGroup::UpdateSearchLocations);
		REL::Relocation<func_t> func{ RELOCATION_ID(43535, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatGroup::UpdateStealthPoints()
	{
		using func_t = decltype(&CombatGroup::UpdateStealthPoints);
		REL::Relocation<func_t> func{ RELOCATION_ID(43573, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatGroup::UpdateTargets()
	{
		using func_t = decltype(&CombatGroup::UpdateTargets);
		REL::Relocation<func_t> func{ RELOCATION_ID(43571, 0) };  // I do not know for AE
		return func(this);
	}
}
