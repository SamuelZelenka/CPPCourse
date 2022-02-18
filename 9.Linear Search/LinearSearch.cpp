#include<iostream>
#include<vector>

using namespace std;

void linear_search(int target, int* numbers, int size, vector<int>* positionVector);

int main()
{
	int numbers[]{ 1,54,34,23,45,6,5,3,4,6,7,4,465,67,8,8,4,1,2,3,5,1,3,6,78,2,1 };
	int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
	int target{ 1 };
	vector<int> foundpositions;

	linear_search(target, numbers, numbersSize, &foundpositions);

	cout << "The number " << target << " was located at position(s) ";
	for (int i = 0; i < foundpositions.size(); i++)
	{
		cout << foundpositions[i] << " ";
	}
}

void linear_search(int target, int* numbers, int size, vector<int>* positionVector)
{
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == target)
		{
			positionVector->push_back(i);
		}
	}
}
