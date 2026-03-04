#include "RotateScript.h"

#include "GameplaySystems.h"

EXPOSE_MEMBERS(Rotate)

GENERATE_BODY_IMPL(Rotate)

void Rotate::Start()
{
	Debug::logEngine("Starting script");
}

void Rotate::Update()
{
	Debug::logEngine("Var: %d", i++);
}