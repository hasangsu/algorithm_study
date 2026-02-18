#include <iostream>

int main()
{
    int N = 0;
    std::cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        int star = (i * 2) - 1;
        int gap = ((N * 2) - star) / 2;
        
        for (int i = 0; i < gap; i++)
        {
            std::cout << " ";
        }
        
        for (int i = 0; i < star; i++)
        {
            std::cout << "*";
        }
        
        if (i != N)
        {
            std::cout << "\n";
        }
    }
}