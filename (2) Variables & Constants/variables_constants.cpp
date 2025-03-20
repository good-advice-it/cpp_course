#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

// (1) Variable declaration (uninitialized, global scope)
// int age;

int main() {
    // (1) Variable declaration (uninitialized, local scope)
    // int otherAge;
    // cout << "My age: " << age << endl;
    // cout << "Other age: " << otherAge << endl;

    // (2) Variable declaration (initialized, local scope)
    // Does not compile (will possible compile on older versions and overflow)
    // long people_on_earth = 7'800'000'000;
    // long people_on_earth {7'800'000'000};
    // cout << "People on Earth: " << people_on_earth << endl;

    // (3) climits and cfloat
    // CLimits defines the limits of the data types for the following:
    // char, short, int, long, long long, float, double, long double
    // CFloat defines the limits of the floating point data types for the following:
    // float, double, long double
    // 
    // cout << "Minimum value for char: " << CHAR_MIN << endl;
    // cout << "Maximum value for char: " << CHAR_MAX << endl;
    // 
    // cout << "Minimum value for short: " << SHRT_MIN << endl;
    // cout << "Maximum value for short: " << SHRT_MAX << endl;
    // 
    // cout << "Minimum value for int: " << INT_MIN << endl;
    // cout << "Maximum value for int: " << INT_MAX << endl;
    // cout << "Maximum value for int: " << INT_MAX << endl;

    // (4) Constants
    const int x = 12LL;
    const long long y = 12LL;
    cout << "x: " << x << " size: " << sizeof(x) << endl;
    cout << "y: " << y << " size: " << sizeof(y) << endl;

    return 0;
}
