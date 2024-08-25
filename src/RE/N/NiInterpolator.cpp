#include "RE/N/NiInterpolator.h"

namespace RE
{
	bool NiInterpolator::Update(float a_time, NiObjectNET* a_interpTarget, NiQuatTransform& a_value)
	{
		return Update1(a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update(float a_time, NiObjectNET* a_interpTarget, NiColorA& a_value)
	{
		return Update2(a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value)
	{
		return Update3(a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value)
	{
		return Update4(a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update(float a_time, NiObjectNET* a_interpTarget, float& a_value)
	{
		return Update5(a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update(float a_time, NiObjectNET* a_interpTarget, bool& a_value)
	{
		return Update6(a_time, a_interpTarget, a_value);
	}

	const NiRTTI* NiInterpolator::GetRTTI() const
	{
	}

	void NiInterpolator::LoadBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiInterpolator::LoadBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(71389, 0) };
		return func(this, a_stream);
	}

	void NiInterpolator::LinkObject(NiStream& a_stream)
	{
		using func_t = decltype(&NiInterpolator::LinkObject);
		REL::Relocation<func_t> func{ RELOCATION_ID(71389, 0) };
		return func(this, a_stream);
	}

	bool NiInterpolator::RegisterStreamables(NiStream& a_stream)
	{
		using func_t = decltype(&NiInterpolator::RegisterStreamables);
		REL::Relocation<func_t> func{ RELOCATION_ID(71390, 0) };
		return func(this, a_stream);
	}

	void NiInterpolator::SaveBinary(NiStream& a_stream)
	{
		using func_t = decltype(&NiInterpolator::SaveBinary);
		REL::Relocation<func_t> func{ RELOCATION_ID(71391, 0) };
		return func(this, a_stream);
	}

	bool NiInterpolator::IsEqual(NiObject* a_object)
	{
		using func_t = decltype(&NiInterpolator::IsEqual);
		REL::Relocation<func_t> func{ RELOCATION_ID(71392, 0) };
		return func(this, a_object);
	}

	bool NiInterpolator::Update1(float a_time, NiObjectNET* a_interpTarget, NiQuatTransform& a_value)
	{
		using func_t = decltype(&NiInterpolator::Update1);
		REL::Relocation<func_t> func{ RELOCATION_ID(71399, 0) };
		return func(this, a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update2(float a_time, NiObjectNET* a_interpTarget, NiColorA& a_value)
	{
		using func_t = decltype(&NiInterpolator::Update2);
		REL::Relocation<func_t> func{ RELOCATION_ID(71398, 0) };
		return func(this, a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update3(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value)
	{
		using func_t = decltype(&NiInterpolator::Update3);
		REL::Relocation<func_t> func{ RELOCATION_ID(71397, 0) };
		return func(this, a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update4(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value)
	{
		using func_t = decltype(&NiInterpolator::Update4);
		REL::Relocation<func_t> func{ RELOCATION_ID(71396, 0) };
		return func(this, a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update5(float a_time, NiObjectNET* a_interpTarget, float& a_value)
	{
		using func_t = decltype(&NiInterpolator::Update5);
		REL::Relocation<func_t> func{ RELOCATION_ID(71395, 0) };
		return func(this, a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update6(float a_time, NiObjectNET* a_interpTarget, bool& a_value)
	{
		using func_t = decltype(&NiInterpolator::Update6);
		REL::Relocation<func_t> func{ RELOCATION_ID(71394, 0) };
		return func(this, a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::IsBoolValueSupported() const
	{
		using func_t = decltype(&NiInterpolator::IsBoolValueSupported);
		REL::Relocation<func_t> func{ RELOCATION_ID(71394, 0) };
		return func(this);
	}
}
