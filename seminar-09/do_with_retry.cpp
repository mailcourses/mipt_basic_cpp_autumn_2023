#include <iostream>
#include <exception>
#include <chrono>
#include <thread>

template<typename Result, typename Exception = std::exception>
Result DoWithRetry(std::function<Result()> func, size_t tries, size_t delay)
{
    size_t counter = 0;
    while(true)
    {
        try
        {
            return func();
        } catch(const Exception& ex)
        {
            std::cout << "Attempt #" << counter << ", we are going to sleep for " << delay << std::endl;
            ++counter;
            std::this_thread::sleep_for(std::chrono::seconds(delay));
            if (counter > tries)
                throw ex;
        }
    }
}

struct ResponseException
{
    ResponseException(const std::string& message) : message(message) {}
    std::string message;
};

std::string get_response()
{
    static size_t cnt = 0;
    if (cnt < 20)
    {
        cnt++;
        throw ResponseException("MIPT");
    }
    return "Hello kitty.";
}

int main()
{
    try{
        auto result = DoWithRetry<std::string, ResponseException>(get_response, 3, 1);
        std::cout << "result of function get_response is [" << result << "]" << std::endl;
    } catch (const ResponseException &ex)
    {
        std::cerr << "[ERR] Message: " << ex.message << std::endl;
    }
}
















