#include <iostream>
#include <stdlib.h>
#include <string.h>

#define CLEAR_CONSOLE (system("CLS"))
#define PRINT(x) (std::cout << x << std::endl);
#define PRINT_RETRY (std::cout << "1 - Play again\n 0 - To quit" << std::endl)
#define PRINT_GUESS_SUCCESS(guessCount) (std::cout << "You guessed the correct number in " << guessCount << ((guessCount == 1) ? " attempt!" : " attempts!") << std::endl)

using namespace std;

void setup(int& guessNumber);
bool guess(int guessNumber);
void play_round();
void check_input(int& output, string message);
bool retry_game();

int main()
{
	do
	{
		play_round();
	} while (retry_game());
}

bool retry_game()
{
	int input;
	
	PRINT_RETRY;

	cin >> input;
	return input != 0;
}

void setup(int& guessNumber)
{
	int min{};
	int max{};

	CLEAR_CONSOLE;
	check_input(min, "Enter Min: ");
	check_input(max, "Enter Max: ");

	srand(time(0));
	guessNumber = min + rand() % (max - min);
}

void play_round()
{
	int guessNumber{};
	int guessCount{0};

	setup(guessNumber);

	do
	{
		guessCount++;
	} while (!guess(guessNumber));

	PRINT_GUESS_SUCCESS(guessCount);
}

bool guess(int correctNumber)
{
	int guess{};

	check_input(guess, "Make a guess");

	if (guess == correctNumber)
	{
		return true;
	}
	return false;
}

void check_input(int& output, string message)
{
	CLEAR_CONSOLE;
	PRINT(message);

	while (!(cin >> output))
	{
		constexpr int maxStreamSize = numeric_limits<streamsize>::max();

		cin.clear();
		cin.ignore(maxStreamSize, '\n');
	} 
}
