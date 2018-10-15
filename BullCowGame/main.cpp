#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
//bool IsIsogram(FText Guess);
void PrintGameSumary();

FBullCowGame BCGame;

int32 main()
{
	do
	{
		system("CLS");
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}

void PrintIntro()
{
	//Introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	// Start the game
	int32 MAX_TRIES = BCGame.GetMaxTries();
	FBullCowCount BullCowCount;
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries()) {
		FText Guess = "";
		do {
			Guess = GetGuess();
		} while (BCGame.CheckGuessValidity(Guess)!=EWordStatus::OK);
		BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls: " << BullCowCount.Bulls << " & Cows:" << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
	PrintGameSumary();
}

FText GetGuess() 
{
	//Get the guess from player
	FText Guess = "";
	std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
	getline(std::cin, Guess);
	int32 GuessLength = Guess.length();
	for (int32 i = 0; i < GuessLength; i++) {
		Guess[i] = tolower(Guess[i]);
	}
	/*BCGame.IncreaseCurrentTry();*/
	return Guess;
}

bool AskToPlayAgain() 
{
	std::cout << "Do you want to play again with the same word? (Y/N)";
	FText Response = "";
	getline(std::cin, Response);
	if (tolower(Response[0]) == 'y') { return true; }
	else if (tolower(Response[0]) == 'n') { return false; }
	else {
		return AskToPlayAgain();
	}
}

//bool IsIsogram(FText Guess) {
//	int32 length = Guess.length();
//	std::sort(Guess.begin(), Guess.end());
//	for (int32 i = 0; i < length; i++) {
//		if (Guess[i] == Guess[i + 1]) {
//			std::cout << "Your guess is not isogram, please try again" << std::endl;
//			return false;
//		}
//	}
//	return true;
//}

void PrintGameSumary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "WELL DONE! YOU WON!" << std::endl;
	}
	else {
		std::cout << "BETTER LUCK NEXT TIME..." << std::endl;
	}
}
