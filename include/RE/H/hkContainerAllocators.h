#pragma once

#include "RE/H/hkMemoryAllocator.h"

namespace RE
{
	struct hkContainerHeapAllocator
	{
		struct Allocator : public hkMemoryAllocator
		{
			inline static constexpr auto RTTI = RTTI_hkContainerHeapAllocator__Allocator;
			inline static constexpr auto VTABLE = VTABLE_hkContainerHeapAllocator__Allocator;

			~Allocator() override;  // 00

			void*        BlockAlloc(std::int32_t a_numBytes) override;                           // 01
			void         BlockFree(void* a_ptr, std::int32_t a_numBytes) override;               // 02
			void*        BufAlloc(std::int32_t& a_reqNumBytesInOut) override;                    // 03
			void         BufFree(void* a_ptr, std::int32_t a_numBytes) override;                 // 04
			void         GetMemoryStatistics(MemoryStatistics& a_usage) override;                // 08
			std::int32_t GetAllocatedSize(const void* a_obj, std::int32_t a_numBytes) override;  // 09
		};
		static_assert(sizeof(Allocator) == 0x8);

		[[nodiscard]] static Allocator* GetSingleton()
		{
			REL::Relocation<hkContainerHeapAllocator::Allocator*> singleton{ RELOCATION_ID(510713, 383828) };
			return singleton.get();
		}
	};
	static_assert(sizeof(hkContainerHeapAllocator) == 0x1);

	inline void* hk_malloc(std::size_t a_size)
	{
		return hkContainerHeapAllocator::GetSingleton()->BlockAlloc(static_cast<int32_t>(a_size));
	}

	template <class T>
	inline T* hk_malloc(std::size_t a_size)
	{
		return static_cast<T*>(hk_malloc(a_size));
	}

	template <class T>
	inline T* hk_malloc()
	{
		return hk_malloc<T>(sizeof(T));
	}

	inline void* hk_calloc(std::size_t a_num, std::size_t a_size)
	{
		const auto ret = hk_malloc(a_num * a_size);
		if (ret) {
			std::memset(ret, 0, a_num * a_size);
		}
		return ret;
	}

	template <class T>
	inline T* hk_calloc(std::size_t a_num, std::size_t a_size)
	{
		return static_cast<T*>(hk_calloc(a_num, a_size));
	}

	template <class T>
	inline T* hk_calloc(std::size_t a_num)
	{
		return hk_calloc<T>(a_num, sizeof(T));
	}

	inline void hk_free(void* a_ptr, int32_t numBytes)
	{
		return hkContainerHeapAllocator::GetSingleton()->BlockFree(a_ptr, numBytes);
	}
}
