#pragma once

namespace RE
{
	class hkbEventInfo
	{
	public:
		/// Definitions of flags that influence the behavior of events.
		enum class Flag : uint32_t
		{
			/// Whether or not clip generators should raise the event.
			FLAG_SILENT = 0x1,

			/// Whether or not the sync point will be
			FLAG_SYNC_POINT = 0x2,
		};
		using Flags = stl::enumeration<Flag, uint32_t>;

		// members
		Flags flags;  // 00 - The flags that influence the behavior of events.
	};
	static_assert(sizeof(hkbEventInfo) == 0x4);
}
