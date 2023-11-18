[[fastcall]]
void foo1(int a, int b, int c, int d, char e, int f, int i, int j, double h)
{
}

void foo2(int a, int b, int c, int d)
{
}

void bar1()
{
    foo1(1,2,3,4,'5',6,7,8, 0.0);
}

void bar2()
{
    foo2(1,2,3,4);
}
