#include <cstdio>

float celsius_to_fahrenheit(float temperature);

int main()
{
	printf("Celcius to Fahrenheit: %f\n", celsius_to_fahrenheit(36));
}

float celsius_to_fahrenheit(float temperature)
{
	return temperature * 9 / 5 + 32;
}