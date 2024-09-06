#pragma once

#include "RE/N/NiMatrix3.h"

namespace RE
{
	class NiMatrix3;

	class NiQuaternion
	{
		static constexpr inline std::array<uint32_t, 3> next = { { 1, 2, 0 } };

	public:
		NiQuaternion() = default;
		explicit NiQuaternion(const RE::NiMatrix3& M);
		NiQuaternion(float angle_X, float angle_Y, float angle_Z);
		constexpr NiQuaternion(float w, float x, float y, float z) :
			w(w), x(x), y(y), z(z)
		{
		}

		constexpr bool operator==(const NiQuaternion& a_rhs) const
		{
			return (x == a_rhs.x && y == a_rhs.y && z == a_rhs.z && w == a_rhs.w);
		}

		void Correct(const NiQuaternion& to) {
			if (Dot(to) < 0.0f)
				Neg();
		}
		constexpr float Dot(class NiQuaternion const& Q) const
		{
			return w * Q.w + x * Q.x + y * Q.y + z * Q.z;
		}
		constexpr void Neg()
		{
			w = -w;
			x = -x;
			y = -y;
			z = -z;
		}
		void SetEulerAnglesXYZ(float X, float Y, float Z);
		void SetRotation(const RE::NiMatrix3& M);
		constexpr void ToRotation(RE::NiMatrix3& ans) const
		{
			float _2x = x * 2.0f;
			float _2z = z * 2.0f;
			float _2x2 = x * _2x;
			float _2xw = w * _2x;
			float _2y2 = y * y * 2.0f;
			float _2yw = w * y * 2.0f;
			float _2xy = x * y * 2.0f;
			float _2xz = x * _2z;
			float _2zw = w * _2z;
			float v12 = z * _2z + _2x2;

			ans.entry[0][0] = 1.0f - (z * _2z + _2y2);
			ans.entry[1][0] = _2xy + _2zw;
			ans.entry[0][1] = _2xy - _2zw;
			ans.entry[2][0] = _2xz - _2yw;
			ans.entry[0][2] = _2xz + _2yw;
			ans.entry[1][2] = (y * _2z) - _2xw;
			ans.entry[1][1] = 1.0f - v12;
			ans.entry[2][1] = (y * _2z) + _2xw;
			ans.entry[2][2] = 1.0f - (_2y2 + _2x2);
		}
		constexpr RE::NiMatrix3 ToRotation() const
		{
			RE::NiMatrix3 ans;
			ToRotation(ans);
			return ans;
		}

		// members
		float w;  // 00
		float x;  // 04
		float y;  // 08
		float z;  // 0C
	};
	static_assert(sizeof(NiQuaternion) == 0x10);
}
