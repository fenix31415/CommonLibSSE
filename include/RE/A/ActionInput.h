#pragma once

#include "RE/A/ActorState.h"
#include "RE/B/BGSAction.h"
#include "RE/B/BGSAnimationSequencer.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	class ActionQueue;

	class ActionInput
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActionInput;
		inline static constexpr auto VTABLE = VTABLE_ActionInput;

		ActionInput(uint32_t a_flags, TESObjectREFR* a_source, BGSAction* a_action, TESObjectREFR* a_target)
		{
			using func_t = ActionInput*(ActionInput*, uint32_t, TESObjectREFR*, BGSAction*, TESObjectREFR*);
			REL::Relocation<func_t> func{ RELOCATION_ID(14814, 0) };  // I do not know for AE
			func(this, a_flags, a_source, a_action, a_target);
		}

		virtual ~ActionInput() {}  // 00

		// add
		virtual ActorState*            GetSourceActorState() const { return nullptr; }  // 01
		virtual ActionQueue*           GetActionQueue() { return 0; }                   // 02
		virtual BGSAnimationSequencer* GetSourceSequencer() const { return nullptr; }   // 03

		// members
		NiPointer<TESObjectREFR> source;  // 08
		NiPointer<TESObjectREFR> target;  // 10
		BGSAction*               action;  // 18
		uint32_t                 unk20;   // 20

	protected:
		struct NoCallCtor
		{};

		ActionInput(NoCallCtor) {}
	};
	static_assert(sizeof(ActionInput) == 0x28);
}
