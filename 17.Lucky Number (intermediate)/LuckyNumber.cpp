#include <iostream>
#include <vector>

using namespace std;

#define IS_LUCKY_NUMBER(input) (cout << input << " is a lucky number. " << endl);
#define IS_NOT_LUCKY_NUMBER(input) (cout << input << " is NOT a lucky number. " << endl);

bool is_lucky_number(vector<int> digits);
vector<int> get_digits(int number);

int main()
{
	int input;
	cout << "Enter number: ";
	cin >> input;
	cout << endl;
	if (is_lucky_number(get_digits(input)))
	{
		IS_LUCKY_NUMBER(input);
	}
	else
	{
		IS_NOT_LUCKY_NUMBER(input);
	}
}

bool is_lucky_number(vector<int> digits)
{
	int&& digitsSize = digits.size();
	if (digitsSize == 0)
	{
		return true;
	}
	for (int i = digitsSize - 2 ; i >= 0; i--)
	{
		if (digits[digitsSize - 1] == digits[i])
		{
			return false;
		}
	}
	digits.pop_back();
	return is_lucky_number(digits);
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
