/*
Из стандартного ввода нам подаются пары: <название города> <численность>
Написать класс, которому на вход подаётся массив пар.
И нужно метод метод random(), который возвращал название города
равномерно его численности.

Город1 90
Город2 2
Город3 8
*/
#include <vector>
#include <utility>
#include <string>
#include <istream>
#include <iostream>
#include <ctime>


class CityGenerator
{
public:
    std::vector<std::pair<std::string, uint64_t>> data_;
public:
    CityGenerator()
    {
        std::srand(std::time(nullptr));
    }
    friend std::istream& operator>>(std::istream& input, CityGenerator& generator);
    const std::pair<std::string, uint64_t>& random() const
    {
        // Use current time as seed for random generator.
        /*std::srand(std::time(nullptr));
        uint32_t random_value = static_cast<uint32_t>(std::rand());
        return data_[random_value % data_.size()];*/
        
        std::vector<uint64_t> distances(data_.size(), 0);
        int cnt = 0;
        /*
        [7, 2, 1]
        [7, 9, 10]
        */
        for(size_t i = 0; i < data_.size(); ++i) {
            
            cnt += data_[i].second;
            distances[i] = cnt;
        }
        
        uint32_t random_value = static_cast<uint32_t>(std::rand());
        random_value %= cnt;
        
        for (size_t i = 0; i < data_.size(); ++i) {
            if (random_value < distances[i]) {
                return data_[i];
            }
        }
    }
};

/*
std::istream& operator>>(std::istream& input, CityGenerator& generator)
{
    std::pair<std::string, uint64_t> p;
    input >> p.first >> p.second;
    generator.data_.push_back(p);
    return input;
}*/

int main()
{
    CityGenerator generator;
    std::pair<std::string, uint64_t> p;
    while(std::cin >> p.first >> p.second){
        generator.data_.push_back(p);
    }
    for (size_t i = 0; i < 100; ++i)
    {
        std::cout << generator.random().first << std::endl;
    }
}
