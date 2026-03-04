#include "Globals.h"
#include "Factory.h"

#include "Creator.h"
#include "Script.h"

#include <unordered_map>

struct FactoryContext
{
	std::unordered_map<std::string, Creator*> table;
};

static FactoryContext* factoryContext = nullptr;

void Factory::CreateContext()
{
	factoryContext = new FactoryContext();
}

void Factory::DestroyContext()
{
	delete factoryContext;
	factoryContext = nullptr;
}

Script* Factory::Create(const std::string& className)
{
	auto it = factoryContext->table.find(className);

	if (it != factoryContext->table.end())
	{
		return it->second->Create();
	}
	else
	{
		return (Script*) nullptr;
	}
}

void Factory::RegisterScript(const std::string& className, Creator* creator)
{
	factoryContext->table[className] = creator;
}