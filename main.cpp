#include <iostream>
#include "dynamic_array.h"

int main()
{

    DynamicArray arr(3);
    // We can add a single element
    arr.add_element(1);

    // Or we can use { } to pass multiple elements at once
    arr.add_element({97, 2, 3, 3});

    // Displays all the elements
    arr.display_element();

    // This returns the size of the array and the number of elements in it
    arr.return_size();

    /* This removes the number specified
    (If there are two or more same numbers, it removes the last one.)
    */
    arr.pop_element(3);

    arr.return_size();

    // Returns the value of array in index 0
    cout << arr[0] << endl;

    arr.display_element();

    return 0;
}