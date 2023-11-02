#include <iostream>

int main()
{
    int n = 0, m = 0, sum = 0;
    std::cin >> n >> m;
    for (int i = 0; i <= n; ++i)
    {
        if ((i % m) == 0)
        {
            std::cout << i << std::endl;
            sum += i;
        }
    }
    std::cout  << "sum=" << sum << std::endl;
}
