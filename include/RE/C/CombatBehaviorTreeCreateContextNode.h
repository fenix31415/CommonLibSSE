#pragma once

#include "RE/C/CombatBehaviorTreeNode.h"

namespace RE
{
	class CombatBehaviorContextAcquireWeapon;
	class CombatBehaviorContextCloseMovement;
	class CombatBehaviorContextCover;
	class CombatBehaviorContextDodgeThreat;
	class CombatBehaviorContextFindAttackLocation;
	class CombatBehaviorContextFlankingMovement;
	class CombatBehaviorContextFlee;
	class CombatBehaviorContextHide;
	class CombatBehaviorContextRangedMovement;
	class CombatBehaviorContextSearch;

	class CombatBehaviorContextMagic;
	class CombatBehaviorContextRanged;
	class CombatBehaviorContextShout;
	class CombatBehaviorContextUsePotion;
	class CombatBehaviorEquipContext;

	template <typename Context>
	class CombatBehaviorTreeCreateContextNodeImplBase : public CombatBehaviorTreeNode
	{
	public:
		CombatBehaviorTreeCreateContextNodeImplBase() = default;
		~CombatBehaviorTreeCreateContextNodeImplBase() = default;

		void Exit(CombatBehaviorThread* thread) override
		{
			auto old_context_sptr = thread->GetCurrentStackObject<CombatBehaviorStack::ObjectPtr>();
			thread->stack.Deallocate<CombatBehaviorStack::ObjectPtr>();
			thread->GetCurrentStackObject<Context>().Exit();
			thread->stack.Deallocate<Context>();
			thread->cur_context_sptr = old_context_sptr;
		}

		void SaveGame(CombatBehaviorThread*, BGSSaveFormBuffer*) override
		{
			// TODO
		}

		void LoadGame(CombatBehaviorThread*, BGSLoadFormBuffer*) override
		{
			// TODO
		}

		bool Validate(CombatBehaviorTreeNode* node) const override
		{
			return Context::Validate(node);
		}

		const BSFixedString& GetType() const override
		{
			static BSFixedString ans("CombatBehaviorTreeNodeObject");
			return ans;
		}

		void EnterContext(CombatBehaviorThread* thread, CombatBehaviorStack::ObjectPtr new_context_sptr)
		{
			thread->stack.StoreData(thread->cur_context_sptr);
			thread->cur_context_sptr = new_context_sptr;
			auto active_node = thread->active_node;
			thread->GetCurrentContext<Context>()->Enter();
			if (active_node == thread->active_node)
				thread->Descend();
		}
	};

	template <typename Context, typename... Fields>
	class CombatBehaviorTreeCreateContextNodeImpl : public CombatBehaviorTreeCreateContextNodeImplBase<Context>
	{
	public:
		template <typename... Params>
		CombatBehaviorTreeCreateContextNodeImpl(Params&&... params) :
			fields(std::make_tuple(std::forward<Params>(params)...))
		{}
		~CombatBehaviorTreeCreateContextNodeImpl() = default;

		void Enter(CombatBehaviorThread* a_thread) override
		{
			//EnterContext(a_thread, a_thread->stack.Allocate<Context>());
			this->EnterContext(a_thread, std::apply(&CombatBehaviorStack::Allocate<Context, const Fields&...>, std::tuple_cat(std::make_tuple(a_thread->stack), fields)));
		}

		// members
		std::tuple<Fields...> fields;
	};

	template <typename Context>
	class CombatBehaviorTreeCreateContextNodeImpl<Context> : public CombatBehaviorTreeCreateContextNodeImplBase<Context>
	{
	public:
		CombatBehaviorTreeCreateContextNodeImpl() = default;
		~CombatBehaviorTreeCreateContextNodeImpl() = default;

		void Enter(CombatBehaviorThread* a_thread) override
		{
			this->EnterContext(a_thread, a_thread->stack.Allocate<Context>());
		}
	};

	template <typename Context, typename... Fields>
	class CombatBehaviorTreeCreateContextNode : public CombatBehaviorTreeCreateContextNodeImpl<Context, Fields...>
	{
	public:
		using CombatBehaviorTreeCreateContextNodeImpl<Context, Fields...>::CombatBehaviorTreeCreateContextNodeImpl;
	};

	// Specs for nodes with Create

#define DECLARE_SPECIALIZATION(Context, SE_ID, AE_ID)                                                            \
	template <>                                                                                                  \
	class CombatBehaviorTreeCreateContextNode<Context> : public CombatBehaviorTreeCreateContextNodeImpl<Context> \
	{                                                                                                            \
	public:                                                                                                      \
		CombatBehaviorTreeCreateContextNode() = delete;                                                          \
                                                                                                                 \
		static CombatBehaviorTreeNode* Create()                                                                  \
		{                                                                                                        \
			REL::Relocation<CombatBehaviorTreeNode*()> func{ RELOCATION_ID((SE_ID), (AE_ID)) };                  \
			return func();                                                                                       \
		}                                                                                                        \
	};                                                                                                           \
	static_assert(sizeof(CombatBehaviorTreeCreateContextNode<Context>) == 0x28)

	DECLARE_SPECIALIZATION(CombatBehaviorContextAcquireWeapon, 46373, 0);       // I do not know for AE
	//DECLARE_SPECIALIZATION(CombatBehaviorContextCloseMovement, 46753, 0);       // I do not know for AE
	//DECLARE_SPECIALIZATION(CombatBehaviorContextCover, 48865, 0);               // I do not know for AE
	//DECLARE_SPECIALIZATION(CombatBehaviorContextDodgeThreat, 46599, 0);         // I do not know for AE
	//DECLARE_SPECIALIZATION(CombatBehaviorContextFindAttackLocation, 46985, 0);  // I do not know for AE
	//DECLARE_SPECIALIZATION(CombatBehaviorContextFlankingMovement, 47164, 0);    // I do not know for AE
	//DECLARE_SPECIALIZATION(CombatBehaviorContextFlee, 47449, 0);                // I do not know for AE
	//DECLARE_SPECIALIZATION(CombatBehaviorContextHide, 47450, 0);                // I do not know for AE
	//DECLARE_SPECIALIZATION(CombatBehaviorContextRangedMovement, 48484, 0);      // I do not know for AE
	//DECLARE_SPECIALIZATION(CombatBehaviorContextSearch, 48572, 0);              // I do not know for AE

#undef DECLARE_SPECIALIZATION

	// inlined specs

#define DECLARE_SPECIALIZATION(List, size, SE_ID, AE_ID)                                                   \
	template <>                                                                                            \
	class CombatBehaviorTreeCreateContextNode<List> : public CombatBehaviorTreeCreateContextNodeImpl<List> \
	{                                                                                                      \
	public:                                                                                                \
		template <typename... Params>                                                                      \
		CombatBehaviorTreeCreateContextNode(Params&&... params) :                                          \
			CombatBehaviorTreeCreateContextNodeImpl<List>(std::forward<Params>(params)...)                 \
		{                                                                                                  \
			this->SetVftable(RELOCATION_ID((SE_ID), (AE_ID)));                                             \
		}                                                                                                  \
	};                                                                                                     \
	static_assert(sizeof(CombatBehaviorTreeCreateContextNode<List>) == (size))



#undef DECLARE_SPECIALIZATION
}
