#include<iostream>
#include<string>

using namespace std;

const string INPUT = "aaaabbbcc";

string compress(string stringUncompressed);
string decompress(string compressedString);

int main()
{
	string compressedString = compress(INPUT);

	cout << "Input: " << INPUT<< endl;
	cout << "Compressed: " << compressedString << endl;
	cout << "De compressed: " << decompress(compressedString) << endl;
}

string compress(string stringUncompressed)
{
	string newString = "";
	int count;
	for (int i = 1; i < stringUncompressed.size(); i++)
	{
		count = 1;
		newString += stringUncompressed[i - 1];
		while (stringUncompressed[i - 1] == stringUncompressed[i])
		{
			count++;
			i++;
		}
		newString += to_string(count);
	}
	return newString;
}

string decompress(string compressedString)
{
	string newString = "";

	for (int index = 1; index < compressedString.size(); index += 2)
	{
		for (int charCount = 0; charCount < (int)(compressedString[index] - '0'); charCount++)
		{
			newString += compressedString[index - 1];
		}
	}
	return newString;
}
