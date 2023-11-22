#include <iostream>
#include <chrono>

class Profiler
{
public:
    Profiler(const std::string& func_name) : func_name_(func_name)
    {
        start_ts_ = std::chrono::system_clock::now();
    }
    ~Profiler()
    {
        auto end_ts_ = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_ts_ - start_ts_);
        std::cout << "Duration of execution function \"" << func_name_ << "\" is " << duration.count() << std::endl;
    }
private:
    std::string func_name_;
    std::chrono::time_point<std::chrono::system_clock> start_ts_;
};

void foo()
{
    Profiler prf(__func__);
    for (size_t i = 0; i < 1,000,000; ++i)
    {
    }
}

void boo()
{
    Profiler prf(__func__);
    for (size_t i = 0; i < 2,000,000; ++i)
    {
    }
}

int main()
{
    foo();
    boo();
    return 0;
}
