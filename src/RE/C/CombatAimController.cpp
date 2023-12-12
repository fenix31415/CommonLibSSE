#include "RE/C/CombatAimController.h"

#include "RE/C/CombatController.h"

namespace RE
{
	uint32_t CombatAimController::CalculatePriority(PRIORITY priority)
	{
		using func_t = decltype(&CombatAimController::CalculatePriority);
		REL::Relocation<func_t> func{ RELOCATION_ID(43137, 0) };  // I do not know for AE
		return func(this, priority);
	}

	void CombatAimController::ClearAim()
	{
		using func_t = decltype(&CombatAimController::ClearAim);
		REL::Relocation<func_t> func{ RELOCATION_ID(43136, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatAimController::HasTargetLOS() const
	{
		using func_t = decltype(&CombatAimController::HasTargetLOS);
		REL::Relocation<func_t> func{ RELOCATION_ID(43139, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatAimController::Register()
	{
		// Not in AddresLib
		if (combat_control)
			combat_control->AddAimController(this);
	}

	void CombatAimController::SetAim(const NiPoint3& a_P)
	{
		using func_t = decltype(&CombatAimController::SetAim);
		REL::Relocation<func_t> func{ RELOCATION_ID(43135, 0) };  // I do not know for AE
		return func(this, a_P);
	}

	void CombatAimController::Unregister()
	{
		// Not in AddresLib
		if (combat_control)
			combat_control->RemoveAimController(this);
	}
}
