// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemiesShooterCharacter.generated.h"

class Strategy
{
public:
	virtual ~Strategy() = default;
	virtual void DoAction() const = 0;
};

class PrintHelloAction : public Strategy
{
public:
	virtual void DoAction() const override
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Orange, "Hello!");
	}
};

class AttackAction : public Strategy
{
public:
	virtual void DoAction() const override
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Orange, "Do Attack!");
	}
};

UCLASS(Blueprintable)
class AEnemiesShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemiesShooterCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
    void BlueprintProviderMethod();

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;

	void MoveForward(float Value);
	void MoveRight(float Value);

	Strategy *currentAction;
	void SetStrategy(Strategy* newStrategy);
};

