#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <vector>
#include <random>

int32_t gValue = 0;

void task(size_t id, int32_t duration)
{
    auto thread_id = std::this_thread::get_id();
    std::cout << "thread #" << id << " (" << thread_id << ")" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    gValue += 10;
    std::cout << "thread #" << id << " (" << thread_id << ") finished" << std::endl;
    std::cout << "gValue = " << gValue << std::endl;
}

std::pair<size_t, std::string> generate_str(size_t id, int32_t duration)
{
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    return std::make_pair(id, "thread#" + std::to_string(id));
}

int main()
{
    const size_t optimal_thread_cnt = std::thread::hardware_concurrency();
    std::cout << "hardware_concurrency: " << optimal_thread_cnt << std::endl;
    {
        std::thread tr1(task, 0, 5);
        std::thread tr2(task, 1, 2);

        std::cout << "[before] waiting for thread1" << std::endl;
        tr1.join();
        std::cout << "[after] finished waiting for thread1" << std::endl;
        std::cout << "[before] waiting for thread2" << std::endl;
        tr2.join();
        std::cout << "[after] finished waiting for thread2" << std::endl;
        std::cout << "[main] gValue = " << gValue << std::endl;
    }
    {
        std::vector< std::future< std::pair<size_t, std::string> > > futures;
        for (size_t i = 0; i < optimal_thread_cnt; ++i)
        {
            futures.push_back( std::async(std::launch::async, generate_str, i, optimal_thread_cnt-i) );
        }

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(std::begin(futures), std::end(futures), g);

        for(size_t i = 0; i < futures.size(); ++i)
        {
            std::cout << "Waiting for out future result..." << std::endl;
            auto&& future = futures[i];
            auto [thread_id, res] = future.get();
            std::cout << "thread_id= " << thread_id  << ", res = " << res << std::endl;
        }
    }
}
