#include <ostream>

class Figure
{
public:
    virtual double perimeter() const = 0;
};

class Triangle: public Figure
{
private:
    double a, b,c;
public:
    Triangle( double a, double b, double c): a(a), b(b),c(c){};
    double perimeter() const override;
};

class Rectangle : public Figure
{
private:
    double a_, b_;
public:
    Rectangle(double a, double b) : a_(a), b_(b) {};
    double perimeter() const override;
};

std::ostream& operator<<(std::ostream& os, Figure& f);
