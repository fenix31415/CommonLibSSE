#pragma once

#include <stdio.h>  // sprintf_s

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CombatBehaviorAcquireResource.h"
#include "RE/C/CombatBehaviorChildSelector.h"
#include "RE/C/CombatBehaviorContextAcquireWeapon.h"
#include "RE/C/CombatBehaviorContextCloseMovement.h"
#include "RE/C/CombatBehaviorContextDodgeThreat.h"
#include "RE/C/CombatBehaviorContextFlankingMovement.h"
#include "RE/C/CombatBehaviorContextMelee.h"
#include "RE/C/CombatBehaviorContextFlee.h"
#include "RE/C/CombatBehaviorEquipContext.h"
#include "RE/C/CombatBehaviorFallbackSelector.h"
#include "RE/C/CombatBehaviorParallel.h"
#include "RE/C/CombatBehaviorRepeat.h"
#include "RE/C/CombatBehaviorThread.h"
#include "RE/C/CombatBehaviorTreeConditionalNode.h"
#include "RE/C/CombatBehaviorTreeCreateContextNode.h"
#include "RE/C/CombatBehaviorTreeValueNodeT.h"
#include "RE/C/CombatBehaviorTreeNodeObject.h"
#include "RE/C/CombatBehaviorTreeNode.h"

namespace RE
{
	class CombatBehaviorTree
	{
	public:
		class TreeBuilder
		{
		public:
			explicit TreeBuilder();
			CombatBehaviorTreeNode* GetNode();
			TreeBuilder&            operator[](const TreeBuilder& a_other);
			TreeBuilder&            operator,(const TreeBuilder& a_other);

			// members
			RE::BSTArray<CombatBehaviorTreeNode*> data;
		};
		static_assert(sizeof(TreeBuilder) == 0x18);

		class CombatBehaviorAttacker
		{
		public:
			operator Actor*();
		};

		class CombatBehaviorTarget
		{
		public:
			operator Actor*();
		};

		static TreeBuilder AddNode(const char* name, CombatBehaviorTreeNode* node);
		void               CreateTree(CombatBehaviorTreeNode* node);

		template <typename T>
		struct IsGameNode
		{
		private:
			static int detect(...);

			template <typename U>
			static decltype(std::declval<U>().Create()) detect(const U&);

		public:
			static constexpr bool value = std::is_same<CombatBehaviorTreeNode*, decltype(detect(std::declval<T>()))>::value;
		};

		template <typename Context>
		[[nodiscard]] static CombatBehaviorTreeNode* CreateContext()
		{
			using Node = CombatBehaviorTreeCreateContextNode<Context>;
			if constexpr (IsGameNode<Node>::value)
				return Node::Create();
			else
				return new CombatBehaviorTreeCreateContextNode<Context>();
		}

		template <typename Context, typename T>
		[[nodiscard]] static CombatBehaviorTreeNode* CreateContext(T arg1)
		{
			return new CombatBehaviorTreeCreateContextNode1<Context, T>(std::move(arg1));
		}

		template <typename Context, typename T, typename U>
		[[nodiscard]] static CombatBehaviorTreeNode* CreateContext(T arg1, U arg2)
		{
			return new CombatBehaviorTreeCreateContextNode2<Context, T, U>(std::move(arg1), std::move(arg2));
		}

		template <typename Object>
		[[nodiscard]] static CombatBehaviorTreeNode* CreateObject()
		{
			using Node = CombatBehaviorTreeNodeObject<Object>;
			if constexpr (IsGameNode<Node>::value)
				return Node::Create();
			else
				return new Node();
		}

		template <typename Object, typename T>
		[[nodiscard]] static CombatBehaviorTreeNode* CreateObject(T arg1)
		{
			return new CombatBehaviorTreeNodeObject1<Object, T>(std::move(arg1));
		}

		template <typename Object, typename T, typename U>
		[[nodiscard]] static CombatBehaviorTreeNode* CreateObject(T arg1, U arg2)
		{
			return new CombatBehaviorTreeNodeObject2<Object, T, U>(std::move(arg1), std::move(arg2));
		}

		template <typename Object, typename T, typename U, typename P>
		[[nodiscard]] static CombatBehaviorTreeNode* CreateObject(T arg1, U arg2, P arg3)
		{
			return new CombatBehaviorTreeNodeObject3<Object, T, U, P>(std::move(arg1), std::move(arg2), std::move(arg3));
		}

		template <typename T>
		struct IsGameNode1
		{
		public:
			static constexpr bool value = false;
		};

		template <typename T>
		struct IsGameNode1<CombatBehaviorTreeConditionalNode<T>>
		{
		private:
			static int detect(...);

			template <typename U>
			static decltype(std::declval<U>().Create(std::declval<T>(), false)) detect(const U&);

		public:
			static constexpr bool value = std::is_same<CombatBehaviorTreeNode*, decltype(detect(std::declval<CombatBehaviorTreeConditionalNode<T>>()))>::value;
		};

		template <typename Expr>
		[[nodiscard]] static CombatBehaviorTreeNode* CreateConditionalNode(Expr expr, bool fail)
		{
			using Node = CombatBehaviorTreeConditionalNode<Expr>;
			if constexpr (IsGameNode1<Node>::value)
				return Node::Create(std::move(expr), fail);
			else
				return new CombatBehaviorTreeConditionalNode<Expr>(std::move(expr), fail);
		}

		template <typename Expr, bool fail>
		[[nodiscard]] static TreeBuilder AddConditionalNode(const char* name, Expr expr, CombatBehaviorTreeNode* node)
		{
			auto cond_node = CreateConditionalNode(std::move(expr), fail);
			char DstBuf[260];
			sprintf_s(DstBuf, 260, "ConditionalNode - %s", name);
			cond_node->name = RE::BSFixedString(DstBuf);
			cond_node->AddChild(node);
			return AddNode(name, node);
		}

#define DECLARE_OVERLOAD(SE_ID, AE_ID, Expr)                                                                       \
	[[nodiscard]] static TreeBuilder AddConditionalNode(const char* name, Expr expr, CombatBehaviorTreeNode* node) \
	{                                                                                                              \
		using func_t = TreeBuilder(const char* name, Expr, CombatBehaviorTreeNode* node);                          \
		REL::Relocation<func_t> func{ RELOCATION_ID(SE_ID, AE_ID) };                                               \
		return func(name, expr, node);                                                                             \
	}

		DECLARE_OVERLOAD(46357, 0, decltype(&CombatBehaviorContextAcquireWeapon::HasAmmoTarget));
		DECLARE_OVERLOAD(47152, 0, decltype(&CombatBehaviorContextFlankingMovement::CheckShouldStalk));
		DECLARE_OVERLOAD(47430, 0, decltype(&CombatBehaviorContextFlee::CheckShouldFlee));
		DECLARE_OVERLOAD(46732, 0, decltype(&CombatBehaviorContextCloseMovement::CheckShouldFallbackToRanged));
		DECLARE_OVERLOAD(46596, 0, decltype(&CombatBehaviorContextDodgeThreat::CheckShouldDodge));
		
		// TODO (Expr)
		//DECLARE_OVERLOAD(48554, 0, decltype(&CombatBehaviorContextAcquireWeapon::sub_1407CD9B0));
		//DECLARE_OVERLOAD(47760, 0, decltype(&CombatBehaviorContextAcquireWeapon::sub_1407CD9B0));
		//DECLARE_OVERLOAD(47761, 0, decltype(&CombatBehaviorContextAcquireWeapon::sub_1407CD9B0));
		//DECLARE_OVERLOAD(47762, 0, decltype(&CombatBehaviorContextAcquireWeapon::sub_1407CD9B0));

		#undef DECLARE_OVERLOAD

		// TODO: AddValue, also inlined
		template <typename T, typename Expr>
		[[nodiscard]] static CombatBehaviorTreeNode* CreateValueNodeT(Expr expr)
		{
			return new CombatBehaviorTreeValueNodeT<T, Expr>(std::move(expr));
		}

		virtual void Initialize();  // 00

		// members
		BSFixedString           name;  // 08
		CombatBehaviorTreeNode* root;  // 10
	};
	static_assert(sizeof(CombatBehaviorTree) == 0x18);
}
