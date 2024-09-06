#include "RE/N/NiInterpolator.h"

namespace RE
{
	void NiInterpolator::CopyMembers(NiInterpolator* dst, NiCloningProcess& proc)
	{
		NiObject::CopyMembers(dst, proc);
	}

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

	NiInterpolator::NiInterpolator() :
		NiObject(), lastTime(-std::numeric_limits<float>::max())
	{
	}

	const NiRTTI* NiInterpolator::GetRTTI() const
	{
		REL::Relocation<const NiRTTI*> rtti{ NiInterpolator::Ni_RTTI };
		return rtti.get();
	}

	void NiInterpolator::LoadBinary(NiStream& a_stream)
	{
		NiObject::LoadBinary(a_stream);
	}

	void NiInterpolator::LinkObject(NiStream& a_stream)
	{
		NiObject::LinkObject(a_stream);
	}

	bool NiInterpolator::RegisterStreamables(NiStream& a_stream)
	{
		return NiObject::RegisterStreamables(a_stream);
	}

	void NiInterpolator::SaveBinary(NiStream& a_stream)
	{
		NiObject::SaveBinary(a_stream);
	}

	bool NiInterpolator::IsEqual(NiObject* a_object)
	{
		return NiObject::IsEqual(a_object);
	}

	bool NiInterpolator::Update1(float, NiObjectNET*, NiQuatTransform&)
	{
		return false;
	}

	bool NiInterpolator::Update2(float, NiObjectNET*, NiColorA&)
	{
		return false;
	}

	bool NiInterpolator::Update3(float, NiObjectNET*, NiPoint3&)
	{
		return false;
	}

	bool NiInterpolator::Update4(float, NiObjectNET*, NiQuaternion&)
	{
		return false;
	}

	bool NiInterpolator::Update5(float, NiObjectNET*, float&)
	{
		return false;
	}

	bool NiInterpolator::Update6(float, NiObjectNET*, bool&)
	{
		return false;
	}

	bool NiInterpolator::IsBoolValueSupported() const
	{
		return false;
	}

	bool NiInterpolator::IsFloatValueSupported() const
	{
		return false;
	}

	bool NiInterpolator::IsQuaternionValueSupported() const
	{
		return false;
	}

	bool NiInterpolator::IsPoint3ValueSupported() const
	{
		return false;
	}

	bool NiInterpolator::IsColorAValueSupported() const
	{
		return false;
	}

	bool NiInterpolator::IsTransformValueSupported() const
	{
		return false;
	}

	void NiInterpolator::Collapse()
	{
	}

	void NiInterpolator::GetActiveTimeRange(float& a_beginKeyTime, float& a_endKeyTime) const
	{
		a_beginKeyTime = 0;
		a_endKeyTime = 0;
	}

	void NiInterpolator::GuaranteeTimeRange(float, float)
	{
	}

	NiInterpolator* NiInterpolator::GetSequenceInterpolator(float, float)
	{
		auto ans = static_cast<NiInterpolator*>(this->Clone());
		ans->SetUpDependencies();
		return ans;
	}

	bool NiInterpolator::ResolveDependencies(NiAVObjectPalette*)
	{
		return true;
	}

	bool NiInterpolator::SetUpDependencies()
	{
		return true;
	}

	bool NiInterpolator::AlwaysUpdate() const
	{
		return false;
	}

	NiBoolInterpolator* NiInterpolator::AsNiBoolInterpolator()
	{
		return nullptr;
	}

}
