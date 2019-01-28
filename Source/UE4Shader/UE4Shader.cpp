// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Shader.h"

class FShaderGameModuleImpl : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override
	{
		FDefaultGameModuleImpl::StartupModule();

		AddShaderSourceDirectoryMapping(TEXT("/Project"), FPaths::Combine(FPaths::ProjectDir(), TEXT("Shaders")));
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FShaderGameModuleImpl, UE4Shader, "UE4Shader" );
