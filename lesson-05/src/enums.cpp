#include <iostream>

enum VideoCategory
{
    VC_None,
    VC_Cats,
    VC_Movie
};

enum class ProductCategory
{
    None,
    Cars,
    Games
};

VideoCategory getVideoCategory()
{
    return VC_Cats;
}

int main()
{
    //...
    VideoCategory category = getVideoCategory();
    ProductCategory pr_category = ProductCategory::None;
    switch(pr_category)
    {
        case ProductCategory::None:
            std::cout << "ProductCategory None" << std::endl;
            break;
        case ProductCategory::Cars:
            std::cout << "ProductCategory Cars" << std::endl;
            break;
        case ProductCategory::Games:
            std::cout << "ProductCategory Games" << std::endl;
            break;
    }
}
