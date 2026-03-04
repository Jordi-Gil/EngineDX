#pragma once

#include "Creator.h"
#include "Member.h"

#define GENERATE_BODY(classname)										\
public:																	\
	classname(/* GameObject* owner_ */) : Script(/* owner_ */ ) {}      \
	const std::vector<Member>& GetMembers() const override;				\
																		\
private:																\
	static const CreatorImplementation<classname> creator;

#define GENERATE_BODY_IMPL(classname)										\
	const CreatorImplementation<classname> classname::creator(#classname);	\
																			\
	const std::vector<Member>& classname::GetMembers() const {				\
		return members;														\
	}


class Script
{
public:

	Script(/* GameObject* owner_ */ ) /* : owner(_owner) */ {}

	virtual const std::vector<Member>& GetMembers() const = 0;

	virtual void Update() = 0;
	virtual void Start() = 0;

	//virtual void OnButtonClick() { }
	//virtual void OnValueChanged() { }
	// ....
	//virtual void OnEnabled() { }
	//virtual void OnDisabled() { }

private:

	// GameObject* owner;
};

