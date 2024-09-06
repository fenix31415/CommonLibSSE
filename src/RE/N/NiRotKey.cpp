#include "RE/N/NiRotKey.h"

namespace RE
{
	bool NiRotKey::Equal(const NiRotKey& a, const NiRotKey& b)
	{
		return NiAnimationKey::Equal(a, b) && a.val == b.val;
	}

	NiQuaternion NiRotKey::GenInterp(float time, NiRotKey* keys, KeyType type, uint32_t numKeys, uint32_t& curInd, uint8_t keySize)
	{
		using func_t = decltype(&NiRotKey::GenInterp);
		REL::Relocation<func_t> func{ RELOCATION_ID(71500, 0) };
		return func(time, keys, type, numKeys, curInd, keySize);
	}

	NiAnimationKey* (*NiRotKey::GetArrayFunction(KeyType type))(uint32_t size)
	{
		return NiAnimationKey::GetArrayFunction(KeyContent::kRot, type);
	}

	void (*NiRotKey::GetDeleteFunction(KeyType type))(NiAnimationKey*)
	{
		return NiAnimationKey::GetDeleteFunction(KeyContent::kRot, type);
	}

	bool (*NiRotKey::GetEqualFunction(KeyType type))(const NiAnimationKey& a, const NiAnimationKey& b)
	{
		return NiAnimationKey::GetEqualFunction(KeyContent::kRot, type);
	}

	void (*NiRotKey::GetFillDerivedFunction(KeyType type))(NiAnimationKey*, uint32_t numKeys, uint8_t keySize)
	{
		return NiAnimationKey::GetFillDerivedFunction(KeyContent::kRot, type);
	}

	uint8_t NiRotKey::GetKeySize(KeyType type)
	{
		return NiAnimationKey::GetKeySize(KeyContent::kRot, type);
	}
}
