#include<iostream>
#include<string>

using namespace std;

void print_numbers(int* numbers, int numbersize);
bool isArithmeticProgression(int* numbers, int size);

int main()
{
	int numbers[]{10,20,30,40};
	int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
	print_numbers(numbers, numbersSize);
	isArithmeticProgression(numbers, numbersSize) ? cout << "IS Arithmetic Progression" : cout << "IS NOT Arithmetic Progression";

	int someValue{5};
	int* ptr;
	int& ref = someValue;

	ptr = &ref;
	someValue = ref + ref;

}

void print_numbers(int* numbers, int numbersize)
{
	cout << "Numbers: ";
	for (int i = 0; i < numbersize; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
}

bool isArithmeticProgression(int* numbers, int size)
{
	bool isArithemticProgression = true;

	if (size > 1)
	{
		int difference = numbers[1] - numbers[0];
		for (int i = 2; i < size; i++)
		{
			if (numbers[i] - numbers[i - 1] != difference)
			{
				return false;
			}
		}
	}
	return true;
}
