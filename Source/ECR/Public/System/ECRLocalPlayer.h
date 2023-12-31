﻿// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonLocalPlayer.h"
#include "AudioMixerBlueprintLibrary.h"
#include "ECRLocalPlayer.generated.h"

class UECRSettingsLocal;
class UECRSettingsShared;
class UInputMappingContext;

/**
 * UECRLocalPlayer
 */
UCLASS(BlueprintType)
class ECR_API UECRLocalPlayer : public UCommonLocalPlayer
{
	GENERATED_BODY()

public:
	UECRLocalPlayer();

	//~UObject interface
	virtual void PostInitProperties() override;
	//~End of UObject interface

public:
	UFUNCTION(BlueprintCallable)
	UECRSettingsLocal* GetLocalSettings() const;

	UFUNCTION(BlueprintCallable)
	UECRSettingsShared* GetSharedSettings() const;

	UFUNCTION(BlueprintCallable)
	void ResetSharedSettings();
	
protected:
	void OnAudioOutputDeviceChanged(const FString& InAudioOutputDeviceId);

	UFUNCTION()
	void OnCompletedAudioDeviceSwap(const FSwapAudioOutputResult& SwapResult);

private:
	UPROPERTY(Transient)
	mutable UECRSettingsShared* SharedSettings;

	UPROPERTY(Transient)
	mutable const UInputMappingContext* InputMappingContext;

	UPROPERTY()
	TWeakObjectPtr<APlayerController> LastBoundPC;
};
