#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	struct ShoutHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_ShoutHandler;

		~ShoutHandler() override;  // 00

		// override (PlayerInputHandler)
		bool CanProcess(InputEvent* a_event) override;                                  // 01
		void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;  // 04

		// members
		bool          field_10;       // 10
		bool          still_holding;  // 11
		char          pad12[6];       // 12
		BSFixedString event;          // 18
	};
	static_assert(sizeof(ShoutHandler) == 0x20);
}
