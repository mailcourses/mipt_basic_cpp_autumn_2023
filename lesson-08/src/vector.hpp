
namespace my
{

template<typename T>
class vector
{
public:
    vector();
    void push_back(const T&);
    ~vector();
private:
    T* data_;
};

#include "vector.tpp"

template <int N>
int foo()
{
return N * 2;
}

template <double N>
int boo()
{
return N * 2;
}
/*
template<typename T>
vector<T>::vector() : data_(new T[10])
{
}

template<typename T>
vector<T>::~vector()
{
    delete[] data_;
}
*/

}; // namespace my
