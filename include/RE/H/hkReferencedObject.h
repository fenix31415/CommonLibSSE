#pragma once

#include "RE/H/hkBaseObject.h"

namespace RE
{
	class hkClassEnum;
	class hkClassMember;
	class hkCustomAttributes;

	/// Reflection information for any reflected type.
	/// Reflection is based upon the Java object model where any
	/// class has exactly zero or one parents and may implement
	/// zero or more interfaces. An interface is a class which
	/// has virtual methods but no data members.
	class hkClass
	{
	public:
		enum class Flag : uint32_t
		{
			FLAGS_NONE = 0,
			FLAGS_NOT_SERIALIZABLE = 1
		};
		using Flags = RE::stl::enumeration<Flag, uint32_t>;

		/// Are we a parent class of class k
		bool isSuperClass(const hkClass& k) const
		{
			for (const hkClass* clas = &k; clas; clas = clas->parent) {
				if (!std::strcmp(clas->name, name)) {
					return true;
				}
			}
			return false;
		}

		// members
		const char*               name;                      // 00 - Name of this type
		const hkClass*            parent;                    // 08 - Parent class
		int32_t                   objectSize;                // 10 - Size of the live instance
		int32_t                   numImplementedInterfaces;  // 14 - Number of interfaces implemented by this class
		const hkClassEnum*        declaredEnums;             // 18 - Declared enum members
		int32_t                   numDeclaredEnums;          // 20 - Number of enums declared in this class
		char                      pad24[4];                  // 24
		const hkClassMember*      declaredMembers;           // 28 - Declared members
		int32_t                   numDeclaredMembers;        // 30 - Number of members declared in this class
		char                      pad34[4];                  // 34
		const void*               defaults;                  // 38 - Default values for this class
		const hkCustomAttributes* attributes;                // 40 - Default values for this class
		Flags                     flags;                     // 48
		int32_t                   m_describedVersion;        // 4C - Version of described object
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
