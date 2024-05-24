#pragma once

namespace RE
{
	class CombatCoverLocation;

	struct CombatCoverSegment
	{
		CombatCoverSegment() = default;
		CombatCoverSegment(float a_start, float a_end);

		float CalculateDistance(float offset) const;
		bool  CheckFree(float width) const;
		bool  CheckOffset(float offset, float width) const;
		bool  CheckOffset(float offset) const;
		bool  CheckOverlap(const CombatCoverSegment& other) const;
		void  SetData(CombatCoverLocation* a_coverLocation, float a_start, float a_end);
		bool  QFree() const;

		// members
		CombatCoverLocation* coverLocation;  // 00
		float                start;          // 08
		float                end;            // 0C
	};
	static_assert(sizeof(CombatCoverSegment) == 0x10);
}
