#include <iostream>
#include <cstdio>
#include <thread>

bool is_even(int value);
bool is_even_modulo(int value);

int evenOdd{ 3 };

int main()
{
	using std::chrono::high_resolution_clock;
	using std::chrono::duration_cast;
	using std::chrono::duration;
	using std::chrono::milliseconds;

	printf("Even or Odd: %i %s\n", evenOdd, is_even(evenOdd) ? "is even" : "is odd");

	auto t1 = high_resolution_clock::now();
	is_even(32);
	auto t2 = high_resolution_clock::now();

	duration<double, std::milli> test1 = t2 - t1;

	t1 = high_resolution_clock::now();
	is_even_modulo(32);
	t2 = high_resolution_clock::now();

	duration<double, std::milli> test2 = t2 - t1;

	std::cout << "Bitwise: " << test1.count() << "ms\n";
	std::cout << "Modulo: " << test2.count() << "ms\n";

}

bool is_even(int value)
{
	return value & 1;
}
bool is_even_modulo(int value)
{
	return value % 2 == 0;
}