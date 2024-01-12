#pragma once

namespace RE
{
	class CombatTargetLocationAngle
	{
	public:
		CombatTargetLocationAngle() = default;
		CombatTargetLocationAngle(float angle, float width);

		bool CheckAngle(float angle, float width_mult = 1.0f) const;

		// members
		float angle;  // 00
		float width;  // 04
		float start;  // 08
		float end;    // 0C
	};
	static_assert(sizeof(CombatTargetLocationAngle) == 0x10);
}
