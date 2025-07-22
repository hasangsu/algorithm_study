#include <iostream>

int main()
{
    int count = 0;
    std::cin >> count;
    
    int numbers[count] = { 0, };
    for (int index = 0; index < count; index++)
    {
        int number = 0;
        std::cin >> number;
        
        numbers[index] = number;
    }
    
    int index = 0;
    while (index < count - 1)
    {
        int base = numbers[index];
        int next = numbers[index + 1];
        if (base < next)
        {
            index++;
            continue;
        }
        
        numbers[index] = numbers[index + 1];
        numbers[index + 1] = base;
        index = 0;
    }
    
    for (int index = 0; index < count; index++)
    {
        std::cout << numbers[index] << "\n";
    }
}