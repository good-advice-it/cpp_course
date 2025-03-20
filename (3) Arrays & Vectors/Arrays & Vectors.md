# Arrays & Vectors

## Arrays

An array is a compound or structure data type, meaning it is a type composed of a collection of other types.

All elements of the array must be of the same type.

Each array element can be addressed by an index, which is a non-negative integer.

Arrays are a fixed size, meaning the number of elements in the array must be known at compile time or dynamically allocated at runtime, the array can not grow or shrink.

Arrays are stored in contiguous memory locations, meaning the elements are stored one after the other in memory.

C++ has no built-in array bounds checking, so it is possible to access an element outside the bounds of the array.

Arrays are zero indexed, meaning the first element is at index 0, the last element is at index `size - 1`.

Arrays can be initialized when they are declared.

```c++
// int myArray[5];                   // Declares an array of 5 integers, uninitialized
// int myArray[5] = {1, 2, 3, 4, 5}; // Declares an array of 5 integers, initialized
```

### Declaring / initializing arrays

Elements of the array should also be initialized to non- zero values, as uninitialized elements (could) contain garbage values.

```c++
int myArray[5];                   // Declares an array of 5 integers, uninitialized
int myArray[5] = {1, 2, 3, 4, 5}; // Declares an array of 5 integers, initialized
int myArray[5] = {};              // Declares an array of 5 integers, initialized to 0
int myArray[5] = {3,5};           // Declares an array of 5 integers, initialized to 3, 5, 0, 0, 0
```

Array size can also be determined at compile time. This means you would not have to specify the size of the array when declaring it.

```c++
int myArray[] = {1, 2, 3, 4, 5}; // Declares an array of 5 integers
```

### Multidimensional arrays

Arrays can have more than one dimension.

A two-dimensional array is an array of arrays.

```c++
int myArray[2][3] = { {1, 2, 3}, {4, 5, 6} };
```

## Vectors

Most of the time, you will want to use the `std::vector` class instead of arrays.

`std::vector` is a sequence container that encapsulates dynamic size arrays, meaning the size of the vector can change at runtime.

`std::vector` is part of the C++ Standard Library, so you will need to include the `<vector>` header.

```c++
#include <vector>
std::vector <char> vowels {'a', 'e', 'i', 'o', 'u'}; // 5 elements initialized
std::vector <int> testScores(10);                    // 10 elements initialized to 0
std::vector <double> hiTemps(365, 80.0);             // 365 elements initialized to 80.0
```

When using the subscript operator `[]` with a vector, you can access elements just like you would with an array.

It will not provide bounds checking when doing this, so it is possible to access an element outside the bounds of the vector.

```c++
std::vector <int> testScores(10); // 10 elements initialized to 0
testScores[0] = 100;
std::cout << testScores[0] << std::endl; // 100
```

Unlike arrays, when declaring a vector, all elements are initialized to zero by default.

### Useful vector methods

* `push_back()` - Adds an element to the end of the vector.
* `pop_back()` - Removes the last element from the vector.
* `size()` - Returns the number of elements in the vector.
* `at()` - Returns the element at a specific index.
* `empty()` - Returns true if the vector is empty, false otherwise.

```c++
std::vector <int> testScores(10); // 10 elements initialized to 0
testScores.push_back(100);        // Adds 100 to the end of the vector
testScores.pop_back();            // Removes the last element from the vector
std::cout << testScores.size() << std::endl; // 1
std::cout << testScores.at(0) << std::endl;   // 0
std::cout << testScores.empty() << std::endl; // 0 (boolean false)
```
