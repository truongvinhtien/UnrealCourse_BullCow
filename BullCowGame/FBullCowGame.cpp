#pragma once
#include "FBullCowGame.h"
#include <algorithm>
#include <iostream>

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 3;
	MyMaxTries = MAX_TRIES;
	
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
		
	MyCurrentTry = 1;
	
	bGameIsWon = false;

	return;
}

int32 FBullCowGame::GetMaxTries() const 
{
	TMap <int32, int32> WordLengthToMaxtries{ {3,4}, {4,5}, {5,5}, {6,5} };
	return WordLengthToMaxtries[MyHiddenWord.length()]; 
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::IncreaseCurrentTry()
{
	MyCurrentTry++;
	return;
}

bool FBullCowGame::IsGameWon()
{
	return bGameIsWon;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	int32 GuessLength = Guess.length();
	int32 HiddenWordLength = GetHiddenWordLength();

	if (GuessLength != HiddenWordLength) {
		std::cout << "Your guess has more or less than " << HiddenWordLength << " letter" << std::endl;
		return EWordStatus::Wrong_Length;
	}
	else if (!IsIsogram(Guess)) {
		std::cout << "Your guess is not isogram, please try again" << std::endl;
		return EWordStatus::Not_Isogram;
	}
	else return EWordStatus::OK;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	if (Guess.length() <= 1) { return true; }
	TMap <char, bool> LetterSeen;
	for (char c : Guess) {
		if (!LetterSeen[c]) { LetterSeen[c] = true; }
		else return false;
	}
	return true;
}

//receives valid guess, increament turn and return count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	
	FBullCowCount BullCowCount;

	for (int32 i = 0; i < Guess.length(); i++) {
		int pos = MyHiddenWord.find(Guess[i]);
		if (pos == i) { BullCowCount.Bulls++; }
		else if (pos != i && pos != std::string::npos) { BullCowCount.Cows++; }
	}
	if (BullCowCount.Bulls == GetHiddenWordLength()) {
		bGameIsWon = true;
	}

	IncreaseCurrentTry();
	return BullCowCount;
}

