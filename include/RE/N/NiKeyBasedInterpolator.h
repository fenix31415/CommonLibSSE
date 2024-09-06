#pragma once

#include "RE/N/NiAnimationKey.h"
#include "RE/N/NiInterpolator.h"

namespace RE
{
	class NiKeyBasedInterpolator : public NiInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiKeyBasedInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiKeyBasedInterpolator;

		using KeyType = NiAnimationKey::KeyType;
		using KeyContent = NiAnimationKey::KeyContent;

		NiKeyBasedInterpolator() = default;
		~NiKeyBasedInterpolator() override = default;  // 00

		// override (NiInterpolator)
		const NiRTTI* GetRTTI() const override;                                         // 02
		void          LoadBinary(NiStream& a_stream) override;                          // 18
		void          LinkObject(NiStream& a_stream) override;                          // 19
		bool          RegisterStreamables(NiStream& a_stream) override;                 // 1A
		void          SaveBinary(NiStream& a_stream) override;                          // 1B
		bool          IsEqual(NiObject* a_object) override;                             // 1C
		void          GetActiveTimeRange(float& a_start, float& a_end) const override;  // 32

		// add
		[[nodiscard]] virtual uint16_t        GetKeyChannelCount() const = 0;                 // 39
		[[nodiscard]] virtual uint32_t        GetKeyCount(uint16_t a_channel) const = 0;      // 3A
		[[nodiscard]] virtual KeyType         GetKeyType(uint16_t a_channel) const = 0;       // 3C
		[[nodiscard]] virtual KeyContent      GetKeyContent(uint16_t a_channel) const = 0;    // 3B
		[[nodiscard]] virtual NiAnimationKey* GetKeyArray(uint16_t a_channel) const = 0;      // 3D
		[[nodiscard]] virtual uint8_t         GetKeyStride(uint16_t a_channel) const = 0;     // 3E
		[[nodiscard]] virtual bool            GetChannelPosed(uint16_t a_channel) const = 0;  // 3F

		void            CopyMembers(NiKeyBasedInterpolator* dst, NiCloningProcess& proc);
		NiAnimationKey* GetAnim(uint32_t& KeyCount, KeyType& KeyType, uint8_t& KeyStride, uint16_t channel);
		NiAnimationKey* GetKeyAt(uint32_t ind, uint16_t channel) const;
		// void FillDerivedValues(uint16 channel);   used NiAnimationKey::ms_fillderived
	};
	static_assert(sizeof(NiKeyBasedInterpolator) == 0x18);
}
