#include "Globals.h"
#include "SpritePass.h"

#include "Application.h"
#include "ModuleD3D12.h"
#include "ModuleResources.h"

#include "SpriteFont.h"
#include "SpriteBatch.h"
#include "DirectXHelpers.h"
#include "ResourceUploadBatch.h"

SpritePass::SpritePass(SpriteDescriptors _spriteDescriptors, std::vector<const wchar_t*>& filenameFonts, std::vector<const wchar_t*>& filenameSprites)
{
	spriteDescriptors = _spriteDescriptors;

	ModuleD3D12* d3d12 = app->getD3D12();
	ID3D12Device* device = d3d12->getDevice();

	ResourceUploadBatch resourceUploadBatch(device);

	resourceUploadBatch.Begin();

	DirectX::RenderTargetState rtState(d3d12->getBackBufferFormat(), d3d12->getDepthStencilBufferFormat());
	DirectX::DX12::SpriteBatchPipelineStateDescription pipelineStateDesc(rtState);

	spriteBatch = std::make_unique<DirectX::DX12::SpriteBatch>(device, resourceUploadBatch, pipelineStateDesc);


	for (int i = 0; i < filenameFonts.size(); ++i)
	{
		fonts.push_back(
			std::make_unique<SpriteFont>(
				device,
				resourceUploadBatch,
				filenameFonts[i],
				spriteDescriptors.getFontCPUHandle(i),
				spriteDescriptors.getFontGPUHandle(i)
			)
		);
	}

	ModuleResources* resources = app->getResources();

	for (int i = 0; i < filenameSprites.size(); ++i)
	{
		sprites.push_back(resources->createTextureFromFile(filenameSprites[i]));
		CreateShaderResourceView(device, sprites[i].Get(), spriteDescriptors.getTextureCPUHandle(i), /* isCubeMap */ false);
	}

	std::future<void> callback = resourceUploadBatch.End(d3d12->getDrawCommandQueue());
	callback.wait();
};

SpritePass::~SpritePass()
{

}

void SpritePass::resize(float width, float height)
{
	ModuleD3D12* d3d12 = app->getD3D12();

	D3D12_VIEWPORT viewport{ 0.0f, 0.0f, width, height, 0.0f, 1.0f };
	spriteBatch->SetViewport(viewport);
}

void SpritePass::beginRender(ID3D12GraphicsCommandList* commandList)
{
	BEGIN_EVENT(commandList, "Sprite Pass");
	spriteBatch->Begin(commandList);
}

void SpritePass::endRender(ID3D12GraphicsCommandList* commandList)
{ 
	spriteBatch->End();
	END_EVENT(commandList);
}

void SpritePass::renderText(const wchar_t* text, UINT font, Vector2 position, Vector4 color)
{ 
	_ASSERTE(font < fonts.Size());
	Vector2 origin = fonts[font]->MeasureString(text) / 2.f;
	fonts[font]->DrawString(spriteBatch.get(), text, position, color, 0.0f, origin);
}

void SpritePass::renderSprite(UINT sprite, Vector2 position, Vector4 color)
{ 
	XMUINT2 size = GetTextureSize(sprites[sprite].Get());
	Vector2 origin;
	origin.x = (float) size.x * 0.5f;
	origin.y = (float) size.y * 0.5f;
	spriteBatch->Draw(spriteDescriptors.getTextureGPUHandle(sprite), size, position, nullptr, color, 0.f, origin);
}