#include <iostream>
#include <memory>

void foo()
{
    int *a3 = nullptr;
    if (a3)
        std::cout << "a3 = " << *a3 << std::endl;
}

void boo(int *a)
{
    //a + 10
}

void boo_2(std::shared_ptr<int> a)
{
    
}

void boo_3(std::shared_ptr<int[]> a)
{
    
}

int main()
{
    int *a1 = new int[3];
    for (size_t i = 0; i < 3; ++i)
    {
        a1[i] = i+1;
    }
    // [1][2][3]
    //
    //  a1
    int *a2 = new int{5};
    // [5]
    //  a2
    std::shared_ptr<int> p_a2(new int{6});
    std::shared_ptr<int[]> p_a3(new int[10]);
    /*
    int i = 10;
    std::shared_ptr<int> p_a3(&i);
    */
    std::cout << "[1] counter of use memory for p_a2: " << p_a2.use_count() << std::endl;
    {
        std::shared_ptr<int> p_b2 = p_a2;
        std::cout << "[2.1] counter of use memory for p_a2: " << p_a2.use_count() << std::endl;
        std::cout << "[2.2] counter of use memory for p_b2: " << p_b2.use_count() << std::endl;
        std::cout << "[2.2.1] unique for p_a2: " << p_a2.unique() << std::endl;
        p_b2.reset();
        std::cout << "[2.2.2] unique for p_a2: " << p_a2.unique() << std::endl;
        std::cout << "[2.3] counter of use memory for p_a2: " << p_a2.use_count() << std::endl;
        std::cout << "[2.4] counter of use memory for p_b2: " << p_b2.use_count() << std::endl;
        p_b2.reset(new int{-1});
        std::shared_ptr<int> p_a3 = std::move(p_a2);
        std::cout << "[2.5] counter of use memory for p_a2: " << p_a2.use_count() << std::endl;
        std::cout << "[2.6] counter of use memory for p_a3: " << p_a3.use_count() << std::endl;
    }
    std::cout << "[3] counter of use memory for p_a2: " << p_a2.use_count() << std::endl;
    boo(a2);
    boo_2(p_a2);
    boo_3(p_a3);

    std::cout << "a1[0] = " << *a1 << ", a2 = " << *a2 << std::endl;
    std::cout << "a1[2] = " << a1[2] << std::endl;

    std::cout << "a2 + 2 = " << *(a2+2) << std::endl;
    int *_a2 = a1 + 2;
    //  0   1   2
    // [1] [2] [3]
    //         _a2
    std::cout << "a1[2] = " << *_a2 << std::endl;
    std::cout << "a1[2] = " << *(a1 + 2) << std::endl;
    std::ptrdiff_t delta = _a2 - a1;
    std::cout << "distance = " << delta << std::endl;

    foo();

 /*   ++a1;
    std::cout << "new a1 = " << *a1 << std::endl;*/

    delete[] a1;
    delete a2;
}
