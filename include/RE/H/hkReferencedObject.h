#pragma once

#include "RE/H/hkBaseObject.h"

namespace RE
{
	class hkCustomAttributes;

	/// Reflection information for any reflected type.
	class hkClass
	{
	public:
		enum FlagValues
		{
			kFlagsNone = 0,
			kFlagsNotSerializable = 1
		};
		using Flags = stl::enumeration<FlagValues, std::uint32_t>;

		const char*                name;                      // 00
		const hkClass*             parent;                    // 08
		std::int32_t               objectSize;                // 10
		std::int32_t               numImplementedInterfaces;  // 14
		const class hkClassEnum*   declaredEnums;             // 18
		std::int32_t               numDeclaredEnums;          // 20
		std::uint32_t              pad24;                     // 24
		const class hkClassMember* declaredMembers;           // 28
		std::int32_t               numDeclaredMembers;        // 30
		std::uint32_t              pad34;                     // 34
		const void*                defaults;                  // 38
		const hkCustomAttributes*  attributes;                // 40
		Flags                      flags;                     // 48
		std::int32_t               describedVersion;          // 4C
	};
	static_assert(sizeof(hkClass) == 0x50);
	class hkStatisticsCollector;

	class hkReferencedObject : public hkBaseObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkReferencedObject;
		inline static constexpr auto VTABLE = VTABLE_hkReferencedObject;

		enum class LockMode
		{
			kNone = 0,
			kAuto,
			kManual
		};

		enum
		{
			kMemSize = 0x7FFF
		};

		hkReferencedObject();
		~hkReferencedObject() override = default;  // 00

		// add
		virtual const hkClass* GetClassType() const;                                                                     // 01 - { return 0; }
		virtual void           CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const;  // 02

		void         AddReference() const;
		std::int32_t GetAllocatedSize() const;
		std::int32_t GetReferenceCount() const;
		void         RemoveReference() const;

		// members
		std::uint16_t                 memSizeAndFlags;  // 08
		volatile mutable std::int16_t referenceCount;   // 0A
		std::uint32_t                 pad0C;            // 0C
	};
	static_assert(sizeof(hkReferencedObject) == 0x10);
}
