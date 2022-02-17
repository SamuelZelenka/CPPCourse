#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void setup(int* min, int* max);
bool guess(int guessNumber);
void play_round();
void check_input(int* output, string asd);
bool play_again();
bool is_input_number(int* output);


int main()
{
	do
	{
		play_round();
	} while (play_again());
}

bool play_again()
{
	int input;
	cout << "Enter any key to play again.\n 1 - Exit" << endl;
	if (is_input_number(&input))
	{
		return input != 1;
	}
	return true;
}
void setup(int* guessNumber)
{
	int min{};
	int max{};

	system("CLS");
	check_input(&min, "Enter Min: ");
	check_input(&max, "Enter Max: ");

	srand(time(0));
	*guessNumber = min + rand() % (max - min);
}

void play_round()
{
	int guessNumber{};
	int guessCount{0};
	setup(&guessNumber);
	do
	{
		guessCount++;
	} while (!guess(guessNumber));
	cout << "You guessed the correct number in " << guessCount << "attempts!" << endl;
}

bool guess(int correctNumber)
{
	int guess{};
	check_input(&guess, "Make a guess");
	if (guess == correctNumber)
	{
		return true;
	}
	return false;
}

void check_input(int* output, string message)
{
	bool isValid = false;
	do
	{
		system("CLS");
		cout << message << endl;
		isValid = is_input_number(output);
	} while (isValid);
}

bool is_input_number(int* output)
{
	if (cin >> *output)
	{
		return false;
	}
	return true;
}
