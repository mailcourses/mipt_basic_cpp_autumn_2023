# Домашнее задание к лекции №4

## Написать библиотеку-парсер

Необходимо написать функцию-парсер строк состоящих из следующих токенов:
- строка (например, "beatngu" или "4you");
- число (целочисленное неотрицательное число, помещающее в uint64\_t, например, 1234, 00323, 0);

Число состоит из символов от 0 до 9, строка - все остальные символы.
Если числовой токен не помещается в uint64\_t, то должен обрабатываться как токен-строка.
Токены разделены пробелами, символами табуляции и первода строки.

Пользователь функции должен иметь возможность зарегистрировать callback-функции, вызываемую каждый раз, когда найден токен, функция получает токен. Должна быть возможность передать свой обработчик под каждый тип токена, но могут и не передавать.

```c++

using func_ptr = void(*)();
using func_digit_ptr = ...;
using func_str_ptr = ...;


void parse(const std::string& text,
           func_digit_ptr digit_callback = nullptr,
           func_str_ptr string_callback = nullptr
);

void parse_string(const std::string& text)
{
    //...
}

int main()
{
    std::string line;
    //...
    parse(line, nullptr, parse_string);
    return 0;
}
```

При большом желании можно реализовать в виде класса-парсера.
```c++
class TokenParser
{
public:
    TokenParser() = default;

    // Устанавливаем callback-функцию перед стартом парсинга.
    SetStartCallback(...);

    // Устанавливаем callback-функцию после окончания парсинга.
    SetEndCallback(...);

    // Устанавливаем callback-функцию для обработки чисел.
    SetDigitTokenCallback(...);

    // Тут другие методы для установки callback-функций.
    //...
    void Parse(const std::string &);
};

int main()
{
    TokenParser parser;
    std::string line;
    while (std::getline(line)) {
        parser.Parse(line);
    }
}
```
