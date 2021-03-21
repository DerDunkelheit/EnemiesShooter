// Copyright Epic Games, Inc. All Rights Reserved.

#include "EnemiesShooterGameMode.h"
#include "EnemiesShooterPlayerController.h"
#include "EnemiesShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEnemiesShooterGameMode::AEnemiesShooterGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AEnemiesShooterPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}