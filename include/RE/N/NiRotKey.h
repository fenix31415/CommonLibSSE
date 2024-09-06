#pragma once

#include "RE/N/NiAnimationKey.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiQuaternion.h"

namespace RE
{
	class NiRotKey : public NiAnimationKey
	{
	public:
		static bool         Equal(const NiRotKey& a, const NiRotKey& b);
		static NiQuaternion GenInterp(float time, NiRotKey* keys, KeyType type, uint32_t numKeys, uint32_t& curInd, uint8_t keySize);
		static NiAnimationKey* (*GetArrayFunction(KeyType type))(uint32_t size);
		static void (*GetDeleteFunction(KeyType type))(NiAnimationKey*);
		static bool (*GetEqualFunction(KeyType type))(const NiAnimationKey& a, const NiAnimationKey& b);
		static void (*GetFillDerivedFunction(KeyType type))(NiAnimationKey*, uint32_t numKeys, uint8_t keySize);
		static uint8_t GetKeySize(KeyType type);

		// members
		NiQuaternion val;  // 04
	};
	static_assert(sizeof(NiRotKey) == 0x14);

	class NiBezRotKey : public NiRotKey
	{
	public:
		// members
		NiQuaternion P;  // 14
	};
	static_assert(sizeof(NiBezRotKey) == 0x24);

	class NiLinRotKey : public NiRotKey
	{
	};
	static_assert(sizeof(NiLinRotKey) == 0x14);

	class NiTCBRotKey : public NiRotKey
	{
	public:
		// members
		NiPoint3     P;   // 14
		NiQuaternion S1;  // 20
		NiQuaternion S2;  // 30
	};
	static_assert(sizeof(NiTCBRotKey) == 0x40);
}
