#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/N/NiInterpolator.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiLookAtInterpolator : public NiInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiLookAtInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiLookAtInterpolator;

		~NiLookAtInterpolator() override = default;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                            // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;   // 17
		void          LoadBinary(NiStream& a_stream) override;             // 18
		void          LinkObject(NiStream& a_stream) override;             // 19
		bool          RegisterStreamables(NiStream& a_stream) override;    // 1A
		void          SaveBinary(NiStream& a_stream) override;             // 1B
		bool          IsEqual(NiObject* a_object) override;                // 1C
		void          ProcessClone(NiCloningProcess& a_cloning) override;  // 1D

		// override (NiInterpolator)
		bool            Update1(float a_time, NiObjectNET* a_interpTarget, NiQuatTransform& a_value) override;  // 25
		bool            Update2(float a_time, NiObjectNET* a_target, NiColorA& a_value) override;               // 26
		bool            Update3(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value) override;         // 27
		bool            Update4(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value) override;     // 28
		bool            Update5(float a_time, NiObjectNET* a_interpTarget, float& a_value) override;            // 29
		bool            Update6(float a_time, NiObjectNET* a_interpTarget, bool& a_value) override;             // 2A
		bool            IsTransformValueSupported() const override;                                             // 30
		void            Collapse() override;                                                                    // 31
		void            GetActiveTimeRange(float& a_beginKeyTime, float& a_endKeyTime) const override;          // 32
		void            GuaranteeTimeRange(float a_startTime, float a_endTime) override;                        // 33
		NiInterpolator* GetSequenceInterpolator(float a_startTime, float a_endTime) override;                   // 34
		bool            ResolveDependencies(NiAVObjectPalette* a_palette) override;                             // 35
		bool            SetUpDependencies() override;                                                           // 36
		bool            AlwaysUpdate() const override;                                                          // 37

		// members
		uint16_t                  flags;             // 18
		uint8_t                   pad1A[6];          // 1A
		NiAVObject*               lookAt;            // 20
		BSFixedString             lookatName;        // 28
		NiQuatTransform           val;               // 30
		NiPointer<NiInterpolator> interpolators[3];  // 50 -- pos rot scale
	};
	static_assert(sizeof(NiLookAtInterpolator) == 0x68);
}
