#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/C/CombatObject.h"

namespace RE
{
	class CombatController;

	class CombatTargetSelector : public CombatObject
	{
	public:
		enum class PRIORITY : uint32_t
		{
			kPRIORITY_0,
			kPRIORITY_1,
			kPRIORITY_2,
			kPRIORITY_3
		};

		enum class Flag : uint32_t
		{
			kActive = 1 << 1,
			kTargetInvalid = 1 << 2
		};
		using FLAGS = stl::enumeration<Flag, uint32_t>;

		~CombatTargetSelector();

		// override (CombatObject)
		std::uint32_t GetObjectType() override;                     // 02
		void          SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void          LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04

		// add
		virtual void        Update();            // 05
		virtual ActorHandle SelectTarget() = 0;  // 06

		// members
		CombatController* combat_control;  // 10
		ActorHandle       target;          // 18
		PRIORITY          priority;        // 1C
		FLAGS             flags;           // 20
		uint8_t           pad24[4];        // 24
	};
	static_assert(sizeof(CombatTargetSelector) == 0x28);
}
