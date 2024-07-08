#include <iostream>

using namespace std;

class DynamicArray
{
private:
	int mySize;	  // Size of the array
	int initial;  // Number of elements in the array
	int *myArray; // Pointer to the array

public:
	DynamicArray(int size) : mySize(size), initial(0)
	{
		myArray = new int[mySize];
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

	void add_element(int input)
	{
		if (this->initial == this->mySize)
		{
			const int new_size = this->mySize * 2;
			int *new_array = new int[new_size];
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
	void add_element(const initializer_list<int> &inputs)
	{
		for (int input : inputs)
		{
			add_element(input);
		}
	}

	const void return_size()
	{
		cout << "Size: " << this->mySize << ", Elements: " << this->initial << endl;
	}

	void pop_element(int get)
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
					int *shrink_array = new int[shrink_size];
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

	int& operator[](int index){
		return this->myArray[index];
	}

	void delete_all()
	{
		delete[] this->myArray;
		this->myArray = new int[2];
		this->mySize = 1;
		this->initial = 0;
	}
};
