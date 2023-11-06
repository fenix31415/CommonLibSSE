#pragma once

#include "RE/M/MagicSystem.h"

namespace RE
{
	class ActorMagicCaster;
	class CombatInventoryItemMagic;
	class CombatMagicCaster;
	class CombatProjectileAimController;
	class MagicItem;

	class CombatBehaviorContextMagic
	{
	public:
		CombatBehaviorContextMagic(CombatInventoryItemMagic* citem);

		MagicSystem::CastingType GetCastingType();

		// members
		ActorMagicCaster*              magicCaster;     // 00
		MagicItem*                     mitem;           //		08
		CombatMagicCaster*             combatMcaster;   // 10
		CombatProjectileAimController* projAimControl;  // 18
	};
	static_assert(sizeof(CombatBehaviorContextMagic) == 0x20);
}
