#include "RE/B/BShkbUtils.h"

namespace RE {
	namespace BShkbUtils
	{
		bool GetActiveClips(hkbCharacter* hkbChar, float time, BSScrapArray<BSAnimationGraphManager::ClipData>& ans)
		{
			using func_t = decltype(GetActiveClips);
			REL::Relocation<func_t> func{ RELOCATION_ID(62935, 0) };  // I do not know for AE
			return func(hkbChar, time, ans);
		}

		bool GraphInspection(const GraphInspectionConfiguration& cfg, hkbCharacter& hkbChar, GraphInspectionFunctor& functor)
		{
			using func_t = decltype(GraphInspection);
			REL::Relocation<func_t> func{ RELOCATION_ID(64198, 0) };  // I do not know for AE
			return func(cfg, hkbChar, functor);
		}

		GraphTraverser* GraphTraverser::ctor(GraphTraverser* _this, int flags, hkbNode* root)
		{
			using func_t = decltype(&GraphTraverser::ctor);
			REL::Relocation<func_t> func{ RELOCATION_ID(62942, 0) };  // I do not know for AE
			return func(_this, flags, root);
		}

		GraphTraverser::~GraphTraverser()
		{
			using funcs_t = void(void*);
			{
				REL::Relocation<funcs_t> func{ RELOCATION_ID(66854, 0) };  // I do not know for AE
				func(buffer);
			}
			{
				REL::Relocation<funcs_t> func{ RELOCATION_ID(32072, 0) };  // I do not know for AE
				func(arena);
			}
		}

		hkbNode* GraphTraverser::Next()
		{
			using func_t = decltype(&GraphTraverser::Next);
			REL::Relocation<func_t> func{ RELOCATION_ID(62944, 0) };  // I do not know for AE
			return func(this);
		}
	}
}
