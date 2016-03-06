// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Shader.h"
#include "VertexGlobalShader.h"

FVertexGlobalShader::FVertexGlobalShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
	: FGlobalShader(Initializer)
{
}

/**
@note シェーダファイル名が "VertexGlobalShader" (.usfファイル名、ファイルはEngine/Shaders/以下へコピーしておく)
@note コールされるシェーダ関数名が "Main"
*/
IMPLEMENT_SHADER_TYPE(, FVertexGlobalShader, TEXT("VertexGlobalShader"), TEXT("Main"), SF_Vertex);