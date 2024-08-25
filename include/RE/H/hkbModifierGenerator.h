#pragma once

#include "RE/H/hkbGenerator.h"

namespace RE
{
	class hkbGenerator;
	class hkbModifier;

	class hkbModifierGenerator : public hkbGenerator
	{
	public:
		static hkbModifierGenerator* Create(hkbModifier* modifier, hkbGenerator* generator)
		{
			auto ans = hk_malloc<hkbModifierGenerator>();
			return ctor(ans, modifier, generator);
		}

		// members
		hkbModifier*  modifier;   // 48
		hkbGenerator* generator;  // 50

	private:
		static hkbModifierGenerator* ctor(hkbModifierGenerator* _this, hkbModifier* modifier, hkbGenerator* generator)
		{
			using func_t = decltype(&hkbModifierGenerator::ctor);
			REL::Relocation<func_t> func{ RELOCATION_ID(58894, 0) };  // I do not know for AE
			return func(_this, modifier, generator);
		}
	};
	static_assert(sizeof(hkbModifierGenerator) == 0x58);
}
