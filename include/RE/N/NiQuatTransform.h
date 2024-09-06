#pragma once

#include "RE/N/NiPoint3.h"
#include "RE/N/NiQuaternion.h"

namespace RE
{
	class NiQuatTransform
	{
		static constexpr inline float        INVALID_FLOAT = -std::numeric_limits<float>::max();
		static constexpr inline NiPoint3     INVALID_TRANSLATE = { INVALID_FLOAT, INVALID_FLOAT, INVALID_FLOAT };
		static constexpr inline NiQuaternion INVALID_ROTATE = NiQuaternion(INVALID_FLOAT, INVALID_FLOAT, INVALID_FLOAT, INVALID_FLOAT);
		static constexpr inline float        INVALID_SCALE = INVALID_FLOAT;

	public:
		NiQuatTransform() :
			translation(INVALID_TRANSLATE), rotation(INVALID_ROTATE), scale(INVALID_SCALE) {}
		NiQuatTransform(NiPoint3 translation, NiQuaternion rotation, float scale) :
			translation(std::move(translation)), rotation(std::move(rotation)), scale(scale){};

		bool operator==(const NiQuatTransform& a_rhs) const { return translation == a_rhs.translation && rotation == a_rhs.rotation && scale == a_rhs.scale; }
		bool operator!=(const NiQuatTransform& a_rhs) const { return !operator==(a_rhs); }

		bool isInvalidTranslation() const
		{
			return translation.x == INVALID_FLOAT;
		}
		bool isInvalidRotation() const
		{
			return rotation.x == INVALID_FLOAT;
		}
		bool isInvalidScale() const
		{
			return scale == INVALID_FLOAT;
		}
		bool isInvalid() const
		{
			return isInvalidScale() && isInvalidRotation() && isInvalidTranslation();
		}

		// members
		NiPoint3     translation;  // 00
		NiQuaternion rotation;     // 0C
		float        scale;        // 1C
	};
	static_assert(sizeof(NiQuatTransform) == 0x20);
}
