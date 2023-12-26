#include <future>
#include <iostream>

double sample(size_t id)
{
    std::cout << "Starting sample" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Just before end of sample" << std::endl;
    return 100500.0;
}

void task1(std::future<double> future)
{
    std::cout << "task starting " << std::endl;
    double res = -1.0;
    auto status = future.wait_for(std::chrono::milliseconds(500));
    while (true)
    {
        if (status == std::future_status::deferred)
            std::cout << "задача еще не стартовала" << std::endl;
        else if (status == std::future_status::timeout)
            std::cout << "результата не дождались" << std::endl;
        else if (status == std::future_status::ready)
        {
            std::cout << "все готово" << std::endl;
            res = future.get();
            break;
        }
        status = future.wait_for(std::chrono::milliseconds(500));
    }
    std::cout << "task ending " << std::endl;
    std::cout << "res = " << res << std::endl;
}

int main()
{
    std::packaged_task<double(size_t)> task{sample};
    auto future = task.get_future();
    std::cout << "After get future" << std::endl;
    // что-то делаемgg
    std::thread sample_th(std::move(task), 100);
    // что-то делать
    std::thread t(task1, std::move(future));
    //std::cout << "result of our future is " << future.get() << std::endl;
    sample_th.join();
    t.join();
}
