#include "Globals.h"
#include "SpritePass.h"

#include "Application.h"
#include "ModuleD3D12.h"
#include "ModuleResources.h"
#include "ModuleFonts.h"

#include "SpriteFont.h"
#include "SpriteBatch.h"
#include "DirectXHelpers.h"
#include "ResourceUploadBatch.h"

SpritePass::SpritePass(SpriteDescriptors _spriteDescriptors)
{
	spriteDescriptors = _spriteDescriptors;

	ModuleD3D12* d3d12 = app->getD3D12();
	ID3D12Device* device = d3d12->getDevice();

	ResourceUploadBatch resourceUploadBatch(device);

	resourceUploadBatch.Begin();

	DirectX::RenderTargetState rtState(d3d12->getBackBufferFormat(), d3d12->getDepthStencilBufferFormat());
	DirectX::DX12::SpriteBatchPipelineStateDescription pipelineStateDesc(rtState);

	spriteBatch = std::make_unique<DirectX::DX12::SpriteBatch>(device, resourceUploadBatch, pipelineStateDesc);

	ModuleFonts* fonts = app->getFonts();
	for (std::vector<Font>::const_iterator::value_type font : fonts->getFonts())
	{
		spriteFonts.push_back(
			std::make_unique<SpriteFont>(
				device,
				resourceUploadBatch,
				font.getFilename(),
				spriteDescriptors.getFontCPUHandle(font.getIdx()),
				spriteDescriptors.getFontGPUHandle(font.getIdx())
			)
		);
	}

	ModuleResources* resources = app->getResources();

	//	for (int i = 0; i < filenameSprites.size(); ++i)
	//	{
	//		spriteTextures.push_back(resources->createTextureFromFile(filenameSprites[i]));
	//		CreateShaderResourceView(device, spriteTextures[i].Get(), spriteDescriptors.getTextureCPUHandle(i), /* isCubeMap */ false);
	//	}
	//

	std::future<void> callback = resourceUploadBatch.End(d3d12->getDrawCommandQueue());
	callback.wait();
};

SpritePass::~SpritePass()
{

}

void SpritePass::resize(float width, float height)
{
	ModuleD3D12* d3d12 = app->getD3D12();
	canvasSize = Vector2(width, height);
	D3D12_VIEWPORT viewport{ 0.0f, 0.0f, width, height, 0.0f, 1.0f };
	spriteBatch->SetViewport(viewport);
}

void SpritePass::record(ID3D12GraphicsCommandList* commandList, const std::vector<Label>& labels)
{ 
	beginRender(commandList);

	for (std::vector<Label>::const_iterator::value_type label : labels)
	{
		Vector2 position = Vector2::Zero;
		
		switch (label.getAlignment())
		{
		case Label::Alignment::Center:
			position = canvasSize * 0.5f;
			position = position + label.getOffset();
			break;
		default:
			break;
		}

		renderText(label.getText(), label.getFont(), position, label.getColor(), label.getRotation());
	}

	endRender(commandList);
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

void SpritePass::renderText(const char* text, UINT font, Vector2 position, Vector4 color, float rotation)
{ 
	_ASSERTE(font < spriteFonts.Size());
	Vector2 origin = spriteFonts[font]->MeasureString(text) / 2.f;
	spriteFonts[font]->DrawString(spriteBatch.get(), text, position, color, rotation, origin);
}

void SpritePass::renderSprite(UINT sprite, Vector2 position, Vector4 color)
{ 
	XMUINT2 size = GetTextureSize(spriteTextures[sprite].Get());
	Vector2 origin;
	origin.x = (float) size.x * 0.5f;
	origin.y = (float) size.y * 0.5f;
	spriteBatch->Draw(spriteDescriptors.getTextureGPUHandle(sprite), size, position, nullptr, color, 0.f, origin);
}