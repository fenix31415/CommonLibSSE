#include "RE/N/NiFloatData.h"

namespace RE
{
	NiFloatData::NiFloatData() :
		numKeys(0),
		pad14(0),
		keys(nullptr),
		type(KeyType::kNoInterp),
		keySize(0),
		pad25(0),
		pad26(0)
	{}

	NiFloatData::~NiFloatData()
	{
		NiFloatKey::CleanKeys(keys, type);
	}

	const NiRTTI* NiFloatData::GetRTTI() const
	{
		REL::Relocation<const NiRTTI*> rtti{ NiFloatData::Ni_RTTI };
		return rtti.get();
	}

	void NiFloatData::LoadBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiFloatData::LoadBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(71064, 0) };
		return func(this, a_stream);
	}

	void NiFloatData::LinkObject(NiStream& a_stream)
	{
		NiObject::LinkObject(a_stream);
	}

	bool NiFloatData::RegisterStreamables(NiStream& a_stream)
	{
		return NiObject::RegisterStreamables(a_stream);
	}

	void NiFloatData::SaveBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiFloatData::SaveBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(71067, 0) };
		return func(this, a_stream);
	}

	bool NiFloatData::IsEqual(NiObject* a_object)
	{
		auto b = static_cast<NiFloatData*>(a_object);
		bool ans = NiObject::IsEqual(b) && numKeys == b->numKeys && type == b->type && keySize == b->keySize;
		if (!ans)
			return false;

		auto eq_rot = NiFloatKey::GetEqualFunction(type);
		for (uint32_t i = 0; i < numKeys; i++) {
			auto a_key = keys->GetKeyAt(i, keySize);
			auto b_key = b->keys->GetKeyAt(i, keySize);
			if (!eq_rot(*a_key, *b_key))
				return false;
		}
		return true;
	}

	std::uint32_t NiFloatData::GetNumKeys() const
	{
		return numKeys;
	}

	NiFloatKey* NiFloatData::GetAnim(std::uint32_t& a_numKeys, KeyType& a_type, std::uint8_t& a_size) const
	{
		a_numKeys = numKeys;
		a_type = type;
		a_size = keySize;
		return keys;
	}
}
