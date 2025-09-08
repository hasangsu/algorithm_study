#include <iostream>

long long factorial(int number)
{
    if (number <= 1)
    {
        return 1;
    }
    
    return number * factorial(number - 1);
}

int main()
{
    int number = 0;
    std::cin >> number;
    
    long long result = factorial(number);
    std::cout << result;
}