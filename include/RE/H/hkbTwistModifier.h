#pragma once

#include "RE/H/hkbModifier.h"

namespace RE
{
	/// A modifier to twist a chain of bones (such as the spine of the character) around a given axis.
	class hkbTwistModifier : public hkbModifier
	{
	public:
		// members
		hkVector4        axisOfRotation;           // 50 - The axis of rotation
		float            twistAngle;               // 60 - The total twist angle to apply to chain of bones
		int16_t          startBoneIndex;           // 64 - Index of the first bone in the chain. This bone must be closer to the root than endBoneIndex.
		int16_t          endBoneIndex;             // 66 - Index of the last bone in the chain. This bone must be farther from the root than startBoneIndex.
		int8_t           setAngleMethod;           // 68 - Twist angle per bone increased via LINEAR or RAMPED method
		int8_t           rotationAxisCoordinates;  // 69 - Whether the m_axisOfRotation is in model space or local space
		bool             isAdditive;               // 6A - Twist angle per bone is ADDITIVE or NOT
		char             pad6B[5];                 // 6B
		hkArray<int16_t> boneChainIndices;         // 70 - The bone chain which we want to twist
		hkArray<int16_t> parentBoneIndices;        // 80 - The parent indices of m_startBoneIndex
	};
	static_assert(sizeof(hkbTwistModifier) == 0x90);
}
