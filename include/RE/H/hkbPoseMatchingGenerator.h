#pragma once

#include "RE/H/hkbBlenderGenerator.h"

namespace RE
{
	class hkbPoseMatchingGenerator : public hkbBlenderGenerator
	{
	public:
		/// The modifier is either performing matching or playing out the matched animation.
		enum class Mode : uint8_t
		{
			/// Perform pose matching.  Generate the currently matched pose.
			MODE_MATCH,

			/// Play back the current animation beginning at the matched pose.
			MODE_PLAY
		};

		// members
		NiQuaternion worldFromModelRotation;      // A0 -- The rotation of the frame of reference used for pose matching.
		float        blendSpeed;                  // B0 -- Speed at which to blend in and out the blend weights (in weight units per second).
		float        minSpeedToSwitch;            // B4 -- Don't switch if the pelvis speed is below this.
		float        minSwitchTimeNoError;        // B8 -- The minimum time between switching matches when the matching error is 0.
		float        minSwitchTimeFullError;      // BC -- The minimum time between switching matches when the matching error is 1.
		int32_t      startPlayingEventId;         // C0 -- An event to set m_mode to MODE_PLAY.
		int32_t      startMatchingEventId;        // C4 -- An event to set m_mode to MODE_MATCH.
		int16_t      rootBoneIndex;               // C8 -- The root (ragdoll) bone used for pose matching.  If this is -1, the index is taken from the character's hkbBoneInfo.
		int16_t      otherBoneIndex;              // CA -- A second (ragdoll) bone used for pose matching.  If this is -1, the index is taken from the character's hkbBoneInfo.
		int16_t      anotherBoneIndex;            // CC -- A third (ragdoll) bone used for pose matching.  If this is -1, the index is taken from the character's hkbBoneInfo.
		int16_t      pelvisIndex;                 // CD -- The (ragdoll) pelvis bone used to measure the speed of the ragdoll.
		Mode         mode;                        // D0 -- Whether matching poses or playing out the remaining animation.
		char         padD1[3];                    // D1
		int32_t      currentMatch;                // D4 -- The index of the child that is the current match to the ragdoll pose.
		int32_t      bestMatch;                   // D8 -- The child that matches best to the ragdoll.
		float        timeSinceBetterMatch;        // DC -- The time since m_bestMatch changed.
		float        error;                       // E0 -- The current error (between 0 and 1).
		bool         resetCurrentMatchLocalTime;  // E4 -- When the mode changes from playing to matching we need to reset the local time of the playing clip to zero.
		char         padE5[3];                    // E5
		void*        poseMatchingUtility;         // E8 -- A pose matching utility which does the work.
	};
	static_assert(sizeof(hkbPoseMatchingGenerator) == 0xF0);

}
