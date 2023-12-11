#include <iostream>

#include "searcher.hpp"

namespace searcher
{

void YoulaSearcher::print_results(const Documents& docs, bool is_debug)
{
    for (auto &doc : docs)
    {
        std::cout << doc.first << std::endl;
        if (is_debug)
        {
            std::cout << doc.second << std::endl;
        }
        std::cout << "qparams_ == " << this->qparams_ << std::endl;
    }
}

int32_t YoulaSearcher::distance(const Document& doc1, const Document& doc2, YoulaSearcher& searcher)
{
    std::cout << "doc1: " << doc1.first << ", doc2: " << doc2.first << std::endl;
    std::cout << "qparams_ == " << searcher.qparams_ << std::endl;
    return 1;
}

} // namespace searcher

int main()
{
    searcher::YoulaSearcher searcher;
    searcher::YoulaSearcher::Documents docs = {{"<h1>Wikipedia</h1>", 100}, {"<h1>VKontakte</h1>", 99}, {"<h1>Google</h1>", 98}};
    bool is_debug = true;
    searcher.print_results(docs);
    searcher.distance(docs[0], docs[1], searcher);

    searcher::YoulaSearcher::distance(docs[1], docs[2], searcher);
}
