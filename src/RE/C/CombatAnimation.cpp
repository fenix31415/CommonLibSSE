#include "RE/C/CombatAnimation.h"

namespace RE
{
	CombatAnimation::CombatAnimation(Actor* actor, ANIM anim) :
		TESActionData(NoCallCtor())
	{
		using func_t = CombatAnimation*(CombatAnimation*, Actor*, ANIM);
		REL::Relocation<func_t> func{ RELOCATION_ID(43235, 0) };  // I do not know for AE
		func(this, actor, anim);
	}

	CombatAnimation::CombatAnimation(Actor* actor, TESObjectREFR* target, ANIM anim) :
		TESActionData(NoCallCtor())
	{
		using func_t = CombatAnimation*(CombatAnimation*, Actor*, TESObjectREFR*, ANIM);
		REL::Relocation<func_t> func{ RELOCATION_ID(43236, 0) };  // I do not know for AE
		func(this, actor, target, anim);
	}

	CombatAnimation::CombatAnimation(Actor* actor, BGSAction* action) :
		TESActionData(NoCallCtor())
	{
		using func_t = CombatAnimation*(CombatAnimation*, Actor * actor, BGSAction*);
		REL::Relocation<func_t> func{ RELOCATION_ID(43237, 0) };  // I do not know for AE
		func(this, actor, action);
	}

	bool CombatAnimation::Execute(Actor* actor, ANIM anim)
	{
		using func_t = bool(Actor*, ANIM);
		REL::Relocation<func_t> func{ RELOCATION_ID(43245, 0) };  // I do not know for AE
		return func(actor, anim);
	}

	bool CombatAnimation::Execute(Actor* actor, TESObjectREFR* target, ANIM anim)
	{
		using func_t = bool(Actor*, TESObjectREFR*, ANIM);
		REL::Relocation<func_t> func{ RELOCATION_ID(43246, 0) };  // I do not know for AE
		return func(actor, target, anim);
	}

	bool CombatAnimation::Check()
	{
		using func_t = decltype(&CombatAnimation::Check);
		REL::Relocation<func_t> func{ RELOCATION_ID(43238, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatAnimation::Execute()
	{
		using func_t = bool(CombatAnimation*);
		REL::Relocation<func_t> func{ RELOCATION_ID(43239, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatAnimation::GetEventData(const BSFixedString& event_name, float& event_time)
	{
		using func_t = bool(CombatAnimation*, const BSFixedString&, float&);
		REL::Relocation<func_t> func{ RELOCATION_ID(43240, 0) };  // I do not know for AE
		return func(this, event_name, event_time);
	}

	bool CombatAnimation::GetEventData(const BSFixedString& event_name, float& event_time, NiPoint3& translation)
	{
		using func_t = bool(CombatAnimation*, const BSFixedString&, float&, NiPoint3&);
		REL::Relocation<func_t> func{ RELOCATION_ID(43241, 0) };  // I do not know for AE
		return func(this, event_name, event_time, translation);
	}

	float CombatAnimation::GetEventTime(const BSFixedString& event_name)
	{
		using func_t = decltype(&CombatAnimation::GetEventTime);
		REL::Relocation<func_t> func{ RELOCATION_ID(43243, 0) };  // I do not know for AE
		return func(this, event_name);
	}

	float CombatAnimation::GetLength()
	{
		using func_t = decltype(&CombatAnimation::GetLength);
		REL::Relocation<func_t> func{ RELOCATION_ID(43244, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatAnimation::GetTranslation(NiPoint3& translation)
	{
		using func_t = decltype(&CombatAnimation::GetTranslation);
		REL::Relocation<func_t> func{ RELOCATION_ID(43242, 0) };  // I do not know for AE
		return func(this, translation);
	}

	bool CombatAnimation::LoadClipData()
	{
		using func_t = decltype(&CombatAnimation::LoadClipData);
		REL::Relocation<func_t> func{ RELOCATION_ID(43247, 0) };  // I do not know for AE
		return func(this);
	}
}
