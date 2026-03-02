#pragma once

class Font
{
public:

	enum class FontIdx
	{
		Arial
	};

	static const char* GetFontString(Font::FontIdx font);

	Font(Font::FontIdx _fontIdx, const wchar_t* _filename) : fontIdx(_fontIdx), filename(_filename) {}

	UINT			getIdx() const { return (UINT)fontIdx; }
	const wchar_t*	getFilename() const { return filename; }

private:

	const wchar_t* filename;
	Font::FontIdx fontIdx;
};