#include "Globals.h"
#include "Font.h"

const char* Font::GetFontString(Font::FontIdx font)
{
	switch (font)
	{
	case Font::FontIdx::Arial:
		return "Arial";
	default:
		_ASSERTE(false);
	}
}