#include <cstdint>
#include <string>
#include <iostream>

template<class T>
class Matrix
{
public:
    void foo(){}
    bool operator<(int rhs) { return true; }
public:
    T* data;
};

template <class T>
bool lessThan7(T value) { return value < 7; }


template <class T>
void print(T&& val)
{
    std::cout << "[print single] " << val << '\n';
}
template <class T, class... Args>
void print(T&& val, Args&&... args)
{
    std::cout << "[print variadic] " << val << '\n';
    print(std::forward<Args>(args)...);
}

int main()
{
    Matrix<int32_t> m1;
    m1.foo();
    Matrix<float> m2;
    m2.foo();
    Matrix<std::string> m3;
    m3.foo();

    lessThan7(10);
    lessThan7(4.0);
    lessThan7<Matrix<int32_t>>(m1);
    lessThan7(m2);
    print(10, "hello, world", 5.0, 1, 1, 1);
    return 0;
}
