#include <iostream>

struct Base
{
    Base()
    {
        std::cout << "Base()" << std::endl;
    }
    ~Base()
    {
        std::cout << "~Base()" << std::endl;
    }
};

struct Foo : Base
{
    Foo(size_t size) : data(new int[size])
    {
        std::cout << "Foo()" << std::endl;
        throw std::exception();
        try
        {
            throw std::exception();
        }
        catch(...)
        {
            
        }
    }
    ~Foo()
    {
        std::cout << "~Foo()" << std::endl;
    }
    int* data = nullptr;
};

int main()
{
    try
    {
        Foo foo(100);
    }
    catch(...)
    {
        std::cout << "Catched by ..." << std::endl;
    }
}
