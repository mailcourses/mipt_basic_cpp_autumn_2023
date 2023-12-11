#include <iostream>

#pragma pack(push, 2)
class S
{
public:
    char m1;
    double m2;
};
#pragma pack(pop)

class S1
{
public:
    double m1;
    int32_t m2;
    int32_t m3;
};

int main()
{
    std::cout << "sizeof(char)=" << sizeof(char) << std::endl;
    std::cout << "sizeof(double)=" << sizeof(double) << std::endl;
    std::cout << "sizeof(S)=" << sizeof(S) << std::endl;
    std::cout << "offsetof(S, m1)=" << offsetof(S, m1) << std::endl;
    std::cout << "offsetof(S, m2)=" << offsetof(S, m2) << std::endl;

    std::cout << "============" << std::endl;
    std::cout << "offsetof(S1, m1)=" << offsetof(S1, m1) << std::endl;
    std::cout << "offsetof(S2, m2)=" << offsetof(S1, m2) << std::endl;
    std::cout << "offsetof(S2, m3)=" << offsetof(S1, m3) << std::endl;
    std::cout << "sizeof(S1)=" << sizeof(S1) << std::endl;
}
