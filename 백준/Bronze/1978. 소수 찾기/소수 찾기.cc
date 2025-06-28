#include <iostream>

int main()
{
    int count = 0;
    std::cin >> count;
    
    int result = 0;
    for (int index = 0; index < count; index++)
    {
        int number = 0 ;
        std::cin >> number;
        if (number <= 1)
        {
            continue;
        }
        
        bool isPrime = true;
        for (int prime = 2; prime < number; prime++)
        {
            if (number % prime == 0)
            {
                // 약수 있음
                isPrime = false;
                break;
            }
        }
        
        if (isPrime)
        {
            result++;
        }
    }
    
    std::cout << result;
}