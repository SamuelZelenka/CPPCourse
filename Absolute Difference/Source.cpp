#include <cstdio>

int abs(int value);

int main()
{
	printf("Absolute Difference: %i\n", (abs(-2) + abs(6)));
}

int abs(int value)
{
	return  value < 0 ? -value : value;
}