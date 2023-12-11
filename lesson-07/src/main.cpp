#include <iostream>
#include "shared_ptr.hpp"

int main()
{
    smart_ptr::shared_ptr sp1(new std::string("Hello kitty!"));
    smart_ptr::shared_ptr sp2(sp1);
    smart_ptr::shared_ptr sp3(new std::string("MIPT"));
    sp3 = sp3;

    sp3 = std::move(sp2);
    smart_ptr::shared_ptr sp4(std::move(sp3));
    return 0;
}
