#pragma once
#include <string>
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int; 

// two integers, implement to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	OK,
	Not_Isogram,
	Wrong_Length
};

class FBullCowGame 
{
public:
	FBullCowGame();
	void Reset(); //TODO make a more rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const; // const - a promise not to change any variable 
	int32 GetHiddenWordLength() const;
	void IncreaseCurrentTry();


	bool IsGameWon();

	EWordStatus CheckGuessValidity(FString);
	

	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	
};