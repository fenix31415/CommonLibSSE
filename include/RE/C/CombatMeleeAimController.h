#pragma once

#include "RE/C/CombatTrackTargetAimController.h"

namespace RE
{
	class CombatMeleeAimController : public CombatTrackTargetAimController
	{
	public:
		// override (CombatObject)
		std::uint32_t GetObjectType() override;                     // 02
		void          SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void          LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04

		// override (CombatAimController)
		bool                 CheckAim(const NiPoint3& from, const NiPoint3& to) override;  // 05
		bool                 CheckAim(const NiPoint3& P) override;                         // 06
		void                 Update() override;                                            // 08
		CombatAimController* Clone() const override;                                       // 09

		// members
		float   trackDistanceMin;  // 50
		uint8_t pad54[3];          // 54
	};
	static_assert(sizeof(CombatMeleeAimController) == 0x58);
}
