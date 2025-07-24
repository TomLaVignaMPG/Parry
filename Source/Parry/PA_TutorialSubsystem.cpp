// Fill out your copyright notice in the Description page of Project Settings.


#include "PA_TutorialSubsystem.h"

void UPA_TutorialSubsystem::EnableTutorial()
{
	//if(bIsTutorialEnabled) return;

	bIsTutorialEnabled = true;
	OnTutorialToggled.Broadcast(true);
}

void UPA_TutorialSubsystem::DisableTutorial()
{
	//if(!bIsTutorialEnabled) return;

	bIsTutorialEnabled = false;
	OnTutorialToggled.Broadcast(false);
}