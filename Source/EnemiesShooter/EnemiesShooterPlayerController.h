// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnemiesShooterPlayerController.generated.h"

UCLASS()
class AEnemiesShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AEnemiesShooterPlayerController();

protected:

	UPROPERTY(EditAnywhere)
	bool bUseMouseToMove = true;
	
	/** True if the controlled character should navigate to the mouse cursor. */
	bool bMoveToMouseCursor = false;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
};


