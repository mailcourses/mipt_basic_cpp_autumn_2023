#include <iostream>

class ISearcher
{
public:
    ISearcher() = default;
    virtual void search() = 0;
    virtual void print_result() = 0;
};

class YoulaSearcher : public ISearcher
{
public:
    YoulaSearcher() = default;
    void search() override
    {
        std::cout << "[YoulaSearcher][search]" << std::endl;
    }
    void print_result() override {}
};

class VideoSearcher : public ISearcher
{
public:
    VideoSearcher() = default;
    void search() override
    {
        std::cout << "[VideoSearcher][search]" << std::endl;
    }
    void print_result() override {}
};

void make_searcher(ISearcher* searcher)
{
    searcher->search();
}

int main()
{
    YoulaSearcher* ys = new YoulaSearcher;
    VideoSearcher* vs = new VideoSearcher;
    make_searcher(ys);
    make_searcher(vs);
    //ISearcher *searcher = new ISearcher;
}

