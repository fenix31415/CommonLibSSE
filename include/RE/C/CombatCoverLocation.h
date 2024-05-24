#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/C/CombatCoverEdge.h"
#include "RE/C/CombatObject.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class CombatCoverLocation : public CombatObject
	{
	public:
		~CombatCoverLocation() override;

		// override (CombatObject)
		virtual std::uint32_t GetObjectType() override;
		virtual void          SaveGame(BGSSaveGameBuffer* a_buf) override;
		virtual void          LoadGame(BGSLoadGameBuffer* a_buf) override;

		void UpdateCovers(const NiPoint3& a_cover1, const NiPoint3& a_cover2);

		// members
		CombatCoverEdge edge;            // 10
		ActorHandle     actor;           // 68
		NiPoint3        cover1;          // 6C
		NiPoint3        cover2;          // 78
		NiPoint3        threatLocation;  // 84
		uint32_t        coverKey;        // 90
		uint32_t        flags;           // 94
		float           segmentCenter;   // 98
	};
	static_assert(sizeof(CombatCoverLocation) == 0xA0);
}
