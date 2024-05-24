#include "RE/C/CombatMathUtilities.h"

namespace RE
{
	namespace CombatMathUtilities
	{
		uint32_t GetCapsuleType()
		{
			REL::Relocation<uint32_t> type{ RELOCATION_ID(516480, 0) };  // I do not know for AE
			return type.get();
		}

		uint32_t GetSphereType()
		{
			REL::Relocation<uint32_t> type{ RELOCATION_ID(516479, 0) };  // I do not know for AE
			return type.get();
		}

		uint32_t GetConeType()
		{
			REL::Relocation<uint32_t> type{ RELOCATION_ID(516482, 0) };  // I do not know for AE
			return type.get();
		}

		uint32_t GetSweptConeType()
		{
			REL::Relocation<uint32_t> type{ RELOCATION_ID(516483, 0) };  // I do not know for AE
			return type.get();
		}

		uint32_t GetSweptCapsuleType()
		{
			REL::Relocation<uint32_t> type{ RELOCATION_ID(516484, 0) };  // I do not know for AE
			return type.get();
		}

		uint32_t GetSweptSphereType()
		{
			REL::Relocation<uint32_t> type{ RELOCATION_ID(516481, 0) };  // I do not know for AE
			return type.get();
		}

		Shape::Shape(uint32_t a_shape_type) :
			shape_type(a_shape_type)
		{}

		float CalculateAverageDistance(const LineSegment& s1, const NiPoint3& s2)
		{
			using func_t = float(const LineSegment&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32569, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		float CalculateDistanceSquared(const LineSegment& s1, const NiPoint3& s2)
		{
			using func_t = float(const LineSegment&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32565, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		float CalculateDistanceSquared(const LineSegment& s1, const LineSegment& s2)
		{
			using func_t = float(const LineSegment&, const LineSegment&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32566, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		float CalculateDistanceSquared(const Parallelogram& s1, const LineSegment& s2)
		{
			using func_t = float(const Parallelogram&, const LineSegment&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32567, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		float CalculateDistanceSquared(const Cone& s1, const NiPoint3& s2)
		{
			using func_t = float(const Cone&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32568, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CalculateIntersection(const LineSegment& s1, const Sphere& s2, float& k_min, float& k_max)
		{
			using func_t = bool(const LineSegment&, const Sphere&, float&, float&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32570, 0) };  // I do not know for AE
			return func(s1, s2, k_min, k_max);
		}

		bool CalculateIntersection(const MovingSphere& s1, const MovingSphere& s2, float& k)
		{
			using func_t = bool(const MovingSphere&, const MovingSphere&, float&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32571, 0) };  // I do not know for AE
			return func(s1, s2, k);
		}

		NiPoint3 CalculateSupport(const Sphere& s, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Sphere&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32583, 0) };  // I do not know for AE
			return func(s, dir);
		}

		NiPoint3 CalculateSupport(const Capsule& s, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Capsule&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32584, 0) };  // I do not know for AE
			return func(s, dir);
		}

		NiPoint3 CalculateSupport(const Cone& s, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Cone&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32585, 0) };  // I do not know for AE
			return func(s, dir);
		}

		NiPoint3 CalculateSupport(const MovingCapsule& s, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const MovingCapsule&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32592, 0) };  // I do not know for AE
			return func(s, dir);
		}

		NiPoint3 CalculateSupport(const MovingCone& s, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const MovingCone&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32599, 0) };  // I do not know for AE
			return func(s, dir);
		}

		NiPoint3 CalculateSupport(const MovingSphere& s, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const MovingSphere&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32605, 0) };  // I do not know for AE
			return func(s, dir);
		}

		NiPoint3 CalculateSupport(const Capsule& s1, const Capsule& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Capsule&, const Capsule&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32593, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const Capsule& s1, const Cone& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Capsule&, const Cone&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32597, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const Capsule& s1, const Sphere& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Capsule&, const Sphere&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32598, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const Capsule& s1, const MovingCapsule& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Capsule&, const MovingCapsule&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32594, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const Capsule& s1, const MovingCone& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Capsule&, const MovingCone&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32595, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const Capsule& s1, const MovingSphere& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Capsule&, const MovingSphere&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32596, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const Cone& s1, const Cone& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Cone&, const Cone&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32600, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const Cone& s1, const Capsule& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Cone&, const Capsule&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32603, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const Cone& s1, const Sphere& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Cone&, const Sphere&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32604, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const Cone& s1, const MovingCapsule& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Cone&, const MovingCapsule&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32601, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const Cone& s1, const MovingCone& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Cone&, const MovingCone&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32602, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const Sphere& s1, const Sphere& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Sphere&, const Sphere&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32606, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const Sphere& s1, const Capsule& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Sphere&, const Capsule&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32607, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const Sphere& s1, const Cone& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const Sphere&, const Cone&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32608, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const MovingCapsule& s1, const Capsule& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const MovingCapsule&, const Capsule&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32587, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const MovingCapsule& s1, const Cone& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const MovingCapsule&, const Cone&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32588, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const MovingCone& s1, const Capsule& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const MovingCone&, const Capsule&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32589, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const MovingCone& s1, const Cone& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const MovingCone&, const Cone&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32590, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		NiPoint3 CalculateSupport(const MovingSphere& s1, const Sphere& s2, const NiPoint3& dir)
		{
			using func_t = NiPoint3(const MovingSphere&, const Sphere&, const NiPoint3&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32591, 0) };  // I do not know for AE
			return func(s1, s2, dir);
		}

		bool CheckIntersection(const LineSegment& s1, const Sphere& s2)
		{
			using func_t = bool(const LineSegment&, const Sphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32563, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const GenericShape& s1, const GenericShape& s2)
		{
			using func_t = bool(const GenericShape&, const GenericShape&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32564, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const Capsule& s1, const Sphere& s2)
		{
			using func_t = bool(const Capsule&, const Sphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32577, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const Sphere& s1, const Capsule& s2)
		{
			using func_t = bool(const Sphere&, const Capsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32578, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const Capsule& s1, const Capsule& s2)
		{
			using func_t = bool(const Capsule&, const Capsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32579, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const Capsule& s1, const MovingSphere& s2)
		{
			using func_t = bool(const Capsule&, const MovingSphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32636, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingCapsule& s1, const Capsule& s2)
		{
			using func_t = bool(const MovingCapsule&, const Capsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32580, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const Cone& s1, const Sphere& s2)
		{
			using func_t = bool(const Cone&, const Sphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32581, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const Sphere& s1, const Cone& s2)
		{
			using func_t = bool(const Sphere&, const Cone&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32582, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingSphere& s1, const Sphere& s2)
		{
			using func_t = bool(const MovingSphere&, const Sphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32630, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Sphere& s1, const Sphere& s2)
		{
			using func_t = bool(const Sphere&, const Sphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32625, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Sphere& s1, const Capsule& s2)
		{
			using func_t = bool(const Sphere&, const Capsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32626, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Sphere& s1, const Cone& s2)
		{
			using func_t = bool(const Sphere&, const Cone&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32627, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const Sphere& s1, const MovingSphere& s2)
		{
			using func_t = bool(const Sphere&, const MovingSphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32633, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const Sphere& s1, const MovingCapsule& s2)
		{
			using func_t = bool(const Sphere&, const MovingCapsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32631, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const Sphere& s1, const MovingCone& s2)
		{
			using func_t = bool(const Sphere&, const MovingCone&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32632, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Capsule& s1, const Sphere& s2)
		{
			using func_t = bool(const Capsule&, const Sphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32619, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Capsule& s1, const Capsule& s2)
		{
			using func_t = bool(const Capsule&, const Capsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32614, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Capsule& s1, const Cone& s2)
		{
			using func_t = bool(const Capsule&, const Cone&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32618, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Capsule& s1, const MovingSphere& s2)
		{
			using func_t = bool(const Capsule&, const MovingSphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32617, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Capsule& s1, const MovingCapsule& s2)
		{
			using func_t = bool(const Capsule&, const MovingCapsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32615, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Capsule& s1, const MovingCone& s2)
		{
			using func_t = bool(const Capsule&, const MovingCone&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32616, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Cone& s1, const Sphere& s2)
		{
			using func_t = bool(const Cone&, const Sphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32624, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Cone& s1, const Capsule& s2)
		{
			using func_t = bool(const Cone&, const Capsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32623, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Cone& s1, const Cone& s2)
		{
			using func_t = bool(const Cone&, const Cone&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32620, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const Cone& s1, const MovingSphere& s2)
		{
			using func_t = bool(const Cone&, const MovingSphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32637, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Cone& s1, const MovingCapsule& s2)
		{
			using func_t = bool(const Cone&, const MovingCapsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32621, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const Cone& s1, const MovingCone& s2)
		{
			using func_t = bool(const Cone&, const MovingCone&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32622, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const MovingSphere& s1, const Sphere& s2)
		{
			using func_t = bool(const MovingSphere&, const Sphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32613, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingSphere& s1, const Capsule& s2)
		{
			using func_t = bool(const MovingSphere&, const Capsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32634, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingSphere& s1, const Cone& s2)
		{
			using func_t = bool(const MovingSphere&, const Cone&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32635, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingSphere& s1, const MovingSphere& s2)
		{
			using func_t = bool(const MovingSphere&, const MovingSphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32650, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingSphere& s1, const MovingCapsule& s2)
		{
			using func_t = bool(const MovingSphere&, const MovingCapsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32651, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingSphere& s1, const MovingCone& s2)
		{
			using func_t = bool(const MovingSphere&, const MovingCone&);
			REL::Relocation<func_t> func{ RELOCATION_ID(, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingCapsule& s1, const Sphere& s2)
		{
			using func_t = bool(const MovingCapsule&, const Sphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32628, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const MovingCapsule& s1, const Capsule& s2)
		{
			using func_t = bool(const MovingCapsule&, const Capsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32609, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const MovingCapsule& s1, const Cone& s2)
		{
			using func_t = bool(const MovingCapsule&, const Cone&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32610, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingCapsule& s1, const MovingSphere& s2)
		{
			using func_t = bool(const MovingCapsule&, const MovingSphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32640, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingCapsule& s1, const MovingCapsule& s2)
		{
			using func_t = bool(const MovingCapsule&, const MovingCapsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32638, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingCapsule& s1, const MovingCone& s2)
		{
			using func_t = bool(const MovingCapsule&, const MovingCone&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32639, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingCone& s1, const Sphere& s2)
		{
			using func_t = bool(const MovingCone&, const Sphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32629, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const MovingCone& s1, const Capsule& s2)
		{
			using func_t = bool(const MovingCone&, const Capsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32611, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersectionGJK(const MovingCone& s1, const Cone& s2)
		{
			using func_t = bool(const MovingCone&, const Cone&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32612, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingCone& s1, const MovingSphere& s2)
		{
			using func_t = bool(const MovingCone&, const MovingSphere&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32646, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingCone& s1, const MovingCapsule& s2)
		{
			using func_t = bool(const MovingCone&, const MovingCapsule&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32645, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		bool CheckIntersection(const MovingCone& s1, const MovingCone& s2)
		{
			using func_t = bool(const MovingCone&, const MovingCone&);
			REL::Relocation<func_t> func{ RELOCATION_ID(32644, 0) };  // I do not know for AE
			return func(s1, s2);
		}

		void CreateCapsule(Actor* actor, const NiPoint3& actor_pos, Capsule& ans)
		{
			using func_t = decltype(CreateCapsule);
			REL::Relocation<func_t> func{ RELOCATION_ID(32572, 0) };  // I do not know for AE
			return func(actor, actor_pos, ans);
		}

		void CreateMovingCapsule(Actor* actor, const NiPoint3& actor_moving, MovingCapsule& ans)
		{
			using func_t = decltype(CreateMovingCapsule);
			REL::Relocation<func_t> func{ RELOCATION_ID(32573, 0) };  // I do not know for AE
			return func(actor, actor_moving, ans);
		}

		bool UpdateSimplex(Simplex& simplex, NiPoint3& P)
		{
			using func_t = decltype(UpdateSimplex);
			REL::Relocation<func_t> func{ RELOCATION_ID(32586, 0) };  // I do not know for AE
			return func(simplex, P);
		}

		Sphere::Sphere() :
			Shape{ GetSphereType() }, center(), radius()
		{}

		Sphere::Sphere(const NiPoint3& a_center, float a_radius) :
			Shape{ GetSphereType() }, center(a_center), radius(a_radius)
		{}

		void Sphere::GetLocation(NiPoint3& location) const
		{
			location = center;
		}

		void Sphere::SetLocation(const NiPoint3& location)
		{
			center = location;
		}

		Cone::Cone() :
			Shape{ GetConeType() }, segment{}, radius(), cone()
		{}

		Cone::Cone(const NiPoint3& P1, const NiPoint3& P2, float a_radius, float a_cone) :
			Shape{ GetConeType() }, segment{ P1, P2 - P1 }, radius(a_radius), cone(a_cone)
		{}

		void Cone::GetLocation(NiPoint3& location) const
		{
			location = segment.base;
		}

		void Cone::SetLocation(const NiPoint3& location)
		{
			segment.base = location;
		}

		Capsule::Capsule() :
			Shape{ GetCapsuleType() }, segment{}, radius()
		{}

		Capsule::Capsule(const NiPoint3& P1, const NiPoint3& P2, float a_radius) :
			Shape{ GetCapsuleType() }, segment{ P1, P2 - P1 }, radius(a_radius)
		{}

		void Capsule::GetLocation(NiPoint3& location) const
		{
			location = segment.base;
		}

		void Capsule::SetLocation(const NiPoint3& location)
		{
			segment.base = location;
		}

		template class SweptShape<Sphere>;
		static_assert(sizeof(MovingSphere) == 0x24);
		template class SweptShape<Cone>;
		static_assert(sizeof(MovingCone) == 0x38);
		template class SweptShape<Capsule>;
		static_assert(sizeof(MovingCapsule) == 0x34);

		LineSegment::LineSegment(const NiPoint3& a_base, const NiPoint3& a_offset) :
			base(a_base), offset(a_offset), len2(offset.SqrLength())
		{}

		Parallelogram::Parallelogram(const LineSegment& a_segment, const NiPoint3& a_vector) :
			segment(a_segment), vector(a_vector)
		{}
	}
}
