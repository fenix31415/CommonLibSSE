#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/P/PlayerCamera.h"

namespace RE
{
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;
	class NiPoint3;
	class NiQuaternion;
	class TESCamera;

	class TESCameraState : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESCameraState;
		inline static constexpr auto VTABLE = VTABLE_TESCameraState;

		TESCameraState(TESCamera* a_camera, CameraState a_id) :
			camera(a_camera), id(a_id)
		{
		}

		virtual ~TESCameraState() = default;  // 00

		// add
		virtual void Begin(){};                                                                        // 01
		virtual void End(){};                                                                          // 02
		virtual void Update(BSTSmartPointer<TESCameraState>& a_nextState) { a_nextState = nullptr; };  // 03
		virtual void GetRotation(NiQuaternion& a_rotation);                                            // 04
		virtual void GetTranslation(NiPoint3& a_translation) { a_translation = {}; };                  // 05
		virtual void SaveGame(BGSSaveFormBuffer*){};                                                   // 06
		virtual void LoadGame(BGSLoadFormBuffer*){};                                                   // 07
		virtual void Revert(BGSLoadFormBuffer*){};                                                     // 08

		// members
		std::uint32_t pad0C;   // 0C
		TESCamera*    camera;  // 10
		CameraState   id;      // 18
		std::uint32_t pad1C;   // 1C
	};
	static_assert(sizeof(TESCameraState) == 0x20);
}
