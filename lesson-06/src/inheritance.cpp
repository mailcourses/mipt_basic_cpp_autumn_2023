#include <iostream>

class Animal
{
public:
    Animal() = default;
public:
    uint32_t age = 0;
    uint32_t weight = 0;
};


static Animal operator+(const Animal& lhs, const Animal& rhs)
{
    Animal res;
    res.age = lhs.age + rhs.age;
    return res;
}


struct Mammal2: Animal
{

};

class Mammal : protected Animal
{
public:
    Mammal()
    {
        std::cout << "Mammal()" << std::endl;
    }
    virtual ~Mammal()
    {
        std::cout << "~Mammal()" << std::endl;
    }
    virtual void feed();
    virtual Mammal operator+(const Mammal& rhs)
    {
        std::cout << "Animal operator+(const Animal& rhs)" << std::endl;
        return Mammal();
    }
};

void Mammal::feed()
{
    std::cout << "[Mammal][feed]" << std::endl;
    std::cout << age << ", " << weight << std::endl;
}


class Smart
{
public:
    Smart() = default;
public:
    uint32_t iq;
};

class Ape : public Mammal, public Smart
{
public:
    Ape()
    {
        std::cout << "Ape()" << std::endl;
    }
    ~Ape()
    {
        std::cout << "~Ape()" << std::endl;
    }
    void jump()
    {
        std::cout << "age: " << age << " weight: " << weight << ", iq: " << iq <<  std::endl;
    }
    void feed()
    {
        std::cout << "[Ape][feed]" << std::endl;
    }
    virtual Mammal operator+(const Mammal& rhs) override
    {
        std::cout << "[APE] Mammal operator+(const Mammal& rhs)" << std::endl;
        return Mammal();
    }
};

class Cat : public Mammal, public Smart
{
public:
    Cat()
    {
        std::cout << "Cat()" << std::endl;
    }
    ~Cat()
    {
        std::cout << "~Cat()" << std::endl;
    }
    void feed()
    {
        std::cout << "[Cat][feed]" << std::endl;
    }
private:
    std::string nickname;
};

void call_feed(Mammal& mammal)
{
    mammal.feed();
}

void call_feed(Mammal* mammal)
{
    mammal->feed();
    *mammal + Mammal();
    delete mammal;
}

int main()
{
    Animal a1, a2;
    a1 + a2;
    Mammal ape;
    ape.feed();
    //std::cout << "age: " << ape.age << " weight: " << ape.weight << std::endl;

    std::cout << "sizeof(Mammal) is " << sizeof(Mammal) << " bytes." << std::endl;

    Ape super_ape;
    super_ape.jump();
    super_ape.feed();

    std::cout << "Creating Ape..." << std::endl;
    Ape* ape_ptr = new Ape();
    std::cout << "Creating Cat..." << std::endl;
    Cat* cat_ptr = new Cat();

    //ape_ptr->feed();
    /*cat_ptr->feed();

    call_feed(*ape_ptr);
    call_feed(*cat_ptr);
*/
    std::cout << "=========" << std::endl;
    call_feed(ape_ptr);
    std::cout << "=========" << std::endl;
    //call_feed(cat_ptr);
}
