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

	template <typename Context, uint64_t SE, uint64_t AE>
	class CombatBehaviorTreeCreateContextNodeWithCtor : public CombatBehaviorTreeNode
	{
	public:
		CombatBehaviorTreeCreateContextNodeWithCtor() = delete;

		static CombatBehaviorTreeNode* Create()
		{
			REL::Relocation<CombatBehaviorTreeNode*()> func{ RELOCATION_ID(SE, AE) };
			return func();
		}
	};

	template <typename Context>
	class CombatBehaviorTreeCreateContextNode : public CombatBehaviorTreeNode
	{
	public:
		~CombatBehaviorTreeCreateContextNode() = default;
		CombatBehaviorTreeCreateContextNode() = default;

		void Enter(CombatBehaviorThread* a_thread) override
		{
			a_thread->cur_context_sptr = a_thread->stack.Allocate<Context>();
			a_thread->stack.StoreData(a_thread->cur_context_sptr);
			a_thread->stack.Access<Context>(a_thread->cur_context_sptr.frame).EnterContext();
			a_thread->Descend();
		}

		void Exit(CombatBehaviorThread* thread) override
		{
			thread->cur_context_sptr = thread->stack.RemoveData<CombatBehaviorStack::ObjectPtr>();
			thread->stack.Deallocate<Context>();
		}

		void SaveGame(CombatBehaviorThread*, BGSSaveFormBuffer*) override
		{
			// TODO
			//Context::SaveGame(a_thread->GetCurrentStackObject<Context>(), a_buf);
		}

		void LoadGame(CombatBehaviorThread*, BGSLoadFormBuffer*) override
		{
			// TODO
		}

		bool Validate(CombatBehaviorTreeNode* node) const override
		{
			return CombatBehaviorBranch::Validate(node);
		}

		const BSFixedString& GetType() const override
		{
			static BSFixedString ans("CombatBehaviorTreeCreateContextNode");
			return ans;
		}
	};

#define DECLARE_SPECIALIZATION(T, SE, AE, size)                                                                    \
	template <>                                                                                                    \
	class CombatBehaviorTreeCreateContextNode<T> : public CombatBehaviorTreeCreateContextNodeWithCtor<T, SE, AE>   \
	{                                                                                                              \
	public:                                                                                                        \
		using CombatBehaviorTreeCreateContextNodeWithCtor<T, SE, AE>::CombatBehaviorTreeCreateContextNodeWithCtor; \
	};                                                                                                             \
	static_assert(sizeof(CombatBehaviorTreeCreateContextNode<T>) == size)
	
	DECLARE_SPECIALIZATION(CombatBehaviorContextAcquireWeapon, 46373, 0, 0x28);       // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorContextCloseMovement, 46753, 0, 0x28);       // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorContextCover, 48865, 0, 0x28);               // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorContextDodgeThreat, 46599, 0, 0x28);         // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorContextFindAttackLocation, 46985, 0, 0x28);  // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorContextFlankingMovement, 47164, 0, 0x28);    // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorContextFlee, 47449, 0, 0x28);                // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorContextHide, 47450, 0, 0x28);                // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorContextRangedMovement, 48484, 0, 0x28);      // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorContextSearch, 48572, 0, 0x28);              // I do not know for AE

#undef DECLARE_SPECIALIZATION

	template <typename Context, typename T>
	class CombatBehaviorTreeCreateContextNode1Base : public CombatBehaviorTreeNode
	{
	public:
		CombatBehaviorTreeCreateContextNode1Base(T arg1) :
			field1(std::move(arg1))
		{}

		// members
		T field1;  // 28
	};

	template <typename Context, typename T, uint64_t SE_ID, uint64_t AE_ID>
	class CombatBehaviorTreeCreateContextNode1Inlined : public CombatBehaviorTreeCreateContextNode1Base<Context, T>
	{
	public:
		CombatBehaviorTreeCreateContextNode1Inlined(T arg1) :
			CombatBehaviorTreeCreateContextNode1Base<Context, T>(std::forward<T>(arg1))
		{
			this->SetVftable(RELOCATION_ID(SE_ID, AE_ID));
		}
	};

	template <typename Object, typename T>
	class CombatBehaviorTreeCreateContextNode1
	{
		// Inherit from ContextNode and add fields, override functions
		CombatBehaviorTreeCreateContextNode1() = delete;
	};

	namespace MappingOffsetsContext1
	{
		template <typename Context, typename T, uint64_t SE, uint64_t AE>
		struct Entry
		{
			using context = Context;
			using type = T;
			static constexpr uint64_t SE_ID = SE;
			static constexpr uint64_t AE_ID = AE;
		};

		template <typename Context, typename T, bool isSE, typename Map, std::size_t... I>
		constexpr uint64_t mapper_impl(std::index_sequence<I...>)
		{
			return ((std::is_same_v<Context, typename std::tuple_element_t<I, Map>::context> * std::is_same_v<T, typename std::tuple_element_t<I, Map>::type> * (isSE ? std::tuple_element_t<I, Map>::SE_ID : std::tuple_element_t<I, Map>::AE_ID)) + ...);
		}

		template <typename Context, typename T, bool isSE, typename Map>
		constexpr uint64_t mapper()
		{
			return mapper_impl<Context, T, isSE, Map>(std::make_index_sequence<std::tuple_size_v<Map>>{});
		}

		template <typename Context, typename T, typename Map>
		constexpr uint64_t MapperSE()
		{
			return mapper<Context, T, true, Map>();
		}

		template <typename Context, typename T, typename Map>
		constexpr uint64_t MapperAE()
		{
			return mapper<Context, T, false, Map>();
		}
	}

	namespace ContextNode1Helper
	{
		using namespace MappingOffsetsContext1;

		constexpr uint64_t read(const std::array<REL::ID, 1>& a)
		{
			return a[0].id();
		}

		using Map = std::tuple<
			Entry<CombatBehaviorContextMagic, decltype(&CombatBehaviorEquipContext::GetCombatItem), read(VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorContextMagic_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____), read(VTABLE_CombatBehaviorTreeNode)>,          // I do now know for AE
			Entry<CombatBehaviorContextRanged, decltype(&CombatBehaviorEquipContext::GetCombatItem), read(VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorContextRanged_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____), read(VTABLE_CombatBehaviorTreeNode)>,        // I do now know for AE
			Entry<CombatBehaviorContextShout, decltype(&CombatBehaviorEquipContext::GetCombatItem), read(VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorContextShout_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____), read(VTABLE_CombatBehaviorTreeNode)>,          // I do now know for AE
			Entry<CombatBehaviorContextUsePotion, decltype(&CombatBehaviorEquipContext::GetCombatItem), read(VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorContextUsePotion_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____), read(VTABLE_CombatBehaviorTreeNode)>,  // I do now know for AE
			Entry<CombatBehaviorEquipContext, decltype(&CombatBehaviorThread::GetChildIndex), read(VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorEquipContext_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorThread_unsignedint_CombatBehaviorThread____void____), read(VTABLE_CombatBehaviorTreeNode)>                                                     // I do now know for AE
			>;

		template <typename Context, typename T>
		class Helper : public CombatBehaviorTreeCreateContextNode1Inlined<Context, T, MapperSE<Context, T, Map>(), MapperAE<Context, T, Map>()>
		{
			static constexpr uint64_t SE_ID = MapperSE<Context, T, Map>();
			static constexpr uint64_t AE_ID = MapperAE<Context, T, Map>();

			static_assert(SE_ID > 0);

		public:
			using CombatBehaviorTreeCreateContextNode1Inlined<Context, T, SE_ID, AE_ID>::CombatBehaviorTreeCreateContextNode1Inlined;
			using Helper_t = Helper<Context, T>;
		};
		static_assert(sizeof(CombatBehaviorTreeCreateContextNode1Inlined<void*, int, 0, 0>) == 0x30);
		static_assert(sizeof(CombatBehaviorTreeCreateContextNode1Inlined<void*, void*, 0, 0>) == 0x30);
	}

#define DECLARE_SPECIALIZATION(C, T, SE, AE, size)                                                                      \
	template <>                                                                                                         \
	class CombatBehaviorTreeCreateContextNode1<C, T> : public CombatBehaviorTreeCreateContextNode1Inlined<C, T, SE, AE> \
	{                                                                                                                   \
	public:                                                                                                             \
		using CombatBehaviorTreeCreateContextNode1Inlined<C, T, SE, AE>::CombatBehaviorTreeCreateContextNode1Inlined;   \
	};                                                                                                                  \
	static_assert(sizeof(CombatBehaviorTreeCreateContextNode1<C, T>) == size)

	DECLARE_SPECIALIZATION(CombatBehaviorContextMagic, decltype(&CombatBehaviorEquipContext::GetCombatItem), VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorContextMagic_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);          // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorContextRanged, decltype(&CombatBehaviorEquipContext::GetCombatItem), VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorContextRanged_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);        // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorContextShout, decltype(&CombatBehaviorEquipContext::GetCombatItem), VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorContextShout_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);          // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorContextUsePotion, decltype(&CombatBehaviorEquipContext::GetCombatItem), VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorContextUsePotion_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);  // I do not know for AE
	DECLARE_SPECIALIZATION(CombatBehaviorEquipContext, decltype(&CombatBehaviorThread::GetChildIndex), VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorEquipContext_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorThread_unsignedint_CombatBehaviorThread____void____[0].id(), VTABLE_CombatBehaviorTreeNode[0].id(), 0x30);                                                    // I do not know for AE

	template <typename Object, typename T, typename U>
	class CombatBehaviorTreeCreateContextNode2Base : public CombatBehaviorTreeNode
	{
	public:
		CombatBehaviorTreeCreateContextNode2Base(T arg1, U arg2) :
			field1(std::move(arg1)), field2(std::move(arg2))
		{}

		// members
		T field1;  // 28
		U field2;  // ??
	};

	template <typename Object, typename T, typename U, const std::array<REL::ID, 1>& vftableID>
	class CombatBehaviorTreeCreateContextNode2Inlined : public CombatBehaviorTreeCreateContextNode2Base<Object, T, U>
	{
	public:
		inline static constexpr auto VTABLE = vftableID;

		CombatBehaviorTreeCreateContextNode2Inlined(T arg1, U arg2) :
			CombatBehaviorTreeCreateContextNode2Base<Object, T, U>(std::forward<T>(arg1), std::forward<U>(arg2))
		{
			stl::emplace_vtable<CombatBehaviorTreeCreateContextNode2Inlined>(this);
		}

	protected:
		using Base_t = CombatBehaviorTreeCreateContextNode2Inlined<Object, T, U, vftableID>;
	};

	template <typename Object, typename T, typename U>
	class CombatBehaviorTreeCreateContextNode2
	{
		~CombatBehaviorTreeCreateContextNode2() = delete;  // Inherit from ContextNode and add fields, override functions
	};

	class CombatBehaviorContextBlock;
	template<>
	class CombatBehaviorTreeCreateContextNode2<CombatBehaviorContextBlock, decltype(&CombatBehaviorEquipContext::GetCombatItem), CombatBehaviorContextMelee::ATTACK_TYPE> : public CombatBehaviorTreeCreateContextNode2Inlined<CombatBehaviorContextBlock, decltype(&CombatBehaviorEquipContext::GetCombatItem), CombatBehaviorContextMelee::ATTACK_TYPE, VTABLE_CombatBehaviorTreeCreateContextNode2_CombatBehaviorContextBlock_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____CombatBehaviorContextMelee__ATTACK_TYPE_>
	{
	public:
		using Base_t::Base_t;
	};

	class CombatBehaviorContextMelee;
	template <>
	class CombatBehaviorTreeCreateContextNode2<CombatBehaviorContextMelee, decltype(&CombatBehaviorEquipContext::GetCombatItem), CombatBehaviorContextMelee::ATTACK_TYPE> : public CombatBehaviorTreeCreateContextNode2Inlined<CombatBehaviorContextBlock, decltype(&CombatBehaviorEquipContext::GetCombatItem), CombatBehaviorContextMelee::ATTACK_TYPE, VTABLE_CombatBehaviorTreeCreateContextNode2_CombatBehaviorContextMelee_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____CombatBehaviorContextMelee__ATTACK_TYPE_>
	{
	public:
		using Base_t::Base_t;
	};
}
