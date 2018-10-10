#include "FBullCowGame.h"
#include <algorithm>
#include <iostream>

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
		
	MyCurrentTry = 1;
	
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::ReturnHiddenWordLength() const
{
	return MyHiddenWord.length();
}

void FBullCowGame::IncreaseCurrentTry()
{
	MyCurrentTry++;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString Guess)
{
	int32 GuessLength = Guess.length();
	int32 HiddenWordLength = ReturnHiddenWordLength();

	if (GuessLength != HiddenWordLength) {
		std::cout << "Your guess has more or less than " << HiddenWordLength << " letter" << std::endl;
		return false;
	}

	int32 length = Guess.length();
	std::sort(Guess.begin(), Guess.end());
	for (int32 i = 0; i < length; i++) {
		if (Guess[i] == Guess[i + 1]) {
			std::cout << "Your guess is not isogram, please try again" << std::endl;
			return false;
		}
	}
	return true;
}

//receives valid guess, increament turn and return count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	IncreaseCurrentTry();

	FBullCowCount BullCowCount;

	for (int32 i = 0; i < Guess.length(); i++) {
		if (MyHiddenWord.find(Guess[i]) == i) {
			BullCowCount.Bulls++;
		}
		else if (MyHiddenWord.find(Guess[i]) != i) {
			BullCowCount.Cows++;
		}
	}

	return BullCowCount;
}
