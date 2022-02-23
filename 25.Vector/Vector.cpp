#include <stdexcept>
#include <iostream>

template <typename T> class vector
{
private:
	T* arr_;
	T* end_;
	int capacity;
	int size;
public:
	vector()
	{
		arr_ = new T[1];
		end_ = arr_;
		capacity = 1;
		size = 0;
	}
	void push(T data)
	{
		if (size == capacity)
		{
			T* tempArr = new T[2 * capacity];

			for (int i = 0; i < capacity; i++)
			{
				tempArr[i] = arr_[i];
			}
		
			delete arr_;
			capacity *= 2;
			arr_ = tempArr;
		}
		arr_[size] = data;
		end_ = &data;
		size++;
	}

	T pop()
	{
		size--;
		if (size < 0)
		{
			throw std::out_of_range("Vector is empty.");
		}
		end_ = &arr_[size - 1];
		return arr_[size];
	}
	int getSize()
	{
		return size;
	}

	T* begin()
	{
		return arr_;
	}

	T* end()
	{
		int&& typeSize = sizeof(T)/size;
		return arr_ + typeSize * size;
	}
};

int main()
{
	vector<int> someVector;

	someVector.push(1);
	someVector.push(2);

	someVector.push(3);

	someVector.push(4);

	std::cout << "size: " << someVector.getSize() << std::endl;

	for (int number : someVector)
	{
		std::cout << "Number: " << number << std::endl;
	}

}