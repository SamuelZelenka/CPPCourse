#include<iostream>

using namespace std;
void swap_pointers(int* value1, int* value2);
void swap_references(int& value1, int& value2);

int main() 
{
	int value1 = 3;
	int value2 = 5;

	cout << "Before Swap: " << "value1: " << value1 << " value2: " << value2 << endl;
	swap(value1, value2);
	cout << "After Swap: " << "value1: " << value1 << " value2: " << value2 << endl;
	cout << endl;

	cout << "Before Swap: " << "value1: " << value1 << " value2: " << value2 << endl;
	swap_pointers(&value1, &value2);
	cout << "After Swap: " << "value1: " << value1 << " value2: " << value2 << endl;
	cout << endl;

	cout << "Before Swap: " << "value1: " << value1 << " value2: " << value2 << endl;
	swap_references(value1, value2);
	cout << "After Swap: " << "value1: " << value1 << " value2: " << value2 << endl;
	cout << endl;

	return 0;
}

void swap_pointers(int* value1, int* value2)
{
	*value1 = *value1 + *value2;
	*value2 = *value1 - *value2;
	*value1 = *value1 - *value2;
}

void swap_references(int& value1, int& value2)
{
	value1 = value1 + value2;
	value2 = value1 - value2;
	value1 = value1 - value2;
}