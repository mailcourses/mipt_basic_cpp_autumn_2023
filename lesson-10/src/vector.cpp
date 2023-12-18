#include <iostream>
#include <vector>

constexpr size_t N = 20;

/*
          0 1 2 3 4 5 6
vector = [z|z|z|z|z|z|z]

        0   1   2   3   4
list = [z]->[z]->[z]->[z]->[z]

         0 1 2 3    4 5 6 7    8 9 10 11
deque = [z|z|z|z]->[z|z|z|z]->[z|z|z|z]->
*/

int main()
{
    {
        std::vector<int> v;
        v.reserve(N);
        std::cout << "i #-1" << " capacity = " << v.capacity() << ", size = " << v.size() << std::endl;
        for (size_t i = 0; i < N; ++i)
        {
            v.push_back(i);
            std::cout << "i #" << i << " capacity = " << v.capacity() << ", size = " << v.size() << std::endl;
        }
        for (size_t i = 0; i < N/2; ++i)
        {
            v.pop_back();
            std::cout << "[pop_back] i #" << i << " capacity = " << v.capacity() << ", size = " << v.size() << std::endl;
        }
        v.shrink_to_fit();
        std::cout << "[pop_back] i #final" << " capacity = " << v.capacity() << ", size = " << v.size() << std::endl;

        v.clear();
        std::cout << "[pop_back] i #clear" << " capacity = " << v.capacity() << ", size = " << v.size() << std::endl;
        //v.swap(std::vector<int>());
        //std::cout << "[pop_back] i #clear2" << " capacity = " << v.capacity() << ", size = " << v.size() << std::endl;
    }
}
