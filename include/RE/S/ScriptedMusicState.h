#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSMusicType;

	namespace TESAudio
	{
		class ScriptedMusicState
		{
		public:
			virtual ~ScriptedMusicState();

			static ScriptedMusicState* GetSingleton();

			void Add(BGSMusicType* playlist);
			void Remove(BGSMusicType* playlist);

			// members
			uint64_t                        unk08;      // 08
			BSTSmallArray<BGSMusicType*, 2> playlists;  // 10
		};
		static_assert(sizeof(ScriptedMusicState) == 0x30);
	}
}
