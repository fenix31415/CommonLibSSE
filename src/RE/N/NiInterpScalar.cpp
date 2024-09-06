#include "RE/N/NiInterpScalar.h"

namespace RE
{
	float NiInterpScalar::Linear(float val, float from, float to)
	{
		return ((1.0f - val) * from) + (val * to);
	}

	float NiInterpScalar::Bezier(float val, float from_val, float from_P2, float to_val, float to_P1)
	{
		return (((from_P2 + to_P1 - (to_val - from_val) * 2.0f) * val + (to_val - from_val) * 3.0f - from_P2 * 2.0f + to_P1) * val + from_P2) * val + from_val;
	}

	float NiInterpScalar::TCB(float val, float from_val, float from_P2, float to_val, float to_P1)
	{
		return (((from_P2 + to_P1 - (to_val - from_val) * 2.0f) * val + (to_val - from_val) * 3.0f - from_P2 * 2.0f + to_P1) * val + from_P2) * val + from_val;
	}

	void NiInterpScalar::AdjustBezier(float prev_val, float prev_time, float& ans_prev_P2, float next_val, float next_time, float& ans_next_P1, float time, float /* val */, float& P1, float& P2)
	{
		float k1 = 1.0f / (next_time - prev_time);
		float k2 = k1 * (time - prev_time);

		float P1_val = (((((((ans_prev_P2 - ((next_val - prev_val) * 2.0f)) + ans_next_P1) * 3.0f) * k2) + (((((next_val - prev_val) * 3.0f) - (ans_prev_P2 * 2.0f)) - ans_next_P1) * 2.0f)) * k2) + ans_prev_P2) * k1;
		P1 = P1_val;
		P2 = P1_val * (next_time - time);

		P1 = (time - prev_time) * P1;

		ans_prev_P2 = k2 * ans_prev_P2;
		ans_next_P1 = k1 * (next_time - time) * ans_next_P1;
	}
}
