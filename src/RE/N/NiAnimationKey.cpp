#include "RE/N/NiAnimationKey.h"

namespace RE
{
	NiAnimationKey::NiAnimationKey() :
		_time(0.0)
	{}

	NiAnimationKey::NiAnimationKey(float a_time) :
		_time(a_time)
	{}

	NiAnimationKey::~NiAnimationKey()
	{}

	bool NiAnimationKey::Equal(const NiAnimationKey& a, const NiAnimationKey& b)
	{
		return a._time == b._time;
	}

	NiAnimationKey* (*NiAnimationKey::GetArrayFunction(KeyContent content, KeyType type))(uint32_t size)
	{
		return ms_arrays()[static_cast<uint32_t>(content)][static_cast<uint32_t>(type)];
	}

	void (*NiAnimationKey::GetDeleteFunction(NiAnimationKey::KeyContent content, NiAnimationKey::KeyType type))(NiAnimationKey*)
	{
		return ms_deletes()[static_cast<uint32_t>(content)][static_cast<uint32_t>(type)];
	}

	bool (*NiAnimationKey::GetEqualFunction(KeyContent content, KeyType type))(const NiAnimationKey& a, const NiAnimationKey& b)
	{
		return ms_equals()[static_cast<uint32_t>(content)][static_cast<uint32_t>(type)];
	}

	void (*NiAnimationKey::GetFillDerivedFunction(KeyContent content, KeyType type))(NiAnimationKey*, uint32_t numKeys, uint8_t keySize)
	{
		return ms_fillderived()[static_cast<uint32_t>(content)][static_cast<uint32_t>(type)];
	}

	uint8_t NiAnimationKey::GetKeySize(KeyContent content, KeyType type)
	{
		return ms_keysizes()[static_cast<uint32_t>(content)][static_cast<uint32_t>(type)];
	}

	void NiAnimationKey::GuaranteeKeyAtStartAndEnd(KeyContent content, KeyType type, NiAnimationKey*& keys, uint32_t& NumKeys, float start, float end)
	{
		using func_t = decltype(&NiAnimationKey::GuaranteeKeyAtStartAndEnd);
		REL::Relocation<func_t> func{ RELOCATION_ID(71059, 0) };
		return func(content, type, keys, NumKeys, start, end);
	}

	float NiAnimationKey::GetTime() const
	{
		return _time;
	}

	void NiAnimationKey::SetTime(float a_time)
	{
		_time = a_time;
	}

	NiAnimationKey* NiAnimationKey::GetKeyAt(std::uint32_t a_index, std::uint8_t a_keySize) const
	{
		return reinterpret_cast<NiAnimationKey*>((std::uint8_t*)this + a_index * a_keySize);
	}

	const NiAnimationKey::ms_keysizes_t& NiAnimationKey::ms_keysizes()
	{
		return *REL::Relocation<ms_keysizes_t*>(RELOCATION_ID(524317, 0));
	}

	const NiAnimationKey::ms_deletes_t& NiAnimationKey::ms_deletes()
	{
		return *REL::Relocation<ms_deletes_t*>(RELOCATION_ID(524233, 0));
	}

	const NiAnimationKey::ms_equals_t& NiAnimationKey::ms_equals()
	{
		return *REL::Relocation<ms_equals_t*>(RELOCATION_ID(524170, 0));
	}

	const NiAnimationKey::ms_arrays_t& NiAnimationKey::ms_arrays()
	{
		return *REL::Relocation<ms_arrays_t*>(RELOCATION_ID(524212, 0));
	}

	const NiAnimationKey::ms_fillderived_t& NiAnimationKey::ms_fillderived()
	{
		return *REL::Relocation<ms_fillderived_t*>(RELOCATION_ID(524296, 0));
	}
}
