#include "RE/H/hkpWorldObject.h"

#include "RE/T/TESHavokUtilities.h"

namespace RE
{
	const hkpCollidable* hkpWorldObject::GetCollidable() const
	{
		return &collidable;
	}

	hkpCollidable* hkpWorldObject::GetCollidableRW()
	{
		return &collidable;
	}

	hkpPropertyValue hkpWorldObject::GetProperty(uint32_t key) const
	{
		if (key == 0)
			key = 1;

		for (const auto& prop : properties) {
			if (prop.key == key)
				return prop.value;
		}

		return hkpPropertyValue{ 0 };
	}

	const hkpShape* hkpWorldObject::GetShape() const
	{
		const auto hkpCollidable = GetCollidable();
		return hkpCollidable ? hkpCollidable->GetShape() : nullptr;
	}

	TESObjectREFR* hkpWorldObject::GetUserData() const
	{
		const auto hkpCollidable = GetCollidable();
		return hkpCollidable ? TESHavokUtilities::FindCollidableRef(*hkpCollidable) : nullptr;
	}
}
