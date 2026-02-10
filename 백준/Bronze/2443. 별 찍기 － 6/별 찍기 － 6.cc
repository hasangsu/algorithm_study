#include <iostream>

int main()
{
    int N = 0;
    std::cin >> N;
    
    int max = (2 * N) - 1;
    while (N)
    {
        int star = (2 * N) - 1;
        int gapHalf = (max - star) / 2;
        
        // 왼쪽 공백출력
        for (int i = 0; i < gapHalf; i++)
        {
            std::cout << " ";
        }
        
        // 별 출력
        for (int i = 0; i < star; i++)
        {
            std::cout << "*";
        }
        
        // 다음줄
        std::cout << "\n";
        
        N--;
    }
}