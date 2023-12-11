#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "vector.hpp"

/*
template<typename Container, typename WithinType, typename Index>
WithinType authAndAccess(Container &c, Index i)
{}

authAndAccess<std::vector<std::string>, std::string, size_t>(vec, 0);
 */

template<typename Container, typename Index>
auto authAndAccess(Container &c, Index i) -> decltype(c[i])
{
   return c[i];
}

int main()
{
    std::unordered_map<std::string, std::vector<std::pair<std::string, int32_t>>> map;
    //std::unordered_map<std::string, std::vector<std::pair<std::string, int32_t>>>::iterator it = map.begin();
    auto it = map.begin();
    for (auto elem : map)
    {
        std::cout << elem.first << std::endl;
    }
    my::vector<int32_t> vec1;
    my::vector<std::string> vec2;

    my::foo<1>();
    //my::boo<2.0>();

    std::vector<std::string> vec{"hello", "cat", "dog", "ape"};
    //authAndAccess<std::vector<std::string>, size_t>(vec, 0);
    authAndAccess(vec, 0);






}
