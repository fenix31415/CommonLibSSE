#pragma once

#include "RE/B/BSAnimationGraphManager.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class BSSynchronizedClipGenerator;
	class hkbBehaviorGraph;
	class hkbBlenderGenerator;
	class hkbCharacter;
	class hkbClipGenerator;
	class hkbContext;
	class hkbGenerator;
	class hkbModifier;
	class hkbNode;
	class hkbStateMachine;

	namespace BShkbUtils
	{
		struct GraphInspectionConfiguration
		{
			// members
			float    mb_time;         // 00
			bool     generators;      // 04
			bool     state_machines;  // 05
			bool     field6;          // 06
			bool     field7;          // 07
			bool     mb_modifiers;    // 08
			bool     field9;          // 09
			bool     fieldA;          // 0A
			bool     fieldB;          // 0B
			uint32_t fieldC;          // 0C
		};
		static_assert(sizeof(GraphInspectionConfiguration) == 0x10);

		struct RecursionParameters
		{
			// members
			float    field_0;    // 00
			float    pos_scale;  // 04
			uint16_t field_8;    // 08
			uint16_t field_A;    // 0A
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
			virtual bool call_blenderGen(const hkbContext&, hkbBlenderGenerator&, RecursionParameters&) { return true; }
			virtual bool call_syncGen(const hkbContext&, BSSynchronizedClipGenerator&, RecursionParameters&)
			{
				return true;
			}
			virtual bool call_someGen(const hkbContext&, hkbGenerator&, RecursionParameters&) { return true; }
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
			static GraphTraverser* ctor(GraphTraverser* _this, int flags, hkbNode* root);

		public:
			GraphTraverser(int flags, RE::hkbNode* root) { ctor(this, flags, root); }

			GraphTraverser(const GraphTraverser&) = delete;
			GraphTraverser& operator=(const GraphTraverser&) = delete;

			~GraphTraverser();

			hkbNode* Next();

			// members
			char arena[0x40];     // 00
			char buffer[0x8];     // 40
			char field_48[0x18];  // 48
		};
		static_assert(sizeof(GraphTraverser) == 0x60);

		bool GetActiveClips(hkbCharacter* hkbChar, float time, BSScrapArray<BSAnimationGraphManager::ClipData>& ans);
		bool GraphInspection(const GraphInspectionConfiguration& cfg, hkbCharacter& hkbChar,
			GraphInspectionFunctor& functor);
	}
}
