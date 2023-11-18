#include <iostream>

#include "header.hpp"

//static int i = 1;
int i = 1;

void foo()
{
    static int j = 2;
    int k = 3;
    std::cout << "i = " << i << ", j = " << j << ", k = " << k << std::endl;
    ++i; ++j; ++k;
}

int main()
{
    for (size_t n = 0; n < 5; ++n)
    {
        foo();
        std::cout << "i = " << i << std::endl;
    }
    std::cout << "magic_num = " << magic_num << std::endl;
    int tmp;
    std::cin >> tmp;
}
