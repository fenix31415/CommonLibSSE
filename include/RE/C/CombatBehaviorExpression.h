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
		template <typename U>
		CombatBehaviorExpression(U&& e) :
			e(std::forward<U>(e))
		{}

		template <typename T>
		operator T()
		{
			return e;
		}

		// members
		E e;
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
		template <typename T, typename... Params>
		CombatBehaviorMemberFunc(T&& f, Params&&... params) :
			f(std::forward<T>(f)), args(std::make_tuple(std::forward<Params>(params)...))
		{}

		template <typename T>
		operator T()
		{
			return std::apply([this](const auto&... args) { (CombatBehaviorMemberFunc__GetThis<C>.*f)(args...); }, args);
		}

		// members
		M                   f;
		std::tuple<Args...> args;
	};

	template <typename C, typename M>
	class CombatBehaviorMemberFunc<C, M>
	{
	public:
		template <typename T>
		CombatBehaviorMemberFunc(T&& f) :
			f(std::forward<T>(f))
		{}

		template <typename T>
		operator T()
		{
			return (CombatBehaviorMemberFunc__GetThis<C>.*f)();
		}

		// members
		M f;
	};
}
