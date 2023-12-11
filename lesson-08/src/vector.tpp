template<typename T>
vector<T>::vector() : data_(new T[10])
{
}

template<typename T>
vector<T>::~vector()
{
    delete[] data_;
}

