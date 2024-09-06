#pragma once

#include "RE/N/NiBlendInterpolator.h"
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiQuatTransform.h"

namespace RE
{
	class NiBlendAccumTransformInterpolator : public NiBlendInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiBlendAccumTransformInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiBlendAccumTransformInterpolator;

		struct AccumArrayItem
		{
			float           field_0;     // 00
			NiQuatTransform transform1;  // 04
			NiQuatTransform transform2;  // 24
			NiMatrix3       M;           // 44
		};
		static_assert(sizeof(AccumArrayItem) == 0x68);

		~NiBlendAccumTransformInterpolator() override;  // 00

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
		bool IsTransformValueSupported() const override;                                             // 30

		// override (NiBlendInterpolator)
		uint8_t AddInterpInfo(NiInterpolator* interp, float a3, char a4, float a5) override;  // 39
		void    RemoveInterpInfo(uint8_t ind) override;                                       // 3A
		bool    InterpolatorIsCorrectType(NiInterpolator* interp) override;                   // 3B
		bool    ReallocateArrays() override;                                                  // 3C

		// add
		virtual bool GetValue(NiQuatTransform& ans);

		// members
		NiQuatTransform val;          // 48
		AccumArrayItem* accum_array;  // 68 -- unique_ptr
		uint8_t         field_70;     // 70
		uint8_t         pad71[7];     // 70
	};
	static_assert(sizeof(NiBlendAccumTransformInterpolator) == 0x78);
}
