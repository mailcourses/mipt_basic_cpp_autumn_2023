#include "figure.hpp"

double Triangle::perimeter() const
{
    return a + b + c;
}

double Rectangle::perimeter() const
{
    return 2 * (a_ + b_);
}

std::ostream& operator<<(std::ostream& os, Figure& f)
{
    os << f.perimeter() << std::endl;
    return os;
}
