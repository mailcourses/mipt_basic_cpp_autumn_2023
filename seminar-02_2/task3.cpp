#include <iostream>

int main()
{
    int n;
    int sum = 0;
    std::cin >> n;
    while (n / 10 > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    sum += n;
    std::cout << "sum=" << sum << std::endl;
}
