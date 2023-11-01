#include <iostream>
#include <cstdint>

#include "header.hpp"
#include "math.hpp"

#define MAGIC_VAR 100500
#define MAX(x, y) ( x > y ? x : y )
#define NAME(text) #text

int main()
{
    int32_t a = 0;
    int32_t b = MAGIC_VAR;
    std::cout << MAX(++a, 0) << std::endl;
    std::cout << MAX(++a, 10) << std::endl;

    #line 100
    std::cout << "Hello, " << NAME(world) << " from "
              << __FILE__ << " and line #" << __LINE__
              << std::endl;

//    std::string str = MAGIC_VAR;
/*
 *  Тернарный оператор
    if (<условие>)
    {
        <блок кода 1>
    }
    else
    {
        <блок кода 2>
    }
    ===
          <условие> ? <блок кода 1> : <блок кода 2>
max(a,b)  a > b ? a : b;
*/
    return 0;
}
