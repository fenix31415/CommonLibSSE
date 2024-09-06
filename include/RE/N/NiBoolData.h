#pragma once

#include "RE/N/NiObject.h"

namespace RE
{
	class NiBoolKey;

	class NiBoolData : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiBoolData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiBoolData;

		using KeyType = NiAnimationKey::KeyType;

		~NiBoolData() override;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                          // 02
		virtual void  LoadBinary(NiStream& a_stream) override;           // 18
		virtual void  LinkObject(NiStream& a_stream) override;           // 19
		virtual bool  RegisterStreamables(NiStream& a_stream) override;  // 1A
		virtual void  SaveBinary(NiStream& a_stream) override;           // 1B
		virtual bool  IsEqual(NiObject* a_object) override;              // 1C

		// members
		uint32_t   numKeys;  // 10
		uint32_t   pad14;    // 14
		NiBoolKey* keys;     // 18
		KeyType    type;     // 20
		uint8_t    keySize;  // 24
		uint8_t    pad25;    // 25
		uint16_t   pad26;    // 26
	};
	static_assert(sizeof(NiBoolData) == 0x28);
}
