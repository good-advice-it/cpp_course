# Functions

Functions work basically the same as any other language.

Two functions can not just "call" each other, they must be defined before they are called.
This is done with function prototypes.
A function prototype is a declaration of a function that tells the compiler what the function will return and what parameters it will take.

```cpp
#include <iostream>

// Function prototype
int add(int x, int y);

int main() {
    std::cout << add(1, 2) << std::endl;
    return 0;
}

// Function definition
int add(int x, int y) {
    return x + y;
}
```

## Default arguments

Default arguments can be provided for a function.

If a default argument is provided, the argument can be omitted when calling the function.

This can be defined in the function prototype or the function definition, but not both.

If the default argument is defined in the function prototype, it does not need to be defined in the function definition.

If the default argument is defined in the function definition, it does not need to be defined in the function prototype.

The best practice is to define the default argument in the function prototype.

```cpp
#include <iostream>

int main() {
    std::cout << add(1) << std::endl;
    return 0;
}

int add(int x, int y = 2) {
    return x + y;
}
```

## Pass-by-value

When a function is called, the arguments are passed to the function.

The arguments can be passed by value, reference, or pointer.

A copy is made of the argument passed.

This means that for example, if a large object is passed to a function, the object is copied, resulting in a possibly expensive operation.

```cpp
#include <iostream>

void add(int x) {
    x++; // this operation acts on a copy of the X passed to the function
}

int main() {
    int x = 1;
    add(x);
    std::cout << x << std::endl; // X is still 1 due to the value being copied
    return 0;
}
```

## Pass-by-reference

Passing by reference is done by adding an `&` to the parameter, this means that the function will act on a pointer (or reference) to the original object passed.

This means that the function can change the value of the object passed.

```cpp
#include <iostream>

void add(int &x) {
    x++;
}

int main() {
    int x = 1;
    add(x);
    std::cout << x << std::endl; // X is now 2
    return 0;
}
```

This is not like a reference in say, the GO programming language, where a copy of the pointer value is passed.

Unlike GO, the pointer also does not need to be dereferenced to access the value, you can work with the reference as if it were the original object.

## Overloading functions

Functions can be overloaded in C++.

These functions are able to have different parameter list, but the compiler has to be able to tell this apart.

It is an example of polymorphism, meaning that the same function name can be used for different functions.

```cpp
#include <iostream>

int add(int x, int y) {
    return x + y;
}

double add(double x, double y) {
    return x + y;
}

int main() {
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.1, 2.2) << std::endl;
    return 0;
}
```

The return type is however not considered when overloading functions.

Meaning the following would be an error:

```cpp
#include <iostream>

int getNumber() {
    return 1;
}

double getNumber() {
    return 1.1;
}

int main() {
    std::cout << getNumber() << std::endl;
    return 0;
}
```

If the `int getNumber()` function is provided with a default value, the following would be valid
(because a default value is provided and the compiler now knows which function to call):

```cpp
#include <iostream>

int getNumber(int x = 1) {
    return x;
}

double getNumber() {
    return 1.1;
}

int main() {
    std::cout << getNumber() << std::endl;
    return 0;
}
```

## Arrays to functions

Passing an array to a function is done by passing a pointer to the first element of the array.

Thus, only the pointer value gets copied and not the entire array.

## Const parameters

If a parameter is declared as `const`, the function can not change the value of the parameter.

This is useful when passing large objects to functions, or possibly arrays that should not be changed.

## Static variables

Static variables are variables that are shared between all instances of a function.

These are only initialized once, the value is kept between function calls.

```cpp
#include <iostream>

void increment() {
    static int x = 0;
    x++;
    std::cout << x << std::endl;
}

int main() {
    increment();
    increment();
    increment();
    return 0;
}
```

## How do function calls work

* Analogous to a stack of books
* LIFO stack
* Push & pop

### Stack frame or Activation record

* Functions must return control to the caller.
* Each function call, a new activation record is created and pushed onto the stack.
* When the function returns, the activation record is popped off the stack.

#### The activation record

The activation record contains the following:

* Return address
* Parameters
* Local variables
* Temporary variables
* Saved registers

### Stack overflow

Stack size is finite and too much data might get pushed onto the stack, this is called a stack overflow.

This can happen when (for example) a recursive function is called too many times.

### Inline functions

Inline functions are functions that are expanded in place of the function call.

This is done by the compiler, and is not guaranteed to happen.

We can however suggest to the compiler that we want a function to be inlined by using the `inline` keyword.

This will avoid the overhead of a function call, but will increase the size of the program.

This is useful for small functions that are called many times. Large functions should not be inlined.

```cpp
#include <iostream>

inline int add(int x, int y) {
    return x + y;
}

int main() {
    std::cout << add(1, 2) << std::endl;
    return 0;
}
```


