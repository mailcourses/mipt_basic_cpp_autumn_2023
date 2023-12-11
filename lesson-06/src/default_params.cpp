#include <iostream>
#include <vector>

class Searcher
{
public:
    using Document = std::pair<std::string, int32_t>;
    using Documents = std::vector<Document>;

    Searcher() = default;
    // qs: q=text&debug=1
    void print_results(const Documents& docs, bool is_debug);
};
