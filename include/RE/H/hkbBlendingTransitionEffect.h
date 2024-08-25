#pragma once

#include "RE/H/hkbTransitionEffect.h"

namespace RE
{
	class hkbBlendingTransitionEffect : public hkbTransitionEffect
	{
	public:
		/// Flags to indicate specialized behavior.
		enum class FlagBits : uint16_t
		{
			/// No flags.
			FLAG_NONE = 0x0,

			/// Just use the worldFromModel of the generator being transitioned to.
			FLAG_IGNORE_FROM_WORLD_FROM_MODEL = 0x1,

			/// Synchronize the cycles of the children.
			FLAG_SYNC = 0x2,

			/// Just use the worldFromModel of the generator being transitioned from.
			FLAG_IGNORE_TO_WORLD_FROM_MODEL = 0x4,

			/// Blend the to and from world from models but ignore the to generator's rotation
			FLAG_IGNORE_TO_WORLD_FROM_MODEL_ROTATION = 0x8,
		};
		using Flags = stl::enumeration<FlagBits, uint16_t>;

		/// Modes regarding how to deal with the end of the "from" generator.
		enum class EndMode : uint8_t
		{
			/// Don't do anything special regarding the end of the "from" generator.
			END_MODE_NONE = 0,

			/// Ignore m_duration, and instead transition until the end of the "from" generator.
			END_MODE_TRANSITION_UNTIL_END_OF_FROM_GENERATOR = 1,

			/// If the transition begins closer than m_duration to the end of the "from" generator,
			/// shorten the transition duration to the time remaining so that the transition does
			/// not play the "from" generator beyond the end.
			END_MODE_CAP_DURATION_AT_END_OF_FROM_GENERATOR = 2,
		};

		static hkbBlendingTransitionEffect* Create(float duration, Flags flags = FlagBits::FLAG_NONE, EndMode endMode = EndMode::END_MODE_NONE);

		// members
		float duration;  // 50
		uint32_t
				 toGeneratorStartTimeFraction;  // 54 - The start time of the to-generator when the transition begins, expressed as a fraction of its duration.
		Flags    flags;                         // 58 - Flags to indicate specialized behavior.
		EndMode  endMode;                       // 5A - The treatment of the end of the from-generator.
		uint8_t  field_5B;                      // 5B
		uint32_t field_5C;                      // 5C
		uint64_t field_60;                      // 60
		uint64_t field_68;                      // 68
		uint64_t field_70;                      // 70
		uint64_t field_78;                      // 78
		uint64_t field_80;                      // 80
		uint16_t field_88;                      // 88
		char     field_8A[6];                   // 8A

	private:
		static hkbBlendingTransitionEffect* ctor(hkbBlendingTransitionEffect* _this, float duration, Flags flags, EndMode endMode);
	};
	static_assert(sizeof(hkbBlendingTransitionEffect) == 0x90);
}
