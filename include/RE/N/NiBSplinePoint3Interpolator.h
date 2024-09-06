#pragma once

#include "RE/N/NiBSplineInterpolator.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class NiBSplinePoint3Interpolator : public NiBSplineInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiBSplinePoint3Interpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiBSplinePoint3Interpolator;

		~NiBSplinePoint3Interpolator() override = default;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C

		// override (NiInterpolator)
		bool Update1(float a_time, NiObjectNET* a_interpTarget, NiQuatTransform& a_value) override;  // 25
		bool Update2(float a_time, NiObjectNET* a_interpTarget, NiColorA& a_value) override;         // 26
		bool Update3(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value) override;         // 27
		bool Update4(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value) override;     // 28
		bool Update5(float a_time, NiObjectNET* a_interpTarget, float& a_value) override;            // 29
		bool Update6(float a_time, NiObjectNET* a_interpTarget, bool& a_value) override;             // 2A
		bool IsPoint3ValueSupported() const override;                                                // 2E

		// override (NiBSplineInterpolator)
		uint16_t GetChannelCount() const override;                           // 39
		uint32_t GetDimension(uint16_t channel) const override;              // 3B
		uint32_t GetDegree(uint16_t channel) const override;                 // 3C
		bool     GetChannelPosed() const override;                           // 3D
		uint32_t GetControlHandle(uint16_t channel) const override;          // 40
		void     SetControlHandle(uint32_t val, uint16_t channel) override;  // 41

		// members
		NiPoint3 val;            // 30
		uint32_t controlHandle;  // 3C
	};
	static_assert(sizeof(NiBSplinePoint3Interpolator) == 0x40);
}
