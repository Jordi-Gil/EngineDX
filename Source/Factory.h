#pragma once

#include <string>

#if defined(ENGINE_API)
/* do nothing. */
#elif defined(_MSC_VER)
#define ENGINE_API __declspec(dllexport)
#endif

class Script;
class Creator;

namespace Factory
{
	void CreateContext();
	void DestroyContext();

	ENGINE_API Script* Create(const std::string& className);
	ENGINE_API void RegisterScript(const std::string& className, Creator* creator);
};

