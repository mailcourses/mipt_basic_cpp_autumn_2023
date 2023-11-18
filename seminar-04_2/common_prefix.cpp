#include <iostream>
#include <vector>
#include <algorithm>

//! Особая уличная магия. Хотите немного магии?
size_t min(const std::vector<std::string>& strs)
{
    return (*std::min_element(std::begin(strs),
                              std::end(strs),
                              [](const std::string& str1, const std::string& str2) {
                                   return str1.length() < str2.length();
    })).size();
}

std::string getCommonPrefix(const std::vector<std::string>& strs)
{
    std::string res{};

    if (strs.empty())
    {
        return res;
    }

    size_t min_str_len = min(strs);
    for (size_t col = 0; col < min_str_len; ++col)
    {
        for (size_t row = 0; row < strs.size()-1; ++row)
        {
            if (strs[row][col] != strs[row+1][col])
                return res;
        }
        res.push_back( strs.back()[col] );
    }
    return res;
}

int main()
{
    std::vector<std::string> strs = {"cacao", "cat", "calcium"};
    std::cout << "Common prefix: " << getCommonPrefix( strs ) << std::endl;
}
