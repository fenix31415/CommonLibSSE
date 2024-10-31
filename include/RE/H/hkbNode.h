#pragma once

#include "RE/H/hkStringPtr.h"
#include "RE/H/hkbBindable.h"
#include "RE/H/hkbContext.h"

namespace RE
{
	class hkbEvent;
	class hkbNode;

	/// Stores returned info about a child of a node.
	struct hkbNodeChildInfo
	{
		hkbNodeChildInfo() = default;

		// members
		hkbNode* node{};                 // 00 - The child node template
		bool     ignoreEvents{ false };  // 08 - If true, events will not be sent to the nodes and events generated by the node will not be forwarded
		bool     reset{ false };         // 09 - Whether to reset the node asap (deactivate and then activate)
		bool     syncToParent{ false };  // 0A - Whether or not to synchronize this node with the parent
		bool     stopped{ false };       // 0B - Whether or not the parent wants this child to be moved forward in time
		char     pad0C[4];               // 0C
	};
	static_assert(sizeof(hkbNodeChildInfo) == 0x10);

	class hkbNode : public hkbBindable
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbNode;
		inline static constexpr auto VTABLE = VTABLE_hkbNode;

		/// Stores returned info about the children of a node.
		struct ChildrenInfo
		{
			ChildrenInfo(hkArray<hkbNodeChildInfo>& childInfos) :
				childInfos(childInfos) {}

			// members
			hkArray<hkbNodeChildInfo>& childInfos;  // 00 - An array of child info (must be allocated by the caller)
			uint8_t                    unk08;       // 08
			uint8_t                    unk09;       // 09
			uint8_t                    unk0A;       // 0A
			uint8_t                    unk0B;       // 0B
			char                       pad0C[4];    // 0C
		};
		static_assert(sizeof(ChildrenInfo) == 0x10);

		/// Flags used when calling GenNumChildren() or GetChildren().
		enum class GetChildrenFlagBits : int32_t
		{
			kActiveOnly = 1 << 0,      // If true, only return the active children (otherwise, all children).
			kGeneratorsOnly = 1 << 1,  // // If true, only return generators (else also return modifiers).
			// If true, the behavior graphs pointed to by hkbBehaviorReferenceGenerators
			// will be ignored (along with all of their descendants).
			kIgnoreReferencedBehaviour = 1 << 2
		};
		using GET_CHILDREN_FLAGS = stl::enumeration<GetChildrenFlagBits, int32_t>;

		enum class CloneState : uint8_t
		{
			kDefault = 0,
			kTemplate = 1,
			kClone = 2,
			kShareable = 3
		};

		~hkbNode() override;  // 00

		// add
		virtual void Activate(const hkbContext& a_context);                     // 04 - { return; }
		virtual void Update(const hkbContext& a_context, float a_timestep);     // 05 - { userData |= 1; }
		virtual void handleEvent(const hkbContext& ctx, hkbEvent& event);       // 06 - { return; }
		virtual void Deactivate(const hkbContext& a_context);                   // 07 - { return; }
		virtual int  getMaxNumChildren(GET_CHILDREN_FLAGS flags);               // 08 - { return 2; }
		virtual void getChildren(GET_CHILDREN_FLAGS flags, ChildrenInfo& ans);  // 09 - { return; }
		virtual void isValid(void);                                             // 0A - { return 1; }
		virtual void precompute(void);                                          // 0B - { return; }
		virtual void cloneNode(void);                                           // 0C
		virtual void createInternalState(void);                                 // 0D - { return 0; }
		virtual void getInternalState(void);                                    // 0E - { return; }
		virtual void getInternalStateUser(void);                                // 0F - { return; }
		virtual void setInternalState(void);                                    // 10 - { return; }
		virtual void setInternalStateUser(void);                                // 11 - { return; }
		virtual void getActiveEvents(void);                                     // 12 - { return; }
		virtual void Unk_13(void);                                              // 13 - { return 0; }
		virtual void getActiveVariablesSpecial(void);                           // 14 - { return; }
		virtual bool isGenerator() const;                                       // 15 - { return 0; }
		virtual bool isGraph() const;                                           // 16 - { return 0; }

		// members
		std::uint64_t userData;    // 30
		hkStringPtr   name;        // 38
		std::uint16_t id;          // 40
		CloneState    cloneState;  // 42
		std::uint8_t  pad43;       // 43
		std::uint32_t pad44;       // 44
	};
	static_assert(sizeof(hkbNode) == 0x48);

	using GET_CHILDREN_FLAG = hkbNode::GetChildrenFlagBits;
	using GET_CHILDREN_FLAGS = hkbNode::GET_CHILDREN_FLAGS;
}
