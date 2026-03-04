#pragma once

#if defined(ENGINE_API)
/* do nothing. */
#elif defined(_MSC_VER)
#define ENGINE_API __declspec(dllexport)
#endif

namespace Time
{
	ENGINE_API uint64_t GetDeltaTime();
};

namespace Debug
{
	ENGINE_API void logEngine(const char* fmt, ...);
}
