#include "RE/N/NiFloatKey.h"

namespace RE
{
	NiFloatKey::NiFloatKey() :
		_value(0.0)
	{}

	NiFloatKey::NiFloatKey(float a_time, float a_value) :
		NiAnimationKey(a_time),
		_value(a_value)
	{}

	NiFloatKey::~NiFloatKey()
	{}

	float NiFloatKey::GetValue() const
	{
		return _value;
	}

	void NiFloatKey::SetValue(float a_value)
	{
		_value = a_value;
	}

	NiFloatKey* NiFloatKey::GetKeyAt(std::uint32_t a_index, std::uint8_t a_keySize)
	{
		return static_cast<NiFloatKey*>(NiAnimationKey::GetKeyAt(a_index, a_keySize));
	}

	void NiFloatKey::CleanKeys(NiFloatKey* keys, KeyType type)
	{
		if (keys)
			NiFloatKey::GetDeleteFunction(type)(keys);
	}

	bool NiFloatKey::Equal(const NiFloatKey& a, const NiFloatKey& b)
	{
		return NiAnimationKey::Equal(a, b) && a._value == b._value;
	}

	float NiFloatKey::GenInterp(float time, NiFloatKey* keys, KeyType type, uint32_t numKeys, uint32_t& curInd, uint8_t keySize)
	{
		using func_t = decltype(&NiFloatKey::GenInterp);
		REL::Relocation<func_t> func{ RELOCATION_ID(71474, 0) };
		return func(time, keys, type, numKeys, curInd, keySize);
	}

	void (*NiFloatKey::GetDeleteFunction(KeyType type))(NiAnimationKey*)
	{
		return NiAnimationKey::GetDeleteFunction(KeyContent::kFloat, type);
	}

	bool (*NiFloatKey::GetEqualFunction(KeyType type))(const NiAnimationKey& a, const NiAnimationKey& b)
	{
		return NiAnimationKey::GetEqualFunction(KeyContent::kFloat, type);
	}

	uint8_t NiFloatKey::GetKeySize(KeyType type)
	{
		return NiAnimationKey::GetKeySize(KeyContent::kFloat, type);
	}
}
