#pragma once

#include "RE/B/BGSActionData.h"

namespace RE
{
	class TESActionData : public BGSActionData
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESActionData;
		inline static constexpr auto VTABLE = VTABLE_TESActionData;
		
		using BGSActionData::BGSActionData;
		virtual ~TESActionData() override {}  // 00

		// override (ActionInput)
		ActorState*            GetSourceActorState() const override { return nullptr; }  // 01
		ActionQueue*           GetActionQueue(void) override { return nullptr; }         // 02 - { return 0; }
		BGSAnimationSequencer* GetSourceSequencer() const override { return nullptr; }   // 03

		// override (BGSActionData)
		BGSActionData* Clone() const override { return nullptr; }  // 04
		bool           Process() override { return false; }        // 05

	};
	static_assert(sizeof(TESActionData) == 0x60);
}
