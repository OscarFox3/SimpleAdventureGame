// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class INTPROJECT_API UMyObject : public UObject
{
	GENERATED_BODY()

public:
	UMyObject();

	UPROPERTY(BluePrintReadOnly, Category = "MyVariables") // Macros for blueprint access
	float MyFloat;

	UFUNCTION(BlueprintCallable, Category = "MyFunctions")
	void MyFunction();

		
};
