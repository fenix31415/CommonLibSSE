#pragma once

#include "RE/H/hkQsTransform.h"
#include "RE/H/hkaDefaultAnimationControl.h"
#include "RE/H/hkbContext.h"
#include "RE/H/hkbEventBase.h"
#include "RE/H/hkbGenerator.h"

namespace RE
{
	class hkbEventProperty : public hkbEventBase
	{
	};

	class hkClipTrigger
	{
	public:
		float            localTime;            // 00
		hkbEventProperty event;                // 08
		bool             relativeToEndOfClip;  // 18
		bool             acyclic;              // 19
		bool             isAnnotation;         // 1A
	};
	static_assert(sizeof(hkClipTrigger) == 0x20);

	class hkbClipTriggerArray : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbClipTriggerArray;
		inline static constexpr auto VTABLE = VTABLE_hkbClipTriggerArray;

		~hkbClipTriggerArray() override;  // 00

		// members
		hkArray<hkClipTrigger> triggers;  // 10
	};
	static_assert(sizeof(hkbClipTriggerArray) == 0x20);

	class hkbClipGenerator : public hkbGenerator
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbClipGenerator;
		inline static constexpr auto VTABLE = VTABLE_hkbClipGenerator;

		// Playback modes determine how time advances for the clip.
		enum class PlaybackMode : uint8_t
		{
			// Play the clip once from start to finish.
			kModeSinglePlay = 0,
			// Play the clip over and over in a loop.
			kModeLooping = 1,
			// Don't advance the clip.  Let the user control the local time.
			kModeUserControlled = 2,
			// At the end of the animation, turn around backward, and then turn around again at the beginning, etc.
			kModePingPong = 3,
			// How many modes there are.
			kModeCount = 4
		};

		~hkbClipGenerator() override;  // 00

		// override (hkbNode)
		void Activate(const hkbContext& a_context) override;                  // 04
		void Update(const hkbContext& a_context, float a_timestep) override;  // 05
		void Deactivate(const hkbContext& a_context) override;                // 07

		// override (hkbGenerator)
		void Generate(const hkbContext& a_context) override;    // 17
		void UpdateSync(const hkbContext& a_context) override;  // 19

		// Add a trigger to the clip.
		void addTrigger(float atLocalTime, const hkbEventBase& event, bool relativeToEndOfClip = false, bool acyclic = false, bool isAnnotation = false)
		{
			REL::Relocation<decltype(&hkbClipGenerator::addTrigger)> func(RELOCATION_ID(58614, 0));  // I do not know for AE
			return func(this, atLocalTime, event, relativeToEndOfClip, acyclic, isAnnotation);
		}

		static hkbClipGenerator* Create()
		{
			auto ans = hk_malloc<hkbClipGenerator>();
			std::memset(ans, 0, sizeof(hkbClipGenerator));
			return ctor(ans);
		}

		// members
		hkStringPtr                           animationName;                       // 048 - The name of the animation to play.
		hkRefPtr<hkbClipTriggerArray>         triggers;                            // 050 - Triggers (events that occur at specific times).
		float                                 cropStartAmountLocalTime;            // 058 - The number of seconds (in clip time) to crop the beginning of the clip.
		float                                 cropEndAmountLocalTime;              // 05C - The number of seconds (in clip time) to crop the end of the clip.
		float                                 startTime;                           // 060 - The time at which to start the animation in local time.
		float                                 playbackSpeed;                       // 064 - Playback speed (negative for backward).
		float                                 enforcedDuration;                    // 068 - If m_enforcedDuration is greater than zero, the clip will be scaled to have the enforced duration.
		float                                 userControlledTimeFraction;          // 06C - In user controlled mode, this fraction (between 0 and 1) dictates the time of the animation.
		std::uint16_t                         animationBindingIndex;               // 070 - An index into the character's hkbAnimationBindingSet.
		PlaybackMode                          mode;                                // 072 - The playback mode.
		std::uint8_t                          flags;                               // 073 - Flags for specialized behavior.
		std::uint32_t                         unk74;                               // 074
		hkArray<hkRefVariant>                 animDatas;                           // 078
		hkRefPtr<hkaDefaultAnimationControl>  animationControl;                    // 088
		hkRefPtr<hkbClipTriggerArray>         originalTriggers;                    // 090
		hkaDefaultAnimationControlMapperData* mapperData;                          // 098 - The retargeting skeleton mapper data
		hkaAnimationBinding*                  binding;                             // 0A0 - The animation binding. This is stored for easy access for SPUs
		hkRefVariant                          mirroredAnimation;                   // 0A8
		hkQsTransform                         extractedMotion;                     // 0B0 - The motion extracted in the last update
		hkArray<hkRefVariant>                 echos;                               // 0E0 - The list of active echos
		float                                 localTime;                           // 0F0 - The local time of the clip (excactly as set in the animation control).
		float                                 time;                                // 0F4 - The time lapsed since activate, taking into consideration the playback speed
		float                                 previousUserControlledTimeFraction;  // 0F8 - In user controlled mode, this fraction (between 0 and 1) is the time of the animation in the previous update.
		std::int32_t                          bufferSize;                          // 0FC - The buffer size to use when decompressing animations (use getMaxSizeOfCombinedDataChunks()).
		std::int32_t                          echoBufferSize;                      // 100
		bool                                  atEnd;                               // 104 - This tells us whether we have reached the end of the clip in MODE_SINGLE_PLAY
		bool                                  ignoreStartTime;                     // 105 - The start time to use next time time activate() is called
		bool                                  pingPongBackward;                    // 106 - Whether ping-pong mode is currently going backward
		std::uint8_t                          pad107[9];                           // 107

	private:
		static hkbClipGenerator* ctor(hkbClipGenerator* _this)
		{
			using func_t = decltype(&ctor);
			REL::Relocation<func_t> func{ RELOCATION_ID(58597, 0) };  // I do not know for AE
			return func(_this);
		}
	};
	static_assert(sizeof(hkbClipGenerator) == 0x110);
}
