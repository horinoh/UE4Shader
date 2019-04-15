// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GlobalShader.h"

/**
@brief ユニフォームバッファ
*/
BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FPixelShaderUniformBuffer, )
SHADER_PARAMETER(float, AspectRatio)
SHADER_PARAMETER(float, Timer)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

/**
 * 
 */
class UE4SHADER_API FPixelGlobalShader : public FGlobalShader
{
	DECLARE_SHADER_TYPE(FPixelGlobalShader, Global);
	//DECLARE_EXPORTED_SHADER_TYPE(FPixelGlobalShader, Global,)
public:
	FPixelGlobalShader() {}
	explicit FPixelGlobalShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer);
	virtual ~FPixelGlobalShader() {}

	static bool ShouldCache(EShaderPlatform Platform) { return IsFeatureLevelSupported(Platform, ERHIFeatureLevel::SM5); }
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return true; }
	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment);

	virtual void SetUniformBuffer(FRHICommandList& CommandList, const FPixelShaderUniformBuffer& UniformBuffer);
};
