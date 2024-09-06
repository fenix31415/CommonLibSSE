#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/N/NiFloatData.h"
#include "RE/N/NiKeyBasedInterpolator.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiQuatTransform.h"

namespace RE
{
	class BSTreadTransfInterpolator : public NiKeyBasedInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTreadTransfInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTreadTransfInterpolator;

		struct LinkInfo
		{
			NiQuatTransform transform1;  // 00
			NiQuatTransform transform2;  // 20
			BSFixedString   str;         // 40
		};
		static_assert(sizeof(LinkInfo) == 0x48);

		~BSTreadTransfInterpolator() override;  // 00

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
		bool Update2(float a_time, NiObjectNET* a_target, NiColorA& a_value) override;               // 26
		bool Update3(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value) override;         // 27
		bool Update4(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value) override;     // 28
		bool Update5(float a_time, NiObjectNET* a_interpTarget, float& a_value) override;            // 29
		bool Update6(float a_time, NiObjectNET* a_interpTarget, bool& a_value) override;             // 2A
		bool IsTransformValueSupported() const override;                                             // 30

		// override (NiKeyBasedInterpolator)
		uint16_t        GetKeyChannelCount() const override;                 // 39
		uint32_t        GetKeyCount(uint16_t a_channel) const override;      // 3A
		KeyContent      GetKeyContent(uint16_t a_channel) const override;    // 3B
		KeyType         GetKeyType(uint16_t a_channel) const override;       // 3C
		NiAnimationKey* GetKeyArray(uint16_t a_channel) const override;      // 3D
		uint8_t         GetKeyStride(uint16_t a_channel) const override;     // 3E
		bool            GetChannelPosed(uint16_t a_channel) const override;  // 3F

		// members
		LinkInfo*              links;      // 18 -- unique_ptr
		uint32_t               numLinks;   // 20
		float                  field_24;   // 24
		float                  field_28;   // 28
		uint32_t               lastIndex;  // 2C
		NiPointer<NiFloatData> data;       // 30
	};
	static_assert(sizeof(BSTreadTransfInterpolator) == 0x38);
}
