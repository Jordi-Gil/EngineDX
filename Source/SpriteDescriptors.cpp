#include "Globals.h"
#include "SpriteDescriptors.h"

void SpriteDescriptors::init(ShaderTableDesc _fontDesc, ShaderTableDesc _imageDesc)
{
	fontDesc = _fontDesc;
	textureDesc = _imageDesc;
}

D3D12_GPU_DESCRIPTOR_HANDLE SpriteDescriptors::getFontGPUHandle(UINT8 slot) const
{
	return fontDesc.getGPUHandle(slot);
}

D3D12_CPU_DESCRIPTOR_HANDLE SpriteDescriptors::getFontCPUHandle(UINT8 slot) const
{
	return fontDesc.getCPUHandle(slot);
}

D3D12_GPU_DESCRIPTOR_HANDLE SpriteDescriptors::getTextureGPUHandle(UINT8 slot) const
{
	return textureDesc.getGPUHandle(slot);
}

D3D12_CPU_DESCRIPTOR_HANDLE SpriteDescriptors::getTextureCPUHandle(UINT8 slot) const
{
	return textureDesc.getCPUHandle(slot);
}