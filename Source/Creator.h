#pragma once

#include "Factory.h"

#if defined(ENGINE_API)
/* do nothing. */
#elif defined(_MSC_VER)
#define ENGINE_API __declspec(dllexport)
#endif

class Script;

class ENGINE_API Creator
{
public:
	Creator(const std::string& className)
	{
		Factory::RegisterScript(className, this);
	}

	virtual ~Creator() {};

	virtual Script* Create() = 0;
};

template<class T>
class ENGINE_API CreatorImplementation : public Creator
{
public:
	CreatorImplementation<T>(const std::string& className) : Creator(className) { }

	virtual ~CreatorImplementation<T>() { }

	virtual Script* Create()
	{
		return new T();
	}
};

