#pragma once

#include "RE/C/CombatBehaviorContextAcquireWeapon.h"
#include "RE/C/CombatBehaviorTreeNode.h"

namespace RE
{
	template <typename Expr>
	class CombatBehaviorTreeConditionalNodeBase : public CombatBehaviorTreeNode
	{
	public:
		~CombatBehaviorTreeConditionalNodeBase() = default;

		template <typename T>
		CombatBehaviorTreeConditionalNodeBase(T&& expr, bool isSelector) :
			expr(std::forward<T>(expr)), isSelector(isSelector)
		{}

		void Enter(CombatBehaviorThread* thread) override
		{
			if (this->expr) {
				thread->Descend();
			} else {
				if (this->isSelector)
					thread->fail_state = CombatBehaviorThread::FailState::kFailed;
				thread->Ascend();
			}
		}

		bool Validate(CombatBehaviorTreeNode* node) const override
		{
			return CombatBehaviorBranch::Validate(node);
		}

		const BSFixedString& GetType() const override
		{
			static BSFixedString ans("CombatBehaviorTreeConditionalNode");
			return ans;
		}

		// members
		Expr expr;
		bool isSelector;
	};

	template <typename Expr>
	class CombatBehaviorTreeConditionalNode : public CombatBehaviorTreeConditionalNodeBase<Expr>
	{
	public:
		using CombatBehaviorTreeConditionalNodeBase<Expr>::CombatBehaviorTreeConditionalNodeBase;
	};

	// Specs for nodes with Create

#define DECLARE_SPECIALIZATION(Expr, size, SE_ID, AE_ID)                                               \
	template <>                                                                                        \
	class CombatBehaviorTreeConditionalNode<Expr> : public CombatBehaviorTreeConditionalNodeBase<Expr> \
	{                                                                                                  \
	public:                                                                                            \
		CombatBehaviorTreeConditionalNode() = delete;                                                  \
                                                                                                       \
		static CombatBehaviorTreeNode* Create()                                                        \
		{                                                                                              \
			REL::Relocation<CombatBehaviorTreeNode*()> func{ RELOCATION_ID((SE_ID), (AE_ID)) };        \
			return func();                                                                             \
		}                                                                                              \
	};                                                                                                 \
	static_assert(sizeof(CombatBehaviorTreeConditionalNode<Expr>) == (size))

	//DECLARE_SPECIALIZATION(CombatBehaviorContextAcquireWeapon, 46373, 0);  // I do not know for AE

#undef DECLARE_SPECIALIZATION
}
