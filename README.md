# Dynamic Array in C++

## Overview

This C++ project implements a dynamic array class (`DynamicArray`) that allows for dynamic resizing and various operations commonly associated with arrays.

## Features

- **Dynamic Sizing**: Automatically adjusts its size to accommodate new elements.
- **Element Addition**: Supports adding single elements or multiple elements at once.
- **Element Removal**: Provides functionality to remove specific elements.
- **Index Access**: Allows accessing elements using array indexing (`[]` operator overloading).
- **Memory Management**: Efficiently manages memory by resizing when necessary and deallocating memory when elements are removed.

## Usage

### Initialization

To use the `DynamicArray` class, initialize it with an initial size:

```cpp
DynamicArray arr(3); // Initializes with a size of 3
```

### Adding elements

```cpp
// We can add a single element
arr.add_element(1);
// Or we can use { } to pass multiple elements at once
arr.add_element({97, 2, 3, 3});
```

### Adding elements

```cpp
// We can add a single element
arr.add_element(1);
// Or we can use { } to pass multiple elements at once
arr.add_element({97, 2, 3, 3});
```
