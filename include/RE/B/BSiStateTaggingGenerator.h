#pragma once

#include "RE/H/hkbGenerator.h"

namespace RE
{
	class BSiStateTaggingGenerator : public hkbGenerator
	{
	public:
		static BSiStateTaggingGenerator* Create(uint32_t iState, uint32_t priority, hkbGenerator* generator)
		{
			auto ans = hk_malloc<BSiStateTaggingGenerator>();
			ctor(ans);
			ans->iStateToSetAs = iState;
			ans->iPriority = priority;
			ans->pDefaultGenerator = generator;
			return ans;
		}

		// members
		uint64_t      field_48;           // 48
		hkbGenerator* pDefaultGenerator;  // 50
		uint32_t      iStateToSetAs;      // 54
		uint32_t      iPriority;          // 58

	private:
		static BSiStateTaggingGenerator* ctor(BSiStateTaggingGenerator* _this)
		{
			using func_t = decltype(&BSiStateTaggingGenerator::ctor);
			REL::Relocation<func_t> func{ RELOCATION_ID(62225, 0) };  // I do not know for AE
			return func(_this);
		}
	};
	static_assert(sizeof(BSiStateTaggingGenerator) == 0x60);
}
