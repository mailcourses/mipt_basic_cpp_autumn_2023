#include <iostream>
#include <queue>
#include <vector>

struct Foo
{
    int val{0};
    std::string str{};
    Foo(int val, const std::string& str): val(val), str(str) {}
};

std::ostream& operator<<(std::ostream& out, const Foo& foo)
{
    out << "Foo(" << foo.val << ", " << foo.str << ")";
    return out;
}

int main()
{
    // A = []
    // len(A) = n
    // k наибольших элементов.
    constexpr int k = 3;

    // n log k
    {
        std::vector<int> A = {4,2,8,10,3};
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int num : A)
        {
            pq.push(num);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        while(!pq.empty())
        {
            std::cout << pq.top() << " ";
            pq.pop();
        }
        // n log n + n log n -> O(n log n)
        std::cout << std::endl;
    }
    {
        std::vector<int> A = {4,2,8,10,3};
        // n log n
        std::sort(std::rbegin(A), std::rend(A));
        for (size_t i = 0; i < k; ++i)
        {
            int num = A[i];
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    {
        std::vector<Foo> foos = {Foo(4, "Walter"), Foo(2, "Jesse"), Foo(8, "Gus"), Foo(10, "Mike"), Foo(8, "Soul")};
        auto cmp = [](const Foo& lhs, const Foo& rhs)
        {
            if(lhs.val == rhs.val)
                return lhs.str < rhs.str;
            return lhs.val < rhs.val;
        };

        std::priority_queue<Foo, std::vector<Foo>, decltype(cmp)> pq(cmp);
        for (Foo& foo: foos)
        {
            pq.push(foo);
        }

        while(!pq.empty())
        {
            std::cout << pq.top() << " ";
            pq.pop();
        }
    }
}
