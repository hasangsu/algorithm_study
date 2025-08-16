#include <iostream>
#include <cmath>

bool isPrime(long long number)
{
    if (number < 2)
    {
        // 2 미만은 소수 아니다.
        return false;
    }
    
    if (number == 2) 
    {
        // 2 는 소수다.
        return true;
    }
    
    if (number % 2 == 0) 
    {
        // 2로 나누어 떨어지면 소수 아니다.
        return false;
    }
    
    long long limit = static_cast<long long>(sqrt(number));
    for (long long i = 3; i <= limit; i += 2) 
    {
        if (number % i == 0) 
        {
            // 나누어 떨어지면 소수 아니다.
            return false;
        }
        
    }
    
    return true;
}

int main()
{
    while (true)
    {
        int number = 0;
        std::cin >> number;
        
        if (number <= 0)
        {
            break;
        }
        
        int start = number + 1;
        int finish = number * 2;
        int result = 0;
        while (start <= finish)
        {
            if (isPrime(start))
            {
                result++;
            }
            
            start++;
        }
        
        std::cout << result << "\n";
    }
}