#pragma once

#include "RE/N/NiInterpolator.h"

namespace RE
{
	class NiBSplineBasisData;
	class NiBSplineData;

	class NiBSplineInterpolator : public NiInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiBSplineInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiBSplineInterpolator;

		~NiBSplineInterpolator() override = default;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		bool          IsEqual(NiObject* a_object) override;              // 1C

		// override (NiInterpolator)
		bool Update1(float a_time, NiObjectNET* a_interpTarget, NiQuatTransform& a_value) override;  // 25
		bool Update2(float a_time, NiObjectNET* a_interpTarget, NiColorA& a_value) override;         // 26
		bool Update3(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value) override;         // 27
		bool Update4(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value) override;     // 28
		bool Update5(float a_time, NiObjectNET* a_interpTarget, float& a_value) override;            // 29
		bool Update6(float a_time, NiObjectNET* a_interpTarget, bool& a_value) override;             // 2A
		bool IsFloatValueSupported() const override;                                                 // 2C

		// add
		virtual uint16_t GetChannelCount() const = 0;                           // 39
		virtual uint32_t GetControlPointCount(uint16_t channel) const;          // 3A
		virtual uint32_t GetDimension(uint16_t channel) const = 0;              // 3B
		virtual uint32_t GetDegree(uint16_t channel) const = 0;                 // 3C
		virtual bool     GetChannelPosed() const = 0;                           // 3D
		virtual bool     UsesCompressedControlPoints() const;                   // 3E
		virtual uint32_t GetAllocatedSize(uint16_t channel) const;              // 3F
		virtual uint32_t GetControlHandle(uint16_t channel) const = 0;          // 40
		virtual void     SetControlHandle(uint32_t val, uint16_t channel) = 0;  // 41

		// members
		float                         min_time;    // 18
		float                         max_time;    // 1C
		NiPointer<NiBSplineData>      data;        // 20
		NiPointer<NiBSplineBasisData> basis_data;  // 28
	};
	static_assert(sizeof(NiBSplineInterpolator) == 0x30);
}
