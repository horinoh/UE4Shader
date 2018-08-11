// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GlobalShader.h"

/**
@brief ユニフォームバッファ
*/
BEGIN_UNIFORM_BUFFER_STRUCT(FPixelShaderUniformBuffer, )
UNIFORM_MEMBER(float, AspectRatio)
UNIFORM_MEMBER(float, Timer)
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
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return true; }
	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment);

	virtual void SetUniformBuffer(FRHICommandList& CommandList, const FPixelShaderUniformBuffer& UniformBuffer);
};
