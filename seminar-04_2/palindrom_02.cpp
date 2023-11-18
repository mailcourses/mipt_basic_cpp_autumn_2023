#include <string>
#include <iostream>

bool isPalindrome(const std::string &str)
{
    size_t i = 0;
    size_t j = str.length()-1;
    while (i < j)
    {
        if (str[i] == ' ')
        {
            ++i;
            continue;
        }
        
        if (str[j] == ' ')
        {
            --j;
            continue;
        }
        
        if (str[i] != str[j])
        {
            return false;
        }
        ++i; --j;
        
    }
    return true;
}

int main()
{
    std::cout << std::boolalpha << isPalindrome("b ao  ab  ") << std::endl;
    std::cout << std::boolalpha << isPalindrome("        babcb") << std::endl;
    std::cout << std::boolalpha << isPalindrome("t") << std::endl; // ???
    std::cout << std::boolalpha << isPalindrome("ab ba") << std::endl;
}
