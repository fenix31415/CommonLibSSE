#pragma once

#include "RE/A/AITimer.h"
#include "RE/B/BSCoreTypes.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/C/CombatObject.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class CombatController;
	class MagicCaster;

	class CombatAimController : public CombatObject
	{
	public:
		enum class PRIORITY : uint32_t
		{
			kUnk0,
			kUnk1,
			kUnk2,
			kUnk3,
			kUnk4,
			kUnk5
		};

		enum class Flags : uint32_t
		{
			kAiming = 1 << 0,
			kUpdating = 1 << 1,
			kUnk2 = 1 << 2,
			kDisable = 1 << 3,
			kUnk4 = 1 << 4,
			kUnk5 = 1 << 5,
			kUnk6 = 1 << 6
		};
		using FLAGS = stl::enumeration<Flags, uint32_t>;

		~CombatAimController();  // 00

		// override (CombatObject)
		std::uint32_t GetObjectType() override;                     // 02
		void          SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void          LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04

		// add
		virtual bool                 CheckAim(const NiPoint3& from, const NiPoint3& to);  // 05
		virtual bool                 CheckAim(const NiPoint3& P);                         // 06
		virtual bool                 CheckAim(float cone);                                // 07
		virtual void                 Update();                                            // 08
		virtual CombatAimController* Clone() const;                                       // 09
		virtual void                 FinishLoadGame();                                    // 0A

		uint32_t CalculatePriority(PRIORITY priority);
		void     ClearAim();
		bool     GetTargetLastSeenLocation(NiPoint3& ans);
		bool     HasTargetLOS() const;
		void     Register();
		void     SetAim(const NiPoint3& P);
		void     Unregister();

		[[nodiscard]] static CombatAimController* Create(CombatController* control, PRIORITY priority);
		[[nodiscard]] static CombatAimController* Create(CombatController* control, PRIORITY priority, const NiPoint3& P);

		// members
		MagicCaster*      mcaster;         // 10 -- or weap?
		NiPoint3          P;               // 18
		uint32_t          field_24;        // 24
		CombatController* combat_control;  // 28
		ActorHandle       target;          // 30
		PRIORITY          priority1;       // 34
		PRIORITY          priority2;       // 38
		FLAGS             flags;           // 3C
		AITimer           timer;           // 40
	private:
		CombatAimController* Ctor1(CombatController* control, PRIORITY priority);
		CombatAimController* Ctor2(CombatController* control, PRIORITY priority, const NiPoint3& P);
	};
	static_assert(sizeof(CombatAimController) == 0x48);
}
