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
	class CombatBehaviorLand;
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
	class CombatBehaviorSearchInvestigateDoor;
	class CombatBehaviorSequence;
	class CombatBehaviorSpecialAttack;
	class CombatBehaviorStalk;
	class CombatBehaviorStrafe;
	class CombatBehaviorSurround;
	class CombatBehaviorTakeoff;
	class CombatBehaviorTrackTarget;
	class CombatBehaviorWaitBehindCover;

	class ConditionalChildSelector;
	class NextChildSelector;
	class RandomValueChildSelector;
	class ValueChildSelector;
	class WeightedRandomChildSelector;

	class CombatBehaviorAcquireItem;
	class CombatBehaviorCastConcentrationSpell;
	class CombatBehaviorCastImmediateSpell;
	class CombatBehaviorEnableBlackboardFlag;
	class CombatBehaviorFlee;
	class CombatBehaviorIdle;
	class CombatBehaviorLand;
	class CombatBehaviorLandNearby;
	class CombatBehaviorRepeat;
	class CombatBehaviorRepeat;
	class CombatBehaviorWatchTarget;

	class CombatBlackboardFlag;

	class CombatBehaviorAcquireResource;
	class CombatBehaviorFaceAngle;
	class CombatBehaviorRepeat;
	class CombatBehaviorSetBlackboardData;
	class CombatBehaviorSpawnParallel;

	namespace Impl
	{
		template <typename T, typename = void>
		struct has_member : std::false_type
		{};

		template <typename T>
		struct has_member<T, std::void_t<decltype(T::VTABLE)>> : std::true_type
		{};
	}

	template <typename Object>
	class CombatBehaviorTreeNodeObjectImplBase : public CombatBehaviorTreeNode
	{
	public:
		CombatBehaviorTreeNodeObjectImplBase() = default;
		~CombatBehaviorTreeNodeObjectImplBase() = default;

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

		template <typename F, typename T, typename U>
		static decltype(auto) apply_invoke(F&& func, T&& first, U&& tuple)
		{
			return std::apply(std::forward<F>(func), std::tuple_cat(std::forward_as_tuple(std::forward<T>(first)), std::forward<U>(tuple)));
		}

		void Enter(CombatBehaviorThread* a_thread) override
		{
			//a_thread->stack.Allocate<Object>();
			std::apply(&CombatBehaviorStack::Allocate<Object, const Fields&...>, std::tuple_cat(std::make_tuple(a_thread->stack), fields));
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
			// todo: pass fields
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
			REL::Relocation<CombatBehaviorTreeNode*()> func{ RELOCATION_ID(SE_ID, AE_ID) };      \
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

	template <>
	class CombatBehaviorTreeNodeObject<CombatBehaviorRepeat, float> : public CombatBehaviorTreeNodeObjectImpl<CombatBehaviorRepeat, float>
	{
	public:
		template <typename... Params>
		CombatBehaviorTreeNodeObject(Params&&... params) :
			CombatBehaviorTreeNodeObjectImpl<CombatBehaviorRepeat, float>(std::forward<Params>(params)...)
		{
			this->SetVftable(RELOCATION_ID(265835, 0));
		}
	};
	static_assert(sizeof(CombatBehaviorTreeNodeObject<CombatBehaviorRepeat, float>) == 0x30);

}
