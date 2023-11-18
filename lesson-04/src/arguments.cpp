#include <iostream>

void foo(int a)
{
    std::cout << "[foo] a before = " << a << std::endl;
    a += 1;
    std::cout << "[foo] a after = " << a << std::endl;
}

void boo(int &a)
{
    std::cout << "[boo] a before = " << a << std::endl;
    int b = 100500;
    a = b;
    a += 1;
    std::cout << "[boo] a after = " << a << std::endl;
}

void moo(const int &a)
{
    std::cout << "[moo] a before = " << a << std::endl;
    //a += 1; <-- не будет компилироваться, так как изменять
    //пытаемся.
    std::cout << "[moo] a after = " << a << std::endl;
}

void goo(int *a)
{
    if (a == nullptr)
        return;
    std::cout << "[goo] a before = " << *a << std::endl;
    *a += 1;
    std::cout << "[goo] a after = " << *a << std::endl;
}

int main()
{
    int tmp = 0;
    foo(tmp);
    std::cout << "tmp after foo = " << tmp << std::endl;

    boo(tmp);
    std::cout << "tmp after boo = " << tmp << std::endl;

    moo(tmp);
    std::cout << "tmp after moo = " << tmp << std::endl;

    goo(&tmp);
    std::cout << "tmp after goo = " << tmp << std::endl;

    goo(nullptr);
}
