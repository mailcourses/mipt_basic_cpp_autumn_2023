#include <iostream>
#include <string> // для использования std::string

using namespace std;

void foo(std::string&)
{
}

//auto foo(...)
//{
//    //...
//}

/*
void foo(double)
{
}
*/

int main()
{
    string str1{"Hello"};
    string str2{" world"};
    cout << str1 + str2 << endl;
    cout << operator+(str1, str2) << endl;
    std::string str3 = str1 + str2;
    str3.push_back('!');
    cout << str1.size() << " <-- str1.size, str2.size --> " << str2.size() << endl;
    cout << str3 << std::endl;
    // Hello world!
    // 0123456789
    cout << "substr(1,4) = " << str3.substr(1, 4) << std::endl;
    str3.clear();
    cout << "str3=[" << str3 << "]" << std::endl;
    // cout << str1.operator+(str2) << endl;
    auto var1 = 4.5;    // double
    auto var2 = 1.0f;   // float
    auto var3 = 100.3L; // long double
    foo(var3);

    //typedef std::vector<std::vector<std::pair<std::string, int64_t>>> vec_t;
    std::vector<std::vector<std::pair<std::string, int64_t>>> magic;
    //std::vector<std::vector<std::pair<std::string, int64_t>>>::iterator == auto
    auto it = magic.begin();
}
