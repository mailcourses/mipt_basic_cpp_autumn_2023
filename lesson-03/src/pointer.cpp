#include <iostream>

int main()
{

    int a1 = 100;
    int a2 = 300;
    //const int* b = nullptr;
    int const* const b = &a1;
    if (b == nullptr)
    {
        //b = &a1;
    }

    std::cout << "a before = " << a1 << std::endl;
    //*b = 200;
    std::cout << "a after = " << a1 << std::endl;

    //b = &a2;

    int** c = nullptr;
    //c = &b;
    int*** d = &c;
    int**** e = &d;

    int* f = new int[10];
    delete[] f;
    std::cout << "sizeof(int*) = " << sizeof(int*) << ", sizeof(char*) = " << sizeof(char*) << std::endl;
    //char buf[8192 * 1024];
    char *ch = nullptr;
    char &ch_ref = *ch;
    std::cout << ch_ref << std::endl;
}
