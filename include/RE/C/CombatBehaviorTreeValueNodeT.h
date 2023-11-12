#pragma once

#include "RE/A/Actor.h"
#include "RE/C/CombatBehaviorContextMagic.h"
#include "RE/C/CombatBehaviorContextRangedMovement.h"
#include "RE/C/CombatBehaviorExpression.h"
#include "RE/C/CombatBehaviorTreeUtils.h"
#include "RE/C/CombatBehaviorTreeValueNode.h"
#include "RE/C/CombatController.h"
#include "RE/C/CombatGroup.h"
#include "RE/C/CombatState.h"
#include "RE/T/TESCombatStyle.h"

namespace RE
{
	template<typename T, typename Expr>
	class CombatBehaviorTreeValueNodeTImpl : public CombatBehaviorTreeValueNode<T>
	{
	public:
		template<typename U>
		CombatBehaviorTreeValueNodeTImpl(U&& expr) :
			expr(std::forward<U>(expr)) {}

		T GetValue() override
		{
			return static_cast<T>(expr);
		}

		// members
		Expr expr;  // 30
	};

	template <typename T, typename Expr>
	class CombatBehaviorTreeValueNodeT : public CombatBehaviorTreeValueNodeTImpl<T, Expr>
	{
	public:
		using CombatBehaviorTreeValueNodeTImpl<T, Expr>::CombatBehaviorTreeValueNodeTImpl;
	};

	// inlined specs

#define DECLARE_SPECIALIZATION(T, Expr, size, SE_ARR, AE_ARR)                                      \
	template <>                                                                                    \
	class CombatBehaviorTreeValueNodeT<T, Expr> : public CombatBehaviorTreeValueNodeTImpl<T, Expr> \
	{                                                                                              \
	public:                                                                                        \
		template <typename U>                                                                      \
		CombatBehaviorTreeValueNodeT(U&& expr) :                                                   \
			CombatBehaviorTreeValueNodeTImpl<T, Expr>(std::forward<U>(expr))                       \
		{                                                                                          \
			this->SetVftable(RELOCATION_ID((SE_ARR)[0].id(), (AE_ARR)[0].id()));                   \
		}                                                                                          \
	};                                                                                             \
	static_assert(sizeof(CombatBehaviorTreeValueNodeT<T, Expr>) == (size))

#define COMMA ,
	DECLARE_SPECIALIZATION(unsigned int, int, 0x38, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_int_, 0);
	DECLARE_SPECIALIZATION(unsigned int, MagicSystem::CastingType, 0x38, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_MagicSystem__CastingType_, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatInventoryItem::TYPE, 0x38, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatInventoryItem__TYPE_, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorUnaryExpression<CombatBehaviorMemberFunc<CombatState COMMA decltype(&CombatState::QTargetLost)> COMMA OpNot>>, 0x38, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorUnaryExpression_CombatBehaviorMemberFunc_CombatState_bool_CombatState____void___OpNot___, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorUnaryExpression<CombatBehaviorMemberFunc<CombatBehaviorEquipContext COMMA decltype(&CombatBehaviorEquipContext::CheckEquipmentChanged)> COMMA OpNot>>, 0x38, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorUnaryExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_bool_CombatBehaviorEquipContext____void___OpNot___, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorUnaryExpression<CombatBehaviorMemberFunc<CombatController COMMA decltype(&CombatController::CheckCombatArea) COMMA CombatBehaviorTreeUtils::CombatBehaviorAttacker> COMMA OpNot>>, 0x40, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorUnaryExpression_CombatBehaviorMemberFunc1_CombatController_bool_CombatController____Actor__CombatBehaviorTree__CombatBehaviorAttacker__OpNot___, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorMemberFunc<CombatState COMMA decltype(&CombatState::CheckShouldHide)>>, 0x38, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatState_bool_CombatState____void____, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorMemberFunc<CombatGroup COMMA decltype(&CombatGroup::IsSearching)>>, 0x38, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatGroup_bool_CombatGroup____void____, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorMemberFunc<CombatBehaviorEquipContext COMMA decltype(&CombatBehaviorEquipContext::GetEquipmentType)>>, 0x38, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_CombatInventoryItem__TYPE_CombatBehaviorEquipContext____void____, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorMemberFunc<CombatBehaviorContextRangedMovement COMMA decltype(&CombatBehaviorContextRangedMovement::CheckOutOfRange)>>, 0x38, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorContextRangedMovement_bool_CombatBehaviorContextRangedMovement____void____, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorMemberFunc<CombatBehaviorContextMagic COMMA decltype(&CombatBehaviorContextMagic::GetCastingType)>>, 0x38, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorContextMagic_MagicSystem__CastingType_CombatBehaviorContextMagic____void____, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorMemberFunc<CombatBehaviorContextCloseMovement COMMA decltype(&CombatBehaviorContextCloseMovement::CheckOutOfRange)>>, 0x38, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorContextCloseMovement_bool_CombatBehaviorContextCloseMovement____void____, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorMemberFunc<Actor COMMA decltype(&Actor::CanStrafe)>>, 0x38, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorMemberFunc_Actor_bool_IMovementState____void____, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorMemberFunc<Actor COMMA decltype(&Actor::CanFly)>>, 0x40, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorMemberFunc_Actor_bool_Actor____void____, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorMemberFunc<Actor COMMA decltype(&ActorState::IsFlying)>>, 0x38, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorMemberFunc_Actor_bool_ActorState____void____, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorMemberFunc<TESCombatStyle COMMA decltype(&TESCombatStyle::HasFlag) COMMA TESCombatStyle::FLAG>>, 0x40, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorMemberFunc1_TESCombatStyle_bool_TESCombatStyle____unsignedint__TESCombatStyle__FLAG___, 0);
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorBinaryExpression<CombatBehaviorUnaryExpression<CombatBehaviorMemberFunc<CombatState COMMA decltype(&CombatState::QTargetLost)> COMMA OpNot> COMMA CombatBehaviorExpression<CombatBehaviorBinaryExpression<CombatBehaviorFunc<float (*)(TESObjectREFR* COMMA TESObjectREFR*) COMMA CombatBehaviorTreeUtils::CombatBehaviorAttacker COMMA CombatBehaviorTreeUtils::CombatBehaviorTarget> COMMA float COMMA OpLessThan>> COMMA OpAnd>>, 0x50, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorBinaryExpression_CombatBehaviorUnaryExpression_CombatBehaviorMemberFunc_CombatState_bool_CombatState____void___OpNot__CombatBehaviorExpression_CombatBehaviorBinaryExpression_CombatBehaviorFunc2_float___TESObjectREFR_TESObjectREFR__CombatBehaviorTree__CombatBehaviorAttacker_CombatBehaviorTree__CombatBehaviorTarget__float_OpLessThan___OpAnd___, 0);
	// TODO: size is actually 0x48
	DECLARE_SPECIALIZATION(unsigned int, CombatBehaviorExpression<CombatBehaviorBinaryExpression<CombatBehaviorMemberFunc<CombatState COMMA decltype(&CombatState::CheckShouldFlee)> COMMA CombatBehaviorExpression<CombatBehaviorMemberFunc<Actor COMMA decltype(&Actor::IsBleedingOut)>> COMMA OpOr>>, 0x40, RE::VTABLE_CombatBehaviorTreeValueNodeT_unsignedint_CombatBehaviorExpression_CombatBehaviorBinaryExpression_CombatBehaviorMemberFunc_CombatState_bool_CombatState____void___CombatBehaviorExpression_CombatBehaviorMemberFunc_Actor_bool_Actor____void____OpOr___, 0);
#undef COMMA

#undef DECLARE_SPECIALIZATION
}
