#include <iostream>
#include <climits>

int main()
{
    int min = INT_MAX, max = INT_MIN, sum = 0, count = 0;
    // min = std::numeric_limits<int>::max();
    // max = std::numeric_limits<int>::min();
    int num;
    while(std::cin >> num)
    {
        if (num < min) // min = std::min(min, num)
            min = num;
        if (num > max) // max = std::max(max, num);
            max = num;
        sum += num;
        count++; // ++count;
    }
    std::cout << "min: " << min << ", max: " << max << ", avg: " << ((float)sum / count) << std::endl;
}
