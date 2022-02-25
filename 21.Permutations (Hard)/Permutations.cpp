#include <iostream>
#include <string>

using namespace std;

const string INPUT = "ABC";

string permute(string input, int left, int right);


int main()
{
	cout << permute(INPUT, 0, INPUT.size() - 1) << endl;
	return 0;
}

string permute(string input, int left, int right)
{
	string stringVersion = "";
	if (left == right)
	{
		stringVersion += input + "\n";
	}
	else
	{
		for (int i = left; i <= right; i++)
		{
			swap(input[left], input[i]);
			stringVersion += permute(input, left + 1, right);
			swap(input[left], input[i]);
		}
	}
	return stringVersion;
}