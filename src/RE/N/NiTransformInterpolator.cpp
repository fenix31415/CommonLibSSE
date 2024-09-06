#include "RE/N/NiTransformInterpolator.h"

#include "RE/N/NiFloatKey.h"
#include "RE/N/NiPosKey.h"
#include "RE/N/NiRotKey.h"

namespace RE
{
	NiTransformInterpolator::NiTransformInterpolator(NiTransformData* data) :
		NiKeyBasedInterpolator(), val(), data(data), curPosInd(0), curRotInd(0), curScaleInd(0), useValue(false)
	{
	}

	NiTransformInterpolator::NiTransformInterpolator(NiQuatTransform val) :
		NiKeyBasedInterpolator(), val(std::move(val)), data(nullptr), curPosInd(0), curRotInd(0), curScaleInd(0), useValue(false)
	{
	}

	const NiRTTI* NiTransformInterpolator::GetRTTI() const
	{
		REL::Relocation<const NiRTTI*> rtti{ NiTransformInterpolator::Ni_RTTI };
		return rtti.get();
	}

	NiObject* NiTransformInterpolator::CreateClone(NiCloningProcess& a_cloning)
	{
		auto ans = new NiTransformInterpolator();
		CopyMembers(ans, a_cloning);
		return ans;
	}

	void NiTransformInterpolator::LoadBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiTransformInterpolator::LoadBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(71177, 0) };
		return func(this, a_stream);
	}

	void NiTransformInterpolator::LinkObject(NiStream& a_stream)
	{
		NiKeyBasedInterpolator::LinkObject(a_stream);
	}

	bool NiTransformInterpolator::RegisterStreamables(NiStream& a_stream)
	{
		if (NiKeyBasedInterpolator::RegisterStreamables(a_stream)) {
			if (data)
				data->RegisterStreamables(a_stream);
			return true;
		}
		return false;
	}

	void NiTransformInterpolator::SaveBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiTransformInterpolator::SaveBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(71180, 0) };
		return func(this, a_stream);
	}

	bool NiTransformInterpolator::IsEqual(NiObject* a_object)
	{
		auto b = static_cast<NiTransformInterpolator*>(a_object);
		bool ans = NiKeyBasedInterpolator::IsEqual(b) && val == b->val;
		if (!ans)
			return false;

		return data && b->data && data->IsEqual(b->data.get()) || !data && !b->data;
	}

	bool NiTransformInterpolator::Update1(float a_time, NiObjectNET*, NiQuatTransform& a_value)
	{
		if (useValue) {
			lastTime = a_time;
			a_value = val;
			return true;
		}

		if (a_time == lastTime) {
			a_value = val;
			return !val.isInvalid();
		}

		if (data) {
			if (uint32_t numKeysPos = data->numKeysPos) {
				uint32_t new_curPosInd = curPosInd;
				val.translation = NiPosKey::GenInterp(a_time, data->keysPos, data->typePos, numKeysPos, new_curPosInd, data->keySizePos);
				curPosInd = static_cast<uint16_t>(new_curPosInd);
			}

			if (uint32_t numKeysRot = data->numKeysRot) {
				uint32_t new_curRotInd = curRotInd;
				val.rotation = NiRotKey::GenInterp(a_time, data->keysRot, data->typeRot, numKeysRot, new_curRotInd, data->keySizeRot);
				curRotInd = static_cast<uint16_t>(new_curRotInd);
			}

			if (uint32_t numKeysScale = data->numKeysScale) {
				uint32_t new_curScaleInd = curScaleInd;
				val.scale = NiFloatKey::GenInterp(a_time, data->keysScale, data->typeScale, numKeysScale, new_curScaleInd, data->keySizeScale);
				curScaleInd = static_cast<uint16_t>(new_curScaleInd);
			}
		}

		a_value = val;
		bool valid = !val.isInvalid();
		if (valid)
			lastTime = a_time;
		return valid;
	}

	bool NiTransformInterpolator::Update2(float a_time, NiObjectNET* a_interpTarget, NiColorA& a_value)
	{
		return NiInterpolator::Update2(a_time, a_interpTarget, a_value);
	}

	bool NiTransformInterpolator::Update3(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value)
	{
		return NiInterpolator::Update3(a_time, a_interpTarget, a_value);
	}

	bool NiTransformInterpolator::Update4(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value)
	{
		return NiInterpolator::Update4(a_time, a_interpTarget, a_value);
	}

	bool NiTransformInterpolator::Update5(float a_time, NiObjectNET* a_interpTarget, float& a_value)
	{
		return NiInterpolator::Update5(a_time, a_interpTarget, a_value);
	}

	bool NiTransformInterpolator::Update6(float a_time, NiObjectNET* a_interpTarget, bool& a_value)
	{
		return NiInterpolator::Update6(a_time, a_interpTarget, a_value);
	}

	bool NiTransformInterpolator::IsTransformValueSupported() const
	{
		return true;
	}

	void NiTransformInterpolator::Collapse()
	{
		using func_t = decltype(&NiTransformInterpolator::Collapse);
		REL::Relocation<func_t> func{ RELOCATION_ID(71194, 0) };
		return func(this);
	}

	void NiTransformInterpolator::GetActiveTimeRange(float& a_beginKeyTime, float& a_endKeyTime) const
	{
		using func_t = decltype(&NiTransformInterpolator::GetActiveTimeRange);
		REL::Relocation<func_t> func{ RELOCATION_ID(71195, 0) };
		return func(this, a_beginKeyTime, a_endKeyTime);
	}

	void NiTransformInterpolator::GuaranteeTimeRange(float a_startTime, float a_endTime)
	{
		if (data)
			data->GuaranteeKeysAtStartAndEnd(a_startTime, a_endTime);
	}

	NiInterpolator* NiTransformInterpolator::GetSequenceInterpolator(float a_startTime, float a_endTime)
	{
		using func_t = decltype(&NiTransformInterpolator::GetSequenceInterpolator);
		REL::Relocation<func_t> func{ RELOCATION_ID(71197, 0) };
		return func(this, a_startTime, a_endTime);
	}

	uint16_t NiTransformInterpolator::GetKeyChannelCount() const
	{
		return 3;
	}

	uint32_t NiTransformInterpolator::GetKeyCount(uint16_t a_channel) const
	{
		switch (a_channel) {
		case 0:
			return data ? data->numKeysPos : 0;
		case 1:
			return data ? data->numKeysRot : 0;
		case 2:
			return data ? data->numKeysScale : 0;
		default:
			return 0;
		}
	}

	NiAnimationKey::KeyType NiTransformInterpolator::GetKeyType(uint16_t a_channel) const
	{
		switch (a_channel) {
		case 0:
			return data ? data->typePos : NiAnimationKey::KeyType::kNoInterp;
		case 1:
			return data ? data->typeRot : NiAnimationKey::KeyType::kNoInterp;
		case 2:
			return data ? data->typeScale : NiAnimationKey::KeyType::kNoInterp;
		default:
			return NiAnimationKey::KeyType::kNoInterp;
		}
	}

	NiAnimationKey::KeyContent NiTransformInterpolator::GetKeyContent(uint16_t a_channel) const
	{
		switch (a_channel) {
		case 0:
			return NiAnimationKey::KeyContent::kPos;
		case 1:
			return NiAnimationKey::KeyContent::kRot;
		case 2:
			return NiAnimationKey::KeyContent::kFloat;
		default:
			return NiAnimationKey::KeyContent::kTotal;
		}
	}

	NiAnimationKey* NiTransformInterpolator::GetKeyArray(uint16_t a_channel) const
	{
		switch (a_channel) {
		case 0:
			return data ? data->keysPos : nullptr;
		case 1:
			return data ? data->keysRot : nullptr;
		case 2:
			return data ? data->keysScale : nullptr;
		default:
			return nullptr;
		}
	}

	uint8_t NiTransformInterpolator::GetKeyStride(uint16_t a_channel) const
	{
		switch (a_channel) {
		case 0:
			return data ? data->keySizePos : 0;
		case 1:
			return data ? data->keySizeRot : 0;
		case 2:
			return data ? data->keySizeScale : 0;
		default:
			return 0;
		}
	}

	bool NiTransformInterpolator::GetChannelPosed(uint16_t a_channel) const
	{
		if (data && GetKeyCount(a_channel))
			return false;

		switch (a_channel) {
		case 0:
			return !val.isInvalidTranslation();
		case 1:
			return !val.isInvalidRotation();
		case 2:
			return !val.isInvalidScale();
		default:
			return false;
		}
	}

	NiTransformInterpolator* NiTransformInterpolator::CreateObject(void)
	{
		return new NiTransformInterpolator();
	}

	void NiTransformInterpolator::CopyMembers(NiTransformInterpolator* dst, NiCloningProcess& proc)
	{
		NiKeyBasedInterpolator::CopyMembers(dst, proc);

		dst->val = val;
		dst->data = data;
		dst->curPosInd = curPosInd;
		dst->curRotInd = curRotInd;
		dst->curScaleInd = curScaleInd;
	}

	void NiTransformInterpolator::SetPoseValue(const NiQuatTransform& new_val)
	{
		if (!val.isInvalidRotation()) {
			val.rotation = new_val.rotation;
			if (data)
				data->ReplaceRotAnim(nullptr, 0, KeyType::kNoInterp);
		}
		if (!val.isInvalidScale()) {
			val.scale = new_val.scale;
			if (data)
				data->ReplaceScaleAnim(nullptr, 0, KeyType::kNoInterp);
		}
		if (!val.isInvalidTranslation()) {
			val.translation = new_val.translation;
			if (data)
				data->ReplacePosAnim(nullptr, 0, KeyType::kNoInterp);
		}
	}
}
