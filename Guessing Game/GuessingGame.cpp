#include <iostream>

using namespace std;

void setup(int* min, int* max);

int main()
{
	int min{};
	int max{};

	bool isRunning{};
	setup(&min, &max);

}


void setup(int* min, int* max)
{
	cout << "Enter Min: " << endl;
	cin >> *min;
	cout << "Enter Max: " << endl;
	cin >> *max;
}

