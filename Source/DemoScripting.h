#pragma once
#include "Module.h"

#include <vector>

class DemoScripting : public Module
{
public:

	virtual bool init() override;
	virtual void update() override;

private:

	std::vector<UINT> scripts;

};

