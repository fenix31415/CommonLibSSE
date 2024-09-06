#pragma once

#include "RE/N/NiAnimationKey.h"
#include "RE/N/NiObject.h"

namespace RE
{
	class NiFloatKey;
	class NiPosKey;
	class NiRotKey;

	class NiTransformData : public NiObject
	{
		void CleanPosAnim();
		void CleanRotAnim();
		void CleanScaleAnim();

	public:
		inline static constexpr auto RTTI = RTTI_NiTransformData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiTransformData;

		using KeyType = NiAnimationKey::KeyType;

		NiTransformData();
		~NiTransformData() override;

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		bool          IsEqual(NiObject* a_object) override;              // 1C

		static NiTransformData* Create();

		void GuaranteeKeysAtStartAndEnd(float start, float end);
		void ReplacePosAnim(NiPosKey* new_keys, uint32_t new_numKeys, KeyType new_type);
		void ReplaceRotAnim(NiRotKey* new_keys, uint32_t new_numKeys, KeyType new_type);
		void ReplaceScaleAnim(NiFloatKey* new_keys, uint32_t new_numKeys, KeyType new_type);
		void SetPosAnim(NiPosKey* new_keys, uint32_t new_numKeys, KeyType new_type);
		void SetRotAnim(NiRotKey* new_keys, uint32_t new_numKeys, KeyType new_type);
		void SetScaleAnim(NiFloatKey* new_keys, uint32_t new_numKeys, KeyType new_type);

		// members
		uint16_t    numKeysRot;    // 10
		uint16_t    numKeysPos;    // 12
		uint16_t    numKeysScale;  // 14
		char        pad16[2];      // 14
		KeyType     typeRot;       // 18
		KeyType     typePos;       // 1C
		KeyType     typeScale;     // 20
		uint8_t     keySizeRot;    // 24
		uint8_t     keySizePos;    // 25
		uint8_t     keySizeScale;  // 26
		char        pad27;         // 27
		NiRotKey*   keysRot;       // 27
		NiPosKey*   keysPos;       // 30
		NiFloatKey* keysScale;     // 38
	};
	static_assert(sizeof(NiTransformData) == 0x40);
}
