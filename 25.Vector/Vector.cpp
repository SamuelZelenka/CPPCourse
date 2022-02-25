#include <stdexcept>
#include <iostream>

using namespace std;

template <typename T> class vector
{
private:
	T* arr_;
	T* end_;
	int capacity;
	
public:
	int size;
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
		if (size <= 0)
		{
			throw out_of_range("Vector is empty.");
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
		return arr_ + (sizeof(T) / size) * size;
	}

	T operator[](int index)
	{
		string asd;

		asd.le
		if (index < 0 || index > getSize() - 1)
		{
			throw out_of_range("Index out of range");
		}
		return arr_[index];
	}
};

int main()
{
	vector<int> someVector;

	someVector.push(1);
	someVector.push(2);

	someVector.push(3);

	someVector.push(4);

	cout << "size: " << someVector.getSize() << endl;
	

	for (int number : someVector) 
	{
		cout << "Number: " << number << endl;
	}
	for (int i = 0; i < someVector.getSize(); i++) 
	{
		cout << "Number: " << someVector[i] << endl;
	}
}