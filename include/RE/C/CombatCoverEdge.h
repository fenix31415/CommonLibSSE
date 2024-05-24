#pragma once

#include "RE/B/BSFastNavmeshEdgeHandle.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class CombatCoverEdge
	{
	public:
		struct CombatCoverData
		{
			CombatCoverData() = default;
			CombatCoverData(const BSFastNavmeshEdgeHandle& handle);

			float GetHeight() const;

			// members
			uint8_t cover_height;  // 00 -- 15 -> inf
			bool    isLeft;        // 01
			bool    field_2;       // 02
			bool    isCoverHalf;   // 03
		};
		static_assert(sizeof(CombatCoverData) == 0x4);

		struct CombatNavmeshCoverEdge
		{
			// members
			BSFastNavmeshEdgeHandle handle;       // 00
			uint32_t                key;          // 18
			NiPoint3                vertexes[2];  // 1C
			uint32_t                pad34;        // 34
		};
		static_assert(sizeof(CombatNavmeshCoverEdge) == 0x38);

		CombatCoverEdge() = delete;
		CombatCoverEdge(const CombatCoverEdge& other) = default;
		CombatCoverEdge(const BSFastNavmeshEdgeHandle& handle);
		CombatCoverEdge(const BSFastNavmeshEdgeHandle& handle, const CombatCoverData& a_coverData);

		void Initialize(const BSFastNavmeshEdgeHandle& handle);

		// members
		CombatCoverData     coverData;    // 00
		uint32_t            pad4;         // 04
		BSNavmeshEdgeHandle handle;       // 08
		uint32_t            coverKey;     // 20
		NiPoint3            vertexes[2];  // 24
		NiPoint3            normal;       // 3C
		NiPoint3            edgeVector;   // 48
		float               length;       // 54
	};
	static_assert(sizeof(CombatCoverEdge) == 0x58);
}
