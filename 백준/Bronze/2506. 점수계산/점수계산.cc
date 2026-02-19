#include <iostream>

int main()
{
    int N = 0;
    std::cin >> N;
    
    int result = 0;
    int straight = 0;
    for (int i = 0; i < N; i++)
    {
        int p = 0;
        std::cin >> p;
        
        if (p != 1)
        {
            // 정답이 아니면
            straight = 0;
            continue;
        }
        
        straight += 1;
        result += straight;
    }
    
    std::cout << result;
}