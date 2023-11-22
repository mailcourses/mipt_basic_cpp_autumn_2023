#include <iostream>
#include <sstream>

struct Human
{
//public:
    size_t var{0};

public:
    // Конструктор по умолчанию.
    Human()
    {
        std::cout << "Human()" << std::endl;
    }

    Human(size_t age) //: age(age)
    {
        this->age = age;
        std::cout << "Human(" << age << ")" << std::endl;
    }

    // Конструктор копирования.
    Human(const Human& other)
    {
        std::cout << "Human(const Human&)" << std::endl;
        age = other.age;
        height = other.height;
        salary = other.salary;
    }

    //! Деструктор.
    ~Human()
    {
        std::cout << "~Human(" << age << ")" << std::endl;
    }

public:
    size_t getSalary(/*Human *this*/) const
    {
        return /*this->*/salary;
    }

    size_t getAgeSalary(double koef = 0.5) const
    {
        logger_ << std::string{"Calling getAgeSalary with koef "} << std::to_string(koef) << std::endl;
        return getAge() * salary * koef;
    }

    void setSalary(size_t _salary)
    {
        salary = _salary;
    }

private:
    size_t getAge(/*Human *this*/) const
    {
        return this->age;
    }
public:
    size_t age{0};
public:
    //! Рост в сантиметрах.
    size_t height{0};
private:
    size_t salary{0};
    using Logger = std::stringstream;
    mutable Logger logger_;
};

class HumanNonCopable
{
public:
    HumanNonCopable() {};
    HumanNonCopable(const HumanNonCopable&) = delete;
};

int main()
{
    Human person;
    person.age = 34;
    person.height = 185;
    person.setSalary(1500);
    std::cout << "age=" << person.age << ", height=" << person.height << std::endl;
    //std::cout << "salary=" << person.salary << std::endl; <-- потому что приватный
    std::cout << "var=" << person.var << std::endl;
    std::cout << "salary=" << person.getSalary() << std::endl;
    std::cout << "age salary=" << person.getAgeSalary(2.0) << std::endl;

    {
        Human person_copy_1 = person;
    }
    Human person_copy_2{person};
    {
        Human* person_ptr = new Human(100500);
        delete person_ptr;
    }
    std::cout << "After namespace" << std::endl;
    Human person_copy_3(person);

    HumanNonCopable hnc_1;
    //HumanNonCopable hnc_2{hnc_1}; <-- удалили руками конструктор копирования
    //

    {
        const Human person_copy_4(person);
        std::cout << "Salary for person #4 " << person_copy_4.getSalary() << std::endl;
    }



}
