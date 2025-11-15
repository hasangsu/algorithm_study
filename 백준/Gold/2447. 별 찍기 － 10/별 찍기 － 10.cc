#include <iostream>

bool isBlank(int i, int j)
{
    while (i > 0)
    {
        if ((i % 3 == 1) &&
            (j % 3 == 1))
        {
            return true;
        }
        
        i = i / 3;
        j = j / 3;
    }
    
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N = 0;
    std::cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (isBlank(i, j))
            {
                std::cout << " ";
            }
            else
            {
                std::cout << "*";
            }
        }
        std::cout << "\n";
    }
}