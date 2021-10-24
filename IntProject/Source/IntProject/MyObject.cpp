// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObject.h"

UMyObject::UMyObject()  // definition for constructor 
{
	MyFloat = 0;  // default value
}

void UMyObject::MyFunction()
{
	// Prints warning text to output log temporary
	UE_LOG(LogTemp, Warning, TEXT("This is our warning text!"));
}