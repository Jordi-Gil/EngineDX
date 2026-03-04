#include "Globals.h"
#include "GameplaySystems.h"

#include "Application.h"

uint64_t Time::GetDeltaTime()
{
	return app->getElapsedMilis();
}

void Debug::logEngine(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	LOG(fmt, args);
	va_end(args);
}