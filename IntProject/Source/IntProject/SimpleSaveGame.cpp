// Fill out your copyright notice in the Description page of Project Settings.
/** @file SimpleSaveGame.cpp

 *  @brief This file has functionallity for Save Game option.

 *  @author Oscar Fox

 *  @bug No known bugs.

 */

#include "SimpleSaveGame.h"

USimpleSaveGame::USimpleSaveGame()
{
	PlayerName = TEXT("Default");

	UserIndex = 0;

	CharacterStats.WeaponName = TEXT("");
}
