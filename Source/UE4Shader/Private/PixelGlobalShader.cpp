// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Shader.h"
#include "PixelGlobalShader.h"

#include "ShaderParameterUtils.h"

/**
@brief ユニフォームバッファ
*/
IMPLEMENT_UNIFORM_BUFFER_STRUCT(FPixelShaderUniformBuffer, TEXT("PSUniform"))

FPixelGlobalShader::FPixelGlobalShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
	: FGlobalShader(Initializer)
{
}

void FPixelGlobalShader::ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment& OutEnvironment)
{
	FGlobalShader::ModifyCompilationEnvironment(Platform, OutEnvironment);
	OutEnvironment.CompilerFlags.Add(CFLAG_StandardOptimization);
}

void FPixelGlobalShader::SetUniformBuffer(FRHICommandList& CommandList, const FPixelShaderUniformBuffer& UniformBuffer)
{
	TUniformBufferRef<FPixelShaderUniformBuffer> Buffer;
	Buffer = TUniformBufferRef<FPixelShaderUniformBuffer>::CreateUniformBufferImmediate(UniformBuffer, UniformBuffer_SingleDraw);
	SetUniformBufferParameter(CommandList, GetPixelShader(), GetUniformBufferParameter<FPixelShaderUniformBuffer>(), Buffer);
}

/**
@note シェーダファイル名が "PixelGlobalShader" (.usfファイル名、ファイルはEngine/Shaders/以下へコピーしておく)
@note コールされるシェーダ関数名が "Main"
*/
IMPLEMENT_SHADER_TYPE(, FPixelGlobalShader, TEXT("PixelGlobalShader"), TEXT("Main"), SF_Pixel);