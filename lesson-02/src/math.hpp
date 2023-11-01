#pragma once

double square(double d);
int sum(int a, int b);
int sum(double a, double b);

struct Foo
{
    int sum(int a, int b);
};

namespace mystd
{
    int sum(int a, int b);
};
