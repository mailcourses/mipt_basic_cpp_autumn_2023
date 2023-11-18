#include <string>


namespace mipt
{

namespace foo
{

void help(std::string str)
{
    //cin
    //cout
}

} // namespace foo


void help(std::string str)
{
}

} // namespace mipt

void help(std::string str)
{
}

int main()
{
    //using namespace mipt; <-- ошибка
    //error: call of overloaded ‘help(const char [5])’ is ambiguous
    help("help");
    mipt::help("help");
    mipt::foo::help("help");
}
