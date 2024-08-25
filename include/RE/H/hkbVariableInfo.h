#pragma once

namespace RE
{
	struct hkbRoleAttribute
	{
		enum class Role : uint16_t
		{
			/// No particular role.
			ROLE_DEFAULT,

			/// The property should be interpreted as a filename (char*).
			ROLE_FILE_NAME,

			/// The property is a bone index (hkInt16).
			ROLE_BONE_INDEX,

			/// The property is a bone index map (hkArray<hkInt16>).  Note that it is not recommended that you use this
			/// attribute because you will not be able to bind such a node property to a character property.
			ROLE_BONE_INDEX_MAP,

			/// The property is an event ID (hkInt32)
			ROLE_EVENT_ID,

			/// The property is a behavior variable index (hkInt32).
			ROLE_VARIABLE_INDEX,

			/// The property is a behavior attribute index (hkInt32).
			ROLE_ATTRIBUTE_INDEX,

			/// The property is a time in seconds (hkReal).
			ROLE_TIME,

			/// The property is a script
			ROLE_SCRIPT,

			/// The property is a local frame
			ROLE_LOCAL_FRAME,

			/// The property is a bone attachment
			ROLE_BONE_ATTACHMENT,
		};

		enum class RoleFlag : uint16_t
		{
			/// No flags.
			FLAG_NONE = 0,

			/// The property refers to the ragdoll skeleton.  Use this in conjunction with
			/// ROLE_BONE_WEIGHT_ARRAY, ROLE_BONE_INDEX, or ROLE_BONE_INDEX_MAP.
			FLAG_RAGDOLL = 1,

			/// The property should be normalized (apply this to hkVector4).
			FLAG_NORMALIZED = 1 << 1,

			/// HAT will not allow the property to be bound to a variable.
			FLAG_NOT_VARIABLE = 1 << 2,

			/// HAT will not show the property in the UI.
			FLAG_HIDDEN = 1 << 3,

			/// The property is an output (otherwise it is an input).
			FLAG_OUTPUT = 1 << 4,

			/// HAT will not allow the property to be bound to a character property.
			FLAG_NOT_CHARACTER_PROPERTY = 1 << 5,
		};
		using RoleFlags = stl::enumeration<RoleFlag, uint16_t>;

		/// The role of the associated property.
		Role role;

		/// The flags for the associated property.
		RoleFlags flags;
	};
	static_assert(sizeof(hkbRoleAttribute) == 0x4);

	class hkbVariableInfo
	{
	public:
		enum class VariableType : uint8_t
		{
			VARIABLE_TYPE_INVALID = static_cast<uint8_t>(-1),

			// word-sized (at most)
			VARIABLE_TYPE_BOOL = 0,
			VARIABLE_TYPE_INT8,
			VARIABLE_TYPE_INT16,
			VARIABLE_TYPE_INT32,
			VARIABLE_TYPE_REAL,

			VARIABLE_TYPE_POINTER,  // this must be after the word-sized types and before the quad-sized types

			// quad-word sized
			VARIABLE_TYPE_VECTOR3,
			VARIABLE_TYPE_VECTOR4,
			VARIABLE_TYPE_QUATERNION,
		};

		// members
		hkbRoleAttribute role; // 00
		VariableType     type; // 04
	};
	static_assert(sizeof(hkbVariableInfo) == 0x6);
}
