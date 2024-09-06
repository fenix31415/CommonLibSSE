#include "RE/N/NiTimeController.h"

#include "RE/N/NiCloningProcess.h"
#include "RE/N/NiObjectNET.h"

namespace RE
{
	NiTimeController::NiTimeController() :
		NiObject(),
		flags(),
		frequency(1),
		phase(0),
		loKeyTime(std::numeric_limits<float>::max()),
		hiKeyTime(-std::numeric_limits<float>::max()),
		startTime(-std::numeric_limits<float>::max()),
		lastTime(-std::numeric_limits<float>::max()),
		weightedLastTime(0),
		scaledTime(-std::numeric_limits<float>::max()),
		target(nullptr),
		next(nullptr)
	{
		flags.set(Flag::kCycleType_Clamp, Flag::kActive, Flag::kComputeScaledTime);
	}

	const NiRTTI* NiTimeController::GetRTTI() const
	{
		REL::Relocation<const NiRTTI*> rtti{ NiTimeController::Ni_RTTI };
		return rtti.get();
	}

	void NiTimeController::LoadBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiTimeController::LoadBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(69433, 70810) };
		return func(this, a_stream);
	}

	void NiTimeController::LinkObject(NiStream& a_stream)
	{
		using func_t = decltype(&NiTimeController::LinkObject);
		REL::Relocation<func_t> func{ RELOCATION_ID(69434, 70811) };
		return func(this, a_stream);
	}

	bool NiTimeController::RegisterStreamables(NiStream& a_stream)
	{
		if (NiObject::RegisterStreamables(a_stream)) {
			if (next)
				next->RegisterStreamables(a_stream);
			return true;
		}
		return false;
	}

	void NiTimeController::SaveBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiTimeController::SaveBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(69436, 70813) };
		return func(this, a_stream);
	}

	bool NiTimeController::IsEqual(NiObject* a_object)
	{
		auto b = static_cast<NiTimeController*>(a_object);

		return NiObject::IsEqual(b) &&
		       flags.underlying() == b->flags.underlying() &&
		       frequency == b->frequency &&
		       phase == b->phase &&
		       loKeyTime == b->loKeyTime &&
		       hiKeyTime == b->hiKeyTime &&
		       (target && b->target || !target && !b->target);
	}

	void NiTimeController::ProcessClone(NiCloningProcess& a_cloning)
	{
		NiObject::ProcessClone(a_cloning);
		if (next)
			return next->ProcessClone(a_cloning);
	}

	void NiTimeController::Start(float a_time)
	{
		flags.set(Flag::kActive);
		lastTime = -std::numeric_limits<float>::max();
		if (flags.all(Flag::kAnimType_AppInit))
			startTime = a_time;
	}

	void NiTimeController::Stop()
	{
		lastTime = -std::numeric_limits<float>::max();
		flags.reset(Flag::kActive);
		if (flags.all(Flag::kAnimType_AppInit))
			startTime = -std::numeric_limits<float>::max();
	}

	void NiTimeController::SetTarget(NiObjectNET* a_target)
	{
		using func_t = decltype(&NiTimeController::SetTarget);
		REL::Relocation<func_t> func{ RELOCATION_ID(69442, 70819) };
		return func(this, a_target);
	}

	float NiTimeController::ComputeScaledTime(float a_time)
	{
		using func_t = decltype(&NiTimeController::ComputeScaledTime);
		REL::Relocation<func_t> func{ RELOCATION_ID(69447, 70824) };
		return func(this, a_time);
	}

	void NiTimeController::StartAnimations(NiObjectNET* a_target)
	{
		using func_t = decltype(&NiTimeController::StartAnimations);
		REL::Relocation<func_t> func{ RELOCATION_ID(69444, 70821) };
		return func(a_target);
	}

	void NiTimeController::CopyMembers(NiTimeController* dst, NiCloningProcess& proc)
	{
		NiObject::CopyMembers(dst, proc);

		dst->flags = flags;
		dst->frequency = frequency;
		dst->phase = phase;
		dst->loKeyTime = loKeyTime;
		dst->hiKeyTime = hiKeyTime;
		dst->startTime = startTime;
		dst->lastTime = lastTime;
		dst->weightedLastTime = weightedLastTime;

		if (target) {
			if (auto found = proc.cloneMap.find(target); found != proc.cloneMap.end() && target->GetRTTI() == found->second->GetRTTI()) {
				dst->target = static_cast<NiObjectNET*>(found->second);
			} else {
				dst->target = nullptr;
			}
		}

		if (next) {
			dst->next = NiTimeControllerPtr(static_cast<NiTimeController*>(next->CreateClone(proc)));
		}
	}

	bool NiTimeController::DontDoUpdate(float time)
	{
		if (flags.all(Flag::kActive) && (time != lastTime || (flags.all(Flag::kForceUpdate)))) {
			if (!flags.all(Flag::kComputeScaledTime)) {
				flags.reset(Flag::kForceUpdate);
				return false;
			}

			if (float new_scaledTime = ComputeScaledTime(time); new_scaledTime != scaledTime || flags.all(Flag::kForceUpdate)) {
				scaledTime = new_scaledTime;
				flags.reset(Flag::kForceUpdate);
				return false;
			}
		}
		return true;
	}
}
