#pragma once

#include "RE/B/bhkShapePhantom.h"
#include "RE/H/hkArray.h"
#include "RE/H/hkMatrix3.h"

namespace RE
{
	class hkpCdBodyPairCollector;
	class hkpCdPointCollector;
	struct hkpLinearCastInput;
	class hkpShape;
	class hkTransform;
	class NiTransform;

	class bhkSimpleShapePhantom : public bhkShapePhantom
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkSimpleShapePhantom;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkSimpleShapePhantom;

		~bhkSimpleShapePhantom() override;  // 00

		// override (bhkPhantom)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          Unk_2B(void) override;                              // 2B
		void          Unk_2C(void) override;                              // 2C
		void          Unk_2D(void) override;                              // 2D
		void          Unk_2E(void) override;                              // 2E
		void          Unk_2F(void) override;                              // 2F

		struct CtorParams
		{
			uint32_t          collFilterInfo;  // 00
			uint32_t          pad04;           // 04
			hkpShape*         shape;           // 08
			char              field_10;        // 10 - == 2
			char              pad11[7];        // 11
			hkArray<uint64_t> array;           // 18
			uint64_t          mb_pad28;        // 28
			hkMatrix4         orientation;     // 30
		};
		static_assert(sizeof(CtorParams) == 0x70);

		static bhkSimpleShapePhantom* Create(const CtorParams& params);
		static bhkSimpleShapePhantom* Create(hkpShape* shape, const hkTransform& transform, uint32_t collFilterInfo);

		void getClosestPoints(hkpCdPointCollector& collector);
		void getPenetrations(hkpCdBodyPairCollector& collector);
		void setTransform(const NiTransform& transform);
		void setTransform(const hkTransform& transform);
		void setPosition(const hkVector4& pos);
		void setPositionAndLinearCast(const hkVector4& position, const hkpLinearCastInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector);

	private:
		static bhkSimpleShapePhantom* ctor(bhkSimpleShapePhantom* _this, const CtorParams& params);
		static bhkSimpleShapePhantom* ctor(bhkSimpleShapePhantom* _this, hkpShape* shape, const hkTransform& transform, uint32_t collFilterInfo);
	};
	static_assert(sizeof(bhkSimpleShapePhantom) == 0x30);
}
