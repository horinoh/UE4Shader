// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GlobalShader.h"

/**
@brief ユニフォームバッファ
*/
BEGIN_UNIFORM_BUFFER_STRUCT(FPixelShaderUniformBuffer, )
DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(float, AspectRatio)
DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(float, Timer)
END_UNIFORM_BUFFER_STRUCT(FPixelShaderUniformBuffer)

/**
 * 
 */
class UE4SHADER_API FPixelGlobalShader : public FGlobalShader
{
	DECLARE_SHADER_TYPE(FPixelGlobalShader, Global);

public:
	FPixelGlobalShader() {}
	explicit FPixelGlobalShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer);
	virtual ~FPixelGlobalShader() {}

	static bool ShouldCache(EShaderPlatform Platform) { return IsFeatureLevelSupported(Platform, ERHIFeatureLevel::SM5); }
	static void ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment& OutEnvironment);

	virtual void SetUniformBuffer(FRHICommandList& CommandList, const FPixelShaderUniformBuffer& UniformBuffer);
};
