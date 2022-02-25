#include<iostream>
#include<vector>

using namespace std;

#define CONTAINS_DIGIT(input, digit) (cout << input << " contains the number " << digit << "." << endl);
#define DOESNT_CONTAINS_DIGIT(input, digit) (cout << input << " doesn't contain the number " << digit << "." << endl);

bool contains_number(int digit, int number);
vector<int> get_digits(int number);

const int INPUT_DIGIT = 4; // Single digit lookup
const int INPUT_NUMBER = 678234; //Number to look through

int main()
{
	if (contains_number(INPUT_DIGIT, INPUT_NUMBER))
	{
		CONTAINS_DIGIT(INPUT_NUMBER, INPUT_DIGIT);
	}
	else
	{
		DOESNT_CONTAINS_DIGIT(INPUT_NUMBER, INPUT_DIGIT);
	}
}

bool contains_number(int digit, int number)
{
	for (int i = 0; number > 0; i++)
	{
		if (number % 10 == digit)
		{
			return true;
		}
		number /= 10;
	}
	return false;
}