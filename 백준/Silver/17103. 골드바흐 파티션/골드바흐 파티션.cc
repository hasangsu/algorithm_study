#include <iostream>
#include <vector>
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
    int count = 0;
    std::cin >> count;
    
    // 소수 확인 (n 은 최대 100만)
    std::vector<bool> isPrimeArray(1000000 + 1, false);
    for (int index = 1; index <= 1000001; index++)
    {
        bool result = isPrime(index);
        isPrimeArray[index] = result;
    }
        
    for (int index = 0; index < count; index++)
    {
        int number = 0;
        std::cin >> number;
        
        // 골드바흐 확인
        int result = 0;
        for (int index = 1; index <= number/2; index++)
        {
            // 소수가 아니면 확인하지 않는다.
            if (!isPrimeArray[index])
            {
                continue;
            }
            
            // n = p + q 일때.
            // q = n - p
            // ex) q = 10 - 1
            int n = number;
            int p = index;
            if (!isPrimeArray[n-p])
            {
                continue;
            }
            
            result++;
        }
        
        std::cout << result << "\n";
    }
}