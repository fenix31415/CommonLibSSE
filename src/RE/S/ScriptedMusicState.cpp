#include "RE/S/ScriptedMusicState.h"

namespace RE
{
	namespace TESAudio
	{
		ScriptedMusicState* ScriptedMusicState::GetSingleton()
		{
			return *REL::Relocation<ScriptedMusicState**>(RELOCATION_ID(515125, 0));
		}

		void ScriptedMusicState::Add(BGSMusicType* playlist)
		{
			using func_t = decltype(&ScriptedMusicState::Add);
			REL::Relocation<func_t> func{ RELOCATION_ID(34322, 0) };
			return func(this, playlist);
		}

		void ScriptedMusicState::Remove(BGSMusicType* playlist)
		{
			using func_t = decltype(&ScriptedMusicState::Remove);
			REL::Relocation<func_t> func{ RELOCATION_ID(34323, 0) };
			return func(this, playlist);
		}
	}
}
