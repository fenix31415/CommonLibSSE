#include "RE/N/NiPosData.h"

#include "RE/N/NiPosKey.h"

namespace RE
{
	NiPosData::NiPosData() :
		NiObject(), numKeys(0), keys(nullptr), keyType(KeyType::kNoInterp), keySize(0)
	{
	}

	NiPosData::~NiPosData()
	{
		NiPosKey::CleanKeys(keys, keyType);
	}

	const NiRTTI* NiPosData::GetRTTI() const
	{
		REL::Relocation<const NiRTTI*> rtti{ NiPosData::Ni_RTTI };
		return rtti.get();
	}

	void NiPosData::LoadBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiPosData::LoadBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(71541, 0) };
		return func(this, a_stream);
	}

	void NiPosData::LinkObject(NiStream& a_stream)
	{
		NiObject::LinkObject(a_stream);
	}

	bool NiPosData::RegisterStreamables(NiStream& a_stream)
	{
		return NiObject::RegisterStreamables(a_stream);
	}

	void NiPosData::SaveBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiPosData::SaveBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(71544, 0) };
		return func(this, a_stream);
	}

	bool NiPosData::IsEqual(NiObject* a_object)
	{
		auto b = static_cast<NiPosData*>(a_object);

		bool ans = NiObject::IsEqual(b) && numKeys == b->numKeys && keyType == b->keyType && keySize == b->keySize;
		if (!ans)
			return false;

		auto eq_rot = NiPosKey::GetEqualFunction(keyType);
		for (uint32_t i = 0; i < numKeys; i++) {
			auto a_key = keys->GetKeyAt(i, keySize);
			auto b_key = b->keys->GetKeyAt(i, keySize);
			if (!eq_rot(*a_key, *b_key))
				return false;
		}

		return true;
	}

	NiPosData* NiPosData::CreateObject()
	{
		return new NiPosData();
	}

	void NiPosData::ReplaceAnim(NiPosKey* new_keys, uint32_t new_numKeys, KeyType new_type)
	{
		NiPosKey::CleanKeys(keys, keyType);
		SetAnim(new_keys, new_numKeys, new_type);
	}

	void NiPosData::SetAnim(NiPosKey* new_keys, uint32_t new_numKeys, KeyType new_type)
	{
		if (new_keys && new_numKeys) {
			numKeys = new_numKeys;
			keys = new_keys;
			keyType = new_type;
			keySize = NiPosKey::GetKeySize(new_type);
		} else {
			numKeys = 0;
			keys = nullptr;
			keyType = KeyType::kNoInterp;
			keySize = 0;
		}
	}
}
