#include "RE/N/NiQuaternion.h"

namespace RE
{
	NiQuaternion::NiQuaternion(const RE::NiMatrix3& M)
	{
		SetRotation(M);
	}

	NiQuaternion::NiQuaternion(float angle_X, float angle_Y, float angle_Z)
	{
		SetEulerAnglesXYZ(angle_X, angle_Y, angle_Z);
	}

	void NiQuaternion::SetRotation(const RE::NiMatrix3& M)
	{
		float X = M.entry[0][0];
		float Y = M.entry[1][1];
		float Z = M.entry[2][2];
		float Tr = X + Y + Z;

		if (Tr <= 0.0f) {
			// 0 if M[0][0], 1 if M[1][1], 2 if M[2][2]
			uint32_t argmax = Y > X;

			const float* ptr = static_cast<const float*>(&M.entry[0][0]);

			// Z > max(X, Y)
			if (Z > *(ptr + 4 * argmax))
				argmax = 2i64;

			uint32_t ind2 = next[argmax];
			uint32_t ind3 = next[ind2];
			float    S = *(ptr + 4 * argmax) - *(ptr + 4 * ind2) - *(ptr + 4 * ind3);

			float* ans[3] = { &x, &y, &z };
			S = std::sqrt(S + 1.0f);

			*ans[argmax] = S * 0.5f;
			S = 0.5f / S;
			w = (*(ptr + 3 * ind3 + ind2) - *(ptr + 3 * ind2 + ind3)) * S;
			*ans[ind2] =
				(*(ptr + 3 * argmax + ind2) + *(ptr + 3 * ind2 + argmax)) *
				S;
			*ans[ind3] =
				(*(ptr + 3 * argmax + ind3) + *(ptr + 3 * ind3 + argmax)) *
				S;
		} else {
			float S = std::sqrt(Tr + 1.0f);
			w = S * 0.5f;
			S = 0.5f / S;
			x = (M.entry[2][1] - M.entry[1][2]) * S;
			y = (M.entry[0][2] - M.entry[2][0]) * S;
			z = (M.entry[1][0] - M.entry[0][1]) * S;
		}
	}

	void NiQuaternion::SetEulerAnglesXYZ(float X, float Y, float Z)
	{
		float cos_x = std::cos(X * -0.5f);
		float cos_y = std::cos(Y * 0.5f);
		float cos_z = std::cos(Z * -0.5f);
		float sin_x = std::sin(X * -0.5f);
		float sin_y = std::sin(Y * 0.5f);
		float sin_z = std::sin(Z * -0.5f);

		w = sin_z * sin_y * sin_x + cos_z * cos_y * cos_x;
		x = cos_z * cos_y * sin_x - sin_z * sin_y * cos_x;
		y = sin_x * cos_y * sin_z + sin_y * cos_x * cos_z;
		z = cos_y * cos_x * sin_z - sin_y * sin_x * cos_z;
	}
}
