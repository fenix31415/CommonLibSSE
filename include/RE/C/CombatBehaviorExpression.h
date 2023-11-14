#pragma once

#include "RE/C/CombatBehaviorController.h"
#include "RE/C/CombatBehaviorThread.h"
#include "RE/T/TLSData.h"

namespace RE
{
	template <typename E>
	class CombatBehaviorExpression
	{
	public:
		CombatBehaviorExpression(E&& e) :
			e(std::forward<E>(e))
		{}

		template <typename T>
		operator T()
		{
			return e;
		}

		// members
		E e;
	};

	struct OpNot
	{
		template <typename T>
		static bool apply(T&& arg)
		{
			return !arg;
		}
	};

	struct OpLessThan
	{
		template <typename T, typename U>
		static bool apply(T&& arg1, U&& arg2)
		{
			return static_cast<std::remove_reference_t<U>>(arg1) < arg2;
		}
	};

	struct OpGreaterThan
	{
		template <typename T, typename U>
		static bool apply(T&& arg1, U&& arg2)
		{
			return static_cast<std::remove_reference_t<U>>(arg1) > arg2;
		}
	};

	struct OpEquals
	{
		template <typename T, typename U>
		static bool apply(T&& arg1, U&& arg2)
		{
			return static_cast<std::remove_reference_t<U>>(arg1) == arg2;
		}
	};

	struct OpNotEquals
	{
		template <typename T, typename U>
		static bool apply(T&& arg1, U&& arg2)
		{
			return static_cast<std::remove_reference_t<U>>(arg1) != arg2;
		}
	};

	struct OpAnd
	{
		static bool apply(bool arg1, bool arg2)
		{
			return arg1 && arg2;
		}
	};

	struct OpOr
	{
		static bool apply(bool arg1, bool arg2)
		{
			return arg1 || arg2;
		}
	};

	template<typename F, typename Op>
	class CombatBehaviorUnaryExpression
	{
	public:
		template <typename T>
		CombatBehaviorUnaryExpression(T&& f) :
			f(std::forward<T>(f))
		{}

		template <typename T>
		operator T()
		{
			return Op::apply(f);
		}

		// members
		F f;
	};

	template <typename F1, typename F2, typename Op>
	class CombatBehaviorBinaryExpression
	{
	public:
		template <typename T, typename U>
		CombatBehaviorBinaryExpression(T&& f1, U&& f2) :
			f1(std::forward<T>(f1)), f2(std::forward<U>(f2))
		{}

		template <typename T>
		operator T()
		{
			return Op::apply(f1, f2);
		}

		// members
		F1 f1;
		F2 f2;
	};

	template <typename F, typename... Args>
	class CombatBehaviorFunc
	{
	public:
		template <typename T, typename... Params>
		CombatBehaviorFunc(T&& f, Params&&... params) :
			f(std::forward<T>(f)), args(std::make_tuple(std::forward<Params>(params)...))
		{}

		template <typename T>
		operator T()
		{
			return std::apply(f, args);
		}

		// members
		F                   f;
		std::tuple<Args...> args;
	};

	template <typename F>
	class CombatBehaviorFunc<F>
	{
	public:
		template <typename T>
		CombatBehaviorFunc(T&& f) :
			f(std::forward<T>(f))
		{}

		template <typename T>
		operator T()
		{
			return f();
		}

		// members
		F f;
	};

	template <typename T>
	T* CombatBehaviorMemberFunc__GetThis()
	{
		if constexpr (std::is_same_v<T, Actor>)
			return CombatBehaviorController::GetCurrentAttacker();
		else if constexpr (std::is_same_v<T, CombatGroup>)
			return CombatBehaviorController::GetCurrentCombatGroup();
		else if constexpr (std::is_same_v<T, CombatInventory>)
			return CombatBehaviorController::GetCurrentCombatInventory();
		else if constexpr (std::is_same_v<T, CombatState>)
			return CombatBehaviorController::GetCurrentCombatState();
		else
			return GetStaticTLSData()->combatAIThread->GetCurrentContext<T>();
	}

	template <typename C, typename M, typename... Args>
	class CombatBehaviorMemberFunc
	{
	public:
		CombatBehaviorMemberFunc(auto&& f, auto&&... params) :
			f(std::forward<decltype(f)>(f)), args(std::make_tuple(std::forward<decltype(params)>(params)...))
		{}

		template <typename T>
		operator T()
		{
			return std::apply([this](auto&&... args) { return (CombatBehaviorMemberFunc__GetThis<C>()->*f)(std::forward<decltype(args)>(args)...); }, args);
		}

		// members
		M                   f;
		std::tuple<Args...> args;
	};

	template <typename C, typename M>
	class CombatBehaviorMemberFunc<C, M>
	{
	public:
		CombatBehaviorMemberFunc(auto&& f) :
			f(std::forward<decltype(f)>(f))
		{}

		template <typename T>
		operator T()
		{
			return static_cast<T>((CombatBehaviorMemberFunc__GetThis<C>()->*f)());
		}

		// members
		M f;
	};
}
