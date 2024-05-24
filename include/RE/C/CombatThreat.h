#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/B/BSCoreTypes.h"
#include "RE/C/CombatObject.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class NiNode;
	class TESObjectREFR;
	class bhkRigidBody;

	namespace CombatMathUtilities
	{
		class GenericShape;
	}

	class CombatThreat : public CombatObject
	{
	public:
		~CombatThreat() override;  // 00

		// override (CombatObject)
		std::uint32_t GetObjectType() override;                     // 02
		void          SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void          LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04

		bool CheckVelocityDirection(const NiPoint3& pos) const;
		bool CheckCollision(const CombatMathUtilities::GenericShape& s, float time) const;
		bool CreateCollisionShape(float time, CombatMathUtilities::GenericShape* ans) const;
		void Initialize(TESObjectREFR* refr, float radius, float damage, float expl_time);
		bool Update();

		// members
		FormID        threatID;                        // 10
		RefHandle     threatRef;                       // 14
		NiPoint3      threatLocation;                  // 18
		NiPoint3      angle;                           // 24
		float         radius;                          // 30
		float         damage;                          // 34
		float         range;                           // 38
		float         cone;                            // 3C
		AITimeStamp   explosionTimestamp;              // 40
		RefHandle     owner;                           // 44
		NiNode*       threatRoot;                      // 48
		bhkRigidBody* body;                            // 50
		NiPoint3      linearVelocity;                  // 58
		AITimeStamp   updatedCachedVelocityTimeStamp;  // 64
	};
	static_assert(sizeof(CombatThreat) == 0x68);
}
