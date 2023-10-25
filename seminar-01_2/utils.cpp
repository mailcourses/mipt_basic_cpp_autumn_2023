#include "utils.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>

int32_t add(int32_t a, int32_t b)
{
    uint32_t c = 100;
    if (a < c)
        return a + c;
    return a + b;
}

void foo()
{
    // что-то 
}

std::string replace_spaces(std::string input)
{
    std::replace(input.begin(), input.end(), ' ', '%');

    return input;
}

// exit(main())

/*
int main()
{
    int32_t a{10};
    foo();
    std::string txt{"word1 word2"}; // ("word1 word2")
                                    // = std::string("word1 word2") | = "word1 word2"
    char *const data = replace_spaces(txt).data();
    printf("%d === %s\n", a, data);//.data()); // data() == char * const
    std::cout << replace_spaces(txt) << "\n"; // std::endl;
    return 0;
}
*/
