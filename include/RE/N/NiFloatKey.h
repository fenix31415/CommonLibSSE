#pragma once

#include "RE/N/NiAnimationKey.h"

namespace RE
{
	class NiFloatKey : public NiAnimationKey
	{
	public:
		NiFloatKey();
		NiFloatKey(float a_time, float a_value);
		~NiFloatKey();

		[[nodiscard]] float GetValue() const;
		void                SetValue(float a_value);
		NiFloatKey*         GetKeyAt(std::uint32_t a_index, std::uint8_t a_keySize);

		static void  CleanKeys(NiFloatKey* keys, KeyType type);
		static bool  Equal(const NiFloatKey& a, const NiFloatKey& b);
		static float GenInterp(float time, NiFloatKey* keys, KeyType type, uint32_t numKeys, uint32_t& curInd, uint8_t keySize);
		static void (*GetDeleteFunction(KeyType type))(NiAnimationKey*);
		static bool (*GetEqualFunction(KeyType type))(const NiAnimationKey& a, const NiAnimationKey& b);
		static uint8_t GetKeySize(KeyType type);

	protected:
		float _value;  // 04
	};
	static_assert(sizeof(NiFloatKey) == 0x8);

	class NiBezFloatKey : public NiFloatKey
	{
	public:
		// members
		float P1;  // 08
		float P2;  // 0C
	};
	static_assert(sizeof(NiBezFloatKey) == 0x10);

	class NiLinFloatKey : public NiFloatKey
	{
	};
	static_assert(sizeof(NiLinFloatKey) == 0x8);

	class NiTCBFloatKey : public NiFloatKey
	{
	public:
		// members
		float T;   // 08
		float C;   // 0C
		float B;   // 10
		float P1;  // 14
		float P2;  // 18
	};
	static_assert(sizeof(NiTCBFloatKey) == 0x1C);
}
