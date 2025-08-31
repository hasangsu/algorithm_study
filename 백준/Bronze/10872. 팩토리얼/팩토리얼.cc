#include <iostream>

int factorial(int number)
{
    if (number <= 0)
    {
        return 1;
    }
    else
    {
        return number * factorial(number - 1);
    }
}

int main()
{
    int number = 0;
    std::cin >> number;
    
    int result = factorial(number);
    std::cout << result;
}