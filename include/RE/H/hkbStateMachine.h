#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkRefPtr.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkbBehaviorGraph.h"
#include "RE/H/hkbBindable.h"
#include "RE/H/hkbCondition.h"
#include "RE/H/hkbEvent.h"
#include "RE/H/hkbGenerator.h"
#include "RE/H/hkbTransitionEffect.h"

namespace RE
{
	struct hkMap64;
	class hkbStateChooser;

	class hkbStateListener : public hkReferencedObject
	{
	};
	static_assert(sizeof(hkbStateListener) == 0x10);

	class BSiStateTaggingUtils__BSiStateTaggingStateListener : public hkbStateListener
	{
	public:
		// members
		uint32_t iState;    // 10
		uint32_t priority;  // 14
	};
	static_assert(sizeof(BSiStateTaggingUtils__BSiStateTaggingStateListener) == 0x18);

	/// A state machine that transitions between generators.
	///
	/// An hkbStateMachine organizes a set of states, each of which has an hkbGenerator.  The state machine is
	/// itself an hkbGenerator.  When not in a transition, it simply generates a pose by calling the generator
	/// corresponding to the current state.  During a transition, it generates poses using an hkbTransitionEffect to
	/// generate the pose (typically by blending the generator being transitioned from with the one being transitioned
	/// to.
	class hkbStateMachine : public hkbGenerator
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbStateMachine;
		inline static constexpr auto VTABLE = VTABLE_hkbStateMachine;

		// Ways of setting the start state.
		enum class StartStateMode
		{
			// Set the start state to m_startStateId.
			kDefault = 0,
			// Set the start state from the variable whose index is m_syncVariableIndex.
			kSync = 1,
			// Set the start state to a random state.
			kRandom = 2,
			// Set the start state using m_startStateChooser.
			kChooser = 3
		};

		// How to deal with self-transitions (when the state machine is transitioned to while still active).
		enum class StateMachineSelfTransitionMode
		{
			// Stay in the current state.
			kNoTransition = 0,
			// Transition to the start state if a transition exists between the current state and the start state.
			kTransitionToStartState = 1,
			// Transition to the start state using a transition if there is one, or otherwise by abruptly changing states.
			kForceTransitionToStartState = 2
		};

		class TransitionInfoArray;

		class StateInfo : public hkbBindable
		{
		public:
			inline static constexpr auto RTTI = RTTI_hkbStateMachine__StateInfo;

			~StateInfo() override;  // 00

			// members
			hkArray<hkRefPtr<hkbStateListener>> listeners;           // 30
			void*                               unk40;               // 40 -- hkRefPtr
			void*                               eventPropertyArray;  // 48 -- hkRefPtr
			hkRefPtr<TransitionInfoArray>       transitions;         // 50 -- The transitions out of this state
			hkRefPtr<hkbGenerator>              generator;           // 58 -- The generator associated with this state
			hkStringPtr                         name;                // 60 -- The name of this state
			std::uint32_t                       id;                  // 68
			float                               probability;         // 6C
			bool                                enable;              // 70 -- Enable this state. Otherwise, it will be inaccessible.
			char                                pad71[7];            // 71
		};
		static_assert(sizeof(StateInfo) == 0x78);

		/// A time interval bounded by events or hkReals.
		///
		/// If you specify the interval using fixed times (hkReals), then the times correspond to
		/// the amount of local state machine time that has passed since the state was entered.
		/// If you specify the interval using events, then the interval begins whenever the
		/// m_enterEventId event is received and ends whenever the m_exitEventId is
		/// received.
		///
		/// An interval is bounded on both ends either by events or fixed times.  You can't use
		/// an event on one end and a fixed time on the other.
		///
		/// When using either interval specification, you should try to ensure that the interval
		/// is at least one frame long.  Otherwise, the interval may open and close again in one
		/// frame, and its effects may not be processed.
		///
		/// If either m_enterEventId or m_exitEventId are not EVENT_ID_NULL, then they define the interval.
		/// Otherwise (if both are EVENT_ID_NULL), the m_enterTime and m_exitTime will define the interval.
		struct TimeInterval
		{
			TimeInterval() :
				enterEventId(-1), exitEventId(-1), enterTime(0), exitTime(0) {}

			// members
			int32_t enterEventId;  // 00
			int32_t exitEventId;   // 04
			float   enterTime;     // 08
			float   exitTime;      // 0C
		};
		static_assert(sizeof(TimeInterval) == 0x10);

		struct TransitionInfo
		{
			enum class Flag : uint16_t
			{
				kNone = 0,
				FLAG_USE_TRIGGER_INTERVAL = 1 << 0,
				FLAG_USE_INITIATE_INTERVAL = 1 << 1,
				FLAG_UNINTERRUPTIBLE_WHILE_PLAYING = 1 << 2,
				FLAG_UNINTERRUPTIBLE_WHILE_DELAYED = 1 << 3,
				FLAG_DELAY_STATE_CHANGE = 1 << 4,
				FLAG_DISABLED = 1 << 5,
				FLAG_DISALLOW_RETURN_TO_PREVIOUS_STATE = 1 << 6,
				FLAG_DISALLOW_RANDOM_TRANSITION = 1 << 7,
				FLAG_DISABLE_CONDITION = 1 << 8,
				FLAG_ALLOW_SELF_TRANSITION_BY_TRANSITION_FROM_ANY_STATE = 1 << 9,
				FLAG_IS_GLOBAL_WILDCARD = 1 << 10,
				FLAG_IS_LOCAL_WILDCARD = 1 << 11,
				FLAG_FROM_NESTED_STATE_ID_IS_VALID = 1 << 12,
				FLAG_TO_NESTED_STATE_ID_IS_VALID = 1 << 13,
				FLAG_ABUT_AT_END_OF_FROM_GENERATOR = 1 << 14
			};
			using FLAGS = stl::enumeration<Flag, uint16_t>;

			TransitionInfo(hkbTransitionEffect* a_transition, int32_t a_eventId, uint32_t a_toStateId);

			// members

			/// 00 - The interval in which the event must be received for the transition to occur.
			///
			/// This is only used if (m_flags & FLAG_USE_TRIGGER_INTERVAL) is true.
			/// You should make sure that the interval is longer than your timestep
			/// (eg, 1/30 sec), or else the interval may be missed.
			TimeInterval triggerInterval;

			/// 10 - The interval in which the transition may begin.
			///
			/// This is only used if (m_flags & FLAG_USE_BEGIN_INTERVAL) is true.
			/// If the transition is activated outside of this interval, the transition
			/// will be delayed until the interval begins.
			/// You should make sure that the interval is longer than your timestep
			/// (eg, 1/30 sec), or else the interval may be missed.
			TimeInterval                  initiateInterval;
			hkRefPtr<hkbTransitionEffect> transition;         // 20
			hkRefPtr<hkbCondition>        condition;          // 28
			int32_t                       eventId;            // 30
			int32_t                       toStateId;          // 34
			int32_t                       fromNestedStateId;  // 38
			int32_t                       toNestedStateId;    // 3C
			uint16_t                      priority;           // 40
			FLAGS                         flags;              // 42
			uint32_t                      pad_44;             // 44
		};
		static_assert(sizeof(TransitionInfo) == 0x48);

		class TransitionInfoArray : public hkReferencedObject
		{
		public:
			inline static constexpr auto RTTI = RTTI_hkbStateMachine__TransitionInfoArray;

			~TransitionInfoArray() override;  // 00

			static TransitionInfoArray* Create()
			{
				auto ans = hk_malloc<TransitionInfoArray>();
				std::memset(ans, 0, sizeof(TransitionInfoArray));
				stl::emplace_vtable(ans);
				return ans;
			}

			// members
			hkArray<TransitionInfo> transitions;  // 10
		};
		static_assert(sizeof(TransitionInfoArray) == 0x20);

		~hkbStateMachine() override;  // 00

		/// Add a state given a state index, generator and name.
		///
		/// (not from the docs) If stateID is 0, adds new state to the start of the states array
		void addState(int32_t stateId, class hkbGenerator* generator, char const* name = nullptr);

		/// Add a state given a generator and name. returns the ID of the created state
		int32_t addState(hkbGenerator* generator, const char* name = nullptr);

		/// Add a transition and returns the newly created TransitionInfo.
		/// Note that the returned TransitionInfo is only valid until you
		/// call addTransition() again, because each call to addTransition()
		/// may reallocate the internal array of TransitionInfos.
		///
		/// \param eventId The ID of the event that triggers the transition.
		/// \param fromState The state from which this transition occurs.
		/// \param toState The state to which this transition goes.
		/// \param transition The transition to apply.
		/// \param condition The condition that must be true for the transition to occur.
		TransitionInfo* addTransition(int32_t eventId, int32_t fromStateId,
			int32_t toStateId, hkbTransitionEffect* transition = nullptr, hkbCondition* condition = nullptr)
		{
			auto& from_state = getStateInfoById(fromStateId);
			if (!from_state.transitions)
				from_state.transitions = hkRefPtr(hkbStateMachine::TransitionInfoArray::Create());

			return addTransitionInternal(eventId, toStateId, transition, condition, from_state.transitions->transitions);
		}

		/// add the transition
		TransitionInfo* addTransitionInternal(int32_t eventId, int32_t toStateId, hkbTransitionEffect* transition, hkbCondition* condition, hkArray<TransitionInfo>& transitions);

		uint16_t getCurrentStateIndex() const;

		hkbStateMachine* getNestedStateMachineClone(const hkbBehaviorGraph& behaviorGraph, int32_t stateIndex);

		hkbBehaviorGraph::StateMachineInfo* getNestedStateMachineInfo(const hkbBehaviorGraph& behaviorGraph, int32_t stateIndex);

		/// get the nested state machine template given the nested state machine index
		hkbStateMachine* getNestedStateMachineTemplate(const hkbBehaviorGraph& behaviorGraph, int32_t stateIndex);

		/// Get a state index given the state ID.
		int32_t getStateIndex(int32_t stateID) const;

		/// Get the StateInfo for a state given the id.
		StateInfo& getStateInfoById(int32_t stateId);

		/// Get the StateInfo (const) for a state given the id.
		const StateInfo& getStateInfoById(int32_t stateId) const;

		/// Get the StateInfo for a state given the index (in the range of 0 to getNumStates()-1).
		StateInfo& getStateInfoByIndex(int32_t stateIndex);

		/// Get the StateInfo (const) for a state given the index (in the range of 0 to getNumStates()-1).
		const StateInfo& getStateInfoByIndex(int32_t stateIndex) const;

		/// Return a state ID that has not been used yet (the smallest positive ID).
		///
		/// This method requires time linear in the number of states, so use it sparingly.
		/// It's better to choose the IDs yourself.
		int32_t getUnusedStateId() const;

		// members
		hkbEvent                                                       eventToSendWhenStateOrTransitionChanges;  // 048 - If non-null, this event is sent at the beginning and end of a transition, or once for an instantaneous transition.
		hkRefPtr<hkbStateChooser>                                      startStateChooser;                        // 060 - An object that chooses the start state
		std::int32_t                                                   startStateID;                             // 068
		std::int32_t                                                   returnToPreviousStateEventID;             // 06C - If this event is received, the state machine returns to the previous state if there is an appropriate transition defined.
		std::int32_t                                                   randomTransitionEventID;                  // 070 - If this event is received, the state machine chooses a random transition from among those available.
		std::int32_t                                                   transitionToNextHigherStateEventID;       // 074 - If the event is received, the state machine chooses a state with the id higher than the m_currentStateId and do a transition to that state.
		std::int32_t                                                   transitionToNextLowerStateEventID;        // 078 - If the event is received, the state machine chooses a state with the id lower than the m_currentStateId and do a transition to that state.
		std::int32_t                                                   syncVariableIndex;                        // 07C - We use variables to sync the start state of the state machine.
		std::int32_t                                                   currentStateID;                           // 080
		bool                                                           wrapAroundStateID;                        // 084
		std::int8_t                                                    maxSimultaneousTransitions;               // 085 - The number of transitions that can be active at once.
		stl::enumeration<StartStateMode, std::uint8_t>                 startStateMode;                           // 086 - How to set the start state.
		stl::enumeration<StateMachineSelfTransitionMode, std::uint8_t> selfTransitionMode;                       // 087 - How to deal with self-transitions (when the state machine is transitioned to while still active).
		bool                                                           isActive;                                 // 088 - Whether or not the state machine is active (activate() called but not deactivate()).
		std::uint8_t                                                   pad41;                                    // 089
		std::uint16_t                                                  pad42;                                    // 08A
		std::uint32_t                                                  pad44;                                    // 08C
		hkArray<StateInfo*>                                            states;                                   // 090 - The list of states
		hkRefPtr<TransitionInfoArray>                                  wildcardTransitions;                      // 0A0 - The list of transitions from any state (don't have a specific from state)
		hkMap64*                                                       stateIDToIndexMap;                        // 0A8 - State id to index map
		hkArray<hkRefVariant>                                          activeTransitions;                        // 0B0 - The list of currently active transitions
		hkArray<hkRefVariant>                                          transitionFlags;                          // 0C0 - Internal flags for the transitions of the current state
		hkArray<hkRefVariant>                                          wildcardTransitionFlags;                  // 0D0 - Internal flags for the wildcard transitions
		hkArray<hkRefVariant>                                          delayedTransitions;                       // 0E0 - This list consists of all transitions which have their initiate intervals flag or their abutment flag set.
		float                                                          timeInState;                              // 0F0 - How many seconds we've been in the current state
		float                                                          lastLocalTime;                            // 0F4 - What was the last local time from the syncInfo
		std::int32_t                                                   previousStateID;                          // 0F8
		std::int32_t                                                   nextStartStateIndexOverride;              // 0FC - The index of the next start state if overridden (-1 means not overridden)
		bool                                                           stateOrTransitionChanged;                 // 100 - Whether the state or transition has changed lately
		bool                                                           echoNextUpdate;                           // 101 - Whether or not to perform an echo next time update() is called.
		std::uint16_t                                                  currentStateIndexAndEntered;              // 102
		std::uint32_t                                                  pad0BC;                                   // 104
	};
	static_assert(sizeof(hkbStateMachine) == 0x108);
}
