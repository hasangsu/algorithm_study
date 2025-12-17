#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int twoPointers(const std::vector<int> &primes, int target)
{
    int start = 0;
    int end = 0;
    
    int result = 0;
    int sum = 0;
    
    while (true)
    {
        if (target <= sum)
        {
            if (target == sum)
            {
                result++;
            }
            
            sum -= primes[start];
            start++;
        }
        else if (end == primes.size())
        {
            break;
        }
        else
        {
            sum += primes[end];
            end++;
        }
    }
    
    if (result == INT_MAX)
    {
        return 0;
    }
    else
    {
        return result;
    }
    
    return result;
}

int main()
{
    int N = 0;
    std::cin >> N;
    
    std::vector<bool> isPrime(N + 1, true);
    std::vector<int> primes;

    // 0과 1은 소수가 아님
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    // 소수 리스트
    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
    
    int result = twoPointers(primes, N);
    std::cout << result;
}