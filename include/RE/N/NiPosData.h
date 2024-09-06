#pragma once

#include "RE/N/NiAnimationKey.h"
#include "RE/N/NiObject.h"

namespace RE
{
	class NiPosKey;

	class NiPosData : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiPosData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiPosData;

		using KeyType = NiAnimationKey::KeyType;

		NiPosData();
		~NiPosData() override;

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		bool          IsEqual(NiObject* a_object) override;              // 1C

		static NiPosData* CreateObject();

		void ReplaceAnim(NiPosKey* new_keys, uint32_t new_numKeys, KeyType new_type);
		void SetAnim(NiPosKey* new_keys, uint32_t new_numKeys, KeyType new_type);

		// members
		uint32_t  numKeys;   // 10
		char      pad14[4];  // 14
		NiPosKey* keys;      // 18
		KeyType   keyType;   // 20
		uint8_t   keySize;   // 24
		char      pad25[3];  // 25
	};
	static_assert(sizeof(NiPosData) == 0x28);
}
