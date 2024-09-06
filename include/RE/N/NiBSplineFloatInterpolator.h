#pragma once

#include "RE/N/NiBSplineInterpolator.h"

namespace RE
{
	class NiBSplineFloatInterpolator : public NiBSplineInterpolator
	{
	public:
		~NiBSplineFloatInterpolator() override = default;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                          // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning);          // 17
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		bool          IsEqual(NiObject* a_object) override;              // 1C

		// override (NiBSplineInterpolator)
		virtual uint16_t GetChannelCount() const;                           // 39
		virtual uint32_t GetDimension(uint16_t channel) const;              // 3B
		virtual uint32_t GetDegree(uint16_t channel) const;                 // 3C
		virtual bool     GetChannelPosed() const;                           // 3D
		virtual uint32_t GetControlHandle(uint16_t channel) const;          // 40
		virtual void     SetControlHandle(uint32_t val, uint16_t channel);  // 41

		// members
		float    val;            // 30
		uint32_t controlHandle;  // 34
	};
	static_assert(sizeof(NiBSplineFloatInterpolator) == 0x38);
}
