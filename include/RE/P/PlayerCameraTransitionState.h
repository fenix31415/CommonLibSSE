#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/N/NiPoint2.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiQuaternion.h"
#include "RE/P/PlayerInputHandler.h"
#include "RE/T/TESCameraState.h"

namespace RE
{
	class NiNode;

	class PlayerCameraTransitionState : public TESCameraState
	{
	public:
		inline static constexpr auto RTTI = RTTI_PlayerCameraTransitionState;
		inline static constexpr auto VTABLE = VTABLE_PlayerCameraTransitionState;

		virtual ~PlayerCameraTransitionState();  // 00

		// override (TESCameraState)
		virtual void Begin() override;                                               // 01
		virtual void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;  // 03
		virtual void GetRotation(NiQuaternion& a_rotation) override;                 // 04
		virtual void GetTranslation(NiPoint3& a_translation) override;               // 05

		// members
		std::uint64_t                       unk20;               // 20
		RE::BSTSmartPointer<TESCameraState> transitionFrom;      // 28
		RE::BSTSmartPointer<TESCameraState> transitionTo;        // 30
		std::uint32_t                       interpolation_type;  // 38
		bool                                update_from_state;   // 3C
		bool                                update_to_state;     // 3D
	};
	static_assert(sizeof(PlayerCameraTransitionState) == 0x40);
}
