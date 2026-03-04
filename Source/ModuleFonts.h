#pragma once

#include <vector>

#include "Module.h"
#include "Font.h"

class ModuleFonts : public Module
{
public:

	virtual bool init();

	const std::vector<Font>&	getFonts() const { return fonts; }
	const Font getFont(Font::FontIdx idx) const 
	{ 
		_ASSERTE((UINT)idx < fonts.size());
		return fonts[(UINT)idx]; 
	}

private:

	std::vector<Font> fonts;
};