#include "RE/N/NiTransformData.h"

#include "RE/N/NiEulerRotKey.h"
#include "RE/N/NiFloatKey.h"
#include "RE/N/NiPosKey.h"
#include "RE/N/NiRotKey.h"

namespace RE
{
	NiTransformData::NiTransformData() :
		NiObject(),
		numKeysRot(0), numKeysPos(0), numKeysScale(0),
		typeRot(NiAnimationKey::KeyType::kNoInterp),
		typePos(NiAnimationKey::KeyType::kNoInterp),
		typeScale(NiAnimationKey::KeyType::kNoInterp),
		keySizeRot(0), keySizePos(0), keySizeScale(0),
		keysRot(nullptr), keysPos(nullptr), keysScale(nullptr)
	{
	}

	RE::NiTransformData::~NiTransformData()
	{
		CleanRotAnim();
		CleanPosAnim();
		CleanScaleAnim();
	}

	const NiRTTI* NiTransformData::GetRTTI() const
	{
		REL::Relocation<const NiRTTI*> rtti{ NiTransformData::Ni_RTTI };
		return rtti.get();
	}

	void NiTransformData::LoadBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiTransformData::LoadBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(71522, 0) };
		return func(this, a_stream);
	}

	void NiTransformData::LinkObject(NiStream& a_stream)
	{
		NiObject::LinkObject(a_stream);
	}

	bool NiTransformData::RegisterStreamables(NiStream& a_stream)
	{
		return NiObject::RegisterStreamables(a_stream);
	}

	void NiTransformData::SaveBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiTransformData::SaveBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(71525, 0) };
		return func(this, a_stream);
	}

	bool NiTransformData::IsEqual(NiObject* a_object)
	{
		auto b = static_cast<NiTransformData*>(a_object);
		bool ans = NiObject::IsEqual(b) &&
		           numKeysRot == b->numKeysRot && typeRot == b->typeRot &&
		           numKeysPos == b->numKeysPos && typePos == b->typePos &&
		           numKeysScale == b->numKeysScale && typeScale == b->typeScale &&
		           keySizeRot == b->keySizeRot && keySizePos == b->keySizePos && keySizeScale == b->keySizeScale;

		if (!ans)
			return false;

		auto eq_rot = NiRotKey::GetEqualFunction(typeRot);
		for (uint32_t i = 0; i < numKeysRot; i++) {
			auto a_key = keysRot->GetKeyAt(i, keySizeRot);
			auto b_key = b->keysRot->GetKeyAt(i, keySizeRot);
			if (!eq_rot(*a_key, *b_key))
				return false;
		}

		auto eq_pos = NiPosKey::GetEqualFunction(typePos);
		for (uint32_t i = 0; i < numKeysPos; i++) {
			auto a_key = keysPos->GetKeyAt(i, keySizePos);
			auto b_key = b->keysPos->GetKeyAt(i, keySizePos);
			if (!eq_pos(*a_key, *b_key))
				return false;
		}

		auto eq_scale = NiFloatKey::GetEqualFunction(typeScale);
		for (uint32_t i = 0; i < numKeysScale; i++) {
			auto a_key = keysScale->GetKeyAt(i, keySizeScale);
			auto b_key = b->keysScale->GetKeyAt(i, keySizeScale);
			if (!eq_scale(*a_key, *b_key))
				return false;
		}

		return true;
	}

	NiTransformData* NiTransformData::Create()
	{
		return new NiTransformData();
	}

	void NiTransformData::CleanPosAnim()
	{
		if (keysPos)
			NiPosKey::GetDeleteFunction(typePos)(keysPos);
	}

	void NiTransformData::CleanRotAnim()
	{
		if (keysRot) {
			if (typeRot == KeyType::kEuler)
				(static_cast<NiEulerRotKey*>(keysRot))->CleanUp();

			NiRotKey::GetDeleteFunction(typeRot)(keysRot);
		}
	}

	void NiTransformData::CleanScaleAnim()
	{
		NiFloatKey::CleanKeys(keysScale, typeScale);
	}

	void NiTransformData::GuaranteeKeysAtStartAndEnd(float start, float end)
	{
		if (numKeysRot) {
			uint32_t numKeys = numKeysRot;
			auto     keys = static_cast<NiAnimationKey*>(keysRot);
			NiAnimationKey::GuaranteeKeyAtStartAndEnd(NiAnimationKey::KeyContent::kRot, typeRot, keys, numKeys, start, end);
			numKeysRot = static_cast<uint16_t>(numKeys);
			keysRot = static_cast<NiRotKey*>(keys);
		}

		if (numKeysPos) {
			uint32_t numKeys = numKeysPos;
			auto     keys = static_cast<NiAnimationKey*>(keysPos);
			NiAnimationKey::GuaranteeKeyAtStartAndEnd(NiAnimationKey::KeyContent::kPos, typePos, keys, numKeys, start, end);
			numKeysPos = static_cast<uint16_t>(numKeys);
			keysPos = static_cast<NiPosKey*>(keys);
		}

		if (numKeysScale) {
			uint32_t numKeys = numKeysScale;
			auto     keys = static_cast<NiAnimationKey*>(keysScale);
			NiAnimationKey::GuaranteeKeyAtStartAndEnd(NiAnimationKey::KeyContent::kFloat, typeScale, keys, numKeys, start, end);
			numKeysScale = static_cast<uint16_t>(numKeys);
			keysScale = static_cast<NiFloatKey*>(keys);
		}
	}

	void NiTransformData::ReplacePosAnim(NiPosKey* new_keys, uint32_t new_numKeys, KeyType new_type)
	{
		CleanPosAnim();
		SetPosAnim(new_keys, new_numKeys, new_type);
	}

	void NiTransformData::ReplaceRotAnim(NiRotKey* new_keys, uint32_t new_numKeys, KeyType new_type)
	{
		CleanRotAnim();
		SetRotAnim(new_keys, new_numKeys, new_type);
	}

	void NiTransformData::ReplaceScaleAnim(NiFloatKey* new_keys, uint32_t new_numKeys, KeyType new_type)
	{
		CleanScaleAnim();
		SetScaleAnim(new_keys, new_numKeys, new_type);
	}

	void NiTransformData::SetPosAnim(NiPosKey* new_keys, uint32_t new_numKeys, KeyType new_type)
	{
		if (new_keys && new_numKeys) {
			numKeysPos = static_cast<uint16_t>(new_numKeys);
			keysPos = new_keys;
			typePos = new_type;
			keySizePos = NiPosKey::GetKeySize(new_type);
		} else {
			numKeysPos = 0;
			keysPos = nullptr;
			typePos = KeyType::kNoInterp;
			keySizePos = 0;
		}
	}

	void NiTransformData::SetRotAnim(NiRotKey* new_keys, uint32_t new_numKeys, KeyType new_type)
	{
		if (new_keys && new_numKeys) {
			numKeysRot = static_cast<uint16_t>(new_numKeys);
			keysRot = new_keys;
			typeRot = new_type;
			keySizeRot = NiRotKey::GetKeySize(new_type);
		} else {
			numKeysRot = 0;
			keysRot = nullptr;
			typeRot = KeyType::kNoInterp;
			keySizeRot = 0;
		}
	}

	void NiTransformData::SetScaleAnim(NiFloatKey* new_keys, uint32_t new_numKeys, KeyType new_type)
	{
		if (new_keys && new_numKeys) {
			numKeysScale = static_cast<uint16_t>(new_numKeys);
			keysScale = new_keys;
			typeScale = new_type;
			keySizeScale = NiPosKey::GetKeySize(new_type);
		} else {
			numKeysScale = 0;
			keysScale = nullptr;
			typeScale = KeyType::kNoInterp;
			keySizeScale = 0;
		}
	}
}
