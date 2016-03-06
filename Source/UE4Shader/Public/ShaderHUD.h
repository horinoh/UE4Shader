// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "ShaderHUD.generated.h"

/**
 * 
 */
UCLASS()
class UE4SHADER_API AShaderHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AShaderHUD(const FObjectInitializer& ObjectInitializer);

	//!< AHUD
	virtual void DrawHUD() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Shader)
	class UShaderComponent* ShaderComp;
};
