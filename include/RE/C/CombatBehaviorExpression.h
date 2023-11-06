#pragma once

namespace RE
{
	template <typename E>
	class CombatBehaviorExpression
	{
	public:
		template <typename T>
		operator T()
		{
			return e;
		}

		// members
		E e;
	};

	template <typename F, typename A1>
	class CombatBehaviorFunc1
	{
	public:
		template <typename T>
		operator T()
		{
			return f(arg1);
		}

		// members
		F                            f;
		CombatBehaviorExpression<A1> arg1;
	};

	template <typename F, typename A1, typename A2>
	class CombatBehaviorFunc2
	{
	public:
		template <typename T>
		operator T()
		{
			return f(arg1, arg2);
		}

		// members
		F                            f;
		CombatBehaviorExpression<A1> arg1;
		CombatBehaviorExpression<A2> arg2;
	};

	template <typename C, typename M>
	class CombatBehaviorMemberFunc
	{
	public:
		// return (CombatController::GetCurrent##C##()->*f)()
		//template <typename T>
		//operator T()
		//{
		//
		//}

		// members
		M f;
	};
}
