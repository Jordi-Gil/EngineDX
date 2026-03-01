#pragma once

#include "ShaderTableDesc.h"

class SpriteDescriptors
{
public:
	SpriteDescriptors() {};
	~SpriteDescriptors() = default;

	void init(ShaderTableDesc _fontDesc, ShaderTableDesc _imageDesc);

	D3D12_GPU_DESCRIPTOR_HANDLE getFontGPUHandle(UINT8 slot = 0) const;
	D3D12_CPU_DESCRIPTOR_HANDLE getFontCPUHandle(UINT8 slot = 0) const;

	D3D12_GPU_DESCRIPTOR_HANDLE getTextureGPUHandle(UINT8 slot = 0) const;
	D3D12_CPU_DESCRIPTOR_HANDLE getTextureCPUHandle(UINT8 slot = 0) const;

private:

	ShaderTableDesc fontDesc;
	ShaderTableDesc textureDesc;
};

