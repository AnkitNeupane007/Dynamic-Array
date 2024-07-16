#include <iostream>

using namespace std;

template <typename T>
class DynamicArray
{
private:
	int mySize;	  // Size of the array
	int initial;  // Number of elements in the array
	T *myArray; // Pointer to the array

public:
	DynamicArray(int size) : mySize(size), initial(0)
	{
		myArray = new T[mySize];
	}

	~DynamicArray()
	{
		delete[] myArray;
	}

	const void display_element()
	{
		if (this->initial == 0)
		{
			cout << "No elements.";
		}

		for (int i = 0; i < this->initial; i++)
		{
			cout << this->myArray[i] << " ";
		}
		cout << endl;
	}

	void add_element(T input)
	{
		if (this->initial == this->mySize)
		{
			const int new_size = this->mySize * 2;
			T *new_array = new T[new_size];
			for (int i = 0; i < this->mySize; i++)
			{
				new_array[i] = this->myArray[i];
			}
			delete[] this->myArray;
			this->myArray = new_array;
			this->mySize = new_size;
		}

		this->myArray[this->initial] = input;
		this->initial++;
	}

	// Multiple elements can be added at once
	void add_element(const initializer_list<T> &inputs)
	{
		for (auto input : inputs)
		{
			add_element(input);
		}
	}

	const void return_size()
	{
		cout << "Size: " << this->mySize << ", Elements: " << this->initial << endl;
	}

	void pop_element(T get)
	{
		if (this->initial == 0)
		{
			throw out_of_range("The dynamic array is empty.");
			return;
		}

		int count = 0;
		bool present = false;

		for (int i = 0; i < this->initial; i++)
		{
			if (this->myArray[i] == get)
			{
				for (int j = i; j < this->initial; j++)
				{
					this->myArray[j] = this->myArray[j + 1];
					present = true;
					count++;
				}
				this->initial--;
				i--;
				if (this->initial <= this->mySize / 2 && this->initial > 1)
				{
					int shrink_size = this->mySize / 2;
					T *shrink_array = new T[shrink_size];
					for (int i = 0; i < this->initial; i++)
					{
						shrink_array[i] = this->myArray[i];
					}
					delete[] this->myArray;
					this->myArray = shrink_array;
					this->mySize = shrink_size;
				}
				break;
			}
		}
		if (present != true)
			cout << "Not there." << endl;
	}

	T& operator[](int index){
		return this->myArray[index];
	}

	void delete_all()
	{
		delete[] this->myArray;
		this->myArray = new T[2];
		this->mySize = 1;
		this->initial = 0;
	}
};
