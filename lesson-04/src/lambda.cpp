#include <iostream>

int main()
{
    int r = 200;
    std::string str{"500"};
    auto comp = [=, &r](int x, int y) {
        r *= 10;
        return x + y + r + std::stoi(str);
    };
    std::cout << "r=" << r << std::endl;
    std::cout << comp(10, 20) << std::endl;
}
