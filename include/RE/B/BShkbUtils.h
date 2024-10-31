#pragma once

#include "RE/B/BSAnimationGraphManager.h"
#include "RE/B/BSTArray.h"
#include "RE/H/hkbNode.h"

namespace RE
{
	class BGSGamebryoSequenceGenerator;
	class BSSynchronizedClipGenerator;
	class hkbBehaviorGraph;
	class hkbCharacter;
	class hkbClipGenerator;
	class hkbContext;
	class hkbGenerator;
	class hkbModifier;
	class hkbNode;
	class hkbPoseMatchingGenerator;
	class hkbStateMachine;

	namespace BShkbUtils
	{
		struct GraphInspectionConfiguration
		{
			// members
			float    time;                            // 00
			bool     clips;                           // 04 - Clip SynchronizedClip GamebryoSequence
			bool     state_machines;                  // 05
			bool     allow_behavior_and_states;       // 06
			bool     allow_inactive;                  // 07
			bool     modifiers;                       // 08
			bool     not_copy_variables;              // 09
			bool     inactive_manualselector_childs;  // 0A
			bool     should_echo;                     // 0B - set echo = 1 for hkbBlenderGenerator (before return)
			uint32_t pad0C;                           // 0C
		};
		static_assert(sizeof(GraphInspectionConfiguration) == 0x10);

		struct RecursionParameters
		{
			// members
			float    weight2;        // 00
			float    weight1;        // 04
			uint16_t inactive_mask;  // 08
			uint16_t field_A;        // 0A
		};
		static_assert(sizeof(RecursionParameters) == 0xC);

		struct StateRecursionData
		{
			// members
			hkbGenerator*     generator;    // 00
			hkbBehaviorGraph* graph;        // 08
			uint16_t          recursion_A;  // 10
			char              pad_12[6];    // 12
		};
		static_assert(sizeof(StateRecursionData) == 0x18);

		class GraphInspectionFunctor
		{
		public:
			virtual ~GraphInspectionFunctor() {}
			virtual bool call_posematchingGen(const hkbContext&, hkbPoseMatchingGenerator&, RecursionParameters&) { return true; }
			virtual bool call_syncGen(const hkbContext&, BSSynchronizedClipGenerator&, RecursionParameters&)
			{
				return true;
			}
			virtual bool call_someGen(const hkbContext&, BGSGamebryoSequenceGenerator&, RecursionParameters&) { return true; }
			virtual bool call_modifier(const hkbContext&, hkbModifier&, RecursionParameters&) { return true; }
			virtual bool call_clipGen(const hkbContext&, float, hkbClipGenerator&, RecursionParameters&)
			{
				return true;
			}
			virtual bool call_statemachine(const hkbContext&, hkbStateMachine&, RecursionParameters&,
				BSScrapArray<StateRecursionData>&)
			{
				return false;
			}
		};
		static_assert(sizeof(GraphInspectionFunctor) == 0x8);

		class GraphTraverser
		{
			static GraphTraverser* ctor(GraphTraverser* _this, GET_CHILDREN_FLAGS flags, hkbNode* root);

		public:
			struct Data
			{
				// members
				Data*    next_in_queue;      // 00 - intrusive pointer
				Data*    next_in_hashtable;  // 08 - intrusive pointer
				hkbNode* data;               // 10
			};
			static_assert(sizeof(Data) == 0x18);

			GraphTraverser(GET_CHILDREN_FLAGS flags, RE::hkbNode* root) { ctor(this, flags, root); }

			GraphTraverser(const GraphTraverser&) = delete;
			GraphTraverser& operator=(const GraphTraverser&) = delete;

			~GraphTraverser();

			hkbNode* Next();

			// members
			char               arena[0x40];  // 00 - BSTObjectArena<Data>
			char               buffer[0x8];  // 40 - AutoScrapBuffer
			Data*              queue;        // 48
			Data**             queue_end;    // 50
			GET_CHILDREN_FLAGS flags;        // 58
			uint32_t           pad5C;        // 5C
		};
		static_assert(sizeof(GraphTraverser) == 0x60);

		bool GetActiveClips(hkbCharacter* hkbChar, float time, BSScrapArray<BSAnimationGraphManager::ClipData>& ans);
		bool GraphInspection(const GraphInspectionConfiguration& cfg, hkbCharacter& hkbChar,
			GraphInspectionFunctor& functor);
	}
}
