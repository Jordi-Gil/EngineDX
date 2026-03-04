#include "Globals.h"
#include "DemoScripting.h"

#include "Application.h"
#include "ModuleScene.h"

#include "Script.h"

bool DemoScripting::init()
{
	ModuleScene* scene = app->getScene();
	scripts.push_back(scene->addScript("Rotate"));
	return true;
}

void DemoScripting::update()
{
	ModuleScene* scene = app->getScene();

	for (UINT scriptId : scripts)
	{
		ModuleScene::ScriptPtr script = scene->getScript(scriptId);
		script->Update();
	}
}