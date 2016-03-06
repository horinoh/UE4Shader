// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GlobalShader.h"

struct FVertex
{
	FVector4 Position;
	FVector2D UV;
};

class FVertexDeclaration : public FRenderResource
{
public:
	FVertexDeclarationRHIRef VertexDeclarationRHI;
	virtual ~FVertexDeclaration() {}
	virtual void InitRHI() override
	{
		FVertexDeclarationElementList Elements;
		const auto Stride = sizeof(FVertex);
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FVertex, Position), VET_Float4, 0, Stride));
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FVertex, UV), VET_Float2, 1, Stride));
		VertexDeclarationRHI = RHICreateVertexDeclaration(Elements);
	}
	virtual void ReleaseRHI() override
	{
		VertexDeclarationRHI.SafeRelease();
	}
};

/**
 * 
 */
class UE4SHADER_API FVertexGlobalShader : public FGlobalShader
{
	DECLARE_SHADER_TYPE(FVertexGlobalShader, Global);

public:
	FVertexGlobalShader() {}
	explicit FVertexGlobalShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer);
	virtual ~FVertexGlobalShader() {}

	static bool ShouldCache(EShaderPlatform Platform) { return IsFeatureLevelSupported(Platform, ERHIFeatureLevel::SM5); }
};
