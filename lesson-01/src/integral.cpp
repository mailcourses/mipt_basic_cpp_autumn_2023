#include <iostream>
#include <cstdint> // для intX_t
#include <cstddef> // для size_t

int main()
{
    unsigned int num1 = 100;
    unsigned short int num2 = 10;
    long long int num3 = 1000;
    std::cout << sizeof(num1) << " == " << sizeof(int) << std::endl;
    std::cout << sizeof(num2) << " == " << sizeof(short int) << std::endl;
    std::cout << sizeof(num3) << " == " << sizeof(long long int) << std::endl;
    uint32_t num4 = 1'000'000; // 1_000_000
    uint64_t num5;
    uint8_t num6;
    size_t size;
    std::cout << "sizeof(size_t) = " << sizeof(size_t) << std::endl; 
    for (size_t i = 10; i >= 0; --i)
    {
        std::cout << i << std::endl;
        if (i > 10) break;
    }
}
