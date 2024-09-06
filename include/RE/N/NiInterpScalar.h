#pragma once

namespace RE
{
	class NiInterpScalar
	{
	public:
		static float Linear(float val, float from, float to);
		static float Bezier(float val, float from_val, float from_P2, float to_val, float to_P1);
		static float TCB(float val, float from_val, float from_P2, float to_val, float to_P1);
		static void AdjustBezier(float prev_val, float prev_time, float& ans_prev_P2, float next_val, float next_time, float& ans_next_P1, float time, float /* val */, float& P1, float& P2);
	};
}
