// main которая со стандартного ввода считывает
// данные в формате:
// <triangle|rectangle> <length1> <length2> [<length3>]
#include <iostream>
#include <string>

#include "figure.hpp"

void print(Figure &t)
{
    std::cout << t << std::endl;
}

int main()
{
    std::string figure;
    double len[3];
    while (std::cin >> figure) 
    {
        if (figure == "triangle")
        {
            std::cin >> len[0] >> len[1] >> len[2];
            Triangle triangle(len[0], len[1], len[2]);
            print(triangle);
        }
        else
        if (figure == "rectangle")
        {
            std::cin >> len[0] >> len[1];
            Rectangle rectangle(len[0], len[1]);
            print(rectangle);
        }
    }
    return 0;
}
