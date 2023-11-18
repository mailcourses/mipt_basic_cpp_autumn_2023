#include "searcher.hpp"

std::string search(std::string query, uint32_t region)
{
    //
    if (query == "weather" && region == 1)
        return std::string{"Rostov,18"};
    else if (query == "weather" && region == 70)
        return std::string{"Moscow,8"};
    return std::string{};
}

bool isEqual(std::string text1, std::string text2)
{
    return convertTextToSound(text1) == convertTextToSound(text2);
}

std::string convertTextToSound(std::string text)
{
    if (text == std::string{"Ashcraft"})
        return std::string{"A261"};
    if (text == std::string{"Ashcroft"})
        return std::string{"A261"};
    return std::string{"0000"};
}
