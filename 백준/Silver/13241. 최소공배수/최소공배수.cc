#include <iostream>

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

long long lcm(long long a, long long b)
{
    return a * b / (gcd(a,b));
}

int main()
{
    long long numberA = 0;
    long long numberB = 0;
    std::cin >> numberA >> numberB;
    
    long long result = lcm(numberA, numberB);
    std::cout << result;
}