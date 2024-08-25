#include "RE/B/bhkSimpleShapePhantom.h"

namespace RE
{
	bhkSimpleShapePhantom* bhkSimpleShapePhantom::ctor(bhkSimpleShapePhantom* _this, const CtorParams& params)
	{
		using func_t = bhkSimpleShapePhantom*(bhkSimpleShapePhantom * _this, const CtorParams& params);
		REL::Relocation<func_t> func{ RELOCATION_ID(37690, 0) };  // I do not know for AE
		return func(_this, params);
	}

	bhkSimpleShapePhantom* bhkSimpleShapePhantom::ctor(bhkSimpleShapePhantom* _this, hkpShape* shape, const hkTransform& transform, uint32_t collFilterInfo)
	{
		using func_t = bhkSimpleShapePhantom*(bhkSimpleShapePhantom * _this, hkpShape * shape, const hkTransform& transform, uint32_t collFilterInfo);
		REL::Relocation<func_t> func{ RELOCATION_ID(60675, 0) };  // I do not know for AE
		return func(_this, shape, transform, collFilterInfo);
	}

	bhkSimpleShapePhantom* bhkSimpleShapePhantom::Create(const CtorParams& params)
	{
		auto ans = malloc<bhkSimpleShapePhantom>();
		ctor(ans, params);
		return ans;
	}

	bhkSimpleShapePhantom* bhkSimpleShapePhantom::Create(hkpShape* shape, const hkTransform& transform, uint32_t collFilterInfo)
	{
		auto ans = malloc<bhkSimpleShapePhantom>();
		ctor(ans, shape, transform, collFilterInfo);
		return ans;
	}

	void bhkSimpleShapePhantom::getClosestPoints(hkpCdPointCollector& collector)
	{
		using func_t = decltype(&bhkSimpleShapePhantom::getClosestPoints);
		REL::Relocation<func_t> func{ RELOCATION_ID(76897, 0) };  // I do not know for AE
		return func(this, collector);
	}

	void bhkSimpleShapePhantom::getPenetrations(hkpCdBodyPairCollector& collector)
	{
		using func_t = decltype(&bhkSimpleShapePhantom::getPenetrations);
		REL::Relocation<func_t> func{ RELOCATION_ID(76898, 0) };  // I do not know for AE
		return func(this, collector);
	}

	void bhkSimpleShapePhantom::setTransform(const NiTransform& transform)
	{
		using func_t = void(bhkSimpleShapePhantom*, const NiTransform&);
		REL::Relocation<func_t> func{ RELOCATION_ID(19678, 0) };  // I do not know for AE
		return func(this, transform);
	}

	void bhkSimpleShapePhantom::setTransform(const hkTransform& transform)
	{
		using func_t = void(bhkSimpleShapePhantom*, const hkTransform&);
		REL::Relocation<func_t> func{ RELOCATION_ID(76894, 0) };  // I do not know for AE
		return func(this, transform);
	}

	void bhkSimpleShapePhantom::setPosition(const hkVector4& pos)
	{
		using func_t = decltype(&bhkSimpleShapePhantom::setPosition);
		REL::Relocation<func_t> func{ RELOCATION_ID(76895, 0) };  // I do not know for AE
		return func(this, pos);
	}

	void bhkSimpleShapePhantom::setPositionAndLinearCast(const hkVector4& position, const hkpLinearCastInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector)
	{
		using func_t = decltype(&bhkSimpleShapePhantom::setPositionAndLinearCast);
		REL::Relocation<func_t> func{ RELOCATION_ID(76896, 0) };  // I do not know for AE
		return func(this, position, input, castCollector, startCollector);
	}
}
