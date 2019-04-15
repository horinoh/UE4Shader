// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Shader.h"
#include "PixelGlobalShader.h"

#include "ShaderParameterUtils.h"

IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FPixelShaderUniformBuffer, "PSUniform");

FPixelGlobalShader::FPixelGlobalShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
	: FGlobalShader(Initializer)
{
}

void FPixelGlobalShader::ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
{
	FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
	OutEnvironment.CompilerFlags.Add(CFLAG_StandardOptimization);
}

void FPixelGlobalShader::SetUniformBuffer(FRHICommandList& CommandList, const FPixelShaderUniformBuffer& UniformBuffer)
{
	TUniformBufferRef<FPixelShaderUniformBuffer> Buffer;
	Buffer = TUniformBufferRef<FPixelShaderUniformBuffer>::CreateUniformBufferImmediate(UniformBuffer, UniformBuffer_SingleDraw);
	SetUniformBufferParameter(CommandList, GetPixelShader(), GetUniformBufferParameter<FPixelShaderUniformBuffer>(), Buffer);
}

IMPLEMENT_SHADER_TYPE(, FPixelGlobalShader, TEXT("/Project/Private/PixelGlobalShader.usf"), TEXT("Main"), SF_Pixel);