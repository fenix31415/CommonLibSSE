#pragma once

#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkStringPtr.h"

namespace RE
{
	struct LocalFrameOnBone;
	class hkQsTransform;
	class hkaBone;

	/// The class that represents a combination of a character rig and arbitrary float data.
	/// The bone/transform data is designed to represent a skeletal animation rig - bone(transform) names, hierarchy and reference pose.
	/// The float slot data is designed to store arbitrary floating point data.
	///
	/// Either bones or float slots may be empty (but not both). For example:
	///     - A character rig might have only bones.
	///     - A character rig with auxiliary animated data might have both bones and float slots.
	///     - A morph target 'rig' might have only float slots.
	///
	/// Note that size of m_bones.getSize()==m_parentIndices.getSize()==m_referencePose.getSize().
	class hkaSkeleton : public hkReferencedObject
	{
	public:
		// members
		hkStringPtr            name;             // 10 - A user name to aid in identifying the skeleton
		hkArray<int16_t>       parentIndices;    // 18 - Parent relationship
		hkArray<hkaBone>       bones;            // 28 - Bones for this skeleton
		hkArray<hkQsTransform> referencePose;    // 38 - The reference pose for the bones of this skeleton. This pose is stored in local space.
		hkArray<float>         referenceFloats;  // 48 - The reference values for the float slots of this skeleton. This pose is stored in local space.
		// 58 - Floating point track slots. Often used for auxiliary float data or morph target parameters etc.
		// This defines the target when binding animations to a particular rig.
		hkArray<hkStringPtr>      floatSlots;
		hkArray<LocalFrameOnBone> localFrames;  // 68 - A set of partitions of the skeleton
	};
	static_assert(sizeof(hkaSkeleton) == 0x78);
}
