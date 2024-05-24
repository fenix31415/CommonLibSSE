#include "RE/C/CombatCoverUtilities.h"

namespace RE
{
	namespace CombatCoverUtilities
	{
		bool CalculateCoverLocations(const CombatCoverEdge& edge, const CombatCoverSearchData& searchData, float pos, NiPoint3& ans1, NiPoint3& ans2)
		{
			using func_t = decltype(CalculateCoverLocations);
			REL::Relocation<func_t> func{ RELOCATION_ID(43412, 0) };  // I do not know for AE
			return func(edge, searchData, pos, ans1, ans2);
		}

		bool CheckCover(const NiPoint3& coverPos, const NiPoint3& threatPos)
		{
			using func_t = decltype(CheckCover);
			REL::Relocation<func_t> func{ RELOCATION_ID(43378, 0) };  // I do not know for AE
			return func(coverPos, threatPos);
		}

		bool CheckCoverEdge(const BSFastNavmeshEdgeHandle& handle, CombatCoverSearch* search)
		{
			using func_t = decltype(CheckCoverEdge);
			REL::Relocation<func_t> func{ RELOCATION_ID(43410, 0) };  // I do not know for AE
			return func(handle, search);
		}

		bool CheckCoverEdges(CombatNavmeshSearchNode* node, const CombatCoverSearch& search)
		{
			using func_t = decltype(CheckCoverEdges);
			REL::Relocation<func_t> func{ RELOCATION_ID(43408, 0) };  // I do not know for AE
			return func(node, search);
		}

		bool CheckCoverLocation(const CombatCoverEdge& edge, float pos, CombatCoverSearch* search)
		{
			using func_t = decltype(CheckCoverLocation);
			REL::Relocation<func_t> func{ RELOCATION_ID(43411, 0) };  // I do not know for AE
			return func(edge, pos, search);
		}

		bool CheckLedgeCover(const CombatCoverEdge& edge, const NiPoint3& coverPos, const NiPoint3& threatPos, float actorHeight)
		{
			using func_t = decltype(CheckLedgeCover);
			REL::Relocation<func_t> func{ RELOCATION_ID(43414, 0) };  // I do not know for AE
			return func(edge, coverPos, threatPos, actorHeight);
		}

		bool CheckThreatLOS(BSPathingLocation& loc, const BSTArray<NiPoint3>& threats)
		{
			using func_t = bool(BSPathingLocation&, const BSTArray<NiPoint3>&);
			REL::Relocation<func_t> func{ RELOCATION_ID(43413, 0) };  // I do not know for AE
			return func(loc, threats);
		}

		AITimeStamp GetDynamicCoverUpdateTimeStamp(const BSNavmesh* navmesh, uint16_t triangle_ind)
		{
			using func_t = decltype(GetDynamicCoverUpdateTimeStamp);
			REL::Relocation<func_t> func{ RELOCATION_ID(43415, 0) };  // I do not know for AE
			return func(navmesh, triangle_ind);
		}
	}

	namespace CombatCoverActorUtilities
	{
		bool CheckCoverSafe(const CombatCoverLocation& loc, const NiPoint3& threatPos)
		{
			using func_t = decltype(CheckCoverSafe);
			REL::Relocation<func_t> func{ RELOCATION_ID(43409, 0) };  // I do not know for AE
			return func(loc, threatPos);
		}
	}
}
