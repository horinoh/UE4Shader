// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PixelGlobalShader.h"

#include "Components/ActorComponent.h"
#include "ShaderComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4SHADER_API UShaderComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UShaderComponent();

	//!< UActorComponent
	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void Draw();

	UTextureRenderTarget2D* GetTextureRenderTarget2D() const { return TextureRenderTarget2D; }

private:
	UPROPERTY(VisibleAnywhere, Category = RenderTarget)
	UTextureRenderTarget2D* TextureRenderTarget2D;
	FPixelShaderUniformBuffer UniformBuffer;
};
