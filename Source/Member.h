#pragma once

#include <variant>
#include <string>
#include <vector>
#include <SimpleMath.h>

/* Creating a new member type:
*    1. Add a new MemberType for the new member
*    2. Add the new member to the GetMemberTypeName and GetMemberTypeFromName functions in Member.cpp
*    3. Add the member editor functionality and serialization in ComponentScript.cpp
*/

#define MEMBER_VARIANT std::variant<bool, char, unsigned char, short, unsigned short, int, unsigned int, long long, unsigned long long, float, double, std::string, Vector2, Vector3, Vector4>

#define EXPOSE_MEMBERS(classname) \
	using ClassType = classname;  \
	static const std::vector<Member> members;

#define MEMBER(type, member) \
	Member(type, #member, offsetof(ClassType, member))

#define MEMBER_SEPARATOR(name) \
	Member(MemberType::SEPARATOR, name, 0)

#define GET_OFFSET_MEMBER(script, offset) \
	(((char*) script) + offset)


enum class MemberType
{
	UNKNOWN,

	// Numeric Types
	BOOL,
	INT,
	UINT,
	LONGLONG,
	ULONGLONG,
	FLOAT,
	VECTOR2,
	VECTOR3,
	VECTOR4,
	DOUBLE,

	// String
	STRING,

	// GAME_OBJECT_UID
	GAME_OBJECT_UID,

	// Resources
	SCENE_RESOURCE

};

struct Member
{
	Member(MemberType _type, const char* _name, size_t _offset) 
	: type(_type), name(_name), offset(_offset)
	{ }

	MemberType	type;
	const char* name;
	size_t		offset;
};

const char* GetMemberTypeName(MemberType type);
MemberType GetMemberTypeFromName(const char* name);