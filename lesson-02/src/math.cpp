#include "math.hpp"

double square(double d)
{
    return d * d;
}

int sum(int a, int b)
{
    return a + b;
}

int sum(double a, double b)
{
    return a + b;
}

int Foo::sum(int a, int b)
{
    return a + b;
}

namespace mystd
{
    int sum(int a, int b)
    {
        return a + b;
    }
};
