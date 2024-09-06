#include "RE/N/NiSingleInterpController.h"

#include "RE/N/NiInterpolator.h"
#include "RE/N/NiObjectNET.h"

namespace RE
{
	const NiRTTI* NiSingleInterpController::GetRTTI() const
	{
		REL::Relocation<const NiRTTI*> rtti{ NiSingleInterpController::Ni_RTTI };
		return rtti.get();
	}

	void NiSingleInterpController::LoadBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiSingleInterpController::LoadBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(71157, 0) };
		return func(this, a_stream);
	}

	void NiSingleInterpController::LinkObject(NiStream& a_stream)
	{
		NiInterpController::LinkObject(a_stream);
	}

	bool NiSingleInterpController::RegisterStreamables(NiStream& a_stream)
	{
		if (NiInterpController::RegisterStreamables(a_stream)) {
			if (interpolator)
				interpolator->RegisterStreamables(a_stream);
			return true;
		}
		return false;
	}

	void NiSingleInterpController::SaveBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiSingleInterpController::SaveBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(71160, 0) };
		return func(this, a_stream);
	}

	bool NiSingleInterpController::IsEqual(NiObject* a_object)
	{
		auto b = static_cast<NiSingleInterpController*>(a_object);
		return NiInterpController::IsEqual(b) &&
		       (interpolator && b->interpolator && interpolator->IsEqual(b->interpolator.get()) ||
				   !interpolator && !b->interpolator);
	}

	void NiSingleInterpController::ProcessClone(NiCloningProcess& a_cloning)
	{
		NiTimeController::ProcessClone(a_cloning);
		if (interpolator)
			interpolator->ProcessClone(a_cloning);
	}

	bool NiSingleInterpController::TargetIsRequiredType() const
	{
		return InterpTargetIsCorrectType(target);
	}

	uint16_t NiSingleInterpController::GetInterpolatorCount() const
	{
		return 1;
	}

	const char* NiSingleInterpController::GetInterpolatorID(uint16_t)
	{
		return nullptr;
	}

	uint16_t NiSingleInterpController::GetInterpolatorIndex(const char*) const
	{
		return 0;
	}

	uint16_t NiSingleInterpController::GetInterpolatorIndexFx(const BSFixedString& a_id) const
	{
		if (target->name == a_id)
			return 0;
		else
			return NiInterpController::INVALID_INDEX;
	}

	NiInterpolator* NiSingleInterpController::GetInterpolator(uint16_t) const
	{
		return interpolator.get();
	}

	void NiSingleInterpController::SetInterpolator(NiInterpolator* a_interpolator, uint16_t)
	{
		interpolator = NiPointer<NiInterpolator>(a_interpolator);
	}

	void NiSingleInterpController::ResetTimeExtrema()
	{
		if (!flags.all(Flag::kManagerControlled)) {
			NiInterpController::ResetTimeExtrema();
			if (interpolator)
				interpolator->GetActiveTimeRange(loKeyTime, hiKeyTime);
		}
	}

	void NiSingleInterpController::GuaranteeTimeRange(float a_startTime, float a_endTime)
	{
		if (interpolator)
			interpolator->GuaranteeTimeRange(a_startTime, a_endTime);
	}

	void NiSingleInterpController::CopyMembers(NiSingleInterpController* dst, NiCloningProcess& proc)
	{
		NiInterpController::CopyMembers(dst, proc);

		if (interpolator) {
			dst->interpolator = NiPointer<NiInterpolator>(static_cast<NiInterpolator*>(interpolator->CreateSharedClone(proc)));
		}
	}
}
