// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Shader.h"
#include "ShaderComponent.h"

#include "RHIStaticStates.h"
#include "PipelineStateCache.h"

#include "VertexGlobalShader.h"

TGlobalResource<FVertexDeclaration> GVertexDeclaration;

UShaderComponent::UShaderComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;

	//!< In case create from contents
	//static ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> RT(TEXT("TextureRenderTarget2D'/Game/Textures/RT_Texture2D.RT_Texture2D'"));
	//if (nullptr != RT.Object)
	//{
	//	RenderTarget2D = RT.Object;
	//}
}

void UShaderComponent::InitializeComponent()
{
	Super::InitializeComponent();

	TextureRenderTarget2D = NewObject<UTextureRenderTarget2D>(this);
	if (nullptr != TextureRenderTarget2D)
	{
		TextureRenderTarget2D->InitAutoFormat(1024, 1024);
		//RenderTarget2D->OverrideFormat = EPixelFormat::PF_A32B32G32R32F;
		//RenderTarget2D->bNeedsTwoCopies = false;
		//RenderTarget2D->AddressX = TextureAddress::TA_Wrap;
		//RenderTarget2D->AddressY = TextureAddress::TA_Wrap;
		//RenderTarget2D->ClearColor = FLinearColor::Blue;
		//RenderTarget2D->UpdateResourceImmediate(true);
	}
}

void UShaderComponent::UninitializeComponent()
{
	Super::UninitializeComponent();
}

void UShaderComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction );

	UniformBuffer.AspectRatio = TextureRenderTarget2D->GetSurfaceWidth() / TextureRenderTarget2D->GetSurfaceHeight();
	UniformBuffer.Timer = GetWorld()->GetTimeSeconds();
	ENQUEUE_UNIQUE_RENDER_COMMAND_ONEPARAMETER(Draw,
		UShaderComponent*, ShaderComp, this,
		{
			ShaderComp->Draw();
		}
	);
}

void UShaderComponent::Draw()
{
	if (nullptr != TextureRenderTarget2D)
	{
		auto& CommandList = GRHICommandList.GetImmediateCommandList();

		SetRenderTarget(CommandList, TextureRenderTarget2D->GetRenderTargetResource()->GetRenderTargetTexture(), FTexture2DRHIRef());

		TShaderMapRef<FVertexGlobalShader> VertexShader(GetGlobalShaderMap(ERHIFeatureLevel::Type::SM5));
		TShaderMapRef<FPixelGlobalShader> PixelShader(GetGlobalShaderMap(ERHIFeatureLevel::Type::SM5));

		{
			FGraphicsPipelineStateInitializer GraphicsPS;

			GraphicsPS.RasterizerState = TStaticRasterizerState<>::GetRHI();
			GraphicsPS.BlendState = TStaticBlendState<>::GetRHI();
			GraphicsPS.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();

			//!< GVertexDeclaration is defined head of this file
			GraphicsPS.BoundShaderState.VertexDeclarationRHI = GVertexDeclaration.VertexDeclarationRHI;
			GraphicsPS.BoundShaderState.VertexShaderRHI = GETSAFERHISHADER_VERTEX(*VertexShader);
			GraphicsPS.BoundShaderState.PixelShaderRHI = GETSAFERHISHADER_PIXEL(*PixelShader);
			//GraphicsPS.PrimitiveType = PT_TriangleStrip;

			SetGraphicsPipelineState(CommandList, GraphicsPS, EApplyRendertargetOption::ForceApply);
		}

		PixelShader->SetUniformBuffer(CommandList, UniformBuffer);
		//PixelShader->SetSRV(CommandList, SRV);
		{
			TArray<FVertex> Vertices;
			Vertices.Add(FVertex());
			Vertices.Last().Position = FVector4(-1.0f, 1.0f, 0.0f, 1.0f);
			Vertices.Last().UV = FVector2D(0.0f, 0.0f);

			Vertices.Add(FVertex());
			Vertices.Last().Position = FVector4(1.0f, 1.0f, 0.0f, 1.0f);
			Vertices.Last().UV = FVector2D(1.0f, 0.0f);

			Vertices.Add(FVertex());
			Vertices.Last().Position = FVector4(-1.0f, -1.0f, 0.0f, 1.0f);
			Vertices.Last().UV = FVector2D(0.0f, 1.0f);

			Vertices.Add(FVertex());
			Vertices.Last().Position = FVector4(1.0f, -1.0f, 0.0f, 1.0f);
			Vertices.Last().UV = FVector2D(1.0f, 1.0f);

			DrawPrimitiveUP(CommandList, PT_TriangleStrip, Vertices.Num() - 2, &Vertices[0], sizeof(Vertices[0]));
		}
		//PixelShader->UnsetSRV(CommandList);
	}
}

