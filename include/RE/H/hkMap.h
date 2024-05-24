#pragma once

#include "RE/H/hkContainerAllocators.h"

namespace RE
{
	struct hkMap64
	{
	public:
		uint32_t insert(int64_t key, int64_t val)
		{
			REL::Relocation<uint32_t(hkMap64*, void*, uint64_t key, int64_t val)> func(RELOCATION_ID(56771, 0));  // I do not know for AE
			return func(this, RE::hkContainerHeapAllocator::GetSingleton(), key, val);
		}

		int64_t getWithDefault(int64_t key, int64_t val_default)
		{
			REL::Relocation<int64_t(hkMap64*, int64_t, int64_t)> func(RELOCATION_ID(56768, 0));  // I do not know for AE
			return func(this, key, val_default);
		}

	private:
		struct Entry
		{
			uint64_t key;
			uint64_t val;
		};
		static_assert(sizeof(Entry) == 0x10);

	public:
		// members
		Entry*   data;
		uint32_t size;
		uint32_t cap;
	};
	static_assert(sizeof(hkMap64) == 0x10);
}
