#include "Globals.h"
#include "ModuleGameplaySystems.h"

#include "Application.h"
#include "ModuleScene.h"

#include "Factory.h"

bool ModuleGameplaySystems::init()
{
	Factory::CreateContext();

	return LoadGameplayDLL("GameplaySystems.dll");
}

bool ModuleGameplaySystems::LoadGameplayDLL(const char* path)
{
	if (gameCodeDLL)
	{
		LOG("DLL already loaded.");
		return false;
	}

	gameCodeDLL = LoadLibraryA(path);

	return gameCodeDLL != nullptr;
}

bool ModuleGameplaySystems::UnloadGameplayDLL()
{
	ModuleScene* scene = app->getScene();
	scene->clearScripts();

	if (!gameCodeDLL)
	{
		LOG("No DLL to unload.");
		return false;
	}

	FreeLibrary(gameCodeDLL);
	gameCodeDLL = nullptr;

	return true;
}