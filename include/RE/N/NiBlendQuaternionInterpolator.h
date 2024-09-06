#pragma once

#include "RE/N/NiBlendInterpolator.h"
#include "RE/N/NiQuaternion.h"

namespace RE
{
	class NiBlendQuaternionInterpolator : public NiBlendInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiBlendQuaternionInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiBlendQuaternionInterpolator;

		~NiBlendQuaternionInterpolator() override = default;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                                            // 02
		NiObject*     CreateClone([[maybe_unused]] NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;                             // 18
		void          LinkObject(NiStream& a_stream) override;                             // 19
		bool          RegisterStreamables(NiStream& a_stream) override;                    // 1A
		void          SaveBinary(NiStream& a_stream) override;                             // 1B
		bool          IsEqual(NiObject* a_object) override;                                // 1C

		// override (NiInterpolator)
		bool Update1(float a_time, NiObjectNET* a_interpTarget, NiQuatTransform& a_value) override;  // 25
		bool Update2(float a_time, NiObjectNET* a_interpTarget, NiColorA& a_value) override;         // 26
		bool Update3(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value) override;         // 27
		bool Update4(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value) override;     // 28
		bool Update5(float a_time, NiObjectNET* a_interpTarget, float& a_value) override;            // 29
		bool Update6(float a_time, NiObjectNET* a_interpTarget, bool& a_value) override;             // 2A
		bool IsQuaternionValueSupported() const override;                                            // 2D

		// override (NiBlendInterpolator)
		bool InterpolatorIsCorrectType(NiInterpolator* interp) override;  // 3B

		// members
		NiQuaternion val;  // 48
	};
	static_assert(sizeof(NiBlendQuaternionInterpolator) == 0x58);
}
