#pragma once

#include "RE/H/hkbEventBase.h"
#include "RE/H/hkbGenerator.h"

namespace RE
{
	class hkbBlenderGenerator;
	class hkbBlendingTransitionEffect;

	class BSCyclicBlendTransitionGenerator : public hkbGenerator
	{
	public:
		// members
		uint64_t                     unk48;                        // 48
		hkbBlenderGenerator*         pBlenderGenerator;            // 50
		hkbEventBase                 EventToFreezeBlendValue;      // 58
		hkbEventBase                 EventToCrossBlend;            // 68
		float                        fBlendParameter;              // 78
		float                        fTransitionDuration;          // 7C
		uint8_t                      field_80;                     // 80
		uint8_t                      pad81[7];                     // 81
		uint64_t                     field_88;                     // 88
		hkbBlenderGenerator*         pTransitionBlenderGenerator;  // 90
		uint64_t                     field_98;                     // 98
		hkbBlendingTransitionEffect* pTransitionEffect;            // A0
		uint8_t                      currentMode;                  // A8
		uint8_t                      pad_A9[7];                    // A9
	};
	static_assert(sizeof(BSCyclicBlendTransitionGenerator) == 0xB0);
}
