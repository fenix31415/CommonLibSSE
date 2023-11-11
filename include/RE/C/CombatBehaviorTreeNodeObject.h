#pragma once

#include <functional>

#include "RE/A/AITimer.h"
#include "RE/C/CombatBehaviorAcquireResource.h"
#include "RE/C/CombatBehaviorBlock.h"
#include "RE/C/CombatBehaviorBlockAttack.h"
#include "RE/C/CombatBehaviorChildSelector.h"
#include "RE/C/CombatBehaviorContextAcquireWeapon.h"
#include "RE/C/CombatBehaviorExpression.h"
#include "RE/C/CombatBehaviorFallbackSelector.h"
#include "RE/C/CombatBehaviorParallel.h"
#include "RE/C/CombatBehaviorRepeat.h"
#include "RE/C/CombatBehaviorSequence.h"
#include "RE/C/CombatBehaviorTreeNode.h"
#include "RE/C/CombatBlackboardKey.h"

namespace RE
{
	template <typename Object>
	class CombatBehaviorTreeNodeObjectImplBase : public CombatBehaviorTreeNode
	{
	public:
		CombatBehaviorTreeNodeObjectImplBase() = default;
		~CombatBehaviorTreeNodeObjectImplBase() = default;

		void Update(CombatBehaviorThread* thread) override
		{
			thread->GetCurrentStackObject<Object>().Update();
		}

		void Exit(CombatBehaviorThread* thread) override
		{
			thread->GetCurrentStackObject<Object>().Exit();
			thread->stack.Deallocate<Object>();
		}

		void SaveGame(CombatBehaviorThread*, BGSSaveFormBuffer*) override
		{
			// TODO
		}

		void LoadGame(CombatBehaviorThread*, BGSLoadFormBuffer*) override
		{
			// TODO
		}

		void Abort(CombatBehaviorThread* thread) override
		{
			thread->GetCurrentStackObject<Object>().Abort();
		}

		bool Validate(CombatBehaviorTreeNode* node) const override
		{
			return Object::Validate(node);
		}

		const BSFixedString& GetType() const override
		{
			static BSFixedString ans("CombatBehaviorTreeNodeObject");
			return ans;
		}
	};

	template <typename Object, typename... Fields>
	class CombatBehaviorTreeNodeObjectImpl : public CombatBehaviorTreeNodeObjectImplBase<Object>
	{
	public:
		template <typename... Params>
		CombatBehaviorTreeNodeObjectImpl(Params&&... params) :
			fields(std::make_tuple(std::forward<Params>(params)...))
		{}
		~CombatBehaviorTreeNodeObjectImpl() = default;

		void Enter(CombatBehaviorThread* a_thread) override
		{
			//a_thread->stack.Allocate<Object>();
			std::apply(
				[a_thread](const auto&... args) { a_thread->stack.Allocate<Object, const Fields&...>(args...); }, fields);
			a_thread->GetCurrentStackObject<Object>().Enter();
		}

		// members
		std::tuple<Fields...> fields;
	};

	template <typename Object>
	class CombatBehaviorTreeNodeObjectImpl<Object> : public CombatBehaviorTreeNodeObjectImplBase<Object>
	{
	public:
		CombatBehaviorTreeNodeObjectImpl() = default;
		~CombatBehaviorTreeNodeObjectImpl() = default;

		void Enter(CombatBehaviorThread* a_thread) override
		{
			a_thread->stack.Allocate<Object>();
			a_thread->GetCurrentStackObject<Object>().Enter();
		}
	};

	template <typename Object, typename... Fields>
	class CombatBehaviorTreeNodeObject : public CombatBehaviorTreeNodeObjectImpl<Object, Fields...>
	{
	public:
		using CombatBehaviorTreeNodeObjectImpl<Object, Fields...>::CombatBehaviorTreeNodeObjectImpl;
	};

	// Specs for nodes with Create

#define DECLARE_SPECIALIZATION(Object, SE_ID, AE_ID)                                             \
	template <>                                                                                  \
	class CombatBehaviorTreeNodeObject<Object> : public CombatBehaviorTreeNodeObjectImpl<Object> \
	{                                                                                            \
	public:                                                                                      \
		CombatBehaviorTreeNodeObject() = delete;                                                 \
                                                                                                 \
		static CombatBehaviorTreeNode* Create()                                                  \
		{                                                                                        \
			REL::Relocation<CombatBehaviorTreeNode*()> func{ RELOCATION_ID((SE_ID), (AE_ID)) };  \
			return func();                                                                       \
		}                                                                                        \
	};                                                                                           \
	static_assert(sizeof(CombatBehaviorTreeNodeObject<Object>) == 0x28)                          \

	DECLARE_SPECIALIZATION(CombatBehaviorBlock, 46647, 0);                                          // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorBlockAttack, 46648, 0);                                    // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorChildSelector<ConditionalChildSelector>, 46756, 0);        // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorChildSelector<RandomValueChildSelector>, 46757, 0);        // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorChildSelector<ValueChildSelector>, 46477, 0);              // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFallbackSelector<NextChildSelector>, 32407, 0);            // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFallbackSelector<WeightedRandomChildSelector>, 47787, 0);  // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorParallel, 46279, 0);                                       // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorRepeat, 32409, 0);                                         // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorSequence, 46375, 0);                                       // I do not know for AE

#undef DECLARE_SPECIALIZATION

	// inlined specs

#define DECLARE_SPECIALIZATION(List, size, SE_ID, AE_ID)                                     \
	template <>                                                                              \
	class CombatBehaviorTreeNodeObject<List> : public CombatBehaviorTreeNodeObjectImpl<List> \
	{                                                                                        \
	public:                                                                                  \
		template <typename... Params>                                                        \
		CombatBehaviorTreeNodeObject(Params&&... params) :                                   \
			CombatBehaviorTreeNodeObjectImpl<List>(std::forward<Params>(params)...)          \
		{                                                                                    \
			this->SetVftable(RELOCATION_ID((SE_ID), (AE_ID)));                               \
		}                                                                                    \
	};                                                                                       \
	static_assert(sizeof(CombatBehaviorTreeNodeObject<List>) == (size))						 \

	#define COMMA ,
	DECLARE_SPECIALIZATION(CombatBehaviorRepeat COMMA float, 0x30, 265835, 0);  // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorRepeat COMMA float COMMA CombatBehaviorRepeat::Flags, 0x30, 267191, 0);  // I do not know for AE
	#undef COMMA

#undef DECLARE_SPECIALIZATION
}
