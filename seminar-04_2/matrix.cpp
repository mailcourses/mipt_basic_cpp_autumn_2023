#include <iostream>

int** buildMatrix(int n, int m)
{
    int** mt = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        mt[i] = new int[m];
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> mt[i][j];
        }
    }
    
    return mt;
}

void printZigzagMatrix(int n, int m, int** mt)
{
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; ++j)
            {
                std::cout << mt[i][j] << " ";
            }
        }
        else
        {
            for (int j = m-1; j >= 0; --j)
            {
                std::cout << mt[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    int r, c;
    std::cin >> r >> c;

    int** mt = buildMatrix(r, c);
    printZigzagMatrix(r, c, mt);
}
