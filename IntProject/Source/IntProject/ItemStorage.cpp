// Fill out your copyright notice in the Description page of Project Settings.
/** @file ItemStorage.cpp

 *  @brief This file has functionallity for blueprint item storage.

 *  @author Oscar Fox

 *  @bug No known bugs.

 */

#include "ItemStorage.h"

// Sets default values
AItemStorage::AItemStorage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AItemStorage::BeginPlay()
{
	Super::BeginPlay();
	
}

