# Characters & Strings

## C-style strings

Sequence of contiguously stored characters, terminated by a null character.

```cpp
char str[] = "Hello";
char* str = "Hello";
```

The C++ compiler will automatically add a null character at the end of string literals.

## CPP strings

```cpp
#include <string>
using namespace std;

string s0 = "Hello";
string s1 {s0}; // Copy constructor
string s2 {s0, 1, 3}; // s2 = "ell"
string s3 (5, 'a'); // s3 = "aaaaa"
string s4 = s0 // Copy assignment
```
