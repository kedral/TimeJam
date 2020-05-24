// Fill out your copyright notice in the Description page of Project Settings.
#include "Living.h"

// Sets default values for this component's properties
ULiving::ULiving(float initialHealth) : Health(initialHealth)
{
}

// Called when the game starts
void ULiving::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ULiving::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void ULiving::HandleDeath()
{
	//TODO Play death animation
	UE_LOG(LogTemp, Warning, TEXT("You have died."));
}

void ULiving::TakeHit()
{
	UE_LOG(LogTemp, Warning, TEXT("You have been hit."));

	(this->Health - 1.f) <= 0.f ? this->Health--, HandleDeath() : this->Health--;
}

float ULiving::GetHealth()
{
	return this->Health;
}

void ULiving::SetHealth(float newHealth)
{
	this->Health = newHealth;
}

