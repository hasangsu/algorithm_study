#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    std::cin >> N;
    
    int max = (N * 2) - 1;
    
    // 위
    for (int i = max; i >= 1; i -= 2)
    {
        int gap = (max - i) / 2;
        
        // 왼쪽 갭
        for (int j = 0; j < gap; j++)
        {
            std::cout << " ";
        }
        
        // 별
        for (int k = 0; k < i; k++)
        {
            std::cout << "*";
        }
        
        // 개행
        std::cout << "\n";
    }
    
    // 아래
    for (int i = 3; i <= max; i += 2)
    {
        int gap = (max - i) / 2;
        
        // 왼쪽 갭
        for (int j = 0; j < gap; j++)
        {
            std::cout << " ";
        }
        
        // 별
        for (int k = 0; k < i; k++)
        {
            std::cout << "*";
        }
        
        // 개행
        std::cout << "\n";
    }
}