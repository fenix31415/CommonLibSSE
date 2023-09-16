#pragma once

#include "RE/C/CombatAcquireItem.h"

namespace RE
{
	class CombatBehaviorContextAcquireWeapon
	{
	public:
		const CombatAcquireItem& getAcquireAmmo() const;
		const CombatAcquireItem& getAcquireWeapon() const;

		// members
		CombatAcquireItem weapon;    // 00
		CombatAcquireItem ammo;      // 18
		uint64_t          field_30;  // 30
	};
	static_assert(sizeof(CombatBehaviorContextAcquireWeapon) == 0x38);
}
