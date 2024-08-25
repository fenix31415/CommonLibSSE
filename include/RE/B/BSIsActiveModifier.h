#pragma once

#include "RE/H/hkbModifier.h"

namespace RE
{
	class BSIsActiveModifier : public hkbModifier
	{
	public:
		static BSIsActiveModifier* Create()
		{
			auto ans = hk_malloc<BSIsActiveModifier>();
			return ctor(ans);
		}

		// members
		bool bIsActive0;      // 50
		bool bInvertActive0;  // 51
		bool bIsActive1;      // 52
		bool bInvertActive1;  // 53
		bool bIsActive2;      // 54
		bool bInvertActive2;  // 55
		bool bIsActive3;      // 56
		bool bInvertActive3;  // 57
		bool bIsActive4;      // 58
		bool bInvertActive4;  // 59
		char pad5A[6];        // 5A

	private:
		static BSIsActiveModifier* ctor(BSIsActiveModifier* _this)
		{
			using func_t = decltype(&BSIsActiveModifier::ctor);
			REL::Relocation<func_t> func{ RELOCATION_ID(62308, 0) };  // I do not know for AE
			return func(_this);
		}
	};
	static_assert(sizeof(BSIsActiveModifier) == 0x60);
}
