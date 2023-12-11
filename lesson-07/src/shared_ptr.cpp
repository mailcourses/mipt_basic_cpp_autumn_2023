#include "shared_ptr.hpp"

namespace smart_ptr
{

shared_ptr::shared_ptr(T* rhs) : shared_(new _shared_struct)
{
    shared_->counter_ += 1;
    shared_->data_ = rhs;
}

/*
 * shared_ptr sp1;
 * shared_ptr sp2(sp1);
 */
shared_ptr::shared_ptr(const shared_ptr& rhs)
{
    /*this->*/shared_ = rhs.shared_;
    shared_->counter_ += 1;
    std::cout << "Incrementing counter... " << shared_->counter_ << std::endl;
}

/*
 * shared_ptr sp1;
 * shared_ptr sp2;
 * shared_ptr sp3(sp2);
 * ...
 * sp3 = sp1;
 */
shared_ptr&
shared_ptr::operator=(const shared_ptr& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    destroy();
    shared_ = rhs.shared_;
    shared_->counter_ += 1;
    std::cout << "[operator=] Incrementing counter... " << shared_->counter_ << std::endl;
    return *this;
}

/*
 * shared_ptr sp1;
 * shared_ptr sp2(std::move(sp1));
 */
shared_ptr::shared_ptr(shared_ptr&& rhs)
{
    /*this->*/shared_ = rhs.shared_;
    rhs.shared_ = nullptr;
    std::cout << "shared_ptr(&&)" << std::endl;
}

/*
 * shared_ptr sp1;
 * shared_ptr sp2;
 * shared_ptr sp3(sp2);
 * ...
 * sp3 = std::move(sp1);
 */
shared_ptr&
shared_ptr::operator=(shared_ptr&& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    destroy();
    shared_ = rhs.shared_;
    rhs.shared_ = nullptr;
    std::cout << "operator=(&&)" << std::endl;
    return *this;
}

shared_ptr::~shared_ptr()
{
    std::cout << "~shared_ptr()" << std::endl;
    destroy();
}

void shared_ptr::destroy()
{
    if (!shared_)
        return;

    shared_->counter_ -= 1;
    /*if (shared_->counter_ > 0)
    {
        shared_->counter_ -= 1;
    }*/
    std::cout << "Deincrementing counter... " << shared_->counter_ << std::endl;
    if (shared_->counter_ == 0)
    {
        std::cout << "Ready to delete objects..." << std::endl;
        delete shared_->data_;
        delete shared_;
        shared_ = nullptr;
    }
}

} // namespace smart_ptr
