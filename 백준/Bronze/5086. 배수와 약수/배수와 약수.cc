#include <iostream>

int main()
{
    while (true)
    {
        int number1 = 0;
        int number2 = 0;
        std::cin >> number1 >> number2;
        
        if ((number1 == 0) &&
            (number2 == 0))
        {
            break;
        }
        
        // 배수
        if (number1 % number2 == 0)
        {
            std::cout << "multiple" << "\n";
        }
        else if (number2 % number1 == 0)
        {
            std::cout << "factor" << "\n";
        }
        else
        {
            std::cout << "neither" << "\n";
        }
    }
}