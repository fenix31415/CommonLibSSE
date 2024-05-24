#include "RE/C/CombatCoverSegment.h"

namespace RE
{
	CombatCoverSegment::CombatCoverSegment(float a_start, float a_end) :
		coverLocation(nullptr), start(a_start), end(a_end)
	{}

	float CombatCoverSegment::CalculateDistance(float offset) const
	{
		// not in AddressLibrary
		if (offset > end)
			return offset - end;

		return offset >= start ? 0.0f : start - offset;
	}

	bool CombatCoverSegment::CheckFree(float width) const
	{
		// not in AddressLibrary
		return !coverLocation && (end - start >= width);
	}

	bool CombatCoverSegment::CheckOverlap(const CombatCoverSegment& other) const
	{
		return end >= other.start && start <= other.end;
	}

	bool CombatCoverSegment::CheckOffset(float offset, float width) const
	{
		// not in AddressLibrary
		float radius = width * 0.5f;
		return (offset - radius) >= start && (radius + offset) <= end;
	}

	bool CombatCoverSegment::CheckOffset(float offset) const
	{
		return offset >= start && offset <= end;
	}

	void CombatCoverSegment::SetData(CombatCoverLocation* a_coverLocation, float a_start, float a_end)
	{
		// not in AddressLibrary
		coverLocation = a_coverLocation;
		start = a_start;
		end = a_end;
	}

	bool CombatCoverSegment::QFree() const
	{
		return !coverLocation;
	}
}
