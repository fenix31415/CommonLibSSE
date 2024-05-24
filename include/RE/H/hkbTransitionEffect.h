#pragma once

#include "RE/H/hkbGenerator.h"

namespace RE
{
	class hkbTransitionEffect : public RE::hkbGenerator
	{
	public:
		/// These modes determine the behavior when the to-generator is already active when the transition begins.
		enum SelfTransitionMode : uint8_t
		{
			/// If the to-generator is cyclic, it will be continued without interruption.  Otherwise, it will be
			/// blended with itself using the echo feature.
			SELF_TRANSITION_MODE_CONTINUE_IF_CYCLIC_BLEND_IF_ACYCLIC,

			/// Continue the to-generator without interruption.
			SELF_TRANSITION_MODE_CONTINUE,

			/// Reset the to-generator to the beginning.
			SELF_TRANSITION_MODE_RESET,

			/// Reset the to-generator to the beginning using the echo feature to blend.
			SELF_TRANSITION_MODE_BLEND,
		};

		enum EventMode : uint8_t
		{
			/// Apply the event mode from m_defaultEventMode.
			EVENT_MODE_DEFAULT,

			/// Don't ignore the events of either the from-generator or the to-generator.
			EVENT_MODE_PROCESS_ALL,

			/// Ignore all events sent by or to the from-generator.
			EVENT_MODE_IGNORE_FROM_GENERATOR,

			/// Ignore all events sent by or to the to-generator.
			EVENT_MODE_IGNORE_TO_GENERATOR,
		};

		// members
		RE::stl::enumeration<SelfTransitionMode, uint8_t>
												 selfTransitionMode;  // 48 - What to do if the to-generator is already active when the transition activates it
		RE::stl::enumeration<EventMode, uint8_t> eventMode;           // 49 - How to process the events of the from- and to-generators.
		uint8_t                                  field_4A;            // 4A - defaultEventMode?
		char                                     pad4B[5];            // 4B
	};
	static_assert(sizeof(hkbTransitionEffect) == 0x50);
}
