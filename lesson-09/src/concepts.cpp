#include <iostream>

struct A
{
    void foo() {}
    double magic;
};

struct B
{
};

template<typename T>
concept FooType =
    requires (T t) {
        { t.foo() } -> std::same_as<void>;
        { t.magic } -> std::convertible_to<int>;
    };

template<FooType T>
void boo(T t)
{
    std::cout << "[boo] Type T with void foo() function." << std::endl;
    t.foo();
}

template<class T>
void boo(T t)
{
    std::cout << "[boo] Type T without void foo() function." << std::endl;
}

int main()
{
    A a;
    B b;
    boo(a);
    boo(b);
}
