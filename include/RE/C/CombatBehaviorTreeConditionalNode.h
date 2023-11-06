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
		CombatBehaviorTreeConditionalNodeBase(Expr expr, bool fail) :
			expr(std::move(expr)), fail(fail) {}

		// members
		Expr expr;
		bool fail;
	};

	template <typename Expr, uint64_t SE, uint64_t AE>
	class CombatBehaviorTreeConditionalNodeWithCtor : public CombatBehaviorTreeConditionalNodeBase<Expr>
	{
	public:
		CombatBehaviorTreeConditionalNodeWithCtor() = delete;

		static CombatBehaviorTreeNode* Create(const Expr& a_expr, bool a_fail)
		{
			REL::Relocation<CombatBehaviorTreeNode*(const Expr&, bool)> func{ RELOCATION_ID(SE, AE) };
			return func(a_expr, a_fail);
		}
	};

	template <typename Expr>
	class CombatBehaviorTreeConditionalNode : public CombatBehaviorTreeConditionalNodeBase<Expr>
	{
	public:
		~CombatBehaviorTreeConditionalNode() = default;
		using CombatBehaviorTreeConditionalNodeBase<Expr>::CombatBehaviorTreeConditionalNodeBase;

		void Enter(CombatBehaviorThread* thread) override
		{
			if (this->expr()) {
				thread->Descend();
			} else {
				if (this->fail)
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
	};

#define DECLARE_SPECIALIZATION(T, SE, AE, size)                                                                \
	template <>                                                                                                \
	class CombatBehaviorTreeConditionalNode<T> : public CombatBehaviorTreeConditionalNodeWithCtor<T, SE, AE>   \
	{                                                                                                          \
	public:                                                                                                    \
		using CombatBehaviorTreeConditionalNodeWithCtor<T, SE, AE>::CombatBehaviorTreeConditionalNodeWithCtor; \
	};                                                                                                         \
	static_assert(sizeof(CombatBehaviorTreeConditionalNode<T>) == size)
	
	// TODO rest

	DECLARE_SPECIALIZATION(decltype(&CombatBehaviorEquipContext::CanEquipItem), 46372, 0, 0x38);  // I do not know for AE

#undef DECLARE_SPECIALIZATION
}
