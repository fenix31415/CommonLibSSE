#include "RE/N/NiKeyBasedInterpolator.h"

namespace RE
{
	const NiRTTI* NiKeyBasedInterpolator::GetRTTI() const
	{
		REL::Relocation<const NiRTTI*> rtti{ NiKeyBasedInterpolator::Ni_RTTI };
		return rtti.get();
	}

	void NiKeyBasedInterpolator::LoadBinary(NiStream& a_stream)
	{
		NiInterpolator::LoadBinary(a_stream);
	}

	void NiKeyBasedInterpolator::LinkObject(NiStream& a_stream)
	{
		NiInterpolator::LinkObject(a_stream);
	}

	bool NiKeyBasedInterpolator::RegisterStreamables(NiStream& a_stream)
	{
		return NiInterpolator::RegisterStreamables(a_stream);
	}

	void NiKeyBasedInterpolator::SaveBinary(NiStream& a_stream)
	{
		NiInterpolator::SaveBinary(a_stream);
	}

	bool NiKeyBasedInterpolator::IsEqual(NiObject* a_object)
	{
		return NiInterpolator::IsEqual(a_object);
	}

	void NiKeyBasedInterpolator::GetActiveTimeRange(float& a_start, float& a_end) const
	{
		using func_t = decltype(&NiKeyBasedInterpolator::GetActiveTimeRange);
		REL::Relocation<func_t> func{ RELOCATION_ID(71463, 0) };
		return func(this, a_start, a_end);
	}

	void NiKeyBasedInterpolator::CopyMembers(NiKeyBasedInterpolator* dst, NiCloningProcess& proc)
	{
		NiInterpolator::CopyMembers(dst, proc);
	}

	NiAnimationKey* NiKeyBasedInterpolator::GetAnim(uint32_t& KeyCount, KeyType& KeyType, uint8_t& KeyStride, uint16_t channel)
	{
		KeyCount = GetKeyCount(channel);
		KeyType = GetKeyType(channel);
		KeyStride = GetKeyStride(channel);
		return static_cast<NiAnimationKey*>(GetKeyArray(channel));
	}

	NiAnimationKey* NiKeyBasedInterpolator::GetKeyAt(uint32_t ind, uint16_t channel) const
	{
		return reinterpret_cast<NiAnimationKey*>(reinterpret_cast<char*>(GetKeyArray(channel)) + ind * GetKeyStride(channel));
	}
}
