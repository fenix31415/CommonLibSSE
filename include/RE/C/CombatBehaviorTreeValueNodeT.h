#pragma once

#include "RE/C/CombatBehaviorContextMagic.h"
#include "RE/C/CombatBehaviorTreeValueNode.h"

namespace RE
{
	template<typename T, typename Expr>
	class CombatBehaviorTreeValueNodeTBase : public CombatBehaviorTreeValueNode<T>
	{
	public:
		template<typename U>
		CombatBehaviorTreeValueNodeTBase(U&& expr) :
			expr(std::forward<U>(expr)) {}

		T GetValue() override
		{
			return static_cast<T>(expr);
		}

		// members
		Expr expr;  // 30
	};

	template <typename T, typename Expr>
	class CombatBehaviorTreeValueNodeT : public CombatBehaviorTreeValueNodeTBase<T, Expr>
	{
	public:
		using CombatBehaviorTreeValueNodeTBase<T, Expr>::CombatBehaviorTreeValueNodeTBase;
	};



}
