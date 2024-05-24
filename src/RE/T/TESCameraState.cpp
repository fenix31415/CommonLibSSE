#include "RE/T/TESCameraState.h"

#include "RE/N/NiQuaternion.h"

namespace RE
{
	void RE::TESCameraState::GetRotation(NiQuaternion& a_rotation)
	{
		a_rotation = { 1, 0, 0, 0 };
	}
}
