#pragma once

#include "RE/N/NiKeyBasedInterpolator.h"
#include "RE/N/NiQuaternion.h"
#include "RE/N/NiRotData.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiQuaternionInterpolator : public NiKeyBasedInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiQuaternionInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiQuaternionInterpolator;

		~NiQuaternionInterpolator() override = default;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C

		// override (NiInterpolator)
		bool            Update1(float a_time, NiObjectNET* a_interpTarget, NiQuatTransform& a_value) override;  // 25
		bool            Update2(float a_time, NiObjectNET* a_target, NiColorA& a_value) override;               // 26
		bool            Update3(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value) override;         // 27
		bool            Update4(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value) override;     // 28
		bool            Update5(float a_time, NiObjectNET* a_interpTarget, float& a_value) override;            // 29
		bool            Update6(float a_time, NiObjectNET* a_interpTarget, bool& a_value) override;             // 2A
		bool            IsQuaternionValueSupported() const override;                                            // 2D
		void            Collapse();                                                                             // 31
		void            GetActiveTimeRange(float& a_beginKeyTime, float& a_endKeyTime) const override;          // 32
		void            GuaranteeTimeRange(float a_startTime, float a_endTime) override;                        // 33
		NiInterpolator* GetSequenceInterpolator(float a_startTime, float a_endTime) override;                   // 34

		// override (NiKeyBasedInterpolator)
		uint16_t        GetKeyChannelCount() const override;                 // 39
		uint32_t        GetKeyCount(uint16_t a_channel) const override;      // 3A
		KeyContent      GetKeyContent(uint16_t a_channel) const override;    // 3B
		KeyType         GetKeyType(uint16_t a_channel) const override;       // 3C
		NiAnimationKey* GetKeyArray(uint16_t a_channel) const override;      // 3D
		uint8_t         GetKeyStride(uint16_t a_channel) const override;     // 3E
		bool            GetChannelPosed(uint16_t a_channel) const override;  // 3F

		// members
		NiQuaternion         val;        // 18
		NiPointer<NiRotData> data;       // 28
		uint32_t             lastIndex;  // 30
		uint8_t              pad34[4];   // 34
	};
	static_assert(sizeof(NiQuaternionInterpolator) == 0x38);
}
