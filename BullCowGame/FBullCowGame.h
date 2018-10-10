#pragma once
#include <string>

using FString = std::string;
using int32 = int; 

// two integers, implement to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame 
{
public:
	FBullCowGame();
	void Reset(); //TODO make a more rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const; // const - a promise not to change any variable 
	int32 ReturnHiddenWordLength() const;
	void IncreaseCurrentTry();


	bool IsGameWon();
	bool CheckGuessValidity(FString);
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};