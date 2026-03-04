#pragma once

#include "Module.h"

class ModuleGameplaySystems : public Module
{
public:

	bool init() override;

private:

	bool LoadGameplayDLL(const char* path);
	bool UnloadGameplayDLL();
private:

	HMODULE gameCodeDLL = nullptr;
};

