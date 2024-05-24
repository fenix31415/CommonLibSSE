#pragma once

#include "CollisionLayers.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class Actor;
	class BGSAttackData;
	class BGSExplosion;
	class BGSProjectile;
	struct BGSWorldLocation;
	struct bhkPickData;
	class BSPathingLocation;
	class NiAVObject;
	class TESAmmo;
	class TESBoundObject;
	class TESObjectREFR;
	class TESObjectWEAP;
	class Projectile;

	enum class ACTOR_LOS_LOCATION : uint32_t
	{
		kNone,
		kEyes,
		kHead,
		kTorso,
		kFeet
	};

	namespace CombatUtilities
	{
		float       CalculateAnticipatedDistance(TESObjectREFR* refr1, TESObjectREFR* refr2, float time);
		float       CalculateAnticipatedDistanceSquared(TESObjectREFR* refr1, TESObjectREFR* refr2, float time);
		void        CalculateAnticipatedLocation(TESObjectREFR* refr, float time, NiPoint3& anticPos);
		float       CalculateAnticipatedLocationAndHeading(Actor* a, float time, NiPoint3& anticPos);
		float       CalculateAnticipatedMeleeDistanceSquared(Actor* a1, Actor* a2, float time);
		float       CalculateAttackRange(Actor* attacker, Actor* target);
		float       CalculateDesiredAttackRange(Actor* attacker, TESObjectREFR* target);
		float       CalculateDistanceSquared(TESObjectREFR* refr1, TESObjectREFR* refr2);
		float       CalculateDistanceSquared(TESObjectREFR* a, const BGSWorldLocation& loc);
		bool        CalculateExactLOS(Actor* attacker, TESObjectREFR* target, const NiPoint3& attackerPos, const NiPoint3& targetPos, COL_LAYER layer);
		float       CalculateItemDPS(Actor* a, TESBoundObject* attackItem, TESAmmo* ammo = nullptr);
		void        CalculateItemRanges(Actor* a, TESObjectWEAP* weap, float& minRange, float& maxRange, TESAmmo* ammo);
		float       CalculateMeleeDistanceSquared(Actor* attacker, const NiPoint3& attackerPos, Actor* target, const NiPoint3& targetPos);
		bool        CalculateProjectileLOS(Actor* shooter, BGSProjectile* bproj, float speed, const NiPoint3& from, const NiPoint3& to, NiPoint3* hitPos = nullptr, TESObjectREFR** hitRefr = nullptr, float* fraction = nullptr);
		NiAVObject* CalculateProjectileLOS(Actor* shooter, BGSProjectile* bproj, bhkPickData& pdata);
		float       CalculateProjectileSpeed(Actor* shooter, BGSProjectile* bproj);
		float       CalculateRelativeVelocity(TESObjectREFR* refr, const NiPoint3& P);
		float       CalculateSomeDistance(TESObjectREFR* attacker, TESObjectREFR* target, bool countSlope = false, TESObjectREFR* attacker_mount = nullptr);
		float       CalculateVelocityAngle(TESObjectREFR* refr, const NiPoint3& P);
		bool        CanActorExistInSpace(Actor* a, const BGSWorldLocation& loc);
		bool        CanActorExistInTargetSpace(Actor* a, Actor* target);
		bool        CheckFiringArc(const NiPoint3& from, const NiPoint3& to, float heading, float HeadingTolerance);
		bool        CheckMovementAngle(const NiPoint3& from, const NiPoint3& to, const NiPoint3& P, float maxAngle);
		bool        CheckNavmeshLineOfSight(BSPathingLocation& from, const NiPoint3& to);
		bool        CheckNavmeshLineOfSight(BSPathingLocation& from, const NiPoint3& to, BSPathingLocation& ans);
		bool        CheckPathingDistance(Actor* a, const NiPoint3& dst, float maxDist);
		bool        CheckPathingDistance(const NiPoint3& from, const NiPoint3& to, float height, float maxDist);
		bool        CheckPathingLineOfSight(BSPathingLocation& from, const NiPoint3& to, BSPathingLocation& ans);
		bool        CheckStraightPath(TESObjectREFR* refr, const NiPoint3& from, NiPoint3& to, float speed, float minDist);
		bool        CheckStraightPathNavmesh(TESObjectREFR* refr, const NiPoint3& from, NiPoint3& to, float minDist);
		bool        CheckStraightPathNavmeshFast(TESObjectREFR* refr, const NiPoint3& from, NiPoint3& to, float extent = 0.0f);
		float       ComputeProjectileTime(float len2d, float angle_x, float speed);
		float       FindAngleOfProjectile(float len2d, float dz, float speed, float gravity, bool pick_max_angle = false);
		float       FindAngleOfProjectile(Projectile* proj, NiPoint3 move, float speed = 0.0f, bool pick_max_angle = false);
		void        GetAimAnglesFromVector(const NiPoint3& V, float& rotZ, float& rotX);
		NiPoint3    GetAngleToProjectedPoint(const NiPoint3& from, const NiPoint3& to);
		NiPoint3    GetAngleToProjectedTarget(const NiPoint3& from, TESObjectREFR* target, float speed, float gravity, ACTOR_LOS_LOCATION pos = ACTOR_LOS_LOCATION::kTorso);
		float       GetAngleToTarget(Actor* attacker, Actor* target, float* a3);
		float       GetAttackerTargetCollisionExtents(TESObjectREFR* attacker, TESObjectREFR* target);
		float       GetAttackerTargetExtents(TESObjectREFR* attacker, TESObjectREFR* target);
		float       GetAttackerWeaponTargetExtents(Actor* attacker, Actor* target, float attackerWeaponReach = -1.0f);
		Actor*      GetFacingTarget(Actor* attacker, float reach, BGSAttackData* adata);
		float       GetForwardCollisionExtent(TESObjectREFR* refr);
		float       GetForwardExtent(TESObjectREFR* refr);
		NiPoint3    GetProjectedPointForTarget(const NiPoint3& from, TESObjectREFR* target, float speed, float gravity, ACTOR_LOS_LOCATION pos = ACTOR_LOS_LOCATION::kTorso, bool pick_max_angle = false);
		NiPoint3    GetProjectedPointForTarget(const NiPoint3& from, const NiPoint3& to, const NiPoint3& target_lin_vel, float speed, float gravity, bool pick_max_angle = false);
		float       GetProjectileMaximumRange(BGSProjectile* bproj, float speed = 0.0f);
		NiPoint3    GetTargetAttackLocation(TESObjectREFR* target, ACTOR_LOS_LOCATION pos = ACTOR_LOS_LOCATION::kNone);
		NiPoint3    GetTargetAttackOffset(TESObjectREFR* target, ACTOR_LOS_LOCATION pos = ACTOR_LOS_LOCATION::kNone);
		float       GetWeaponReach(Actor* a, TESObjectWEAP* weap);
		bool        IsActorMovingAway(Actor* a, const NiPoint3& P);
		bool        IsActorMovingToward(Actor* a, const NiPoint3& P);
		bool        IsActorUsingMagic(Actor* a);
		bool        IsActorUsingMelee(Actor* a);
		bool        IsActorUsingRanged(Actor* a);
		bool        IsActorUsingUnarmed(Actor* a);
		bool        IsDangerousExplosion(BGSExplosion* expl);
		bool        IsInAttackRange(Actor* attacker, Actor* target, float extend = 0.0f);
		bool        IsOffensiveItem(TESBoundObject* item);
		bool        IsTargetIncapacitated(Actor* a);
		bool        IsTargetWithinFiringArc(Actor* attacker, const NiPoint3& from, const NiPoint3& to, float HeadingTolerance, float LookingTolerance);
		bool        IsTargetWithinStrikeAngle(Actor* attacker, TESObjectREFR* target, const NiPoint3& attackerPos, const NiPoint3& targetPos, BGSAttackData* attackData = nullptr, float attackAngleMult = 1.0f, float* headingDelta_deg = nullptr, bool notIgnoreRotating = false);
	}
}
