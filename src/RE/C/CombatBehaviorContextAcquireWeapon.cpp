#include "RE/C/CombatBehaviorContextAcquireWeapon.h"

namespace RE
{
	const CombatAcquireItem& CombatBehaviorContextAcquireWeapon::getAcquireAmmo() const
	{
		return ammo;
	}

	const CombatAcquireItem& CombatBehaviorContextAcquireWeapon::getAcquireWeapon() const
	{
		return weapon;
	}
}
