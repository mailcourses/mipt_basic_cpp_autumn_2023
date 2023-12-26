#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <vector>
#include <random>

std::pair<size_t, std::string> generate_str(size_t id, int32_t duration)
{
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    return std::make_pair(id, "thread#" + std::to_string(id));
}

int main()
{
    const size_t optimal_thread_cnt = std::thread::hardware_concurrency();

    {
        auto f = std::async(std::launch::deferred, []() {
            return 5;
        });
        std::cout << "is_valid: " << f.valid() << std::endl;
        auto status = f.wait_for(std::chrono::seconds(1));
        while(status != std::future_status::ready)
        {
            if (status == std::future_status::deferred)
            {
                std::cout << "задача еще не стартовала" << std::endl;
                auto res = f.get();
                break;
            }
            else if (status == std::future_status::timeout)
            {
                std::cout << "результата не дождались" << std::endl;
            }
            else if (status == std::future_status::ready)
            {
                std::cout << "все готово";
            }
        }
        std::cout << "все готово" << std::endl;
    }
    {
        auto f = std::async(std::launch::async, []() {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return 5;
        });
        std::cout << "is_valid: " << f.valid() << std::endl;
        auto status = f.wait_for(std::chrono::seconds(1));
        while(status != std::future_status::ready)
        {
            if (status == std::future_status::deferred)
            {
                std::cout << "задача еще не стартовала" << std::endl;
                auto res = f.get();
                break;
            }
            else if (status == std::future_status::timeout)
            {
                std::cout << "результата не дождались" << std::endl;
                status = f.wait_for(std::chrono::seconds(1));
            }
        }
        std::cout << "все готово" << std::endl;
    }
}
