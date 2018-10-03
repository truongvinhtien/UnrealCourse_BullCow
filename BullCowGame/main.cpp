#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();


int main()
{
	PrintIntro();
	do
	{
		PlayGame();
	} while (AskToPlayAgain());



	return 0;
}

void PrintIntro()
{
	//Introduce the game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
	return;
}

void PlayGame()
{
	// Start the game
	constexpr int NUMBER_OF_TURN = 5;
	for (int count = 1; count <= NUMBER_OF_TURN; count++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess() {
	//Get the guess from player
	std::string Guess = "";
	std::cout << "Enter your guess: ";
	getline(std::cin, Guess);
	//Repeat the guess to player

	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (Y/N)";
	std::string Reply = "";
	getline(std::cin, Reply);
	if (tolower(Reply[0]) == 'y') { return true; }
	else if (tolower(Reply[0]) == 'n') { return false; }
	else {
		return AskToPlayAgain();
	}
}