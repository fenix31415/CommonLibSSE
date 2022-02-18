#include "RE/T/TESObjectSTAT.h"

namespace RE
{
	bool TESObjectSTAT::HasTreeLOD() const
	{
		return (formFlags & RecordFlags::kHasTreeLOD) != 0;
	}

	bool TESObjectSTAT::IsSkyObject() const
	{
		return (formFlags & RecordFlags::kIsSkyObject) != 0;
	}

	bool TESObjectSTAT::IsSnowObject() const
	{
		return data.flags.all(TESObjectSTATData::Flag::kConsideredSnow);
	}
}
