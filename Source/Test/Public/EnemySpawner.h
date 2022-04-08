// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class TEST_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "maxHealth")
		float numberOfEnemies = 0;
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
