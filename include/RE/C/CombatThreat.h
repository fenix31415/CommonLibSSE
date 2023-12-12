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

	class CombatThreat : public CombatObject
	{
	public:
		// TODO: rest
		//bool CheckCollision(CombatMathUtilities::GenericShape* a2, float time);
		void Initialize(TESObjectREFR* refr, float rad, float damage, float expl_time);
		bool Update();

		// members
		FormID        formid;          // 10
		RefHandle     handle;          // 14
		NiPoint3      pos;             // 18
		NiPoint3      angle;           // 24
		float         rad;             // 30
		float         damage;          // 34
		float         range;           // 38
		float         cone;            // 3C
		AITimeStamp   explosion_time;  // 40
		RefHandle     shooter;         // 44
		NiNode*       root;            // 48
		bhkRigidBody* body;            // 50
		NiPoint3      velocity;        // 58
		float         cacheVelocity;   // 64
	};
	static_assert(sizeof(CombatThreat) == 0x68);
}
