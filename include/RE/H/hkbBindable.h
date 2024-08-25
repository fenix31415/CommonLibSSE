#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkRefPtr.h"
#include "RE/H/hkStringPtr.h"
#include "RE/H/hkReferencedObject.h"

namespace RE
{
	class hkClass;
	class hkRefVariant;
	
	class hkbVariableBindingSet : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbVariableBindingSet;
		inline static constexpr auto VTABLE = VTABLE_hkbVariableBindingSet;

		struct Binding
		{
		public:
			/// Which data we are binding to.
			enum class BindingType : uint8_t
			{
				/// Binding to a variable.
				BINDING_TYPE_VARIABLE,

				/// Binding to a character property.
				BINDING_TYPE_CHARACTER_PROPERTY,
			};

			// members
			hkStringPtr memberPath;             // 00
			hkClass*    memberClass;            // 08
			int32_t     offsetInObjectPlusOne;  // 10
			int32_t     offsetInArrayPlusOne;   // 14
			int32_t     rootVariableIndex;      // 18
			int32_t     variableIndex;          // 1C
			int8_t      bitIndex;               // 20
			BindingType bindingType;            // 21
			int8_t      memberType;             // 22
			int8_t      variableType;           // 23
			int8_t      flags;                  // 24
			char        pad25[3];               // 25
		};
		static_assert(sizeof(Binding) == 0x28);

		
		/// Add a binding to the set.
		///
		/// The memberPath is made up of member names, separated by '/'.
		/// Integers after colons in the path are array indices.
		/// For example, "children:2/blendWeight" would seek an array
		/// member named "children", access the second member, and then
		/// look for a member named "blendWeight" in that object.
		void addBinding(const char* memberPath, int32_t variableIndex, Binding::BindingType bindingType = Binding::BindingType::BINDING_TYPE_VARIABLE, int32_t bitIndex = -1)
		{
			REL::Relocation<decltype(&hkbVariableBindingSet::addBinding)> func(RELOCATION_ID(58805, 0));  // I do not know for AE
			return func(this, memberPath, variableIndex, bindingType, bitIndex);
		}

		static hkbVariableBindingSet* Create()
		{
			auto ans = hk_malloc<hkbVariableBindingSet>();
			std::memset(ans, 0, sizeof(hkbVariableBindingSet));
			stl::emplace_vtable(ans);
			ans->indexOfBindingToEnable = -1;
			return ans;
		}

		// members
		hkArray<Binding> bindings;                // 10
		int32_t          indexOfBindingToEnable;  // 20
		bool             hasOutputBinding;        // 24
		char             pad25[3];                // 25
	};
	static_assert(sizeof(hkbVariableBindingSet) == 0x28);

	class hkbBindable : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbBindable;
		inline static constexpr auto VTABLE = VTABLE_hkbBindable;

		~hkbBindable() override;  // 00

		// add
		virtual void Unk_03(void);  // 03

		// members
		hkRefPtr<hkbVariableBindingSet> variableBindingSet;  // 10
		hkArray<hkRefVariant>           cachedBindables;     // 18
		bool                            areBindablesCached;  // 28
		std::uint8_t                    pad29;               // 29
		std::uint16_t                   pad2A;               // 2A
		std::uint32_t                   pad2C;               // 2C
	};
	static_assert(sizeof(hkbBindable) == 0x30);
}
