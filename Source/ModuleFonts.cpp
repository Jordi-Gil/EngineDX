#include "Globals.h"
#include "ModuleFonts.h"

bool ModuleFonts::init()
{
	fonts.push_back({ Font::FontIdx::Arial , L"./Assets/Fonts/arial.spritefont" });
	return true;
}