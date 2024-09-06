#pragma once

#include "RE/N/NiAnimationKey.h"
#include "RE/N/NiObject.h"

namespace RE
{
	class NiRotKey;

	class NiRotData : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiRotData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiRotData;

		using KeyType = NiAnimationKey::KeyType;

		~NiRotData() override;

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		bool          IsEqual(NiObject* a_object) override;              // 1C

		// members
		uint32_t  numKeys;   // 10
		char      pad14[4];  // 14
		NiRotKey* keys;      // 18
		KeyType   keyType;   // 20
		uint8_t   keySize;   // 24
		uint8_t   pad25[3];  // 25
	};
	static_assert(sizeof(NiRotData) == 0x28);
}
