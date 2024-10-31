#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkbEventBase.h"
#include "RE/H/hkbModifier.h"
#include "RE/N/NiQuaternion.h"

namespace RE
{
	struct BSLookAtModifierBoneData
	{
		// members
		int16_t      index;              // 00
		char         pad02[14];          // 02
		NiQuaternion fwdAxisLS;          // 10
		float        limitAngleDegrees;  //20
		float        onGain;             //24
		float        offGain;            //28
		bool         enabled;            // 2C
		char         pad2D[3];
		NiQuaternion currentFwdAxisLS;  // 30
	};
	static_assert(sizeof(BSLookAtModifierBoneData) == 0x40);

	class BSLookAtModifier : public hkbModifier
	{
	public:
		// members
		bool                              lookAtTarget;                // 50
		char                              pad51[7];                    // 51
		hkArray<BSLookAtModifierBoneData> bones;                       // 58
		hkArray<BSLookAtModifierBoneData> eyeBones;                    // 68
		float                             limitAngleDegrees;           // 78
		float                             limitAngleThresholdDegrees;  // 7C
		bool                              continueLookOutsideOfLimit;  // 80
		char                              pad81[3];                    // 81
		float                             onGain;                      // 84
		float                             offGain;                     // 88
		bool                              useBoneGains;                // 8C
		char                              pad8D[3];                    // 8D
		NiQuaternion                      targetLocation;              // 90
		bool                              targetOutsideLimits;         // A0
		char                              padA1[7];                    // A1
		hkbEventBase                      targetOutOfLimitEvent;       // A8
		bool                              lookAtCamera;                // B8
		char                              padB9[3];                    // B9
		NiPoint3                          lookAtCameraDir;             // BC
		float                             timeStep;                    // C8
		bool                              ballBonesValid;              // CC
		char                              padCD[3];                    // CD
		void*                             pSkeletonMemory;             // D0
	};
	static_assert(sizeof(BSLookAtModifier) == 0xD8);
}
