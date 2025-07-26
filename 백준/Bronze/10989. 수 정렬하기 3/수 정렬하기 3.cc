#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int count = 0;
    std::cin >> count;
    
    int numbers[10001] = { 0, };
    for (int index = 1; index <= count; index++)
    {
        int number = 0;
        std::cin >> number;
        
        numbers[number] += 1;
    }
    
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 1; j <= numbers[i]; j++)
        {
            std::cout << i << "\n";    
        }
    }
}