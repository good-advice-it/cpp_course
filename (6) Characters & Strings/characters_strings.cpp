#include <iostream>
#include <string>

char* myStr1 = "hahahaha";
char myStr2[5] = "haha"; // 5 characters, 4 + 1 for null terminator
char myStr3[5] = "hah"; // 5 characters, 3 + 2 nulls, the final null being the terminator (but unnecessary)
std::string myStr4 ("haha"); // 5 characters, 4 + 1 for null terminator
std::string myStr5 ("zipzap"); // 5 characters, 4 + 1 for null terminator

int main(int argc, char const *argv[]) {
    /* code */

    // char* myStr5 = myStr1 + 5; no pointer arithmetic.... dont do this. bad. BAD!

    std::cout << "myStr1: " << myStr1 << std::endl;
    std::cout << "myStr2: " << myStr2 << std::endl;
    std::cout << "myStr3: " << myStr3 << std::endl;
    std::cout << "myStr4: " << myStr4 << std::endl;
    std::cout << "myStr5: " << myStr5 << std::endl;

    std::cout << myStr4 + myStr5 << std::endl; // This is pointer arithmetic, but it's not what you think it is

    for (auto c : myStr2) {
        std::cout << c << std::endl;
    }

    return 0;
}
