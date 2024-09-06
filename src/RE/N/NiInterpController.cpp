#include "RE/N/NiInterpController.h"

namespace RE
{
	NiInterpController::NiInterpController() :
		NiTimeController()
	{
		flags.reset(Flag::kManagerControlled);
	}

	const NiRTTI* NiInterpController::GetRTTI() const
	{
		REL::Relocation<const NiRTTI*> rtti{ NiInterpController::Ni_RTTI };
		return rtti.get();
	}

	void NiInterpController::LoadBinary(NiStream& a_stream)
	{
		NiTimeController::LoadBinary(a_stream);
	}

	void NiInterpController::LinkObject(NiStream& a_stream)
	{
		NiTimeController::LinkObject(a_stream);
	}

	bool NiInterpController::RegisterStreamables(NiStream& a_stream)
	{
		return NiTimeController::RegisterStreamables(a_stream);
	}

	void NiInterpController::SaveBinary(NiStream& a_stream)
	{
		NiTimeController::SaveBinary(a_stream);
	}

	bool NiInterpController::IsEqual(NiObject* a_object)
	{
		return NiTimeController::IsEqual(a_object);
	}

	void NiInterpController::ResetTimeExtrema()
	{
		if (flags.all(Flag::kManagerControlled)) {
			loKeyTime = 0;
			hiKeyTime = 0;
		}
	}

	const char* NiInterpController::GetCtlrID()
	{
		return nullptr;
	}

	void NiInterpController::CopyMembers(NiInterpController* dst, NiCloningProcess& proc)
	{
		NiTimeController::CopyMembers(dst, proc);
	}
}
