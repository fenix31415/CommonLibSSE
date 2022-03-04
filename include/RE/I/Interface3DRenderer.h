#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiFrustum.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSCullingProcess;
	class BSLight;
	class BSShaderAccumulator;
	class NiCamera;
	class NiNode;
	class ShadowSceneNode;

	namespace Interface3D
	{
		struct MENU
		{
			enum TYPE : std::uint32_t
			{
				kJournal = 0,
				kInventory,
				kInventoryMagic,
				kBook,
				kLoading,
				kUnk05,
				kStats,
				kLockpicking,

				kTotal = 8
			};
		};
		using MENU_TYPE = MENU::TYPE;

		class Renderer : public BSTSingletonSDM<Renderer>
		{
		public:
			struct LightParams
			{
			public:
				// members
				NiColor            color;         // 00
				NiPoint3           translate;     // 0C
				float              radius;        // 18
				float              fade;          // 1C
				bool               castsShadows;  // 20
				NiPointer<BSLight> light;         // 28
				LightParams*       next;          // 30
			};
			static_assert(sizeof(LightParams) == 0x38);

			static Renderer* GetSingleton()
			{
				REL::Relocation<Renderer**> singleton{ REL::ID(517052) };
				return *singleton;
			}

			// members
			std::uint8_t                   pad01;                           // 01
			std::uint16_t                  pad02;                           // 02
			std::uint32_t                  pad04;                           // 04
			BSCullingProcess*              cullingProcess;                  // 08
			NiPointer<BSShaderAccumulator> unk10;                           // 10
			NiPointer<BSShaderAccumulator> unk18;                           // 18
			NiPointer<NiCamera>            camera;                          // 20
			mutable BSSpinLock             lock;                            // 28
			ShadowSceneNode*               shadowSceneNode;                 // 30
			NiPointer<NiNode>              menuObjects[MENU_TYPE::kTotal];  // 38
			BSTArray<LightParams>          lightParams;                     // 78
			MENU_TYPE                      currentMenu;                     // 90
			std::uint32_t                  pad94;                           // 94
			BSTArray<MENU_TYPE>            menus;                           // 98
			BSTArray<void*>                unkB0;                           // B0
			std::uint64_t                  unkC8;                           // C8
			std::uint64_t                  unkD0;                           // D0
			std::uint64_t                  unkD8;                           // D8
			std::uint64_t                  unkE0;                           // E0
			std::uint64_t                  unkE8;                           // E8
			std::uint64_t                  unkF0;                           // F0
			NiFrustum                      viewFrustum;                     // F8
		};
		static_assert(sizeof(Renderer) == 0x118);
	}
}
