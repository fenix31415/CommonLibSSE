#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BGSTextureSet;
	class NiAVObject;
	class NiNode;
	class TESObjectCELL;

	struct DECAL_CREATION_DATA
	{
	public:
		DECAL_CREATION_DATA() = default;

		// members
		NiPoint3              origin{};                   // 00
		NiPoint3              direction{};                // 0C
		NiPoint3              surfaceNormal{};            // 18
		ObjectRefHandle       objRef{};                   // 24
		NiPointer<NiAVObject> avObj{ nullptr };           // 28
		NiNode*               clone{ nullptr };           // 30
		BGSTextureSet*        texSet{ nullptr };          // 38
		BGSTextureSet*        texSet2{ nullptr };         // 40
		int32_t               unk48{ -1 };                // 48
		float                 width{ 0.0f };              // 4C
		float                 height{ 0.0f };             // 50
		float                 depth{ 0.0f };              // 54
		NiMatrix3             rot{};                      // 58
		uint8_t               pad7C[4];                   // 7C
		TESObjectCELL*        parentCell{ nullptr };      // 80
		float                 parallaxScale{ 0.0f };      // 88
		uint8_t               pad8C[4];                   // 8C
		uint64_t              unk90{ 0 };                 // 90
		float                 shininess{ 4.0f };          // 98
		float                 angleThreshold{ 15.0f };    // 9C
		float                 unkA0{ 16.0f };             // A0
		NiColor               color{ 1.0f, 1.0f, 1.0f };  // A4
		uint32_t              unkB0{ 0 };                 // B0
		uint8_t               subtextures{ 0 };           // B4
		uint8_t               unkB5{ 0 };                 // B5
		uint8_t               unkB6{ 1 };                 // B6
		bool                  parallax{ false };          // B7
		bool                  alphaTesting{ true };       // B8
		bool                  alphaBlending{ false };     // B9
		uint8_t               parallaxPasses{ 0 };        // BA
		uint8_t               unkBB{ 0 };                 // BB
		uint8_t               unkBC{ 0 };                 // BC
		uint8_t               twoSided{ 0 };              // BD
		uint8_t               unkBE{ 0 };                 // BE
		uint8_t               unkBF{ 0 };                 // BF
		uint32_t              visited{ 0 };               // C0
		uint8_t               padC4[4];                   // C4
	};
	static_assert(sizeof(DECAL_CREATION_DATA) == 0xC8);

	struct BGSDecalGroup
	{
	public:
		// members
		bool                           permanentGroup;  // 00
		bool                           manualSaveLoad;  // 01
		std::uint16_t                  pad02;           // 02
		std::uint32_t                  pad04;           // 04
		BSTArray<std::uint32_t>        decalGroups;     // 08
		BSTArray<DECAL_CREATION_DATA*> pendingDecals;   // 20
	};
	static_assert(sizeof(BGSDecalGroup) == 0x38);
}
