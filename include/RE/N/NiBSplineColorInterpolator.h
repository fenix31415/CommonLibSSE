#pragma once

#include "RE/N/NiBSplineInterpolator.h"
#include "RE/N/NiColor.h"

namespace RE
{
	class NiBSplineColorInterpolator : public NiBSplineInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiBSplineColorInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiBSplineColorInterpolator;

		~NiBSplineColorInterpolator() override = default;  // 00

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
		bool IsColorAValueSupported() const override;                                                // 2F

		// override (NiBSplineInterpolator)
		uint16_t GetChannelCount() const override;                           // 39
		uint32_t GetDimension(uint16_t channel) const override;              // 3B
		uint32_t GetDegree(uint16_t channel) const override;                 // 3C
		bool     GetChannelPosed() const override;                           // 3D
		uint32_t GetControlHandle(uint16_t channel) const override;          // 40
		void     SetControlHandle(uint32_t val, uint16_t channel) override;  // 41

		// members
		NiColorA val;            // 30
		uint32_t controlHandle;  // 40
		uint8_t  pad44[4];       // 44
	};
	static_assert(sizeof(NiBSplineColorInterpolator) == 0x48);
}
