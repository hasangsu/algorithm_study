#include <iostream>

int main()
{
    int N = 0;
    std::cin >> N;
    
    int tmp = N;
    while (true)
    {
        if (tmp <= 0)
        {
            break;
        }
        
        // 별 갯수
        int star = tmp;
        
        // 공백 갯수
        int gap = N - star;
        
        // 공백 출력
        for (int i = 0; i < gap; i++)
        {
            std::cout << " ";
        }
        
        // 별 출력
        for (int i = 0; i < star; i++)
        {
            std::cout << "*";
        }
        
        // 갯수 줄이기
        tmp--;
        if (1 <= tmp)
        {
            std::cout << "\n";
        }
    }
}