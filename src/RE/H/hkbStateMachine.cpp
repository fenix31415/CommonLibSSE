#include "RE/H/hkbStateMachine.h"
#include "RE/H/hkMap.h"

namespace RE
{
	hkbStateMachine::TransitionInfo::TransitionInfo(hkbTransitionEffect* a_transition, int32_t a_eventId, uint32_t a_toStateId) :
		triggerInterval(), initiateInterval(), transition(a_transition), condition(nullptr), eventId(a_eventId), toStateId(a_toStateId), fromNestedStateId(), toNestedStateId(), priority(), flags()
	{
	}

	void hkbStateMachine::addState(int32_t stateId, hkbGenerator* generator, char const* stateName)
	{
		REL::Relocation<void(hkbStateMachine*, int32_t, hkbGenerator*, char const*)> func(RELOCATION_ID(58706, 0));  // I do not know for AE
		return func(this, stateId, generator, stateName);
	}

	int32_t hkbStateMachine::addState(RE::hkbGenerator* generator, const char* stateName)
	{
		int32_t stateID = getUnusedStateId();
		addState(stateID, generator, stateName);
		return stateID;
	}

	hkbStateMachine::TransitionInfo* hkbStateMachine::addTransitionInternal(int32_t eventId, int32_t toStateId, hkbTransitionEffect* transition, hkbCondition* condition, hkArray<TransitionInfo>& transitions)
	{
		REL::Relocation<decltype(&hkbStateMachine::addTransitionInternal)> func(RELOCATION_ID(58730, 0));  // I do not know for AE
		return func(this, eventId, toStateId, transition, condition, transitions);
	}

	int32_t hkbStateMachine::getStateIndex(int32_t stateID) const
	{
		if (stateID)
			return static_cast<int32_t>(stateIDToIndexMap->getWithDefault(stateID, -1));
		if (states.empty() || states[0]->id != 0)
			return -1;
		return 0;
	}

	hkbStateMachine::StateInfo& hkbStateMachine::getStateInfoById(int32_t stateId)
	{
		return *states[getStateIndex(stateId)];
	}

	const hkbStateMachine::StateInfo& hkbStateMachine::getStateInfoById(int32_t stateId) const
	{
		return *states[getStateIndex(stateId)];
	}

	hkbStateMachine::StateInfo& hkbStateMachine::getStateInfoByIndex(int32_t stateIndex)
	{
		return *states[stateIndex];
	}

	const hkbStateMachine::StateInfo& hkbStateMachine::getStateInfoByIndex(int32_t stateIndex) const
	{
		return *states[stateIndex];
	}

	int32_t hkbStateMachine::getUnusedStateId() const
	{
		int32_t i = 0;
		while (getStateIndex(i) != -1) ++i;
		return i;
	}
}
