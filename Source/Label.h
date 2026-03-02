#pragma once

#include "Font.h"

class Label
{
public:

	enum class Alignment
	{
		Center
	};

	void				setFont(Font::FontIdx value) { font = (UINT)value; }
	void				setRotation(float value) { rotation = value; }
	void				setOffset(Vector2 value) { offset = value; }
	void				setColor(Vector4 value) { color = value; }
	void				setText(std::string value) { text = value; }
	void				setAlignment(Label::Alignment value) { alignment = value; }

	UINT				getFont() const { return font; }
	float				getRotation() const { return rotation; }
	Vector2				getOffset() const { return offset; }
	Vector4				getColor() const { return color; }
	const char*			getText() const { return text.data(); }
	Label::Alignment	getAlignment() const { return alignment; }
private:

	UINT font;
	Label::Alignment alignment;
	float rotation = 0.f;
	Vector2 offset = Vector2::Zero;
	Vector4 color = { 1.f, 1.f, 1.f, 1.f };
	std::string text;
};

