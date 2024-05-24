#include "RE/C/CombatUtilities.h"

namespace RE
{
	namespace CombatUtilities
	{
		float CalculateAnticipatedDistance(TESObjectREFR* refr1, TESObjectREFR* refr2, float time)
		{
			using func_t = decltype(CalculateAnticipatedDistance);
			REL::Relocation<func_t> func{ RELOCATION_ID(46055, 0) };  // I do not know for AE
			return func(refr1, refr2, time);
		}

		float CalculateAnticipatedDistanceSquared(TESObjectREFR* refr1, TESObjectREFR* refr2, float time)
		{
			using func_t = decltype(CalculateAnticipatedDistanceSquared);
			REL::Relocation<func_t> func{ RELOCATION_ID(46056, 0) };  // I do not know for AE
			return func(refr1, refr2, time);
		}

		void CalculateAnticipatedLocation(TESObjectREFR* refr, float time, NiPoint3& anticPos)
		{
			using func_t = decltype(CalculateAnticipatedLocation);
			REL::Relocation<func_t> func{ RELOCATION_ID(46045, 0) };  // I do not know for AE
			return func(refr, time, anticPos);
		}

		float CalculateAnticipatedLocationAndHeading(Actor* a, float time, NiPoint3& anticPos)
		{
			using func_t = decltype(CalculateAnticipatedLocationAndHeading);
			REL::Relocation<func_t> func{ RELOCATION_ID(46046, 0) };  // I do not know for AE
			return func(a, time, anticPos);
		}

		float CalculateAnticipatedMeleeDistanceSquared(Actor* a1, Actor* a2, float time)
		{
			using func_t = decltype(CalculateAnticipatedMeleeDistanceSquared);
			REL::Relocation<func_t> func{ RELOCATION_ID(46057, 0) };  // I do not know for AE
			return func(a1, a2, time);
		}

		float CalculateAttackRange(Actor* attacker, Actor* target)
		{
			using func_t = decltype(CalculateAttackRange);
			REL::Relocation<func_t> func{ RELOCATION_ID(46072, 0) };  // I do not know for AE
			return func(attacker, target);
		}

		float CalculateDesiredAttackRange(Actor* attacker, TESObjectREFR* target)
		{
			using func_t = decltype(CalculateDesiredAttackRange);
			REL::Relocation<func_t> func{ RELOCATION_ID(46074, 0) };  // I do not know for AE
			return func(attacker, target);
		}

		float CalculateDistanceSquared(TESObjectREFR* refr1, TESObjectREFR* refr2)
		{
			using func_t = float(TESObjectREFR*, TESObjectREFR*);
			REL::Relocation<func_t> func{ RELOCATION_ID(46058, 0) };  // I do not know for AE
			return func(refr1, refr2);
		}

		float CalculateDistanceSquared(TESObjectREFR* a, const BGSWorldLocation& loc)
		{
			using func_t = float(TESObjectREFR*, const BGSWorldLocation&);
			REL::Relocation<func_t> func{ RELOCATION_ID(46059, 0) };  // I do not know for AE
			return func(a, loc);
		}

		bool CalculateExactLOS(Actor* attacker, TESObjectREFR* target, const NiPoint3& attackerPos, const NiPoint3& targetPos, COL_LAYER layer)
		{
			using func_t = decltype(CalculateExactLOS);
			REL::Relocation<func_t> func{ RELOCATION_ID(46037, 0) };  // I do not know for AE
			return func(attacker, target, attackerPos, targetPos, layer);
		}

		float CalculateItemDPS(Actor* a, TESBoundObject* attackItem, TESAmmo* ammo)
		{
			using func_t = decltype(CalculateItemDPS);
			REL::Relocation<func_t> func{ RELOCATION_ID(46070, 0) };  // I do not know for AE
			return func(a, attackItem, ammo);
		}

		void CalculateItemRanges(Actor* a, TESObjectWEAP* weap, float& minRange, float& maxRange, TESAmmo* ammo)
		{
			using func_t = decltype(CalculateItemRanges);
			REL::Relocation<func_t> func{ RELOCATION_ID(46068, 0) };  // I do not know for AE
			return func(a, weap, minRange, maxRange, ammo);
		}

		float CalculateSomeDistance(TESObjectREFR* attacker, TESObjectREFR* target, bool countSlope, TESObjectREFR* attacker_mount)
		{
			using func_t = decltype(CalculateSomeDistance);
			REL::Relocation<func_t> func{ RELOCATION_ID(46012, 0) };  // I do not know for AE
			return func(attacker, target, countSlope, attacker_mount);
		}

		float CalculateVelocityAngle(TESObjectREFR* refr, const NiPoint3& P)
		{
			using func_t = decltype(CalculateVelocityAngle);
			REL::Relocation<func_t> func{ RELOCATION_ID(46066, 0) };  // I do not know for AE
			return func(refr, P);
		}

		float CalculateMeleeDistanceSquared(Actor* attacker, const NiPoint3& attackerPos, Actor* target, const NiPoint3& targetPos)
		{
			using func_t = decltype(CalculateMeleeDistanceSquared);
			REL::Relocation<func_t> func{ RELOCATION_ID(46061, 0) };  // I do not know for AE
			return func(attacker, attackerPos, target, targetPos);
		}

		bool CalculateProjectileLOS(Actor* shooter, BGSProjectile* bproj, float speed, const NiPoint3& from, const NiPoint3& to, NiPoint3* hitPos, TESObjectREFR** hitRefr, float* fraction)
		{
			using func_t = bool(Actor*, BGSProjectile*, float, const NiPoint3&, const NiPoint3&, NiPoint3*, TESObjectREFR**, float*);
			REL::Relocation<func_t> func{ RELOCATION_ID(46036, 0) };  // I do not know for AE
			return func(shooter, bproj, speed, from, to, hitPos, hitRefr, fraction);
		}

		NiAVObject* CalculateProjectileLOS(Actor* shooter, BGSProjectile* bproj, bhkPickData& pdata)
		{
			using func_t = NiAVObject*(Actor*, BGSProjectile*, bhkPickData&);
			REL::Relocation<func_t> func{ RELOCATION_ID(46035, 0) };  // I do not know for AE
			return func(shooter, bproj, pdata);
		}

		float CalculateProjectileSpeed(Actor* shooter, BGSProjectile* bproj)
		{
			using func_t = decltype(CalculateProjectileSpeed);
			REL::Relocation<func_t> func{ RELOCATION_ID(46026, 0) };  // I do not know for AE
			return func(shooter, bproj);
		}

		float CalculateRelativeVelocity(TESObjectREFR* refr, const NiPoint3& P)
		{
			using func_t = decltype(CalculateRelativeVelocity);
			REL::Relocation<func_t> func{ RELOCATION_ID(46065, 0) };  // I do not know for AE
			return func(refr, P);
		}

		bool CanActorExistInSpace(Actor* a, const BGSWorldLocation& loc)
		{
			using func_t = decltype(CanActorExistInSpace);
			REL::Relocation<func_t> func{ RELOCATION_ID(46043, 0) };  // I do not know for AE
			return func(a, loc);
		}

		bool CanActorExistInTargetSpace(Actor* a, Actor* target)
		{
			using func_t = decltype(CanActorExistInTargetSpace);
			REL::Relocation<func_t> func{ RELOCATION_ID(46042, 0) };  // I do not know for AE
			return func(a, target);
		}

		bool CheckFiringArc(const NiPoint3& from, const NiPoint3& to, float heading, float HeadingTolerance)
		{
			using func_t = decltype(CheckFiringArc);
			REL::Relocation<func_t> func{ RELOCATION_ID(46077, 0) };  // I do not know for AE
			return func(from, to, heading, HeadingTolerance);
		}

		bool CheckMovementAngle(const NiPoint3& from, const NiPoint3& to, const NiPoint3& P, float maxAngle)
		{
			using func_t = decltype(CheckMovementAngle);
			REL::Relocation<func_t> func{ RELOCATION_ID(46075, 0) };  // I do not know for AE
			return func(from, to, P, maxAngle);
		}

		bool CheckNavmeshLineOfSight(BSPathingLocation& from, const NiPoint3& to)
		{
			using func_t = bool (BSPathingLocation&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(46047, 0) };  // I do not know for AE
			return func(from, to);
		}

		bool CheckNavmeshLineOfSight(BSPathingLocation& from, const NiPoint3& to, BSPathingLocation& ans)
		{
			using func_t = bool(BSPathingLocation&, const NiPoint3&, BSPathingLocation&);
			REL::Relocation<func_t> func{ RELOCATION_ID(46048, 0) };  // I do not know for AE
			return func(from, to, ans);
		}

		bool CheckPathingDistance(Actor* a, const NiPoint3& dst, float maxDist)
		{
			using func_t = bool (Actor*, const NiPoint3&, float);
			REL::Relocation<func_t> func{ RELOCATION_ID(46053, 0) };  // I do not know for AE
			return func(a, dst, maxDist);
		}

		bool CheckPathingDistance(const NiPoint3& from, const NiPoint3& to, float height, float maxDist)
		{
			using func_t = bool(const NiPoint3&, const NiPoint3&, float, float);
			REL::Relocation<func_t> func{ RELOCATION_ID(46054, 0) };  // I do not know for AE
			return func(from, to, height, maxDist);
		}

		bool CheckPathingLineOfSight(BSPathingLocation& from, const NiPoint3& to, BSPathingLocation& ans)
		{
			using func_t = bool(BSPathingLocation&, const NiPoint3&, BSPathingLocation&);
			REL::Relocation<func_t> func{ RELOCATION_ID(46049, 0) };  // I do not know for AE
			return func(from, to, ans);
		}

		bool CheckStraightPath(TESObjectREFR* refr, const NiPoint3& from, NiPoint3& to, float speed, float minDist)
		{
			using func_t = decltype(CheckStraightPath);
			REL::Relocation<func_t> func{ RELOCATION_ID(46050, 0) };  // I do not know for AE
			return func(refr, from, to, speed, minDist);
		}

		bool CheckStraightPathNavmesh(TESObjectREFR* refr, const NiPoint3& from, NiPoint3& to, float minDist)
		{
			using func_t = decltype(CheckStraightPathNavmesh);
			REL::Relocation<func_t> func{ RELOCATION_ID(46051, 0) };  // I do not know for AE
			return func(refr, from, to, minDist);
		}

		bool CheckStraightPathNavmeshFast(TESObjectREFR* refr, const NiPoint3& from, NiPoint3& to, float extent)
		{
			using func_t = decltype(CheckStraightPathNavmeshFast);
			REL::Relocation<func_t> func{ RELOCATION_ID(46052, 0) };  // I do not know for AE
			return func(refr, from, to, extent);
		}

		float ComputeProjectileTime(float len2d, float angle_x, float speed)
		{
			using func_t = decltype(ComputeProjectileTime);
			REL::Relocation<func_t> func{ RELOCATION_ID(46029, 0) };  // I do not know for AE
			return func(len2d, angle_x, speed);
		}

		float FindAngleOfProjectile(float len2d, float dz, float speed, float gravity, bool pick_max_angle)
		{
			using func_t = float(float, float, float, float, bool);
			REL::Relocation<func_t> func{ RELOCATION_ID(46027, 0) };  // I do not know for AE
			return func(len2d, dz, speed, gravity, pick_max_angle);
		}

		float FindAngleOfProjectile(Projectile* proj, NiPoint3 move, float speed, bool pick_max_angle)
		{
			using func_t = float(Projectile*, NiPoint3, float, bool);
			REL::Relocation<func_t> func{ RELOCATION_ID(46028, 0) };  // I do not know for AE
			return func(proj, move, speed, pick_max_angle);
		}

		void GetAimAnglesFromVector(const NiPoint3& V, float& rotZ, float& rotX)
		{
			using func_t = decltype(GetAimAnglesFromVector);
			REL::Relocation<func_t> func{ RELOCATION_ID(46076, 0) };  // I do not know for AE
			return func(V, rotZ, rotX);
		}

		NiPoint3 GetAngleToProjectedPoint(const NiPoint3& from, const NiPoint3& to)
		{
			using func_t = decltype(GetAngleToProjectedPoint);
			REL::Relocation<func_t> func{ RELOCATION_ID(46023, 0) };  // I do not know for AE
			return func(from, to);
		}

		NiPoint3 GetAngleToProjectedTarget(const NiPoint3& from, TESObjectREFR* target, float speed, float gravity, ACTOR_LOS_LOCATION pos)
		{
			using func_t = decltype(GetAngleToProjectedTarget);
			REL::Relocation<func_t> func{ RELOCATION_ID(46022, 0) };  // I do not know for AE
			return func(from, target, speed, gravity, pos);
		}

		float GetAngleToTarget(Actor* attacker, Actor* target, float* a3)
		{
			using func_t = decltype(GetAngleToTarget);
			REL::Relocation<func_t> func{ RELOCATION_ID(46019, 0) };  // I do not know for AE
			return func(attacker, target, a3);
		}

		float GetAttackerTargetCollisionExtents(TESObjectREFR* attacker, TESObjectREFR* target)
		{
			using func_t = decltype(GetAttackerTargetCollisionExtents);
			REL::Relocation<func_t> func{ RELOCATION_ID(46016, 0) };  // I do not know for AE
			return func(attacker, target);
		}

		float GetAttackerTargetExtents(TESObjectREFR* attacker, TESObjectREFR* target)
		{
			using func_t = decltype(GetAttackerTargetExtents);
			REL::Relocation<func_t> func{ RELOCATION_ID(46015, 0) };  // I do not know for AE
			return func(attacker, target);
		}

		float GetAttackerWeaponTargetExtents(Actor* attacker, Actor* target, float attackerWeaponReach)
		{
			using func_t = decltype(GetAttackerWeaponTargetExtents);
			REL::Relocation<func_t> func{ RELOCATION_ID(46017, 0) };  // I do not know for AE
			return func(attacker, target, attackerWeaponReach);
		}

		Actor* GetFacingTarget(Actor* attacker, float reach, BGSAttackData* adata)
		{
			using func_t = decltype(GetFacingTarget);
			REL::Relocation<func_t> func{ RELOCATION_ID(46011, 0) };  // I do not know for AE
			return func(attacker, reach, adata);
		}

		float GetForwardCollisionExtent(TESObjectREFR* refr)
		{
			using func_t = decltype(GetForwardCollisionExtent);
			REL::Relocation<func_t> func{ RELOCATION_ID(46014, 0) };  // I do not know for AE
			return func(refr);
		}

		float GetForwardExtent(TESObjectREFR* refr)
		{
			using func_t = decltype(GetForwardExtent);
			REL::Relocation<func_t> func{ RELOCATION_ID(46013, 0) };  // I do not know for AE
			return func(refr);
		}

		NiPoint3 GetProjectedPointForTarget(const NiPoint3& from, TESObjectREFR* target, float speed, float gravity, ACTOR_LOS_LOCATION pos, bool pick_max_angle)
		{
			using func_t = NiPoint3(const NiPoint3&, TESObjectREFR*, float, float, ACTOR_LOS_LOCATION, bool);
			REL::Relocation<func_t> func{ RELOCATION_ID(46024, 0) };  // I do not know for AE
			return func(from, target, speed, gravity, pos, pick_max_angle);
		}

		NiPoint3 GetProjectedPointForTarget(const NiPoint3& from, const NiPoint3& to, const NiPoint3& target_lin_vel, float speed, float gravity, bool pick_max_angle)
		{
			using func_t = NiPoint3(const NiPoint3&, const NiPoint3&, const NiPoint3&, float, float, bool);
			REL::Relocation<func_t> func{ RELOCATION_ID(46025, 0) };  // I do not know for AE
			return func(from, to, target_lin_vel, speed, gravity, pick_max_angle);
		}

		float GetProjectileMaximumRange(BGSProjectile* bproj, float speed)
		{
			using func_t = decltype(GetProjectileMaximumRange);
			REL::Relocation<func_t> func{ RELOCATION_ID(46032, 0) };  // I do not know for AE
			return func(bproj, speed);
		}

		NiPoint3 GetTargetAttackLocation(TESObjectREFR* target, ACTOR_LOS_LOCATION pos)
		{
			using func_t = decltype(GetTargetAttackLocation);
			REL::Relocation<func_t> func{ RELOCATION_ID(46021, 0) };  // I do not know for AE
			return func(target, pos);
		}

		NiPoint3 GetTargetAttackOffset(TESObjectREFR* target, ACTOR_LOS_LOCATION pos)
		{
			using func_t = decltype(GetTargetAttackOffset);
			REL::Relocation<func_t> func{ RELOCATION_ID(46020, 0) };  // I do not know for AE
			return func(target, pos);
		}

		float GetWeaponReach(Actor* a, TESObjectWEAP* weap)
		{
			using func_t = decltype(GetWeaponReach);
			REL::Relocation<func_t> func{ RELOCATION_ID(46018, 0) };  // I do not know for AE
			return func(a, weap);
		}

		bool IsActorMovingAway(Actor* a, const NiPoint3& P)
		{
			using func_t = decltype(IsActorMovingAway);
			REL::Relocation<func_t> func{ RELOCATION_ID(46062, 0) };  // I do not know for AE
			return func(a, P);
		}

		bool IsActorMovingToward(Actor* a, const NiPoint3& P)
		{
			using func_t = decltype(IsActorMovingToward);
			REL::Relocation<func_t> func{ RELOCATION_ID(46063, 0) };  // I do not know for AE
			return func(a, P);
		}

		bool IsActorUsingMagic(Actor* a)
		{
			using func_t = decltype(IsActorUsingMagic);
			REL::Relocation<func_t> func{ RELOCATION_ID(46040, 0) };  // I do not know for AE
			return func(a);
		}

		bool IsActorUsingMelee(Actor* a)
		{
			using func_t = decltype(IsActorUsingMelee);
			REL::Relocation<func_t> func{ RELOCATION_ID(46039, 0) };  // I do not know for AE
			return func(a);
		}

		bool IsActorUsingRanged(Actor* a)
		{
			using func_t = decltype(IsActorUsingRanged);
			REL::Relocation<func_t> func{ RELOCATION_ID(46041, 0) };  // I do not know for AE
			return func(a);
		}

		bool IsActorUsingUnarmed(Actor* a)
		{
			using func_t = decltype(IsActorUsingUnarmed);
			REL::Relocation<func_t> func{ RELOCATION_ID(46038, 0) };  // I do not know for AE
			return func(a);
		}

		bool IsDangerousExplosion(BGSExplosion* expl)
		{
			using func_t = decltype(IsDangerousExplosion);
			REL::Relocation<func_t> func{ RELOCATION_ID(46044, 0) };  // I do not know for AE
			return func(expl);
		}

		bool IsInAttackRange(Actor* attacker, Actor* target, float extend)
		{
			using func_t = decltype(IsInAttackRange);
			REL::Relocation<func_t> func{ RELOCATION_ID(46073, 0) };  // I do not know for AE
			return func(attacker, target, extend);
		}

		bool IsOffensiveItem(TESBoundObject* item)
		{
			using func_t = decltype(IsOffensiveItem);
			REL::Relocation<func_t> func{ RELOCATION_ID(46071, 0) };  // I do not know for AE
			return func(item);
		}

		bool IsTargetIncapacitated(Actor* a)
		{
			using func_t = decltype(IsTargetIncapacitated);
			REL::Relocation<func_t> func{ RELOCATION_ID(46064, 0) };  // I do not know for AE
			return func(a);
		}

		bool IsTargetWithinFiringArc(Actor* attacker, const NiPoint3& from, const NiPoint3& to, float HeadingTolerance, float LookingTolerance)
		{
			using func_t = decltype(IsTargetWithinFiringArc);
			REL::Relocation<func_t> func{ RELOCATION_ID(46034, 0) };  // I do not know for AE
			return func(attacker, from, to, HeadingTolerance, LookingTolerance);
		}

		bool IsTargetWithinStrikeAngle(Actor* attacker, TESObjectREFR* target, const NiPoint3& attackerPos, const NiPoint3& targetPos, BGSAttackData* attackData, float attackAngleMult, float* headingDelta_deg, bool notIgnoreRotating)
		{
			using func_t = decltype(IsTargetWithinStrikeAngle);
			REL::Relocation<func_t> func{ RELOCATION_ID(46033, 0) };  // I do not know for AE
			return func(attacker, target, attackerPos, targetPos, attackData, attackAngleMult, headingDelta_deg, notIgnoreRotating);
		}
	}
}
