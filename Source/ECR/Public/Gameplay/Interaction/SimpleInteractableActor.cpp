﻿#include "SimpleInteractableActor.h"

ASimpleInteractableActor::ASimpleInteractableActor(const FObjectInitializer& ObjectInitializer)
{
}

void ASimpleInteractableActor::GatherInteractionOptions(const FInteractionQuery& InteractQuery,
                                                        FInteractionOptionBuilder& OptionBuilder)
{
	TArray<FInteractionOption> InteractionOptions = GetInteractionOptions(InteractQuery);
	for (FInteractionOption InteractionOption : InteractionOptions)
	{
		InteractionOption.AbilitySource = this;
		OptionBuilder.AddInteractionOption(InteractionOption);
	}
}
