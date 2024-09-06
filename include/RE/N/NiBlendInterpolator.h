#pragma once

#include "RE/N/NiInterpolator.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiBlendInterpolator : public NiInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiBlendInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiBlendInterpolator;

		class InterpInfo
		{
		public:
			NiPointer<NiInterpolator> interpolator;  // 00
			float                     field_8;       // 08
			float                     weight;        // 0C
			uint8_t                   priority;      // 10
			char                      pad11[3];      // 11
			float                     field_14;      // 14
			float                     field_18;      // 18
			char                      unk1C[4];      // 1C
		};
		static_assert(sizeof(InterpInfo) == 0x20);

		enum class Flag : uint8_t
		{
			ManagerControlled,
			OnlyUseHighestWeight,
			ComputeNormalizedWeights
		};
		using Flags = stl::enumeration<Flag, uint8_t>;

		~NiBlendInterpolator() override;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                            // 02
		void          LoadBinary(NiStream& a_stream) override;             // 18
		void          LinkObject(NiStream& a_stream) override;             // 19
		bool          RegisterStreamables(NiStream& a_stream) override;    // 1A
		void          SaveBinary(NiStream& a_stream) override;             // 1B
		bool          IsEqual(NiObject* a_object) override;                // 1C
		void          ProcessClone(NiCloningProcess& a_cloning) override;  // 1D

		// override (NiInterpolator)
		void Collapse() override;                                              // 31
		void GuaranteeTimeRange(float a_startTime, float a_endTime) override;  // 33

		// add
		virtual uint8_t AddInterpInfo(NiInterpolator* interp, float a3, char a4, float a5);  // 39
		virtual void    RemoveInterpInfo(uint8_t ind);                                       // 3A
		virtual bool    InterpolatorIsCorrectType(NiInterpolator* interp) = 0;               // 3B
		virtual bool    ReallocateArrays();                                                  // 3C

		// members
		Flags           flags;                       // 18
		uint8_t         arraySize;                   // 19
		uint8_t         interps_count;               // 1A
		uint8_t         firstadded_interpolatorInd;  // 1B
		uint8_t         highestpriority;             // 1C
		uint8_t         lowestpriority;              // 1D
		char            pad1E[2];                    // 1E
		InterpInfo*     interp_array_data;           // 20
		NiInterpolator* firstadded_interp;           // 28
		float           weightThreshold;             // 30
		float           some_time;                   // 34
		float           field_38;                    // 38
		float           field_3C;                    // 3C
		float           field_40;                    // 40
		char            unk44[4];                    // 44
	};
	static_assert(sizeof(NiBlendInterpolator) == 0x48);
}
