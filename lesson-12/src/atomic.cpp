#include <future>
#include <thread>
#include <iostream>
#include <vector>
#include <atomic>

std::atomic<int> gValue = 0;


void foo(size_t id)
{
    gValue += 1; // gvalue = gvalue + 1;
}

constexpr int N = 1000;

int main()
{
    std::vector<std::thread> threads;
    for(size_t i = 0; i < N; ++i)
    {
        threads.emplace_back(foo, i);
    }
    for(size_t i = 0; i < N; ++i)
    {
        threads[i].join();
    }
    std::cout << "gValue=" << gValue << std::endl;
}
