#pragma once

#include "NiInterpController.h"

namespace RE
{
	class NiSingleInterpController : public NiInterpController
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiSingleInterpController;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiSingleInterpController;

		NiSingleInterpController() = default;
		~NiSingleInterpController() override = default;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                            // 02
		void          LoadBinary(NiStream& a_stream) override;             // 18
		void          LinkObject(NiStream& a_stream) override;             // 19
		bool          RegisterStreamables(NiStream& a_stream) override;    // 1A
		void          SaveBinary(NiStream& a_stream) override;             // 1B
		bool          IsEqual(NiObject* a_object) override;                // 1C
		void          ProcessClone(NiCloningProcess& a_cloning) override;  // 1D

		// override (NiTimeController)
		bool TargetIsRequiredType() const override;  // 2E

		// override (NiInterpController)
		uint16_t        GetInterpolatorCount() const override;                                           // 2F
		const char*     GetInterpolatorID(uint16_t a_index = 0) override;                                // 30
		uint16_t        GetInterpolatorIndex(const char* a_id) const override;                           // 31
		uint16_t        GetInterpolatorIndexFx(const BSFixedString& a_id) const override;                // 32
		NiInterpolator* GetInterpolator(uint16_t a_index = 0) const override;                            // 33
		void            SetInterpolator(NiInterpolator* a_interpolator, uint16_t a_index = 0) override;  // 34
		void            ResetTimeExtrema() override;                                                     // 35
		void            GuaranteeTimeRange(float a_startTime, float a_endTime) override;                 // 3A

		// add
		virtual bool InterpTargetIsCorrectType(NiObjectNET* target) const = 0;  // 3C

		void CopyMembers(NiSingleInterpController* dst, NiCloningProcess& proc);

		// members
		NiPointer<NiInterpolator> interpolator{ nullptr };  // 48
	};
	static_assert(sizeof(NiSingleInterpController) == 0x50);
}
