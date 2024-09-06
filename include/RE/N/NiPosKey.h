#pragma once

#include "RE/N/NiAnimationKey.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class NiPosKey : public NiAnimationKey
	{
	public:
		static void            CleanKeys(NiPosKey* keys, KeyType type);
		static bool            Equal(const NiPosKey& a, const NiPosKey& b);
		static NiAnimationKey* (*GetArrayFunction(KeyType type))(uint32_t size);
		static NiPoint3        GenInterp(float time, NiPosKey* keys, KeyType type, uint32_t numKeys, uint32_t& curInd, uint8_t keySize);
		static void            (*GetDeleteFunction(KeyType type))(NiAnimationKey*);
		static bool            (*GetEqualFunction(KeyType type))(const NiAnimationKey& a, const NiAnimationKey& b);
		static void            (*GetFillDerivedFunction(KeyType type))(NiAnimationKey*, uint32_t numKeys, uint8_t keySize);
		static uint8_t         GetKeySize(KeyType type);

		// members
		NiPoint3 val;  // 04
	};
	static_assert(sizeof(NiPosKey) == 0x10);

	class NiBezPosKey : public NiPosKey
	{
	public:
		// members
		NiPoint3 P_unk;  // 10
		NiPoint3 P1;     // 1C
		NiPoint3 P2;     // 28
		NiPoint3 P3;     // 34
	};
	static_assert(sizeof(NiBezPosKey) == 0x40);

	class NiLinPosKey : public NiPosKey
	{
	};
	static_assert(sizeof(NiLinPosKey) == 0x10);

	class NiTCBPosKey : public NiPosKey
	{
	public:
		// members
		NiPoint3 T;   // 10
		NiPoint3 C;   // 1C
		NiPoint3 B;   // 28
		NiPoint3 P1;  // 34
		NiPoint3 P2;  // 40
	};
	static_assert(sizeof(NiTCBPosKey) == 0x4C);
}
