#pragma once

#include "RE/N/NiKeyBasedInterpolator.h"
#include "RE/N/NiQuatTransform.h"
#include "RE/N/NiTransformData.h"

namespace RE
{
	class NiTransformInterpolator : public NiKeyBasedInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiTransformInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiTransformInterpolator;

		NiTransformInterpolator(NiTransformData* data);
		NiTransformInterpolator(NiQuatTransform val = NiQuatTransform());
		~NiTransformInterpolator() override = default;  // 00

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
		bool            Update2(float a_time, NiObjectNET* a_interpTarget, NiColorA& a_value) override;         // 26
		bool            Update3(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value) override;         // 27
		bool            Update4(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value) override;     // 28
		bool            Update5(float a_time, NiObjectNET* a_interpTarget, float& a_value) override;            // 29
		bool            Update6(float a_time, NiObjectNET* a_interpTarget, bool& a_value) override;             // 2A
		bool            IsTransformValueSupported() const override;                                             // 30
		void            Collapse() override;                                                                    // 31
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

		static NiTransformInterpolator* CreateObject(void);

		void CopyMembers(NiTransformInterpolator* dst, NiCloningProcess& proc);
		void SetPoseValue(const NiQuatTransform& new_val);

		// members
		NiQuatTransform            val;          // 18
		NiPointer<NiTransformData> data;         // 38
		uint16_t                   curPosInd;    // 40
		uint16_t                   curRotInd;    // 42
		uint16_t                   curScaleInd;  // 44
		bool                       useValue;     // 46
		char                       pad47;        // 47
	};
	static_assert(sizeof(NiTransformInterpolator) == 0x48);
}
