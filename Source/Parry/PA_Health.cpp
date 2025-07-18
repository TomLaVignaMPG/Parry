// Fill out your copyright notice in the Description page of Project Settings.


#include "PA_Health.h"

// Sets default values for this component's properties
UPA_Health::UPA_Health()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPA_Health::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	
}


// Called every frame
void UPA_Health::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UPA_Health::ChangeHealth(float HealthDelta)
{
	CurrentHealth = CurrentHealth - HealthDelta;
	
	if (CurrentHealth <= 0)
	{
		CurrentHealth = 0;
		OnDeath.Broadcast();
		return false;
	}
	
	OnHealthChanged.Broadcast(HealthDelta, CurrentHealth);
	
	return true;
}

