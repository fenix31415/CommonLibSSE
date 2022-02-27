#pragma once

#include "RE/C/CombatInventoryItem.h"
#include "RE/C/CombatObject.h"

namespace RE
{
	class CombatController;
	class CombatProjectileAimController;
	class MagicItem;

	class CombatMagicCaster : public CombatObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatMagicCaster;

		~CombatMagicCaster() override;  // 00

		// override (CombatObject)
		void SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04

		// add
		virtual CombatInventoryItem::CATEGORY GetCategory() = 0;                                                   // 05
		virtual bool                          CheckStartCast(CombatController* a_combatController);                // 06
		virtual bool                          CheckStopCast(CombatController* a_combatController);                 // 07
		virtual float                         CalcCastMagicChance(CombatController* a_combatController) const;     // 08
		virtual float                         CalcMagicHoldTime(CombatController* a_combatController) const;       // 09
		virtual void*                         GetMagicTarget(CombatController* a_combatController) const;          // 0A
		virtual void                          NotifyStartCast(CombatController* a_combatController);               // 0B
		virtual void                          NotifyStopCast(CombatController* a_combatController);                // 0C
		virtual void                          SetupAimController(CombatProjectileAimController* a_aimController);  // 0D

		// members
		CombatInventoryItemMagic* inventoryItem;  // 10
		MagicItem*                magicItem;      // 18
	};
	static_assert(sizeof(CombatMagicCaster) == 0x20);
}
