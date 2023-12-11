#include <cstdint>

#include "vector.hpp"

namespace my
{

template<typename T>
vector<T>::vector() : data_(new T[10])
{
}

template<typename T>
vector<T>::~vector()
{
    delete[] data_;
}

template class vector<int32_t>;
template class vector<float>;

} // namespace my
