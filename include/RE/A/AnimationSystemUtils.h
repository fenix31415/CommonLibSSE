#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class BoundAnimationData;
	class BSAnimationGraphManager;
	class ClipGeneratorData;
	class NiPoint3;
	class NiQuaternion;
	class TESObjectREFR;

	namespace AnimationSystemUtils
	{

		class UtilsClipData
		{
			ClipGeneratorData*  eventData;      // 00
			BoundAnimationData* movement_data;  // 08
			float               playbackSpeed;  // 10
			float               weight;         // 14
			bool                isMirror;       // 18
			char                pad19[7];       // 19
		};
		static_assert(sizeof(UtilsClipData) == 0x20);

		using ClipInfo = BSScrapArray<UtilsClipData>;

		bool  GetAnimationEndpoint(TESObjectREFR* refr, const ClipInfo& clipInfo, NiPoint3& translation, NiPoint3& rotation_angles, float& end_time, NiPoint3& translation_start, NiPoint3& translation_delta, NiPoint3& rotation_start_angles, NiPoint3& rotate_from_before_angles);
		float GetAnimationEndTime(const ClipInfo& clipInfo);
		float GetAnimationMaxDuration(TESObjectREFR* refr);
		bool  GetAnimationTranslation(const ClipInfo& clipInfo, NiPoint3& translation);
		bool  GetAttackClipData(const BSFixedString& project_name, const BSFixedString& clip_name, float& hitframe_time, NiPoint3& hitframe_pos, NiPoint3& a_final_pos);
		bool  GetClipInfo(BSAnimationGraphManager* mngr, int32_t activeGraph_ind, const BSScrapArray<BSFixedString>& events, ClipInfo& clipInfo);
		bool  GetClipInfoFromEvent(TESObjectREFR* a, const BSFixedString& event_name, ClipInfo& clipInfo);
		bool  GetEventTime(const ClipInfo& clipInfo, const BSFixedString& event_name, float& event_time);
		void  GetTranslationFromClipData(const ClipInfo& clipInfo, float time, NiPoint3& translation);
		bool  SumAnimationDataToTime(const ClipInfo& clipInfo, float time, NiPoint3& translation, NiQuaternion& rotation);
	}
}
