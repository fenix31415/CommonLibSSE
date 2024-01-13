#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class Actor;

	namespace CombatMathUtilities
	{
		uint32_t GetCapsuleType();
		uint32_t GetConeType();
		uint32_t GetSphereType();
		uint32_t GetSweptCapsuleType();
		uint32_t GetSweptConeType();
		uint32_t GetSweptSphereType();

		struct LineSegment
		{
			LineSegment() = default;
			LineSegment(const NiPoint3& a_base, const NiPoint3& offset);
			LineSegment(const LineSegment& other) = default;

			// members
			NiPoint3 base;    // 00
			NiPoint3 offset;  // 0C
			float    len2;    // 18
		};
		static_assert(sizeof(LineSegment) == 0x1C);

		struct Parallelogram
		{
			Parallelogram() = default;
			Parallelogram(const LineSegment& a_segment, const NiPoint3& a_vector);

			// members
			LineSegment segment;  // 00
			NiPoint3    vector;   // 1C
		};
		static_assert(sizeof(Parallelogram) == 0x28);

		class Shape
		{
		public:
			Shape(uint32_t a_shape_type);

			// members
			uint32_t shape_type;  // 00
		};

		class Sphere : public Shape
		{
		public:
			Sphere(const NiPoint3& a_center, float a_radius);
			Sphere(const Sphere& other) = default;
			Sphere& operator=(const Sphere&) = default;

			void GetLocation(NiPoint3& location) const;
			void SetLocation(const NiPoint3& location);

			// members
			NiPoint3 center;  // 04
			float    radius;  // 10
		};
		static_assert(sizeof(Sphere) == 0x14);

		class Cone : public Shape
		{
		public:
			Cone(const NiPoint3& P1, const NiPoint3& P2, float a_radius, float a_cone);
			Cone(const Cone& other) = default;
			Cone& operator=(const Cone&) = default;

			void GetLocation(NiPoint3& location) const;
			void SetLocation(const NiPoint3& location);

			// members
			LineSegment segment;       // 04
			float       radius;        // 20
			float       cone;          // 24
		};
		static_assert(sizeof(Cone) == 0x28);

		class Capsule : public Shape
		{
		public:
			Capsule(const NiPoint3& P1, const NiPoint3& P2, float a_radius);
			Capsule(const Capsule& other) = default;
			Capsule& operator=(const Capsule&) = default;

			void GetLocation(NiPoint3& location) const;
			void SetLocation(const NiPoint3& location);

			// members
			LineSegment segment;       // 04
			float       radius;        // 20
		};
		static_assert(sizeof(Capsule) == 0x24);

		template <typename Inner>
		uint32_t GetSweptType()
		{
			static_assert(std::is_same_v<Inner, Capsule> || std::is_same_v<Inner, Cone> || std::is_same_v<Inner, Sphere>);

			if (std::is_same_v<Inner, Capsule>)
				return GetSweptCapsuleType();
			if (std::is_same_v<Inner, Cone>)
				return GetSweptConeType();
			if (std::is_same_v<Inner, Sphere>)
				return GetSweptSphereType();
		}

		template <typename Inner>
		class SweptShape : public Shape
		{
		public:
			SweptShape(const Inner& a_inner, const NiPoint3& a_translation) :
				Shape(GetSweptType<Inner>()), inner(a_inner), translation(a_translation) {}
			SweptShape(const SweptShape& other) = default;
			SweptShape& operator=(const SweptShape&) = default;

			void GetLocation(NiPoint3& location) const
			{
				return inner.GetLocation(location);
			}

			void SetLocation(const NiPoint3& location)
			{
				return inner.SetLocation(location);
			}

			// members
			Inner    inner;        // 04
			NiPoint3 translation;  // ??
		};

		extern template class SweptShape<Sphere>;
		using MovingSphere = SweptShape<Sphere>;
		extern template class SweptShape<Cone>;
		using MovingCone = SweptShape<Cone>;
		extern template class SweptShape<Capsule>;
		using MovingCapsule = SweptShape<Capsule>;

		class GenericShape
		{
		public:
			// members
			union
			{
				Sphere        sphere;
				Cone          cone;
				Capsule       capsule;
				MovingSphere  movingSphere;
				MovingCone    movingCone;
				MovingCapsule movingCapsule;
			};
		};
		static_assert(sizeof(GenericShape) == 0x38);

		using Simplex = BSScrapArray<NiPoint3>;

		float CalculateAverageDistance(const LineSegment& s1, const NiPoint3& s2);

		float CalculateDistanceSquared(const LineSegment& s1, const NiPoint3& s2);
		float CalculateDistanceSquared(const LineSegment& s1, const LineSegment& s2);
		float CalculateDistanceSquared(const Parallelogram& s1, const LineSegment& s2);
		float CalculateDistanceSquared(const Cone& s1, const NiPoint3& s2);

		bool CalculateIntersection(const LineSegment& s1, const Sphere& s2, float& k_min, float& k_max);
		bool CalculateIntersection(const MovingSphere& s1, const MovingSphere& s2, float& k);

		NiPoint3 CalculateSupport(const Sphere& s, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Capsule& s, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Cone& s, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const MovingCapsule& s, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const MovingCone& s, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const MovingSphere& s, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Capsule& s1, const Capsule& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Capsule& s1, const Cone& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Capsule& s1, const Sphere& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Capsule& s1, const MovingCapsule& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Capsule& s1, const MovingCone& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Capsule& s1, const MovingSphere& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Cone& s1, const Cone& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Cone& s1, const Capsule& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Cone& s1, const Sphere& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Cone& s1, const MovingCapsule& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Cone& s1, const MovingCone& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Sphere& s1, const Sphere& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Sphere& s1, const Capsule& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const Sphere& s1, const Cone& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const MovingCapsule& s1, const Capsule& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const MovingCapsule& s1, const Cone& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const MovingCone& s1, const Capsule& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const MovingCone& s1, const Cone& s2, const NiPoint3& dir);
		NiPoint3 CalculateSupport(const MovingSphere& s1, const Sphere& s2, const NiPoint3& dir);

		bool CheckIntersection(const LineSegment& s1, const Sphere& s2);
		bool CheckIntersection(const GenericShape& s1, const GenericShape& s2);

		bool CheckIntersection(const Sphere& s1, const Capsule& s2);
		bool CheckIntersection(const Sphere& s1, const Cone& s2);
		bool CheckIntersection(const Sphere& s1, const MovingSphere& s2);
		bool CheckIntersection(const Sphere& s1, const MovingCapsule& s2);
		bool CheckIntersection(const Sphere& s1, const MovingCone& s2);
		bool CheckIntersection(const Capsule& s1, const Sphere& s2);
		bool CheckIntersection(const Capsule& s1, const Capsule& s2);
		bool CheckIntersection(const Capsule& s1, const MovingSphere& s2);
		bool CheckIntersection(const Cone& s1, const Sphere& s2);
		bool CheckIntersection(const Cone& s1, const MovingSphere& s2);
		bool CheckIntersection(const MovingSphere& s1, const Sphere& s2);
		bool CheckIntersection(const MovingSphere& s1, const Capsule& s2);
		bool CheckIntersection(const MovingSphere& s1, const Cone& s2);
		bool CheckIntersection(const MovingSphere& s1, const MovingSphere& s2);
		bool CheckIntersection(const MovingSphere& s1, const MovingCapsule& s2);
		bool CheckIntersection(const MovingSphere& s1, const MovingCone& s2);
		bool CheckIntersection(const MovingCapsule& s1, const Sphere& s2);
		bool CheckIntersection(const MovingCapsule& s1, const Capsule& s2);
		bool CheckIntersection(const MovingCapsule& s1, const MovingSphere& s2);
		bool CheckIntersection(const MovingCapsule& s1, const MovingCapsule& s2);
		bool CheckIntersection(const MovingCapsule& s1, const MovingCone& s2);
		bool CheckIntersection(const MovingCone& s1, const Sphere& s2);
		bool CheckIntersection(const MovingCone& s1, const MovingSphere& s2);
		bool CheckIntersection(const MovingCone& s1, const MovingCapsule& s2);
		bool CheckIntersection(const MovingCone& s1, const MovingCone& s2);

		bool CheckIntersectionGJK(const MovingCapsule& s1, const Capsule& s2);
		bool CheckIntersectionGJK(const MovingCapsule& s1, const Cone& s2);
		bool CheckIntersectionGJK(const MovingCone& s1, const Capsule& s2);
		bool CheckIntersectionGJK(const MovingCone& s1, const Cone& s2);
		bool CheckIntersectionGJK(const MovingSphere& s1, const Sphere& s2);
		bool CheckIntersectionGJK(const Capsule& s1, const Capsule& s2);
		bool CheckIntersectionGJK(const Capsule& s1, const MovingCapsule& s2);
		bool CheckIntersectionGJK(const Capsule& s1, const MovingCone& s2);
		bool CheckIntersectionGJK(const Capsule& s1, const MovingSphere& s2);
		bool CheckIntersectionGJK(const Capsule& s1, const Cone& s2);
		bool CheckIntersectionGJK(const Capsule& s1, const Sphere& s2);
		bool CheckIntersectionGJK(const Cone& s1, const Cone& s2);
		bool CheckIntersectionGJK(const Cone& s1, const MovingCapsule& s2);
		bool CheckIntersectionGJK(const Cone& s1, const MovingCone& s2);
		bool CheckIntersectionGJK(const Cone& s1, const Capsule& s2);
		bool CheckIntersectionGJK(const Cone& s1, const Sphere& s2);
		bool CheckIntersectionGJK(const Sphere& s1, const Sphere& s2);
		bool CheckIntersectionGJK(const Sphere& s1, const Capsule& s2);
		bool CheckIntersectionGJK(const Sphere& s1, const Cone& s2);

		void CreateCapsule(Actor* actor, const NiPoint3& actor_pos, Capsule& ans);
		void CreateMovingCapsule(Actor* actor, const NiPoint3& actor_moving, MovingCapsule& ans);

		bool UpdateSimplex(Simplex& simplex, NiPoint3& P);
	}
}
