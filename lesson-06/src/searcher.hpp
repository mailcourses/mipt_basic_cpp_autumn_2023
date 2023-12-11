#include <vector>

namespace searcher
{

class YoulaSearcher
{
public:
    using Document = std::pair<std::string, int32_t>;
    using Documents = std::vector<Document>;
    using qs_map = std::string;

    YoulaSearcher() = default;
    // qs: q=text&debug=1
    void print_results(const Documents& docs, bool is_debug = false);
    static int32_t distance(const Document& doc1, const Document& doc2, YoulaSearcher& searcher);
public:
    qs_map qparams_;
};

}// namespace searcher
