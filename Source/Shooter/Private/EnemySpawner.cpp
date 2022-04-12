// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include <string.h>
#include <string>
#include "EnemyCharacter.h"
// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle OutHandle;



	GetWorld()->GetTimerManager().SetTimer(OutHandle, this, &AEnemySpawner::SpawnEnemies, TimeToSpawn, true);
	//GetWorldTimerManager().SetTimer(OutHandle, this, &AEnemySpawner::SpawnEnemies, 5.f, true);
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float AEnemySpawner::random(float a, float b)
{
	srand(time(NULL));

	int r = rand() % 2;

	if (r == 0)
		return a;
	else
		return b;
}

void AEnemySpawner::SpawnEnemies()
{
	//Player Position
	FVector MyCharacterPosition;
	MyCharacterPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	//Square donut
	minX = FMath::FRandRange(MyCharacterPosition.X - minspawnRadius, MyCharacterPosition.X - maxspawnRadius);
	maxX = FMath::FRandRange(MyCharacterPosition.X + minspawnRadius, MyCharacterPosition.X + maxspawnRadius);

	minY = FMath::FRandRange(MyCharacterPosition.Y + minspawnRadius, MyCharacterPosition.Y + maxspawnRadius);
	maxY = FMath::FRandRange(MyCharacterPosition.Y + minspawnRadius, MyCharacterPosition.Y + maxspawnRadius);

	//if a collision is happening in the spawn point etc..
	FActorSpawnParameters SpawnParams;

	//Actual Spawn. The following function returns a reference to the spawned actor
	AEnemyCharacter* ActorRef = GetWorld()->SpawnActor<AEnemyCharacter>(EnemyCharacterBP, FVector(random(minX,maxX), random(minY, maxY), MyCharacterPosition.Z + 30), GetActorRotation());
	GLog->Log("Spawned the UsefulActor.");
}


