#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CombatBehaviorAcquireResource.h"
#include "RE/C/CombatBehaviorChildSelector.h"
#include "RE/C/CombatBehaviorContextAcquireWeapon.h"
#include "RE/C/CombatBehaviorContextMelee.h"
#include "RE/C/CombatBehaviorEquipContext.h"
#include "RE/C/CombatBehaviorFallbackSelector.h"
#include "RE/C/CombatBehaviorParallel.h"
#include "RE/C/CombatBehaviorRepeat.h"
#include "RE/C/CombatBehaviorThread.h"
#include "RE/C/CombatBehaviorTreeCreateContextNode.h"
#include "RE/C/CombatBehaviorTreeNode.h"
#include "RE/C/CombatBehaviorTreeNodeObject.h"

namespace RE
{
	class CombatBehaviorAcquireItem;
	class CombatBehaviorAcquireResource;
	class CombatBehaviorAdvance;
	class CombatBehaviorAttack;
	class CombatBehaviorAttackFromCover;
	class CombatBehaviorAttackLow;
	class CombatBehaviorBackoff;
	class CombatBehaviorBash;
	class CombatBehaviorBlock;
	class CombatBehaviorBlockAttack;
	class CombatBehaviorCastConcentrationSpell;
	class CombatBehaviorCastImmediateSpell;
	class CombatBehaviorCastShout;
	class CombatBehaviorChase;
	class CombatBehaviorCheckUnreachableTarget;
	class CombatBehaviorCircle;
	class CombatBehaviorCircleDistant;
	class CombatBehaviorContextAcquireWeapon;
	class CombatBehaviorContextBlock;
	class CombatBehaviorContextCloseMovement;
	class CombatBehaviorContextCover;
	class CombatBehaviorContextDodgeThreat;
	class CombatBehaviorContextFindAttackLocation;
	class CombatBehaviorContextFlankingMovement;
	class CombatBehaviorContextFlee;
	class CombatBehaviorContextHide;
	class CombatBehaviorContextMagic;
	class CombatBehaviorContextRanged;
	class CombatBehaviorContextRangedMovement;
	class CombatBehaviorContextSearch;
	class CombatBehaviorContextShout;
	class CombatBehaviorContextUsePotion;
	class CombatBehaviorDisableAim;
	class CombatBehaviorDiveBomb;
	class CombatBehaviorDodgeThreat;
	class CombatBehaviorDrinkPotion;
	class CombatBehaviorDynamicConditionalNode;
	class CombatBehaviorEquipObject;
	class CombatBehaviorEquipRangedWeapon;
	class CombatBehaviorEquipShout;
	class CombatBehaviorEquipSpell;
	class CombatBehaviorExitWater;
	class CombatBehaviorFallback;
	class CombatBehaviorFallbackToRanged;
	class CombatBehaviorFaceAngle;
	class CombatBehaviorFindAllyAttackLocation;
	class CombatBehaviorFindAttackLocation;
	class CombatBehaviorFindCover;
	class CombatBehaviorFindLateralAttackLocation;
	class CombatBehaviorFindWeapon;
	class CombatBehaviorFlank;
	class CombatBehaviorFlankDistant;
	class CombatBehaviorFlee;
	class CombatBehaviorFleeThroughDoor;
	class CombatBehaviorFleeToAlly;
	class CombatBehaviorFleeToCover;
	class CombatBehaviorFlyingAttack;
	class CombatBehaviorForceFail;
	class CombatBehaviorForceSuccess;
	class CombatBehaviorGroundAttack;
	class CombatBehaviorHide;
	class CombatBehaviorHover;
	class CombatBehaviorIdle;
	class CombatBehaviorLand;
	class CombatBehaviorLandNearby;
	class CombatBehaviorMaintainOptimalRange;
	class CombatBehaviorOrbit;
	class CombatBehaviorOrbitDistant;
	class CombatBehaviorParallel;
	class CombatBehaviorPause;
	class CombatBehaviorPerchAttack;
	class CombatBehaviorPrepareDualCast;
	class CombatBehaviorPursueTarget;
	class CombatBehaviorRangedAttack;
	class CombatBehaviorRepeat;
	class CombatBehaviorReposition;
	class CombatBehaviorReturnToCombatArea;
	class CombatBehaviorSearch;
	class CombatBehaviorSearchCenter;
	class CombatBehaviorSearchInvestigateDoor;
	class CombatBehaviorSearchLocation;
	class CombatBehaviorSearchWander;
	class CombatBehaviorSequence;
	class CombatBehaviorSpawnParallel;
	class CombatBehaviorSpecialAttack;
	class CombatBehaviorStalk;
	class CombatBehaviorStrafe;
	class CombatBehaviorSurround;
	class CombatBehaviorTakeoff;
	class CombatBehaviorTrackTarget;
	class CombatBehaviorWaitBehindCover;
	class CombatBehaviorWatchTarget;

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

		static TreeBuilder AddNode(char* name, CombatBehaviorTreeNode* node);
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

		// TODO Blackboard 1407E24AF 1407F5492 140827AC5
		//      Settings 14081CE3E 14081C8F0 14081C971

		virtual void Initialize();  // 00

		// members
		BSFixedString           name;  // 08
		CombatBehaviorTreeNode* root;  // 10
	};
	static_assert(sizeof(CombatBehaviorTree) == 0x18);
}
