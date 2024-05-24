#pragma once

#include "RE/H/hkpShape.h"

namespace RE
{
	class hkpCollidable;

	struct hkpRootCdBodyPair
	{
		hkpCollidable* rootCollidableA;  // 00
		hkpShapeKey    shapeKeyA;        //08
		uint32_t       pad0C;            // 0C
		hkpCollidable* rootCollidableB;  // 10
		hkpShapeKey    shapeKeyB;        //18
		uint32_t       pad1C;            // 1C
	};
	static_assert(sizeof(hkpRootCdBodyPair) == 0x20);
}
