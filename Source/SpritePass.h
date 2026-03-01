#pragma once

#include "SpriteDescriptors.h"

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

	SpritePass(SpriteDescriptors _spriteDescriptors, std::vector<const wchar_t*>& fonts, std::vector<const wchar_t*>& sprites);
	~SpritePass();
	void resize(float width, float height);

	void beginRender(ID3D12GraphicsCommandList* commandList);
	void endRender(ID3D12GraphicsCommandList* commandList);
	void renderText(const wchar_t* text, UINT font, Vector2 position, Vector4 color = { 1.0f, 1.0f , 1.0f , 1.0f });
	void renderSprite(UINT sprite, Vector2 position, Vector4 color = { 1.0f, 1.0f , 1.0f , 1.0f });

private:

	std::unique_ptr<SpriteBatch>				spriteBatch;
	std::vector<std::unique_ptr<SpriteFont>>	fonts;
	std::vector<ComPtr<ID3D12Resource>>			sprites;

	SpriteDescriptors							spriteDescriptors;
};

