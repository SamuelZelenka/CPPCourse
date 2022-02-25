#include<iostream>
#include<string>

using namespace std;

int main()
{
	string someString = "Hello";

	cout << "Original: " << someString << endl; 
	cout << "Reversed: ";
	for (int i = someString.size() - 1; i != -1; i--)
	{
		cout << someString[i];
	}
	cout << endl;

}