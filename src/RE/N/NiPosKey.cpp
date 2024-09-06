#include "RE/N/NiPosKey.h"

namespace RE
{
	void NiPosKey::CleanKeys(NiPosKey* keys, KeyType type)
	{
		if (keys)
			NiPosKey::GetDeleteFunction(type)(keys);
	}

	bool NiPosKey::Equal(const NiPosKey& a, const NiPosKey& b)
	{
		return NiAnimationKey::Equal(a, b) && a.val == b.val;
	}

	NiAnimationKey* (*NiPosKey::GetArrayFunction(KeyType type))(uint32_t size)
	{
		return NiAnimationKey::GetArrayFunction(KeyContent::kPos, type);
	}

	NiPoint3 NiPosKey::GenInterp(float time, NiPosKey* keys, KeyType type, uint32_t numKeys, uint32_t& curInd, uint8_t keySize)
	{
		using func_t = decltype(&NiPosKey::GenInterp);
		REL::Relocation<func_t> func{ RELOCATION_ID(71511, 0) };
		return func(time, keys, type, numKeys, curInd, keySize);
	}

	void (*NiPosKey::GetDeleteFunction(KeyType type))(NiAnimationKey*)
	{
		return NiAnimationKey::GetDeleteFunction(KeyContent::kPos, type);
	}

	bool (*NiPosKey::GetEqualFunction(KeyType type))(const NiAnimationKey& a, const NiAnimationKey& b)
	{
		return NiAnimationKey::GetEqualFunction(KeyContent::kPos, type);
	}

	void (*NiPosKey::GetFillDerivedFunction(KeyType type))(NiAnimationKey*, uint32_t numKeys, uint8_t keySize)
	{
		return NiAnimationKey::GetFillDerivedFunction(KeyContent::kPos, type);
	}

	uint8_t NiPosKey::GetKeySize(KeyType type)
	{
		return NiAnimationKey::GetKeySize(KeyContent::kPos, type);
	}
}
