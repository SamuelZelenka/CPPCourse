#include<iostream>
#include<vector>

using namespace std;

#define CONTAINS_DIGIT(input, digit) (std::cout << input << " contains the number " << digit << "." << std::endl);
#define DOESNT_CONTAINS_DIGIT(input, digit) (cout << input << " doesn't contain the number " << digit << "." << endl);

bool contains_number(int digit, int number);
vector<int> get_digits(int number);

const int INPUT_DIGIT = 1;
const int INPUT_NUMBER = 678234;

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
	vector<int> digits = get_digits(number);
	for (int i = 0; i < digits.size(); i++)
	{
		if (digits[i] == digit)
		{
			return true;
		}
	}
	return false;
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