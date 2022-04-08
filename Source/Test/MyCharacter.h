// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class TEST_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "name")
		FString name = "Hoffe";
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "maxHealth")
		float maxHealth = 100;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "currentHealth")
		float currentHealth = 70;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "damage")
		float damage = 5;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "currency")
		int currency = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "attackSpeed")
		float attackSpeed = 1;

	UFUNCTION(BlueprintCallable, Category = "HelloWorld")
		void HelloWorld();

};
