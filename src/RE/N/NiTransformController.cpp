#include "RE/N/NiTransformController.h"

#include "RE/N/NiAVObject.h"
#include "RE/N/NiInterpolator.h"
#include "RE/N/NiQuatTransform.h"
#include "RE/N/NiRTTI.h"
#include "RE/N/NiTransformInterpolator.h"

namespace RE
{
	const NiRTTI* NiTransformController::GetRTTI() const
	{
		REL::Relocation<const NiRTTI*> rtti{ NiTransformController::Ni_RTTI };
		return rtti.get();
	}

	NiObject* NiTransformController::CreateClone(NiCloningProcess& a_cloning)
	{
		auto ans = new NiTransformController();
		NiSingleInterpController::CopyMembers(ans, a_cloning);
		return ans;
	}
		
	void NiTransformController::LoadBinary(NiStream& a_stream)
	{
		NiSingleInterpController::LoadBinary(a_stream);
	}

	void NiTransformController::LinkObject(NiStream& a_stream)
	{
		NiSingleInterpController::LinkObject(a_stream);
	}

	bool NiTransformController::RegisterStreamables(NiStream& a_stream)
	{
		return NiSingleInterpController::RegisterStreamables(a_stream);
	}

	void NiTransformController::SaveBinary(NiStream& a_stream)
	{
		NiSingleInterpController::SaveBinary(a_stream);
	}

	bool NiTransformController::IsEqual(NiObject* a_object)
	{
		return NiSingleInterpController::IsEqual(a_object);
	}

	void NiTransformController::Update(NiUpdateData& updateData)
	{
		if (flags.all(Flag::kManagerControlled)) {
			scaledTime = INVALID_TIME;
		} else if (NiTimeController::DontDoUpdate(updateData.time)) {
			if (!interpolator || !interpolator->AlwaysUpdate())
				return;
		}

		if (interpolator && target) {
			NiQuatTransform transform;
			if (interpolator->Update1(scaledTime, target, transform)) {
				auto _target = static_cast<NiAVObject*>(target);

				if (!transform.isInvalidTranslation())
					_target->local.translate = transform.translation;

				if (!transform.isInvalidRotation())
					transform.rotation.ToRotation(_target->local.rotate);

				if (!transform.isInvalidScale())
					_target->local.scale = std::abs(transform.scale);
			}
		}
	}

	bool NiTransformController::IsTransformController() const
	{
		return true;
	}

	NiInterpolator* NiTransformController::CreatePoseInterpolator(uint16_t)
	{
		auto _target = static_cast<NiAVObject*>(target);
		return new NiTransformInterpolator(NiQuatTransform(_target->local.translate, NiQuaternion{ _target->local.rotate }, _target->local.scale));
	}

	void NiTransformController::SynchronizePoseInterpolator(NiInterpolator* a_interp, uint16_t)
	{
		auto _target = static_cast<NiAVObject*>(target);
		static_cast<NiTransformInterpolator*>(a_interp)->SetPoseValue(NiQuatTransform(_target->local.translate, NiQuaternion{ _target->local.rotate }, _target->local.scale));
	}

	NiBlendInterpolator* NiTransformController::CreateBlendInterpolator(uint16_t a_index, bool a_managerControlled, bool a_accumulateAnimations, float a_weightThreshold, uint8_t a_arraySize) const
	{
		using func_t = decltype(&NiTransformController::CreateBlendInterpolator);
		REL::Relocation<func_t> func{ RELOCATION_ID(71339, 0) };
		return func(this, a_index, a_managerControlled, a_accumulateAnimations, a_weightThreshold, a_arraySize);
	}

	bool NiTransformController::InterpolatorIsCorrectType(NiInterpolator* a_interpolator, uint16_t) const
	{
		return a_interpolator->IsTransformValueSupported();
	}

	bool NiTransformController::InterpTargetIsCorrectType(NiObjectNET* a_target) const
	{
		if (!a_target)
			return false;

		auto rtti = a_target->GetRTTI();
		return rtti && rtti->IsKindOf(REL::Relocation<const NiRTTI*>(NiAVObject::Ni_RTTI).get());
	}

	NiTransformController* NiTransformController::CreateObject()
	{
		return new NiTransformController();
	}
}
