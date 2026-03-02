#pragma once

#include "SpriteDescriptors.h"
#include "Label.h"

namespace DirectX
{
	inline namespace DX12
	{
		class SpriteFont;
		class SpriteBatch;
	}
}

class SpritePass
{
public:

	SpritePass(SpriteDescriptors _spriteDescriptors);
	~SpritePass();
	void resize(float width, float height);

public:

	void record(ID3D12GraphicsCommandList* commandList, const std::vector<Label>& labels);

private:

	void beginRender(ID3D12GraphicsCommandList* commandList);
	void endRender(ID3D12GraphicsCommandList* commandList);
	void renderText(const char* text, UINT font, Vector2 position, Vector4 color, float rotation);
	void renderSprite(UINT sprite, Vector2 position, Vector4 color = { 1.0f, 1.0f , 1.0f , 1.0f });

private:

	Vector2										canvasSize;
	std::unique_ptr<SpriteBatch>				spriteBatch;
	std::vector<std::unique_ptr<SpriteFont>>	spriteFonts;
	std::vector<ComPtr<ID3D12Resource>>			spriteTextures;

	SpriteDescriptors							spriteDescriptors;
};

