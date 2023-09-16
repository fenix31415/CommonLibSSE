#pragma once

namespace RE
{
	class CombatAcquireItem
	{
	public:
		//members
		RefHandle mb_targetHandle;  // 00
		uint32_t  field_4;          // 04
		uint64_t  field_8;          // 08
		uint32_t  field_10;         // 10
		uint32_t  field_14;         // 14
	};
	static_assert(sizeof(CombatAcquireItem) == 0x18);
}
