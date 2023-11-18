#include <string>
#include <iostream>

bool isPalindrome(const std::string &str)
{
    if (str.empty())
        return true;
    
    size_t n = str.size();   
    
    for (size_t i = 0; str[i] == str[n-1-i]; ++i)
    {
        if (n-1-i < i)
        {
            return true;
        }
    }
    return false;
}

int main()
{   std::string long_str{"assdfsdfsdf.....sfdsdfsdf"};
    isPalindrome(long_str);
    std::cout << std::boolalpha << isPalindrome("baoab") << std::endl;
    std::cout << std::boolalpha << isPalindrome("babcb") << std::endl;
    std::cout << std::boolalpha << isPalindrome("") << std::endl; // ???
    std::cout << std::boolalpha << isPalindrome("abba") << std::endl;
}
