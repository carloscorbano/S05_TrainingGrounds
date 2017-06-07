// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "S05_TrainingGroundsGameMode.h"
#include "S05_TrainingGroundsHUD.h"
#include "S05_TrainingGroundsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AS05_TrainingGroundsGameMode::AS05_TrainingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AS05_TrainingGroundsHUD::StaticClass();
}
