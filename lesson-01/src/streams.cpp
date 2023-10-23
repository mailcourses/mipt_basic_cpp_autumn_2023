#include <iostream>
#include <iomanip>

// ostream& operator>>(ostream&, std::string&)

int main()
{
    std::string text;
    int32_t num;
    while (std::cin >> text >> num)
    {
        uint64_t abs_num = num > 0 ? num : -num;
        for (size_t i = 0; i < text.length(); ++i)
        {
            // std::toupper()
            text[i] = std::tolower(text[i]);
        }
        auto str1 = std::to_string(abs_num);
        //std::cout << text << " <=> " << std::setw(12) << std::setfill('a') << abs_num << "\n";
        std::cout << text << " <=> " << std::setw(12) << abs_num << "\n";
    }
}
