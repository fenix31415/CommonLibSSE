#pragma once

#include "RE/T/TLSData.h"
#include "RE/C/CombatBehaviorThread.h"

#pragma warning(push)
#pragma warning(disable: 4324)  // structure was padded due to alignment specifier

namespace RE
{
	template <typename Derived>
	class alignas(4) CombatBehaviorContext
	{
	public:
		static Derived* GetContext()
		{
			const auto& sptr = RE::GetStaticTLSData()->combatAIThread->cur_context_sptr;
			return sptr.stack ? sptr->stack.Access<Derived>(sptr.frame) : nullptr;
		}

		void EnterContext() {}
	};
}

#pragma warning(pop)
