#pragma once

#include "RE/N/NiPoint3.h"

namespace RE
{
	class Actor;
	class IMessageBoxCallback;
	template <class T>
	class NiPointer;
	class Setting;
	class TESObjectREFR;
	class TESForm;
	class InventoryEntryData;

	//template <std::same_as<const char*>... T>
	template <typename... T>
	void CreateMessage(const char* a_message, void (*a_callback)(uint8_t), std::uint32_t a_arg3, std::uint32_t a_arg4, std::uint32_t a_arg5, T... argz)
	{
		//Args seems to be a va_list of strings ended with a null string (I think?),
		// arg3 seems to be the value of the first index,
		// callback is actually a void function that takes an int as a parameter
		// arg 4 and arg 5 are still unknown

		using func_t = decltype(&CreateMessage<T...>);
		REL::Relocation<func_t> func{ RELOCATION_ID(51420, 52269) };
		return func(a_message, a_callback, a_arg3, a_arg4, a_arg5, argz...);
	}
	void          CreateRefHandle(RefHandle& a_handleOut, TESObjectREFR* a_refTo);
	void          DebugNotification(const char* a_notification, const char* a_soundToPlay = 0, bool a_cancelIfAlreadyQueued = true);
	void          DebugMessageBox(const char* a_message);
	float         GetArmorFinalRating(InventoryEntryData* a_armorEntryData, float a_armorPerks, float a_skillMultiplier);
	std::uint32_t GetDurationOfApplicationRunTime();
	Setting*      GetINISetting(const char* a_name);
	float         GetSecondsSinceLastFrame();
	bool          LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut);
	bool          LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut);
	void          PlaySound(const char* a_editorID);
	bool          RandomBoolChance(float chance);
	void          ShakeCamera(float a_strength, const NiPoint3& a_position, float a_duration);
}
