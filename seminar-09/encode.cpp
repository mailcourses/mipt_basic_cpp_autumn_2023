#include <iostream>

std::string encode(const std::string& str)
{
    if (str.empty())
        return std::string{};
    std::string out;
    out.reserve(str.size());
    const size_t n = str.size();
    for (size_t i = 0; i < n - 1; ++i)
    {
        char elem = str[i];
        size_t num = 1;
        if (str[i] == str[i+1])
        {
            size_t j = i + 1;
            while (j < str.size() && str[j] == elem)
            {
               ++num;
               j++; i++;
            }
        }
        if (num != 1)
            out += std::to_string(num);
        out.push_back(elem);
    }
    // TODO: переделать.
    if (n >= 2 && str[n-1] != str[n-2])
    {
        out.push_back(str.back());
    }
    return out;
}

std::string encode2(const std::string& str)
{
    if (str.empty())
        return std::string{};
    std::string out;
    out.reserve(str.size());
    const size_t n = str.size();
    char ch = str[0];
    size_t cnt = 1;
    for (size_t i = 1; i < n; ++i)
    {
        if (str[i] == ch)
        {
            cnt++;
            continue;
        }
        if (cnt != 1)
            out += std::to_string(cnt);
        out.push_back(ch);
        cnt = 1;
        ch = str[i];
    }
    if (cnt != 1)
        out += std::to_string(cnt);
    out.push_back(ch);
    return out;
}

int main()
{
    {
        std::string str{"aabcdddee"};
        std::cout << str << std::endl;
        std::cout << encode(str) << std::endl;
    }
    {
        std::string str{"aabcdddef"};
        std::cout << str << std::endl;
        std::cout << encode(str) << std::endl;
    }
    {
        std::string str{"aabcdddee"};
        std::cout << str << std::endl;
        std::cout << encode2(str) << std::endl;
    }
    {
        std::string str{"aabcdddef"};
        std::cout << str << std::endl;
        std::cout << encode2(str) << std::endl;
    }
}
