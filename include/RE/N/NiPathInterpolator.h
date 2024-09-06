#pragma once

#include "RE/N/NiKeyBasedInterpolator.h"

namespace RE
{
	class NiFloatData;
	class NiPosData;

	class NiPathInterpolator : public NiKeyBasedInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiKeyBasedInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiKeyBasedInterpolator;

		~NiPathInterpolator() override;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                                            // 02
		NiObject*     CreateClone([[maybe_unused]] NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;                             // 18
		void          LinkObject(NiStream& a_stream) override;                             // 19
		bool          RegisterStreamables(NiStream& a_stream) override;                    // 1A
		void          SaveBinary(NiStream& a_stream) override;                             // 1B
		bool          IsEqual(NiObject* a_object) override;                                // 1C
		void          ProcessClone(NiCloningProcess& a_cloning) override;                  // 1D

		// override (NiInterpolator)
		bool            Update1(float a_time, NiObjectNET* a_interpTarget, NiQuatTransform& a_value) override;  // 25
		bool            Update2(float a_time, NiObjectNET* a_interpTarget, NiColorA& a_value) override;         // 26
		bool            Update3(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value) override;         // 27
		bool            Update4(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value) override;     // 28
		bool            Update5(float a_time, NiObjectNET* a_interpTarget, float& a_value) override;            // 29
		bool            Update6(float a_time, NiObjectNET* a_interpTarget, bool& a_value) override;             // 2A
		bool            IsTransformValueSupported() const override;                                             // 30
		void            GetActiveTimeRange(float& a_beginKeyTime, float& a_endKeyTime) const override;          // 32
		void            GuaranteeTimeRange(float a_startTime, float a_endTime) override;                        // 33
		NiInterpolator* GetSequenceInterpolator(float a_startTime, float a_endTime) override;                   // 34

		// override (NiKeyBasedInterpolator)
		uint16_t        GetKeyChannelCount() const override;                 // 39
		uint32_t        GetKeyCount(uint16_t a_channel) const override;      // 3A
		KeyType         GetKeyType(uint16_t a_channel) const override;       // 3C
		KeyContent      GetKeyContent(uint16_t a_channel) const override;    // 3B
		NiAnimationKey* GetKeyArray(uint16_t a_channel) const override;      // 3D
		uint8_t         GetKeyStride(uint16_t a_channel) const override;     // 3E
		bool            GetChannelPosed(uint16_t a_channel) const override;  // 3F

		// members
		uint16_t               flags;        // 18
		char                   pad1A[2];     // 1A
		uint32_t               ind;          // 1C
		uint32_t               lastIndex;    // 20
		char                   pad24[4];     // 24
		NiPointer<NiPosData>   posData;      // 28
		NiPointer<NiFloatData> pcts;         // 30
		float*                 lengths;      // 38 -- unique_ptr
		float                  path_length;  // 40
		float                  field_44;     // 44
		float                  field_48;     // 48
		uint16_t               unk4C;        // 4C
		char                   pad4E[2];     // 4E
		float                  pos;          // 50
		uint32_t               unk54;        // 54
		NiQuaternion           Q;            // 58
		NiPoint3               P;            // 68
		float                  scale;        // 74
	};
	static_assert(sizeof(NiPathInterpolator) == 0x78);
}
