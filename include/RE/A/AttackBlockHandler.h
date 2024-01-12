#pragma once

#include "RE/H/HeldStateHandler.h"

namespace RE
{
	struct AttackBlockHandler : public HeldStateHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_AttackBlockHandler;

		enum class AttackType : std::uint32_t
		{
			kNone,
			kLeft,
			kRight,
			kDual
		};

		virtual ~AttackBlockHandler();  // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;                                  // 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;  // 04
		virtual void UpdateHeldStateActive(const ButtonEvent* a_event) override;                // 05
		virtual void SetHeldStateActive(bool a_flag) override;                                  // 06

		// members
		uint64_t      dualTimeMs;                  // 18
		BSFixedString ignoreControlId;             // 20
		AttackType    attackType;                  // 28
		std::uint32_t attackCount;                 // 2C
		uintptr_t     initialPowerAttackDelay;     // 30 -- Setting*
		uintptr_t     subsequentPowerAttackDelay;  // 38 -- Setting*
		bool          ignoreUP;                    // 40
		bool          unk41;                       // 41
		bool          heldLeft;                    // 42
		bool          heldRight;                   // 43
		std::uint32_t unk44;                       // 44
	};
	static_assert(sizeof(AttackBlockHandler) == 0x48);
}
