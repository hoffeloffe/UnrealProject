// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyCharacter.h"
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
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "minspawnRadius")
		float minspawnRadius = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "maxspawnRadius")
		float maxspawnRadius = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ActorSpawning")
		float TimeToSpawn = 5.f;

	UPROPERTY(EditDefaultsOnly, Category = "EnemyCharacterBP")
		TSubclassOf<AEnemyCharacter> EnemyCharacterBP;

	UFUNCTION(BlueprintCallable, Category = "SpawnEnemies")
		void SpawnEnemies();

private:
	float random(float a, float b);

	float minX;
	float minY;

	float maxX;
	float maxY;

	float Z;

};



