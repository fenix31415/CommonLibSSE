#pragma once

#include "RE/H/hkbGenerator.h"

namespace RE
{
	class hkbClipGenerator;

	class BSSynchronizedClipGenerator : public hkbGenerator
	{
	public:
		// members
		uint64_t          unk48;                         // 048
		hkbClipGenerator* pClipGenerator;                // 050
		const char*       SyncAnimPrefix;                // 058
		bool              bSyncClipIgnoreMarkPlacement;  // 060
		char              pad61[3];                      // 061
		float             fGetToMarkTime;                // 064
		float             fMarkErrorThreshold;           // 068
		uint16_t          field_6C;                      // 06C
		bool              bApplyMotionFromRoot;          // 06E
		uint8_t           pad_6F;                        // 06F
		uint8_t           unk70[0x110 - 0x70];           // 070
		float             fCurrentLerp;                  // 110
		uint32_t          field_114;                     // 114
		uint64_t          field_118;                     // 118
		uint64_t          field_120;                     // 120
		uint16_t          field_128;                     // 128
		uint16_t          field_12A;                     // 12A
		uint8_t           field_12C;                     // 12C
		uint8_t           pad12D[3];                     // 12D
	};
	static_assert(sizeof(BSSynchronizedClipGenerator) == 0x130);

}
