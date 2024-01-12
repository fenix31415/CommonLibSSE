#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/C/CombatObject.h"
#include "RE/C/CombatTargetLocationAngle.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class CombatTargetLocation : public CombatObject
	{
	public:
		~CombatTargetLocation() override;  // 00

		// override (CombatObject)
		std::uint32_t GetObjectType() override;                     // 02
		void          SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void          LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04

		bool CheckAngle(const NiPoint3& target_pos, const NiPoint3& actor_pos, float width_mult) const;
		bool CheckPoint(const NiPoint3& target_pos, const NiPoint3& actor_pos, float width_mult) const;

		// members
		ActorHandle               owner;           // 10
		FormID                    targetID;        // 14
		CombatTargetLocationAngle angle;           // 18
		NiPoint3                  locationOffset;  // 28
		uint32_t                  pad34;           // 34
	};
	static_assert(sizeof(CombatTargetLocation) == 0x38);
}
