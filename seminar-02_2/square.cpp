#include <cstdint>
#include <cstdlib>

int32_t square(int32_t num)
{
    return num * num;
}

int main()
{
    //int a;
    int b = 10;
    unsigned int c = 100;
    int *d = (int *)malloc(10 * sizeof(int));
    // .. какая-то логика
    d[0] = 10;
    //free(d);
    if (b < (int)c)
        return square(1);
    return square(4);
}
