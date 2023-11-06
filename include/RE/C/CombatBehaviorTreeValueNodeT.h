#pragma once

#include "RE/C/CombatBehaviorContextMagic.h"
#include "RE/C/CombatBehaviorTreeValueNode.h"

namespace RE
{
	template<typename T, typename Expr>
	class CombatBehaviorTreeValueNodeTBase : public CombatBehaviorTreeValueNode<T>
	{
	public:
		CombatBehaviorTreeValueNodeTBase(Expr expr) :
			expr(std::move(expr)) {}

		// members
		Expr expr;  // 30
	};

	template <typename T, typename Expr, uint64_t SE, uint64_t AE>
	class CombatBehaviorTreeValueNodeTInlined : public CombatBehaviorTreeValueNodeTBase<T, Expr>
	{
	public:
		T GetValue() override { return T(); }

		CombatBehaviorTreeValueNodeTInlined(Expr expr) :
			CombatBehaviorTreeValueNodeTBase<T, Expr>(std::forward<Expr>(expr))
		{
			this->SetVftable(RELOCATION_ID(SE, AE));
		}
	};

	template <typename T, typename Expr>
	class CombatBehaviorTreeValueNodeT : public CombatBehaviorTreeValueNodeTBase<T, Expr>
	{
	public:
		T GetValue() override
		{
			if constexpr (std::is_invocable_v<Expr>)
				return this->expr();
			else
				return this->expr;
		}

		using CombatBehaviorTreeValueNodeTBase<T, Expr>::CombatBehaviorTreeValueNodeTBase;
	};

#define DECLARE_SPECIALIZATION(T, E, SE, AE, size)                                                      \
	template <>                                                                                         \
	class CombatBehaviorTreeValueNodeT<T, E> : public CombatBehaviorTreeValueNodeTInlined<T, E, SE, AE> \
	{                                                                                                   \
	public:                                                                                             \
		using CombatBehaviorTreeValueNodeTInlined<T, E, SE, AE>::CombatBehaviorTreeValueNodeTInlined;   \
	};                                                                                                  \
	static_assert(sizeof(CombatBehaviorTreeValueNodeT<T, E>) == size)

	DECLARE_SPECIALIZATION(uint32_t, MagicSystem::CastingType, VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_MagicSystem__CastingType_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x38);                                                                                                                                                  // I do not know for AE
	DECLARE_SPECIALIZATION(uint32_t, decltype(&CombatBehaviorContextMagic::GetCastingType), VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorContextMagic_MagicSystem__CastingType_CombatBehaviorContextMagic____void____[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x38);  // I do not know for AE
	DECLARE_SPECIALIZATION(uint32_t, int, VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_int_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x38);                                                                                                                                                                                            // I do not know for AE

	// TODO rest

#undef DECLARE_SPECIALIZATION
}
