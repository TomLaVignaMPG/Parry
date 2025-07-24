// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PA_TutorialSubsystem.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTutorialToggled, bool, bTutorialState);
UCLASS()
class PARRY_API UPA_TutorialSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnTutorialToggled OnTutorialToggled;
 
private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	bool bIsTutorialEnabled = true;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	bool bEnableTutorial = true;

public:

	UFUNCTION(BlueprintCallable)
	bool GetTutorialToggle() const { return bIsTutorialEnabled; }

	UFUNCTION(BlueprintCallable)
	void EnableTutorial();

	UFUNCTION(BlueprintCallable)
	void DisableTutorial();
};
