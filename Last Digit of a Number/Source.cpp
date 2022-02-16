#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include "CoolHeader.h"

using namespace std;

int last_digit(int number);
vector<int> get_digits(int number);
void print_digits(vector<int> digits);

int main()
{
	bool poo = true;
	int peepeepoopoo = true;

	printf("Last Digit of Number: %i\n", last_digit(137));
	vector<int> digits = get_digits(137);

	print_digits(digits);

	reverse(digits.begin(), digits.end());

	cout << endl;

	print_digits(digits);
}

void print_digits(vector<int> digits)
{
	for (int i = 0; i < digits.size(); i++)
	{
		printf("%i", digits.at(i));
	}
}

int last_digit(int number)
{
	return number % 10;
}

vector<int> get_digits(int number)
{
	vector<int> digits;

	for (int i = 0; number > 0; i++)
	{
		int digit = number % 10;
		number /= 10;
		digits.push_back(digit);
	}
	return digits;
}