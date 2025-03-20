# Variables

## Creating a variable

[type] [identifier]; // uninitialized variable

[type] [identifier] = [value]; // initialized variable

Example:

```c++
int myAge;
```

## Uninitialized variables

Can be used, but should generally be manually set to the 0 value.

This depends on the compiler and language version, but generally, the value of an uninitialized variable is undefined,
**except** when defined at file scope instead of function scope.

Example:

```c++
int myAge; // uninitialized variable
int myAge = 0; // initialized variable, C-like
int myAge (0); // initialized variable, C++-like, constructor initialization
int myAge {0}; // initialized variable, C++11-like, list initialization
```

## Built in primitive types

Fundamental types are the basic types of, and implemented by the language.

### Character types

Used to represent characters and strings.

Wider types can represent wider character sets.

* `char`        - Exactly one byte.
* `char16_t`    - At least 16 bits
* `char32_t`    - At least 32 bits
* `wchar_t`     - Can represent the largest supported character set

There are differences when defining a character or a string, for example - you would define a character with single quotes, and a string with double quotes.

```c++
char myChar = 'A'; // character
char myString[] = "Hello"; // string
```

### Integer types

Used to represent whole numbers.

Both signed and unsigned types are supported.

Larger numbers can be delimited by a single quote (') for readability.

Example:

```c++
int myInt = 123'456'789;
```

#### Signed integers

The signed keyword is optional, as integers are signed by default.

* `signed short int`     - At least 16 bits
* `signed int`           - At least 16 bits
* `signed long int`      - At least 32 bits
* `signed long long int` - At least 64 bits

#### Unsigned integers

The unsigned keyword has to be used to specify an unsigned integer.

These can not be negative, but have positive ranges twice as large as signed integers.

* `unsigned short int`     - At least 16 bits
* `unsigned int`           - At least 16 bits
* `unsigned long int`      - At least 32 bits
* `unsigned long long int` - At least 64 bits

### Floating point types

Used to represent real numbers (Non integer numbers, fractions, decimals)

Represented in scientific notation by a mantissa and an exponent.

The precision represents the number of bits in the mantissa.

Precision and size are compiler dependant.

| Type        | Precision         | Negative range   | Positive Range  |
|-------------|-------------------|------------------|-----------------|
| float       | 7 Decimal digits  | 1.2 * 10 ^ -38   | 3.4 * 10 ^ 38   |
| double      | 15 decimal digits | 2.2 x 10 ^ -308  | 1.8 * 10 ^ 308  |
| long double | 19 decimal digits | 3.3 * 10 ^ -4932 | 1.2 * 10 ^ 4932 |

### Boolean types

Used to represent true or false values.

* `bool` - Can be either true or false.

Size is compiler dependant, but usually 8 bits (1 byte).

Zero would imply false, any non zero value implies true.

## Size of a variable

The `sizeof` operator can be used to retrieve the size of a variable in bytes (for a specific machine and compiler).

It can be used for types and variables.

Example:

```c++
int myInt = 123;
std::cout << sizeof(myInt) << std::endl; // 4
std::cout << sizeof(int) << std::endl; // 4
```

For variables, the parentheses are optional.

Example:

```c++
int myInt = 123;

std::cout << sizeof myInt << std::endl; // 4
std::cout << sizeof int << std::endl; // Syntax error
```

### CLimits and CFloat

The `climits` and `cfloat` headers provide information about the limits of the built in types.

This information is compiler dependant, but generally provides the minimum and maximum values for each type.

The climits library provides this information for integral types (char, short, int, long, long long).

The cfloat library provides this information for floating point types (float, double, long double).

## Constants

The value of a constant can not be changed after it has been defined.

Constants always have the following:

1. An identifier
2. A type
3. A value

There are a few different types of constants in C++.

* Literal constants
* Declared constants (const keyword)
* Constant expressions (constexpr keyword)
* Enumerated constants (enum keyword)
* Macro/Defined constants (#define directive)

### Literal constants

These are constants that are directly written into the code, the most obvious kinds of constants.

Example:

```c++
int myInt = 123; // 123 is a literal constant
char myName[] = "John"; // "John" is a literal constant
```

Integers can also be suffixed with `u` or `U` for unsigned, `l` or `L` for long, and `ll` or `LL` for long long.

Example:

```c++
int myInt = 123; // int
unsigned int myUInt = 123u; // unsigned int
long myLong = 123l; // long
long long myLongLong = 123ll; // long long
```

Floating point literal constants can be suffixed with `f` or `F` for float, `l` or `L` for long double.

 > From the gcc [manual](https://gcc.gnu.org/onlinedocs/gcc/Long-Long.html):
 > > ISO C99 supports data types for integers that are at least 64 bits wide ( . . . ) . To make an integer constant of type long long int, add the suffix LL to the integer. To make an integer constant of type unsigned long long int, add the suffix ULL to the integer.
 > -- <cite>https://stackoverflow.com/a/8809325</cite>

### Macro/Defined constants

Defined constants are created using the `#define` directive.

These are very common in old C and C++ code, but are generally discouraged in modern C++.

The preprocessor replaces all instances of the defined constant with the value.

But there is a catch - the preprocessor does not understand the C++ syntax or type system so it can lead to unexpected behavior.
