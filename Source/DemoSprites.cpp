#include "Globals.h"
#include "DemoSprites.h"

#include "Application.h"
#include "ModuleScene.h"
#include "Label.h"

bool DemoSprites::init()
{
	ModuleScene* scene = app->getScene();

	Label label;

	label.setFont(Font::FontIdx::Arial);
	label.setText("Hello World");
	label.setAlignment(Label::Alignment::Center);

	scene->addLabel(std::move(label));

	return true;
}