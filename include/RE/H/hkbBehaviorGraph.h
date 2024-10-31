#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkMap.h"
#include "RE/H/hkRefVariant.h"
#include "RE/H/hkbGenerator.h"

namespace RE
{
	class hkbBehaviorGraphData;
	class hkbStateMachine;
	class hkbVariableValueSet;

	/// Information about a node in a behavior graph.
	struct hkbNodeInfo
	{
		void*    unk00;         //00
		int64_t  unk08;         //08
		int64_t  unk10;         //10
		void*    unk18;         //18
		char     unk20[48];     //20
		hkbNode* nodeTemplate;  //50
		hkbNode* nodeClone;     //58
		hkbNode* behavior;      //60
		int64_t  unk68;         //68
		int64_t  unk70;         //70
		int64_t  unk78;         //78
		int64_t  unk80;         //80
		bool     unk88;         //88
	};
	static_assert(sizeof(hkbNodeInfo) == 0x90);

	using NodeList = hkArray<hkbNodeInfo>;

	class hkbSymbolIdMap : public RE::hkReferencedObject
	{
	public:
		// members
		hkArray<uint32_t> array;  // 10
		hkMap64           map;    // 20
	};
	static_assert(sizeof(hkbSymbolIdMap) == 0x30);

	class hkbBehaviorGraph : public hkbGenerator
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbBehaviorGraph;
		inline static constexpr auto VTABLE = VTABLE_hkbBehaviorGraph;

		// How do deal with variables when the behavior is inactive
		enum class VariableMode
		{
			/// Throw away the variable values and memory on deactivate().
			/// In this mode, variable memory is allocated and variable values are
			/// reset each time activate() is called.
			kDiscardWhenActive = 0,

			/// Don't discard the variable memory on deactivate(), and don't
			/// reset the variable values on activate() (except the first time).
			kMaintainValuesWhenInactive = 1,
		};

		/// Stores the relationships between state machines and which behavior graph contains each state machine.
		struct StateMachineInfo
		{
			// members
			hkbStateMachine*  stateMachineTemplate;          // 00 - A pointer to a node which is a state machine.
			uint64_t          field08;                       // 08
			uint64_t          field10;                       // 10
			hkMap64*          eventToGlobalTransitionMap;    // 18 - A map from events to global transition. The index of the transition in hkbStateMachine::m_wildcardTransitions is stored.
			hkArray<int32_t>* childStateMachineInfoIndices;  // 20 - The child state machine info indices
			uint32_t          field28;                       // 28
			uint32_t          field2C;                       // 2C
		};
		static_assert(sizeof(StateMachineInfo) == 0x30);

		struct GlobalTransitionData : public hkReferencedObject
		{
			// members
			StateMachineInfo* stateMachineInfos;               // 10 - All the state machines in the entire behavior graph.
			uint64_t          field18;                         // 18
			uint64_t          field20;                         // 20
			uint64_t          field28;                         // 28
			hkMap64           stateMachineTemplateToIndexMap;  // 30 - A map from state machines to indices in the m_stateMachineInfos
			hkMap64           eventToStateMachineInfoIndices;  // 40 - A map from event IDs to arrays of indices into the m_stateMachineInfos. This map tells us which state machines have global wildcard transitions defined for each event ID.
			uint64_t          field50;                         // 50
			uint64_t          field58;                         // 58
		};
		static_assert(sizeof(GlobalTransitionData) == 0x60);

		static const hkClass& staticClass()
		{
			return *REL::Relocation<hkClass*>(REL::ID(521003));
		}

		~hkbBehaviorGraph() override;  // 00

		// override (hkbNode)
		hkClass* GetClassType() const override;                                                                     // 01
		void     CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;  // 02
		void     Activate(const hkbContext& a_context) override;                                                    // 04
		void     Update(const hkbContext& a_context, float a_timestep) override;                                    // 05
		void     handleEvent(const hkbContext& ctx, hkbEvent& event) override;                                      // 06
		void     Deactivate(const hkbContext& a_context) override;                                                  // 07
		void     getChildren(GET_CHILDREN_FLAGS flags, ChildrenInfo& ans) override;                                 // 09
		void     cloneNode() override;                                                                              // 0C
		bool     isGraph() const override;                                                                          // 16 - { return 1; }

		// override (hkbGenerator)
		void generate(const hkbContext& a_context) const override;              // 17
		bool canRecycleOutput() const override;                                 // 18 - { return 1; }
		void updateSync(const hkbContext& a_context, void* nodeInfo) override;  // 19

		hkbNode* getNodeClone(hkbNode* nodeTemplate) const;
		hkbNode* getNodeTemplate(hkbNode* nodeClone) const;

		// members
		stl::enumeration<VariableMode, std::uint8_t> variableMode;                     // 048 - How do deal with variables when the behavior is inactive
		std::uint8_t                                 pad49;                            // 049
		std::uint16_t                                pad4A;                            // 04A
		std::uint32_t                                pad4C;                            // 04C
		hkArray<hkRefVariant>                        uniqueIDPool;                     // 050 - A pool of unique IDs to be used for hkbTransitionEffects (all other nodes have static unique IDs).
		hkRefVariant                                 idToStateMachineTemplateMap;      // 060 - A map from ids to state machine templates. This is used for looking up global transitions.
		hkArray<hkRefVariant>                        mirroredExternalIDMap;            // 068 - The mapper between external Id's and mirrored external Id's
		hkRefVariant                                 pseudoRandomGenerator;            // 078
		hkRefPtr<hkbGenerator>                       rootGenerator;                    // 080
		hkRefPtr<hkbBehaviorGraphData>               data;                             // 088 - The constant data associated with the behavior
		hkRefVariant                                 rootGeneratorClone;               // 090 - If this is a clone, this pointer points to the original root of the cloned behavior graph.
		NodeList*                                    activeNodes;                      // 098 - The current active nodes in the behavior.
		hkRefVariant                                 activeNodeTemplateToIndexMap;     // 0A0
		hkRefVariant                                 activeNodesChildrenIndices;       // 0A8
		hkRefPtr<GlobalTransitionData>               globalTransitionData;             // 0B0 - A member for storing all the information required for doing global transitions.
		hkRefPtr<hkbSymbolIdMap>                     eventIDMap;                       // 0B8 - A mapper between internal event IDs and external event IDs
		hkRefPtr<hkbSymbolIdMap>                     attributeIDMap;                   // 0C0 - A mapper between internal attribute IDs and external attribute IDs.
		hkRefPtr<hkbSymbolIdMap>                     variableIDMap;                    // 0C8 - A mapper between internal variable IDs and external variable IDs.
		hkRefPtr<hkbSymbolIdMap>                     characterPropertyIDMap;           // 0D0 - A mapper between internal character property IDs and those in the character (external).
		hkbVariableValueSet*                         variableValueSet;                 // 0D8 - The current value of the behavior variables.
		hkMap64*                                     nodeTemplateToCloneMap;           // 0E0 - A map from template nodes to cloned nodes.
		hkMap64*                                     nodeCloneToTemplateMap;           // 0E8
		hkRefVariant                                 stateListenerTemplateToCloneMap;  // 0F0 - A map from template state listeners to clones.
		hkRefVariant                                 nodePartitionInfo;                // 0F8
		std::int32_t                                 numIntermediateOutputs;           // 100 - The number of intermediate outputs needed to process the partitioned graph.
		std::uint32_t                                pad104;                           // 104
		hkArray<hkRefVariant>                        jobs;                             // 108 - The jobs for partition that can run on SPUs.
		hkArray<hkRefVariant>                        allPartitionMemory;               // 118 - The memory required for all the partitions.
		std::int16_t                                 numStaticNodes;                   // 128
		std::int16_t                                 nextUniqueID;                     // 12A - The next unique ID to use if m_uniqueIdPool is empty.
		bool                                         isActive;                         // 12C - Whether or not the behavior has been activated.
		bool                                         isLinked;                         // 12D - Whether or not the behavior graph has been linked (see hkbBehaviorLinkingUtils).
		bool                                         updateActiveNodes;                // 12E - If this is set to true then we update the active nodes at the next opportunity.
		bool                                         stateOrTransitionChanged;         // 12F - If this is set to true then we need to go through the nodes and process any nodes whose m_enable has changed.
	};
	static_assert(sizeof(hkbBehaviorGraph) == 0x130);
}
