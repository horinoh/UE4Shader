// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Shader.h"
#include "ShaderHUD.h"

#include "ShaderComponent.h"

AShaderHUD::AShaderHUD(const FObjectInitializer& ObjectInitializer)
{
	ShaderComp = ObjectInitializer.CreateDefaultSubobject<UShaderComponent>(this, TEXT("Shader"));
}

void AShaderHUD::DrawHUD()
{
	Super::DrawHUD();

	if (nullptr != Canvas)
	{
		if (nullptr != ShaderComp)
		{
			const auto TextureRenderTarget2D = ShaderComp->GetTextureRenderTarget2D();
			if (nullptr != TextureRenderTarget2D)
			{
				const FVector2D ScreenSize(Canvas->SizeX, Canvas->SizeY);
				FCanvasTileItem Item(FVector2D::ZeroVector, TextureRenderTarget2D->Resource, ScreenSize, FLinearColor::White);
				Item.BlendMode = SE_BLEND_Opaque;
				Canvas->DrawItem(Item);
			}
		}
	}
}
