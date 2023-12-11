#include <iostream>

struct A
{
    A(const std::string& name) : name(name)
    {
        std::cout << "A() " << name << std::endl;
    }
    ~A()
    {
        std::cout << "~A() " << name << std::endl;
    }
    std::string name;
};

struct Error {};
struct FileError : public Error {};

void foo() {
    A a1("a1");
    throw Error();
}

void bar() {
    A a2("a2");
    try
    {
        A a3("a3");
        foo();
    }
    catch (const FileError&)
    {
        std::cout << "Catched by FileError" << std::endl;
    }
}

int main()
{
    try
    {
       bar();
    }
    catch(const Error&)
    {
        std::cout << "Catched by Error" << std::endl;
    }
    catch(...)
    {
        std::cout << "Catched by ..." << std::endl;
    }
}
