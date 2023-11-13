#pragma once

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

		template <typename Context, typename... Fields>
		class CreateContextImpl
		{
			using Node = CombatBehaviorTreeCreateContextNode<Context, Fields...>;

		public:
			template <typename... Args>
			[[nodiscard]] static Node* eval(Args&&... params)
			{
				if constexpr (IsGameNode<Node>::value)
					return static_cast<Node*>(Node::Create(std::forward<Args>(params)...));
				else
					return new Node(std::forward<Args>(params)...);
			}
		};

		template <typename Object, typename... Fields>
		class CreateObjectImpl
		{
			using Node = CombatBehaviorTreeNodeObject<Object, Fields...>;

		public:
			template <typename... Args>
			[[nodiscard]] static Node* eval(Args&&... params)
			{
				if constexpr (IsGameNode<Node>::value)
					return static_cast<Node*>(Node::Create(std::forward<Args>(params)...));
				else
					return new Node(std::forward<Args>(params)...);
			}
		};

		template <typename Expr>
		class CreateConditionalNodeImpl
		{
			using Node = CombatBehaviorTreeConditionalNode<Expr>;

		public:
			template <typename T>
			[[nodiscard]] static Node* eval(T&& expr, bool isSelector)
			{
				return new Node(std::forward<T>(expr), isSelector);
			}
		};

		template <typename Expr>
		class AddConditionalSelectorNodeImpl
		{
		public:
			template <typename T>
			[[nodiscard]] static TreeBuilder eval(const char* name, T&& expr, CombatBehaviorTreeNode* node)
			{
				auto cond_node = CreateConditionalNodeImpl::eval(std::forward<T>(expr), true);
				char DstBuf[260];
				sprintf_s(DstBuf, 260, "ConditionalNode - %s", name);
				cond_node->name = RE::BSFixedString(DstBuf);
				cond_node->AddChild(node);
				return AddNode(name, node);
			}
		};

		template <typename Expr>
		class AddConditionalSequenceNodeImpl
		{
		public:
			template <typename T>
			[[nodiscard]] static TreeBuilder eval(const char* name, T&& expr, CombatBehaviorTreeNode* node)
			{
				auto cond_node = CreateConditionalNodeImpl::eval(std::forward<T>(expr), false);
				char DstBuf[260];
				sprintf_s(DstBuf, 260, "ConditionalNode - %s", name);
				cond_node->name = RE::BSFixedString(DstBuf);
				cond_node->AddChild(node);
				return AddNode(name, node);
			}
		};

		template <typename Expr>
		class AddRandomNodeImpl
		{
			using MainExpr_t = CombatBehaviorExpression<CombatBehaviorFunc<bool (*)(float), Expr>>;

		public:
			template <typename T>
			[[nodiscard]] static TreeBuilder eval(const char* name, T&& expr, CombatBehaviorTreeNode* node)
			{
				auto cond_node = CreateConditionalNodeImpl<MainExpr_t>::eval(std::forward<T>(expr), true);
				char DstBuf[260];
				sprintf_s(DstBuf, 260, "ConditionalNode - %s", name);
				cond_node->name = RE::BSFixedString(DstBuf);
				cond_node->AddChild(node);
				return AddNode(name, node);
			}
		};

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

		template <typename T, typename Expr>
		[[nodiscard]] static auto CreateValueNodeT(auto&& expr)
		{
			return new CombatBehaviorTreeValueNodeT<T, Expr>(std::forward<decltype(expr)>(expr));
		}

		// TODO: I do not know how to add overloads for instances that already present in the game (e.g. 1407DA2B0). Do we need this?
		template <typename T, typename Expr>
		static TreeBuilder AddValueNodeT(const char* name, auto&& expr, CombatBehaviorTreeNode* node)
		{
			auto value_node = CreateValueNodeT<T, Expr>(std::forward<decltype(expr)>(expr));
			node->name = name;
			char DstBuf[260];
			sprintf_s(DstBuf, 260, "ValueNode - %s", name);
			return AddNode(DstBuf, value_node);
		}

		// TODO: I do not know how to implement AddValueNode (e.g. 1407DA250 detects unsigned int and calls 1407DA2B0)

		virtual void Initialize();  // 00

		// members
		BSFixedString           name;  // 08
		CombatBehaviorTreeNode* root;  // 10
	};
	static_assert(sizeof(CombatBehaviorTree) == 0x18);
}
