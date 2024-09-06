#pragma once

#include "RE/N/NiKeyBasedInterpolator.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiBoolInterpolator : public NiKeyBasedInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiBoolInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiBoolInterpolator;

		~NiBoolInterpolator() override = default;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C

		// override (NiInterpolator)
		bool                Update1(float a_time, NiObjectNET* a_interpTarget, NiQuatTransform& a_value) override;  // 25
		bool                Update2(float a_time, NiObjectNET* a_target, NiColorA& a_value) override;               // 26
		bool                Update3(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value) override;         // 27
		bool                Update4(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value) override;     // 28
		bool                Update5(float a_time, NiObjectNET* a_interpTarget, float& a_value) override;            // 29
		bool                Update6(float a_time, NiObjectNET* a_interpTarget, bool& a_value) override;             // 2A
		bool                IsBoolValueSupported() const override;                                                  // 2B
		void                Collapse() override;                                                                    // 31
		void                GuaranteeTimeRange(float a_start, float a_end) override;                                // 33
		NiInterpolator*     GetSequenceInterpolator(float a_start, float a_end) override;                           // 34
		NiBoolInterpolator* AsNiBoolInterpolator() override;                                                        // 38

		// override (NiKeyBasedInterpolator)
		uint16_t        GetKeyChannelCount() const override;                 // 39
		uint32_t        GetKeyCount(uint16_t a_channel) const override;      // 3A
		KeyContent      GetKeyContent(uint16_t a_channel) const override;    // 3B
		KeyType         GetKeyType(uint16_t a_channel) const override;       // 3C
		NiAnimationKey* GetKeyArray(uint16_t a_channel) const override;      // 3D
		uint8_t         GetKeyStride(uint16_t a_channel) const override;     // 3E
		bool            GetChannelPosed(uint16_t a_channel) const override;  // 3F

		// members
		uint8_t               val;        // 18
		uint8_t               pad19[7];   // 19
		NiPointer<NiBoolData> colorData;  // 28
		uint32_t              lastIndex;  // 30
		uint8_t               pad34[4];   // 34
	};
	static_assert(sizeof(NiBoolInterpolator) == 0x30);
}
