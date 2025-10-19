#include <iostream>

int main()
{
    int number = 0;
    std::cin >> number;
    
    for (int i = 1; i <= number; i++)
    {
        std::cout << i << "\n";
    }
}