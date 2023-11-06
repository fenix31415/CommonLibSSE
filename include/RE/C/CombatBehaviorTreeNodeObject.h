#pragma once

#include "RE/A/AITimer.h"
#include "RE/C/CombatBehaviorAcquireResource.h"
#include "RE/C/CombatBehaviorChildSelector.h"
#include "RE/C/CombatBehaviorContextAcquireWeapon.h"
#include "RE/C/CombatBehaviorExpression.h"
#include "RE/C/CombatBehaviorFallbackSelector.h"
#include "RE/C/CombatBehaviorParallel.h"
#include "RE/C/CombatBehaviorRepeat.h"
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

	template <typename Object, uint64_t SE, uint64_t AE>
	class CombatBehaviorTreeNodeObjectWithCreate : public CombatBehaviorTreeNode
	{
	public:
		CombatBehaviorTreeNodeObjectWithCreate() = delete;

		static CombatBehaviorTreeNode* Create()
		{
			REL::Relocation<CombatBehaviorTreeNode*()> func{ RELOCATION_ID(SE, AE) };
			return func();
		}
	};

	template <typename Object>
	class CombatBehaviorTreeNodeObject : public CombatBehaviorTreeNode
	{
	public:
		~CombatBehaviorTreeNodeObject() = default;
		CombatBehaviorTreeNodeObject() = default;

		void Enter(CombatBehaviorThread* a_thread) override
		{
			a_thread->stack.Allocate<Object>();
			a_thread->GetCurrentStackObject<Object>().Enter();
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

#define DECLARE_SPECIALIZATION(O, SE, AE, size)                                                          \
	template <>                                                                                          \
	class CombatBehaviorTreeNodeObject<O> : public CombatBehaviorTreeNodeObjectWithCreate<O, SE, AE>     \
	{                                                                                                    \
	public:                                                                                              \
		using CombatBehaviorTreeNodeObjectWithCreate<O, SE, AE>::CombatBehaviorTreeNodeObjectWithCreate; \
	};                                                                                                   \
	static_assert(sizeof(CombatBehaviorTreeNodeObject<O>) == size)

	DECLARE_SPECIALIZATION(CombatBehaviorAdvance, 46758, 0, 0x28);                                        // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorAttack, 48154, 0, 0x28);                                         // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorAttackFromCover, 48867, 0, 0x28);                                // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorAttackLow, 48001, 0, 0x28);                                      // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorBackoff, 46759, 0, 0x28);                                        // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorBash, 46646, 0, 0x28);                                           // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorBlock, 46647, 0, 0x28);                                          // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorBlockAttack, 46648, 0, 0x28);                                    // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorCastConcentrationSpell, 48077, 0, 0x28);                         // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorCastImmediateSpell, 48078, 0, 0x28);                             // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorCastShout, 48815, 0, 0x28);                                      // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorChase, 47167, 0, 0x28);                                          // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorCheckUnreachableTarget, 48252, 0, 0x28);                         // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorChildSelector<ConditionalChildSelector>, 46756, 0, 0x28);        // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorChildSelector<RandomValueChildSelector>, 46757, 0, 0x28);        // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorChildSelector<ValueChildSelector>, 46477, 0, 0x28);              // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorCircle, 46760, 0, 0x28);                                         // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorCircleDistant, 46761, 0, 0x28);                                  // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorDiveBomb, 47788, 0, 0x28);                                       // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorDodgeThreat, 46600, 0, 0x28);                                    // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorDrinkPotion, 48991, 0, 0x28);                                    // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorDynamicConditionalNode, 46478, 0, 0x28);                         // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorEquipObject, 46479, 0, 0x28);                                    // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorEquipRangedWeapon, 46480, 0, 0x28);                              // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorEquipShout, 46481, 0, 0x28);                                     // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorEquipSpell, 46482, 0, 0x28);                                     // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorExitWater, 48253, 0, 0x28);                                      // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFallback, 46762, 0, 0x28);                                       // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFallbackSelector<NextChildSelector>, 32407, 0, 0x28);            // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFallbackSelector<WeightedRandomChildSelector>, 47787, 0, 0x28);  // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFallbackToRanged, 46763, 0, 0x28);                               // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFindAllyAttackLocation, 46987, 0, 0x28);                         // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFindAttackLocation, 46988, 0, 0x28);                             // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFindCover, 48868, 0, 0x28);                                      // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFindLateralAttackLocation, 46989, 0, 0x28);                      // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFindWeapon, 46374, 0, 0x28);                                     // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFlank, 47168, 0, 0x28);                                          // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFlankDistant, 47169, 0, 0x28);                                   // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFlee, 47453, 0, 0x28);                                           // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFleeThroughDoor, 47454, 0, 0x28);                                // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFleeToAlly, 47455, 0, 0x28);                                     // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFleeToCover, 47456, 0, 0x28);                                    // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFlyingAttack, 47789, 0, 0x28);                                   // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorForceFail, 48575, 0, 0x28);                                      // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorForceSuccess, 47457, 0, 0x28);                                   // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorGroundAttack, 47790, 0, 0x28);                                   // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorHide, 47458, 0, 0x28);                                           // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorHover, 47791, 0, 0x28);                                          // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorLand, 47792, 0, 0x28);                                           // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorMaintainOptimalRange, 48485, 0, 0x28);                           // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorOrbit, 47793, 0, 0x28);                                          // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorOrbitDistant, 47794, 0, 0x28);                                   // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorParallel, 46279, 0, 0x28);                                       // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorPause, 46483, 0, 0x28);                                          // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorPerchAttack, 47795, 0, 0x28);                                    // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorPrepareDualCast, 48079, 0, 0x28);                                // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorPursueTarget, 48002, 0, 0x28);                                   // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorRangedAttack, 32408, 0, 0x28);                                   // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorRepeat, 32409, 0, 0x28);                                         // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorReposition, 46764, 0, 0x28);                                     // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorReturnToCombatArea, 48254, 0, 0x28);                             // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorSearchInvestigateDoor, 48576, 0, 0x28);                          // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorSequence, 46375, 0, 0x28);                                       // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorSpecialAttack, 48155, 0, 0x28);                                  // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorStalk, 47170, 0, 0x28);                                          // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorStrafe, 48486, 0, 0x28);                                         // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorSurround, 46765, 0, 0x28);                                       // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorTakeoff, 47796, 0, 0x28);                                        // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorTrackTarget, 47459, 0, 0x28);                                    // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorWaitBehindCover, 48869, 0, 0x28);                                // I do not know for AE

#undef DECLARE_SPECIALIZATION

	template <typename Object, typename T>
	class CombatBehaviorTreeNodeObject1Base : public CombatBehaviorTreeNode
	{
	public:
		CombatBehaviorTreeNodeObject1Base(T arg1) :
			field1(std::move(arg1))
		{}

		// members
		T field1;  // 28
	};

	template <typename Object, typename T, uint64_t SE_ID, uint64_t AE_ID>
	class CombatBehaviorTreeNodeObject1Inlined : public CombatBehaviorTreeNodeObject1Base<Object, T>
	{
	public:
		CombatBehaviorTreeNodeObject1Inlined(T arg1) :
			CombatBehaviorTreeNodeObject1Base<Object, T>(std::forward<T>(arg1))
		{
			this->SetVftable(RELOCATION_ID(SE_ID, AE_ID));
		}
	};

	template <typename Object, typename T>
	class CombatBehaviorTreeNodeObject1 : public CombatBehaviorTreeNodeObject1Base<Object, T>
	{
		// Inherit from NodeObject and add fields, override functions
		CombatBehaviorTreeNodeObject1() = delete;
	};

#define DECLARE_SPECIALIZATION(O, T, SE, AE, size)                                                                    \
	template <>                                                                                                       \
	class CombatBehaviorTreeNodeObject1<O, T> : public CombatBehaviorTreeNodeObject1Inlined<O, T, SE, AE> \
	{                                                                                                                 \
	public:                                                                                                           \
		using CombatBehaviorTreeNodeObject1Inlined<O, T, SE, AE>::CombatBehaviorTreeNodeObject1Inlined;       \
	};                                                                                                                \
	static_assert(sizeof(CombatBehaviorTreeNodeObject1<O, T>) == size)

	//using tmp_t = ;

	//DECLARE_SPECIALIZATION(CombatBehaviorAcquireItem, CombatBehaviorExpression<RE::CombatBehaviorMemberFunc<CombatBehaviorContextAcquireWeapon, decltype(&CombatBehaviorContextAcquireWeapon::getAcquireWeapon)>>, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorAcquireItem_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorContextAcquireWeapon_CombatAcquireItemconst_CombatBehaviorContextAcquireWeapon____void____[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);  // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorCastConcentrationSpell, bool, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorCastConcentrationSpell_bool_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                                                                                                                                                            // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorCastImmediateSpell, bool, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorCastImmediateSpell_bool_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                                                                                                                                                                    // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorEnableBlackboardFlag, CombatBlackboardFlag*, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorEnableBlackboardFlag_CombatBlackboardFlag_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                                                                                                                               // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFlee, float, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorFlee_float_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                                                                                                                                                                                              // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorIdle, float, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorIdle_float_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                                                                                                                                                                                              // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorLand, float, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorLand_float_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                                                                                                                                                                                              // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorLandNearby, float, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorLandNearby_float_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                                                                                                                                                                                  // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorRepeat, CombatBehaviorRepeat::FLAGS, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorRepeat_CombatBehaviorRepeat__FLAGS_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                                                                                                                                              // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorRepeat, float, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorRepeat_float_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                                                                                                                                                                                          // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorWatchTarget, float, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorWatchTarget_float_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                                                                                                                                                                                // I do not know for AE

#undef DECLARE_SPECIALIZATION

	/*
	// TODO Settings, Function1
		14081CE3E 14081C8F0 14081C971
	
	// TODO CombatAimController::PRIORITY
	template <>
	class CombatBehaviorTreeNodeObject1<CombatBehaviorDisableAim, uint32_t> : public CombatBehaviorTreeNodeObject1Inlined<CombatBehaviorDisableAim, uint32_t, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorDisableAim_CombatAimController__PRIORITY_>
	{
	public:
		using Base_t::Base_t;
	};
	static_assert(sizeof(CombatBehaviorTreeNodeObject1<CombatBehaviorDisableAim, uint32_t>) == 0x30);

	// TODO arg1 = COMBAT_SEARCH_PRIORITY
	template <>
	class CombatBehaviorTreeNodeObject1<CombatBehaviorSearchCenter, uint32_t> : public CombatBehaviorTreeNodeObject1Inlined<CombatBehaviorSearchCenter, uint32_t, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorSearchCenter_COMBAT_SEARCH_PRIORITY_>
	{
	public:
		using Base_t::Base_t;
	};
	static_assert(sizeof(CombatBehaviorTreeNodeObject1<CombatBehaviorSearchCenter, uint32_t>) == 0x30);

	// TODO arg1 = COMBAT_SEARCH_PRIORITY
	template <>
	class CombatBehaviorTreeNodeObject1<CombatBehaviorSearchWander, uint32_t> : public CombatBehaviorTreeNodeObject1Inlined<CombatBehaviorSearchWander, uint32_t, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorSearchWander_COMBAT_SEARCH_PRIORITY_>
	{
	public:
		using Base_t::Base_t;
	};
	static_assert(sizeof(CombatBehaviorTreeNodeObject1<CombatBehaviorSearchWander, uint32_t>) == 0x30);

	// TODO arg1 = COMBAT_SEARCH_PRIORITY
	template <>
	class CombatBehaviorTreeNodeObject1<CombatBehaviorSearchLocation, uint32_t> : public CombatBehaviorTreeNodeObject1Inlined<CombatBehaviorSearchLocation, uint32_t, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorSearchLocation_COMBAT_SEARCH_PRIORITY_>
	{
	public:
		using Base_t::Base_t;
	};
	static_assert(sizeof(CombatBehaviorTreeNodeObject1<CombatBehaviorSearchLocation, uint32_t>) == 0x30);

	// TODO arg1 = COMBAT_SEARCH_PRIORITY
	template <>
	class CombatBehaviorTreeNodeObject1<CombatBehaviorSearch, uint32_t> : public CombatBehaviorTreeNodeObject1Inlined<CombatBehaviorSearch, uint32_t, VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorSearch_COMBAT_SEARCH_PRIORITY_>
	{
	public:
		using Base_t::Base_t;
	};
	static_assert(sizeof(CombatBehaviorTreeNodeObject1<CombatBehaviorSearch, uint32_t>) == 0x30);
	*/

	template <typename Object, typename T, typename U>
	class CombatBehaviorTreeNodeObject2Base : public CombatBehaviorTreeNode
	{
	public:
		CombatBehaviorTreeNodeObject2Base(T arg1, U arg2) :
			field1(std::move(arg1)), field2(std::move(arg2))
		{}

		// members
		T field1;  // 28
		U field2;  // ??
	};

	template <typename Object, typename T, typename U, uint64_t SE_ID, uint64_t AE_ID>
	class CombatBehaviorTreeNodeObject2Inlined : public CombatBehaviorTreeNodeObject2Base<Object, T, U>
	{
	public:
		CombatBehaviorTreeNodeObject2Inlined(T arg1, U arg2) :
			CombatBehaviorTreeNodeObject2Base<Object, T, U>(std::forward<T>(arg1), std::forward<U>(arg2))
		{
			this->SetVftable(RELOCATION_ID(SE_ID, AE_ID));
		}
	};

	template <typename Object, typename T, typename U>
	class CombatBehaviorTreeNodeObject2 : public CombatBehaviorTreeNodeObject1Base<Object, T>
	{
		// Inherit from NodeObject and add fields, override functions
		CombatBehaviorTreeNodeObject2() = delete;
	};

#define DECLARE_SPECIALIZATION(O, T, U, SE, AE, size)                                                \
	template <>                                                                              \
	class CombatBehaviorTreeNodeObject2<O, T, U> : public CombatBehaviorTreeNodeObject2Inlined<O, T, U, SE, AE> \
	{                                                                                        \
	public:                                                                                  \
		using CombatBehaviorTreeNodeObject2Inlined<O, T, U, SE, AE>::CombatBehaviorTreeNodeObject2Inlined;                                                            \
	};                                                                                       \
	static_assert(sizeof(CombatBehaviorTreeNodeObject2<O, T, U>) == size)

	DECLARE_SPECIALIZATION(CombatBehaviorAcquireResource, BSFixedString, int, VTABLE_CombatBehaviorTreeNodeObject2_CombatBehaviorAcquireResource_BSFixedString_int_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x38);                                                                                                                            // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorFaceAngle, float, bool, VTABLE_CombatBehaviorTreeNodeObject2_CombatBehaviorFaceAngle_float_bool_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                                                                                                                      // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorRepeat, float, CombatBehaviorRepeat::FLAGS, VTABLE_CombatBehaviorTreeNodeObject2_CombatBehaviorRepeat_float_CombatBehaviorRepeat__FLAGS_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                                                                              // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorSetBlackboardData, CombatBlackboardKey<AITimeStamp>*, decltype(&AITimer::QTimer), VTABLE_CombatBehaviorTreeNodeObject2_CombatBehaviorSetBlackboardData_CombatBlackboardKey_AITimeStamp__CombatBehaviorExpression_CombatBehaviorFunc_float___void____[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x38);  // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorSpawnParallel, uint32_t, CombatBehaviorParallel::FLAGS, VTABLE_CombatBehaviorTreeNodeObject2_CombatBehaviorSpawnParallel_unsignedint_CombatBehaviorParallel__FLAGS_[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                                                   // I do not know for AE

#undef DECLARE_SPECIALIZATION

	template <typename Object, typename T, typename U, typename P>
	class CombatBehaviorTreeNodeObject3Base : public CombatBehaviorTreeNode
	{
	public:
		CombatBehaviorTreeNodeObject3Base(T arg1, U arg2, P arg3) :
			field1(std::move(arg1)), field2(std::move(arg2)), field3(std::move(arg3))
		{}

		// members
		T field1;  // 28
		U field2;  // ??
		P field3;  // ??
	};

	template <typename Object, typename T, typename U, typename P, const std::array<REL::ID, 1>& vftableID>
	class CombatBehaviorTreeNodeObject3Inlined : public CombatBehaviorTreeNodeObject3Base<Object, T, U, P>
	{
	public:
		inline static constexpr auto VTABLE = vftableID;

		CombatBehaviorTreeNodeObject3Inlined(T arg1, U arg2, P arg3) :
			CombatBehaviorTreeNodeObject3Base<Object, T, U, P>(std::forward<T>(arg1), std::forward<U>(arg2), std::forward<P>(arg3))
		{
			stl::emplace_vtable<CombatBehaviorTreeNodeObject3Inlined>(this);
		}
	};

	template <typename Object, typename T, typename U, typename P>
	class CombatBehaviorTreeNodeObject3
	{
		// Inherit from NodeObject and add fields, override functions
		CombatBehaviorTreeNodeObject3() = delete;
	};

	template <>
	class CombatBehaviorTreeNodeObject3<CombatBehaviorAcquireResource, BSFixedString, int, CombatBehaviorAcquireResource::FLAG> : public CombatBehaviorTreeNodeObject3Inlined<CombatBehaviorAcquireResource, BSFixedString, int, CombatBehaviorAcquireResource::FLAG, VTABLE_CombatBehaviorTreeNodeObject3_CombatBehaviorAcquireResource_BSFixedString_int_CombatBehaviorAcquireResource__FLAG_>
	{
	public:
		using CombatBehaviorTreeNodeObject3Inlined<CombatBehaviorAcquireResource, BSFixedString, int, CombatBehaviorAcquireResource::FLAG, VTABLE_CombatBehaviorTreeNodeObject3_CombatBehaviorAcquireResource_BSFixedString_int_CombatBehaviorAcquireResource__FLAG_>::CombatBehaviorTreeNodeObject3Inlined;
	};
	static_assert(sizeof(CombatBehaviorTreeNodeObject3<CombatBehaviorAcquireResource, BSFixedString, int, CombatBehaviorAcquireResource::FLAG>) == 0x38);
}
