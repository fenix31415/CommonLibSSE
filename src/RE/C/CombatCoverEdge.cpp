#include "RE/C/CombatCoverEdge.h"

namespace RE
{
	CombatCoverEdge::CombatCoverData::CombatCoverData(const BSFastNavmeshEdgeHandle& handle)
	{
		using func_t = CombatCoverData*(CombatCoverData*, const BSFastNavmeshEdgeHandle&);
		REL::Relocation<func_t> func{ RELOCATION_ID(43373, 0) };  // I do not know for AE
		func(this, handle);
	}

	float CombatCoverEdge::CombatCoverData::GetHeight() const
	{
		// not in AddressLibrary
		if (cover_height == 15)
			return std::numeric_limits<float>::max();
		else
			return cover_height * 16.0f;
	}

	CombatCoverEdge::CombatCoverEdge(const BSFastNavmeshEdgeHandle& a_handle)
	{
		using func_t = CombatCoverEdge*(CombatCoverEdge*, const BSFastNavmeshEdgeHandle&);
		REL::Relocation<func_t> func{ RELOCATION_ID(43376, 0) };  // I do not know for AE
		func(this, a_handle);
	}

	CombatCoverEdge::CombatCoverEdge(const BSFastNavmeshEdgeHandle& a_handle, const CombatCoverData& a_coverData)
	{
		using func_t = CombatCoverEdge*(CombatCoverEdge*, const BSFastNavmeshEdgeHandle&, const CombatCoverData&);
		REL::Relocation<func_t> func{ RELOCATION_ID(43377, 0) };  // I do not know for AE
		func(this, a_handle, a_coverData);
	}

	void CombatCoverEdge::Initialize(const BSFastNavmeshEdgeHandle& a_handle)
	{
		using func_t = decltype(&CombatCoverEdge::Initialize);
		REL::Relocation<func_t> func{ RELOCATION_ID(43381, 0) };  // I do not know for AE
		return func(this, a_handle);
	}
}
