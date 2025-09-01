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
    int numberN = 0;
    int numberK = 0;
    std::cin >> numberN >> numberK;
    
    int result = factorial(numberN) / (factorial(numberK) * factorial(numberN - numberK));
    std::cout << result;
}