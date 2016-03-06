// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Shader.h"
#include "ShaderGameMode.h"

#include "ShaderHUD.h"

AShaderGameMode::AShaderGameMode()
{
	HUDClass = AShaderHUD::StaticClass();
}
