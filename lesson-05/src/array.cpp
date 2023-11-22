#include <iostream>

struct Array
{

    Array(int32_t init_num = 0)
    {
        for (size_t i = 0; i < N; ++i)
        {
            data[i] = init_num;
        }
    }

    Array sum(const Array& rhs)
    {
        Array res;
        for (size_t i = 0; i < N; ++i)
        {
            res.data[i] = data[i] + rhs.data[i];
        }
        return res;
    }

    Array operator+(const Array& rhs)
    {
        Array res;
        for (size_t i = 0; i < N; ++i)
        {
            res.data[i] = data[i] + rhs.data[i];
        }
        return res;
    }

    bool operator==(const Array& rhs)
    {
        for (size_t i = 0; i < N; ++i)
        {
            if (data[i] != rhs.data[i])
                return false;
        }
        return true;
    }

    std::ostream& operator<<(std::ostream& out)
    {
        for (size_t i = 0; i < N; ++i)
        {
            out << "i:" << i << ":" << data[i] << " ";
        }
        out << "\n";
        return out;
    }
    //(((std::cout << 32) << "example") << std::endl);

    static constexpr size_t N = 10;
    friend std::ostream& operator<<(std::ostream& out, const Array& arr);
private:
    int32_t data[N];
};

std::ostream& operator<<(std::ostream& out, const Array& arr)
{
    for (size_t i = 0; i < arr.N; ++i)
    {
        out << "i:" << i << ":" << arr.data[i] << " ";
    }
    return out;
}

int main()
{
    Array arr1(10);
    Array arr2(5);

    Array arr3 = arr1.sum(arr2);
    Array arr4 = arr1 + arr2;

    std::cout << std::boolalpha << (arr4 == arr3) << std::endl;
    std::cout << std::boolalpha << (arr1 == arr3) << std::endl;
    std::cout << arr1 << std::endl; // operator<<
    arr1 << std::cout << std::endl;
    return 0;
}
