#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void setup(int* min, int* max);
bool guess(int guessNumber);
void play_round();
void check_input(int* output, string asd);
bool is_playing();

int main()
{
	do
	{
		play_round();
	} while (is_playing());
}

bool is_playing()
{
	int input;
	cout << "1 - Play again\n 0 - To quit" << endl;

	cin >> input;

	return input != 0;

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

	cout << "You guessed the correct number in " << guessCount << ((guessCount == 1) ? " attempt!" : " attempts!") << endl;
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
	system("CLS");
	cout << message << endl;

	while (!(cin >> *output))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} 
}
