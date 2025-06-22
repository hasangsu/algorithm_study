#include <iostream>

int main()
{
    int number = 0;
    std::cin >> number;
    
    int base = 1;
    int accumulate = 1;
    while (true)
    {
        if (base < number)
        {
            base = (accumulate * 6) + base;
            accumulate++;
        }
        else
        {
            break;
        }
    }

    std::cout << accumulate;
}