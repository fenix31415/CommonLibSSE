#pragma once

namespace RE
{
	class hkbContext;

	class BSISpeedSamplerDB
	{
	public:
		virtual ~BSISpeedSamplerDB() = default;
		virtual float QuerySpeed(hkbContext* ctx, int32_t iState, float direction, float goalSpeed) = 0;
	};
	static_assert(sizeof(BSISpeedSamplerDB) == 8);
}
