#include <iostream>

int add(int x, int y) {
    return x + y;
}

double add(double x, double y) {
    return x + y;
}

short add(short x, short y) {
    static int count = 0;
    std::cout << "Function call count: " << ++count << std::endl;
    return x + y;
}

int main() {
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.1, 2.2) << std::endl;
    std::cout << add(static_cast<short>(1), static_cast<short>(2)) << std::endl;
    std::cout << add(static_cast<short>(3), static_cast<short>(4)) << std::endl;
    return 0;
}