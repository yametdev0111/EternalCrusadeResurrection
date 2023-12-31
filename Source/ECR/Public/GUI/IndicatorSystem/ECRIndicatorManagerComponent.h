﻿// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Components/ControllerComponent.h"
#include "Delegates/DelegateCombinations.h"

#include "ECRIndicatorManagerComponent.generated.h"

class UIndicatorDescriptor;

/**
 * @class UECRIndicatorManagerComponent
 */
UCLASS(BlueprintType, Blueprintable)
class ECR_API UECRIndicatorManagerComponent : public UControllerComponent
{
	GENERATED_BODY()

public:
	UECRIndicatorManagerComponent(const FObjectInitializer& ObjectInitializer);

	static UECRIndicatorManagerComponent* GetComponent(AController* Controller);

	UFUNCTION(BlueprintCallable, Category = Indicator)
	void AddIndicator(UIndicatorDescriptor* IndicatorDescriptor);
	
	UFUNCTION(BlueprintCallable, Category = Indicator)
	void RemoveIndicator(UIndicatorDescriptor* IndicatorDescriptor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNonDefaultHandledIndicatorAdded(UIndicatorDescriptor* IndicatorDescriptor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNonDefaultHandledIndicatorRemoved(UIndicatorDescriptor* IndicatorDescriptor);
	
	DECLARE_EVENT_OneParam(UECRIndicatorManagerComponent, FIndicatorEvent, UIndicatorDescriptor* Descriptor)
	FIndicatorEvent OnIndicatorAdded;
	FIndicatorEvent OnIndicatorRemoved;

	const TArray<UIndicatorDescriptor*>& GetIndicators() const { return Indicators; }

private:
	UPROPERTY()
	TArray<UIndicatorDescriptor*> Indicators;
};
