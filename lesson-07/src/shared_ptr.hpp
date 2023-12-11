#include <iostream>

namespace smart_ptr
{

class shared_ptr
{
public:
    using T = std::string;

    shared_ptr() = default;
    shared_ptr(T*);
    //! Копирование
    shared_ptr(const shared_ptr&);
    shared_ptr& operator=(const shared_ptr&);
    //! Перемещение
    shared_ptr(shared_ptr&&);
    shared_ptr& operator=(shared_ptr&&);
    ~shared_ptr();
private:
    void destroy();
private:

    struct _shared_struct
    {
        T* data_ = nullptr;
        size_t counter_ = 0;
    };

private:
    _shared_struct* shared_ = nullptr;
};

} // namespace smart_ptr
