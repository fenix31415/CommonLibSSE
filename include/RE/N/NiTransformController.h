#pragma once

#include "RE/N/NiSingleInterpController.h"

namespace RE
{
	class NiTransformController : public NiSingleInterpController
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiTransformController;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiTransformController;

		NiTransformController() = default;
		~NiTransformController() override = default;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C

		// override (NiTimeController)
		void Update(NiUpdateData& updateData) override;
		bool IsTransformController() const override;

		// override (NiInterpController)
		NiInterpolator*      CreatePoseInterpolator(uint16_t a_index) override;                                                                                                                                             // 37
		void                 SynchronizePoseInterpolator(NiInterpolator* a_interp, uint16_t a_index = 0) override;                                                                                                          // 38
		NiBlendInterpolator* CreateBlendInterpolator(uint16_t a_index = 0, bool a_managerControlled = false, bool a_accumulateAnimations = false, float a_weightThreshold = 0.0f, uint8_t a_arraySize = 2) const override;  // 39                                                                                                                                        // 3A
		bool                 InterpolatorIsCorrectType(NiInterpolator* a_interpolator, uint16_t a_index) const override;                                                                                                    // 3B

		// override (NiSingleInterpController)
		bool InterpTargetIsCorrectType(NiObjectNET* target) const override;

		static NiTransformController* CreateObject();
	};
	static_assert(sizeof(NiTransformController) == 0x50);
}
