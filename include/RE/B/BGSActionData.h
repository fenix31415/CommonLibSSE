#pragma once

#include "RE/A/ActionInput.h"
#include "RE/A/ActionOutput.h"

namespace RE
{
	class BGSActionData :
		public ActionInput,  // 00
		public ActionOutput  // 28
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSActionData;
		inline static constexpr auto VTABLE = VTABLE_BGSActionData;

		BGSActionData() :
			ActionInput(NoCallCtor())
		{
			using func_t = BGSActionData*(BGSActionData*);
			REL::Relocation<func_t> func{ RELOCATION_ID(15916, 41558) };
			func(this);
		}

		virtual ~BGSActionData() override {}  // 00

		// add
		virtual BGSActionData* Clone() const { return nullptr; }  // 04
		virtual bool           Process() { return false; };       // 05

		// members
		uint32_t flags;  // 58

	protected:
		BGSActionData(NoCallCtor a) :
			ActionInput(a) {}
	};
	static_assert(sizeof(BGSActionData) == 0x60);
}
