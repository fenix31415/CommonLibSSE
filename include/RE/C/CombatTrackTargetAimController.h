#pragma once

#include "RE/C/CombatAimController.h"

namespace RE
{
	class CombatTrackTargetAimController : public CombatAimController
	{
	public:
		~CombatTrackTargetAimController();

		// override (CombatObject)
		std::uint32_t GetObjectType() override;                     // 02
		void          SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void          LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04

		// override (CombatAimController)
		void                 Update() override;       // 08
		CombatAimController* Clone() const override;  // 09

		static CombatTrackTargetAimController* Create(CombatController* control, PRIORITY priority, float R, bool a5);

		// members
		float   trackDistanceMax;  // 48
		bool    field_4C;          // 4C
		uint8_t pad4D[3];          // 4D
	private:
		CombatTrackTargetAimController* Ctor(CombatController* control, PRIORITY priority, float R, bool a5);
	};
	static_assert(sizeof(CombatTrackTargetAimController) == 0x50);
}
