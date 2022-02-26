#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTSingleton.h"
#include "RE/H/hkpCollisionFilter.h"

namespace RE
{
	class bhkCollisionFilter : public hkpCollisionFilter
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCollisionFilter;

		[[nodiscard]] static bhkCollisionFilter* GetSingleton()
		{
			REL::Relocation<bhkCollisionFilter**> singleton{ REL::ID(514415) };
			return *singleton;
		}

		~bhkCollisionFilter() override;  // 00

		std::uint32_t GetNewSystemGroup()
		{
			auto systemGroup = nextSystemGroup + 1;
			if (nextSystemGroup == 65535) {
				systemGroup = 10;
			}
			nextSystemGroup = systemGroup;

		    return systemGroup;
		}

		// members
		std::uint32_t unk48;                     // 048
		std::uint32_t nextSystemGroup;           // 04C
		std::uint32_t bipedBitfields[32];        // 050
		std::uint32_t layerCollisionGroups[64];  // 0D0
		std::uint64_t layerBitfields[64];        // 1D0
		std::uint64_t triggerField;              // 3D0
		std::uint64_t sensorField;               // 3D8
		BSFixedString collisionLayerNames[64];   // 3E0
		std::uint8_t  unk5E0[256];               // 5E0
		BSFixedString collisionBoneNames[32];    // 6E0
	};
	static_assert(sizeof(bhkCollisionFilter) == 0x7E0);
}
