#pragma once

namespace RE
{
	class BSNavmesh;

	struct BSNavmeshInfo;

	class BSFastNavmeshEdgeHandle
	{
	public:
		// members
		BSNavmesh* navmesh;       // 00
		uint16_t   triangle_ind;  // 08
		uint8_t    padA[6];       // 0A
		int32_t    edge_ind;      // 10
		uint32_t   pad14;         // 14
	};
	static_assert(sizeof(BSFastNavmeshEdgeHandle) == 0x18);

	class BSNavmeshEdgeHandle
	{
		// members
		BSNavmeshInfo* navmeshInfo;   // 00
		uint16_t       triangle_ind;  // 08
		uint8_t        padA[6];       // 0A
		int32_t        edge_ind;      // 10
		uint32_t       pad14;         // 14
	};
	static_assert(sizeof(BSNavmeshEdgeHandle) == 0x18);
}
