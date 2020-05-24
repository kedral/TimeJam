// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Living.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TIMECHILD_API ULiving : public UActorComponent
{
	GENERATED_BODY()

private:
	// Character's health
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
	float Health;
public:	
	// Sets default values for this component's properties
	ULiving() : Health(3) {};
	ULiving(float initialHealth);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	virtual void HandleDeath();

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	virtual void TakeHit();

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	virtual float GetHealth();

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	virtual void SetHealth(float newHealth);
};
