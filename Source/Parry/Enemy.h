// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperCharacter.h"
#include "Enemy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnParried, bool, EnemyParried, float, KnockbackAmount);

UCLASS()
class PARRY_API AEnemy : public APaperCharacter
{
	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnParried OnParried;

public:
	// Sets default values for this actor's properties
	AEnemy();

	UFUNCTION(BlueprintCallable)
	bool GetParried() const { return bParried; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool bParried = false;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float Knockback = 0.0f;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void ChangeParry();
};
