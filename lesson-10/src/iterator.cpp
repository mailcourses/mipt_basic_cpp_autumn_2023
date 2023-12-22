#include <iterator>
#include <iostream>

template<typename T>
class ArrayIterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
    ArrayIterator(T* ptr) : ptr_(ptr) {}

    bool operator!=(const ArrayIterator& rhs)
    {
        return ptr_ != rhs.ptr_;
    }

    ArrayIterator& operator++()
    {
        ++ptr_;
        return *this;
    }

    T operator*()
    {
        return *ptr_;
    }
private:
    T* ptr_;
};

template<typename T, size_t Size>
struct Array
{
    using iterator = ArrayIterator<T>;

    Array(const std::initializer_list<T> &list)
    {
     //   static_assert(5 == list.size(), "Hello, world");
        auto it = std::begin(list);
        for (size_t i = 0; it != std::end(list) && i < Size; ++it, ++i )
        {
            data[i] = *it;
        }
    }

    iterator begin()
    {
        return iterator(data);
    }
    iterator end()
    {
        return iterator(data + Size);
    }

    T data[Size];
};

int main()
{
 //   std::array<int, 5> arr_ = {100, 500, 1, 6, 3, -1};
    Array<int32_t, 5> arr = {100, 500, 1, 6, 3, -1};
    for ( auto it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    return 0;
}
