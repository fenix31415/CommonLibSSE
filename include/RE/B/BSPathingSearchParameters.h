#pragma once

namespace RE
{
	class BSPathingSearchParameters
	{
	public:
		float    PreferredFactor;
		float    TangentSmoothing;
		uint16_t RetryCount;
		uint16_t flags;
	};
	static_assert(sizeof(BSPathingSearchParameters) == 0xC);
}
