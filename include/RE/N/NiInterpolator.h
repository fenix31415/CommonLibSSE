#pragma once

#include "RE/N/NiObject.h"

namespace RE
{
	class NiAVObjectPalette;
	class NiBoolInterpolator;
	class NiColorA;
	class NiObjectNET;
	class NiPoint3;
	class NiQuaternion;
	class NiQuatTransform;

	class NiInterpolator : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiInterpolator;

		static constexpr inline uint8_t INVALID_BOOL = 2;

		NiInterpolator();
		~NiInterpolator() override = default;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		bool          IsEqual(NiObject* a_object) override;              // 1C

		// add
		virtual bool                Update1(float a_time, NiObjectNET* a_interpTarget, NiQuatTransform& a_value);  // 25
		virtual bool                Update2(float a_time, NiObjectNET* a_interpTarget, NiColorA& a_value);         // 26
		virtual bool                Update3(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value);         // 27
		virtual bool                Update4(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value);     // 28
		virtual bool                Update5(float a_time, NiObjectNET* a_interpTarget, float& a_value);            // 29
		virtual bool                Update6(float a_time, NiObjectNET* a_interpTarget, bool& a_value);             // 2A
		[[nodiscard]] virtual bool  IsBoolValueSupported() const;                                                  // 2B
		[[nodiscard]] virtual bool  IsFloatValueSupported() const;                                                 // 2C
		[[nodiscard]] virtual bool  IsQuaternionValueSupported() const;                                            // 2D
		[[nodiscard]] virtual bool  IsPoint3ValueSupported() const;                                                // 2E
		[[nodiscard]] virtual bool  IsColorAValueSupported() const;                                                // 2F
		[[nodiscard]] virtual bool  IsTransformValueSupported() const;                                             // 30
		virtual void                Collapse();                                                                    // 31
		virtual void                GetActiveTimeRange(float& a_beginKeyTime, float& a_endKeyTime) const;          // 32
		virtual void                GuaranteeTimeRange(float a_startTime, float a_endTime);                        // 33
		virtual NiInterpolator*     GetSequenceInterpolator(float a_startTime, float a_endTime);                   // 34
		virtual bool                ResolveDependencies(NiAVObjectPalette* a_palette);                             // 35
		virtual bool                SetUpDependencies();                                                           // 36
		[[nodiscard]] virtual bool  AlwaysUpdate() const;                                                          // 37
		virtual NiBoolInterpolator* AsNiBoolInterpolator();                                                        // 38

		void CopyMembers(NiInterpolator* dst, NiCloningProcess& proc);
		bool Update(float a_time, NiObjectNET* a_interpTarget, NiQuatTransform& a_value);
		bool Update(float a_time, NiObjectNET* a_interpTarget, NiColorA& a_value);
		bool Update(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value);
		bool Update(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value);
		bool Update(float a_time, NiObjectNET* a_interpTarget, float& a_value);
		bool Update(float a_time, NiObjectNET* a_interpTarget, bool& a_value);

		// members
		float         lastTime;  // 10
		std::uint32_t pad14;     // 14
	};
	static_assert(sizeof(NiInterpolator) == 0x18);
}
