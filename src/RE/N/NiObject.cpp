#include "RE/N/NiObject.h"

#include "RE/N/NiCloningProcess.h"
#include "RE/N/NiRTTI.h"
#include "RE/N/NiStream.h"

namespace RE
{
	const NiRTTI* NiObject::GetRTTI() const
	{
		REL::Relocation<const NiRTTI*> rtti{ NiObject::Ni_RTTI };
		return rtti.get();
	}

	bool NiObject::RegisterStreamables(NiStream& a_stream)
	{
		return a_stream.RegisterSaveObject(this);
	}

	bool NiObject::IsEqual(NiObject* a_object)
	{
		return a_object != nullptr && std::strcmp(GetRTTI()->GetName(), a_object->GetRTTI()->GetName()) == 0;
	}

	void NiObject::ProcessClone(NiCloningProcess& a_cloning)
	{
		using func_t = decltype(&NiObject::ProcessClone);
		REL::Relocation<func_t> func{ RELOCATION_ID(68838, 70190) };
		return func(this, a_cloning);
	}

	NiObject* NiObject::Clone()
	{
		using func_t = decltype(&NiObject::Clone);
		REL::Relocation<func_t> func{ RELOCATION_ID(68835, 0) };
		return func(this);
	}

	void NiObject::CopyMembers(NiObject* dst, NiCloningProcess& proc)
	{
		proc.cloneMap.insert({ this, dst });
	}

	void NiObject::CreateDeepCopy(NiPointer<NiObject>& a_object)
	{
		using func_t = decltype(&NiObject::CreateDeepCopy);
		REL::Relocation<func_t> func{ RELOCATION_ID(68839, 70191) };
		return func(this, a_object);
	}

	NiObject* NiObject::CreateSharedClone(NiCloningProcess& proc)
	{
		if (auto found = proc.cloneMap.find(this); found != proc.cloneMap.end()) {
			return found->second;
		} else {
			return CreateClone(proc);
		}
	}
}
