#include "RE/A/AnimationClipDataSingleton.h"

namespace RE
{
	AnimationClipDataSingleton* AnimationClipDataSingleton::GetSingleton()
	{
		return *REL::Relocation<AnimationClipDataSingleton**>(RELOCATION_ID(515414, 0));  // I do not know for AE
	}

	bool AnimationClipDataSingleton::GetClipInformation(const BSFixedString& project_name, const BSFixedString& clip_name, AnimationClipData& ClipInformation)
	{
		using func_t = decltype(&AnimationClipDataSingleton::GetClipInformation);
		REL::Relocation<func_t> func{ RELOCATION_ID(31799, 0) };  // I do not know for AE
		return func(this, project_name, clip_name, ClipInformation);
	}

	bool AnimationClipDataSingleton::ClipData::GetEventTime(const BSFixedString& event_name, float& time)
	{
		using func_t = decltype(&AnimationClipDataSingleton::ClipData::GetEventTime);
		REL::Relocation<func_t> func{ RELOCATION_ID(31803, 0) };  // I do not know for AE
		return func(this, event_name, time);
	}

	uint16_t BSUtilities::ConvertFloatToHalf(float val)
	{
		using func_t = decltype(BSUtilities::ConvertFloatToHalf);
		REL::Relocation<func_t> func{ RELOCATION_ID(74491, 0) };  // I do not know for AE
		return func(val);
	}

	float BSUtilities::ConvertHalfToFloat(uint16_t val)
	{
		using func_t = decltype(BSUtilities::ConvertHalfToFloat);
		REL::Relocation<func_t> func{ RELOCATION_ID(74492, 0) };  // I do not know for AE
		return func(val);
	}
}
