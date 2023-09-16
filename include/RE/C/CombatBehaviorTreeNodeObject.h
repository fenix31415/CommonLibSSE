#pragma once

#include "RE/C/CombatBehaviorAcquireResource.h"
#include "RE/C/CombatBehaviorChildSelector.h"
#include "RE/C/CombatBehaviorContextAcquireWeapon.h"
#include "RE/C/CombatBehaviorFallbackSelector.h"
#include "RE/C/CombatBehaviorParallel.h"
#include "RE/C/CombatBehaviorRepeat.h"
#include "RE/C/CombatBehaviorTreeNode.h"

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
	class CombatBehaviorFlee;
	class CombatBehaviorIdle;
	class CombatBehaviorLand;
	class CombatBehaviorLandNearby;
	class CombatBehaviorRepeat;
	class CombatBehaviorRepeat;
	class CombatBehaviorWatchTarget;

	class CombatBehaviorAcquireResource;
	class CombatBehaviorFaceAngle;
	class CombatBehaviorRepeat;
	class CombatBehaviorSpawnParallel;

	template <typename Object, uint64_t SE, uint64_t AE>
	class CombatBehaviorTreeNodeObjectWithCtor : public CombatBehaviorTreeNode
	{
	public:
		CombatBehaviorTreeNodeObjectWithCtor() = delete;

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

		const BSFixedString& GetName() const
		{
			return name;
		}
	};

	namespace MappingOffsets
	{
		template <typename T, uint64_t SE, uint64_t AE>
		struct Entry
		{
			using type = T;
			static constexpr uint64_t SE_ID = SE;
			static constexpr uint64_t AE_ID = AE;
		};

		template <typename T, bool isSE, typename Map, std::size_t... I>
		constexpr uint64_t mapper_impl(std::index_sequence<I...>)
		{
			return ((std::is_same_v<T, typename std::tuple_element_t<I, Map>::type> * (isSE ? std::tuple_element_t<I, Map>::SE_ID : std::tuple_element_t<I, Map>::AE_ID)) + ...);
		}

		template <typename T, bool isSE, typename Map>
		constexpr uint64_t mapper()
		{
			return mapper_impl<T, isSE, Map>(std::make_index_sequence<std::tuple_size_v<Map>>{});
		}

		template <typename T, typename Map>
		constexpr uint64_t MapperSE()
		{
			return mapper<T, true, Map>();
		}

		template <typename T, typename Map>
		constexpr uint64_t MapperAE()
		{
			return mapper<T, false, Map>();
		}
	}

	namespace NodeObjectHelper
	{
		using namespace MappingOffsets;

		using Map = std::tuple<
			Entry<CombatBehaviorAdvance, 46758, 0>,
			Entry<CombatBehaviorAttack, 48154, 0>,
			Entry<CombatBehaviorAttackFromCover, 48867, 0>,
			Entry<CombatBehaviorAttackLow, 48001, 0>,
			Entry<CombatBehaviorBackoff, 46759, 0>,
			Entry<CombatBehaviorBash, 46646, 0>,
			Entry<CombatBehaviorBlock, 46647, 0>,
			Entry<CombatBehaviorBlockAttack, 46648, 0>,
			Entry<CombatBehaviorCastConcentrationSpell, 48077, 0>,
			Entry<CombatBehaviorCastImmediateSpell, 48078, 0>,
			Entry<CombatBehaviorCastShout, 48815, 0>,
			Entry<CombatBehaviorChase, 47167, 0>,
			Entry<CombatBehaviorCheckUnreachableTarget, 48252, 0>,
			Entry<CombatBehaviorChildSelector<ConditionalChildSelector>, 46756, 0>,
			Entry<CombatBehaviorChildSelector<RandomValueChildSelector>, 46757, 0>,
			Entry<CombatBehaviorChildSelector<ValueChildSelector>, 46477, 0>,
			Entry<CombatBehaviorCircle, 46760, 0>,
			Entry<CombatBehaviorCircleDistant, 46761, 0>,
			Entry<CombatBehaviorDiveBomb, 47788, 0>,
			Entry<CombatBehaviorDodgeThreat, 46600, 0>,
			Entry<CombatBehaviorDrinkPotion, 48991, 0>,
			Entry<CombatBehaviorDynamicConditionalNode, 46478, 0>,
			Entry<CombatBehaviorEquipObject, 46479, 0>,
			Entry<CombatBehaviorEquipRangedWeapon, 46480, 0>,
			Entry<CombatBehaviorEquipShout, 46481, 0>,
			Entry<CombatBehaviorEquipSpell, 46482, 0>,
			Entry<CombatBehaviorExitWater, 48253, 0>,
			Entry<CombatBehaviorFallback, 46762, 0>,
			Entry<CombatBehaviorFallbackSelector<NextChildSelector>, 32407, 0>,
			Entry<CombatBehaviorFallbackSelector<WeightedRandomChildSelector>, 47787, 0>,
			Entry<CombatBehaviorFallbackToRanged, 46763, 0>,
			Entry<CombatBehaviorFindAllyAttackLocation, 46987, 0>,
			Entry<CombatBehaviorFindAttackLocation, 46988, 0>,
			Entry<CombatBehaviorFindCover, 48868, 0>,
			Entry<CombatBehaviorFindLateralAttackLocation, 46989, 0>,
			Entry<CombatBehaviorFindWeapon, 46374, 0>,
			Entry<CombatBehaviorFlank, 47168, 0>,
			Entry<CombatBehaviorFlankDistant, 47169, 0>,
			Entry<CombatBehaviorFlee, 47453, 0>,
			Entry<CombatBehaviorFleeThroughDoor, 47454, 0>,
			Entry<CombatBehaviorFleeToAlly, 47455, 0>,
			Entry<CombatBehaviorFleeToCover, 47456, 0>,
			Entry<CombatBehaviorFlyingAttack, 47789, 0>,
			Entry<CombatBehaviorForceFail, 48575, 0>,
			Entry<CombatBehaviorForceSuccess, 47457, 0>,
			Entry<CombatBehaviorGroundAttack, 47790, 0>,
			Entry<CombatBehaviorHide, 47458, 0>,
			Entry<CombatBehaviorHover, 47791, 0>,
			Entry<CombatBehaviorLand, 47792, 0>,
			Entry<CombatBehaviorMaintainOptimalRange, 48485, 0>,
			Entry<CombatBehaviorOrbit, 47793, 0>,
			Entry<CombatBehaviorOrbitDistant, 47794, 0>,
			Entry<CombatBehaviorParallel, 46279, 0>,
			Entry<CombatBehaviorPause, 46483, 0>,
			Entry<CombatBehaviorPerchAttack, 47795, 0>,
			Entry<CombatBehaviorPrepareDualCast, 48079, 0>,
			Entry<CombatBehaviorPursueTarget, 48002, 0>,
			Entry<CombatBehaviorRangedAttack, 32408, 0>,
			Entry<CombatBehaviorRepeat, 32409, 0>,
			Entry<CombatBehaviorReposition, 46764, 0>,
			Entry<CombatBehaviorReturnToCombatArea, 48254, 0>,
			Entry<CombatBehaviorSearchInvestigateDoor, 48576, 0>,
			Entry<CombatBehaviorSequence, 46375, 0>,
			Entry<CombatBehaviorSpecialAttack, 48155, 0>,
			Entry<CombatBehaviorStalk, 47170, 0>,
			Entry<CombatBehaviorStrafe, 48486, 0>,
			Entry<CombatBehaviorSurround, 46765, 0>,
			Entry<CombatBehaviorTakeoff, 47796, 0>,
			Entry<CombatBehaviorTrackTarget, 47459, 0>,
			Entry<CombatBehaviorWaitBehindCover, 48869, 0>>;

		template <typename T>
		class Helper : public CombatBehaviorTreeNodeObjectWithCtor<T, MapperSE<T, Map>(), MapperAE<T, Map>()>
		{
			static constexpr uint64_t SE_ID = MapperSE<T, Map>();
			static constexpr uint64_t AE_ID = MapperAE<T, Map>();

			static_assert(SE_ID > 0);

		public:
			using CombatBehaviorTreeNodeObjectWithCtor<T, SE_ID, AE_ID>::CombatBehaviorTreeNodeObjectWithCtor;
			using Helper_t = Helper<T>;
		};
		static_assert(sizeof(CombatBehaviorTreeNodeObjectWithCtor<void*, 0, 0>) == 0x28);
	}

	// Sory, I minimized this macro code as much as I can
	// I have them in my txt file so I can generate any code with them, if necessary
#define DECLARE_SPECIALIZATION(T)                                              \
	template <>                                                                \
	class CombatBehaviorTreeNodeObject<T> : public NodeObjectHelper::Helper<T> \
	{                                                                          \
	public:                                                                    \
		using Helper_t::Helper_t;                                              \
	}

	DECLARE_SPECIALIZATION(CombatBehaviorAdvance);
	DECLARE_SPECIALIZATION(CombatBehaviorAttack);
	DECLARE_SPECIALIZATION(CombatBehaviorAttackFromCover);
	DECLARE_SPECIALIZATION(CombatBehaviorAttackLow);
	DECLARE_SPECIALIZATION(CombatBehaviorBackoff);
	DECLARE_SPECIALIZATION(CombatBehaviorBash);
	DECLARE_SPECIALIZATION(CombatBehaviorBlock);
	DECLARE_SPECIALIZATION(CombatBehaviorBlockAttack);
	DECLARE_SPECIALIZATION(CombatBehaviorCastConcentrationSpell);
	DECLARE_SPECIALIZATION(CombatBehaviorCastImmediateSpell);
	DECLARE_SPECIALIZATION(CombatBehaviorCastShout);
	DECLARE_SPECIALIZATION(CombatBehaviorChase);
	DECLARE_SPECIALIZATION(CombatBehaviorCheckUnreachableTarget);
	DECLARE_SPECIALIZATION(CombatBehaviorChildSelector<ConditionalChildSelector>);
	DECLARE_SPECIALIZATION(CombatBehaviorChildSelector<RandomValueChildSelector>);
	DECLARE_SPECIALIZATION(CombatBehaviorChildSelector<ValueChildSelector>);
	DECLARE_SPECIALIZATION(CombatBehaviorCircle);
	DECLARE_SPECIALIZATION(CombatBehaviorCircleDistant);
	DECLARE_SPECIALIZATION(CombatBehaviorDiveBomb);
	DECLARE_SPECIALIZATION(CombatBehaviorDodgeThreat);
	DECLARE_SPECIALIZATION(CombatBehaviorDrinkPotion);
	DECLARE_SPECIALIZATION(CombatBehaviorDynamicConditionalNode);
	DECLARE_SPECIALIZATION(CombatBehaviorEquipObject);
	DECLARE_SPECIALIZATION(CombatBehaviorEquipRangedWeapon);
	DECLARE_SPECIALIZATION(CombatBehaviorEquipShout);
	DECLARE_SPECIALIZATION(CombatBehaviorEquipSpell);
	DECLARE_SPECIALIZATION(CombatBehaviorExitWater);
	DECLARE_SPECIALIZATION(CombatBehaviorFallback);
	DECLARE_SPECIALIZATION(CombatBehaviorFallbackSelector<NextChildSelector>);
	DECLARE_SPECIALIZATION(CombatBehaviorFallbackSelector<WeightedRandomChildSelector>);
	DECLARE_SPECIALIZATION(CombatBehaviorFallbackToRanged);
	DECLARE_SPECIALIZATION(CombatBehaviorFindAllyAttackLocation);
	DECLARE_SPECIALIZATION(CombatBehaviorFindAttackLocation);
	DECLARE_SPECIALIZATION(CombatBehaviorFindCover);
	DECLARE_SPECIALIZATION(CombatBehaviorFindLateralAttackLocation);
	DECLARE_SPECIALIZATION(CombatBehaviorFindWeapon);
	DECLARE_SPECIALIZATION(CombatBehaviorFlank);
	DECLARE_SPECIALIZATION(CombatBehaviorFlankDistant);
	DECLARE_SPECIALIZATION(CombatBehaviorFlee);
	DECLARE_SPECIALIZATION(CombatBehaviorFleeThroughDoor);
	DECLARE_SPECIALIZATION(CombatBehaviorFleeToAlly);
	DECLARE_SPECIALIZATION(CombatBehaviorFleeToCover);
	DECLARE_SPECIALIZATION(CombatBehaviorFlyingAttack);
	DECLARE_SPECIALIZATION(CombatBehaviorForceFail);
	DECLARE_SPECIALIZATION(CombatBehaviorForceSuccess);
	DECLARE_SPECIALIZATION(CombatBehaviorGroundAttack);
	DECLARE_SPECIALIZATION(CombatBehaviorHide);
	DECLARE_SPECIALIZATION(CombatBehaviorHover);
	DECLARE_SPECIALIZATION(CombatBehaviorLand);
	DECLARE_SPECIALIZATION(CombatBehaviorMaintainOptimalRange);
	DECLARE_SPECIALIZATION(CombatBehaviorOrbit);
	DECLARE_SPECIALIZATION(CombatBehaviorOrbitDistant);
	DECLARE_SPECIALIZATION(CombatBehaviorParallel);
	DECLARE_SPECIALIZATION(CombatBehaviorPause);
	DECLARE_SPECIALIZATION(CombatBehaviorPerchAttack);
	DECLARE_SPECIALIZATION(CombatBehaviorPrepareDualCast);
	DECLARE_SPECIALIZATION(CombatBehaviorPursueTarget);
	DECLARE_SPECIALIZATION(CombatBehaviorRangedAttack);
	DECLARE_SPECIALIZATION(CombatBehaviorRepeat);
	DECLARE_SPECIALIZATION(CombatBehaviorReposition);
	DECLARE_SPECIALIZATION(CombatBehaviorReturnToCombatArea);
	DECLARE_SPECIALIZATION(CombatBehaviorSearchInvestigateDoor);
	DECLARE_SPECIALIZATION(CombatBehaviorSequence);
	DECLARE_SPECIALIZATION(CombatBehaviorSpecialAttack);
	DECLARE_SPECIALIZATION(CombatBehaviorStalk);
	DECLARE_SPECIALIZATION(CombatBehaviorStrafe);
	DECLARE_SPECIALIZATION(CombatBehaviorSurround);
	DECLARE_SPECIALIZATION(CombatBehaviorTakeoff);
	DECLARE_SPECIALIZATION(CombatBehaviorTrackTarget);
	DECLARE_SPECIALIZATION(CombatBehaviorWaitBehindCover);

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
			reinterpret_cast<std::uintptr_t*>(this)[0] = (RELOCATION_ID(SE_ID, AE_ID)).address();
		}

		using Base_t = CombatBehaviorTreeNodeObject1Inlined<Object, T, SE_ID, AE_ID>;
	};

	template <typename Object, typename T>
	class CombatBehaviorTreeNodeObject1
	{
		CombatBehaviorTreeNodeObject1() = delete;  // Inherit from NodeObject and add fields, override functions
	};

	namespace MappingOffsets1
	{
		template <typename Object, typename T, uint64_t SE, uint64_t AE>
		struct Entry
		{
			using object = Object;
			using type = T;
			static constexpr uint64_t SE_ID = SE;
			static constexpr uint64_t AE_ID = AE;
		};

		template <typename Object, typename T, bool isSE, typename Map, std::size_t... I>
		constexpr uint64_t mapper_impl(std::index_sequence<I...>)
		{
			return ((std::is_same_v<Object, typename std::tuple_element_t<I, Map>::object> * std::is_same_v<T, typename std::tuple_element_t<I, Map>::type> * (isSE ? std::tuple_element_t<I, Map>::SE_ID : std::tuple_element_t<I, Map>::AE_ID)) + ...);
		}

		template <typename Object, typename T, bool isSE, typename Map>
		constexpr uint64_t mapper()
		{
			return mapper_impl<Object, T, isSE, Map>(std::make_index_sequence<std::tuple_size_v<Map>>{});
		}

		template <typename Object, typename T, typename Map>
		constexpr uint64_t MapperSE()
		{
			return mapper<Object, T, true, Map>();
		}

		template <typename Object, typename T, typename Map>
		constexpr uint64_t MapperAE()
		{
			return mapper<Object, T, false, Map>();
		}
	}

	namespace NodeObject1Helper
	{
		using namespace MappingOffsets1;

		constexpr uint64_t read(const std::array<REL::ID, 1>& a)
		{
			return a[0].id();
		}

		using Map = std::tuple<
			Entry<CombatBehaviorAcquireItem, decltype(&CombatBehaviorContextAcquireWeapon::getAcquireWeapon), read(VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorAcquireItem_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorContextAcquireWeapon_CombatAcquireItemconst_CombatBehaviorContextAcquireWeapon____void____), 0>,
			Entry<CombatBehaviorCastConcentrationSpell, bool, read(VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorCastConcentrationSpell_bool_), 0>,
			Entry<CombatBehaviorCastImmediateSpell, bool, read(VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorCastImmediateSpell_bool_), 0>,
			Entry<CombatBehaviorFlee, float, read(VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorFlee_float_), 0>,
			Entry<CombatBehaviorIdle, float, read(VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorIdle_float_), 0>,
			Entry<CombatBehaviorLand, float, read(VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorLand_float_), 0>,
			Entry<CombatBehaviorLandNearby, float, read(VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorLandNearby_float_), 0>,
			Entry<CombatBehaviorRepeat, CombatBehaviorRepeat::FLAGS, read(VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorRepeat_CombatBehaviorRepeat__FLAGS_), 0>,
			Entry<CombatBehaviorRepeat, float, read(VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorRepeat_float_), 0>,
			Entry<CombatBehaviorWatchTarget, float, read(VTABLE_CombatBehaviorTreeNodeObject1_CombatBehaviorWatchTarget_float_), 0>>;

		template <typename Object, typename T>
		class Helper : public CombatBehaviorTreeNodeObject1Inlined<Object, T, MapperSE<Object, T, Map>(), MapperAE<Object, T, Map>()>
		{
			static constexpr uint64_t SE_ID = MapperSE<Object, T, Map>();
			static constexpr uint64_t AE_ID = MapperAE<Object, T, Map>();

			static_assert(SE_ID > 0);

		public:
			using CombatBehaviorTreeNodeObject1Inlined<Object, T, SE_ID, AE_ID>::CombatBehaviorTreeNodeObject1Inlined;
			using Helper_t = Helper<Object, T>;
		};
		static_assert(sizeof(CombatBehaviorTreeNodeObject1Inlined<void*, int, 0, 0>) == 0x30);
		static_assert(sizeof(CombatBehaviorTreeNodeObject1Inlined<void*, void*, 0, 0>) == 0x30);
	}

	// Sory, I minimized this macro code as much as I can
	// I have them in my txt file so I can generate any code with them, if necessary
#define DECLARE_SPECIALIZATION(O, T)                                                   \
	template <>                                                                        \
	class CombatBehaviorTreeNodeObject1<O, T> : public NodeObject1Helper::Helper<O, T> \
	{                                                                                  \
	public:                                                                            \
		using Helper_t::Helper_t;                                                      \
	}

	DECLARE_SPECIALIZATION(CombatBehaviorAcquireItem, decltype(&CombatBehaviorContextAcquireWeapon::getAcquireWeapon));
	DECLARE_SPECIALIZATION(CombatBehaviorCastConcentrationSpell, bool);
	DECLARE_SPECIALIZATION(CombatBehaviorCastImmediateSpell, bool);
	DECLARE_SPECIALIZATION(CombatBehaviorFlee, float);
	DECLARE_SPECIALIZATION(CombatBehaviorIdle, float);
	DECLARE_SPECIALIZATION(CombatBehaviorLand, float);
	DECLARE_SPECIALIZATION(CombatBehaviorLandNearby, float);
	DECLARE_SPECIALIZATION(CombatBehaviorRepeat, CombatBehaviorRepeat::FLAGS);
	DECLARE_SPECIALIZATION(CombatBehaviorRepeat, float);
	DECLARE_SPECIALIZATION(CombatBehaviorWatchTarget, float);

#undef DECLARE_SPECIALIZATION

	/*
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
			reinterpret_cast<std::uintptr_t*>(this)[0] = (RELOCATION_ID(SE_ID, AE_ID)).address();
		}

		using Base_t = CombatBehaviorTreeNodeObject2Inlined<Object, T, U, SE_ID, AE_ID>;
	};

	namespace MappingOffsets2
	{
		template <typename Object, typename T, typename U, uint64_t SE, uint64_t AE>
		struct Entry
		{
			using object = Object;
			using type1 = T;
			using type2 = U;
			static constexpr uint64_t SE_ID = SE;
			static constexpr uint64_t AE_ID = AE;
		};

		template <typename Object, typename T, typename U, bool isSE, typename Map, std::size_t... I>
		constexpr uint64_t mapper_impl(std::index_sequence<I...>)
		{
			return ((std::is_same_v<Object, typename std::tuple_element_t<I, Map>::object> * std::is_same_v<T, typename std::tuple_element_t<I, Map>::type1> * std::is_same_v<U, typename std::tuple_element_t<I, Map>::type2> * (isSE ? std::tuple_element_t<I, Map>::SE_ID : std::tuple_element_t<I, Map>::AE_ID)) + ...);
		}

		template <typename Object, typename T, typename U, bool isSE, typename Map>
		constexpr uint64_t mapper()
		{
			return mapper_impl<Object, T, U, isSE, Map>(std::make_index_sequence<std::tuple_size_v<Map>>{});
		}

		template <typename Object, typename T, typename U, typename Map>
		constexpr uint64_t MapperSE()
		{
			return mapper<Object, T, U, true, Map>();
		}

		template <typename Object, typename T, typename U, typename Map>
		constexpr uint64_t MapperAE()
		{
			return mapper<Object, T, U, false, Map>();
		}
	}

	namespace NodeObject2Helper
	{
		using namespace MappingOffsets2;

		constexpr uint64_t read(const std::array<REL::ID, 1>& a)
		{
			return a[0].id();
		}

		using Map = std::tuple<
			Entry<CombatBehaviorAcquireResource, BSFixedString, int, read(VTABLE_CombatBehaviorTreeNodeObject2_CombatBehaviorAcquireResource_BSFixedString_int_), 0>,
			Entry<CombatBehaviorFaceAngle, float, bool, read(VTABLE_CombatBehaviorTreeNodeObject2_CombatBehaviorFaceAngle_float_bool_), 0>,
			Entry<CombatBehaviorRepeat, float, CombatBehaviorRepeat::FLAGS, read(VTABLE_CombatBehaviorTreeNodeObject2_CombatBehaviorRepeat_float_CombatBehaviorRepeat__FLAGS_), 0>,
			Entry<CombatBehaviorSpawnParallel, uint32_t, CombatBehaviorParallel::FLAGS, read(VTABLE_CombatBehaviorTreeNodeObject2_CombatBehaviorSpawnParallel_unsignedint_CombatBehaviorParallel__FLAGS_), 0>>;

		template <typename Object, typename T, typename U>
		class Helper : public CombatBehaviorTreeNodeObject2Inlined<Object, T, U, MapperSE<Object, T, U, Map>(), MapperAE<Object, T, U, Map>()>
		{
			static constexpr uint64_t SE_ID = MapperSE<Object, T, U, Map>();
			static constexpr uint64_t AE_ID = MapperAE<Object, T, U, Map>();

			static_assert(SE_ID > 0);

		public:
			using CombatBehaviorTreeNodeObject2Inlined<Object, T, U, SE_ID, AE_ID>::CombatBehaviorTreeNodeObject2Inlined;
			using Helper_t = Helper<Object, T, U>;
		};
		static_assert(sizeof(CombatBehaviorTreeNodeObject2Inlined<void*, int, int, 0, 0>) == 0x30);
		static_assert(sizeof(CombatBehaviorTreeNodeObject2Inlined<void*, void*, void*, 0, 0>) == 0x38);
		static_assert(sizeof(CombatBehaviorTreeNodeObject2Inlined<void*, int, void*, 0, 0>) == 0x38);
	}

	template <typename Object, typename T, typename U>
	class CombatBehaviorTreeNodeObject2
	{
		~CombatBehaviorTreeNodeObject2() = delete;
	};

	// Sory, I minimized this macro code as much as I can
	// I have them in my txt file so I can generate any code with them, if necessary
#define DECLARE_SPECIALIZATION(O, T, U)                                                      \
	template <>                                                                              \
	class CombatBehaviorTreeNodeObject2<O, T, U> : public NodeObject2Helper::Helper<O, T, U> \
	{                                                                                        \
	public:                                                                                  \
		using Helper_t::Helper_t;                                                            \
	}

	DECLARE_SPECIALIZATION(CombatBehaviorAcquireResource, BSFixedString, int);
	DECLARE_SPECIALIZATION(CombatBehaviorFaceAngle, float, bool);
	DECLARE_SPECIALIZATION(CombatBehaviorRepeat, float, CombatBehaviorRepeat::FLAGS);
	DECLARE_SPECIALIZATION(CombatBehaviorSpawnParallel, uint32_t, CombatBehaviorParallel::FLAGS);

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

		using Base_t = CombatBehaviorTreeNodeObject3Inlined<Object, T, U, P, vftableID>;
	};

	template <typename Object, typename T, typename U, typename P>
	class CombatBehaviorTreeNodeObject3
	{
		~CombatBehaviorTreeNodeObject3() = delete;
	};

	template <>
	class CombatBehaviorTreeNodeObject3<CombatBehaviorAcquireResource, BSFixedString, int, CombatBehaviorAcquireResource::FLAG> : public CombatBehaviorTreeNodeObject3Inlined<CombatBehaviorAcquireResource, BSFixedString, int, CombatBehaviorAcquireResource::FLAG, VTABLE_CombatBehaviorTreeNodeObject3_CombatBehaviorAcquireResource_BSFixedString_int_CombatBehaviorAcquireResource__FLAG_>
	{
	public:
		using Base_t::Base_t;
	};
	static_assert(sizeof(CombatBehaviorTreeNodeObject3<CombatBehaviorAcquireResource, BSFixedString, int, CombatBehaviorAcquireResource::FLAG>) == 0x38);
}
