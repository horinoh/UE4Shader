// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Shader.h"
#include "VertexGlobalShader.h"

FVertexGlobalShader::FVertexGlobalShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
	: FGlobalShader(Initializer)
{
}

IMPLEMENT_SHADER_TYPE(, FVertexGlobalShader, TEXT("/Project/Private/VertexGlobalShader.usf"), TEXT("Main"), SF_Vertex);