#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    while (true)
    {
        int N = 0;
        std::cin >> N;
        
        if (N == 0)
        {
            break;
        }
        
        while (9 < N)
        {
            int sum = 0;
            int temp = N;
            
            while (0 < temp)
            {
                sum += temp % 10;
                temp /= 10;
            }
            
            N = sum;
        }
        
        std::cout << N << "\n";
    }
}