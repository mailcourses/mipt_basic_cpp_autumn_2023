#include <iostream>
#include <vector>

struct Animal
{
    virtual void voice()
    {
        std::cout << "Default voice" << std::endl;
    }
};


struct Dog : Animal
{
    virtual void voice() override
    {
        std::cout << "Dog voice" << std::endl;
    }

    void bark()
    {
        std::cout << "BARK!!!" << std::endl;
    }
};

void foo(Animal* animal)
{
    animal -> voice();
    Dog* dog = dynamic_cast<Dog*>(animal);

    if (dog == nullptr)
    {
        std::cout << "Failed to cast Animal object to Dog object" << std::endl;
        return;
    }
    dog -> bark();
}

void boo(Animal& animal)
{
    animal.voice();
    Dog& dog = dynamic_cast<Dog&>(animal);

    dog.bark();
}

int main()
{
    {
        std::vector<Animal*> zoo{new Animal(), new Dog()};
        for(auto animal : zoo)
        {
            foo(animal);
        }
    }

    {
        std::vector<Animal*> zoo{new Dog(), new Animal(), new Dog()};
        for(auto animal : zoo)
        {
            boo(*animal);
        }
    }
}





