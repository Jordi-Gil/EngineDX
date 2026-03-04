#include "Globals.h"
#include "Member.h"

const char* GetMemberTypeName(MemberType type)
{
	switch (type)
	{
	case MemberType::BOOL:
		return "Bool";
	case MemberType::INT:
		return "Int";
	case MemberType::UINT:
		return "Unsigned int";
	case MemberType::LONGLONG:
		return "Long Long";
	case MemberType::ULONGLONG:
		return "Unsigned Long Long";
	case MemberType::FLOAT:
		return "Float";
	case MemberType::VECTOR2:
		return "Vector2";
	case MemberType::VECTOR3:
		return "Vector3";
	case MemberType::VECTOR4:
		return "Vector4";
	case MemberType::DOUBLE:
		return "Double";
	case MemberType::STRING:
		return "String";
	case MemberType::GAME_OBJECT_UID:
	case MemberType::SCENE_RESOURCE:
	default:
		LOG("Member of type %i hasn't been registered in GetMemberType.", (unsigned)type);
		assert(false);
		return nullptr;
	}
}

MemberType GetMemberTypeFromName(const char* name) {
	if (strcmp(name, "Bool") == 0) {
		return MemberType::BOOL;
	}
	else if (strcmp(name, "Int") == 0) {
		return MemberType::INT;
	}
	else if (strcmp(name, "UInt") == 0) {
		return MemberType::UINT;
	}
	else if (strcmp(name, "LongLong") == 0) {
		return MemberType::LONGLONG;
	}
	else if (strcmp(name, "ULongLong") == 0) {
		return MemberType::ULONGLONG;
	}
	else if (strcmp(name, "Float") == 0) {
		return MemberType::FLOAT;
	}
	else if (strcmp(name, "Vector2") == 0) {
		return MemberType::VECTOR2;
	}
	else if (strcmp(name, "Vector3") == 0) {
		return MemberType::VECTOR3;
	}
	else if (strcmp(name, "Vector4") == 0) {
		return MemberType::VECTOR4;
	}
	else if (strcmp(name, "Double") == 0) {
		return MemberType::DOUBLE;
	}
	else if (strcmp(name, "String") == 0) {
		return MemberType::STRING;
	}
	else if (strcmp(name, "GameObjectUID") == 0) {
		return MemberType::GAME_OBJECT_UID;
	}
	else {
		LOG("No member of name %s exists.", (unsigned)name);
		assert(false); // ERROR: Invalid name
		return MemberType::UNKNOWN;
	}
}