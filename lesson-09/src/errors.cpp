#include <iostream>
#include <cassert>
#include <system_error>

enum class HttpCode
{
    OK = 200,
    NOT_FOUND = 404,
    INTERNAL_SERVER_ERROR = 500
};

class HttpCategory : public std::error_category
{
public:
    const char* name() const noexcept override
    {
        return "http";
    }

    std::string message(int code) const override
    {
        switch(code)
        {
            case 200: return "ok";
            case 404: return "not found";
            case 500: return "internal server error";
            default: assert(!"invalid http code");
        }
    }
};

std::error_code make_error_code(HttpCode code)
{
    static HttpCategory category;
    return std::error_code(static_cast<int>(code), category);
}

std::error_code download(const std::string& url)
{
    if (url == "http://127.0.0.1/")
        return make_error_code(HttpCode::INTERNAL_SERVER_ERROR);
    if (url == "https://vk.com/")
        return make_error_code(HttpCode::OK);
    return make_error_code(HttpCode::NOT_FOUND);
}

int main()
{
    {
        auto error = download("http://127.0.0.1/");
        if (error)
        {
            std::cerr << "error: " << error << std::endl;
            std::cerr << "error message: " << error.message() << std::endl;
        }
    }
    {
        auto error = download("https://vk.com/");
        if (error)
        {
            std::cerr << "error: " << error << std::endl;
            std::cerr << "error message: " << error.message() << std::endl;
        }
    }
    return 0;
}
