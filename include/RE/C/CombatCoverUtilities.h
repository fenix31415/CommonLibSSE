#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class BSFastNavmeshEdgeHandle;
	class BSNavmesh;
	class BSPathingLocation;
	class CombatCoverEdge;
	class CombatCoverLocation;
	class CombatCoverSearch;
	class CombatCoverSearchData;
	class CombatNavmeshSearchNode;
	class NiPoint3;

	namespace CombatCoverUtilities
	{
		bool        CalculateCoverLocations(const CombatCoverEdge& edge, const CombatCoverSearchData& searchData, float pos, NiPoint3& ans1, NiPoint3& ans2);
		bool        CheckCover(const NiPoint3& coverPos, const NiPoint3& threatPos);
		bool        CheckCoverEdge(const BSFastNavmeshEdgeHandle& handle, CombatCoverSearch* search);
		bool        CheckCoverEdges(CombatNavmeshSearchNode* node, const CombatCoverSearch& search);
		bool        CheckCoverLocation(const CombatCoverEdge& edge, float pos, CombatCoverSearch* search);
		bool        CheckLedgeCover(const CombatCoverEdge& edge, const NiPoint3& coverPos, const NiPoint3& threatPos, float actorHeight);
		bool        CheckThreatLOS(BSPathingLocation& loc, const BSTArray<NiPoint3>& threats);
		AITimeStamp GetDynamicCoverUpdateTimeStamp(const BSNavmesh* navmesh, uint16_t triangle_ind);
	}

	namespace CombatCoverActorUtilities
	{
		bool CheckCoverSafe(const CombatCoverLocation& loc, const NiPoint3& threatPos);
	}
}
